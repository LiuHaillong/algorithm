/**
 * @author LHL
 * Date: 2018/6/6
 */
public class SequencePrint {

    private static char endChar = 'h';
    private static int flag = 0;

    public static void main(String[] args) {

        int total = endChar - 'a' + 1;

        sequencePrint(total);
    }

    private static void sequencePrint(int total) {
        char ch = 0;
        String str = "";
        int len = 0;
        for (int i = 1; i <= total; i++) {
            len = i;
            flag = 0;
            for (int j = 0; j < total; j++) {
                ch = (char) ('a' + j);
                str = "(";
                str += ch;
                solve(str, len, ch);
            }
            System.out.println();
        }
    }

    private static void solve(String str, int len, char ch) {
        if (len == 1) {
            if (flag == 1) {
                System.out.print(",");
            }
            flag = 1;
            System.out.print(str + ")");
            return;
        } else {
            String str1 = str;
            char tmp = 0;
            for (int i = 1; ch + i <= endChar; i++) {
                str1 = str + ",";
                tmp = (char) (ch + i);
                str1 += tmp;
                solve(str1, len - 1, tmp);
            }
        }
    }
}
