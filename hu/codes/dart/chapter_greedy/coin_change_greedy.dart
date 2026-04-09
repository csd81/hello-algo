/**
 * File: coin_change_greedy.dart
 * Created Time: 2023-08-11
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

/* Érmecserélés: Mohó algoritmus */
int coinChangeGreedy(List<int> coins, int amt) {
  // Feltételezzük, hogy a coins lista rendezett
  int i = coins.length - 1;
  int count = 0;
  // Ciklusban végez mohó döntéseket, amíg nincs maradék összeg
  while (amt > 0) {
    // Megkeresi a maradék összegnél kisebb és ahhoz legközelebbi érmét
    while (i > 0 && coins[i] > amt) {
      i--;
    }
    // coins[i] kiválasztása
    amt -= coins[i];
    count++;
  }
  // Ha nem található megvalósítható megoldás, adjon vissza -1-et
  return amt == 0 ? count : -1;
}

/* Főprogram */
void main() {
  // Mohó algoritmus: garantáltan megtalálja a globális optimális megoldást
  List<int> coins = [1, 5, 10, 20, 50, 100];
  int amt = 186;
  int res = coinChangeGreedy(coins, amt);
  print("\ncoins = $coins, amt = $amt");
  print("Minimum coins needed to make $amt is $res");

  // Mohó algoritmus: nem garantáltan találja meg a globális optimális megoldást
  coins = [1, 20, 50];
  amt = 60;
  res = coinChangeGreedy(coins, amt);
  print("\ncoins = $coins, amt = $amt");
  print("Minimum coins needed to make $amt is $res");
  print("Actually the minimum number needed is 3, i.e., 20 + 20 + 20");

  // Mohó algoritmus: nem garantáltan találja meg a globális optimális megoldást
  coins = [1, 49, 50];
  amt = 98;
  res = coinChangeGreedy(coins, amt);
  print("\ncoins = $coins, amt = $amt");
  print("Minimum coins needed to make $amt is $res");
  print("Actually the minimum number needed is 2, i.e., 49 + 49");
}
