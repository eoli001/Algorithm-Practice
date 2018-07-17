#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int sumofprime(int n){
  vector<bool> prime(n+1, true);
  for(int i = 0; i < v.size(); i++){
    cout<< v[i] << endl;
  }

  for(int i=2; i*i<=n; i++){

    if(prime[i]){
      for(int j=2*i; j <=n; j+=i){
        prime[i] = false;
      }
    }
    
  }
  int sum = 0;
  for(int k=2; k<=n; k++){
    if (prime[k])
      sum = sum + k;
  }

  return sum;

}

int main ()
{
  /*vector<double> vec;
  vec.push_back(2);
  vec.push_back(5);
  vec.push_back(4);
  vec.push_back(2);
  unordered_map<double,double> mymap;
  for(int i = 0; i < vec.size(); i++){
    if(mymap.find(vec[i]) == mymap.end()){
      mymap[vec[i]] = i; 
    }
  }*/
  sumofprime(3);

  return 0;
}