#include <bits/stdc++.h>
 
using namespace std;
 
#define inf 1<<30
#define mx 100005
#define pi acos(-1)
 
typedef pair<int , int> ii;
typedef pair<int, ii> iii;
 
class my_queue{
    private:
        int arr[10], lcur, rcur, num,n;
   
    public:
    my_queue(int N){
        lcur = 0;
        rcur = 0;
        num = 0;
        n = N;
    }
   
    void pushL(int x){
        if(num>=n){
            printf("The queue is full\n");
            return;
        }
        else if(num == 0){
            num++;
            arr[lcur] = x;
        }
        else{
            num++;
            lcur--;
            if(lcur<0)
                lcur = 9;
            arr[lcur] = x;
        }
        printf("Pushed in left: %d\n",x);
    }
   
    void pushR(int x){
        if(num>=n){
            printf("The queue is full\n");
            return;
        }
        else if(num == 0){
            num++;
            arr[rcur] = x;
        }
        else{
            num++;
            rcur++;
            if(rcur>9)
                rcur = 0;
            arr[rcur] = x;
        }
        printf("Pushed in right: %d\n",x);
    }
   
    void popL(){
        if(num<=0){
            printf("The queue is empty\n");
        }
        else{
            num--;
            printf("Popped from left: %d\n",arr[lcur]);
            lcur++;
            if(lcur>9)
                lcur = 0;
        }
        if(num == 0)
            lcur = rcur = 0;
    }
   
    void popR(){
        if(num<=0){
            printf("The queue is empty\n");
        }
        else{
            num--;
            printf("Popped from right: %d\n",arr[rcur]);
            rcur--;
            if(rcur<0)
                rcur = 9;
        }
        if(num == 0)
            lcur = rcur = 0;
    }
};
   
int main(){
    //freopen("input.txt","r",stdin);
    int T,n,m,x;
    string s;
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> n >> m;
        my_queue q(n);
        printf("Case %d:\n",t);
        for(int i=0; i<m; i++){
            cin >> s;
            if(s == "pushLeft"){
                cin >> x;
                q.pushL(x);
            }
            else if(s == "pushRight"){
                cin >> x;
                q.pushR(x);
            }
            else if(s == "popLeft")
                q.popL();
            else
                q.popR();
        }
    }
    return 0;
}
