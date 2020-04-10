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
#define first F
#define second S

typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;

const int dirx[4] = {0,1,0,-1};
const int diry[4] = {1,0,-1,0};


int x,y,cnt;
string mat[25];
int vis[25][25];

void dfs(int sx, int sy){
	if(vis[sx][sy] || sx<0 || sy<0 || sx >=x || sy >= y)
		return;
	if(mat[sx][sy] == '#')
		return;
	
	cnt++;
	vis[sx][sy] = 1;
	
	for(int i=0; i<4; i++)
		dfs(sx+dirx[i], sy+diry[i]);
}

int main(){
	fasterInOut;
	
	int t,T=1;
	cin >> t;
	while(t--){
		cin >> y >> x;
		for(int i=0; i<x; i++){
			cin >> mat[i];
		}
		
		int sx, sy;
		mem(vis, 0);
		cnt = 0;
		for(int i=0; i<x; i++)
			for(int j=0; j<y; j++)
				if(mat[i][j] == '@'){
					sx = i;
					sy = j;
					dfs(sx,sy);
					cout << "Case " << T++ << ": " << cnt << "\n";
				}
	}
	
    return 0;
}
