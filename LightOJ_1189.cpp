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
 
   
int main(){
    //freopen("input.txt","r",stdin);
    int T;
    ull fac[20],n;
    vector <int> v;
    
    fac[0] = 1;
    for(int i=1; i<20; i++)
        fac[i] = fac[i-1]*i;
    
    sc(T);
    for(int t=1; t<=T; t++){
        scanf("%llu",&n);
       
        for(int i=19; i>=0; i--){
            if(n==0)
                break;
            if(fac[i] <= n && n>0){
                v.push_back(i);
                n -= fac[i];
            }
           
        }
       
        if(n != 0)
            printf("Case %d: impossible\n",t);
        else{
            int l = v.size()-1;
            printf("Case %d: %d!",t,v[l]);
            for(int i=l-1; i>=0; i--)
                printf("+%d!",v[i]);
            printf("\n");
        }
        
        v.clear();
    }
    return 0;
}
