package enmu;

import java.util.Scanner;

/**
 * 火柴棍等式
 * @author lhl
 *
 */
public class CalcNum {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int a,b,c,sum=0;
		for(a=0;a<=1111;a++){
			for(b=0;b<=1111;b++){
				c = a + b;
				if(getNum(a)+getNum(b)+getNum(c)==num-4){
					System.out.println(a+"+"+b+"="+c);
					sum++;
				}
			}
		}
		System.out.println("一共可以拼出"+sum+"个不同的等式");
	}
	
	private static int getNum(int x){
		int num = 0;
		int f[] = {6,2,5,5,4,5,6,3,7,6};
		while(x/10!=0){
			num+=f[x%10];
			x = x/10;
		}
		num+=f[x];
		return num;
	}
}
