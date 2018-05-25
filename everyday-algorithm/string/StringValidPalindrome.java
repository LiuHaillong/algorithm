/**
 * 字符串回文判断
 *
 * @author LHL
 * Date: 2018/5/25
 */
public class StringValidPalindrome {

    public static void main(String[] args) {
        String s = "12345654322";
        String s1 = "12345654321";
        System.out.println(isPalindrome(s));
        System.out.println(isPalindrome(s1));
    }

    private static boolean isPalindrome(String s) {
        char[] cs = s.toCharArray();

        if (s.equals("") || s.length() < 1) {
            return false;
        }

        for (int i = 0, j = cs.length - 1; i < j; ) {
            if (cs[i] != cs[j]) {
                return false;
            }
            ++i;
            --j;
        }

        return true;
    }
}
