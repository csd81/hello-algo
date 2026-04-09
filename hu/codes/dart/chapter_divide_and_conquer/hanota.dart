/**
 * File: hanota.dart
 * Created Time: 2023-08-10
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

/* Korong mozgatása */
void move(List<int> src, List<int> tar) {
  // Vedd ki a korongot az src tetejéről
  int pan = src.removeLast();
  // Helyezd a korongot a tar tetejére
  tar.add(pan);
}

/* Hanoi torony f(i) feladatának megoldása */
void dfs(int i, List<int> src, List<int> buf, List<int> tar) {
  // Ha csak egy korong maradt az src-ben, közvetlenül mozgasd tar-ba
  if (i == 1) {
    move(src, tar);
    return;
  }
  // f(i-1) részfeladat: mozgasd a felső i-1 korongot src-ből buf-ba tar segítségével
  dfs(i - 1, src, tar, buf);
  // f(1) részfeladat: mozgasd a maradék korongot src-ből tar-ba
  move(src, tar);
  // f(i-1) részfeladat: mozgasd a felső i-1 korongot buf-ból tar-ba src segítségével
  dfs(i - 1, buf, src, tar);
}

/* Hanoi torony feladatának megoldása */
void solveHanota(List<int> A, List<int> B, List<int> C) {
  int n = A.length;
  // A felső n korongot A-ból C-be mozgatja B segítségével
  dfs(n, A, B, C);
}

/* Főprogram */
void main() {
  // A lista vége a rúd teteje
  List<int> A = [5, 4, 3, 2, 1];
  List<int> B = [];
  List<int> C = [];
  print("In initial state:");
  print("A = $A");
  print("B = $B");
  print("C = $C");

  solveHanota(A, B, C);

  print("After disk movement is complete:");
  print("A = $A");
  print("B = $B");
  print("C = $C");
}
