/**
 * File: subset_sum_i.dart
 * Created Time: 2023-08-10
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

/* Visszalépéses algoritmus: Részhalmazösszeg I */
void backtrack(
  List<int> state,
  int target,
  List<int> choices,
  int start,
  List<List<int>> res,
) {
  // Ha a részhalmaz összege egyenlő a céllal, rögzítsd a megoldást
  if (target == 0) {
    res.add(List.from(state));
    return;
  }
  // Összes választási lehetőség bejárása
  // Metszés 2: start-tól kezdve bejárva elkerüljük az ismétlődő részhalmazok generálását
  for (int i = start; i < choices.length; i++) {
    // Metszés 1: ha a részhalmaz összege meghaladja a célt, közvetlenül szakítsd meg a ciklust
    // Mivel a tömb rendezett, a későbbi elemek nagyobbak, így a részhalmaz összege biztosan meghaladja a célt
    if (target - choices[i] < 0) {
      break;
    }
    // Kísérlet: válassz, frissítsd a célt és a start értéket
    state.add(choices[i]);
    // Lépj a következő kiválasztási körre
    backtrack(state, target - choices[i], choices, i, res);
    // Visszalépés: vonja vissza a választást, állítsa vissza az előző állapotot
    state.removeLast();
  }
}

/* Részhalmazösszeg I megoldása */
List<List<int>> subsetSumI(List<int> nums, int target) {
  List<int> state = []; // Állapot (részhalmaz)
  nums.sort(); // nums rendezése
  int start = 0; // Bejárás kezdőpontja
  List<List<int>> res = []; // Eredménylista (részhalmazok listája)
  backtrack(state, target, nums, start, res);
  return res;
}

/* Főprogram */
void main() {
  List<int> nums = [3, 4, 5];
  int target = 9;

  List<List<int>> res = subsetSumI(nums, target);

  print("Input array nums = $nums, target = $target");
  print("All subsets with sum equal to $target res = $res");
}
