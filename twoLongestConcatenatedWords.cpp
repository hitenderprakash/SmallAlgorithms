#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <fstream>
#include <iterator>
using namespace std;
bool isConcatenatedWord(string word,unordered_set<string> &se,int len);
bool isWordInCollection(string word,unordered_set<string> &se);
//used to sort strings by their size
struct compare{
    bool operator()(const std::string& first, const std::string& second){
        return first.size() > second.size();
    }
};
//
int main()
{
    unordered_set<string> words;
	ifstream fobject("E:/CPP/Mad/words.txt", ifstream::in);
    istream_iterator<string> fitr(fobject);
    int count = 0;
    //read file
    while(fitr != istream_iterator<string>()){
        words.insert(*fitr);
        count++;
        fitr++;
    }
    //cout<<"\n Done with file read, Total words: "<<count;
    auto it=words.begin();
    vector<string> v(words.begin(),words.end());
    //cout<<"\n Done with copying to vector: "<<count;
    compare c;
    std::sort(v.begin(),v.end(),c);
    //cout<<"\n Done with sorting the vector: "<<count;
    string firstLongest="";
    string secondLongest="";
    for(int i=0; i<v.size();i++){
       // words.erase(v[i]);//delete so that it is not found in the direct search
       //no need to delete it if isConcatenatedWord method can itself checks for first time call when each word would be found in hashmap
       // one way is to pass the original word's size in method and make sure that this entire word match does not cause true return
        if(isConcatenatedWord(v[i],words,v[i].size() )){
            if(firstLongest==""){
                firstLongest=v[i];
            }
            else if(secondLongest==""){
                secondLongest=v[i];
                break;
            }
        }
       // words.insert(v[i]);//restore the original hashmap
    }
    cout<<"\nFirst Longest concatenated word: "<<firstLongest;
    cout<<"\nSecond Longest concatenated word: "<<secondLongest;
    return 0;
}
bool isConcatenatedWord(string word,unordered_set<string> &se,int len){
    if(word.size()==0){
        return false;
    }
    if(isWordInCollection(word,se) && word.size()<len){ //word size is matched with the size of original word
        return true;                                    //Just to ensure that the original word was not directly found in hashmap
    }                                                   // but some suffix was found. Otherwise on first call every word would return true
    for (int i = 1; i < word.length(); i++) {
        string prefix = word.substr(0, i);
        string remainder = word.substr(i, word.length());

         if(isWordInCollection(prefix,se)){
            if (remainder.size() == 0){
                    return true;
            }
            bool res=isConcatenatedWord(remainder,se,len);
            if(res){
                return res; //only return if word is concatenated. else continue with other combinations
            }
        }
    }
    return false;
}
bool isWordInCollection(string word,unordered_set<string> &se){
    if(se.find(word)!=se.end()){
        return true;
    }
    else{
        return false;
    }
}
