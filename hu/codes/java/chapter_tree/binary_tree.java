/**
 * File: binary_tree.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_tree;

import utils.*;

public class binary_tree {
    public static void main(String[] args) {
        /* Bináris fa inicializálása */
        // Csomópontok inicializálása
        TreeNode n1 = new TreeNode(1);
        TreeNode n2 = new TreeNode(2);
        TreeNode n3 = new TreeNode(3);
        TreeNode n4 = new TreeNode(4);
        TreeNode n5 = new TreeNode(5);
        // Hivatkozások (mutatók) felépítése a csomópontok között
        n1.left = n2;
        n1.right = n3;
        n2.left = n4;
        n2.right = n5;
        System.out.println("\nInitialize binary tree\n");
        PrintUtil.printTree(n1);

        /* P csomópont beszúrása n1 -> n2 közé */
        TreeNode P = new TreeNode(0);
        // Csomópont törlése
        n1.left = P;
        P.left = n2;
        System.out.println("\nAfter inserting node P\n");
        PrintUtil.printTree(n1);
        // P csomópont eltávolítása
        n1.left = n2;
        System.out.println("\nAfter removing node P\n");
        PrintUtil.printTree(n1);
    }
}
