/**
 * File: space_complexity.dart
 * Created Time: 2023-2-12
 * Author: Jefferson (JeffersonHuang77@gmail.com)
 */

// ignore_for_file: unused_local_variable

import 'dart:collection';
import '../utils/list_node.dart';
import '../utils/print_util.dart';
import '../utils/tree_node.dart';

/* Függvény */
int function() {
  // Valamilyen műveletek végrehajtása
  return 0;
}

/* Konstans rend */
void constant(int n) {
  // Konstansok, változók, objektumok O(1) tárhelyet foglalnak
  final int a = 0;
  int b = 0;
  List<int> nums = List.filled(10000, 0);
  ListNode node = ListNode(0);
  // A ciklusban lévő változók O(1) tárhelyet foglalnak
  for (var i = 0; i < n; i++) {
    int c = 0;
  }
  // A ciklusban lévő függvények O(1) tárhelyet foglalnak
  for (var i = 0; i < n; i++) {
    function();
  }
}

/* Lineáris rend */
void linear(int n) {
  // n hosszúságú tömb O(n) tárhelyet használ
  List<int> nums = List.filled(n, 0);
  // n hosszúságú lista O(n) tárhelyet foglal
  List<ListNode> nodes = [];
  for (var i = 0; i < n; i++) {
    nodes.add(ListNode(i));
  }
  // n hosszúságú hash tábla O(n) tárhelyet foglal
  Map<int, String> map = HashMap();
  for (var i = 0; i < n; i++) {
    map.putIfAbsent(i, () => i.toString());
  }
}

/* Lineáris rend (rekurzív implementáció) */
void linearRecur(int n) {
  print('Recursion n = $n');
  if (n == 1) return;
  linearRecur(n - 1);
}

/* Négyzetes rend */
void quadratic(int n) {
  // Mátrix O(n^2) tárhelyet használ
  List<List<int>> numMatrix = List.generate(n, (_) => List.filled(n, 0));
  // Kétdimenziós lista O(n^2) tárhelyet használ
  List<List<int>> numList = [];
  for (var i = 0; i < n; i++) {
    List<int> tmp = [];
    for (int j = 0; j < n; j++) {
      tmp.add(0);
    }
    numList.add(tmp);
  }
}

/* Négyzetes rend (rekurzív implementáció) */
int quadraticRecur(int n) {
  if (n <= 0) return 0;
  List<int> nums = List.filled(n, 0);
  print('In recursion n = $n, nums length = ${nums.length}');
  return quadraticRecur(n - 1);
}

/* Főprogram */
TreeNode? buildTree(int n) {
  if (n == 0) return null;
  TreeNode root = TreeNode(0);
  root.left = buildTree(n - 1);
  root.right = buildTree(n - 1);
  return root;
}

/* Főprogram */
void main() {
  int n = 5;
  // Konstans rend
  constant(n);
  // Lineáris rend
  linear(n);
  linearRecur(n);
  // Négyzetes rend
  quadratic(n);
  quadraticRecur(n);
  // Exponenciális rend
  TreeNode? root = buildTree(n);
  printTree(root);
}
