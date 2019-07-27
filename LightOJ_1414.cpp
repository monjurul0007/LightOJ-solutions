#include <bits/stdc++.h>
 
using namespace std;
 
#define inf 1<<30
#define mx 100005
 
typedef pair<int , int> ii;
typedef pair<int, ii> iii;
   
int main(){
    //freopen("input.txt","r",stdin);
    int T,d1,d2,y1,y2;
    char junk;
    string s1,s2,m[13] = {"0","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" ,"December"};
    scanf("%d",&T);
    for(int t=1; t<=T; t++){
        cin >> s1 >> d1 >> junk >> y1;
        cin >> s2 >> d2 >> junk >> y2;
        int cnt;
        for(int i=1; i<13; i++){
            if(s1 == m[i]){
                cnt = i;
                break;
            }
        }
        if(cnt > 2)
            y1++;
           
        if(s2 == "January" || (s2 == "February" && d2 < 29))
            y2--;
       
       
         
        int cnt1 = ((y1/4) + (y1/400)) - (y1/100);
        int cnt2 = ((y2/4) + (y2/400)) - (y2/100);
       
        cnt = cnt2 -cnt1;
       
        if (((y1%4 == 0) && (y1%100!= 0)) || (y1%400 == 0))
            cnt++;
       
        printf("Case %d: %d\n",t,cnt);
    }
    return 0;
}
