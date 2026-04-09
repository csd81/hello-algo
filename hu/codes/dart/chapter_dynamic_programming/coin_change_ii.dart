/**
 * File: coin_change_ii.dart
 * Created Time: 2023-08-11
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

/* Érmecserélés II: Dinamikus programozás */
int coinChangeIIDP(List<int> coins, int amt) {
  int n = coins.length;
  // dp tábla inicializálása
  List<List<int>> dp = List.generate(n + 1, (index) => List.filled(amt + 1, 0));
  // Első oszlop inicializálása
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }
  // Állapotátmenet
  for (int i = 1; i <= n; i++) {
    for (int a = 1; a <= amt; a++) {
      if (coins[i - 1] > a) {
        // Ha meghaladja a célösszeget, ne válaszd ki az i érmét
        dp[i][a] = dp[i - 1][a];
      } else {
        // A két lehetőség összege: nem választja ki vagy kiválasztja az i érmét
        dp[i][a] = dp[i - 1][a] + dp[i][a - coins[i - 1]];
      }
    }
  }
  return dp[n][amt];
}

/* Érmecserélés II: Tárhelyoptimalizált dinamikus programozás */
int coinChangeIIDPComp(List<int> coins, int amt) {
  int n = coins.length;
  // dp tábla inicializálása
  List<int> dp = List.filled(amt + 1, 0);
  dp[0] = 1;
  // Állapotátmenet
  for (int i = 1; i <= n; i++) {
    for (int a = 1; a <= amt; a++) {
      if (coins[i - 1] > a) {
        // Ha meghaladja a célösszeget, ne válaszd ki az i érmét
        dp[a] = dp[a];
      } else {
        // A két lehetőség összege: nem választja ki vagy kiválasztja az i érmét
        dp[a] = dp[a] + dp[a - coins[i - 1]];
      }
    }
  }
  return dp[amt];
}

/* Főprogram */
void main() {
  List<int> coins = [1, 2, 5];
  int amt = 5;

  // Dinamikus programozás
  int res = coinChangeIIDP(coins, amt);
  print("Number of coin combinations to make target amount is $res");

  // Tárhelyoptimalizált dinamikus programozás
  res = coinChangeIIDPComp(coins, amt);
  print("Number of coin combinations to make target amount is $res");
}
