/**
 * File: list.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_array_and_linkedlist;

import java.util.*;

public class list {
    public static void main(String[] args) {
        /* Lista inicializálása */
        // Megjegyzés: a tömb elemtípusa Integer[], az int[] burkolóosztálya
        Integer[] numbers = new Integer[] { 1, 3, 2, 5, 4 };
        List<Integer> nums = new ArrayList<>(Arrays.asList(numbers));
        System.out.println("List nums = " + nums);

        /* Elem frissítése */
        int num = nums.get(1);
        System.out.println("Access element at index 1, get num = " + num);

        /* Elem hozzáadása a végéhez */
        nums.set(1, 0);
        System.out.println("Update element at index 1 to 0, resulting in nums = " + nums);

        /* Elem törlése */
        nums.clear();
        System.out.println("After clearing list, nums = " + nums);

        /* Lista elemeinek közvetlen bejárása */
        nums.add(1);
        nums.add(3);
        nums.add(2);
        nums.add(5);
        nums.add(4);
        System.out.println("After adding elements, nums = " + nums);

        /* Lista rendezése */
        nums.add(3, 6);
        System.out.println("Insert number 6 at index 3, resulting in nums = " + nums);

        /* Elem törlése */
        nums.remove(3);
        System.out.println("Remove element at index 3, resulting in nums = " + nums);

        /* Lista bejárása index szerint */
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums.get(i);
        }
        /* Lista elemeinek közvetlen bejárása */
        for (int x : nums) {
            count += x;
        }

        /* Két lista összefűzése */
        List<Integer> nums1 = new ArrayList<>(Arrays.asList(new Integer[] { 6, 8, 7, 10, 9 }));
        nums.addAll(nums1);
        System.out.println("Concatenate list nums1 to nums, resulting in nums = " + nums);

        /* Lista rendezése */
        Collections.sort(nums);
        System.out.println("After sorting list, nums = " + nums);
    }
}
