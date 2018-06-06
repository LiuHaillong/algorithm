import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;

/**
 * 变位词, 在字典中快速找到它的兄弟字符串
 *
 * @author LHL
 * Date: 2018/6/6
 */
public class BrotherString {

    private static List<String> dic;

    static {
        dic = new ArrayList<>();
        dic.add("abc");
        dic.add("cba");
        dic.add("abe");
        dic.add("eab");
        dic.add("eac");
    }

    public static void main(String[] args) {
        String s1 = "ace";
        for (String s : dic) {

            checkBrother(s1, s);
        }
    }

    private static boolean checkBrother(String s1, String s) {
        char[] cs1 = s1.toCharArray();
        char[] cs2 = s.toCharArray();

        HashMap<Character, Integer> map = new HashMap<>();
        for (char c : cs1) {
            if (!map.containsKey(c)) {
                map.put(c, 1);
            } else {
                map.put(c, map.get(c) + 1);
            }
        }

        try {
            for (char c : cs2) {
                map.put(c, map.get(c) - 1);
            }
        } catch (Exception e) {
        }

        int count = 0;
        Collection<Integer> values = map.values();
        for (Integer value : values) {
            count += value;
        }

        if (count == 0) {
            System.out.println(s);
            return true;
        }
        return false;
    }
}
