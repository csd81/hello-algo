/**
 * File: binary_search_tree.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_tree;

import utils.*;

/* Bináris keresőfa */
class BinarySearchTree {
    private TreeNode root;

    /* Konstruktor */
    public BinarySearchTree() {
        // Üres fa inicializálása
        root = null;
    }

    /* Bináris fa gyökércsomópontjának lekérése */
    public TreeNode getRoot() {
        return root;
    }

    /* Csomópont keresése */
    public TreeNode search(int num) {
        TreeNode cur = root;
        // Ciklikus keresés, levélcsomóponton túllépve kilép
        while (cur != null) {
            // A célcsomópont cur jobb részfájában van
            if (cur.val < num)
                cur = cur.right;
            // A célcsomópont cur bal részfájában van
            else if (cur.val > num)
                cur = cur.left;
            // Megtalálta a célcsomópontot, kilép a ciklusból
            else
                break;
        }
        // A célcsomópont visszaadása
        return cur;
    }

    /* Csomópont beszúrása */
    public void insert(int num) {
        // Ha a fa üres, inicializálja a gyökércsomópontot
        if (root == null) {
            root = new TreeNode(num);
            return;
        }
        TreeNode cur = root, pre = null;
        // Ciklikus keresés, levélcsomóponton túllépve kilép
        while (cur != null) {
            // Duplikált csomópontot talált, közvetlenül visszatér
            if (cur.val == num)
                return;
            pre = cur;
            // A beszúrási pozíció cur jobb részfájában van
            if (cur.val < num)
                cur = cur.right;
            // A beszúrási pozíció cur bal részfájában van
            else
                cur = cur.left;
        }
        // Csomópont beszúrása
        TreeNode node = new TreeNode(num);
        if (pre.val < num)
            pre.right = node;
        else
            pre.left = node;
    }

    /* Csomópont törlése */
    public void remove(int num) {
        // Ha a fa üres, közvetlenül visszatér
        if (root == null)
            return;
        TreeNode cur = root, pre = null;
        // Ciklikus keresés, levélcsomóponton túllépve kilép
        while (cur != null) {
            // Megtalálta a törlendő csomópontot, kilép a ciklusból
            if (cur.val == num)
                break;
            pre = cur;
            // A törlendő csomópont cur jobb részfájában van
            if (cur.val < num)
                cur = cur.right;
            // A törlendő csomópont cur bal részfájában van
            else
                cur = cur.left;
        }
        // Ha nem találta a törlendő csomópontot, közvetlenül visszatér
        if (cur == null)
            return;
        // Gyermekcsomópontok száma = 0 vagy 1
        if (cur.left == null || cur.right == null) {
            // Ha gyermekcsomópontok száma = 0 / 1, child = null / az adott gyermekcsomópont
            TreeNode child = cur.left != null ? cur.left : cur.right;
            // cur csomópont törlése
            if (cur != root) {
                if (pre.left == cur)
                    pre.left = child;
                else
                    pre.right = child;
            } else {
                // Ha a törölt csomópont a gyökércsomópont, újra hozzárendeli a gyökércsomópontot
                root = child;
            }
        }
        // Gyermekcsomópontok száma = 2
        else {
            // Lekéri cur következő csomópontját a középrendű bejárásban
            TreeNode tmp = cur.right;
            while (tmp.left != null) {
                tmp = tmp.left;
            }
            // Rekurzívan törli tmp csomópontot
            remove(tmp.val);
            // cur értékét tmp-vel helyettesíti
            cur.val = tmp.val;
        }
    }
}

public class binary_search_tree {
    public static void main(String[] args) {
        /* Bináris keresőfa inicializálása */
        BinarySearchTree bst = new BinarySearchTree();
        // Megjegyezzük, hogy a különböző beszúrási sorrendek különböző bináris fákat generálnak, ez a sorrend tökéletes bináris fát hoz létre
        int[] nums = { 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 };
        for (int num : nums) {
            bst.insert(num);
        }
        System.out.println("\nInitialized binary tree is\n");
        PrintUtil.printTree(bst.getRoot());

        /* Csomópont keresése */
        TreeNode node = bst.search(7);
        System.out.println("\nFound node object is " + node + ", node value = " + node.val);

        /* Csomópont beszúrása */
        bst.insert(16);
        System.out.println("\nAfter inserting node 16, binary tree is\n");
        PrintUtil.printTree(bst.getRoot());

        /* Csomópont törlése */
        bst.remove(1);
        System.out.println("\nAfter removing node 1, binary tree is\n");
        PrintUtil.printTree(bst.getRoot());
        bst.remove(2);
        System.out.println("\nAfter removing node 2, binary tree is\n");
        PrintUtil.printTree(bst.getRoot());
        bst.remove(4);
        System.out.println("\nAfter removing node 4, binary tree is\n");
        PrintUtil.printTree(bst.getRoot());
    }
}
