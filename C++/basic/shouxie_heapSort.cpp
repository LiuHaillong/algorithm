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
	h[x] = h[y];
	h[y] = temp;
}

void siftdown(int i){
	int t,flag=0;
	while(flag==0 && i*2<=n){
		if(h[i]>h[i*2])
			t = i*2;
		else 
			t = i;
		
		if(i*2+1<=n){
			if(h[t]>h[i*2+1]){
				t = i*2+1;
			}
		}
		if(t!=i){
			swap(t,i);
			i = t;
		}
		else
			flag = 1;
	}
}

int deleteMin(){
	int t;
	t = h[1];
	h[1] = h[n];
	n--;
	siftdown(1);
	return t;
}

//建立最小堆 
void create(){
	int i;
	for(i=n/2;i>=1;i--)
		siftdown(i);
}

int main(){
	int i,num;
	cin>>num;
	for(i=1;i<=num;i++)
		cin>>h[i];
	
	n=num;
	//
	create();
	
	for(i=1;i<=num;i++)
		cout<<deleteMin()<<" ";
	cout<<endl;
	getchar();getchar();
	return 0;
}
