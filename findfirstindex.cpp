#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main ()
{
  vector<double> vec;
  vec.push_back(2);
  vec.push_back(5);
  vec.push_back(4);
  vec.push_back(2);
  unordered_map<double,double> mymap;
  for(int i = 0; i < vec.size(); i++){
    if(mymap.find(vec[i]) == mymap.end()){
      mymap[vec[i]] = i; 
    }
  }
  

  

  unordered_map<double,double>:: const_iterator it = mymap.begin();
  for(;it !=mymap.end();it++){
    cout << it->first << " index is " <<it->second << endl;
  }

  return 0;
}