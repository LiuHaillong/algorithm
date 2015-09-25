#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int f[1001]={0},n,m;

void init(){
	int i;
	for(i=1;i<=n;i++)
		f[i]=i;
}

int getf(int v){
	if(f[v]==v)
		return v;
	else{
		f[v]=getf(f[v]);
		return f[v];
	}
}

void merge(int x,int y){
	int t1,t2;
	t1 = getf(x);
	t2 = getf(y);
	if(t1!=t2){
		f[t2]=t1;
	}
}

int main(){
	int i,x,y;
	scanf("%d %d",&n,&m);
	
	init();
	
	for(i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		merge(x,y);
	}
	
	int sum=0;
	for(i=1;i<=n;i++)
		if(f[i]==i)
			sum++;
	
	
	printf("%d\n",sum);
	getchar();getchar();
	return 0; 
}
