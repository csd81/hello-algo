/**
 * File: knapsack.dart
 * Created Time: 2023-08-11
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

import 'dart:math';

/* 0-1 hátizsák: Nyers erő keresés */
int knapsackDFS(List<int> wgt, List<int> val, int i, int c) {
  // Ha az összes tárgy ki lett választva, vagy a hátizsák teli van, adjon vissza 0-t
  if (i == 0 || c == 0) {
    return 0;
  }
  // Ha meghaladja a hátizsák kapacitását, csak a "nem beletenni" opció választható
  if (wgt[i - 1] > c) {
    return knapsackDFS(wgt, val, i - 1, c);
  }
  // Számítsd ki az i tárgy berakásának és ki nem rakásának maximális értékét
  int no = knapsackDFS(wgt, val, i - 1, c);
  int yes = knapsackDFS(wgt, val, i - 1, c - wgt[i - 1]) + val[i - 1];
  // A két lehetőség nagyobb értékének visszaadása
  return max(no, yes);
}

/* 0-1 hátizsák: Memoizált keresés */
int knapsackDFSMem(
  List<int> wgt,
  List<int> val,
  List<List<int>> mem,
  int i,
  int c,
) {
  // Ha az összes tárgy ki lett választva, vagy a hátizsák teli van, adjon vissza 0-t
  if (i == 0 || c == 0) {
    return 0;
  }
  // Ha van bejegyzés, közvetlenül adja vissza
  if (mem[i][c] != -1) {
    return mem[i][c];
  }
  // Ha meghaladja a hátizsák kapacitását, csak a "nem beletenni" opció választható
  if (wgt[i - 1] > c) {
    return knapsackDFSMem(wgt, val, mem, i - 1, c);
  }
  // Számítsd ki az i tárgy berakásának és ki nem rakásának maximális értékét
  int no = knapsackDFSMem(wgt, val, mem, i - 1, c);
  int yes = knapsackDFSMem(wgt, val, mem, i - 1, c - wgt[i - 1]) + val[i - 1];
  // A két lehetőség nagyobb értékének rögzítése és visszaadása
  mem[i][c] = max(no, yes);
  return mem[i][c];
}

/* 0-1 hátizsák: Dinamikus programozás */
int knapsackDP(List<int> wgt, List<int> val, int cap) {
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
        dp[i][c] = max(dp[i - 1][c], dp[i - 1][c - wgt[i - 1]] + val[i - 1]);
      }
    }
  }
  return dp[n][cap];
}

/* 0-1 hátizsák: Tárhelyoptimalizált dinamikus programozás */
int knapsackDPComp(List<int> wgt, List<int> val, int cap) {
  int n = wgt.length;
  // dp tábla inicializálása
  List<int> dp = List.filled(cap + 1, 0);
  // Állapotátmenet
  for (int i = 1; i <= n; i++) {
    // Fordított sorrendű bejárás
    for (int c = cap; c >= 1; c--) {
      if (wgt[i - 1] <= c) {
        // A nagyobb érték: nem választja ki vagy kiválasztja az i tárgyat
        dp[c] = max(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
      }
    }
  }
  return dp[cap];
}

/* Főprogram */
void main() {
  List<int> wgt = [10, 20, 30, 40, 50];
  List<int> val = [50, 120, 150, 210, 240];
  int cap = 50;
  int n = wgt.length;

  // Nyers erő keresés
  int res = knapsackDFS(wgt, val, n, cap);
  print("Maximum item value not exceeding knapsack capacity is $res");

  // Memoizált keresés
  List<List<int>> mem =
      List.generate(n + 1, (index) => List.filled(cap + 1, -1));
  res = knapsackDFSMem(wgt, val, mem, n, cap);
  print("Maximum item value not exceeding knapsack capacity is $res");

  // Dinamikus programozás
  res = knapsackDP(wgt, val, cap);
  print("Maximum item value not exceeding knapsack capacity is $res");

  // Tárhelyoptimalizált dinamikus programozás
  res = knapsackDPComp(wgt, val, cap);
  print("Maximum item value not exceeding knapsack capacity is $res");
}
