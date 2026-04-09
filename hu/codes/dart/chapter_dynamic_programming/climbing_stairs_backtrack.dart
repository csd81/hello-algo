/**
 * File: climbing_stairs_backtrack.dart
 * Created Time: 2023-08-11
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

/* Visszalépés */
void backtrack(List<int> choices, int state, int n, List<int> res) {
  // Ha felért az n-ik lépcsőre, adjon hozzá 1-et a megoldások számához
  if (state == n) {
    res[0]++;
  }
  // Összes választási lehetőség bejárása
  for (int choice in choices) {
    // Metszés: nem szabad túllépni az n-ik lépcsőn
    if (state + choice > n) continue;
    // Kísérlet: válassz, frissítsd az állapotot
    backtrack(choices, state + choice, n, res);
    // Visszalépés
  }
}

/* Lépcsőmászás: Visszalépés */
int climbingStairsBacktrack(int n) {
  List<int> choices = [1, 2]; // Választhat 1 vagy 2 lépcsőt felmászani
  int state = 0; // A 0. lépcsőről kezd mászni
  List<int> res = [];
  res.add(0); // res[0] a megoldások számát tárolja
  backtrack(choices, state, n, res);
  return res[0];
}

/* Főprogram */
void main() {
  int n = 9;

  int res = climbingStairsBacktrack(n);
  print("Climbing $n stairs has $res solutions");
}
