#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

set<string> permute(string inputString){
    int inputStringSize = inputString.size();
    //use set to avoid duplicates
    set<string> permutations;
    if(inputStringSize==0){
        return permutations;
    }
    else if (inputStringSize==1){
        permutations.insert(inputString);
        return permutations;
    }
    else{
        for(int i=0;i<inputStringSize;i++){
            string inputStringCopy=inputString;
            swap(inputStringCopy[0],inputStringCopy[i]);
            set<string> resultSetFromSubString = permute(inputStringCopy.substr(1));
            for(auto itr=resultSetFromSubString.begin();itr!=resultSetFromSubString.end();itr++){
                permutations.insert(inputStringCopy[0]+ *itr);
            }
        }
        return permutations;
    }
}

//test code
int main(int argc, char *argv[])
{
    if(argc!=2){
        cout<<"\nUsage StringPermutations.o \"string to permute\" \n";
        return 0;
    }
    string inputString = argv[1];
    set<string> permutations = permute(inputString);
    cout<<"\nPermutations of: "<<inputString;
    for(auto itr = permutations.begin(); itr!=permutations.end();itr++){
        cout<<"\n"<<*itr;
    }
    cout<<"\n";
    return 0;
}

