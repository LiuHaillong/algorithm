#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char str[2000020],s[2000020];
int p[2000020];
int len,id,mx;
void pre() //对字符串进行预处理
{
    len=strlen(s);
    str[0]='$';
    str[1]='#';
    for(int i=0;i<len;i++)
    {
        str[i*2+2]=s[i];
        str[i*2+3]='#';
    }
    len=len*2+2;
    str[len]=0;
}
void Manacher() //算法核心
{
    mx=0;
    for(int i=1;i<len;i++)
    {
       p[i]=mx > i ? min(p[2*id - i], mx-i):1;
        while(str[i+p[i]]==str[i-p[i]])
            p[i]++;
        if(p[i]+i>mx)
        {
            mx=p[i]+i;
            id=i;
        }
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%s",s);
        pre();
        Manacher();
        int max=0;
		for(int i=1;i<=len;i++){
			if(p[i]>=max)
				max = p[i];
		}
		printf("%d\n",max-1);
    }
    return 0;
}

