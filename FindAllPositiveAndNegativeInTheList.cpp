#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> findAllmatch(vector<int> numbers){
	unordered_map<int,int> m;
	vector<int> result;
	for(int i = 0; i < numbers.size(); i++){
		m[numbers[i]] = 1;
	}

	for(int i = 0; i < numbers.size(); i++){
		if(m.find(-(numbers[i]))!= m.end()){
			if(numbers[i] > 0  && m[numbers[i]] == 1)
				result.push_back(numbers[i]);
				m[numbers[i]] = 0;
		}
	}
	return result;
}

int main(){
	vector<int> v;
	vector<int> input;//Input: [-19, 12, 5, -3, -12, 8, 3]
	input.push_back(-19);
	/*input.push_back(12);
	input.push_back(5);
	input.push_back(0);
	input.push_back(0);
	input.push_back(-3);
	input.push_back(-12);
	input.push_back(-12);
	input.push_back(8);
	input.push_back(3);*/
	v = findAllmatch(input);
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	}
	return 0;
}