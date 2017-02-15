#include <iostream>
#include<string>

using namespace std;
int myAtoi(string str);
//test code
int main()
{
    cout<<"\n"<<myAtoi("       010");
    return 0;
}//end of est code
int myAtoi(string str) {
    //remove all white spaces
    string::iterator it;
    string newStr="";
    for ( it = str.begin() ; it < str.end(); it++){
        if(*it!=' '){
            newStr=newStr+(*it);
        }
    }
    str=newStr;//string without white spaces
    long value=0;//return value
    int len=str.size();
    bool neg=false;//check if number string has - and converted int will be a negative value
    if(str[0]=='-'||str[0]=='+'){
        if(str[0]=='-'){
            neg=true;
        }
        str=str.erase(0,1);//remove if + or - sign is in front of number
        len=len-1;
    }
    for(int i=0;i<len;i++){
        if (int(str[i])<48 || int(str[i])>57){
            return 0;
        }
        value=value*10+int(str[i]-48);
    }
    if(neg){
        value=-value;//reinstate the negative sign if number is negative
    }
    return value;

}
