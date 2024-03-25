%{
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
#include <variant>
#include <algorithm>
#include "IdList.h"
#include "FuncList.h"
#include "AST.h"
using namespace std;
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
class IdList ids;
class FuncList func;
class ExpressionEvaluator eval;

struct var_type{
     const char* name = "";
     const char* type = "";
     int value_i = 0;
     float value_f = 0.0;
     char value_c = '\0';
     bool value_b = 0;
     char* value_s = "";
     int linenr;
};

queue<var_type> main_q;
queue<var_type> global_q;
queue<var_type> add_var_q;
queue<var_type> update_var_q;
queue<var_type> var_domain_user_def;

queue<const char*> func_usage_args_q;
queue<pair<const char*, vector<const char*>>> func_usage_q;

// queue<pair<const char*, const char*>> var_domain;
// queue<pair<const char*, const char*>> var_domain_user_def;
queue<tuple<const char*, const char*, vector<FormalParam>>> func_domain;

vector<FormalParam> formal_param;

vector<variant<int,float, string>> expression_literals;
vector<string> expression_op;
string expression;
bool error = false;

// void error(const char* s, int linenr){
//      printf("error: %s at line:%d\n", s, linenr);
// }
%}
%union {
    char* string;
    char character;
    int integer;
    float floatVal;
    bool really;
}
%token BGIN END ASSIGN ARRAY WHILE IF ELSE FOR LESS GREATER DIFFERENT EQUAL PLUS MINUS DIVIDE MULTIPLY AND OR NOT STRUCT CLASS FN RETURN POWER
%token<integer> INT
%token<floatVal> FLOAT
%token<string> ID TYPE STRING TRUEE FALSEE CHAR

%left '+' '-'
%left '*' '/'

%start program
%%
program : aux program 
        | mainul {
          if(!error)
               printf("This code is correct!\n");
          else 
               cout<<"\033[1;31mThis code has errors!\033[0m"<<endl;
          }
        ;

aux : user_def_data_types
    | global_declarations           
    | global_functions
    ;
 
global_declarations : decl ';'          
                    | global_declarations decl ';'
                    ;

decl : TYPE ID ARRAY 
     | TYPE ID ASSIGN math_expr {
               bool isInt;
               reverse(expression_literals.begin(), expression_literals.end());
               if(!expression_literals.empty()){
                    if (holds_alternative<int>(expression_literals[0])) {
                         isInt = true;
               }
               else if (holds_alternative<float>(expression_literals[0])) {
                    isInt = false;
               }else {
                    string var_name = get<string>(expression_literals[0]);
                    IdInfo var = ids.getVar(var_name.c_str());
                    if(var.type == "integer") 
                         isInt = true;
                    else if(var.type == "floatVal") 
                         isInt = false;
                    else {
                         error = true;
                         yyerror("The variable given in the expression is not an integer, not an floatVal!");
                    }
               }
                    for(int i = 0; i < expression_literals.size(); i++){
                         if(isInt == true){
                              if(holds_alternative<float>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         } else{
                              if(holds_alternative<int>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         }
                    }
                    if(error == false)
                    {
                    for(int i =0 ;i < expression_op.size(); i++){
                         if (holds_alternative<int>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }
                         else if (holds_alternative<float>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }else {
                              string var_name = get<string>(expression_literals[i]);
                              IdInfo var = ids.getVar(var_name.c_str());
                              expression += var.value;
                         }
                         expression += " ";
                         expression += expression_op[i];
                         expression += " ";
                    }
                    if(holds_alternative<int>(expression_literals[expression_literals.size() -1]))
                              expression += to_string(get<int>(expression_literals[expression_literals.size() -1]));
                    else if(holds_alternative<float>(expression_literals[expression_literals.size() -1])) 
                              expression += to_string(get<float>(expression_literals[expression_literals.size() -1]));
                    else {
                         string var_name = get<string>(expression_literals[expression_literals.size() -1]);
                         IdInfo var = ids.getVar(var_name.c_str());
                         expression += var.value;
                    }
                    }
                    if(error == false){
                         if(isInt){
                              int result = eval.evaluate(expression);
                              if(strcmp($1, "integer") == 0)
                                   ids.addVar($1, $2, "global", result);
                              else 
                                   yyerror("Cannot assign integer to a anything other then integer");
                         }else{
                              float result = eval.evaluate(expression);
                              if(strcmp($1, "floatVal") == 0)
                                   ids.addVar($1, $2, "global", result);
                              else 
                                   yyerror("Cannot assign floatVal to a anything other then floatVal");
                         }
                    }     
               }else {yyerror("there is no expression!");}
               expression_literals.clear();
               expression_op.clear();
               expression.clear();
         }
     | TYPE ID ASSIGN values {
          while(!global_q.empty()){
               var_type aux = global_q.front();
               global_q.pop();

               if(!ids.existsVar(aux.name, "global")){
               if(aux.value_i != 0){
                    ids.addVar($1, aux.name, "global", aux.value_i);
               }
               else if(aux.value_f != 0.0){
                    ids.addVar($1, aux.name, "global", aux.value_f);
               }
               else if(aux.value_b != 0){
                    ids.addVar($1, aux.name, "global", aux.value_b);
               }
               else if(aux.value_c != '\0'){
                    ids.addVar($1, aux.name, "global", aux.value_c);
               }
               else if(aux.value_s != ""){
                    ids.addVar($1, aux.name, "global", aux.value_s);
               } 
          }
          else{
               yyerror("Variable already declared!");
          }
     }

}
     | TYPE ID {if(!ids.existsVar($2, "global")){
          if(strcmp($1, "integer") == 0){
               ids.addVar($1, $2, "global", 0);
          } else if(strcmp($1, "floatVal") == 0){
               ids.addVar($1, $2, "global", 0.0f);
          }else if(strcmp($1, "really") == 0){
               ids.addVar($1, $2, "global", false);
          }else if(strcmp($1, "character") == 0){
               ids.addVar($1, $2, "global", '\0');
          }else if(strcmp($1, "string") == 0){
               ids.addVar($1, $2, "global", "");
          } 
     }
     else {
          yyerror("Variable already exists!");
          yynerrs++;
     } }
     //| global_functions 
     ;

values : TRUEE {var_type x; x.value_b = $1; global_q.push(x);}
       | FALSEE {var_type x; x.value_b = $1; global_q.push(x);}
       | CHAR 
       | STRING {var_type x; x.value_s = $1; global_q.push(x);}
       ;

control_statements : while 
                   | if
                   | if else
                   | for
                   ;

compare : LESS
        | GREATER
        | DIFFERENT
        | EQUAL
        ;

math_op : PLUS {expression_op.push_back("+");}
        | MINUS {expression_op.push_back("-");}
        | DIVIDE {expression_op.push_back("/");}
        | MULTIPLY {expression_op.push_back("*");}
        | POWER {expression_op.push_back("^");}
        ;

bool_op : AND
        | OR
        | EQUAL
        | DIFFERENT
        ;

bool_operand : math_expr
             | TRUEE
             | FALSEE

bool_expr : bool_operand bool_op
          | NOT bool_operand bool_op
          | bool_operand 
          | NOT bool_operand 
          ;

while : WHILE '(' ID compare ID ')' '{' list '}' 
      | WHILE '(' ID compare INT ')' '{' list '}' 
      | WHILE '(' INT compare ID ')' '{' list '}' 
      | WHILE '(' INT compare INT ')' '{' list '}' 
      | WHILE '(' ID compare FLOAT ')' '{' list '}' 
      | WHILE '(' FLOAT compare ID ')' '{' list '}' 
      | WHILE '(' FLOAT compare FLOAT ')' '{' list '}' 
      ;
     
if : IF '(' ID compare ID ')' '{' list '}' 
   | IF '(' ID compare INT ')' '{' list '}' 
   | IF '(' INT compare INT ')' '{' list '}'
   | IF '(' ID compare FLOAT ')' '{' list '}' 
   | IF '(' FLOAT compare FLOAT ')' '{' list '}' 
   ;

else : ELSE if 
     | ELSE '{' list '}' 
     ;

for : FOR '(' ID ASSIGN ID ';' ID compare ID ';' ID ASSIGN math_expr ')' '{' list '}' 
    | FOR '(' ID ASSIGN ID ';' ID compare INT ';' ID ASSIGN math_expr ')' '{' list '}' 
    | FOR '(' ID ASSIGN INT ';' ID compare ID ';' ID ASSIGN math_expr ')' '{' list '}' 
    | FOR '(' ID ASSIGN INT ';' ID compare INT ';' ID ASSIGN math_expr ')' '{' list '}' 
    | FOR '(' ';' ID compare ID ';' ID ASSIGN math_expr ')' '{' list '}' 
    | FOR '(' ';' ID compare INT ';' ID ASSIGN math_expr ')' '{' list '}' 
    | FOR '(' ID ASSIGN ID ';' ID compare FLOAT ';' ID ASSIGN math_expr ')' '{' list '}' 
    | FOR '(' ID ASSIGN FLOAT ';' ID compare ID ';' ID ASSIGN math_expr ')' '{' list '}' 
    | FOR '(' ID ASSIGN FLOAT ';' ID compare FLOAT ';' ID ASSIGN math_expr ')' '{' list '}' 
    | FOR '(' ';' ID compare FLOAT ';' ID ASSIGN math_expr ')' '{' list '}' 
    ;      

mainul : BGIN list END { 
     while(!add_var_q.empty()){
          var_type x = add_var_q.front();
          add_var_q.pop();

          if(!ids.existsVar(x.name, "main")){
               if(x.value_i != NULL)
                    ids.addVar(x.type, x.name, "main", x.value_i);
               else if (x.value_f != 0.0)
                         ids.addVar(x.type, x.name, "main", x.value_f);
               else if (x.value_b != 0)
                         ids.addVar(x.type, x.name, "main", x.value_b);
               else if (x.value_c != '\0')
                         ids.addVar(x.type, x.name, "main", x.value_c);
               else if (x.value_s != "")
                         ids.addVar(x.type, x.name, "main", x.value_s);
          }
          else
               yyerror("Variable already declared!\n");
     }

     while(!update_var_q.empty()){
          var_type x = update_var_q.front();
          update_var_q.pop();

          if(ids.existsVar(x.name, "main")){
               if(x.value_i != 0)
                    ids.updateVar(x.name, "main", x.value_i);
               else if (x.value_f != 0.0)
                         ids.updateVar(x.name, "main", x.value_f);
               else if (x.value_b != 0)
                         ids.updateVar(x.name, "main", x.value_b);
               else if (x.value_c != '\0')
                         ids.updateVar(x.name, "main", x.value_c);
               else if (x.value_s != "")
                         ids.updateVar(x.name, "main", x.value_s);
          }
          else
               yyerror("Variable not declared!\n");
     }

     while(!func_usage_q.empty()){
          const char* name = func_usage_q.front().first;
          vector<const char*> types = func_usage_q.front().second;
          func_usage_q.pop();

          if(func.existsFunc(name, "global")){
               if(func.check_param_types(name, "global", types) == 0)
                    yyerror("Wrong parameters type!\n");
          }
          else
               yyerror("Function never declared!\n");
     }

     }
       ;
     
user_def_data_types : STRUCT  ID'{' user_def_data_types_decl '}' { 
     while(!var_domain_user_def.empty()) {
     var_type x = var_domain_user_def.front();
     var_domain_user_def.pop();

    if(!ids.existsVar(x.name, $2)){
          if(x.value_i != NULL)
                    ids.addVar(x.type, x.name, $2, x.value_i);
               else if (x.value_f != 0.0)
                         ids.addVar(x.type, x.name, $2, x.value_f);
               else if (x.value_b != 0)
                         ids.addVar(x.type, x.name, $2, x.value_b);
               else if (x.value_c != '\0')
                         ids.addVar(x.type, x.name, $2, x.value_c);
               else if (x.value_s != "")
                         ids.addVar(x.type, x.name, $2, x.value_s);
          }
          else
               yyerror("Variable already declared!\n");
} 

     while(!func_domain.empty()){
          auto aux = func_domain.front();
          func_domain.pop();

          const char* name = get<0>(aux);
          const char* return_type = get<1>(aux);
          vector<FormalParam> vars = get<2>(aux);

          func.addFunc(name, return_type, vars, $2);

          
     }

}      
                    | CLASS ID '{' user_def_data_types_decl '}' { 
     while(!var_domain_user_def.empty()) {
     var_type x = var_domain_user_def.front();
     var_domain_user_def.pop();

    if(!ids.existsVar(x.name, $2)){
          if(x.value_i != NULL)
                    ids.addVar(x.type, x.name, $2, x.value_i);
               else if (x.value_f != 0.0)
                         ids.addVar(x.type, x.name, $2, x.value_f);
               else if (x.value_b != 0)
                         ids.addVar(x.type, x.name, $2, x.value_b);
               else if (x.value_c != '\0')
                         ids.addVar(x.type, x.name, $2, x.value_c);
               else if (x.value_s != "")
                         ids.addVar(x.type, x.name, $2, x.value_s);
          }
          else
               yyerror("Variable already declared!\n");
     } 

     while(!func_domain.empty()){
          auto aux = func_domain.front();
          func_domain.pop();

          const char* name = get<0>(aux);
          const char* return_type = get<1>(aux);
          vector<FormalParam> vars = get<2>(aux);

          func.addFunc(name, return_type, vars, $2);

          
     }

}   
                    ; 

user_def_data_types_decl : user_def_data_types_decl TYPE ID ';' { 
     var_type x;
     if(strcmp($2, "integer") == 0){
          x.value_i = -1;
     } else if(strcmp($2, "floatVal") == 0){
          x.value_f = -1;
     }else if(strcmp($2, "really") == 0){
          x.value_b = false;
     }else if(strcmp($2, "character") == 0){
          x.value_c = -1;
     }else if(strcmp($2, "string") == 0){
          x.value_s = "-1";
     } 
     x.name = $3;
     x.type = $2;
     x.linenr = yylineno;
     var_domain_user_def.push(x);

 }
                         | user_def_data_types_decl TYPE ID ARRAY ';'
                         | user_def_data_types_decl TYPE ID ASSIGN math_expr ';' {
               bool isInt;
               reverse(expression_literals.begin(), expression_literals.end());
               if(!expression_literals.empty()){
                    if (holds_alternative<int>(expression_literals[0])) {
                         isInt = true;
               }
               else if (holds_alternative<float>(expression_literals[0])) {
                    isInt = false;
               }else {
                    string var_name = get<string>(expression_literals[0]);
                    IdInfo var = ids.getVar(var_name.c_str());
                    if(var.type == "integer") 
                         isInt = true;
                    else if(var.type == "floatVal") 
                         isInt = false;
                    else {
                         error = true;
                         yyerror("The variable given in the expression is not an integer, not an floatVal!");
                    }
               }
                    for(int i = 0; i < expression_literals.size(); i++){
                         if(isInt == true){
                              if(holds_alternative<float>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         } else{
                              if(holds_alternative<int>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         }
                    }
                    if(error == false)
                    {
                    for(int i =0 ;i < expression_op.size(); i++){
                         if (holds_alternative<int>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }
                         else if (holds_alternative<float>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }else {
                              string var_name = get<string>(expression_literals[i]);
                              IdInfo var = ids.getVar(var_name.c_str());
                              expression += var.value;
                         }
                         expression += " ";
                         expression += expression_op[i];
                         expression += " ";
                    }
                    if(holds_alternative<int>(expression_literals[expression_literals.size() -1]))
                              expression += to_string(get<int>(expression_literals[expression_literals.size() -1]));
                    else if(holds_alternative<float>(expression_literals[expression_literals.size() -1])) 
                              expression += to_string(get<float>(expression_literals[expression_literals.size() -1]));
                    else {
                         string var_name = get<string>(expression_literals[expression_literals.size() -1]);
                         IdInfo var = ids.getVar(var_name.c_str());
                         expression += var.value;
                    }
                    }
                    if(error == false){
                         if(isInt){
                              int result = eval.evaluate(expression);
                              var_type x;
                              x.name = $3;
                              x.type = $2;
                              x.value_i = result;
                              x.linenr = yylineno;
                              var_domain_user_def.push(x);
                         }else{
                              float result = eval.evaluate(expression);
                              var_type x;
                              x.name = $3;
                              x.type = $2;
                              x.value_f = result;
                              x.linenr = yylineno;
                              var_domain_user_def.push(x);
                         }
                    }     
               }else {yyerror("there is no expression!");}
               expression_literals.clear();
               expression_op.clear();
               expression.clear();
         }
                         | user_def_data_types_decl function
                         |
                         ;


global_functions : function {

     while(!func_domain.empty()){
          auto aux = func_domain.front();
          func_domain.pop();

          const char* name = get<0>(aux);
          const char* return_type = get<1>(aux);
          vector<FormalParam> vars = get<2>(aux);

          func.addFunc(name, return_type, vars, "global");

          
     }
}
                 ;

function : FN TYPE ID '(' list_param ')' '{' list '}' { 
     while(!add_var_q.empty()){
          var_type x = add_var_q.front();
          add_var_q.pop();

          if(!ids.existsVar(x.name, $3)){
               if(x.value_i != 0)
                    ids.addVar(x.type, x.name, $3, x.value_i);
               else if (x.value_f != 0.0)
                         ids.addVar(x.type, x.name, $3, x.value_f);
               else if (x.value_b != 0)
                         ids.addVar(x.type, x.name, $3, x.value_b);
               else if (x.value_c != '\0')
                         ids.addVar(x.type, x.name, $3, x.value_c);
               else if (x.value_s != "")
                         ids.addVar(x.type, x.name, $3, x.value_s);
          }
          else
               yyerror("Variable already declared!\n");
     }

     while(!update_var_q.empty()){
          var_type x = update_var_q.front();
          update_var_q.pop();

          if(ids.existsVar(x.name, $3)){
               if(x.value_i != 0)
                    ids.updateVar(x.name, $3, x.value_i);
               else if (x.value_f != 0.0)
                         ids.updateVar(x.name, $3, x.value_f);
               else if (x.value_b != 0)
                         ids.updateVar(x.name, $3, x.value_b);
               else if (x.value_c != '\0')
                         ids.updateVar(x.name, $3, x.value_c);
               else if (x.value_s != "")
                         ids.updateVar(x.name, $3, x.value_s);
          }
          else
               yyerror("Variable not declared!\n");
     }

     func_domain.push(make_tuple($3, $2, formal_param));
     formal_param.clear();
}

                 | FN TYPE ID '(' ')' '{' list '}' {
                    while(!add_var_q.empty()){
          var_type x = add_var_q.front();
          add_var_q.pop();

          if(!ids.existsVar(x.name, $3)){
               if(x.value_i != 0)
                    ids.addVar(x.type, x.name, $3, x.value_i);
               else if (x.value_f != 0.0)
                         ids.addVar(x.type, x.name, $3, x.value_f);
               else if (x.value_b != 0)
                         ids.addVar(x.type, x.name, $3, x.value_b);
               else if (x.value_c != '\0')
                         ids.addVar(x.type, x.name, $3, x.value_c);
               else if (x.value_s != "")
                         ids.addVar(x.type, x.name, $3, x.value_s);
          }
          else
               yyerror("Variable already declared!\n");
     }

     while(!update_var_q.empty()){
          var_type x = update_var_q.front();
          update_var_q.pop();

          if(ids.existsVar(x.name, $3)){
               if(x.value_i != 0)
                    ids.updateVar(x.name, $3, x.value_i);
               else if (x.value_f != 0.0)
                         ids.updateVar(x.name, $3, x.value_f);
               else if (x.value_b != 0)
                         ids.updateVar(x.name, $3, x.value_b);
               else if (x.value_c != '\0')
                         ids.updateVar(x.name, $3, x.value_c);
               else if (x.value_s != "")
                         ids.updateVar(x.name, $3, x.value_s);
          }
          else
               yyerror("Variable not declared!\n");
     }                 }
                 ;

list_param : param 
           | list_param ',' param 
           ;

param : TYPE ID { var_type x;
               if(strcmp($1, "integer") == 0){
                    x.value_i = -1;
               } else if(strcmp($1, "floatVal") == 0){
                    x.value_f = -1;
               }else if(strcmp($1, "really") == 0){
                    x.value_b = false;
               }else if(strcmp($1, "character") == 0){
                    x.value_c = -1;
               }else if(strcmp($1, "string") == 0){
                    x.value_s = "-1";
               } 
               x.name = $2;
               x.type = $1;
               x.linenr = yylineno;
               add_var_q.push(x);

     FormalParam y;
     y.name = $2;
     y.type = $1;
     formal_param.push_back(y);
}
      | TYPE ID ARRAY  
      | ID '(' call_list ')'
      | ID ASSIGN math_expr
      ;  

list : statement
     | list statement
     ;

statement: TYPE ID ';' { var_type x;
               if(strcmp($1, "integer") == 0){
                    x.value_i = -1;
               } else if(strcmp($1, "floatVal") == 0){
                    x.value_f = -1;
               }else if(strcmp($1, "really") == 0){
                    x.value_b = false;
               }else if(strcmp($1, "character") == 0){
                    x.value_c = -1;
               }else if(strcmp($1, "string") == 0){
                    x.value_s = "-1";
               } 
               x.linenr = yylineno;
               x.name = $2;
               x.type = $1;
               add_var_q.push(x); }
         | TYPE ID ASSIGN math_expr ';' {
               bool isInt;
               reverse(expression_literals.begin(), expression_literals.end());
               if(!expression_literals.empty()){
                    if (holds_alternative<int>(expression_literals[0])) {
                         isInt = true;
               }
               else if (holds_alternative<float>(expression_literals[0])) {
                    isInt = false;
               }else {
                    string var_name = get<string>(expression_literals[0]);
                    IdInfo var = ids.getVar(var_name.c_str());
                    if(var.type == "integer") 
                         isInt = true;
                    else if(var.type == "floatVal") 
                         isInt = false;
                    else {
                         error = true;
                         yyerror("The variable given in the expression is not an integer, not an floatVal!");
                    }
               }
                    for(int i = 0; i < expression_literals.size(); i++){
                         if(isInt == true){
                              if(holds_alternative<float>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         } else{
                              if(holds_alternative<int>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         }
                    }
                    if(error == false)
                    {
                    for(int i =0 ;i < expression_op.size(); i++){
                         if (holds_alternative<int>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }
                         else if (holds_alternative<float>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }else {
                              string var_name = get<string>(expression_literals[i]);
                              IdInfo var = ids.getVar(var_name.c_str());
                              expression += var.value;
                         }
                         expression += " ";
                         expression += expression_op[i];
                         expression += " ";
                    }
                    if(holds_alternative<int>(expression_literals[expression_literals.size() -1]))
                              expression += to_string(get<int>(expression_literals[expression_literals.size() -1]));
                    else if(holds_alternative<float>(expression_literals[expression_literals.size() -1])) 
                              expression += to_string(get<float>(expression_literals[expression_literals.size() -1]));
                    else {
                         string var_name = get<string>(expression_literals[expression_literals.size() -1]);
                         IdInfo var = ids.getVar(var_name.c_str());
                         expression += var.value;
                    }
                    }
                    if(error == false){
                         if(isInt){
                              int result = eval.evaluate(expression);
                              var_type x;
                              x.name = $2;
                              x.type = $1;
                              x.value_i = result;
                              x.linenr = yylineno;
                              add_var_q.push(x);

                         }else{
                              float result = eval.evaluate(expression);
                              var_type x;
                              x.name = $2;
                              x.type = $1;
                              x.value_f = result;
                              x.linenr = yylineno;
                              add_var_q.push(x);
                         }
                    }     
               }else {yyerror("there is no expression!");}
               expression_literals.clear();
               expression_op.clear();
               expression.clear();
         }
         | ID ASSIGN math_expr ';'	 {
               bool isInt;
               reverse(expression_literals.begin(), expression_literals.end());
               if(!expression_literals.empty()){
                    if (holds_alternative<int>(expression_literals[0])) {
                         isInt = true;
               }
               else if (holds_alternative<float>(expression_literals[0])) {
                    isInt = false;
               }else {
                    string var_name = get<string>(expression_literals[0]);
                    IdInfo var = ids.getVar(var_name.c_str());
                    if(var.type == "integer") 
                         isInt = true;
                    else if(var.type == "floatVal") 
                         isInt = false;
                    else {
                         error = true;
                         yyerror("The variable given in the expression is not an integer, not an floatVal!");
                    }
               }
                    for(int i = 0; i < expression_literals.size(); i++){
                         if(isInt == true){
                              if(holds_alternative<float>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         } else{
                              if(holds_alternative<int>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         }
                    }
                    if(error == false)
                    {
                    for(int i =0 ;i < expression_op.size(); i++){
                         if (holds_alternative<int>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }
                         else if (holds_alternative<float>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }else {
                              string var_name = get<string>(expression_literals[i]);
                              IdInfo var = ids.getVar(var_name.c_str());
                              expression += var.value;
                         }
                         expression += " ";
                         expression += expression_op[i];
                         expression += " ";
                    }
                    if(holds_alternative<int>(expression_literals[expression_literals.size() -1]))
                              expression += to_string(get<int>(expression_literals[expression_literals.size() -1]));
                    else if(holds_alternative<float>(expression_literals[expression_literals.size() -1])) 
                              expression += to_string(get<float>(expression_literals[expression_literals.size() -1]));
                    else {
                         string var_name = get<string>(expression_literals[expression_literals.size() -1]);
                         IdInfo var = ids.getVar(var_name.c_str());
                         expression += var.value;
                    }
                    }
                    if(error == false){
                         if(isInt){
                              int result = eval.evaluate(expression);
                              // if(ids.existsVar($1, "main"))
                              //      ids.updateVar($1, "main", result);
                              // else
                              //      yyerror("Variable never delcared!");
                              var_type x;
                              x.linenr = yylineno;
                              x.name = $1;
                              x.value_i = result;
                              update_var_q.push(x);
                         }else{
                              float result = eval.evaluate(expression);
                              // if(ids.existsVar($1, "main"))
                              //      ids.addVar("floatVal", $1, "main", result);
                              // else
                              //      yyerror("Variable never delcared!");
                              var_type x;
                              x.linenr = yylineno;
                              x.name = $1;
                              x.value_f = result;
                              update_var_q.push(x);
                         }
                    }     
               }else {yyerror("there is no expression!");}
               expression_literals.clear();
               expression_op.clear();
               expression.clear();
         }
         //| ID ASSIGN CHAR ';'{ids.addVar("character", $1, "main", $3);}
         | ID ASSIGN TRUEE ';'{var_type x; x.linenr = yylineno; x.name = $1; x.value_b = $3; update_var_q.push(x);}
         | ID ASSIGN FALSEE ';'{var_type x; x.linenr = yylineno; x.name = $1; x.value_b = $3; update_var_q.push(x);}
         | ID ASSIGN STRING ';'{var_type x; x.linenr = yylineno; x.name = $1; x.value_s = $3; update_var_q.push(x);}
         //| TYPE ID ASSIGN CHAR ';'{ids.addVar("character", $2, "main",$4);}
         | TYPE ID ASSIGN TRUEE ';'{var_type x; x.linenr = yylineno; x.name = $2; x.type = $1; x.value_b = $4; add_var_q.push(x);}
         | TYPE ID ASSIGN FALSEE ';'{var_type x; x.linenr = yylineno; x.name = $2; x.type = $1; x.value_b = $4; add_var_q.push(x);}
         | TYPE ID ASSIGN STRING ';'{var_type x; x.linenr = yylineno; x.name = $2; x.type = $1; x.value_s = $4; add_var_q.push(x);}
         | ID '(' call_list ')' ';' { 
          vector<const char*> types;
          while(!func_usage_args_q.empty())
          {
               const char* type = func_usage_args_q.front();
               func_usage_args_q.pop();
               types.push_back(type);
          }

          func_usage_q.push(make_pair($1, types));
     }
         | TYPE ID ARRAY ';'
         | ID ARRAY ASSIGN math_expr ';'
         | ID ARRAY ASSIGN values ';'
         | TYPE ID ARRAY ASSIGN math_expr ';'
         | TYPE ID ARRAY ASSIGN values ';'
         | STRUCT ID '{' global_declarations '}'
         | CLASS ID '{' global_declarations '}'
         | ID '{' initialization '}' 
         | ID '.' ID ASSIGN values ';'
         | ID '.' ID ASSIGN math_expr ';'
         | control_statements
         | math_expr ';'
         | bool_expr 
         | RETURN values ';'
         ;

initialization : ID ASSIGN values 
               | ID ASSIGN values ',' initialization
               | ID ASSIGN math_expr {
               bool isInt;
               reverse(expression_literals.begin(), expression_literals.end());
               if(!expression_literals.empty()){
                    if (holds_alternative<int>(expression_literals[0])) {
                         isInt = true;
               }
               else if (holds_alternative<float>(expression_literals[0])) {
                    isInt = false;
               }else {
                    string var_name = get<string>(expression_literals[0]);
                    IdInfo var = ids.getVar(var_name.c_str());
                    if(var.type == "integer") 
                         isInt = true;
                    else if(var.type == "floatVal") 
                         isInt = false;
                    else {
                         error = true;
                         yyerror("The variable given in the expression is not an integer, not an floatVal!");
                    }
               }
                    for(int i = 0; i < expression_literals.size(); i++){
                         if(isInt == true){
                              if(holds_alternative<float>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         } else{
                              if(holds_alternative<int>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         }
                    }
                    if(error == false)
                    {
                    for(int i =0 ;i < expression_op.size(); i++){
                         if (holds_alternative<int>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }
                         else if (holds_alternative<float>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }else {
                              string var_name = get<string>(expression_literals[i]);
                              IdInfo var = ids.getVar(var_name.c_str());
                              expression += var.value;
                         }
                         expression += " ";
                         expression += expression_op[i];
                         expression += " ";
                    }
                    if(holds_alternative<int>(expression_literals[expression_literals.size() -1]))
                              expression += to_string(get<int>(expression_literals[expression_literals.size() -1]));
                    else if(holds_alternative<float>(expression_literals[expression_literals.size() -1])) 
                              expression += to_string(get<float>(expression_literals[expression_literals.size() -1]));
                    else {
                         string var_name = get<string>(expression_literals[expression_literals.size() -1]);
                         IdInfo var = ids.getVar(var_name.c_str());
                         expression += var.value;
                    }
                    }
                    if(error == false){
                         if(isInt){
                              int result = eval.evaluate(expression);
                              if(strcmp($1, "integer") == 0)
                                   ids.addVar("integer", $1, "main", result);
                              else 
                                   yyerror("Cannot assign integer to a anything other then integer");
                         }else{
                              float result = eval.evaluate(expression);
                              if(strcmp($1, "floatVal") == 0)
                                   ids.addVar("floatVal", $1, "main", result);
                              else 
                                   yyerror("Cannot assign floatVal to a anything other then floatVal");
                         }
                    }  
               }else {yyerror("there is no expression!");}
               expression_literals.clear();
               expression_op.clear();
               expression.clear();
         }
               | ID ASSIGN math_expr ',' initialization {
               bool isInt;
               reverse(expression_literals.begin(), expression_literals.end());
               if(!expression_literals.empty()){
                    if (holds_alternative<int>(expression_literals[0])) {
                         isInt = true;
               }
               else if (holds_alternative<float>(expression_literals[0])) {
                    isInt = false;
               }else {
                    string var_name = get<string>(expression_literals[0]);
                    IdInfo var = ids.getVar(var_name.c_str());
                    if(var.type == "integer") 
                         isInt = true;
                    else if(var.type == "floatVal") 
                         isInt = false;
                    else {
                         error = true;
                         yyerror("The variable given in the expression is not an integer, not an floatVal!");
                    }
               }
                    for(int i = 0; i < expression_literals.size(); i++){
                         if(isInt == true){
                              if(holds_alternative<float>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         } else{
                              if(holds_alternative<int>(expression_literals[i])){
                                   error = true;
                                   yyerror("Cannot have multiple types!");
                              }else if(holds_alternative<string>(expression_literals[i])){
                                   string var_name = get<string>(expression_literals[i]);
                                   IdInfo var = ids.getVar(var_name.c_str());
                                   if(var.type == "integer") 
                                        isInt = true;
                                   else if(var.type == "floatVal") 
                                        isInt = false;
                                   else {
                                        error = true;
                                        yyerror("The variable given in the expression is not an integer, not an floatVal!");
                                   }              
                              }
                         }
                    }
                    if(error == false)
                    {
                    for(int i =0 ;i < expression_op.size(); i++){
                         if (holds_alternative<int>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }
                         else if (holds_alternative<float>(expression_literals[i])) {
                              expression += to_string(get<int>(expression_literals[i]));
                         }else {
                              string var_name = get<string>(expression_literals[i]);
                              IdInfo var = ids.getVar(var_name.c_str());
                              expression += var.value;
                         }
                         expression += " ";
                         expression += expression_op[i];
                         expression += " ";
                    }
                    if(holds_alternative<int>(expression_literals[expression_literals.size() -1]))
                              expression += to_string(get<int>(expression_literals[expression_literals.size() -1]));
                    else if(holds_alternative<float>(expression_literals[expression_literals.size() -1])) 
                              expression += to_string(get<float>(expression_literals[expression_literals.size() -1]));
                    else {
                         string var_name = get<string>(expression_literals[expression_literals.size() -1]);
                         IdInfo var = ids.getVar(var_name.c_str());
                         expression += var.value;
                    }
                    }
                    if(error == false){
                         if(isInt){
                              int result = eval.evaluate(expression);
                              if(strcmp($1, "integer") == 0)
                                   ids.addVar("integer", $1, "main", result);
                              else 
                                   yyerror("Cannot assign integer to a anything other then integer");
                         }else{
                              float result = eval.evaluate(expression);
                              if(strcmp($1, "floatVal") == 0)
                                   ids.addVar("floatVal", $1, "main", result);
                              else 
                                   yyerror("Cannot assign floatVal to a anything other then floatVal");
                         }
                    }   
               }else {yyerror("there is no expression!");}
               expression_literals.clear();
               expression_op.clear();
               expression.clear();
         }
               ;

math_expr : ID math_op math_expr {
     IdInfo v = ids.getVar($1); 
     if(v.type != "null") 
          expression_literals.push_back($1); 
     else 
          yyerror("The variable is not defined!");
     }
          | ID {
     IdInfo v = ids.getVar($1); 
     if(v.type != "null") 
          expression_literals.push_back($1); 
     else 
          yyerror("The variable is not defined!");
     }
          | INT math_op math_expr {expression_literals.push_back($1);}
          | INT {
               var_type x; 
               x.value_i = $1;
               main_q.push(x);
               expression_literals.push_back($1);}
          | FLOAT math_op math_expr {expression_literals.push_back($1);}
          | FLOAT {
               var_type x;
               x.value_f = $1;
               main_q.push(x);
               expression_literals.push_back($1);}
          ;

call_list : values_func
          | call_list ',' values_func
          ;

values_func : INT {func_usage_args_q.push("integer");}
            | FLOAT {func_usage_args_q.push("floatVal");}
            | TRUEE {func_usage_args_q.push("really");}
            | FALSEE {func_usage_args_q.push("really");}
            | CHAR {func_usage_args_q.push("character");}
            | STRING {func_usage_args_q.push("string");}
            | ID {func_usage_args_q.push($1);}
            | ID ASSIGN math_expr
            ;
%%
void yyerror(const char * s){
printf("error: %s at line:%d\n",s,yylineno);
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
     cout << "Variables: " << '\n';
     ids.printVars();
     cout << '\n';
     cout << "Functions: " << '\n';
     func.printFunc();
} 