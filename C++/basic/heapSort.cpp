#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int h[101];
int n;

void swap(int x,int y){
	int temp;
	temp = h[x];
	h[x]=h[y];
	h[y]=temp;
}

void siftdown(int i){
	int t,flag=0;
	while(i*2<=n && flag==0){
		if(h[i]>h[i*2])
			t = i*2;
		else
			t = i;
		
		if(i*2+1 <=n){
			if(h[t]>h[i*2+1])
				t=i*2+1;
		}
		if(t!=i){
			swap(t,i);
			i=t;
		}else
			flag = 1;
	}
}

void create(){
	int i;
	//从最后一个非叶节点到第一个节点依次进行向下调整 
	for(i=n/2;i>=1;i--)
		siftdown(i);	
}

int deletemin(){
	int t;
	t = h[1];
	h[1] = h[n];
	n--;
	siftdown(1);
	return t;
}

int main(){
	int i,num;
	cin>>num;
	for	(i=1;i<=num;i++)
		cin>>h[i];

	n = num;
	//建堆
	create();
	
	//删除顶部元素，连续删除n次，其实就是从小到大把数输出来
	for(i=1;i<=num;i++)
		cout<<deletemin()<<" ";
	cout<<endl;
	getchar();getchar();
	return 0;
}
