import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

/**
 * 栈回文
 *
 * @author LHL
 * Date: 2018/6/11
 */
public class StackPalindrome {


    public static void main(String[] args) {
        List<Integer> nums = Arrays.asList(1, 2, 3, 3, 2, 1); // true
//        List<Integer> nums = Arrays.asList(1, 2, 3, 2, 1); // true
//        List<Integer> nums = Arrays.asList(1, 2, 3, 4, 2, 1); // false

        System.out.println(stackPalindrome(nums));
    }

    private static boolean stackPalindrome(List<Integer> nums) {
        Stack<Integer> origin = genStack(nums);
        Stack<Integer> use = genStack(nums);
        ArrayList<Integer> reverseNums = new ArrayList<>();
        while (!use.isEmpty()) {
            reverseNums.add(use.pop());
        }

        Stack<Integer> reverse = genStack(reverseNums);
        while (!reverse.isEmpty()) {
            Integer reverseNum = reverse.pop();
            Integer originNum = origin.pop();
            if (reverseNum != originNum) {
                return false;
            }
        }
        return true;
    }

    private static Stack<Integer> genStack(List<Integer> nums) {
        Stack<Integer> stack = new Stack<>();
        for (Integer num : nums) {
            stack.push(num);
        }
        return stack;
    }
}
