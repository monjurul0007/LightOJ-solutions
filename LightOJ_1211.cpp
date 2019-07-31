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
    int n,x1,y1,z1,x2,y2,z2,_x1,_y1,_z1,_x2,_y2,_z2;
    cin >> T;
    for(int t=1; t<=T; t++){
        bool flag = false;
       
        cin >> n;
        cin >> x1 >> y1 >> z1 >>x2 >> y2 >> z2;
        for(int i=0; i<n-1; i++){
            cin >> _x1 >> _y1 >> _z1 >> _x2 >> _y2 >> _z2;
           
            if(_x2<x1 || x2<_x1)
                flag = true;
            if(_y2<y1 || y2<_y1)
                flag = true;
            if(_z2<z1 || z2<_z1)
                flag = true;
               
            x1 = max(x1,_x1);
            x2 = min(x2,_x2);
           
            y1 = max(y1,_y1);
            y2 = min(y2,_y2);
           
            z1 = max(z1,_z1);
            z2 = min(z2,_z2);
        }
       
        if(flag){
            cout << "Case " << t << ": " << 0 << endl;
            flag = false;
            continue;
        }
       
        int x = abs(x2- x1);
        int y = abs(y2- y1);
        int z = abs(z2- z1);
        cout << "Case " << t << ": " << x*y*z << endl;
    }
    return 0;
}
