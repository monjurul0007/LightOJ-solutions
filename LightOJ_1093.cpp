#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl

#define f0(i,n) for(i=0; i<n; i++)
#define f1(data,i,n) for(data i=1; i<=n; i++) 
#define all(x) x.begin(),x.end()

         
typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;

 
ll arr[100005],mxtree[100005*3],mitree[100005*3];

void build_mxtree(int node, int b, int e){
	if(b==e){
		mxtree[node] = arr[b];
		return;
	}
	
	int left = node*2;
	int right = node*2 +1;
	int mid = (b+e)/2;
	
	build_mxtree(left, b, mid);
	build_mxtree(right, mid+1, e);
	
	if(mxtree[left] > mxtree[right])
		mxtree[node] = mxtree[left];
	else
		mxtree[node] = mxtree[right];
		
}

void build_mitree(int node, int b, int e){
	if(b==e){
		mitree[node] = arr[b];
		return;
	}
	
	int left = node*2;
	int right = node*2 +1;
	int mid = (b+e)/2;
	
	build_mitree(left, b, mid);
	build_mitree(right, mid+1, e);
	
	if(mitree[left] < mitree[right])
		mitree[node] = mitree[left];
	else
		mitree[node] = mitree[right];
		
}

ll mx_query(int node, int i, int j, int b, int e){
	if(j<b || e<i)
		return 0;
		
	if(i<=b && e<=j)
		return mxtree[node];
	
	int left = node*2;
	int right = node*2 +1;
	int mid = (b+e)/2;
	
	ll q1 = mx_query(left, i, j, b, mid);
	ll q2 = mx_query(right, i, j, mid+1, e);
	
	return max(q1,q2);
}

ll mi_query(int node, int i, int j, int b, int e){
	if(j<b || e<i)
		return inf;
		
	if(i<=b && e<=j)
		return mitree[node];
	
	int left = node*2;
	int right = node*2 +1;
	int mid = (b+e)/2;
	
	ll q1 = mi_query(left, i, j, b, mid);
	ll q2 = mi_query(right, i, j, mid+1, e);
	
	return min(q1,q2);
}

int main(){
    int t,n,d;
   
    
	scanf("%d",&t);
	
	for(int T=1; T<=t; T++){
		scanf("%d %d",&n,&d);
		
		for(int i=1; i<=n; i++){
			scanf("%lld",&arr[i]);
		}
		
		build_mitree(1,1,n);
		build_mxtree(1,1,n);
		
		ll mi = mi_query(1,1,3,1,n);
		ll mx = mx_query(1,1,3,1,n);
		ll ans = mx - mi;
		
		for(int i=2; i<n-d+1; i++){
			mi = mi_query(1,i,i+d-1,1,n);
			mx = mx_query(1,i,i+d-1,1,n);
			
			ans = max(mx-mi, ans);
		}
		
		printf("Case %d: %lld\n",T,ans);
	}
	
    return 0;
}
