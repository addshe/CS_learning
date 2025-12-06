#include"ClassDeclaration.h"

bool Stack::pop(string &elem){
    if(empty()){
        return false;
    }
    elem = _stack.back();
    _stack.pop_back();
    return true; 
}

bool Stack::peek(string &elem){
    if(empty()){
        return false;
    }
    elem = _stack.back();
    return true;
}

bool Stack::push(const string &elem){
    if(full()){
        return false;
    }
    _stack.push_back(elem);
    return true;
}

bool Stack::find(string &str){
    for(int ix = size()-1; ix >= 0; --ix){
        if(str == _stack[ix]){
            return true;
        }
    }
    return false;
}

int Stack::count(string &str){
    int cnt = 0;
    for(int ix = size()-1; ix >= 0; --ix){
        if(str == _stack[ix]){
            cnt++;
        }
    }
    return cnt;
}