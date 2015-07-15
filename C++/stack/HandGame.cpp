#include<stdio.h>
struct queue {
	int data[1000];
	int head;
	int tail;
};
struct stack{
	int data[10];
	int top;
};
int main(){
	struct queue q1,q2;
	struct stack s;
	int book[10];
	int i,t;
	
	q1.head=1;
	q1.tail=1;
	
	q2.head=1;
	q2.tail=1;
	
	s.top = 0;
	
	for (i=1;i<=9;i++)
		book[i] = 0;
		
	for (i=1;i<=6;i++){
		scanf("%d",&q1.data[q1.tail]);
		q1.tail++;
	}
	for (i=1;i<=6;i++){
		scanf("%d",&q2.data[q2.tail]);
		q2.tail++;
	}
	while(q1.head<q1.tail && q2.head<q2.tail){
		t = q1.data[q1.head];//q1��һ����
		
		if(book[t]==0){//������û��q1���������� 
			//q1����û��Ӯ���͸�ȥ�������Ʋ����ƷŽ����� 
			q1.head++;
			s.top++;
			s.data[s.top] = t;
			book[t] = 1;
		} else{//��������q1���������
			//q1����Ӯ��,һ�ΰ��������Ʒ����Լ�����
			q1.head++;
			q1.data[q1.tail]=t;
			q1.tail++;
			while(s.data[s.top]!=t){
				book[s.data[s.top]] = 0;
				q1.data[q1.tail] = s.data[s.top];
				q1.tail++;
				s.top--;
			} 	
		}
		
		t = q2.data[q2.head];//q2��һ����
		
		if(book[t]==0){//������û��q2���������� 
			//q2����û��Ӯ���͸�ȥ�������Ʋ����ƷŽ����� 
			q2.head++;
			s.top++;
			s.data[s.top] = t;
			book[t] = 1;
		} else{//��������q2���������
			//q2����Ӯ��,һ�ΰ��������Ʒ����Լ�����
			q2.head++;
			q2.data[q2.tail]=t;
			q2.tail++;
			while(s.data[s.top]!=t){
				book[s.data[s.top]] = 0;
				q2.data[q2.tail] = s.data[s.top];
				q2.tail++;
				s.top--;
			} 	
		}
	}
	
	if(q2.head==q2.tail){
		printf("С�� Win\n");
		printf("С�� ��ǰ���е���Ϊ:");
		for(i=q1.head;i<=q1.tail-1;i++)
			printf(" %d",q1.data[i]);
		if(s.top>0){//˵������������	
			printf("\n�����ϵ�����:");
			for(i=1;i<=s.top;i++)
				printf(" %d",s.data[i]);
		}else
			printf("\n�������Ѿ�û������");
	}else{
		printf("С�� Win\n");
		printf("С�� ��ǰ���е���Ϊ:");
		for(i=q1.head;i<=q2.tail-1;i++)
			printf(" %d",q2.data[i]);
		if(s.top>0){//˵������������	
			printf("\n�����ϵ�����:");
			for(i=1;i<=s.top;i++)
				printf(" %d",s.data[i]);
		}else
			printf("\n�������Ѿ�û������");
	}
}
