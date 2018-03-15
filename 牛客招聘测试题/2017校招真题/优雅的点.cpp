#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n = 0;
    while(cin >> n){
        int res = 0;
        for( int i = 0; i < sqrt(n); i++ ){
            double j = sqrt(n - i*i);
            if( (int)j >= j )
                res++;
        }
        cout<<4*res<<endl;
    }
}