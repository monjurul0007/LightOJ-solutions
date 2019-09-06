/* binary search , upper_bound and lower_bound binary search */

#include <bits/stdc++.h>
 
using namespace std;
 
ll bs_upper(ll arr[],ll n, ll key){
    int bi = 0,en = n-1;
    int mid;
    while(bi <= en){
        mid = (bi+en)/2;
        if(arr[mid] <= key){
		bi = mid + 1;
	}
	else{
		en = mid - 1;
	}
    }
    return en;
}

ll bs_lower(ll arr[],ll n, ll key){
    int bi = 0,en = n-1;
    int mid;
    while(bi <= en){
        mid = (bi+en)/2;
        if(arr[mid] >= key){
		en = mid - 1;
	}
	else{
		bi = mid + 1;
	}
    }
    return bi;
}
 
int main(){
    ll t,arr[100005],n,q,a,b;
    
    scanf("%lld",&t);
    for(int T=1; T<=t; T++){
        scanf("%lld%lld",&n,&q);
    for(int i=0; i<n; i++){
        scanf("%lld",&arr[i]);
    }
    
    printf("Case %d:\n",T);
    for(int i=0; i<q; i++){
	scanf("%lld%lld",&a,&b);
        printf("%lld\n", bs_upper(arr,n,b) - bs_lower(arr,n,a) + 1 );
        }
    }  
    
    return 0;
}
