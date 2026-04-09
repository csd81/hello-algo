/**
 * File: permutations_i.dart
 * Created Time: 2023-08-10
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

/* Visszalépéses algoritmus: Permutációk I */
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
  for (int i = 0; i < choices.length; i++) {
    int choice = choices[i];
    // Metszés: ne engedélyezd az elemek ismételt kiválasztását
    if (!selected[i]) {
      // Kísérlet: válaszd ki, frissítsd az állapotot
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

/* Permutációk I */
List<List<int>> permutationsI(List<int> nums) {
  List<List<int>> res = [];
  backtrack([], nums, List.filled(nums.length, false), res);
  return res;
}

/* Főprogram */
void main() {
  List<int> nums = [1, 2, 3];

  List<List<int>> res = permutationsI(nums);

  print("Input array nums = $nums");
  print("All permutations res = $res");
}
