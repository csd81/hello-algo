/**
 * File: worst_best_time_complexity.dart
 * Created Time: 2023-02-12
 * Author: Jefferson (JeffersonHuang77@gmail.com)
 */

/* { 1, 2, ..., n } elemeket tartalmazó tömb generálása, véletlenszerű sorrendben */
List<int> randomNumbers(int n) {
  final nums = List.filled(n, 0);
  // nums = { 1, 2, 3, ..., n } tömb generálása
  for (var i = 0; i < n; i++) {
    nums[i] = i + 1;
  }
  // Tömb elemeinek véletlenszerű keverése
  nums.shuffle();

  return nums;
}

/* Az 1-es szám indexének megkeresése a nums tömbben */
int findOne(List<int> nums) {
  for (var i = 0; i < nums.length; i++) {
    // Ha az 1-es elem a tömb elején van, legjobb esetbeli időbonyolultság O(1) érhető el
    // Ha az 1-es elem a tömb végén van, legrosszabb esetbeli időbonyolultság O(n) érhető el
    if (nums[i] == 1) return i;
  }

  return -1;
}

/* Főprogram */
void main() {
  for (var i = 0; i < 10; i++) {
    int n = 100;
    final nums = randomNumbers(n);
    int index = findOne(nums);
    print('\nArray [ 1, 2, ..., n ] after shuffling = $nums');
    print('Index of number 1 is + $index');
  }
}
