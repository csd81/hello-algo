/**
 * File: list.dart
 * Created Time: 2023-01-24
 * Author: Jefferson (JeffersonHuang77@gmail.com)
 */

// ignore_for_file: unused_local_variable

/* Főprogram */
void main() {
  /* Lista inicializálása */
  List<int> nums = [1, 3, 2, 5, 4];
  print('List nums = $nums');

  /* Elem frissítése */
  int _num = nums[1];
  print('Access element at index 1, get _num = $_num');

  /* Elemek hozzáadása a végéhez */
  nums[1] = 0;
  print('Update element at index 1 to 0, get nums = $nums');

  /* Elem eltávolítása */
  nums.clear();
  print('After clearing list, nums = $nums');

  /* Lista elemeinek közvetlen bejárása */
  nums.add(1);
  nums.add(3);
  nums.add(2);
  nums.add(5);
  nums.add(4);
  print('After adding elements, nums = $nums');

  /* Lista rendezése */
  nums.insert(3, 6);
  print('Insert number 6 at index 3, get nums = $nums');

  /* Elem eltávolítása */
  nums.removeAt(3);
  print('Delete element at index 3, get nums = $nums');

  /* Lista bejárása index szerint */
  int count = 0;
  for (var i = 0; i < nums.length; i++) {
    count += nums[i];
  }
  /* Lista elemeinek közvetlen bejárása */
  count = 0;
  for (var x in nums) {
    count += x;
  }

  /* Két lista összefűzése */
  List<int> nums1 = [6, 8, 7, 10, 9];
  nums.addAll(nums1);
  print('After concatenating list nums1 to nums, get nums = $nums');

  /* Lista rendezése */
  nums.sort();
  print('After sorting list, nums = $nums');
}
