#include <iostream>
#include <string>
using namespace std;


void perm(string toperm, string appendTo){
    if(toperm.length()==0){
        cout<<"";
    }
    else if (toperm.length()==1){
        cout<<"\n"<<appendTo+toperm;
    }
    else if (toperm.length()>1){
        for (int i=0;i<toperm.length();i++){
            string temp=toperm;
            char ith=toperm[i];
            temp[i]=temp[0];
            perm(temp.erase(0,1),appendTo+ith);
        }
    }
}

//test code
int main()
{
    string a="abcd";
    cout<<"\nPermutations for string \""<<a <<"\" are: ";
    perm(a,"");
    return 0;
}

