#include <iostream>
#include <string>
#include <vector>

using namespace std;

void KMP(string &s,vector<int> &res){
	for(int i=1;i<s.size();i++){
		int j=res[i-1];
		while(j>0 && s[i]!=s[j]){j=res[j-1];}
		res[i]=j+(s[i]==s[j]);
	}
}

int main()
{
    string test="AACDEACAAAACDEACAAAA";//"A";//"AACDEACAAAACDEACAAAA";//"AABAABAB";
    vector<int> tab(test.size(),0);
	KMP(test,tab);
    cout<<"\nInput String: "<<test;
    cout<<"\nSufix Table: "<<"[";
    for(int i=0;i<tab.size();i++){
        cout<<tab[i]<<"  ";
    }
    cout<<"\b\b]\n";
    return 0;
}
