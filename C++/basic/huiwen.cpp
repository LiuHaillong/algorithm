#include<stdio.h>
#include<string.h>
int main(){
	char a[101],s[101];
	int i,len,mid,next,top;
	//读入一行字符串
	gets(a);
	//求字符串长度 
	len = strlen(a);
	//求中间点
	mid = len/2 - 1;
	
	//栈的初始化
	top = 0;
	//把中间点前的值入栈
	for(i=0;i<=mid;i++){
		s[++top]=a[i];
	} 
	
	if (len%2==0)
		next = mid + 1;
	else
		next = mid + 2;
		
	for(i=next;i<=len-1;i++){
		if(a[i]!=s[top])
			break;
		top--;
	}
	
	if (top==0)
		printf("YES");
	else 
		printf("NO");
}
