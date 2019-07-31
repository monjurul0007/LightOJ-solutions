#include <bits/stdc++.h>
 
using namespace std;
 
#define inf 1<<30
#define mx 100005
#define pi acos(-1)
#define sc(a) scanf("%d",&a)
#define scc(a,b) scanf("%d%d",&a,&b)
#define sccc(a,b,c) scanf("%d%d%d",&a,&b,&c)
 
typedef pair<int , int> ii;
typedef pair<int, ii> iii;
typedef long long int ll;
typedef unsigned long long int ull;
 
double log_b(double n, double b){
    return log(n)/log(b);
}
 
int count(int n,int b){
    if(n <= 1)
        return 1;
    return floor(n*log_b(n/M_E,b) + log_b(2*pi*n,b)/2.0)+1;
}
 
int main(){
    //freopen("input.txt","r",stdin);
    int T;
    int n,b;
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> n >> b;
        cout << "Case " << t << ": " << count(n,b) << endl;
    }
    return 0;
}
