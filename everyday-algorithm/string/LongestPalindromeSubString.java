package com.lhl.algorithm.everyday_algorithm.string;

/**
 * 最长回文子串
 *
 * @author LHL
 * Date: 2018/5/25
 * <p>
 * https://segmentfault.com/a/1190000003914228
 * https://juejin.im/entry/58c7936944d90400699c2db4
 */
public class LongestPalindromeSubString {

    public static void main(String[] args) {
        char[] cs = "abba".toCharArray();
        System.out.println(getLongestByEnum(cs, cs.length));
        System.out.println(manacher("abba"));
    }

    // 枚举所有中心位置
    private static int getLongestByEnum(char[] cs, int n) {
        if (cs == null || n < 1) {
            return 0;
        }

        int max, i, j, c;
        max = 0;
        c = 0;

        // i 为回文的中心位置
        for (i = 0; i < n; i++) {

            // 回文长度为奇数
            for (j = 0; (i - j >= 0) && (i + j < n); ++j) {
                if (cs[i - j] != cs[i + j]) {
                    break;
                }
                c = j * 2 + 1;
            }
            if (c > max) {
                max = c;
            }

            // 回文长度为偶数
            for (j = 0; (i - j >= 0) && (i + j + 1 < n); ++j) {
                if (cs[i - j] != cs[i + j + 1]) {
                    break;
                }
                c = j * 2 + 2;
            }
            if (c > max) {
                max = c;
            }

        }

        return max;
    }

    private static int manacher(String str) {
        StringBuffer newStr = new StringBuffer();
        newStr.append('#');
        for (int i = 0; i < str.length(); i++) {
            newStr.append(str.charAt(i));
            newStr.append('#');
        }

        int[] rad = new int[newStr.length()];
        int right = -1;
        int id = -1;

        for (int i = 0; i < newStr.length(); i++) {
            int r = 1;
            if (i <= right) {
                r = Math.min(rad[2 * id - i], id + rad[id] - i);
            }
            while (i - r >= 0 && i + r < newStr.length() && newStr.charAt(i - r) == newStr.charAt(i + r)) {
                r++;
            }

            if (i + r - 1 > right) {
                right = i + r - 1;
                id = i;
            }
            rad[i] = r;
        }

        int maxRad = 0;
        for (int r : rad) {
            if (r > maxRad) {
                maxRad = r;
            }
        }
        return maxRad - 1;
    }


}
