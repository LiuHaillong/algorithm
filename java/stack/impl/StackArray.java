package com.bynear.algorithm.stack;


/**
 * @author HaiLong Liu
 */
public class StackArray implements Stack {
    private final int LEN = 8;
    private Object[] elements;
    private int top;

    public StackArray() {
        top = -1;
        elements = new Object[LEN];
    }

    @Override
    public int getSize() {
        return top + 1;
    }

    @Override
    public boolean isEmpty() {
        return top < 0;
    }

    @Override
    public void push(Object o) {
        if(getSize() >= elements.length) {
            expandSpace();
        }
        elements[++top] = o;
    }

    private void expandSpace() {
        Object[] a = new Object[elements.length * 2];
        for(int i = 0; i < elements.length; i++) {
            a[i] = elements[i];
        }
        elements = a;
    }

    @Override
    public Object pop() throws StackEmptyException {
        if(getSize() < 1)
            throw new StackEmptyException("error, the stack is empty");
        Object o = elements[top];
        elements[top--] = null;
        return o;
    }

    @Override
    public Object peek() throws StackEmptyException {
        return elements[top];
    }
}
