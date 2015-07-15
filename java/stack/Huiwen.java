package stack;

import java.util.Scanner;

/**
 * 判断一个字符串是否是回文字符串
 */
public class Huiwen {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] a = new char[101];
		char[] s = new char[101];
		a = sc.next().toCharArray();
		int i,len,mid,next,top;
		len = a.length;
		//计算中间点
		mid = len/2 - 1;
		//初始化栈
		top = 0;
		for(i=0;i<=mid;i++){
			s[++top] = a[i];
		}
		
		if(len%2==0)
			next = mid + 1;
		else
			next = mid + 2;
		
		for(i=next;i<=len-1;i++){
			if(s[top]!=a[i])
				break;
			top--;
		}
		
		if(top==0)
			System.out.println("YES");
		else
			System.out.println("NO");
		
		sc.close();
	}
}
