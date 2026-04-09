/**
 * File: build_tree.dart
 * Created Time: 2023-08-10
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

import '../utils/print_util.dart';
import '../utils/tree_node.dart';

/* Bináris fa felépítése: oszd meg és uralkodj */
TreeNode? dfs(
  List<int> preorder,
  Map<int, int> inorderMap,
  int i,
  int l,
  int r,
) {
  // Leáll, ha a részfa intervalluma üres
  if (r - l < 0) {
    return null;
  }
  // Gyökércsomópont inicializálása
  TreeNode? root = TreeNode(preorder[i]);
  // m lekérdezése a bal és jobb részfák elválasztásához
  int m = inorderMap[preorder[i]]!;
  // Részfeladat: bal részfa felépítése
  root.left = dfs(preorder, inorderMap, i + 1, l, m - 1);
  // Részfeladat: jobb részfa felépítése
  root.right = dfs(preorder, inorderMap, i + 1 + m - l, m + 1, r);
  // Gyökércsomópont visszaadása
  return root;
}

/* Bináris fa felépítése */
TreeNode? buildTree(List<int> preorder, List<int> inorder) {
  // Hash tábla inicializálása, az inorder elemek indexre való leképezésének tárolásához
  Map<int, int> inorderMap = {};
  for (int i = 0; i < inorder.length; i++) {
    inorderMap[inorder[i]] = i;
  }
  TreeNode? root = dfs(preorder, inorderMap, 0, 0, inorder.length - 1);
  return root;
}

/* Főprogram */
void main() {
  List<int> preorder = [3, 9, 2, 1, 7];
  List<int> inorder = [9, 3, 1, 2, 7];
  print("Pre-order traversal = $preorder");
  print("In-order traversal = $inorder");

  TreeNode? root = buildTree(preorder, inorder);
  print("The constructed binary tree is:");
  printTree(root!);
}
