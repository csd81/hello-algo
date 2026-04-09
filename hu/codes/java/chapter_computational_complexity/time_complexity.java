/**
 * File: time_complexity.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_computational_complexity;

public class time_complexity {
    /* Konstans rend */
    static int constant(int n) {
        int count = 0;
        int size = 100000;
        for (int i = 0; i < size; i++)
            count++;
        return count;
    }

    /* Lineáris rend */
    static int linear(int n) {
        int count = 0;
        for (int i = 0; i < n; i++)
            count++;
        return count;
    }

    /* Lineáris rend (tömb bejárása) */
    static int arrayTraversal(int[] nums) {
        int count = 0;
        // Az iterációk száma arányos a tömb hosszával
        for (int num : nums) {
            count++;
        }
        return count;
    }

    /* Exponenciális rend */
    static int quadratic(int n) {
        int count = 0;
        // Az iterációk száma négyzetes összefüggésben van az n adatmérettel
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count++;
            }
        }
        return count;
    }

    /* Négyzetes rend (buborékrendezés) */
    static int bubbleSort(int[] nums) {
        int count = 0; // Számláló
        // Külső ciklus: a rendezetlen tartomány [0, i]
        for (int i = nums.length - 1; i > 0; i--) {
            // Belső ciklus: a rendezetlen [0, i] tartomány legnagyobb elemét a jobb végére csere
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[j + 1]) {
                    // nums[j] és nums[j + 1] felcserélése
                    int tmp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tmp;
                    count += 3; // Az elemcsere 3 egységműveletet tartalmaz
                }
            }
        }
        return count;
    }

    /* Exponenciális rend (ciklus implementáció) */
    static int exponential(int n) {
        int count = 0, base = 1;
        // A sejtek minden körben kettéosztódnak, így képezve az 1, 2, 4, 8, ..., 2^(n-1) sorozatot
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < base; j++) {
                count++;
            }
            base *= 2;
        }
        // count = 1 + 2 + 4 + 8 + .. + 2^(n-1) = 2^n - 1
        return count;
    }

    /* Exponenciális rend (rekurzív implementáció) */
    static int expRecur(int n) {
        if (n == 1)
            return 1;
        return expRecur(n - 1) + expRecur(n - 1) + 1;
    }

    /* Logaritmikus rend (ciklus implementáció) */
    static int logarithmic(int n) {
        int count = 0;
        while (n > 1) {
            n = n / 2;
            count++;
        }
        return count;
    }

    /* Logaritmikus rend (rekurzív implementáció) */
    static int logRecur(int n) {
        if (n <= 1)
            return 0;
        return logRecur(n / 2) + 1;
    }

    /* Lineáris logaritmikus rend */
    static int linearLogRecur(int n) {
        if (n <= 1)
            return 1;
        int count = linearLogRecur(n / 2) + linearLogRecur(n / 2);
        for (int i = 0; i < n; i++) {
            count++;
        }
        return count;
    }

    /* Faktoriális rend (rekurzív implementáció) */
    static int factorialRecur(int n) {
        if (n == 0)
            return 1;
        int count = 0;
        // 1-ről n-re osztódik szét
        for (int i = 0; i < n; i++) {
            count += factorialRecur(n - 1);
        }
        return count;
    }

    /* Főprogram */
    public static void main(String[] args) {
        // Módosíthatja n-t, hogy megfigyelhesse a különböző bonyolultságok műveleteinek számának trendjét
        int n = 8;
        System.out.println("Input data size n = " + n);

        int count = constant(n);
        System.out.println("Constant order operation count = " + count);

        count = linear(n);
        System.out.println("Linear order operation count = " + count);
        count = arrayTraversal(new int[n]);
        System.out.println("Linear order (array traversal) operation count = " + count);

        count = quadratic(n);
        System.out.println("Quadratic order operation count = " + count);
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = n - i; // [n,n-1,...,2,1]
        count = bubbleSort(nums);
        System.out.println("Quadratic order (bubble sort) operation count = " + count);

        count = exponential(n);
        System.out.println("Exponential order (loop implementation) operation count = " + count);
        count = expRecur(n);
        System.out.println("Exponential order (recursive implementation) operation count = " + count);

        count = logarithmic(n);
        System.out.println("Logarithmic order (loop implementation) operation count = " + count);
        count = logRecur(n);
        System.out.println("Logarithmic order (recursive implementation) operation count = " + count);

        count = linearLogRecur(n);
        System.out.println("Linearithmic order (recursive implementation) operation count = " + count);

        count = factorialRecur(n);
        System.out.println("Factorial order (recursive implementation) operation count = " + count);
    }
}
