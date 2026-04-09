/**
 * File: worst_best_time_complexity.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_computational_complexity;

import java.util.*;

public class worst_best_time_complexity {
    /* Tömb generálása { 1, 2, ..., n } elemekkel, véletlenszerű sorrendben */
    static int[] randomNumbers(int n) {
        Integer[] nums = new Integer[n];
        // nums = { 1, 2, 3, ..., n } tömb generálása
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        // Tömbelemek véletlenszerű összekeverése
        Collections.shuffle(Arrays.asList(nums));
        // Integer[] -> int[]
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = nums[i];
        }
        return res;
    }

    /* Az 1-es szám indexének megkeresése a nums tömbben */
    static int findOne(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            // Ha az 1-es elem a tömb elején van, legjobb eset időbonyolultsága O(1)
            // Ha az 1-es elem a tömb végén van, legrosszabb eset időbonyolultsága O(n)
            if (nums[i] == 1)
                return i;
        }
        return -1;
    }

    /* Főprogram */
    public static void main(String[] args) {
        for (int i = 0; i < 10; i++) {
            int n = 100;
            int[] nums = randomNumbers(n);
            int index = findOne(nums);
            System.out.println("\nArray [ 1, 2, ..., n ] after shuffling = " + Arrays.toString(nums));
            System.out.println("Index of number 1 is " + index);
        }
    }
}
