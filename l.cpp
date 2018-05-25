// you can use includes, for example:
#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<iostream>
#include<cstring>
 using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<string> SplitString(string S, const char* d){
	char *str = new char [S.length()+1];
    strcpy(str,S.c_str());
    char *token;
    char *rest = str;
    vector<string> s;

    while ((token = strtok_r(rest, d , &rest))){
        s.push_back(token);

    }
    return s;
}

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)

    vector<string> s;
    const char* d;
    d = ".?!";
    s = SplitString(S, d);
	for(int i = 0; i < s.size(); i++){
		//cout << s[i]<< endl;
	}
	vector<vector<string> > ds;
	vector<string> temp;
	const char* e;
	e = " ";
	int maxlength = 0;
	for(int j = 0; j < s.size(); j++){
		
		temp = SplitString(s[j], e);
		if(maxlength < temp.size()) maxlength = temp.size();
		

	}
	
    return maxlength;
}

int main(){

	int i;
	string s;
	s = "We test coders. Give us a try?";
	i = solution(s);
	cout<< "maxlength: "<< i <<endl;
	return i;
}