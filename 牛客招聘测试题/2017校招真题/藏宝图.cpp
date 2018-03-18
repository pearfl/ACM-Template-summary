#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	//freopen("input.txt","r",stdin);

	string a,b;
	cin>>a>>b;

	int len1 = a.length();
	int len2 = b.length();
	/*cout<<len1<<endl;
	cout<<len2<<endl;*/
	int temp = 0,flag = 0;
	for(int i=0;i<len1;i++){
		if(a[i] == b[temp]){
			temp++;
			if(temp == len2){
				flag = 1;
				break;
			}
		}
	}

	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;


	return 0;
}