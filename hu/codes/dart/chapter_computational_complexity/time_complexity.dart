/**
 * File: time_complexity.dart
 * Created Time: 2023-02-12
 * Author: Jefferson (JeffersonHuang77@gmail.com)
 */

// ignore_for_file: unused_local_variable

/* Konstans rend */
int constant(int n) {
  int count = 0;
  int size = 100000;
  for (var i = 0; i < size; i++) {
    count++;
  }
  return count;
}

/* Lineáris rend */
int linear(int n) {
  int count = 0;
  for (var i = 0; i < n; i++) {
    count++;
  }
  return count;
}

/* Lineáris rend (tömb bejárása) */
int arrayTraversal(List<int> nums) {
  int count = 0;
  // Az iterációk száma arányos a tömb hosszával
  for (var _num in nums) {
    count++;
  }
  return count;
}

/* Négyzetes rend */
int quadratic(int n) {
  int count = 0;
  // Az iterációk száma négyzetes összefüggésben áll az n adatmérettel
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      count++;
    }
  }
  return count;
}

/* Négyzetes rend (buborékrendezés) */
int bubbleSort(List<int> nums) {
  int count = 0; // Számláló
  // Külső ciklus: a rendezetlen tartomány [0, i]
  for (var i = nums.length - 1; i > 0; i--) {
    // Belső ciklus: a [0, i] rendezetlen tartomány legnagyobb elemét a tartomány jobb végére cseréli
    for (var j = 0; j < i; j++) {
      if (nums[j] > nums[j + 1]) {
        // nums[j] és nums[j + 1] felcserélése
        int tmp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = tmp;
        count += 3; // Az elemcsere 3 alapműveletet tartalmaz
      }
    }
  }
  return count;
}

/* Exponenciális rend (ciklus implementáció) */
int exponential(int n) {
  int count = 0, base = 1;
  // A sejtek minden körben kettéosztódnak, sorozatot alkotva: 1, 2, 4, 8, ..., 2^(n-1)
  for (var i = 0; i < n; i++) {
    for (var j = 0; j < base; j++) {
      count++;
    }
    base *= 2;
  }
  // count = 1 + 2 + 4 + 8 + .. + 2^(n-1) = 2^n - 1
  return count;
}

/* Exponenciális rend (rekurzív implementáció) */
int expRecur(int n) {
  if (n == 1) return 1;
  return expRecur(n - 1) + expRecur(n - 1) + 1;
}

/* Logaritmikus rend (ciklus implementáció) */
int logarithmic(int n) {
  int count = 0;
  while (n > 1) {
    n = n ~/ 2;
    count++;
  }
  return count;
}

/* Logaritmikus rend (rekurzív implementáció) */
int logRecur(int n) {
  if (n <= 1) return 0;
  return logRecur(n ~/ 2) + 1;
}

/* Lineáris logaritmikus rend */
int linearLogRecur(int n) {
  if (n <= 1) return 1;
  int count = linearLogRecur(n ~/ 2) + linearLogRecur(n ~/ 2);
  for (var i = 0; i < n; i++) {
    count++;
  }
  return count;
}

/* Faktoriális rend (rekurzív implementáció) */
int factorialRecur(int n) {
  if (n == 0) return 1;
  int count = 0;
  // 1-ből n darabra osztódik szét
  for (var i = 0; i < n; i++) {
    count += factorialRecur(n - 1);
  }
  return count;
}

/* Főprogram */
void main() {
  // Az n értékét módosítva futtathatod és megfigyelheted a különböző komplexitású műveletek számának trendjét
  int n = 8;
  print('Input data size n = $n');

  int count = constant(n);
  print('Constant-time operations count = $count');

  count = linear(n);
  print('Linear-time operations count = $count');

  count = arrayTraversal(List.filled(n, 0));
  print('Linear-time (array traversal) operations count = $count');

  count = quadratic(n);
  print('Quadratic-time operations count = $count');
  final nums = List.filled(n, 0);
  for (int i = 0; i < n; i++) {
    nums[i] = n - i; // [n,n-1,...,2,1]
  }
  count = bubbleSort(nums);
  print('Quadratic-time (bubble sort) operations count = $count');

  count = exponential(n);
  print('Exponential-time (iterative) operations count = $count');
  count = expRecur(n);
  print('Exponential-time (recursive) operations count = $count');

  count = logarithmic(n);
  print('Logarithmic-time (iterative) operations count = $count');
  count = logRecur(n);
  print('Logarithmic-time (recursive) operations count = $count');

  count = linearLogRecur(n);
  print('Linearithmic-time (recursive) operations count = $count');

  count = factorialRecur(n);
  print('Factorial-time (recursive) operations count = $count');
}
