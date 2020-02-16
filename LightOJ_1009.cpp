#include<bits/stdc++.h>
     
using namespace std;
     
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf INT_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl

#define f0(data,i,n) for(data i=0; i<n; i++)
#define f1(data,i,n) for(data i=1; i<=n; i++) 
#define all(x) x.begin(),x.end()
         
typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue<pii, vector<pii> , greater<pii> > pq; 

int _x[] = {1,0,-1,0};
int _y[] = {0,1,0,-1};

vector <int> adj[20005];
int n,vis[20005];


int bfs(int s){
	int cl1 = 0,cl2 = 0;
	queue <int> q;
	
	vis[s] = 1;
	cl1 = 1;
	q.push(s);
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i];
			
			if(vis[v] == -1){
				if(vis[u] == 1){
					cl2++;
					vis[v] = 2;
				}
				else{
					cl1++;
					vis[v] = 1;
				}
				
				q.push(v);
			}
		}
	}
	
	return max(cl1,cl2);
}

int main(){
	int a,b,t,mx = 0;
	
	scanf("%d",&t);
	
	for(int T=1; T<=t; T++){
		scanf("%d",&n);
		
		set <int> st;
		
		for(int i=0; i<n; i++){
			scanf("%d %d",&a,&b);
			mx = max(a,mx);
			mx = max(b,mx);
			st.insert(a);
			st.insert(b);
			adj[a].pb(b);
			adj[b].pb(a);
		}
		
		int ans = 0;
		memset(vis, -1, sizeof vis);
		
		for(auto i: st){
			if(vis[i] != -1)
				continue;
			ans += bfs(i);
		}
		
		printf("Case %d: %d\n",T,ans);
		
		for(int i=1; i<=mx; i++)
			adj[i].clear();
	}
	
	return 0;
}
