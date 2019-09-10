#include <bits/stdc++.h>
     
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define fin(i) freopen(i, "r", stdin)
#define fout(o) freopen(o, "w", stdout)
#define pb push_back
#define ll long long int
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
     
#define gcd(a,b) __gcd(a,b)
#define lcm(a, b) (a*b)/gcd(a, b)
#define pi acos(-1.0)

using namespace std;

int main() {
    int t;
    cin >> t;
    long double x,y,c;
	  for(int T=1; T<=t; T++){
		cin >> x >> y >> c;
		long double h1,h2,m,hi=max(x,y),lo=0,d;
		
    while(hi-lo > 0.00000000001){   //binary search
			m = (hi+lo)/2;
			h1 = sqrt(x*x - m*m);
			h2 = sqrt(y*y - m*m);
			d = (h1*h2)/(h1+h2);
			if(d > c)
				lo = m;
			else
				hi = m;
		}
    
		cout << "Case " << T << ": " <<  setprecision(10) << fixed << m << endl;
	}
    return 0;
}
