/**
 * File: preorder_traversal_ii_compact.dart
 * Created Time: 2023-08-10
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

import '../utils/print_util.dart';
import '../utils/tree_node.dart';

/* Előrendű bejárás: 2. példa */
void preOrder(
  TreeNode? root,
  List<TreeNode> path,
  List<List<TreeNode>> res,
) {
  if (root == null) {
    return;
  }

  // Kísérlet
  path.add(root);
  if (root.val == 7) {
    // Megoldás rögzítése
    res.add(List.from(path));
  }
  preOrder(root.left, path, res);
  preOrder(root.right, path, res);
  // Visszalépés
  path.removeLast();
}

/* Főprogram */
void main() {
  TreeNode? root = listToTree([1, 7, 3, 4, 5, 6, 7]);
  print("\nInitialize binary tree");
  printTree(root);

  // Előrendű bejárás
  List<TreeNode> path = [];
  List<List<TreeNode>> res = [];
  preOrder(root, path, res);

  print("\nOutput all paths from root node to node 7");
  for (List<TreeNode> vals in res) {
    print(List.generate(vals.length, (i) => vals[i].val));
  }
}
