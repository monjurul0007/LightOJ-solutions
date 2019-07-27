    #include <bits/stdc++.h>
     
    using namespace std;
     
    typedef long long int ll;
     
    ll solve(int n, int k){
        if(n<k){
            return 0;
        }
        if(k==0){
           
            return 1;
        }
        if(k==1){
           
            return n*n;
        }
        return (n*n*solve(n-1, k-1))/k;    
    }
     
    int main(){
        //freopen("input.txt","r",stdin);
        int T,n,k;
        scanf("%d",&T);
        for(int t=1; t<=T; t++){
            scanf("%d%d",&n,&k);
            printf("Case %d: %lld\n",t,solve(n,k));
        }
        return 0;
    }
