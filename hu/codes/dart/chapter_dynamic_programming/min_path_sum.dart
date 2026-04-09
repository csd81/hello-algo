/**
 * File: min_path_sum.dart
 * Created Time: 2023-08-11
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

import 'dart:math';

/* Minimális útvonalösszeg: Nyers erő keresés */
int minPathSumDFS(List<List<int>> grid, int i, int j) {
  // Ha a bal felső sarokba érünk, fejezzük be a keresést
  if (i == 0 && j == 0) {
    return grid[0][0];
  }
  // Ha a sor- vagy oszlopindex túlmutat a határon, adjon vissza +∞ költséget
  if (i < 0 || j < 0) {
    // Dartban az int típus rögzített tartományú egész szám, nincs "végtelen" értéket képviselő érték
    return BigInt.from(2).pow(31).toInt();
  }
  // Számítsa ki a minimális útvonalköltséget bal-felülről (i-1, j)-be és (i, j-1)-be
  int up = minPathSumDFS(grid, i - 1, j);
  int left = minPathSumDFS(grid, i, j - 1);
  // A minimális útvonalköltség visszaadása bal-felülről (i, j)-be
  return min(left, up) + grid[i][j];
}

/* Minimális útvonalösszeg: Memoizált keresés */
int minPathSumDFSMem(List<List<int>> grid, List<List<int>> mem, int i, int j) {
  // Ha a bal felső sarokba érünk, fejezzük be a keresést
  if (i == 0 && j == 0) {
    return grid[0][0];
  }
  // Ha a sor- vagy oszlopindex túlmutat a határon, adjon vissza +∞ költséget
  if (i < 0 || j < 0) {
    // Dartban az int típus rögzített tartományú egész szám, nincs "végtelen" értéket képviselő érték
    return BigInt.from(2).pow(31).toInt();
  }
  // Ha van bejegyzés, közvetlenül adja vissza
  if (mem[i][j] != -1) {
    return mem[i][j];
  }
  // Bal és felső cella minimális útvonalköltsége
  int up = minPathSumDFSMem(grid, mem, i - 1, j);
  int left = minPathSumDFSMem(grid, mem, i, j - 1);
  // A minimális útvonalköltség rögzítése és visszaadása bal-felülről (i, j)-be
  mem[i][j] = min(left, up) + grid[i][j];
  return mem[i][j];
}

/* Minimális útvonalösszeg: Dinamikus programozás */
int minPathSumDP(List<List<int>> grid) {
  int n = grid.length, m = grid[0].length;
  // dp tábla inicializálása
  List<List<int>> dp = List.generate(n, (i) => List.filled(m, 0));
  dp[0][0] = grid[0][0];
  // Állapotátmenet: első sor
  for (int j = 1; j < m; j++) {
    dp[0][j] = dp[0][j - 1] + grid[0][j];
  }
  // Állapotátmenet: első oszlop
  for (int i = 1; i < n; i++) {
    dp[i][0] = dp[i - 1][0] + grid[i][0];
  }
  // Állapotátmenet: többi sor és oszlop
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
    }
  }
  return dp[n - 1][m - 1];
}

/* Minimális útvonalösszeg: Tárhelyoptimalizált dinamikus programozás */
int minPathSumDPComp(List<List<int>> grid) {
  int n = grid.length, m = grid[0].length;
  // dp tábla inicializálása
  List<int> dp = List.filled(m, 0);
  dp[0] = grid[0][0];
  for (int j = 1; j < m; j++) {
    dp[j] = dp[j - 1] + grid[0][j];
  }
  // Állapotátmenet: többi sor
  for (int i = 1; i < n; i++) {
    // Állapotátmenet: első oszlop
    dp[0] = dp[0] + grid[i][0];
    // Állapotátmenet: többi oszlop
    for (int j = 1; j < m; j++) {
      dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
    }
  }
  return dp[m - 1];
}

/* Főprogram */
void main() {
  List<List<int>> grid = [
    [1, 3, 1, 5],
    [2, 2, 4, 2],
    [5, 3, 2, 1],
    [4, 3, 5, 2],
  ];
  int n = grid.length, m = grid[0].length;

// Nyers erő keresés
  int res = minPathSumDFS(grid, n - 1, m - 1);
  print("Minimum path sum from top-left to bottom-right is $res");

// Memoizált keresés
  List<List<int>> mem = List.generate(n, (i) => List.filled(m, -1));
  res = minPathSumDFSMem(grid, mem, n - 1, m - 1);
  print("Minimum path sum from top-left to bottom-right is $res");

// Dinamikus programozás
  res = minPathSumDP(grid);
  print("Minimum path sum from top-left to bottom-right is $res");

// Tárhelyoptimalizált dinamikus programozás
  res = minPathSumDPComp(grid);
  print("Minimum path sum from top-left to bottom-right is $res");
}
