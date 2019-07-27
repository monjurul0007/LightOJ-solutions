#include <bits/stdc++.h>
 
using namespace std;
 
#define inf 1<<30
#define mx 100005
 
typedef pair<int , int> ii;
typedef pair<int, ii> iii;
 
int arr[mx],tree[mx*3];
 
void init(int node, int b, int e){
    if(b==e){
        tree[node] = arr[b];
    }
    else{
        int left = node * 2;
        int right = node * 2 + 1;
        int mid = (b+e) / 2;
        init(left, b, mid);
        init(right, mid+1, e);
        if(tree[left] < tree[right])
            tree[node] = tree[left];
        else
            tree[node] = tree[right];
    }
}
 
int query(int node, int i, int j, int b, int e){
    if(b < i && e < i)
        return inf;
    if(b > j && e > j)
        return inf;
    if(b>=i && e<=j)
        return tree[node];
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b+e) / 2;
    int q1 = query(left, i, j, b, mid);
    int q2 = query(right, i, j, mid+1, e);
    return min(q1 , q2);
}
 
int main(){
    //freopen("input.txt","r",stdin);
    int t,n,q,a,b;
    scanf("%d",&t);
    for(int T=1; T<=t; T++){
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++)
            scanf("%d",&arr[i]);
        init(1,1,n);
        printf("Case %d:\n",T);
        for(int i=0; i<q; i++){
            scanf("%d%d",&a,&b);
            printf("%d\n",query(1,a,b,1,n));
        }
    }
    return 0;
}

// monjurul0007
// LightOJ id = 43555
