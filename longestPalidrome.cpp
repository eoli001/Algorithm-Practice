
#include <iostream>
#include <algorithm>

using namespace std;

string longestPalindrome(string s) {
		int strlength = s.length();
        if( strlength <= 1) 
        	return s; 
        int start = 0;
        int maxlenth = 1;
        bool isPalindromeal[1000][1000] = {false};
        
        for(int i = strlength-1; i >= 0; i--) {
            for(int j = i; j < strlength; j++) {
                if((i+1> j-1 || isPalindromeal[i+1][j-1]) && s[i]==s[j]) {
                    isPalindromeal[i][j] = true;
                    if(j-i+1 > maxlenth) {
                        maxlenth = j-i+1;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start,maxlenth);
    }

int main(int argc, char *argv[])
{
	string s("adsdcvbcvdfgvfmffofffefeffefefffoffmfgcgfgbffgfg");

	cout << longestPalindrome(s) << endl;

	return 0;
}