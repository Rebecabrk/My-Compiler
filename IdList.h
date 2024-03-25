#include <iostream>
#include <vector>
#include <string>
#include <variant>

using namespace std;
struct IdInfo {
    string type;
    string name;
    string domain;
    mutable string value;
};

class IdList {
    vector<IdInfo> vars;
   
    public:
    bool existsVar(const char* s, const char* domain);

    void addVar(const char* type, const char* name, const char* domain, int value);
    void addVar(const char* type, const char* name, const char* domain, float value);
    void addVar(const char* type, const char* name, const char* domain, bool value);
    void addVar(const char* type, const char* name, const char* domain, char value);
    void addVar(const char* type, const char* name, const char* domain, const char * value);

    IdInfo getVar(const char * var_name);

    void updateVar(const char* name, const char* domain, int value);
    void updateVar(const char* name, const char* domain, float value);
    void updateVar(const char* name, const char* domain, bool value);
    void updateVar(const char* name, const char* domain, char value);
    void updateVar(const char* name, const char* domain, const char * value);

    void printVars();
    ~IdList();
};