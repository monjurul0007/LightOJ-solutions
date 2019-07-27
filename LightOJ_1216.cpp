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
    double r1,r2,h,p,area,r;
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> r1 >> r2 >> h >> p;
        r = ((h-p)*(r1-r2))/h;
        r = r1-r;
        area = ((pi*p)/3)*(r*r+r*r2+r2*r2);
        printf("Case %d: %.10f\n",t,area);
    }
    return 0;
}
