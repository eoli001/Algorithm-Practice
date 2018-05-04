#include<iostream>
#include<string>
#include<set>
using namespace std;

string removeDuplicates(std::string const &str) { 
    set<char> chars( str.begin(), str.end());

    return string(chars.begin(), chars.end());
}


int main(){
	string s;
	s = "aaabccddeef";
	cout<< removeDuplicates(s) << endl;;
	return 0;
}

