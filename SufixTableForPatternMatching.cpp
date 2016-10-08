#include <iostream>
#include <string>

using namespace std;

void SetTableValue(string input, int *SufixTable, int i, int k){

    if(k==0){
        if (input[i]==input[0]){
            SufixTable[i]=1;
        }
        else{
            SufixTable[i]=0;
        }
    }
    else if(input[i]==input[(SufixTable[k])]){
        SufixTable[i]=SufixTable[k]+1;
    }
    else if((input[i]!=input[(SufixTable[k])])&&(k==SufixTable[k])){
            SufixTable[i]=0;
            //if k=sufixTable[k] then program will go to infinite loop or crash
    }
    else{
        SetTableValue(input,SufixTable, i, SufixTable[k]);
    }

}

void CreateSufixTable(string input, int *SufixTable){
    int len=input.length();
    SufixTable[0]=0;

    for(int i=1;i<len;i++){
        SetTableValue(input,SufixTable, i, i-1);
    }
}

int main()
{
    string A="AACDEACAAAACDEACAAAA";//"A";//"AACDEACAAAACDEACAAAA";//"AABAABAB";
    int *ST;
    ST=new int [A.length()];
    CreateSufixTable(A,ST);
    cout<<"\nInput String: "<<A;
    cout<<"\nSufix Table: "<<"[";
    for(int i=0;i<A.length();i++){
        cout<<" "<<ST[i];
    }
    cout<<"]";
    return 0;
}
