/**
 * File: preorder_traversal_iii_template.dart
 * Created Time: 2023-08-10
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

import '../utils/print_util.dart';
import '../utils/tree_node.dart';

/* Ellenőrizd, hogy az aktuális állapot megoldás-e */
bool isSolution(List<TreeNode> state) {
  return state.isNotEmpty && state.last.val == 7;
}

/* Megoldás rögzítése */
void recordSolution(List<TreeNode> state, List<List<TreeNode>> res) {
  res.add(List.from(state));
}

/* Ellenőrizd, hogy a választás érvényes-e az aktuális állapotban */
bool isValid(List<TreeNode> state, TreeNode? choice) {
  return choice != null && choice.val != 3;
}

/* Állapot frissítése */
void makeChoice(List<TreeNode> state, TreeNode? choice) {
  state.add(choice!);
}

/* Állapot visszaállítása */
void undoChoice(List<TreeNode> state, TreeNode? choice) {
  state.removeLast();
}

/* Visszalépéses algoritmus: 3. példa */
void backtrack(
  List<TreeNode> state,
  List<TreeNode?> choices,
  List<List<TreeNode>> res,
) {
  // Ellenőrizd, hogy megoldás-e
  if (isSolution(state)) {
    // Megoldás rögzítése
    recordSolution(state, res);
  }
  // Összes választási lehetőség bejárása
  for (TreeNode? choice in choices) {
    // Metszés: ellenőrizd, hogy a választás érvényes-e
    if (isValid(state, choice)) {
      // Kísérlet: válassz, frissítsd az állapotot
      makeChoice(state, choice);
      // Lépj a következő kiválasztási körre
      backtrack(state, [choice!.left, choice.right], res);
      // Visszalépés: vonja vissza a választást, állítsa vissza az előző állapotot
      undoChoice(state, choice);
    }
  }
}

/* Főprogram */
void main() {
  TreeNode? root = listToTree([1, 7, 3, 4, 5, 6, 7]);
  print("\nInitialize binary tree");
  printTree(root);

  // Visszalépéses algoritmus
  List<List<TreeNode>> res = [];
  backtrack([], [root!], res);
  print("\nOutput all paths from root node to node 7, requiring paths do not include nodes with value 3");
  for (List<TreeNode> path in res) {
    print(List.from(path.map((e) => e.val)));
  }
}
