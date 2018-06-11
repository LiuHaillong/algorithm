import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * 链表判断回文
 *
 * @author LHL
 * Date: 2018/6/11
 */
public class LinkedListPalindrome {


    public static void main(String[] args) {
        List<Integer> nums = Arrays.asList(1, 2, 3, 2, 1); //true
//        List<Integer> nums = Arrays.asList(1, 2, 3, 4, 2, 1); // false
//        List<Integer> nums = Arrays.asList(1, 2, 3, 3, 2, 1); // true
        Node head = genLinkedList(nums);

        //printLinkedList(head);

        // valid linked list palindrome
        boolean isPalindrome = linkedlistPalindrome(head);
        System.out.println(isPalindrome);
    }

    private static Node genLinkedList(List<Integer> nums) {
        Node head = null;
        Node tmp = null;
        for (int i = 0; i < nums.size(); i++) {
            Node node = new Node(nums.get(i));
            if (i == 0) {
                head = node;
                tmp = node;
                continue;
            }
            if (i == nums.size() - 1) {
                node.setNext(null);
            }
            tmp.setNext(node);
            tmp = node;
        }
        return head;
    }

    private static boolean linkedlistPalindrome(Node head) {
        Node one = head;
        Node two = head;
        boolean isOdd = true;
        while (two != null && two.next() != null) {
            two = two.next().next();
            if (two == null) {
                isOdd = false;
                break;
            }
            one = one.next();
        }
        // one is the mid
        List<Integer> partOfTwo = new ArrayList<>();
        if (isOdd) {
            partOfTwo.add(one.getValue());
            while (one.hasNext()) {
                one = one.next();
                partOfTwo.add(one.getValue());
            }
        } else {
            partOfTwo.add(one.next().getValue());
            one = one.next();
            while (one.hasNext()) {
                one = one.next();
                partOfTwo.add(one.getValue());
            }
        }

        Collections.reverse(partOfTwo);

        boolean isPalindrome = true;

        Node end = genLinkedList(partOfTwo);
        while (end != null) {
            Integer endValue = end.getValue();
            Integer headValue = head.getValue();
            if (headValue != endValue) {
                isPalindrome = false;
                break;
            }
            end = end.next();
            head = head.next();

        }

        return isPalindrome;
    }

    // print value
    private static void printLinkedList(Node head) {
        System.out.println(head.getValue());
        while (head.hasNext()) {
            head = head.next();
            System.out.println(head.getValue());
        }
    }
}

class Node {
    private int value;
    private Node next;

    public Node(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public boolean hasNext() {
        return next != null;
    }

    public Node next() {
        return next;
    }
}
