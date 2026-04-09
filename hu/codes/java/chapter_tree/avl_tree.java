/**
 * File: avl_tree.java
 * Created Time: 2022-12-10
 * Author: krahets (krahets@163.com)
 */

package chapter_tree;

import utils.*;

/* AVL fa */
class AVLTree {
    TreeNode root; // Gyökércsomópont

    /* Csomópont magasságának lekérése */
    public int height(TreeNode node) {
        // Üres csomópont magassága -1, levélcsomópont magassága 0
        return node == null ? -1 : node.height;
    }

    /* Csomópont magasságának frissítése */
    private void updateHeight(TreeNode node) {
        // A csomópont magassága a legmagasabb részfa magassága + 1
        node.height = Math.max(height(node.left), height(node.right)) + 1;
    }

    /* Egyensúlyi tényező lekérése */
    public int balanceFactor(TreeNode node) {
        // Üres csomópont egyensúlyi tényezője 0
        if (node == null)
            return 0;
        // Csomópont egyensúlyi tényezője = bal részfa magassága - jobb részfa magassága
        return height(node.left) - height(node.right);
    }

    /* Jobbra forgatás művelete */
    private TreeNode rightRotate(TreeNode node) {
        TreeNode child = node.left;
        TreeNode grandChild = child.right;
        // child-ot forgáspontként használva node-ot jobbra forgatja
        child.right = node;
        node.left = grandChild;
        // Csomópont magasságának frissítése
        updateHeight(node);
        updateHeight(child);
        // A forgatás utáni részfa gyökércsomópontjának visszaadása
        return child;
    }

    /* Balra forgatás művelete */
    private TreeNode leftRotate(TreeNode node) {
        TreeNode child = node.right;
        TreeNode grandChild = child.left;
        // child-ot forgáspontként használva node-ot balra forgatja
        child.left = node;
        node.right = grandChild;
        // Csomópont magasságának frissítése
        updateHeight(node);
        updateHeight(child);
        // A forgatás utáni részfa gyökércsomópontjának visszaadása
        return child;
    }

    /* Forgatás végrehajtása a részfa egyensúlyának visszaállításához */
    private TreeNode rotate(TreeNode node) {
        // A csomópont egyensúlyi tényezőjének lekérése
        int balanceFactor = balanceFactor(node);
        // Balra dőlt fa
        if (balanceFactor > 1) {
            if (balanceFactor(node.left) >= 0) {
                // Jobbra forgatás
                return rightRotate(node);
            } else {
                // Először balra, majd jobbra forgatás
                node.left = leftRotate(node.left);
                return rightRotate(node);
            }
        }
        // Jobbra dőlt fa
        if (balanceFactor < -1) {
            if (balanceFactor(node.right) <= 0) {
                // Balra forgatás
                return leftRotate(node);
            } else {
                // Először jobbra, majd balra forgatás
                node.right = rightRotate(node.right);
                return leftRotate(node);
            }
        }
        // Egyensúlyos fa, nincs szükség forgatásra, közvetlenül visszatér
        return node;
    }

    /* Csomópont beszúrása */
    public void insert(int val) {
        root = insertHelper(root, val);
    }

    /* Csomópont rekurzív beszúrása (segédmetódus) */
    private TreeNode insertHelper(TreeNode node, int val) {
        if (node == null)
            return new TreeNode(val);
        /* 1. Beszúrási pozíció keresése és csomópont beszúrása */
        if (val < node.val)
            node.left = insertHelper(node.left, val);
        else if (val > node.val)
            node.right = insertHelper(node.right, val);
        else
            return node; // Duplikált csomópont nem kerül be, közvetlenül visszatér
        updateHeight(node); // Csomópont magasságának frissítése
        /* 2. Forgatás végrehajtása a részfa egyensúlyának visszaállításához */
        node = rotate(node);
        // A részfa gyökércsomópontjának visszaadása
        return node;
    }

    /* Csomópont törlése */
    public void remove(int val) {
        root = removeHelper(root, val);
    }

    /* Csomópont rekurzív törlése (segédmetódus) */
    private TreeNode removeHelper(TreeNode node, int val) {
        if (node == null)
            return null;
        /* 1. Csomópont megkeresése és törlése */
        if (val < node.val)
            node.left = removeHelper(node.left, val);
        else if (val > node.val)
            node.right = removeHelper(node.right, val);
        else {
            if (node.left == null || node.right == null) {
                TreeNode child = node.left != null ? node.left : node.right;
                // Gyermekcsomópontok száma = 0, közvetlenül törli és visszatér
                if (child == null)
                    return null;
                // Gyermekcsomópontok száma = 1, közvetlenül törli
                else
                    node = child;
            } else {
                // Gyermekcsomópontok száma = 2, törli a következő csomópontot a középrendű bejárásban és az aktuális csomópontot azzal helyettesíti
                TreeNode temp = node.right;
                while (temp.left != null) {
                    temp = temp.left;
                }
                node.right = removeHelper(node.right, temp.val);
                node.val = temp.val;
            }
        }
        updateHeight(node); // Csomópont magasságának frissítése
        /* 2. Forgatás végrehajtása a részfa egyensúlyának visszaállításához */
        node = rotate(node);
        // A részfa gyökércsomópontjának visszaadása
        return node;
    }

    /* Csomópont keresése */
    public TreeNode search(int val) {
        TreeNode cur = root;
        // Ciklikus keresés, levélcsomóponton túllépve kilép
        while (cur != null) {
            // A célcsomópont cur jobb részfájában van
            if (cur.val < val)
                cur = cur.right;
            // A célcsomópont cur bal részfájában van
            else if (cur.val > val)
                cur = cur.left;
            // Megtalálta a célcsomópontot, kilép a ciklusból
            else
                break;
        }
        // A célcsomópont visszaadása
        return cur;
    }
}

public class avl_tree {
    static void testInsert(AVLTree tree, int val) {
        tree.insert(val);
        System.out.println("\nAfter inserting node " + val + ", AVL tree is");
        PrintUtil.printTree(tree.root);
    }

    static void testRemove(AVLTree tree, int val) {
        tree.remove(val);
        System.out.println("\nAfter removing node " + val + ", AVL tree is");
        PrintUtil.printTree(tree.root);
    }

    public static void main(String[] args) {
        /* Kérjük, figyelje meg, hogyan tartja fenn az AVL fa az egyensúlyt csomópontok beszúrása után */
        AVLTree avlTree = new AVLTree();

        /* Csomópont beszúrása */
        // Csomópontok törlése
        testInsert(avlTree, 1);
        testInsert(avlTree, 2);
        testInsert(avlTree, 3);
        testInsert(avlTree, 4);
        testInsert(avlTree, 5);
        testInsert(avlTree, 8);
        testInsert(avlTree, 7);
        testInsert(avlTree, 9);
        testInsert(avlTree, 10);
        testInsert(avlTree, 6);

        /* Kérjük, figyelje meg, hogyan tartja fenn az AVL fa az egyensúlyt csomópontok törlése után */
        testInsert(avlTree, 7);

        /* Csomópont törlése */
        // 1 fokú csomópont törlése
        testRemove(avlTree, 8); // 2 fokú csomópont törlése
        testRemove(avlTree, 5); // 1 fokú csomópont törlése
        testRemove(avlTree, 4); // 2 fokú csomópont törlése

        /* Csomópont keresése */
        TreeNode node = avlTree.search(7);
        System.out.println("\nFound node object is " + node + ", node value = " + node.val);
    }
}
