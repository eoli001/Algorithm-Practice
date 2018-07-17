#include <iostream>
#include <string>
#include <vector>
using namespace std;



/* [ -5, -4 ,-3, -2, -1, 0, 1, 2, 3, 4, 5, 6 ]
  -> [0, 1, 2, -5, -4, -3, -2, -1, 3, 4, 5, 6]

  [5, 7, 2, -9, 6, 1, -5, 3, -6]
  -> [5, 7, 2, -9, -5, -6, 6, 1, 3]
 */
vecror<int> moveNegativesToMiddle(int numbers[], int length){
    int mid,curmid,lenpos,indx;
    vector<int> temp;
    lenpos = 0;
    curmid = 0;
    for(int m=0; m < length; m++){
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
                curmid++;
            }

        }
    }
    for(int j = 0; j < length; j++){
        if(numbers[j] < 0){
            temp.push_back(numbers[j]);
        }
    }
    for(int k= indx; k < length; k++){
        if(numbers[k]>0){
            temp.push_back(numbers[k]);
        }
    }
    return temp;
}


int main()
{
    std::cout << "Hello world - C++ !" << endl;
    return 0;
}