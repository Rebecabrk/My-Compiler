#include <iostream>
#include <string>
#include <queue>
#include <variant>
using namespace std;

enum class NodeType {
    Number,
    Operator,
};

enum class OperatorType {
    Addition,
    Subtraction,
    Multiplication,
    Division,
    Power,
    UnaryMinus,
};

using NodeValue = variant<int, float>;

struct ASTNode {
    NodeType type;
    NodeValue value;
    OperatorType op;
    ASTNode* left;
    ASTNode* right;

    ASTNode(NodeType t, NodeValue v) : type(t), value(v), op(OperatorType::Addition), left(nullptr), right(nullptr) {}

    ASTNode(NodeType t, OperatorType o, ASTNode* l, ASTNode* r)
        : type(t), op(o), left(l), right(r) {}
};

class ExpressionEvaluator{
    public:
    float evaluate(const string& expression);
    private:
    queue<string> PostFix(const string& infix);
    bool isNumber(const string& token);
    bool isOperator(const string& token);
    ASTNode* buildAST(queue<string>& postfixQueue);
    OperatorType getOperatorType(const string& token);
    float evaluateAST(ASTNode* node);
    float getNumberValue(const NodeValue& value);
    float evaluateOperator(OperatorType op, float left, float right);
};