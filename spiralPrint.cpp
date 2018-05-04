#include <stdio.h>
#include <iostream>
using namespace std;

#define R 3
#define C 6
 
void spiralPrint(int m, int n, int a[R][C])
{
      
    for(int k = 0; k < m; k++){
        for(int l = 0; l < n; l++){
            cout << a[k][l] << " ";
        }
    }
    cout<<endl;

    

}
 

int main()
{
    int a[R][C] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };
 
    spiralPrint(R, C, a);
    return 0;
}
