package com.bynear.algorithm.everyday_algorithm.string;

import java.math.BigDecimal;

/**
 * 字符串包含(若字符串b中的所有字符都在a中, 则包含)
 * <p>
 * a:"ABCD"; b:"BAD" ===> true
 * a:"ABCD"; b:"BAE" ===> false
 * a:"ABCD"; b:"AA" ===> true
 *
 * @author HaiLong Liu
 */
public class StringContain {

    public static void main(String[] args) throws Exception {
//        System.out.println(isContain("ABCD", "BAD"));
//        System.out.println(isContainBySort("ABCD", "BAD"));
//        System.out.println(isContainByPrimeMulti("ABCD", "BAE"));
        System.out.println(isContainByHash("ABCD", "BAD"));
    }

    // 暴力轮询
    // O(nm)
    public static boolean isContain(String aStr, String bStr) {
        char[] a = aStr.toCharArray();
        char[] b = bStr.toCharArray();

        for (int i = 0; i < b.length; i++) {
            int j;
            for (j = 0; j < a.length && a[j] != b[i]; j++) ;
            if (j >= a.length) {
                return false;
            }
        }
        return true;
    }

    // 排序后轮询
    public static boolean isContainBySort(String aStr, String bStr) {
        char[] a = aStr.toCharArray();
        char[] b = bStr.toCharArray();

        quickSort(a, 0, a.length - 1);
        quickSort(b, 0, b.length - 1);

        for (int pa = 0, pb = 0; pb < b.length; ) {
            while ((pa < a.length) && (a[pa] < b[pb])) {
                pa++;
            }

            if ((pa >= a.length) || (a[pa] > b[pb])) {
                return false;
            }
            pb++;
        }
        return true;
    }

    // 素数相乘
    public static boolean isContainByPrimeMulti(String aStr, String bStr) {
        char[] a = aStr.toCharArray();
        char[] b = bStr.toCharArray();

        final int[] mapping = new int[]{3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        BigDecimal result1 = new BigDecimal(1);
        for (int i = 0; i < a.length; ++i) {
            BigDecimal v = new BigDecimal(mapping[a[i] - 'A']);
            if (result1.divideAndRemainder(v)[1].intValue() != 0) {
                result1 = v.multiply(result1);
            }
        }

        for (int i = 0; i < b.length; ++i) {
            BigDecimal v = new BigDecimal(mapping[b[i] - 'A']);
            if (result1.divideAndRemainder(v)[1].intValue() != 0) {
                return false;
            }
        }

        return true;
    }

    public static boolean isContainByHash(String aStr, String bStr) {
        char[] a = aStr.toCharArray();
        char[] b = bStr.toCharArray();

        int hash = 0;
        for (int i = 0; i < a.length; ++i) {
            hash |= (1 << (a[i] - 'A'));
        }

        for (int i = 0; i < b.length; ++i) {
            if ((hash & (1 << (b[i] - 'A'))) == 0) {
                return false;
            }
        }
        return true;
    }

    // 快速排序
    private static void quickSort(char[] c, int left, int right) {
        if (left > right) {
            return;
        }
        char tmp;
        int i, j;
        tmp = c[left];
        i = left;
        j = right;

        while (i != j) {
            while (c[j] >= tmp && i < j) {
                j--;
            }

            while (c[i] <= tmp && i < j) {
                i++;
            }

            if (i < j) {
                swap(c, i, j);
            }
        }

        c[left] = c[i];
        c[i] = tmp;

        quickSort(c, left, i - 1);
        quickSort(c, i + 1, right);
    }

    // 交换
    private static void swap(char[] c, int i, int j) {
        char tmp = c[i];
        c[i] = c[j];
        c[j] = tmp;
    }
}
