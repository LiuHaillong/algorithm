package sort;

import java.util.Scanner;

/**
 * 桶排序
 * @author BucketSort lhl
 */
public class BucketSort {
	public static void main(String[] args) {
		int a[] = new int[11];
		for (int i = 0; i <= 10; i++)
			a[i] = 0;
		Scanner sc = new Scanner(System.in);
		for (int i = 1; i <= 5; i++) {
			int num = sc.nextInt();
			a[num]++;
		}
		for(int i=10;i>=1;i--){
			for(int j=1;j<=a[i];j++){
				System.out.print(i+"\t");
			}
		}
		sc.close();
	}
}
