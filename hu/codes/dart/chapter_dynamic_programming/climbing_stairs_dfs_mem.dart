/**
 * File: climbing_stairs_dfs_mem.dart
 * Created Time: 2023-08-11
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

/* Memoizált keresés */
int dfs(int i, List<int> mem) {
  // Ismert dp[1] és dp[2], adja vissza azokat
  if (i == 1 || i == 2) return i;
  // Ha dp[i] bejegyzés létezik, közvetlenül adja vissza
  if (mem[i] != -1) return mem[i];
  // dp[i] = dp[i-1] + dp[i-2]
  int count = dfs(i - 1, mem) + dfs(i - 2, mem);
  // dp[i] rögzítése
  mem[i] = count;
  return count;
}

/* Lépcsőmászás: Memoizált keresés */
int climbingStairsDFSMem(int n) {
  // mem[i] az i-ik lépcsőre való feljutás összes megoldásának számát tárolja, -1 azt jelenti, hogy nincs bejegyzés
  List<int> mem = List.filled(n + 1, -1);
  return dfs(n, mem);
}

/* Főprogram */
void main() {
  int n = 9;

  int res = climbingStairsDFSMem(n);
  print("Climbing $n stairs has $res solutions");
}
