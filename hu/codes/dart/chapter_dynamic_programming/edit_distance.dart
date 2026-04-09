/**
 * File: edit_distance.dart
 * Created Time: 2023-08-11
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

import 'dart:math';

/* Szerkesztési távolság: Nyers erő keresés */
int editDistanceDFS(String s, String t, int i, int j) {
  // Ha mindkét s és t üres, adjon vissza 0-t
  if (i == 0 && j == 0) return 0;
  // Ha s üres, adja vissza t hosszát
  if (i == 0) return j;
  // Ha t üres, adja vissza s hosszát
  if (j == 0) return i;
  // Ha két karakter egyenlő, ugorja át mindkét karaktert
  if (s[i - 1] == t[j - 1]) return editDistanceDFS(s, t, i - 1, j - 1);
  // Minimális szerkesztési lépések = minimális szerkesztési lépések (beszúrás, törlés, csere) + 1
  int insert = editDistanceDFS(s, t, i, j - 1);
  int delete = editDistanceDFS(s, t, i - 1, j);
  int replace = editDistanceDFS(s, t, i - 1, j - 1);
  // Minimális szerkesztési lépések visszaadása
  return min(min(insert, delete), replace) + 1;
}

/* Szerkesztési távolság: Memoizált keresés */
int editDistanceDFSMem(String s, String t, List<List<int>> mem, int i, int j) {
  // Ha mindkét s és t üres, adjon vissza 0-t
  if (i == 0 && j == 0) return 0;
  // Ha s üres, adja vissza t hosszát
  if (i == 0) return j;
  // Ha t üres, adja vissza s hosszát
  if (j == 0) return i;
  // Ha van bejegyzés, közvetlenül adja vissza
  if (mem[i][j] != -1) return mem[i][j];
  // Ha két karakter egyenlő, ugorja át mindkét karaktert
  if (s[i - 1] == t[j - 1]) return editDistanceDFSMem(s, t, mem, i - 1, j - 1);
  // Minimális szerkesztési lépések = minimális szerkesztési lépések (beszúrás, törlés, csere) + 1
  int insert = editDistanceDFSMem(s, t, mem, i, j - 1);
  int delete = editDistanceDFSMem(s, t, mem, i - 1, j);
  int replace = editDistanceDFSMem(s, t, mem, i - 1, j - 1);
  // Minimális szerkesztési lépések rögzítése és visszaadása
  mem[i][j] = min(min(insert, delete), replace) + 1;
  return mem[i][j];
}

/* Szerkesztési távolság: Dinamikus programozás */
int editDistanceDP(String s, String t) {
  int n = s.length, m = t.length;
  List<List<int>> dp = List.generate(n + 1, (_) => List.filled(m + 1, 0));
  // Állapotátmenet: első sor és első oszlop
  for (int i = 1; i <= n; i++) {
    dp[i][0] = i;
  }
  for (int j = 1; j <= m; j++) {
    dp[0][j] = j;
  }
  // Állapotátmenet: többi sor és oszlop
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1]) {
        // Ha két karakter egyenlő, ugorja át mindkét karaktert
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        // Minimális szerkesztési lépések = minimális szerkesztési lépések (beszúrás, törlés, csere) + 1
        dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
      }
    }
  }
  return dp[n][m];
}

/* Szerkesztési távolság: Tárhelyoptimalizált dinamikus programozás */
int editDistanceDPComp(String s, String t) {
  int n = s.length, m = t.length;
  List<int> dp = List.filled(m + 1, 0);
  // Állapotátmenet: első sor
  for (int j = 1; j <= m; j++) {
    dp[j] = j;
  }
  // Állapotátmenet: többi sor
  for (int i = 1; i <= n; i++) {
    // Állapotátmenet: első oszlop
    int leftup = dp[0]; // Ideiglenesen tárolja dp[i-1, j-1] értékét
    dp[0] = i;
    // Állapotátmenet: többi oszlop
    for (int j = 1; j <= m; j++) {
      int temp = dp[j];
      if (s[i - 1] == t[j - 1]) {
        // Ha két karakter egyenlő, ugorja át mindkét karaktert
        dp[j] = leftup;
      } else {
        // Minimális szerkesztési lépések = minimális szerkesztési lépések (beszúrás, törlés, csere) + 1
        dp[j] = min(min(dp[j - 1], dp[j]), leftup) + 1;
      }
      leftup = temp; // Frissítés a következő körre: dp[i-1, j-1]
    }
  }
  return dp[m];
}

/* Főprogram */
void main() {
  String s = "bag";
  String t = "pack";
  int n = s.length, m = t.length;

  // Nyers erő keresés
  int res = editDistanceDFS(s, t, n, m);
  print("Changing " + s + " to " + t + " requires minimum $res edits");

  // Memoizált keresés
  List<List<int>> mem = List.generate(n + 1, (_) => List.filled(m + 1, -1));
  res = editDistanceDFSMem(s, t, mem, n, m);
  print("Changing " + s + " to " + t + " requires minimum $res edits");

  // Dinamikus programozás
  res = editDistanceDP(s, t);
  print("Changing " + s + " to " + t + " requires minimum $res edits");

  // Tárhelyoptimalizált dinamikus programozás
  res = editDistanceDPComp(s, t);
  print("Changing " + s + " to " + t + " requires minimum $res edits");
}
