
#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf INT_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define mod 100000007
#define F first  
#define S second   

typedef long long int ll;     
typedef pair<ll , int>  pii;
typedef pair<int , pii > piii; 

vector <pii> adj[30005];
ll dis[30005],n;

void bfs(int s){
	mem(dis, -1);
	queue <pii> q;
	q.push({0,s});
	dis[s] = 0;
	while(!q.empty()){
		int u = q.front().second;
		q.pop();
		for(auto i : adj[u]){
			int v = i.second;
			int w = i.first;
			if(dis[v] == -1){
				dis[v] = dis[u] + w;
				q.push({dis[v],v});
			}
		}
	}
}

int main(){
	int t;
	int u,v,w;
	scanf("%d",&t);
	for(int T=1; T<=t; T++){
		scanf("%lld",&n);
		
		for(int i=0; i<n-1; i++){
			scanf("%d %d %d",&u,&v,&w);
			adj[u].pb({w,v});
			adj[v].pb({w,u});
		}
		
		ll node = 0,mx = 0;
		bfs(0);
		for(int i=0; i<n; i++){
			if(mx < dis[i]){
				mx = dis[i];
				node = i;
			}
		}
		
		bfs(node);
		for(int i=0; i<n; i++){
			if(mx < dis[i]){
				mx = dis[i];
			}
		}
		
		printf("Case %d: %lld\n",T,mx);
		
		for(int i=0; i<n; i++){
			adj[i].clear();
		}
	}
	
    return 0;
}
