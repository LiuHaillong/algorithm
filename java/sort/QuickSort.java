package sort;

import java.util.Scanner;

/**
 * 快速排序
 */
public class QuickSort {
	private static int a[] = new int [101];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i=1;i<=n;i++){
			a[i] = sc.nextInt();
		}
		quicksort(1, n);
		
		for(int i=1;i<=n;i++){
			System.out.println(a[i]+" ");
		}
		sc.close();
	}
	
	//快排
	private static void quicksort(int left,int right){
		int temp = a[left];//基准数
		int i = left;
		int j = right;
		if (left>right){
			return ;
		}
		
		while(i!=j){
			//顺序要从右往左走
			while(a[j]>=temp && i<j)
				j--;
			
			//然后再从左往右找
			while(a[i]<=temp && i<j)
				i++;
			
			//交换2个数在数组中的位置
			//当哨兵i和哨兵j没有相遇时
			if(i<j){
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
		//最终将基准数归位
		a[left] = a[i];
		a[i] = temp;
		
		quicksort(left, i-1);
		quicksort(i+1, right);
	}
}
