/**
 * File: binary_tree_bfs.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_tree;

import utils.*;
import java.util.*;

public class binary_tree_bfs {
    /* Szintenkénti bejárás */
    static List<Integer> levelOrder(TreeNode root) {
        // Sor inicializálása, gyökércsomópont hozzáadása
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        // Lista inicializálása a bejárási sorrend mentéséhez
        List<Integer> list = new ArrayList<>();
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll(); // Kivétel a sorból
            list.add(node.val);           // Csomópont értékének mentése
            if (node.left != null)
                queue.offer(node.left);   // Bal gyermekcsomópont sorba rakása
            if (node.right != null)
                queue.offer(node.right);  // Jobb gyermekcsomópont sorba rakása
        }
        return list;
    }

    public static void main(String[] args) {
        /* Bináris fa inicializálása */
        // Egy függvényt használunk a bináris fa közvetlen tömbből való létrehozásához
        TreeNode root = TreeNode.listToTree(Arrays.asList(1, 2, 3, 4, 5, 6, 7));
        System.out.println("\nInitialize binary tree\n");
        PrintUtil.printTree(root);

        /* Szintenkénti bejárás */
        List<Integer> list = levelOrder(root);
        System.out.println("\nLevel-order traversal node print sequence = " + list);
    }
}
