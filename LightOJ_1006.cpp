#include<bits/stdc++.h>
     
using namespace std;
     
int main(){
        long long int a,b,c,d,e,f,n, caseno = 0, cases;
        scanf("%d", &cases);
        while( cases-- ) {
            long long int arr[10000];
            scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
            arr[0] = a;
            arr[1] = b;
            arr[2] = c;
            arr[3] = d;
            arr[4] = e;
            arr[5] = f;
            for(int i=6; i<=n; i++)
                arr[i] = (arr[i-1] + arr[i-2] + arr[i-3] + arr[i-4] + arr[i-5] + arr[i-6])%10000007;
            printf("Case %lld: %lld\n", ++caseno, arr[n] % 10000007);
        }
        return 0;
 }
