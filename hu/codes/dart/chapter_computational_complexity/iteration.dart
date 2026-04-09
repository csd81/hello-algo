/**
 * File: iteration.dart
 * Created Time: 2023-08-27
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

/* for ciklus */
int forLoop(int n) {
  int res = 0;
  // Összegzés: 1, 2, ..., n-1, n
  for (int i = 1; i <= n; i++) {
    res += i;
  }
  return res;
}

/* while ciklus */
int whileLoop(int n) {
  int res = 0;
  int i = 1; // Feltételváltozó inicializálása
  // Összegzés: 1, 2, ..., n-1, n
  while (i <= n) {
    res += i;
    i++; // Feltételváltozó frissítése
  }
  return res;
}

/* while ciklus (két frissítéssel) */
int whileLoopII(int n) {
  int res = 0;
  int i = 1; // Feltételváltozó inicializálása
  // Összegzés: 1, 4, 10, ...
  while (i <= n) {
    res += i;
    // Feltételváltozó frissítése
    i++;
    i *= 2;
  }
  return res;
}

/* Egymásba ágyazott for ciklus */
String nestedForLoop(int n) {
  String res = "";
  // i ciklus: 1, 2, ..., n-1, n
  for (int i = 1; i <= n; i++) {
    // j ciklus: 1, 2, ..., n-1, n
    for (int j = 1; j <= n; j++) {
      res += "($i, $j), ";
    }
  }
  return res;
}

/* Főprogram */
void main() {
  int n = 5;
  int res;

  res = forLoop(n);
  print("\nFor loop sum result res = $res");

  res = whileLoop(n);
  print("\nWhile loop sum result res = $res");

  res = whileLoopII(n);
  print("\nWhile loop (two updates) sum result res = $res");

  String resStr = nestedForLoop(n);
  print("\nNested for loop result $resStr");
}
