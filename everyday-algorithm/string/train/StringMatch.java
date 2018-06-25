/**
 * 字符串的匹配
 * 在一篇英文文章中查找指定的人名, 人名使用26个英文字母(可以是大写或小写), 空格及两个通配符(*和?)组成, 通配符*表示零个或多个任意字母, 通配符?表示一个任意字母.
 * 例如: "J* Smi??" 可以匹配 "John Smith"
 *
 * @author LHL
 * Date: 2018/6/22
 */
public class StringMatch {

    public static void main(String[] args) {
//        String str1 = "adasdakjljlJohn Smithjasdadasd";
        String str1 = "John Smith";
        String str2 = "J* Smi??";
        System.out.println(stringMatch(str1, str2));
    }

    private static boolean stringMatch(String str1, String str2) {
        boolean[][] dp = new boolean[str2.length() + 1][str1.length() + 1];
        dp[0][0] = true;

        for (int i = 1; i <= str2.length(); i++) {
            char str2_char = str2.charAt(i - 1);
            dp[i][0] = dp[i - 1][0] && str2_char == '*';
            for (int j = 1; j <= str1.length(); j++) {
                char str1_char = str1.charAt(j - 1);
                if (str2_char == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i-1][j-1] && (str2_char == '?' || str1_char == str2_char);
                }
            }
        }
        return dp[str2.length()][str1.length()];
    }

}
