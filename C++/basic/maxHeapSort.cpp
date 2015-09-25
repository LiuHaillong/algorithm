#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int h[101];
int n;

void swap(int x,int y){
	int temp = h[x];
	h[x] = h[y];
	h[y] = temp;
}

void siftdown(int i){
	int t,flag=0;
	while(flag==0 && i*2<=n){
		if(h[i]<h[i*2])
			t = i*2;
		else
			t = i;
		
		if(i*2+1<=n){
			if(h[t]<h[i*2+1])
				t = i*2+1;
		}
		if(t!=i){
			swap(t,i);
			i = t;
		}else
			flag = 1;
	}
}

void create(){
	int i;
	for (i=n/2;i>=1;i--)
		siftdown(i);
}

int deleteMax(){
	int t;
	t = h[1];
	h[1] = h[n];
	n--;
	siftdown(1);
	return t;
}

void heapSort(){
	while(n>1){
		swap(1,n);
		n--;
		siftdown(1);
	}
}

int main(){
	int i,num;
	cin>>num;
	for (i=1;i<=num;i++)
		cin>>h[i];
	n = num;
	
	//½¨×î´ó¶Ñ 
	create();
	
	heapSort();
	
//	for(i=1;i<=num;i++)
//		cout<<deleteMax()<<" ";
		
	for(i=1;i<=num;i++)
		cout<<h[i]<<" ";	
	cout<<endl;
	
	
	getchar();getchar();
	return 0; 
}
