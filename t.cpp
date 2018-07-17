// you can use includes, for example:
 #include <algorithm>
 #include <vector>
 #include <iostream> 
 #include <string>
 #include <map>
 using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<string> &T, vector<string> &R) {
    // write your code in C++14 (g++ 6.2.0)
    map<int, int> m;
    int cou;
    cou = 0;
    for(int i = 0; i < T.size(); i++){
        for(int j = 0; j < T[i].length();j++){

            if(isdigit(T[i][j])){
                int num;
                num =  T[i][j] - '0';;
                if(m.find(num)==m.end()){
                    
                    if(R[i] == "OK"){
                        m[num] = 1;
                    }

                    else
                        m[num] = 0;
                }
                else{
                    if(R[i] == "OK"){ 
                        if (m[num] != 0)
                            m[num] = 1;
                    }
                    else
                        m[num] = 0;
                }
                break;
            }

        }
        
    }
    int mapsize = 0;
    for (map<int,int>::iterator it=m.begin(); it!=m.end(); ++it){
        cout << "key: "<<it -> first << " value:" << it -> second << endl;
        mapsize++;
        
        if(it -> second > 0){
            
            cou++;
        }
        
    }
    int result, s;
    s = m.size();
    result = cou  * 100 / s;
    cout << result<< endl;
    return result;
}

int main(){
    vector<string> T,R;
    T.push_back("codility1c");
    T.push_back("codility3");
    T.push_back("codility2");
    T.push_back("codility1b");
    T.push_back("codility1a");

    R.push_back("Wrong answer");
    R.push_back("OK");
    R.push_back("OK");
    R.push_back("Runtime error");
    R.push_back("OK");
    solution(T,R);

}