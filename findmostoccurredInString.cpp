#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
using namespace std;


vector<string> findmostword(string ss, vector<string> wordsToExclude){
    
    //copy string to array so that we can use strtok_r
    char *str = new char [ss.length()+1];
    strcpy(str,ss.c_str());


    //tokenize by removing "-", space and single quote
    char *token;
    char *rest = str;
    vector<string> s;
    vector<string> result;
    unordered_map<string,int> pair;
    unordered_set<string> setexclde(wordsToExclude.begin(), wordsToExclude.end());

    //multiple delimeter
    while ((token = strtok_r(rest, " '-", &rest))){
        s.push_back(token);

    }

    //hashmap contains all the pair with non excluded word and number of occurence
    for(int i = 0; i < s.size(); i++){

        if(setexclde.find(s[i])==setexclde.end()){
            if (pair.find(s[i]) != pair.end()){
                pair[s[i]] = pair[s[i]] + 1;
            }
            else{
                pair[s[i]] = 1;
            }
        }
        
    }
    

    //go through the pair to find all the max occurrence string
    unordered_map<string,int>::iterator it=pair.begin();
    int count = it->second;
    result.push_back(it->first);
    it++;
    for (; it!=pair.end(); ++it){
        if (it->second > count){
            result.clear();
            count = it->second;
            result.push_back(it->first);
        }
        else if(it->second == count){
            result.push_back(it->first);
        }

    }


    //print all the elements in the result
    for(int i = 0; i < result.size(); i++ ){
        cout << result[i] << endl;
    }
    return result;
}

int main()
{   string ss = "Geek's for for Geek's";
    string wtec[] = {"a", "the","for"};
    vector<string> wordsToExclude(wtec, wtec + sizeof(wtec)/sizeof(string));
    findmostword(ss,wordsToExclude);
    return(0);
}