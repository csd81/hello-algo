/**
 * File: my_list.dart
 * Created Time: 2023-02-05
 * Author: Jefferson (JeffersonHuang77@gmail.com)
 */

/* Lista osztály */
class MyList {
  late List<int> _arr; // Tömb (lista elemeit tárolja)
  int _capacity = 10; // Lista kapacitása
  int _size = 0; // Lista hossza (aktuális elemek száma)
  int _extendRatio = 2; // A lista kapacitásának bővítési szorzója

  /* Konstruktor */
  MyList() {
    _arr = List.filled(_capacity, 0);
  }

  /* Lista hosszának lekérése (aktuális elemek száma) */
  int size() => _size;

  /* Lista kapacitásának lekérése */
  int capacity() => _capacity;

  /* Elem frissítése */
  int get(int index) {
    if (index >= _size) throw RangeError('Index out of bounds');
    return _arr[index];
  }

  /* Elemek hozzáadása a végéhez */
  void set(int index, int _num) {
    if (index >= _size) throw RangeError('Index out of bounds');
    _arr[index] = _num;
  }

  /* Lista elemeinek közvetlen bejárása */
  void add(int _num) {
    // Ha az elemek száma meghaladja a kapacitást, aktiválódik a bővítési mechanizmus
    if (_size == _capacity) extendCapacity();
    _arr[_size] = _num;
    // Az elemek számának frissítése
    _size++;
  }

  /* Lista rendezése */
  void insert(int index, int _num) {
    if (index >= _size) throw RangeError('Index out of bounds');
    // Ha az elemek száma meghaladja a kapacitást, aktiválódik a bővítési mechanizmus
    if (_size == _capacity) extendCapacity();
    // Tol el minden elemet az index pozíció után egy hellyel hátra
    for (var j = _size - 1; j >= index; j--) {
      _arr[j + 1] = _arr[j];
    }
    _arr[index] = _num;
    // Az elemek számának frissítése
    _size++;
  }

  /* Elem eltávolítása */
  int remove(int index) {
    if (index >= _size) throw RangeError('Index out of bounds');
    int _num = _arr[index];
    // Tol el minden elemet az index pozíció után egy hellyel előre
    for (var j = index; j < _size - 1; j++) {
      _arr[j] = _arr[j + 1];
    }
    // Az elemek számának frissítése
    _size--;
    // Az eltávolított elem visszaadása
    return _num;
  }

  /* Főprogram */
  void extendCapacity() {
    // Hozz létre egy új tömböt, amelynek hossza _extendRatio-szorosaa az eredetinek
    final _newNums = List.filled(_capacity * _extendRatio, 0);
    // Másold az eredeti tömböt az új tömbbe
    List.copyRange(_newNums, 0, _arr);
    // Frissítsd a _arr hivatkozást
    _arr = _newNums;
    // Elemek hozzáadása a végéhez
    _capacity = _arr.length;
  }

  /* Lista konvertálása tömbbé */
  List<int> toArray() {
    List<int> arr = [];
    for (var i = 0; i < _size; i++) {
      arr.add(get(i));
    }
    return arr;
  }
}

/* Főprogram */
void main() {
  /* Lista inicializálása */
  MyList nums = MyList();
  /* Lista elemeinek közvetlen bejárása */
  nums.add(1);
  nums.add(3);
  nums.add(2);
  nums.add(5);
  nums.add(4);
  print(
      'List nums = ${nums.toArray()}, capacity = ${nums.capacity()}, length = ${nums.size()}');

  /* Lista rendezése */
  nums.insert(3, 6);
  print('Insert number 6 at index 3, get nums = ${nums.toArray()}');

  /* Elem eltávolítása */
  nums.remove(3);
  print('Delete element at index 3, get nums = ${nums.toArray()}');

  /* Elem frissítése */
  int _num = nums.get(1);
  print('Access element at index 1, get _num = $_num');

  /* Elemek hozzáadása a végéhez */
  nums.set(1, 0);
  print('Update element at index 1 to 0, get nums = ${nums.toArray()}');

  /* Kapacitásbővítési mechanizmus tesztelése */
  for (var i = 0; i < 10; i++) {
    // Az i = 5 értéknél a lista hossza meghaladja a kapacitást, aktiválódik a bővítési mechanizmus
    nums.add(i);
  }
  print(
      'After expansion, list nums = ${nums.toArray()}, capacity = ${nums.capacity()}, length = ${nums.size()}');
}
