#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char s[101];
int n,m;
//abchbn def

//cba fed
//def abc
void ReverseString(char* s,int from,int to){
	while(from<to){
		char t = s[from];
		s[from++]=s[to];
		s[to--]=t;
	}
}

void LeftRotateString(char* s,int n,int m){
	m %=n;
	ReverseString(s,0,m-1);
	ReverseString(s,m,n-1);
	ReverseString(s,0,n-1);
}

int main(){
	scanf("%s",&s);
	n=strlen(s);
	scanf("%d",&m);
	LeftRotateString(s,n,m);
	puts(s);	
	
	return 0;
}
