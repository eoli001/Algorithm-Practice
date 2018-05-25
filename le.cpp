// you can use includes, for example:
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


string convert(string s){
    if(s == "AB" || s == "BA" ){
        return "AA";
    }
    else if(s == "CB" || s == "BC"){
        return "CC";
    }
    else if(s == "AA"){
        return "A";
    }
    else if(s == "CC"){
        return "C";
    }
    return "no rule";
}
string solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int i = 0;
    string copys;
    copys = S;
    while(i < copys.length()-1){
        if (convert(copys.substr(i,2)) == "no rule") {
            i++;
        }
        else{
            string toConvert;
            toConvert = convert(copys.substr(i,2));
            copys.replace(i, 2,  toConvert);

        }
    }
    cout<<copys<<endl;
    return copys;
}

int main(){
    string s,p;
    p = "ABBCC";
    s= solution(p);
    return 0;
}