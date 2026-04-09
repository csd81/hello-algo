/**
 * File: binary_tree_dfs.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_tree;

import utils.*;
import java.util.*;

public class binary_tree_dfs {
    // Lista inicializálása a bejárási sorrend tárolásához
    static ArrayList<Integer> list = new ArrayList<>();

    /* Előrendű bejárás */
    static void preOrder(TreeNode root) {
        if (root == null)
            return;
        // Látogatási prioritás: gyökércsomópont -> bal részfa -> jobb részfa
        list.add(root.val);
        preOrder(root.left);
        preOrder(root.right);
    }

    /* Középrendű bejárás */
    static void inOrder(TreeNode root) {
        if (root == null)
            return;
        // Látogatási prioritás: bal részfa -> gyökércsomópont -> jobb részfa
        inOrder(root.left);
        list.add(root.val);
        inOrder(root.right);
    }

    /* Utórendű bejárás */
    static void postOrder(TreeNode root) {
        if (root == null)
            return;
        // Látogatási prioritás: bal részfa -> jobb részfa -> gyökércsomópont
        postOrder(root.left);
        postOrder(root.right);
        list.add(root.val);
    }

    public static void main(String[] args) {
        /* Bináris fa inicializálása */
        // Egy függvényt használunk a bináris fa közvetlen tömbből való létrehozásához
        TreeNode root = TreeNode.listToTree(Arrays.asList(1, 2, 3, 4, 5, 6, 7));
        System.out.println("\nInitialize binary tree\n");
        PrintUtil.printTree(root);

        /* Előrendű bejárás */
        list.clear();
        preOrder(root);
        System.out.println("\nPreorder traversal node print sequence = " + list);

        /* Középrendű bejárás */
        list.clear();
        inOrder(root);
        System.out.println("\nInorder traversal node print sequence = " + list);

        /* Utórendű bejárás */
        list.clear();
        postOrder(root);
        System.out.println("\nPostorder traversal node print sequence = " + list);
    }
}
