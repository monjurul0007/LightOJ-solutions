#include <stdio.h>
#include <iostream>
#include <stack>
#include <stdlib.h>
 
#define PI acos(-1)
 
using namespace std;
 
int decTobin(int dec){
        int num = 0;
        std::stack<int>bin;
        while(dec>0){
                bin.push(dec%2);
                dec /= 2;
        }
        while(!bin.empty()){
                num = num*10 + bin.top();
                bin.pop();
        }
        return num;
}
 
int main(){
        int t;
        scanf("%d\n",&t);
        for(int i=1; i<=t; i++){
                int dec[4],bin[4];
                scanf("%d.%d.%d.%d",&dec[0],&dec[1],&dec[2],&dec[3]);
                scanf("%d.%d.%d.%d",&bin[0],&bin[1],&bin[2],&bin[3]);
                for(int j=0; j<4; j++){
                        dec[j] = decTobin(dec[j]);
                }
                if(dec[0]==bin[0] && dec[1]==bin[1] && dec[2]==bin[2] && dec[3]==bin[3]) printf("Case %d: Yes\n",i);
                else printf("Case %d: No\n",i);
        }
}
