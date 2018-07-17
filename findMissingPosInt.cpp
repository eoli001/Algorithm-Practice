// you can use includes, for example:
 #include <algorithm>
 #include <vector>
 #include <iostream> 
 using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int smallest = 1;
    for(int i = 0; i < A.size(); i++){
        if(A[i] > smallest)
            return smallest;
        else if(smallest <= A[i])
            smallest++;
           
    }
}
