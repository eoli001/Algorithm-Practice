 #include <algorithm>
 #include <vector>
 #include <iostream>
 #include <string>
 using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &G) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> rspvector(3,0);
    char chosenG;
    int maxSoFar;
    char secChosen;
    for(int i = 0; i < G.length(); i++){
        if(G[i] == 'R'){
            rspvector[0]++;
        }
        else if(G[i] == 'S'){
            rspvector[1]++;
        }
        else if(G[i] == 'P'){
            rspvector[2]++;
        }
    }
    int score1 = 0;
    int score2 = 0;
    int score3 = 0;
    
    score1 = rspvector[0]*1 + rspvector[1]*2;
    cout<<"score1: "<<score1<< endl;
    
    score2 = rspvector[1]*1 + rspvector[2]*2;
    cout<<"score2: "<<score2<< endl;
    
    score3 = rspvector[0]*2 + rspvector[2]*1;
    cout<<"score3: "<<score3<< endl;
    
    
    maxSoFar = max(score1, score2);
    maxSoFar = max(maxSoFar, score3);
    return maxSoFar;
    
}

int main(){
    int sc;
    string s;
    s = "RRPSS";
    sc = solution(s);
    cout<< sc << endl;
}