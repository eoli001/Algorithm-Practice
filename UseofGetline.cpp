#include <stdio.h>      
#include <stdlib.h>     
#include <math.h> 
#include <iostream>
#include <map>
#include <sstream>
#include <string> 
#include <algorithm> 

using namespace std;

typedef map<string, string> M;
bool value_comparer(M::value_type &t1, M::value_type &t2){
		return t1.second<t2.second;
	}

int main(){
	map<pair<string,string>,int> mp;
	M:: const_iterator it;
	string line;
	
	//using mt = decltype(mp) :: value_type;

	

	while(getline(cin, line)){
		istringstream iss(line);
		string s1,s2;
		int i;
		if(iss >> s1 >> s2 >> i){

			it = mp.find(make_pair(s1,s2))
			if(it != mp.end()){
				it->second = it->second + atoi(i);
			}
			else {
				mp.insert(make_pair(make_pair(s1,s2),atoi(i)));
			}
		}
	}


	

	

	M::iterator itor = max_element(mp.begin(), mp.end(), value_comparer);

	cout<< itor->first.first << itor->first.second << itor->second;

	return 0;
}


