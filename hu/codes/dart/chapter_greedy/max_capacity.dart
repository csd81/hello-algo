/**
 * File: max_capacity.dart
 * Created Time: 2023-08-11
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

import 'dart:math';

/* Maximális kapacitás: Mohó algoritmus */
int maxCapacity(List<int> ht) {
  // i, j inicializálása a tömb mindkét végén
  int i = 0, j = ht.length - 1;
  // A kezdeti maximális kapacitás 0
  int res = 0;
  // Ciklus mohó kiválasztáshoz, amíg a két deszka össze nem ér
  while (i < j) {
    // Maximális kapacitás frissítése
    int cap = min(ht[i], ht[j]) * (j - i);
    res = max(res, cap);
    // A rövidebb deszkát befelé mozgatja
    if (ht[i] < ht[j]) {
      i++;
    } else {
      j--;
    }
  }
  return res;
}

/* Főprogram */
void main() {
  List<int> ht = [3, 8, 5, 2, 7, 7, 3, 4];

  // Mohó algoritmus
  int res = maxCapacity(ht);
  print("Maximum capacity is $res");
}
