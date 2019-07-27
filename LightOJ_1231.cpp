#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
ll dp[55][1005][25];
int n,coin[105],c[105];
 
ll solve(int i, int a, int cnt){
    if(i>=n){
        if(a==0)
            return 1;
        else
            return 0;
    }
    if(a==0)
        return 1;
    if(dp[i][a][cnt] != -1)
        return dp[i][a][cnt];
    ll sum1=0,sum2=0;
    if(cnt < c[i] && a - coin[i] >= 0){
        cnt++;
        sum1 = solve(i,a-coin[i],cnt);
        dp[i][a-coin[i]][cnt] = sum1;
    }
    sum2 = solve(i+1, a , 0);
    dp[i+1][a][0] = sum2;
    return (sum1 + sum2)%100000007;
}
 
int main(){
    //freopen("input.txt","r",stdin);
    int T,k;
    scanf("%d",&T);
    for(int t=1; t<=T; t++){
        memset(dp,-1,sizeof dp);
        scanf("%d%d",&n,&k);
        for(int i=0; i<n; i++)
            scanf("%d",&coin[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&c[i]);
        printf("Case %d: %lld\n",t,solve(0,k,0));
    }
    return 0;
}
