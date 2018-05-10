package com.bynear.algorithm.everyday_algorithm.string;

/**
 * 旋转字符串
 *
 * @author HaiLong Liu
 */
public class RotateString {

    /**
     * 向左位移1位
     *
     * @param a 字符数组
     * @param n 字符数组长度
     */
    public static void leftShiftOne(char[] a, int n) {
        char first = a[0];
        for (int i = 1; i < n; i++) {
            a[i - 1] = a[i];
        }
        a[n - 1] = first;
    }

    /**
     * @param str 字符串
     * @param n   左移位数
     * @return
     */
    public static String rotateStr1(String str, int n) {
        char[] a = str.toCharArray();
        while (n-- > 0) {
            leftShiftOne(a, a.length);
        }
        return new String(a);
    }


    public static void main(String[] args) {
        String str = "abcdef";
        System.out.println(rotateStr1(str, 14)); // 暴力位移
        System.out.println(rotateStr2(str, 14)); // 三步翻转
    }

    /**
     * @param str 原字符串
     * @param n   左移n位
     * @return
     */
    private static String rotateStr2(String str, int n) {
        char[] a = str.toCharArray();
        int l = a.length;
        n %= a.length;
        reverseString(a, 0, n - 1);
        reverseString(a, n, l - 1);
        reverseString(a, 0, l - 1);
        return new String(a);
    }

    private static void reverseString(char[] a, int from, int to) {
        while (from < to) {
            char t = a[from];
            a[from++] = a[to];
            a[to--] = t;
        }
    }
}
