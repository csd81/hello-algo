/**
 * File: array.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_array_and_linkedlist;

import java.util.*;
import java.util.concurrent.ThreadLocalRandom;

public class array {
    /* Véletlenszerű hozzáférés elemhez */
    static int randomAccess(int[] nums) {
        // Véletlenszerűen kiválaszt egy számot a [0, nums.length) intervallumból
        int randomIndex = ThreadLocalRandom.current().nextInt(0, nums.length);
        // Lekéri és visszaadja a véletlen elemet
        int randomNum = nums[randomIndex];
        return randomNum;
    }

    /* Tömb hosszának bővítése */
    static int[] extend(int[] nums, int enlarge) {
        // Inicializál egy bővített hosszú tömböt
        int[] res = new int[nums.length + enlarge];
        // Az eredeti tömb összes elemét átmásolja az új tömbbe
        for (int i = 0; i < nums.length; i++) {
            res[i] = nums[i];
        }
        // Visszaadja a bővített új tömböt
        return res;
    }

    /* num elem beszúrása az index pozícióba */
    static void insert(int[] nums, int num, int index) {
        // Az index pozíciótól kezdve minden elemet eggyel hátrébb lép
        for (int i = nums.length - 1; i > index; i--) {
            nums[i] = nums[i - 1];
        }
        // num-ot az index pozícióba rendeli
        nums[index] = num;
    }

    /* Az index pozícióban lévő elem törlése */
    static void remove(int[] nums, int index) {
        // Az index utáni összes elemet eggyel előrébb lép
        for (int i = index; i < nums.length - 1; i++) {
            nums[i] = nums[i + 1];
        }
    }

    /* Tömb bejárása */
    static void traverse(int[] nums) {
        int count = 0;
        // Tömb bejárása index szerint
        for (int i = 0; i < nums.length; i++) {
            count += nums[i];
        }
        // Tömb elemeinek közvetlen bejárása
        for (int num : nums) {
            count += num;
        }
    }

    /* A megadott elem megkeresése a tömbben */
    static int find(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }

    /* Főprogram */
    public static void main(String[] args) {
        /* Tömb inicializálása */
        int[] arr = new int[5];
        System.out.println("Array arr = " + Arrays.toString(arr));
        int[] nums = { 1, 3, 2, 5, 4 };
        System.out.println("Array nums = " + Arrays.toString(nums));

        /* Elem beszúrása */
        int randomNum = randomAccess(nums);
        System.out.println("Get random element in nums " + randomNum);

        /* Tömb bejárása */
        nums = extend(nums, 3);
        System.out.println("Extend array length to 8, resulting in nums = " + Arrays.toString(nums));

        /* Elem beszúrása */
        insert(nums, 6, 3);
        System.out.println("Insert number 6 at index 3, resulting in nums = " + Arrays.toString(nums));

        /* Elem törlése */
        remove(nums, 2);
        System.out.println("Remove element at index 2, resulting in nums = " + Arrays.toString(nums));

        /* Tömb bejárása */
        traverse(nums);

        /* Elem keresése */
        int index = find(nums, 3);
        System.out.println("Find element 3 in nums, get index = " + index);
    }
}
