#include <bits/stdc++.h>

using namespace std;

#define inf 1<<30
#define mx 100005
#define pi acos(-1)

typedef pair<int , int> ii;
typedef pair<int, ii> iii;

	
int main(){
	//freopen("input.txt","r",stdin);
	int T;
	double R,n,r;
	cin >> T;
	for(int t=1; t<=T; t++){
		cin >> R >> n;
		r = (R*sin(pi/n))/(1.+sin(pi/n));
		printf("Case %d: %.10f\n",t,r);
	}
	return 0;
}
