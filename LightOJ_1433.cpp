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
	double ox,oy,ax,ay,bx,by,ab,r,theta;
	cin >> T;
	for(int t=1; t<=T; t++){
		cin >> ox >> oy >> ax >> ay >> bx >> by;
		
		r = sqrt((ox-ax)*(ox-ax) + (oy-ay)*(oy-ay));
		ab = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
		
		double n = ((2*r*r)-(ab*ab))/(2*r*r);
		
		theta = acos(n);
		
		cout << "Case " << t << ": " << setprecision(13) << fixed << r*theta << endl;
	}
	return 0;
}
