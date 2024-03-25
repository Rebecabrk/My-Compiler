#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct FormalParam{
    string name;
    string type;
};

struct FuncInfo {
    string name;
    string returnType;
    vector<FormalParam>formalParam;
    string domain;
};

class FuncList {
    vector<FuncInfo> functions;
   
    public:
    bool check_param_types(const char* name, const char* domain, vector<const char*> types);
    bool existsFunc(const char* s, const char* domain);
    void addFunc(const char* name, const char* returnType, vector<FormalParam> formalParam, const char* domain);
    void printFunc();
    ~FuncList();
};