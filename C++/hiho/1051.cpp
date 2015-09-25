#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        vector<int> v;
        int n,m,maxn = 0,a;
        scanf("%d%d",&n,&m);
        v.push_back(0);
        for(int i = 1; i <= n; i++){
            scanf("%d",&a);
            v.push_back(a);
        }
        v.push_back(100);
        if(n <= m){
            printf("100\n");
            continue;
        }
        for(int i = 0; i < n-m; i++){
            maxn = max(maxn,v[i+m+1]-v[i]);
        }
        printf("%d\n",maxn-1);
    }
    return 0;
}

