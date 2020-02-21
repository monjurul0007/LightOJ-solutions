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

char s[100005];
int tree[100005*3];

void update(int node, int i, int j, int b, int e){
	if(j < b || e < i)
		return;
	
	if(i<=b && e<=j){
		tree[node]++;
		return;
	}
	
	int left = node*2;
	int right = node*2 + 1;
	int mid = (b+e)/2;
	
	update(left, i, j,  b, mid);
	update(right, i, j, mid+1, e);
	
}

int query(int node, int i, int b, int e, int carry){
	if(i < b || e < i)
		return 0;
	
	if(b==e && e == i)
		return tree[node] + carry;
	
	int left = node*2;
	int right = node*2 + 1;
	int mid = (b+e)/2;
	
	int q1 = query(left, i, b, mid, carry+tree[node]);
	int q2 = query(right, i, mid+1, e, carry+tree[node]);
	
	return q1 + q2;
}

int main(){
    int t,q,a,b;
    char c;
    
  scanf("%d",&t);
	
	for(int T=1; T<=t; T++){
		memset(tree, 0, sizeof(tree));
		scanf("%s",s);
		scanf("%d",&q);
		
		int n =  strlen(s);
		
		for(int i=n-1; i>=0; i--)
			s[i+1] = s[i];

		printf("Case %d:\n",T);
		for(int i=0; i<q; i++){
			scanf(" %c",&c);
			
			if(c == 'I'){
				scanf("%d %d",&a,&b);
				update(1,a,b,1,n);
			}
			else{
				scanf("%d",&a);
				int state = query(1,a,1,n,0);

				if(state % 2){
					state = s[a] -'0';
					printf("%d\n",!state);
				}
				else
					printf("%c\n",s[a]);
			}
			
		}
	}
	
    return 0;
}
