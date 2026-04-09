/**
 * File: fractional_knapsack.dart
 * Created Time: 2023-08-11
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

/* Tárgy */
class Item {
  int w; // Tárgy súlya
  int v; // Tárgy értéke

  Item(this.w, this.v);
}

/* Töredékes hátizsák: Mohó algoritmus */
double fractionalKnapsack(List<int> wgt, List<int> val, int cap) {
  // Tárgyak listájának létrehozása két attribútummal: súly, érték
  List<Item> items = List.generate(wgt.length, (i) => Item(wgt[i], val[i]));
  // Rendezés egységérték item.v / item.w szerint csökkenő sorrendben
  items.sort((a, b) => (b.v / b.w).compareTo(a.v / a.w));
  // Ciklus a mohó kiválasztáshoz
  double res = 0;
  for (Item item in items) {
    if (item.w <= cap) {
      // Ha elegendő a maradék kapacitás, tedd be a teljes aktuális tárgyat a hátizsákba
      res += item.v;
      cap -= item.w;
    } else {
      // Ha nem elegendő a maradék kapacitás, tedd be az aktuális tárgy egy részét a hátizsákba
      res += item.v / item.w * cap;
      // Nincs maradék kapacitás, szakítsd meg a ciklust
      break;
    }
  }
  return res;
}

/* Főprogram */
void main() {
  List<int> wgt = [10, 20, 30, 40, 50];
  List<int> val = [50, 120, 150, 210, 240];
  int cap = 50;

  // Mohó algoritmus
  double res = fractionalKnapsack(wgt, val, cap);
  print("Maximum item value not exceeding knapsack capacity is $res");
}
