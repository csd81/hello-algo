/**
 * File: binary_search_recur.dart
 * Created Time: 2023-08-10
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

/* Bináris keresés: f(i, j) részfeladat */
int dfs(List<int> nums, int target, int i, int j) {
  // Ha az intervallum üres, a célelelem nem létezik, visszaad -1-et
  if (i > j) {
    return -1;
  }
  // Középső index m kiszámítása
  int m = (i + j) ~/ 2;
  if (nums[m] < target) {
    // Rekurzió az f(m+1, j) részfeladatra
    return dfs(nums, target, m + 1, j);
  } else if (nums[m] > target) {
    // Rekurzió az f(i, m-1) részfeladatra
    return dfs(nums, target, i, m - 1);
  } else {
    // Megtalálta a célelemet, visszaadja az indexét
    return m;
  }
}

/* Bináris keresés */
int binarySearch(List<int> nums, int target) {
  int n = nums.length;
  // f(0, n-1) feladat megoldása
  return dfs(nums, target, 0, n - 1);
}

/* Főprogram */
void main() {
  int target = 6;
  List<int> nums = [1, 3, 6, 8, 12, 15, 23, 26, 31, 35];

  // Bináris keresés (mindkét oldalról zárt intervallum)
  int index = binarySearch(nums, target);
  print("Index of target element 6 = $index");
}
