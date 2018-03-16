#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f;

int a[1005];
int temp;
void init(){
    for(int i=1;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                if(i*i*i+j*j*j+k*k*k == 100*i+10*j+k){
                    a[temp++] = 100*i+10*j+k;
                }
            }
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    init();
    int n,m,flag;
    while(~scanf("%d %d",&n,&m)){
        flag = 0;
        for(int i=0;i<temp;i++){
            if(a[i] > m){
                break;
            }else if(a[i] < n){
                continue;
            }else{
                if(a[i+1] > m || i==(temp-1)){
                    printf("%d",a[i]);
                }
                else{
                    printf("%d ",a[i]);
                }
                flag = 1;
            }
        }
        if(!flag) cout<<"no"<<endl;
        else cout<<endl;
    }
    return 0;
}