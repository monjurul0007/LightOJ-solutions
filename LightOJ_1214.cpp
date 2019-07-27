    #include<bits/stdc++.h>
    
    using namespace std;
     
    int longDivision(char a[], long long int b){
        int i=0,len = strlen(a);
        long long int rem=0;
        if(a[0] == '-')
            i = 1;
        for(i; i<len; i++){
            rem = rem*10 + (a[i]-'0');
            rem %= b;
        }
        if(rem == 0)
            return 0;
        return 1;
    }
    int main(){
        long long int b;
        int t,no=1,res;
        char a[250];
        scanf("%d\n",&t);
        while(t--){
            scanf("%s %lld",a,&b);
            res = longDivision(a,b);
            if(res == 0)
                printf("Case %d: divisible\n",no++);
            else
                printf("Case %d: not divisible\n",no++);
        }
        return 0;
    }
