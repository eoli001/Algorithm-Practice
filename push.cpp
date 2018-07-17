#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;



/* [ -5, -4 ,-3, -2, -1, 0, 1, 2, 3, 4, 5, 6 ]
  -> [0, 1, 2, -5, -4, -3, -2, -1, 3, 4, 5, 6]

  [5, 7, 2, -9, 6, 1, -5, 3, -6]
  -> [5, 7, 2, -9, -5, -6, 6, 1, 3]
 */
vector<int> moveNegativesToMiddle(int *numbers, int length){
    int mid,curmid,lenpos,indx;
    vector<int> temp;
    lenpos = 0;
    curmid = 0;
    for(int m=0; m < (sizeof(numbers)/sizeof(*numbers)); m++){
        if(numbers[m]> 0)
            lenpos++;
    }

    mid = lenpos/2;
    for(int i = 0; i < length; i++){
        indx = i;
        
        if(curmid == mid){
            break;
        }
            
        else{
            if(numbers[i] >= 0){
                temp.push_back(numbers[i]);
                cout<< "pushed: " << numbers[i] << endl;
                curmid++;
            }

        }
    }
    for(int j = 0; j < length; j++){
        if(numbers[j] < 0){
            temp.push_back(numbers[j]);
            cout<< "pushed: " << numbers[j] << endl;

        }
    }
    for(int k= indx; k < length; k++){
        if(numbers[k]>0){
            temp.push_back(numbers[k]);
            cout<< "pushed: " << numbers[k] << endl;

        }
    }

    for(int k= 0; k < temp.size(); k++){
        cout<< "begin "<<temp[k] << endl;
    }
    return temp;
}


int main()
{
    int c[] = {-5,-4,-3,-2,-1,0,1,2,3,4,5,6};

    vector<int> d;
    d = moveNegativesToMiddle(c, 12);
    for(int k= 0; k < d.size(); k++){
        cout<< "begin "<<d[k] << " ";
    }
    cout<<endl;
    //std::cout << "Hello world - C++ !" << endl;
    return 0;
}