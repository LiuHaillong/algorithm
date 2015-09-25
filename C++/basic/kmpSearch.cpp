#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

char s[10005];
char p[1000005];
int nexts[10005]={-1};
int T;

void Get_Next(char* p){
	int pLen = strlen(p);
	nexts[0] = -1;
	int k = -1;
	int j = 0;
	while(j<pLen){
		if(k==-1 || p[j]==p[k])
			nexts[++j] = ++k;
		else
			k = nexts[k];
	}
}

void kmp(char* s,char* p){
	int i=0,j=0,count=0;
	Get_Next(p);
	int sLen = strlen(s);
	int pLen = strlen(p);
	
	while(i<sLen){
		if(j==-1 || s[i]==p[j]){
			i++;
			j++;
		}else{
			j=nexts[j];
		}
		
		if(j==pLen){
			count++;
		}
	}
	printf("%d\n",count);
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s %s",p,s);
		kmp(s,p);
	}
	return 0;
}

//5
//HA
//HAHAHA
//WQN
//WQN
//ADA
//ADADADA
//BABABB
//BABABABABABABABABB
//DAD
//ADDAADAADDAAADAAD
//ÑùÀýÊä³ö
//3
//1
//3
//1
//0
