//Bellman-Ford �����Ȩ��(�Ż�)
#include<stdio.h>
int main(){
	int i,j,k,n,m,dis[101],e[101][101],u[101],v[101],w[101];
	int bak[101],check,flag;
	int inf = 99999999;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j)
				e[i][j]=0;
			else
				e[i][j]=99999999;
		}
	}
	
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
	}
	
	for(i=1;i<=n;i++)
		dis[i]=inf;
	dis[1]=0;
	
	//Bellman-Ford���Ĵ���
	for(k=1;k<=n-1;k++){
		//��dis���鱸����bak
		for(i=1;i<=n;i++)
			bak[i] =  dis[i];
		for(i=1;i<=m;i++){
			if(dis[v[i]]>dis[u[i]]+w[i]){
				dis[v[i]]=dis[u[i]]+w[i];
			}
		}
		check=0;
		for(i=1;i<=n;i++){
			if(dis[i]!=bak[i]){
				check=1;
				break;
			}
		}
		
		if(check==0)
			break;		 
	}
	//��⸺Ȩ��·
	for(i=1;i<=m;i++)
		if(dis[v[i]]>dis[u[i]]+w[i])
			flag=1;
	if(flag==1){
		printf("��ͼ�и�Ȩ��·");
	}else{
		for(i=1;i<=n;i++)
		printf("%d ",dis[i]);
	}
		
	getchar();getchar();
	return 0; 
}
