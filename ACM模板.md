# ACM代码整合

[TOC]

如果发现文章中有不正确的地方，欢迎联系本人，感谢指出问题的每个人

PS：本文一切代码均有C/C++编写，参与JAVA组的人可以理解思想了以后尝试改写



### ！！！特别提醒

1、注意程序最后应有返回值，且返回值为0

2、万能头文件可以使用(bits/stdc++.h)，比赛中使用c++的方法是，记得开全局空间using namespace std;

3、熟悉STL用法，包括vector、set、map、pair等结构的用法，这会给你剩下许多时间

4、例如max_element、lower_bound函数的用法请熟悉

5、在不能保证自己的算法的绝对正确性的情况下，可以选择保住现有的分，而不去尝试难度较高且自己没有把握的方法



### 1、最小公倍数gcd

```c++
int gcd(int a,int b){
	return b == 0 ? a : gcd(b,a%b);
} 
```



### 2、最大公约数lcm

```c++
int gcd(int a,int b){
	return b == 0 ? a : gcd(b,a%b);
} 

int lcm(int a,int b){
	return a*b/gcd(a,b);
}
```



### 3、Fibonacci数列 

采用记忆化搜索的写法，或者使用状态转移的方法推导

- 记忆化搜索写法

```c++
int dp[1005];
int dfs(int n){
	if(n==1 || n==2){
		return 1;
	}
	if(dp[n] > 0){
		return dp[n];
	}else{
		dp[n] = dfs(n-1) + dfs(n-2);
		return dp[n];
	}	
}

```


- 状态转移写法

```c++
int dp[1000];
dp[1] = 1;
dp[2] = 1;
for(int i=3;i<1000;i++){
  dp[i] = dp[i-1] + dp[i-2];
} 
```



### 4、memset初始化

- memset在整形数组中推荐两种用法

```c++
int dp[1005];
memset(dp,0,sizeof(dp));//dp中的值全部置为了0
memset(dp,-1,sizeof(dp));//dp中的值全部置为了-1
```

 有人问1,2,3其他的可行，当然是不行的，至于原因有兴趣想要知道的话，可以在网上了解

- memset在char数组中
```c++
char str[1005];
memset(str,0,sizeof(str));
```
这样就是将char数组重置了，在多组输入的情况中，memset将会是一个非常高效的方法



### 5、fill初始化

```c++
int dp[100];
fill(dp,dp+10,5);
```

此时dp[0] -> dp[9]的值全部被置为了5

```c++
char str[100];
fill(str,str+10,'m');
```

此时str[0] -> str[9]的值全部被置为了m



以上两个例子相信大家一下子就对fill有所了解了吧，在实际运用中大家可以根据自己的需要使用fill和memset



### 6、ctype.h头文件

|   函数名称   |         函数原型         |                  函数功能                   |            函数返回            |
| :------: | :------------------: | :-------------------------------------: | :------------------------: |
| isalpha  | int isalpha(char ch) |                检查ch是否是字母                | 是字母返回非0（在vs2015中为2），否则返回 0 |
| iscntrl  | int iscntrl(int ch)  |  检查ch是否控制字符(其ASCII码在0和0x1F之间,数值为 0-31)  |        是返回非0,否则返回 0        |
| isdigit  | int isdigit(char ch) |             检查ch是否是数字(0-9)              |        是返回非0,否则返回0         |
| isgraph  | int isgraph(int ch)  | 检查ch是否可显示字符(其ASCII码在0x21到0x7E之间),不包括空格  |        是返回非0,否则返回0         |
| islower  | int islower(int ch)  |             检查ch是否小写字母(a-z)             |        是返回非0,否则返回0         |
| isupper  | int isupper(int ch)  |            检查ch是否是大写字母(A-Z)             |        是返回非0,否则返回0         |
| tolower  | int tolower(int ch)  |              将ch字符转换为小写字母               |      返回ch所代表的字符的小写字母       |
| toupper  | int toupper(int ch)  |              将ch字符转换成大写字母               |         与ch相应的大写字母         |
| isalnum  | int isalnum(int ch)  |              检查ch是否是字母或数字               |      是字母或数字返回非0,否则返回0      |
| isprint  | int isprint(int ch)  | 检查ch是否是可打印字符(包括空格),其ASCII码在0x20到0x7E之间  |        是返回非0,否则返回0         |
| ispunct  | int ispunct(int ch)  | 检查ch是否是标点字符(不包括空格),即除字母,数字和空格以外的所有可打印字符 |        是返回非0,否则返回0         |
| isspace  | int isspace(int ch)  |        检查ch是否是空格符和跳格符(控制字符)或换行符         |        是返回非0,否则返回0         |
| isxdigit | int isxdigit(int ch) |    检查ch是否是一个16进制数学字符(即0-9,或A-F,或a-f)    |        是返回非0,否则返回0         |
| isascii  | int isascii(int ch)  |           测试参数是否是ASCII码0-127            |        是返回非0,否则返回0         |



### 7、素数系列

- 埃拉托斯特尼筛法，或者叫埃氏筛法

```c++
const int N = 100005;  
bool prime[N];  
void init(){  
    for(int i=2;i<N;i++) prime[i]=true;//先全部初始化为素数  
    for(int i=2;i*i<N;i++){  
        if(prime[i]){//如果i是质数  
            for(int j=i*i;j<N;j+=i){//从i的两倍开始的所有的倍数(i*i也行)  
                prime[j] = false;  
            }  
        }  
    }  
}  
```

- 预处理每个数的所有质因数
```c++
const int N = 100000 + 5;  
vector<int > prime_factor[N];  
void init(){  
    for(int i = 2; i < N; i ++){  
        if(prime_factor[i].size() == 0){//如果i是质数   
            for(int j = i; j < N; j += i){  
                prime_factor[j].push_back(i);   
            }  
        }  
    }  
} 
```

- 比如预处理每个数的所有因数

```c++
const int N = 100000 + 5;  
vector<int > factor[N];  
void init(){  
    for(int i = 2; i < N; i ++){  
        for(int j = i; j < N; j += i){  
            factor[j].push_back(i);  
        }  
    }  
}
```

- 预处理每个数的质因数分解

```c++
const int N = 100000 + 5;  
vector<int > prime_factor[N];  
void init(){  
    int temp;  
    for(int i = 2; i < N; i ++){  
        if(prime_factor[i].size() == 0){  
            for(int j = i; j < N; j += i){  
                temp = j;  
                while(temp % i == 0){  
                    prime_factor[j].push_back(i);  
                    temp /= i;  
                }  
            }  
        }  
    }  
}
```

http://blog.csdn.net/laichilizi/article/details/79390020

质因数分解题目↑（输入两个整数a、b，每行输出一个数的分解，形如k=a1*a2*a3...(a1<=a2<=a3....）

```c++
#include<bits/stdc++.h>    
using namespace std;    
const int N = 100000 + 5;    
vector<int > prime_factor[N];    
void init(){    
    int temp;    
    for(int i = 2; i < N; i ++){    
        if(prime_factor[i].size() == 0){    
            for(int j = i; j < N; j += i){    
                temp = j;    
                while(temp % i == 0){    
                    prime_factor[j].push_back(i);    
                    temp /= i;    
                }    
            }    
        }    
    }    
}    
int main()  
{    
    init();   
      
    int a,b;  
    scanf("%d %d",&a,&b);  
    vector<int>::iterator it;  
    for(int i=a;i<=b;i++){  
        cout<<i<<"=";  
        for(it = prime_factor[i].begin(); it != prime_factor[i].end(); it++){  
            if(it != prime_factor[i].end()-1) cout << *it <<"*";  
            else cout<<*it<<endl;  
        }  
              
    }   
}  
```



### 8、BFS系列

http://blog.csdn.net/laichilizi/article/details/75024841

- 马的移动↑，BFS入门题

http://blog.csdn.net/laichilizi/article/details/79383954

- 学霸的迷宫↑，BFS+记录操作方向

### 9、DFS系列

http://blog.csdn.net/laichilizi/article/details/79388913

- 正则问题↑，一个由x()|组成的正则表达式。输入长度不超过100，保证合法，求这个正则表达式能接受的最长字符串的长度

http://blog.csdn.net/laichilizi/article/details/78714582

- POJ-2386，简单区域连通问题，↑



### 10、动态规划（01背包，完全背包）

- 01背包（记忆化搜索）

```c++
#include<bits/stdc++.h>  
using namespace std;  
typedef long long ll;  
  
int n,W;  
int dp[105][10005];  
int w[105],v[105];  
  
int rec(int i,int j){  
    if(dp[i][j] >= 0){  
        return dp[i][j];  
    }  
    int res;  
    if(i == n){  
        res = 0;  
    }else if(j < w[i]){  
        res = rec(i + 1,j);  
    }else{  
        res = max(rec(i + 1,j),rec(i + 1,j - w[i])+v[i]);  
    }  
      
    return dp[i][j] = res;  
}  
  
int main()  
{  
    scanf("%d %d",&n,&W);  
      
    for(int i=0;i<n;i++){  
        scanf("%d %d",&w[i],&v[i]);   
    }  
      
    memset(dp,-1,sizeof(dp));  
      
    cout<<rec(0,W)<<endl;  
      
      
    return 0;  
}  
```

- 01背包（二维DP）
```c++
#include<bits/stdc++.h>  
using namespace std;  
typedef long long ll;  
  
int n,W;  
int dp[105][10005];  
int w[105],v[105];  
  
int main()  
{  
    scanf("%d %d",&n,&W);  
      
    for(int i=0;i<n;i++){  
        scanf("%d %d",&w[i],&v[i]);   
    }  
      
    memset(dp,0,sizeof(dp));  
      
    for(int i=n-1;i>=0;i--){  
        for(int j=0;j<=W;j++){  
            if(j < w[i]){  
                dp[i][j] = dp[i + 1][j];  
            }else{  
                dp[i][j] = max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);  
            }  
        }  
    }  
      
    cout<<dp[0][W]<<endl;  
      
    return 0;  
}  
```

- 01背包（一维最简化）

```c++
int dp[MAX_W +1];

void solve(){
    for(int i=0;i<n;i++){
        for(int j=W;j>=w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    printf("%d\n",dp[W]);
}
```

- 完全背包（一维最简化）

```c++
int dp[MAX_W +1];

void solve(){
    for(int i=0;i<n;i++){
        for(int j=w[i];j<=W;j--){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    printf("%d\n",dp[W]);
}
```



### 11、并查集

```c++
int par[MAX_N];
int rank[MAX_N];

//初始化n个元素 
void init(int n){
	for(int i=0;i<n;i++){
		par[i] = i;
		rank[i] = 0;
	}
}

//查询树的根 
int find(int x){
	if(par[x] == x){
		return x;
	}else{
		return par[x] = find(par[x]);
	}
}

//合并x和y所属的集合 
void unite(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(rank[x] < rank[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(rank[x] == rank[y]) rank[x]++;
	}
}

//判断x和y是否属于同一个集合
bool same(int x,int y){
	return find(x) == find(y);
}
```

经典例题：hdu1232

```c++
#include<cstdio>
using namespace std;

int par[1005];
int rank[1005];

//初始化n个元素
void init(int n){
	for(int i=1;i<=n;i++){
		par[i] = i;
		rank[i] = 0;
	}
}

//查询树的根
int find(int x){
	if(par[x] == x){
		return x;
	}else{
		return par[x] = find(par[x]);
	}
}

//合并x和y所属的集合
void unite(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(rank[x] < rank[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(rank[x] == rank[y]) rank[x]++;
	}
}

//判断x和y是否属于同一个集合
bool same(int x,int y){
	return find(x) == find(y);
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(n == 0) break;
        init(n);
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            unite(x,y);
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(par[i] == i) ans ++;
        }
        printf("%d\n",ans-1);
    }

    return 0;
}

```



### 12、树状数组

```c++
int lowbit(int x){  
    return x&(-x);  
}  

void add(int x,int y){  
    while(x<=n){  
        c[x]+=y;  
        x+=lowbit(x);  
    }  
}  

//用于求序列中小于等于数字x的元素的个数
int sum(int x){  
    int ans=0;  
    while(x>0){  
        ans+=c[x];  
        x-=lowbit(x);  
    }       
    return ans;  
} 
```

http://blog.csdn.net/laichilizi/article/details/79450529

- 求逆序数↑

```c++
#include<iostream>  
#include<cstdio>  
using namespace std;  
int n;  
int aa[100005];  
int c[100005];  
int a[100005];  
int lowbit(int x)  
{  
    return x&(-x);  
}  
void add(int x,int y)  
{  
    while(x<=n)  
    {  
        c[x]+=y;  
        x+=lowbit(x);  
    }  
}  
int sum(int x)  
{  
    int ans=0;  
    while(x>0)  
    {  
        ans+=c[x];  
        x-=lowbit(x);  
    }  
       
    return ans;  
}  
   
int main()  
{  
    scanf("%d",&n);  
    for(int i=0;i<n;i++)  
    {  
        scanf("%d",&a[i]);  
    //  aa[a[i]]=a[i];  
    }   long long aans=0;  
    for(int i = 0 ; i<n;i++)  
    {  
        add(a[i],1);  
        aans+=i-sum(a[i]-1);  
    //  cout << i;  
    //  cout << sum(a[i]-1)<<endl;;  
    }  
   
    printf("%lld\n",aans);  
    return 0;  
} 
```



### 13、快速幂 and 矩阵快速幂

- 快速幂

```c++
typedef long long ll;
ll ksm(ll x,ll n,ll mod){
	ll res = 1;
	x = x % mod;
	while(x > 0){
		if(n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}
```

- 矩阵快速幂

http://blog.csdn.net/wust_zzwh/article/details/52058209

```c++
#include<bits/stdc++.h>  
using namespace std;  
typedef long long ll;  
const int MOD=10000;  
struct mat  
{  
    ll a[2][2];  
};  
mat mat_mul(mat x,mat y)  
{  
    mat res;  
    memset(res.a,0,sizeof(res.a));  
    for(int i=0;i<2;i++)  
        for(int j=0;j<2;j++)  
        for(int k=0;k<2;k++)  
        res.a[i][j]=(res.a[i][j]+x.a[i][k]*y.a[k][j])%MOD;  
    return res;  
}  
void mat_pow(int n)  
{  
    mat c,res;  
    c.a[0][0]=c.a[0][1]=c.a[1][0]=1;  
    c.a[1][1]=0;  
    memset(res.a,0,sizeof(res.a));  
    for(int i=0;i<2;i++) res.a[i][i]=1;  
    while(n)  
    {  
        if(n&1) res=mat_mul(res,c);  
        c=mat_mul(c,c);  
        n=n>>1;  
    }  
    printf("%I64d\n",res.a[0][1]);  
}  
int main()  
{  
    int n;  
    while(~scanf("%d",&n)&&n!=-1)  
    {  
        mat_pow(n);  
    }  
    return 0;  
}
```

### 14、最短路

http://blog.csdn.net/acm_1361677193/article/details/48211319



### 15、string

http://blog.csdn.net/tengfei461807914/article/details/52203202



### 16、二分搜索

二分模型

```c++
while(l < r-1){
        int mid = r + (l - r)>> 1;
        if() l = mid;
        else r = mid;
    }
```



http://blog.csdn.net/laichilizi/article/details/79388555

- 分巧克力↑，经典二分题



### 17、字符串函数

- 字符处理函数：ctype.h

```
int isdigit(int ch)  ;//是否为数字，即ch是否是0-9中的字符
int isxdigit(int ch) ;//是否为十六进制数字，即ch是否是0-9  a-z A-Z 中的字符
int isalpha(int ch)  ;//是否为字母
int isalnum(int ch)  ;//是否为字母或数字
int islower(int ch)  ;//是否为小写字母
int isupper(int ch)  ;//是否为大写字母
int tolower(int ch)  ;//转换为小写字母
int toupper(int ch)  ;//转换为大写字母
```

- 字符串转换函数：stdlib.h

**字符转换为数字：**

```
double atof(char  *str) ; //将字符串str转换为double型数字
int    atoi (char  *str) ; //将字符串str转换为int 型数字
long   atol(char  *str) ; //将字符串str转换为long int 型数字
```

**数字转换为字符：**

```
//将int型数字digit按radix进制转换成字符串destStr
char * itoa (int digit, char *destStr, int radix) ;
//同理将long型数字转换成字符串
char * ltoa (long digit, char *destStr, int radix) ;
//同理将unsignedlong型数字转换成字符串
char * ultoa (long digit, char *destStr,int radix) ;
```

【以上库函数能够用于进制的转换】

类似函数还有：

```
double strtod(char *, char **) ;
long strtol(char *, char **, int) ;
unsigned long strtoul(char *, char **, int) ;
```

- 字符串操作函数：string.h

```
char * strcpy (char *s1, char *s2) ; //将字符串s2拷贝到数组s1中。
char * strncpy(char *s1,char *s2) ; //将字符串s2的最多n个字符拷贝到数组s1中
char * strcat (char *s1, char * s2) ; //将字符串s2连接在字符串s1尾部
char * strncat(char *s1, char *s2, size_tn) ; //将字符串s2中最多n个字符连接在s1之后
```

【注意：以上操作都要求目标字符数组有足够的存储空间】

 

- 符串比較函数：string.h

```
//比較字符串s1，s2.假设s1等于小于或大于s2。分别返回0。负值,正值
int strcmp(char *s1, char *s2 ) ;
int stricmp(char *s1, char *s2) ;//不区分大写和小写地比較两字符串
int strncmp(char *s1, char *s2, size_t n)  ;//比較两字符串的至多n个字符
```

- 字符串查找函数：string.h

```
//在字符串str中查找字符ch第一次出现的位置，假设找到了，就返回str中ch的指针，否则返回NULL
char *strchr(char*str, int ch) ;
//查找字符串str中字符ch的最后一次出现的位置(即：从后往前查找)
char*strrchr(char *str, int ch) ;
//查找字符串str1中第一次出现字符串str2的位置
char *strstr(char*str1, char *str2) ;
//查找字符串str2中随意字符在字符串str1中首次出现的位置。
char*strpbrk(char *str1, char *str2)
```

其他函数：

```
char *strrev(char * ) ; //字符串逆序函数
size_t strlen(char * str) ;//測字符串str的长度
```

注意：

strncpy( ) , strncat( ) , strncmp( ) ,这些函数仅仅能对两个不同的字符串操作，不能对同一字符串的不同部分操作。假设须要这么做，能够使用内存函数。

若把目标字符串初始置空，strncat()能够完毕非常多功能的操作。能够替代strncpy( )的功能，还能够提取子串等。

 

### 18、set & multiset



### 19、map & multimap



### 20、queue & priority_queue

- queue

queue入队，如例：q.push(x); 将x 接到队列的末端。

queue出队，如例：q.pop(); 弹出队列的第一个元素，注意，并不会返回被弹出元素的值。

访问queue队首元素，如例：q.front()，即最早被压入队列的元素。

访问queue队尾元素，如例：q.back()，即最后被压入队列的元素。

判断queue队列空，如例：q.empty()，当队列空时，返回true。

访问队列中的元素个数，如例：q.size()



- priority_queue

empty()  如果优先队列为空，则返回真 

pop()  删除第一个元素 

push()  加入一个元素 

size()  返回优先队列中拥有的元素的个数 

top()  返回优先队列中有最高优先级的元素 



### 21、stack

empty() 堆栈为空则返回真

pop() 移除栈顶元素

push() 在栈顶增加元素

size() 返回栈中元素数目

top() 返回栈顶元素



### 22、vector

http://blog.csdn.net/duan19920101/article/details/50617190/



### 23、贪心算法

http://blog.csdn.net/qq_32400847/article/details/51336300



### 24、数制转换

http://blog.csdn.net/laichilizi/article/details/79381732
 


### 25、LCS

只计算LCS的数目
```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char a[1005],b[1005],ans[1005];
int dp[1005][1005];
int main()
{
	//freopen("input.txt","r",stdin);

	scanf("%s %s",a+1,b+1);
	int n = strlen(a+1);
	int m = strlen(b+1);
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i] == b[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	cout<<dp[n][m]<<endl;

	return 0;
}
```

除了LCS的数目，还输出对应的子串
```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char a[1005],b[1005],ans[1005];
int dp[1005][1005];
int main()
{
	//freopen("input.txt","r",stdin);

	scanf("%s %s",a+1,b+1);
	int n = strlen(a+1);
	int m = strlen(b+1);
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i] == b[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int cur = 0;
	for(int i=n,j=m;dp[i][j];--i,--j){
		while(dp[i][j] == dp[i-1][j]) --i;
		while(dp[i][j] == dp[i][j-1]) --j;
		ans[cur++] = a[i];
	}

	reverse(ans,ans+cur);
	//ans[cur] = '\0';
	printf("%s\n",ans);

	return 0;
}
```

### 26、LIS
```c++
#include<bits/stdc++.h>  
using namespace std;  
#define INF 0x3f3f3f3f  
typedef long long ll;  
  
int dp[105];  
int a[105];  
  
int main()  
{  
    int n;  
    scanf("%d",&n);  
    for(int i=0;i<n;i++) scanf("%d",&a[i]);  
      
    int res = 0;  
    for(int i=0;i<n;i++){  
        dp[i] = 1;  
        for(int j=0;j<i;j++){  
            if(a[j] < a[i]){ //如果是包括相等，就改为<=   
                dp[i] = max(dp[i],dp[j]+1);  
            }  
        }  
        res = max(res,dp[i]);   
    }  
    cout<<res<<endl;  
  
    return 0;  
}
```

### 27、最大字段和
```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[50005];

ll solve(int n,ll *dp){
	ll ans = 0,b = 0;
	for(int i=0;i<n;i++){
		if(b>=0) b+=dp[i];
		else b = dp[i];
		if(b>ans) ans = b;
	}
	return ans;
}

int main(){
	//freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	memset(dp,0,sizeof(dp));

	for(int i=0;i<n;i++) scanf("%lld",&dp[i]);
	ll p = solve(n,dp);
	cout<<p<<endl;

	return 0;
}
```

### 28、循环数组最大字段和
```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[50005];

ll solve(int n,ll *dp){
	ll ans = 0,b = 0;
	for(int i=0;i<n;i++){
		if(b>=0) b+=dp[i];
		else b = dp[i];
		if(b>ans) ans = b;
	}
	return ans;
}

int main(){
	freopen("input.txt","r",stdin);
	int n,sum = 0;
	scanf("%d",&n);
	memset(dp,0,sizeof(dp));

	for(int i=0;i<n;i++){
		scanf("%lld",&dp[i]);
		sum += dp[i];
	}
	ll ans1 = solve(n,dp);

	for(int i=0;i<n;i++) dp[i] = -dp[i];
	ll ans2 = solve(n,dp);
	ll ans = max(ans1,sum+ans2);

	cout<<ans<<endl;

	return 0;
}
```

### 29、最小正字段和
```c++
#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
typedef long long LL;  
#define INF 0x3f3f3f3f;

struct node{  
    LL a;  
    int id_mi;  
    int id_ma;  
};  
bool operator <(node a,node b){  
    return a.a<b.a;  
}  
node dp[50010];  
int main(){  
    int n,a,i,j;  
    scanf("%d",&n);  
    LL ans=0;  
    dp[0].a=0;  
    dp[0].id_mi=0;  
    dp[0].id_ma=0;  
    for(i=1;i<=n;i++){  
        scanf("%lld",&dp[i].a);  
        dp[i].a+=dp[i-1].a;  
        dp[i].id_mi=i;  
        dp[i].id_ma=i;  
          
    }  
    sort(dp,dp+1+n);  
    j=0;  
    for(i=1;i<=n;i++)  
    {  
        if(dp[i].a==dp[j].a){  
            dp[j].id_mi=max(dp[j].id_mi,dp[i].id_mi);  
            dp[j].id_ma=min(dp[j].id_ma,dp[i].id_ma);  
        }  
        else dp[++j]=dp[i];  
    }  
    for(i=0;i<j;i++){  
        if(dp[i].id_mi<dp[i+1].id_ma&&dp[i+1].a-dp[i].a>0&&(ans==0||ans>dp[i+1].a-dp[i].a)){  
            ans=dp[i+1].a-dp[i].a;  
        }  
    }  
    cout<<ans<<endl;  
    return 0;  
}  
```

### 30、大数运算
http://blog.csdn.net/tt2767/article/details/45420067


