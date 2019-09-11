#include<bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

ld bs(ld hi, ld lo, ld a, ld b){
	ld w,l,d,ti,c,m;
	
	while(hi-lo > 0.000000000001){
            w = (hi+lo)/2;
            l = (a*w)/b;
            d = sqrt(l*l+w*w)/2;
            ti = acos((2*d*d - w*w)/(2*d*d));
            c = d*ti;
            m = 2*l+2*c;

            if(m > 400){
                hi = w;
            }
            else
                lo = w;
	}
	
	return w;
}

int main(){
    int T;
    char junk;
    long double a,b,w;
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> a >> junk >> b;
        w = bs(130,0,a,b);
        cout << "Case " << t << ": " << setprecision(10) << fixed << (a*w)/b << " " << w << endl;
    }
}
