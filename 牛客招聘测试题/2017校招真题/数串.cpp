#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main(){
    int count;
    while(cin>>count){
        vector<string> inputStrs;
        string curInputStr;
        for(int i = 0; i<count; ++i){
            cin>>curInputStr;
            inputStrs.push_back(curInputStr);
        }
             
        for(int shift = 0; shift<inputStrs.size()-1; ++shift){
            for(int index = 0; index<inputStrs.size()-1-shift; ++index){
                if((inputStrs[index]+inputStrs[index+1])<(inputStrs[index+1]+inputStrs[index])){
                swap(inputStrs[index],inputStrs[index+1]);
                }
            }
        }
     
        for(string str: inputStrs){
            cout<<str;
        }
        cout<<endl;
    }
    return 0;
}