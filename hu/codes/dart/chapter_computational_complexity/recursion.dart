/**
 * File: recursion.dart
 * Created Time: 2023-08-27
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

/* Rekurzió */
int recur(int n) {
  // Leállási feltétel
  if (n == 1) return 1;
  // Rekurzió: rekurzív hívás
  int res = recur(n - 1);
  // Visszatérés: eredmény visszaadása
  return n + res;
}

/* Rekurzió szimulálása iterációval */
int forLoopRecur(int n) {
  // Explicit verem használata a rendszer hívási verem szimulálásához
  List<int> stack = [];
  int res = 0;
  // Rekurzió: rekurzív hívás
  for (int i = n; i > 0; i--) {
    // "rekurzió" szimulálása "push" művelettel
    stack.add(i);
  }
  // Visszatérés: eredmény visszaadása
  while (!stack.isEmpty) {
    // "visszatérés" szimulálása "pop" művelettel
    res += stack.removeLast();
  }
  // res = 1+2+3+...+n
  return res;
}

/* Farokrekurzió */
int tailRecur(int n, int res) {
  // Leállási feltétel
  if (n == 0) return res;
  // Farokrekurzív hívás
  return tailRecur(n - 1, res + n);
}

/* Fibonacci-sorozat: rekurzió */
int fib(int n) {
  // Leállási feltétel: f(1) = 0, f(2) = 1
  if (n == 1 || n == 2) return n - 1;
  // Rekurzív hívás: f(n) = f(n-1) + f(n-2)
  int res = fib(n - 1) + fib(n - 2);
  // Eredmény visszaadása: f(n)
  return res;
}

/* Főprogram */
void main() {
  int n = 5;
  int res;

  res = recur(n);
  print("\nRecursion sum result res = $res");

  res = tailRecur(n, 0);
  print("\nTail recursion sum result res = $res");

  res = forLoopRecur(n);
  print("\nUsing iteration to simulate recursion sum result res = $res");

  res = fib(n);
  print("\nThe ${n}th Fibonacci number is $res");
}
