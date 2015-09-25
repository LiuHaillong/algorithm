#include<iostream>
#include<algorithm>
using namespace std;

#define maxn 1001
#define INF 99999999
struct room{
	int time;
	int score;
};
struct room r[maxn];

int vis[maxn]={0};
int score[maxn];
int time[maxn][maxn];

int i,j,u,v,n,m,start,end,x,y,z;

void dijkstra(){
	r[start].time = 0;
	r[start].score=score[start];
	
	int min;
	for(i=0;i<n;i++){
		min = INF;
		for(j=0;j<n;j++){
			if(vis[j]==0 && r[j].time<min){
				min = r[j].time;
				u = j;
			}
		}
		vis[u] = 1;
		for(v=0;v<n;v++){
			if(time[u][v]<INF){
				if(r[v].time>=r[u].time+time[u][v]){
					if(r[v].time>r[u].time+time[u][v]){
						r[v].score = r[u].score + score[v];
					}else if(r[v].score<r[u].score+score[v]){
						r[v].score = r[u].score + score[v];
					}
					r[v].time = r[u].time+time[u][v];
				}
			}
		}
	}
}

void init(){
	for(i=0;i<maxn;i++){
		for(j=0;j<maxn;j++){
			time[i][j]=INF;
		}
		r[i].time=INF;
		r[i].score=0;
	}
}

int main(){
	init();
	scanf("%d %d %d %d",&n,&m,&start,&end);
	for(i=0;i<n;i++)
		scanf("%d",&score[i]);
	for(i=0;i<m;i++){
		scanf("%d %d %d",&x,&y,&z);
		time[x][y] = z;
		time[y][x] = z;
	}
	dijkstra();
	printf("%d %d\n",r[end].time,r[end].score);
	return 0;
}
