#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int a[101];

void helanguoqi(int begin,int end){
	int current = begin;
	while(current<=end){
		//��ǰΪ0��begin���� current++ begin++ 
		if(a[current]==0){
			swap(a[current],a[begin]);
			current++;
			begin++; 
		}
		//��ǰΪ1��begin���� current++ 
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
