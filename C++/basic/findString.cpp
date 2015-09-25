#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char s[101];
char p[101];
int T;

int getNum(char* s,char* p){
	int i=0,j=0,count=0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	
	while(i<sLen){
		if(s[i]==p[j]){
			i++;
			j++;
		}else{
			i=i-(j-1);
			j=0;
		}
		
		if(j==pLen){
			count++;
		}
	}
	return count;
}

int main(){
//	scanf("%d",&T);
	cin>>T;
	while(T--){
//		scanf("%s",p);
//		scanf("%s",s);
		
		cin>>p;
		cin>>s;
		
		int num = getNum(s,p);
//		printf("%d\n",num);
		cout<<num<<endl;
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
