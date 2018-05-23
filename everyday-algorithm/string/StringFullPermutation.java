import java.util.Arrays;

/**
 * 字符串全排列
 *
 * @author LHL
 * Date: 2018/5/22
 */
public class StringFullPermutation {

    public static void main(String[] args) {
//        permutationByRecursion("ab".toCharArray(), 0, 1);
        permutationByDicSort("adcb");
    }


    // 递归全排列
    public static void permutationByRecursion(char[] cs, int from, int to) {
        if (to < 1) {
            return;
        }
        if (from == to) {
            for (int i = 0; i <= to; i++) {
                System.out.print(cs[i]);

            }
            System.out.println();
        } else {
            for (int j = from; j <= to; j++) {
                swap(cs, j, from);
                permutationByRecursion(cs, from + 1, to);
                swap(cs, j, from); // 复位
            }
        }
    }

    // 字典序全排列
    public static void permutationByDicSort(String s) {
        char[] cs = s.toCharArray();
        Arrays.sort(cs);
        System.out.println(cs);

        while (doPermutationByDicSort(cs)) {
            System.out.println(cs);
        }
    }

    private static boolean doPermutationByDicSort(char[] cs) {
        int i;
        for (i = cs.length - 2; (i >= 0) && (cs[i] > cs[i + 1]); --i) ;
        if (i < 0) {
            return false;
        }

        int j;
        for (j = cs.length - 1; (j > i) && (cs[i] >= cs[j]); --j) ;
        swap(cs, i, j);
        reverseArray(cs, i + 1, cs.length - 1);
        return true;
    }

    private static void reverseArray(char[] cs, int i, int n) {
        while(i<n){
            char tmp = cs[i];
            cs[i++] = cs[n];
            cs[n--] = tmp;
        }
    }

    public static void swap(char[] cs, int j, int from) {
        char tmp = cs[j];
        cs[j] = cs[from];
        cs[from] = tmp;
    }
}
