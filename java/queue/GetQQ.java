package queue;

import java.util.Scanner;

public class GetQQ {
	public static void main(String[] args) {
		int head,tail,a[]=new int[102];
		a[1]=6;
		a[2]=3;
		a[3]=1;
		a[4]=7;
		a[5]=5;
		a[6]=8;
		a[7]=9;
		a[8]=2;
		a[9]=4;
		int i;
		head =1 ;
		tail = 10;
		while(head<tail){
			System.out.print(a[head]+" ");
			head++;
			
			a[tail] = a[head];
			tail++;
			
			head++;
		}
		
	}
}
