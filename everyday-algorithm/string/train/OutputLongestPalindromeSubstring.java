/**
 * 输出最长回文子串
 * <p>
 * 将一个很长的字符串分割成一段一段的子串, 要求子串都是回文串. 有回文串就输出最长的, 没有回文串就将字符一个一个输出.
 * 例如: 如果输入 "habbafgh", 则输出 "b, abba, f, g, h"
 *
 * @author LHL
 * Date: 2018/6/12
 */
public class OutputLongestPalindromeSubstring {


    public static void main(String[] args) {
        String str = "hcabbacfghabcdedcba";
        longestPalindromeSubstring(str.toCharArray());
    }

    // 中心扩展
    // 要注意奇数串(aba)和偶数串(abba)
    private static void longestPalindromeSubstring(char[] cs) {
        int leftIndex = 0;
        int rightIndex = 0;
        int max = 0;
        for (int i = 0; i < cs.length; i++) { // 子串是奇数串
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 && left < right && right < cs.length) {
                if (cs[left] == cs[right]) {
                    left--;
                    right++;
                } else {
                    break;
                }
            }
            ++left;
            --right;
            if ((right - left + 1) >= max) {
                max = right - left + 1;
                leftIndex = left;
                rightIndex = right;
            }
        }
        for (int i = 0; i < cs.length; i++) { // 子串是偶数串
            int left = i;
            int right = i + 1;
            while (left >= 0 && left < right && right < cs.length) {
                if (cs[left] == cs[right]) {
                    left--;
                    right++;
                } else {
                    break;
                }
            }
            ++left;
            --right;
            if ((right - left + 1) >= max) {
                max = right - left + 1;
                leftIndex = left;
                rightIndex = right;
            }
        }
        pringSubstring(cs, leftIndex, rightIndex);
    }

    private static void pringSubstring(char[] cs, int leftIndex, int rightIndex) {
        for (int i = leftIndex; i <= rightIndex; i++) {
            System.out.print(cs[i]);
        }
        System.out.println();
    }
}
