/**
 * 输入一个英文单词,翻转句子中单词的顺序, 要求单词内字符的顺序不变,句子中单词以空格符隔开. 为简单起见,标点符号和普通字母一样处理.
 * 如输入: "I am a student." 输出: "student. a am I"
 *
 * @author LHL
 * Date: 2018/6/5
 */
public class WordReverse {
    public static void main(String[] args) {
        String s = "I am a student.";
        wordReverse(s);
    }

    // 先整体翻转, 然后每个单词再翻转
    private static void wordReverse(String s) {
        char[] cs = s.toCharArray();

        reverse(cs, 0, cs.length - 1);

        int k = 0;
        for (int i = 0; i < cs.length; i++) {
            char c = cs[i];
            if (c == ' ') {
                reverse(cs, k, i - 1);
                k = i + 1;
            }
        }

        for (int i = 0; i < cs.length; i++) {
            char c = cs[i];
            System.out.print(c);
        }
    }

    private static void reverse(char[] cs, int from, int to) {
        if (from > to)
            return;


        while (from < to) {
            char tmp = cs[from];
            cs[from++] = cs[to];
            cs[to--] = tmp;
        }
    }
}
