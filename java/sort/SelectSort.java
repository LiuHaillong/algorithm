package com.bynear.algorithm.sort;

/**
 * @author HaiLong Liu
 */
public class SelectSort {
    private static int[] nums = new int[]{12, 23, 9, 24, 15, 3, 18};

    public static void main(String[] args) {
        selectSort(nums);
        print(nums);
    }

    public static void selectSort(int[] nums) {
        int len = nums.length;
        for(int i = 0; i < len -1; i++) {
            int min = i;
            for(int j = i + 1; j < len; j++) {
                if(nums[j] < nums[min]) {
                    min = j;
                }
            }
            if(i != min) {
                int tmpValue = nums[i];
                nums[i] = nums[min];
                nums[min] = tmpValue;
            }

        }
    }

    public static void print(int[] nums) {
        for (int num : nums) {
            System.out.println(num);
        }
    }
}
