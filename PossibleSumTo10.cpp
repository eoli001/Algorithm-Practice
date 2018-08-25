
#include <iostream>
#include <algorithm>
using namespace std;

//solution 1
int findNumberofSumAddToTenSol1(int a, int b, int n){
	//int n = 10;
	int result = 0;
	if(a+b < n){
		return 0;
	}
	for(int i = a; i > 0; i--){
		if(i+b >= n && i < n){
			result++;
		}
	}
	return result;
}

//solution 2
int findNumberofSumAddToTenSol2(int a, int b, int n){
	//int n = 10;
	int result = 0;
	int sum = a+b;

	//case 1: (a + b less than n) -> result
	//i.e. (4.4)
	if(a+b < n){
		return 0;
	}
	//case 2: (a+b-1 < 2n, means both a and b are <= n-1)) 
	//i.e. (9,9),(8,5)
	result = sum-n+1; 
	
	//case 3: (one greater than n, one less than n) 
	//i.e. (8,15),(20,5)
	if(max(a,b) > n && min(a,b) < n){
		result = min(a,b);
	}

	//case 4: (a+b+1 >= 2n, means min(a,b) >= n-1, max(a,b) >= n) 
	//(10,9), (9,10), (10,10), (30,35)
	else if(result >= n){
		result = n-1;
	}
	return result;
}



int main(){
	int result;
	result = findNumberofSumAddToTenSol1(1,2,10);
	cout<< "sol1 set 1 result:" << result << endl;
	result = findNumberofSumAddToTenSol2(1,2,10);
	cout<< "sol2 set 1 result:" << result << endl;

	result = findNumberofSumAddToTenSol1(5,5,10);
	cout<< "sol1 set 2 result:" << result << endl;
	result = findNumberofSumAddToTenSol2(5,5,10);
	cout<< "sol2 set 2 result:" << result << endl;

	result = findNumberofSumAddToTenSol1(20,2,10);
	cout<< "sol1 set 3 result:" << result << endl;
	result = findNumberofSumAddToTenSol2(20,2,10);
	cout<< "sol2 set 3 result:" << result << endl;

	result = findNumberofSumAddToTenSol1(3,20,10);
	cout<< "sol1 set 4 result:" << result << endl;
	result = findNumberofSumAddToTenSol2(3,20,10);
	cout<< "sol2 set 4 result:" << result << endl;

	result = findNumberofSumAddToTenSol1(30,30,10);
	cout<< "sol1 set 5 result:" << result << endl;
	result = findNumberofSumAddToTenSol2(30,30,10);
	cout<< "sol2 set 5 result:" << result << endl;

	result = findNumberofSumAddToTenSol1(5,8,10);
	cout<< "sol1 set 6 result:" << result << endl;
	result = findNumberofSumAddToTenSol2(5,8,10);
	cout<< "sol2 set 6 result:" << result << endl;

	result = findNumberofSumAddToTenSol1(8,4,10);
	cout<< "sol1 set 7 result:" << result << endl;
	result = findNumberofSumAddToTenSol2(8,4,10);
	cout<< "sol2 set 7 result:" << result << endl;

	result = findNumberofSumAddToTenSol1(6,5,10);
	cout<< "sol1 set 8 result:" << result << endl;
	result = findNumberofSumAddToTenSol2(6,5,10);
	cout<< "sol2 set 8 result:" << result << endl;

	result = findNumberofSumAddToTenSol1(10,10,10);
	cout<< "sol1 set 9 result:" << result << endl;
	result = findNumberofSumAddToTenSol2(10,10,10);
	cout<< "sol2 set 9 result:" << result << endl;

	result = findNumberofSumAddToTenSol1(9,10,10);
	cout<< "sol1 set 10 result:" << result << endl;
	result = findNumberofSumAddToTenSol2(9,10,10);
	cout<< "sol2 set 10 result:" << result << endl;

	result = findNumberofSumAddToTenSol1(10,8,10);
	cout<< "sol1 set 11 result:" << result << endl;
	result = findNumberofSumAddToTenSol2(10,8,10);
	cout<< "sol2 set 11 result:" << result << endl;

	result = findNumberofSumAddToTenSol1(9,11,10);
	cout<< "sol1 set 11 result:" << result << endl;
	result = findNumberofSumAddToTenSol2(9,11,10);
	cout<< "sol2 set 11 result:" << result << endl;



}

//5, 5 = 1
//5,6 = 2

//7,7    7,3; 6,4; 5,5; 3,7; 4,6;
//3,4,5,6,7 14-10+1

//3,8    3,7; 2,8; 

//10, 10 (1,2,3,4,5,6,7,8,9) (9,8,7,6,5,4,3,2,1)
//10,9 (1,2,3,4,5,6,7,8,9) (9,8,7,6,5,4,3,2,1)
//11,11 



