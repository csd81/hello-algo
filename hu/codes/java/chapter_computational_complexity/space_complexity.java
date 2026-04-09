/**
 * File: space_complexity.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_computational_complexity;

import utils.*;
import java.util.*;

public class space_complexity {
    /* Függvény */
    static int function() {
        // Néhány műveletet végez
        return 0;
    }

    /* Konstans rend */
    static void constant(int n) {
        // Konstansok, változók, objektumok O(1) tárhelyet foglalnak
        final int a = 0;
        int b = 0;
        int[] nums = new int[10000];
        ListNode node = new ListNode(0);
        // A cikluson belüli változók O(1) tárhelyet foglalnak
        for (int i = 0; i < n; i++) {
            int c = 0;
        }
        // A cikluson belüli függvények O(1) tárhelyet foglalnak
        for (int i = 0; i < n; i++) {
            function();
        }
    }

    /* Lineáris rend */
    static void linear(int n) {
        // n hosszúságú tömb O(n) tárhelyet használ
        int[] nums = new int[n];
        // n hosszúságú lista O(n) tárhelyet foglal
        List<ListNode> nodes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            nodes.add(new ListNode(i));
        }
        // n hosszúságú hash tábla O(n) tárhelyet foglal
        Map<Integer, String> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(i, String.valueOf(i));
        }
    }

    /* Lineáris rend (rekurzív implementáció) */
    static void linearRecur(int n) {
        System.out.println("Recursion n = " + n);
        if (n == 1)
            return;
        linearRecur(n - 1);
    }

    /* Exponenciális rend */
    static void quadratic(int n) {
        // Mátrix O(n^2) tárhelyet használ
        int[][] numMatrix = new int[n][n];
        // 2D lista O(n^2) tárhelyet használ
        List<List<Integer>> numList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            List<Integer> tmp = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                tmp.add(0);
            }
            numList.add(tmp);
        }
    }

    /* Négyzetes rend (rekurzív implementáció) */
    static int quadraticRecur(int n) {
        if (n <= 0)
            return 0;
        // A nums tömb hossza n, n-1, ..., 2, 1
        int[] nums = new int[n];
        System.out.println("In recursion n = " + n + ", nums length = " + nums.length);
        return quadraticRecur(n - 1);
    }

    /* Főprogram */
    static TreeNode buildTree(int n) {
        if (n == 0)
            return null;
        TreeNode root = new TreeNode(0);
        root.left = buildTree(n - 1);
        root.right = buildTree(n - 1);
        return root;
    }

    /* Főprogram */
    public static void main(String[] args) {
        int n = 5;
        // Konstans rend
        constant(n);
        // Lineáris rend
        linear(n);
        linearRecur(n);
        // Exponenciális rend
        quadratic(n);
        quadraticRecur(n);
        // Exponenciális rend
        TreeNode root = buildTree(n);
        PrintUtil.printTree(root);
    }
}
