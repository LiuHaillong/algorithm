#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

struct edge{
	int u;
	int v;
	int w;
}; 
struct edge e[50001];
int n,m;
int f[1001]={0},sum=0;

void quicksort(int left,int right){
	int i,j,temp;
	i = left;
	j = right;
	struct edge t;
	
	if(left>right)
		return ;
	
	while(i!=j){
		while(e[j].w>=e[left].w && i<j)
			j--;
		while(e[i].w<=e[left].w && i<j)
			i++;
			
		if(i<j){
			t = e[i];
			e[i] = e[j];
			e[j] = t;
		}
	}
	t = e[left];
	e[left] = e[i];
	e[i] = t;
	
	quicksort(left,i-1);
	quicksort(i+1,right);
	return ;
}

int getf(int v){
	if(f[v]==v)
		return v;
	else
		f[v] = getf(f[v]);
		return f[v];
}

int merge(int u,int v){
	int t1 = getf(u);
	int t2 = getf(v);
	if(t2!=t1){
		f[t2] = t1;
		return 1;
	}
	return 0;
}

int main(){
	int i,count=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
		
	for(i=1;i<=n;i++)
		f[i]=i;
		
	quicksort(1,m);	
	
	for(i=1;i<=m;i++){
		if(merge(e[i].u,e[i].v)){
			count++;
			sum+=e[i].w;
		}
		if(count==n-1)
			break;
	}
	
	printf("%d\n",sum);
	getchar();getchar();
	return 0;
}
