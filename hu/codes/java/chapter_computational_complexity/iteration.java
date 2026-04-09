/**
 * File: iteration.java
 * Created Time: 2023-08-24
 * Author: krahets (krahets@163.com)
 */

package chapter_computational_complexity;

public class iteration {
    /* for ciklus */
    static int forLoop(int n) {
        int res = 0;
        // 1, 2, ..., n-1, n összegzése
        for (int i = 1; i <= n; i++) {
            res += i;
        }
        return res;
    }

    /* while ciklus */
    static int whileLoop(int n) {
        int res = 0;
        int i = 1; // Feltételváltozó inicializálása
        // 1, 2, ..., n-1, n összegzése
        while (i <= n) {
            res += i;
            i++; // Feltételváltozó frissítése
        }
        return res;
    }

    /* while ciklus (két frissítéssel) */
    static int whileLoopII(int n) {
        int res = 0;
        int i = 1; // Feltételváltozó inicializálása
        // 1, 4, 10, ... összegzése
        while (i <= n) {
            res += i;
            // Feltételváltozó frissítése
            i++;
            i *= 2;
        }
        return res;
    }

    /* Egymásba ágyazott for ciklus */
    static String nestedForLoop(int n) {
        StringBuilder res = new StringBuilder();
        // i = 1, 2, ..., n-1, n ciklus
        for (int i = 1; i <= n; i++) {
            // j = 1, 2, ..., n-1, n ciklus
            for (int j = 1; j <= n; j++) {
                res.append("(" + i + ", " + j + "), ");
            }
        }
        return res.toString();
    }

    /* Főprogram */
    public static void main(String[] args) {
        int n = 5;
        int res;

        res = forLoop(n);
        System.out.println("\nfor loop sum result res = " + res);

        res = whileLoop(n);
        System.out.println("\nwhile loop sum result res = " + res);

        res = whileLoopII(n);
        System.out.println("\nwhile loop (two updates) sum result res = " + res);

        String resStr = nestedForLoop(n);
        System.out.println("\nDouble for loop traversal result " + resStr);
    }
}
