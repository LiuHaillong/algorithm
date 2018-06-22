/**
 * 字符个数的统计
 *
 * @author LHL
 * Date: 2018/6/22
 */
public class CharNumStatis {

    public static void main(String[] args) {
        String str = "aaaasdasdasdlkjljl;k;klk;lc,mnxv,xncv";

        charNumStatis(str);
    }

    private static void charNumStatis(String str) {
        char[] cs = str.toCharArray();
        int[] ret = new int[1024];
        for (int i = 0; i < cs.length; i++) {
            char c = cs[i];
            ret[c] += 1;
        }

        for (char c : cs) {
            System.out.printf("%c %d\n", c, ret[c]);
        }
    }
}
