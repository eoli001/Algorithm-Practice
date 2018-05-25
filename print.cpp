#include <iostream>
#include <vector>
#include <math.h> 
#include <string>
#include <sstream> 
using namespace std;

void PrintColumn(int numCol, string s){

	//copy string to vector for easy accessing
	stringstream ss(s);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> strV(begin,end);

	int maxlength; //maximum length of each column
	int numRow; //total number of row 
	numRow = ceil(float(strV.size())/numCol);
	vector<string> reV(strV.size(), ""); //Rearranged string vector
	vector<int> emptySV(numCol, 0); //srored all the maximum length for each column to print, used for printing spaces
	int index; //index of the original vector of string
	index = 0;
	
	int len;
	for(int Col = 0; Col < numCol; Col++){
		maxlength = 0;
		for(int Row = 0; Row < numRow; Row++){

			if(index >= strV.size()) break;
			
			len = strV[index].length();
			
			if (len > maxlength){
				maxlength = len;
				emptySV[Col] = maxlength;
			} 
			if(numCol * Row + Col > strV.size()-1){
				break;

			}
			else{
				//store the string with organized position, ready to be printed
				reV[numCol * Row + Col] = strV[index];
			}
			index++;
				
		}
	}

	//print all stored string
	for(int k = 0; k < reV.size(); k++){
		string emptyS;
		int numEmpty;
		int indx;
		indx = k % 3;
		numEmpty = emptySV[indx] - reV[k].size() + 1;
		emptyS.assign(numEmpty,' ');
		cout << reV[k] << emptyS;
		if ((k+1) % numCol == 0 && k!= 0) cout << endl;
		
	}
	cout<<endl;
}


int main() {

	string str,str2;
	str = "cat caterpillar pie frog elephant pizza ";

	str2 = "a b c d e f g";
  
  	PrintColumn(3, str);
  	PrintColumn(3, str2);
  
  
  	return 0;
}

