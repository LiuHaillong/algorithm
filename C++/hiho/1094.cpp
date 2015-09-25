#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char map[205][205];
char sur1[5][5];
char sur2[5][5];
char sur3[5][5];
char sur4[5][5];
//将字符串右旋转90° 
void change(char sur[][5]){
	char temp[4][4];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			temp[i][j]=sur[i][j];
	
	for(int i=0;i<3;i++)
		sur[i][2]=temp[0][i];
	for(int i=0;i<3;i++)
		sur[i][1]=temp[1][i];
	for(int i=0;i<3;i++)
		sur[i][0]=temp[2][i];
}

void create(char sur1[][5]){ //求出将字符串转90,180,270之后的情况
	 for(int i=0;i<3;i++)
	 	for(int j=0;j<3;j++)
		 	sur2[i][j]=sur1[i][j];
	change(sur2);	 
	for(int i=0;i<3;i++)
	 	for(int j=0;j<3;j++)
		 	sur3[i][j]=sur2[i][j];
	change(sur3);
	for(int i=0;i<3;i++)
	 	for(int j=0;j<3;j++)
		 	sur4[i][j]=sur3[i][j];
	change(sur4);
}

int judge(char map[][205],int x,int y,char sur[][5]){
	if(map[x-1][y-1]!=sur[0][0] || map[x-1][y]!=sur[0][1] || map[x-1][y+1]!=sur[0][2] || map[x][y-1]!=sur[1][0] || map[x][y]!=sur[1][1] || map[x][y+1]!=sur[1][2] || map[x+1][y-1]!=sur[2][0] || map[x+1][y]!=sur[2][1] || map[x+1][y+1]!=sur[2][2])
		return 0;
	return 1;
}

int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s",map[i]);
		}
		for(int i=0;i<3;i++){
			scanf("%s",sur1[i]);
		}
		char center = sur1[1][1];
		create(sur1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(center==map[i][j]){
					if(judge(map,i,j,sur1) || judge(map,i,j,sur2) || judge(map,i,j,sur3) || judge(map,i,j,sur4))
						printf("%d %d\n",i+1,j+1);
				}
	}
	return 0;
}
