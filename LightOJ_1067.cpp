#include<bits/stdc++.h>
     
using namespace std;
     
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
         
typedef long long int ll;    
typedef pair<int , int>  pii;
typedef priority_queue<pii, vector<pii> , greater<pii> > pq;
 
ll fact[1000005];
 
#define mod 1000003

ll bigmod(ll n, ll p){
  if(p == 0)
    return 1;
	
  if(p%2 == 0){
    ll res = bigmod(n,p/2);
    return ((res%mod)*(res%mod))%mod;
  }
  else
    return ((n%mod)*bigmod(n,p-1)%mod)%mod;
}
 
ll nck(ll n, ll k){
  ll d = (fact[n-k] * fact[k])%mod;
  return ((fact[n]%mod) * bigmod(d,mod-2))%mod;
}
 
int main(){
	
  ll t,n,k;
   
  fact[0] = 1;
   
  for(int i=1; i<=1000000; i++)
    fact[i] = (i*fact[i-1])%mod;
   
  scanf("%lld",&t);
   
  for(ll T=1; T<=t; T++){
    scanf("%lld %lld",&n,&k);
       
    printf("Case %lld: %lld\n",T,nck(n,k));
  }
       
  return 0;
}
