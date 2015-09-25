#include<stdio.h>
int a[101],n;

void quicksort(int left,int right){
	int i,j,t,temp;
	i = left;
	j = right;
	temp = a[left];
	if (left>right)
		return ;
	
	while(i!=j){
		while(a[j]>=temp && i<j)
			j--;
			
		while(a[i]<=temp && i<j)
			i++;
			
		if(i<j){
			t = a[j];
			a[j] = a[i];
			a[i] = t;
		}
	}
	
	//基准数交换
	a[left] = a[i];
	a[i] = temp;
	
//	for(i=0;i<n;i++){
//		printf("%d ",a[i]);
//	}
//	printf("\n");
	quicksort(left,i-1);
	quicksort(i+1,right);
	return ;
}

int main(){
	int i;	
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);	
	}
	
	quicksort(0,n-1);
	
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
