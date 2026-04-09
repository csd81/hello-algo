/**
 * File: permutations_ii.dart
 * Created Time: 2023-08-10
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

/* Visszalépéses algoritmus: Permutációk II */
void backtrack(
  List<int> state,
  List<int> choices,
  List<bool> selected,
  List<List<int>> res,
) {
  // Ha az állapot hossza egyenlő az elemek számával, jegyezze fel a megoldást
  if (state.length == choices.length) {
    res.add(List.from(state));
    return;
  }
  // Összes választási lehetőség bejárása
  Set<int> duplicated = {};
  for (int i = 0; i < choices.length; i++) {
    int choice = choices[i];
    // Metszés: ne engedélyezd az elemek ismételt kiválasztását és az egyenlő értékű elemek ismételt kiválasztását
    if (!selected[i] && !duplicated.contains(choice)) {
      // Kísérlet: válaszd ki, frissítsd az állapotot
      duplicated.add(choice); // A kiválasztott elem értékének rögzítése
      selected[i] = true;
      state.add(choice);
      // Lépj a következő kiválasztási körre
      backtrack(state, choices, selected, res);
      // Visszalépés: vonja vissza a választást, állítsa vissza az előző állapotot
      selected[i] = false;
      state.removeLast();
    }
  }
}

/* Permutációk II */
List<List<int>> permutationsII(List<int> nums) {
  List<List<int>> res = [];
  backtrack([], nums, List.filled(nums.length, false), res);
  return res;
}

/* Főprogram */
void main() {
  List<int> nums = [1, 2, 2];

  List<List<int>> res = permutationsII(nums);

  print("Input array nums = $nums");
  print("All permutations res = $res");
}
