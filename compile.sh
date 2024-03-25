bison -d expr.y 
flex expr.l
g++ IdList.cpp FuncList.cpp AST.cpp lex.yy.c expr.tab.c -std=c++17
./a.out test.txt