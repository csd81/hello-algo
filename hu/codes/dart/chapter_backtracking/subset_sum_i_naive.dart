/**
 * File: subset_sum_i_naive.dart
 * Created Time: 2023-08-10
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

/* Visszalépéses algoritmus: Részhalmazösszeg I */
void backtrack(
  List<int> state,
  int target,
  int total,
  List<int> choices,
  List<List<int>> res,
) {
  // Ha a részhalmaz összege egyenlő a céllal, rögzítsd a megoldást
  if (total == target) {
    res.add(List.from(state));
    return;
  }
  // Összes választási lehetőség bejárása
  for (int i = 0; i < choices.length; i++) {
    // Metszés: ha a részhalmaz összege meghaladja a célt, hagyd ki ezt a választást
    if (total + choices[i] > target) {
      continue;
    }
    // Kísérlet: válassz, frissítsd az elemek total összegét
    state.add(choices[i]);
    // Lépj a következő kiválasztási körre
    backtrack(state, target, total + choices[i], choices, res);
    // Visszalépés: vonja vissza a választást, állítsa vissza az előző állapotot
    state.removeLast();
  }
}

/* Részhalmazösszeg I megoldása (ismétlődő részhalmazokat tartalmaz) */
List<List<int>> subsetSumINaive(List<int> nums, int target) {
  List<int> state = []; // Állapot (részhalmaz)
  int total = 0; // Elemek összege
  List<List<int>> res = []; // Eredménylista (részhalmazok listája)
  backtrack(state, target, total, nums, res);
  return res;
}

/* Főprogram */
void main() {
  List<int> nums = [3, 4, 5];
  int target = 9;

  List<List<int>> res = subsetSumINaive(nums, target);

  print("Input array nums = $nums, target = $target");
  print("All subsets with sum equal to $target res = $res");
  print("Please note that this method outputs results containing duplicate sets");
}
