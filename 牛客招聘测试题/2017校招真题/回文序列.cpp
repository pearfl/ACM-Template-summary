#include<iostream>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    int item[50]={0};
    for(int i=0;i<n;i++){
        cin>>item[i];
    }
    int i=0;
    int j=n-1;
    int res=0;
    while(i<j){
        if(item[i]<item[j]){
            item[i+1]=item[i+1]+item[i];
            res++;
            i++;
        }
        else if(item[i]>item[j]){
            item[j-1]=item[j-1]+item[j];
            res++;
            j--;
        }
        else{
            i++;
            j--;
        }
    }
    cout<<res;
}