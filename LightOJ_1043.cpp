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
	  long double a,b,c,r,s,areaB,areaS,hi,lo;
    cin >> t;
    for(int T=1; T<=t; T++){
		cin >> a >> b >> c >> r;
		s = (a+b+c)/2.0;
		areaB = sqrt(s*(s-a)*(s-b)*(s-c));
		long double x,y,z,ss;
		hi = a;
		lo = 0;
		while(hi-lo > 0.000000000001){  // Binary search 
			x = (hi+lo)/2.0;
			y = (b*x)/a;
			z = (c*x)/a;
			ss = (x+y+z)/2;
			areaS = sqrt(ss*(ss-x)*(ss-y)*(ss-z));
			if(areaS > r*(areaB-areaS)){
				hi = x;
			}
			else{
				lo = x;
			}
		}
		cout << "Case " << T << ": " << setprecision(10) << fixed << x << endl;
	}
    return 0;
}
