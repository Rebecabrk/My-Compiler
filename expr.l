%{
#include <iostream>
#include <cstdlib>
#include "expr.tab.h"
using namespace std;
%}


%option noyywrap
%%
"integer" {yylval.string = strdup(yytext); return TYPE;}
"floatVal" {yylval.string = strdup(yytext); return TYPE;}
"character" {yylval.string = strdup(yytext); return TYPE;}
"string" {yylval.string = strdup(yytext); return TYPE;}
"really" {yylval.string = strdup(yytext); return TYPE;}

"while" {yylval.string = strdup(yytext); return WHILE;}
"if" {yylval.string = strdup(yytext); return IF;}
"for" {yylval.string = strdup(yytext); return FOR;}
"else" {yylval.string = strdup(yytext); return ELSE;}
"fn" {yylval.string = strdup(yytext); return FN;}
"struct" {yylval.string = strdup(yytext); return STRUCT;}
"class" {yylval.string = strdup(yytext); return CLASS;}

"and" {return AND;}
"or" {return OR;}
"~" {return NOT;}
"true" {return TRUEE;}
"false" {return FALSEE;}

"return" {return RETURN;}


"begin_code" {return BGIN;}
"end_code" {return END;}

[0-9]+ {yylval.integer = atoi(yytext); return INT;}
[0-9]+("."[0-9]+)? {yylval.floatVal = stof(yytext); return FLOAT;}
[a-zA-Z][a-zA-Z0-9]* {yylval.string = strdup(yytext); return ID;}
\'[a-zA-Z]\' {
                yylval.string = strdup(yytext + 1); 
                yylval.string[strlen(yylval.string) - 1] = '\0'; 
                return CHAR;
            }
\"[a-zA-Z][a-zA-Z0-9]*\" {
                            yylval.string = strdup(yytext + 1); 
                            yylval.string[strlen(yylval.string) - 1] = '\0';  
                            return STRING;
                         }
\[([0-9]+)\] {yylval.string = strdup(yytext); return ARRAY;}
"=" {return ASSIGN;}
"<" {return LESS;}
">" {return GREATER;}
"!=" {return DIFFERENT;}
"==" {return EQUAL;}
"+" {return PLUS;}
"-" {return MINUS;}
"/" {return DIVIDE;}
"*" {return MULTIPLY;}
"^" {return POWER;}

[ \t] ;
\n {yylineno++;}
. {return yytext[0];} 
%%