package com.bynear.algorithm.stack;

/**
 * @author HaiLong Liu
 */
public class StackTest {
    public static void main(String[] args) {
        StackArray stackArray = new StackArray();
        System.out.println(stackArray.getSize());

        stackArray.push(1);
        stackArray.push(2);
        stackArray.push(3);
        System.out.println(stackArray.getSize());
        System.out.println(stackArray.peek());
        System.out.println(stackArray.pop());
        System.out.println(stackArray.pop());
        System.out.println(stackArray.pop());
        System.out.println(stackArray.pop());
    }
}
