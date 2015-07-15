package sort;

import java.util.Scanner;

/**
 * 基于桶排序的去重和排序
 */
public class ISBN {
	private static int book[] = new int[100000000];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i = 1; i <= n; i++) {
			int isbn = sc.nextInt();
			book[isbn] += 1;
		}
		int count = 0;
		long st = System.currentTimeMillis();
//		for(int i=1;i<=1000;i++){
//			if(book[i]!=0){
//				count ++;
//			}
//		}
//		System.out.println(count);
//		for(int i=1;i<=1000;i++){
//			if(book[i]!=0){
//				System.out.print(i+" ");
//			}
//		}
//		System.out.println();
		for (int i=0;i<=100000000;i++){
			book[i] = i;
		}
		long et = System.currentTimeMillis();
		System.out.println((et-st)+"ms");
		sc.close();
	}

}
//input:
//10
//20 40 32 67 40 20 89 300 400 15