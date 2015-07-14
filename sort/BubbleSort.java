import java.util.Scanner;

/**
 * bubble sort
 */
public class BubbleSort {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int len = sc.nextInt();
		int a[] = new int[len];
		for (int i = 0; i < len; i++) {
			a[i] = sc.nextInt();
		}
		
		for(int i=0;i<len-1;i++){
			for(int j=0;j<len-1;j++){
				if(a[j]<a[j+1]){
					int tmp = a[j+1];
					a[j+1] = a[j];
					a[j] = tmp;
				}
			}
		}
		
		for(int i=0;i<len;i++){
			System.out.print(a[i]+" ");
		}
		sc.close();
	}
}
