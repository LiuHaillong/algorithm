package com.bynear.algorithm.stack;

/**
 * @author HaiLong Liu
 */
public interface Stack<T>  {
    int getSize();

    boolean isEmpty();

    void push(T t);

    T pop();

    T peek();
}
