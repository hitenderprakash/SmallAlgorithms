#include <iostream>
#include <string>
#include <strings.h>
#include <vector>
#include <algorithm>

using namespace std;
int contains(string str, string sub_str);
string Remove(string input, string toBeRemoved);
vector<string> splitbyMultiChar(string str, string sep);
string ReplaceSubStr(string input, string toBeReplaced, string Replacement);
string RemoveAll(string input, string toBeRemoved);
string ReplaceAll(string input, string toBeReplaced, string Replacement);
vector<string> split2(string str, string sep);
int main()
{
    string a="Hi my name is Hitender and Hitender";
    string b="Hitender";
    string c="brabcdebrefghbrijklbr";
    //a=a.erase((contains(a,b)),b.size());
    //cout<< ReplaceAll(a,"Hitender","Rakesh");
    vector<string> d=splitbyMultiChar(c,"br");
    for(int i=0;i<d.size();i++){
        cout<<"\n"<<d[i];
    }
    return 0;
}
int contains(string str, string sub_str){
    int index=str.find(sub_str);
    if(index!=std::string::npos){
        return index;
    }
    return -1;
}
vector<string> splitbyMultiChar(string str, string sep){
    char* cstr = const_cast<char*>(str.c_str());
    char* csep= const_cast<char*>(sep.c_str());
    vector<string> retVect;
    char* current=strtok(cstr,csep);
    while(current!=NULL){
        retVect.push_back(current);
        current=strtok(NULL,csep);
    }
    return retVect;
}

string Remove(string input, string toBeRemoved){
    int index=contains(input, toBeRemoved);
    if (index==-1){
        return input;
    }
    else{
        return(input.erase(index,toBeRemoved.size()));
    }
}

string ReplaceSubStr(string input, string toBeReplaced, string Replacement){
    int index=contains(input, toBeReplaced);
    if (index==-1){
        return input;
    }
    else{
        if(Replacement==""){
            return(input.erase(index,toBeReplaced.size()));
        }
        else{
            return(input.replace(index,toBeReplaced.size(),Replacement));
        }
    }
}
string RemoveAll(string input, string toBeRemoved){
    while(true){
        if (input==Remove(input,toBeRemoved)){
            break;
        }
        input=Remove(input,toBeRemoved);
    }
    return input;
}

string ReplaceAll(string input, string toBeReplaced, string Replacement){
    while(true){
        if (input==ReplaceSubStr(input,toBeReplaced,Replacement)){
            break;
        }
        input=ReplaceSubStr(input,toBeReplaced,Replacement);
    }
    return input;
}
vector<string> split(string input, string delimit){
    vector<string> splited;
    if (input.size()==0||delimit==""){
        splited.push_back(input);
        return splited;
    }
    string cur="";
    while (true){
        if(input.size()==0){
            break;
        }
        int found=input.find(delimit);
        if(found==std::string::npos){
            splited.push_back(input);
            return splited;
        }
        else{
            splited.push_back(input.substr(0,found));
            input=input.substr(found+delimit.size(),input.size()-1);
        }
    }
    return splited;
}
