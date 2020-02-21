#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl

#define f0(i,n) for(i=0; i<n; i++)
#define f1(data,i,n) for(data i=1; i<=n; i++) 
#define all(x) x.begin(),x.end()

         
typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;

ll tree[200005*3],N = 150000;
vector < pair<ll,ll> > up;
vector <ll> qu;
set <ll> st;
map <ll, ll> mp;
		

void update(int node, int i, int j, int b, int e){
	if(j<b || e < i)
		return;
	
	if(i<=b && e<=j){
		tree[node]++;
		return; 
	}

	int mid = (b+e)/2;
	
	update(node*2, i, j, b, mid);
	update(node*2 +1, i, j, mid+1, e);
	
}

ll query(int node, int i, int b, int e){
	if(i<b || e < i)
		return 0; 
	
	if(b==e && i==b){
		return tree[node]; 
	}
  
	int mid = (b+e)/2;
	
	ll q1 = query(node*2;, i, b, mid);
	ll q2 = query(node*2 +1, i, mid+1, e);
	
	return q1 + q2 + tree[node];
}

void clear(){
	up.clear();
	qu.clear();
	st.clear();
	mp.clear();
	memset(tree, 0, sizeof(tree));
}

void input(ll n, ll q){
	ll a,b;
	
	for(int i=0; i<n; i++){
		scanf("%lld %lld",&a,&b);
		up.pb({a,b});
		st.insert(a);
		st.insert(b);
	}
		
	for(int i=0; i<q; i++){
		scanf("%lld",&a);
		qu.pb(a);
		st.insert(a);
	}
		
	ll cnt = 0;
	for(auto i : st){
		mp[i] = cnt++;
	}
	
}

int main(){
    int t;
    ll n,q,a,b;
    
	scanf("%d",&t);
	
	for(int T=1; T<=t; T++){
		clear();
	
		scanf("%lld %lld",&n,&q);
		
		input(n,q);
		
		for(int i=0; i<n; i++){
			a = up[i].first;
			b = up[i].second;
			update(1,mp[a],mp[b],0,N);
		}
		
		printf("Case %d:\n",T);
		
		for(int i=0; i<q; i++){
			a = qu[i];
			
			printf("%lld\n",query(1,mp[a],0,N));
		}
		
	}
	
    return 0;
}
