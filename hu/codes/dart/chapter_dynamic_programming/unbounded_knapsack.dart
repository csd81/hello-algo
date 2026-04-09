/**
 * File: unbounded_knapsack.dart
 * Created Time: 2023-08-11
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

import 'dart:math';

/* Korlátlan hátizsák: Dinamikus programozás */
int unboundedKnapsackDP(List<int> wgt, List<int> val, int cap) {
  int n = wgt.length;
  // dp tábla inicializálása
  List<List<int>> dp = List.generate(n + 1, (index) => List.filled(cap + 1, 0));
  // Állapotátmenet
  for (int i = 1; i <= n; i++) {
    for (int c = 1; c <= cap; c++) {
      if (wgt[i - 1] > c) {
        // Ha meghaladja a hátizsák kapacitását, ne válaszd ki az i tárgyat
        dp[i][c] = dp[i - 1][c];
      } else {
        // A nagyobb érték: nem választja ki vagy kiválasztja az i tárgyat
        dp[i][c] = max(dp[i - 1][c], dp[i][c - wgt[i - 1]] + val[i - 1]);
      }
    }
  }
  return dp[n][cap];
}

/* Korlátlan hátizsák: Tárhelyoptimalizált dinamikus programozás */
int unboundedKnapsackDPComp(List<int> wgt, List<int> val, int cap) {
  int n = wgt.length;
  // dp tábla inicializálása
  List<int> dp = List.filled(cap + 1, 0);
  // Állapotátmenet
  for (int i = 1; i <= n; i++) {
    for (int c = 1; c <= cap; c++) {
      if (wgt[i - 1] > c) {
        // Ha meghaladja a hátizsák kapacitását, ne válaszd ki az i tárgyat
        dp[c] = dp[c];
      } else {
        // A nagyobb érték: nem választja ki vagy kiválasztja az i tárgyat
        dp[c] = max(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
      }
    }
  }
  return dp[cap];
}

/* Főprogram */
void main() {
  List<int> wgt = [1, 2, 3];
  List<int> val = [5, 11, 15];
  int cap = 4;

  // Dinamikus programozás
  int res = unboundedKnapsackDP(wgt, val, cap);
  print("Maximum item value not exceeding knapsack capacity is $res");

  // Tárhelyoptimalizált dinamikus programozás
  int resComp = unboundedKnapsackDPComp(wgt, val, cap);
  print("Maximum item value not exceeding knapsack capacity is $resComp");
}
