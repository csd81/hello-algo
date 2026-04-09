/**
 * File: array.dart
 * Created Time: 2023-01-20
 * Author: Jefferson (JeffersonHuang77@gmail.com)
 */

// ignore_for_file: unused_local_variable

import 'dart:math';

/* Véletlenszerű hozzáférés az elemhez */
int randomAccess(List<int> nums) {
  // Véletlenszerűen válassz egy számot a [0, nums.length) intervallumból
  int randomIndex = Random().nextInt(nums.length);
  // Kérd le és add vissza a véletlen elemet
  int randomNum = nums[randomIndex];
  return randomNum;
}

/* Tömb hosszának növelése */
List<int> extend(List<int> nums, int enlarge) {
  // Inicializálj egy bővített hosszú tömböt
  List<int> res = List.filled(nums.length + enlarge, 0);
  // Másold át az összes elemet az eredeti tömbből az új tömbbe
  for (var i = 0; i < nums.length; i++) {
    res[i] = nums[i];
  }
  // Adj vissza az új, bővített tömböt
  return res;
}

/* Helyezd be a _num elemet a tömb index indexére */
void insert(List<int> nums, int _num, int index) {
  // Tol el minden elemet az index pozíciótól egy hellyel hátra
  for (var i = nums.length - 1; i > index; i--) {
    nums[i] = nums[i - 1];
  }
  // Rendeld hozzá a _num értéket az index pozícióhoz
  nums[index] = _num;
}

/* Távolítsd el az elemet az index indexen */
void remove(List<int> nums, int index) {
  // Tol el minden elemet az index pozíció után egy hellyel előre
  for (var i = index; i < nums.length - 1; i++) {
    nums[i] = nums[i + 1];
  }
}

/* Tömb elemeinek bejárása */
void traverse(List<int> nums) {
  int count = 0;
  // Tömb bejárása index szerint
  for (var i = 0; i < nums.length; i++) {
    count += nums[i];
  }
  // Tömb elemeinek közvetlen bejárása
  for (int _num in nums) {
    count += _num;
  }
  // Tömb bejárása forEach metódussal
  nums.forEach((_num) {
    count += _num;
  });
}

/* A megadott elem megkeresése a tömbben */
int find(List<int> nums, int target) {
  for (var i = 0; i < nums.length; i++) {
    if (nums[i] == target) return i;
  }
  return -1;
}

/* Főprogram */
void main() {
  /* Tömb inicializálása */
  var arr = List.filled(5, 0);
  print('Array arr = $arr');
  List<int> nums = [1, 3, 2, 5, 4];
  print('Array nums = $nums');

  /* Elem beillesztése */
  int randomNum = randomAccess(nums);
  print('Get random element $randomNum from nums');

  /* Tömb bejárása */
  nums = extend(nums, 3);
  print('Extend array length to 8, get nums = $nums');

  /* Elem beillesztése */
  insert(nums, 6, 3);
  print("Insert number 6 at index 3, get nums = $nums");

  /* Elem eltávolítása */
  remove(nums, 2);
  print("Delete element at index 2, get nums = $nums");

  /* Tömb bejárása */
  traverse(nums);

  /* Elem keresése */
  int index = find(nums, 3);
  print("Find element 3 in nums, index = $index");
}
