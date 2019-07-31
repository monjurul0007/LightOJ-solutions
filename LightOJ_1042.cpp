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
    ll n;
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> n;
       
        vector <bool> v;
       
        while(n){
            v.push_back(n%2);
            n /= 2;
        }
       
        v.push_back(0);
       
        int l = v.size();
        int z=0,o=0;
       
        for(int i=0; i<l; i++){
            if(v[i])
                o++;
            else
                z++;
            if(v[i] && !v[i+1]){
                v[i+1] = 1;
                z++;
                o--;
                while(z--)
                    v[i--] = 0;
                while(o--)
                    v[i--] = 1;
                break;
            }
        }
       
        for(int i=0; i<l; i++)
            n += v[i]*pow(2,i);
       
        cout << "Case " << t << ": " << n << endl;
    }
    return 0;
}
