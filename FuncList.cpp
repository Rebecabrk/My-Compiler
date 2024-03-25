#include "FuncList.h"
using namespace std;

bool FuncList::existsFunc(const char* s, const char* domain){
    string strvar = string(s);
    string strdomain = string(domain);
     for (const FuncInfo& f : functions) {
        if (strvar == f.name and strdomain == f.domain) { 
            return true;
        }
    }
    return false;
}

void FuncList::addFunc(const char* name, const char* returnType, vector<FormalParam> formalParam, const char* domain){
    FuncInfo f = {string(name), string(returnType), formalParam, string(domain)};
    functions.push_back(f);
}

void FuncList::printFunc(){
    for(auto f: functions){
        cout << "name: " << f.name << "  returnType: " << f.returnType << " FormalParams: \n";
        for(auto p: f.formalParam){
            cout <<"name: " <<  p.name << " type: " << p.type << '\n';
        }
        cout << "domain: " << f.domain << '\n';
    }
}

FuncList::~FuncList(){
    functions.clear();
}

bool FuncList::check_param_types(const char* name, const char* domain, vector<const char*>types){
    vector<string> result;
    string strname = string(name);
    string strdomain = string(domain);
     for (const FuncInfo& f : functions) {
        if (strname == f.name and strdomain == f.domain) { 
            if(f.formalParam.size() != types.size())
                return 0;
            else
            {
                for(int i=0; i<types.size(); i++){
                    if(f.formalParam[i].type != types[i])
                        return 0;
                }
            }
        }
    }
    return 1;
    
}