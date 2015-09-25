#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int a[101];

void helanguoqi(int begin,int end){
	int current = begin;
	while(current<=end){
		//当前为0和begin交换 current++ begin++ 
		if(a[current]==0){
			swap(a[current],a[begin]);
			current++;
			begin++; 
		}
		//当前为1，begin不动 current++ 
		else if(a[current]==1){
			current++;
		}else{
			swap(a[current],a[end]);
			end--;
		}
	}
}

int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	helanguoqi(0,n-1);
	
	for(i=0;i<n;i++)
		printf("%d",a[i]);
	printf("\n");
}
