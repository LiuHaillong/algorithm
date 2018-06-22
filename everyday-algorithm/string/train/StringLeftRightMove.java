import java.util.Stack;

/**
 * 字符串的左右移动
 * 给定一个字符串, 这个字符串为*号和26个字母的任意组合. 现在需要把字符串中的*号都移动到左侧, 而把字符串中的字母移到最右侧并保持相对顺序不变, 要求时间复杂度和空间复杂度最小!
 *
 * @author LHL
 * Date: 2018/6/22
 */
public class StringLeftRightMove {


    public static void main(String[] args) {
        String str = "c***a*b****cd**efh*jkl";

        stringLeftRightMove(str);
        stringLeftRightMoveWithStack(str);
    }

    private static void stringLeftRightMoveWithStack(String str) {
        Stack<Character> leftStack = new Stack<>();
        Stack<Character> rightStack = new Stack<>();
        char[] cs = str.toCharArray();
        for (int i = cs.length - 1; i > -1; i--) {
            char c = cs[i];
            if (c == '*') {
                leftStack.push(c);
            } else {
                rightStack.push(c);
            }
        }

        while (!leftStack.isEmpty()) {
            Character c = leftStack.pop();
            System.out.print(c);
        }
        while (!rightStack.isEmpty()) {
            Character c = rightStack.pop();
            System.out.print(c);
        }

        System.out.println();
    }

    private static void stringLeftRightMove(String str) {
        char[] cs = str.toCharArray();
        int point = cs.length - 1; //字符串尾部第一个*的位置
        int left = cs.length - 1; // 距离*最近的第一个字母的位置
        for (int i = cs.length - 1; i > 0; i--) {
            if (cs[i] == '*') {
                point = i;
                left = point;
                while(cs[left] == '*' && left > 0) {
                    left--;
                }
                swap(cs, point, left);
            }
        }

        printChar(cs);
    }

    public static void swap(char[] cs, int i, int j) {
        char tmp = cs[i];
        cs[i] = cs[j];
        cs[j] = tmp;
    }

    public static void printChar(char[] cs) {
        for (char c : cs) {
            System.out.print(c);
        }
        System.out.println();
    }
}
