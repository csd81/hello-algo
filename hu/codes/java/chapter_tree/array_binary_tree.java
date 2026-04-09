/**
 * File: array_binary_tree.java
 * Created Time: 2023-07-19
 * Author: krahets (krahets@163.com)
 */

package chapter_tree;

import utils.*;
import java.util.*;

/* Tömbbel ábrázolt bináris fa osztály */
class ArrayBinaryTree {
    private List<Integer> tree;

    /* Konstruktor */
    public ArrayBinaryTree(List<Integer> arr) {
        tree = new ArrayList<>(arr);
    }

    /* Lista kapacitása */
    public int size() {
        return tree.size();
    }

    /* Az i indexű csomópont értékének lekérése */
    public Integer val(int i) {
        // Ha az index határon kívül van, null-t ad vissza az üres pozíció jelzéséhez
        if (i < 0 || i >= size())
            return null;
        return tree.get(i);
    }

    /* Az i indexű csomópont bal gyermekének indexe */
    public Integer left(int i) {
        return 2 * i + 1;
    }

    /* Az i indexű csomópont jobb gyermekének indexe */
    public Integer right(int i) {
        return 2 * i + 2;
    }

    /* Az i indexű csomópont szülőjének indexe */
    public Integer parent(int i) {
        return (i - 1) / 2;
    }

    /* Szintenkénti bejárás */
    public List<Integer> levelOrder() {
        List<Integer> res = new ArrayList<>();
        // Tömb közvetlen bejárása
        for (int i = 0; i < size(); i++) {
            if (val(i) != null)
                res.add(val(i));
        }
        return res;
    }

    /* Mélységi bejárás */
    private void dfs(Integer i, String order, List<Integer> res) {
        // Ha üres pozíció, visszatér
        if (val(i) == null)
            return;
        // Előrendű bejárás
        if ("pre".equals(order))
            res.add(val(i));
        dfs(left(i), order, res);
        // Középrendű bejárás
        if ("in".equals(order))
            res.add(val(i));
        dfs(right(i), order, res);
        // Utórendű bejárás
        if ("post".equals(order))
            res.add(val(i));
    }

    /* Előrendű bejárás */
    public List<Integer> preOrder() {
        List<Integer> res = new ArrayList<>();
        dfs(0, "pre", res);
        return res;
    }

    /* Középrendű bejárás */
    public List<Integer> inOrder() {
        List<Integer> res = new ArrayList<>();
        dfs(0, "in", res);
        return res;
    }

    /* Utórendű bejárás */
    public List<Integer> postOrder() {
        List<Integer> res = new ArrayList<>();
        dfs(0, "post", res);
        return res;
    }
}

public class array_binary_tree {
    public static void main(String[] args) {
        // Bináris fa inicializálása
        // Egy függvényt használunk a bináris fa közvetlen tömbből való létrehozásához
        List<Integer> arr = Arrays.asList(1, 2, 3, 4, null, 6, 7, 8, 9, null, null, 12, null, null, 15);

        TreeNode root = TreeNode.listToTree(arr);
        System.out.println("\nInitialize binary tree\n");
        System.out.println("Array representation of binary tree:");
        System.out.println(arr);
        System.out.println("Linked list representation of binary tree:");
        PrintUtil.printTree(root);

        // Tömbbel ábrázolt bináris fa osztály
        ArrayBinaryTree abt = new ArrayBinaryTree(arr);

        // Csomópont elérése
        int i = 1;
        Integer l = abt.left(i);
        Integer r = abt.right(i);
        Integer p = abt.parent(i);
        System.out.println("\nCurrent node index is " + i + ", value is " + abt.val(i));
        System.out.println("Its left child node index is " + l + ", value is " + (l == null ? "null" : abt.val(l)));
        System.out.println("Its right child node index is " + r + ", value is " + (r == null ? "null" : abt.val(r)));
        System.out.println("Its parent node index is " + p + ", value is " + (p == null ? "null" : abt.val(p)));

        // Fa bejárása
        List<Integer> res = abt.levelOrder();
        System.out.println("\nLevel-order traversal is:" + res);
        res = abt.preOrder();
        System.out.println("Preorder traversal is:" + res);
        res = abt.inOrder();
        System.out.println("Inorder traversal is:" + res);
        res = abt.postOrder();
        System.out.println("Postorder traversal is:" + res);
    }
}
