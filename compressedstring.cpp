#include <iostream>
using namespace std;


 
string outputCompressString(string s){
  int count=0;
  char curchar;
  curchar = '\0';
  count = 1;
  string savedString;
  if(s.length() == 0){
    return "";
  }
  for(int i = 0; i <= s.length(); i++){
    if(s[i] == curchar){
      count++;
    }
    else{
      
      if(count > 1){
        savedString = savedString + curchar + to_string(count);
      }
        
      else{
        savedString = savedString + curchar;
        
      }
        count = 1;
        curchar = s[i];
      
    }
    
    
  }
  return savedString;
}

int main() {

  string s = "aabc";
  s = outputCompressString(s);
  cout<< s <<endl;
  string s1 = "aabcC";
  s1 = outputCompressString(s1);
  cout << s1 <<endl;

  string s2 = "";
  s2 = outputCompressString(s2);
  cout << s2 <<endl;

  string s3 = "aaaaab";
  s3 = outputCompressString(s3);
  cout << s3 <<endl;
  
  string s4 = " ";
  s4 = outputCompressString(s4);
  cout << s4 <<endl;

  string s5 = "aaaaaa";
  s5 = outputCompressString(s5);
  cout << s5 <<endl;

  string s6 = "aaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbb";
  s6 = outputCompressString(s6);
  cout << s6 <<endl;

  string s7 = "abcabca";
  s7 = outputCompressString(s7);
  cout << s7 <<endl;

  string s8 = "aabbcc";
  s8 = outputCompressString(s8);
  cout << s8 <<endl;

  string s9 = "abccab";
  s9 = outputCompressString(s9);
  cout << s9 <<endl;

  string s10 = "abbbb";
  s10 = outputCompressString(s10);
  cout<< s10 <<endl;

  string s11 = "   ";
  s11 = outputCompressString(s11);
  cout<< s11 <<endl;

  return 0;
}


/* 
Your last C/C++ code is saved below:
#include <iostream>
using namespace std;

int main() {
  cout<<"Hello";
  return 0;
}


// Write a function that gets a string and compresses it, 
// the function should return the compressed string is it was 
// indeed shorter that the original.

// input: acccb      → returns ac3b
// input:acb         → returns acb
// input: abbbcbbb   → returns ab3cb3
aaccb  
a2c2b
*/