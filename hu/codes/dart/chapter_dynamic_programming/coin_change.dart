/**
 * File: coin_change.dart
 * Created Time: 2023-08-11
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

import 'dart:math';

/* Érmecserélés: Dinamikus programozás */
int coinChangeDP(List<int> coins, int amt) {
  int n = coins.length;
  int MAX = amt + 1;
  // dp tábla inicializálása
  List<List<int>> dp = List.generate(n + 1, (index) => List.filled(amt + 1, 0));
  // Állapotátmenet: első sor és első oszlop
  for (int a = 1; a <= amt; a++) {
    dp[0][a] = MAX;
  }
  // Állapotátmenet: többi sor és oszlop
  for (int i = 1; i <= n; i++) {
    for (int a = 1; a <= amt; a++) {
      if (coins[i - 1] > a) {
        // Ha meghaladja a célösszeget, ne válaszd ki az i érmét
        dp[i][a] = dp[i - 1][a];
      } else {
        // A kisebb érték: nem választja ki vagy kiválasztja az i érmét
        dp[i][a] = min(dp[i - 1][a], dp[i][a - coins[i - 1]] + 1);
      }
    }
  }
  return dp[n][amt] != MAX ? dp[n][amt] : -1;
}

/* Érmecserélés: Tárhelyoptimalizált dinamikus programozás */
int coinChangeDPComp(List<int> coins, int amt) {
  int n = coins.length;
  int MAX = amt + 1;
  // dp tábla inicializálása
  List<int> dp = List.filled(amt + 1, MAX);
  dp[0] = 0;
  // Állapotátmenet
  for (int i = 1; i <= n; i++) {
    for (int a = 1; a <= amt; a++) {
      if (coins[i - 1] > a) {
        // Ha meghaladja a célösszeget, ne válaszd ki az i érmét
        dp[a] = dp[a];
      } else {
        // A kisebb érték: nem választja ki vagy kiválasztja az i érmét
        dp[a] = min(dp[a], dp[a - coins[i - 1]] + 1);
      }
    }
  }
  return dp[amt] != MAX ? dp[amt] : -1;
}

/* Főprogram */
void main() {
  List<int> coins = [1, 2, 5];
  int amt = 4;

  // Dinamikus programozás
  int res = coinChangeDP(coins, amt);
  print("Minimum coins needed to make target amount is $res");

  // Tárhelyoptimalizált dinamikus programozás
  res = coinChangeDPComp(coins, amt);
  print("Minimum coins needed to make target amount is $res");
}
