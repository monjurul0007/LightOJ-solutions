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
char mat[25][25];
int n, m,vis[25][25];

void bfs(int x, int y){
	int ux,uy,vx,vy;
	memset(vis, -1, sizeof vis);
	queue <pii> q;
	
	vis[x][y] = 0;
	q.push(pii(x,y));
	
	while(!q.empty()){
		pii u = q.front();
		q.pop();
		
		ux = u.first;
		uy = u.second;
		
		for(int i=0; i<4; i++){
			vx = ux + _x[i];
			vy = uy + _y[i];
			
			if((vx >=0 && vx<n) && (vy >=0 && vy<m)){
				if(mat[vx][vy] != '#' && mat[vx][vy] != 'm' && vis[vx][vy] == -1){
					vis[vx][vy] = vis[ux][uy] + 1;
					q.push(pii(vx,vy));
				}
			}
		} 
		
	}
	
}

int main(){
	int t;
	
	scanf("%d",&t);
	
	for(int T=1; T<=t; T++){
		scanf("%d %d",&n,&m);
		
		for(int i=0; i<n; i++)
			scanf("%s",&mat[i]);
		
		int sx,sy;
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(mat[i][j] == 'h'){
					sx = i;
					sy = j;
					break;
				}
			}
		}
		
		bfs(sx,sy);
		
		int time = 0;
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(mat[i][j] == 'a' || mat[i][j] == 'b' || mat[i][j] == 'c'){
					time = max(vis[i][j] , time);
				}
			}
		}
		
		printf("Case %d: %d\n",T,time);
	}
	
	return 0;
}
