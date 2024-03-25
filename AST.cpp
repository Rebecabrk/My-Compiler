#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <cmath>
#include <variant>
#include <unordered_map>
#include "AST.h"

using namespace std;
using NodeValue = variant<int, float>;

float ExpressionEvaluator::evaluate(const string &expression)
{
    queue<string> postfixQueue = PostFix(expression);
    ASTNode *ast = buildAST(postfixQueue);
    return evaluateAST(ast);
}

queue<string> ExpressionEvaluator::PostFix(const string& infix) {
        istringstream iss(infix);
        stack<string> operatorStack;
        queue<string> outputQueue;
//cout<<"PoftFixed expr is: ";
        unordered_map<string, int> precedence = {
            {"^", 4},
            {"*", 3},
            {"/", 3},
            {"+", 2},
            {"-", 2},
        };

        string token;
        while (iss >> token) {
            if (isNumber(token)) {
                outputQueue.push(token);
//cout<<token<<" ";
            } else if (isOperator(token)) {
                while (!operatorStack.empty() && isOperator(operatorStack.top()) &&
                       precedence[token] <= precedence[operatorStack.top()]) {
                    outputQueue.push(operatorStack.top());
//cout<<operatorStack.top()<<" ";
                    operatorStack.pop();
                }
                operatorStack.push(token);
            } else if (token == "(") {
                operatorStack.push(token);
            } else if (token == ")") {
                while (!operatorStack.empty() && operatorStack.top() != "(") {
                    outputQueue.push(operatorStack.top());
//cout<<operatorStack.top()<<" ";
                    operatorStack.pop();
                }
                operatorStack.pop(); // Discard the "("
            }
        }

        while (!operatorStack.empty()) {
            outputQueue.push(operatorStack.top());
//cout<<operatorStack.top()<<" ";
            operatorStack.pop();
        }
//cout<<endl;
        return outputQueue;
    }

bool ExpressionEvaluator::isNumber(const string &token)
{
    try
    {
        stoi(token);
        return true;
    }
    catch (...)
    {
        try
        {
            stof(token);
            return true;
        }
        catch (...)
        {
            return false;
        }
    }
}

bool ExpressionEvaluator::isOperator(const string &token)
{
    return token == "+" || token == "-" || token == "*" || token == "/" || token == "^";
}

ASTNode *ExpressionEvaluator::buildAST(queue<string> &postfixQueue)
{
    stack<ASTNode *> nodeStack;

    while (!postfixQueue.empty())
    {
        string token = postfixQueue.front();
        postfixQueue.pop();

        if (isNumber(token))
        {
            if (token.find('.') == string::npos)
            {
                nodeStack.push(new ASTNode(NodeType::Number, stoi(token)));
            }
            else
            {
                nodeStack.push(new ASTNode(NodeType::Number, stof(token)));
            }
        }
        else if (isOperator(token))
        {
            OperatorType opType = getOperatorType(token);
            ASTNode *right = nodeStack.top();
            nodeStack.pop();
            ASTNode *left = nodeStack.top();
            nodeStack.pop();

            nodeStack.push(new ASTNode(NodeType::Operator, opType, left, right));
        }
    }

    return nodeStack.top();
}

OperatorType ExpressionEvaluator::getOperatorType(const string &token)
{
    if (token == "+")
        return OperatorType::Addition;
    if (token == "-")
        return OperatorType::Subtraction;
    if (token == "*")
        return OperatorType::Multiplication;
    if (token == "/")
        return OperatorType::Division;
    if (token == "^")
        return OperatorType::Power;
    return OperatorType::Addition;
}

float ExpressionEvaluator::evaluateAST(ASTNode *node)
{
    if (!node)
    {
        return 0;
    }

    switch (node->type)
    {
    case NodeType::Number:
        return getNumberValue(node->value);
    case NodeType::Operator:
        return evaluateOperator(node->op, evaluateAST(node->left), evaluateAST(node->right));
    default:
        return 0;
    }
}

float ExpressionEvaluator::getNumberValue(const NodeValue &value)
{
    if (holds_alternative<int>(value))
    {
        return static_cast<float>(get<int>(value));
    }
    else if (holds_alternative<float>(value))
    {
        return get<float>(value);
    }
    return 0;
}

float ExpressionEvaluator::evaluateOperator(OperatorType op, float left, float right)
{
    switch (op)
    {
    case OperatorType::Addition:
        return left + right;
    case OperatorType::Subtraction:
        return left - right;
    case OperatorType::Multiplication:
        return left * right;
    case OperatorType::Division:
        if (right != 0)
        {
            return left / right;
        }
        else
        {
            cerr << "Error: Division by zero!" << endl;
            return 0;
        }
    case OperatorType::Power:
        return pow(left, right);
    default:
        return 0;
    }
}