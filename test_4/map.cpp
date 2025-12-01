#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){

    map<string, int> words;
    words["vermeer"] = 1;

    for(const auto &w : words){
        cout << w.first << ": " << w.second << endl;
    }

    int count = 0;
    if(!(count = words.count("vermeer"))){
        cout << "not found" << endl;
    } else {
        cout << "found " << count << " times" << endl;
    }
    
    return 0;
}

