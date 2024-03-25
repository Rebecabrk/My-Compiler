#include "IdList.h"
#include <iostream>
#include <variant>

using namespace std;

void IdList::addVar(const char *type, const char *name, const char *domain, int value)
{
    IdInfo var = {string(type), string(name), string(domain), to_string(value)};
    vars.push_back(var);
}

void IdList::addVar(const char *type, const char *name, const char *domain, float value)
{
    IdInfo var = {string(type), string(name), string(domain), to_string(value)};
    vars.push_back(var);
}

void IdList::addVar(const char *type, const char *name, const char *domain, bool value)
{
    IdInfo var = {string(type), string(name), string(domain), to_string(value)};
    vars.push_back(var);
}

void IdList::addVar(const char *type, const char *name, const char *domain, char value)
{
    IdInfo var = {string(type), string(name), string(domain), to_string(value)};
    vars.push_back(var);
}

void IdList::addVar(const char *type, const char *name, const char *domain, const char *value)
{
    IdInfo var = {string(type), string(name), string(domain), string(value)};
    vars.push_back(var);
}

void IdList::updateVar(const char *name, const char *domain, int value)
{
    string strvar = string(name);
    string strdomain = string(domain);
    for (const IdInfo &v : vars)
    {
        if (strvar == v.name and strdomain == v.domain)
        {
            v.value = to_string(value);
        }
    }
}

void IdList::updateVar(const char *name, const char *domain, float value)
{
    string strvar = string(name);
    string strdomain = string(domain);
    for (const IdInfo &v : vars)
    {
        if (strvar == v.name and strdomain == v.domain)
        {
            v.value = to_string(value);
        }
    }
}

void IdList::updateVar(const char *name, const char *domain, bool value)
{
    string strvar = string(name);
    string strdomain = string(domain);
    for (const IdInfo &v : vars)
    {
        if (strvar == v.name and strdomain == v.domain)
        {
            v.value = to_string(value);
        }
    }
}

void IdList::updateVar(const char *name, const char *domain, char value)
{
    string strvar = string(name);
    string strdomain = string(domain);
    for (const IdInfo &v : vars)
    {
        if (strvar == v.name and strdomain == v.domain)
        {
            v.value = to_string(value);
        }
    }
}

void IdList::updateVar(const char *name, const char *domain, const char *value)
{
    string strvar = string(name);
    string strdomain = string(domain);
    for (const IdInfo &v : vars)
    {
        if (strvar == v.name and strdomain == v.domain)
        {
            v.value = string(value);
        }
    }
}

bool IdList::existsVar(const char *var, const char *domain)
{
    string strvar = string(var);
    string strdomain = string(domain);
    for (const IdInfo &v : vars)
    {
        if (strvar == v.name and strdomain == v.domain)
        {
            return true;
        }
    }
    return false;
}

void IdList::printVars()
{
    for (const IdInfo &v : vars)
    {
        cout << "name: " << v.name << " type:" << v.type << " domain:" << v.domain << " value: " << v.value << endl;
    }
}

IdList::~IdList()
{
    vars.clear();
}

IdInfo IdList::getVar(const char * var_name){
    string strvar = string(var_name);
    for (const IdInfo &v : vars)
    {
        if (strvar == v.name )
        {
            IdInfo var = {v.type,v.name,v.domain, v.value};
            return var;
        }
    }
    IdInfo var = {"null", "null", "null", "null"};
    return var;
}