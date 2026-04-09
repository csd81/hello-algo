/**
 * File: n_queens.dart
 * Created Time: 2023-08-10
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

/* Visszalépéses algoritmus: N királynő */
void backtrack(
  int row,
  int n,
  List<List<String>> state,
  List<List<List<String>>> res,
  List<bool> cols,
  List<bool> diags1,
  List<bool> diags2,
) {
  // Ha minden sor el van helyezve, jegyezze fel a megoldást
  if (row == n) {
    List<List<String>> copyState = [];
    for (List<String> sRow in state) {
      copyState.add(List.from(sRow));
    }
    res.add(copyState);
    return;
  }
  // Összes oszlop bejárása
  for (int col = 0; col < n; col++) {
    // Számítsd ki az ehhez a cellához tartozó főátlót és mellékátlót
    int diag1 = row - col + n - 1;
    int diag2 = row + col;
    // Metszés: ne engedélyezd királynő elhelyezését az oszlopban, főátlón és mellékátlón
    if (!cols[col] && !diags1[diag1] && !diags2[diag2]) {
      // Kísérlet: helyezd el a királynőt ebbe a cellába
      state[row][col] = "Q";
      cols[col] = true;
      diags1[diag1] = true;
      diags2[diag2] = true;
      // Következő sor elhelyezése
      backtrack(row + 1, n, state, res, cols, diags1, diags2);
      // Visszalépés: állítsd vissza ezt a cellát üres cellává
      state[row][col] = "#";
      cols[col] = false;
      diags1[diag1] = false;
      diags2[diag2] = false;
    }
  }
}

/* N királynő megoldása */
List<List<List<String>>> nQueens(int n) {
  // Inicializálj egy n*n sakktáblát, ahol 'Q' a királynőt, '#' az üres cellát jelöli
  List<List<String>> state = List.generate(n, (index) => List.filled(n, "#"));
  List<bool> cols = List.filled(n, false); // Nyilvántartja, hogy van-e királynő az oszlopban
  List<bool> diags1 = List.filled(2 * n - 1, false); // Nyilvántartja, hogy van-e királynő a főátlón
  List<bool> diags2 = List.filled(2 * n - 1, false); // Nyilvántartja, hogy van-e királynő a mellékátlón
  List<List<List<String>>> res = [];

  backtrack(0, n, state, res, cols, diags1, diags2);

  return res;
}

/* Főprogram */
void main() {
  int n = 4;
  List<List<List<String>>> res = nQueens(n);
  print("Input board size is $n");
  print("Total queen placement solutions: ${res.length}");
  for (List<List<String>> state in res) {
    print("--------------------");
    for (List<String> row in state) {
      print(row);
    }
  }
}
