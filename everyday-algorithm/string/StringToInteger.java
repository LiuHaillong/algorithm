/**
 * 字符串转换成整数
 *
 * @author LHL
 * Date: 2018/5/24
 */
public class StringToInteger {
    public static void main(String[] args) {

        String s = "   -2147483649";
        System.out.println(strToInt(s));
    }

    private static int strToInt(String str) {
        char[] cs = str.toCharArray();

        final int MAX_VALUE = Integer.MAX_VALUE;
        final int MIN_VALUE = Integer.MIN_VALUE;

        if (cs.length == 0) {
            return 0;
        }

        int i = 0;
        int n = 0;

        //  处理空格
        while (Character.isSpaceChar(cs[i])) {
            ++i;
        }

        // 处理正负
        int sign = 1;
        if (cs[i] == '+' || cs[i] == '-') {
            if (cs[i] == '-')
                sign = -1;
            ++i;
        }

        // 确定是数字后才执行循环
        while (Character.isDigit(cs[i])) {
            // 处理溢出
            int c = cs[i] - '0';
            if (sign > 0 && (n > MAX_VALUE / 10 || (n == MAX_VALUE / 10 && c > MAX_VALUE % 10))) {
                n = MAX_VALUE;
                break;
            } else if (sign < 0 && (n > MIN_VALUE / 10 || (n == MIN_VALUE / 10 && c > MIN_VALUE % 10))) {
                n = MIN_VALUE;
                break;
            }

            n = n * 10 + c;
            ++i;
            if (i == cs.length)
                break;
        }
        return sign > 0 ? n : -n;

    }
}
