#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

bool sortcol(const vector<string>& v1, const vector<string>& v2) {
      return v1[1] > v2[1];
  }

int main ()
{
  map<int,int> mymap;

  mymap[1]=1;
  mymap[2]=2;
  mymap[3]=3;
  mymap[3]=4;


  cout << "mymap[3] is " << mymap[3] << '\n';

  if(mymap[4] == 0){
    cout << "mymap[4] is " << mymap[4] << '\n';
  }
  else{
    cout << "mymap[4] is  not declared."<< '\n';
  }

  
  vector<string> a,b;
  a.push_back("a");
  a.push_back("6");  
  b.push_back("b");
  b.push_back("3");
  vector<vector<string> > c;
  c.push_back(a);
  c.push_back(b);
  sort(c.begin(), c.end(), sortcol);
  for(int i = 0; i < c.size(); i++){
    for(int j = 0; j < c[i].size(); j++){
      cout <<c[i][j]<< " " ;
    }
    cout<<endl;
  }

  return 0;
}
