#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define mod 100000007
#define F first
#define S second

typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;


vector <int> adj[105];
int mat[105][105],vis[105];

int dfs(int s, int d, int cnt){
	if(s == d)
		return cnt;
	
	int res;
	vis[s] = 1;
	
	for(auto i: adj[s])
		if(vis[i] == -1)
			res = dfs(i,d,cnt+mat[s][i]);
	
	return res;
}

int main(){
	//fasterInOut;
	
	int n,t,u,v,w;
	
	scanf("%d",&t);
	for(int T=1; T<=t; T++){
		scanf("%d",&n);
		mem(vis,-1);
		
		for(int i=0; i<n; i++){
			scanf("%d %d %d",&u,&v,&w);
			mat[u][v] = 0;
			mat[v][u] = w;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		int temp = adj[1][1];
		adj[1].pop_back();
		
		int ans = mat[temp][1] + dfs(1,temp,0);
		
		swap(adj[1][0] ,temp);
		mem(vis, -1);
		ans = min(ans, mat[temp][1] + dfs(1,temp,0));
		
		printf("Case %d: %d\n",T,ans);
		
		for(int i=0; i<=n; i++)
			adj[i].clear();
	}
	
    return 0;
}
