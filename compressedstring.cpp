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
  cout<<"s.lenth" << s.length();
  for(int i = 0; i <= s.length(); i++){
    //cout << "s[i] " << s[i] << endl;
    //cout << "curchar " << curchar << endl;
    cout<<count<<endl;
    if(s[i] == curchar){
      count++;
    }
    else{
      
      if(count > 1){
        cout << "s[i]a " << s[i] << endl;
        savedString = savedString + curchar + to_string(count);
      }
        
      else{
        cout << "s[i]b " << s[i] << endl;
        savedString = savedString + curchar;
        cout << "here "<< curchar<<endl; 
        
      }
        count = 1;
        curchar = s[i];
        cout<< s[i] <<endl;
      
    }
    
    
  }
  return savedString;
}

int main() {
  string s = "aabcc";
  s = outputCompressString(s);
  cout<<s <<endl;
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