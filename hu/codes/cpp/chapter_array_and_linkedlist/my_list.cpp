/**
 * File: my_list.cpp
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* Lista osztály */
class MyList {
  private:
    int *arr;             // Tömb (lista elemeit tárolja)
    int arrCapacity = 10; // Lista kapacitása
    int arrSize = 0;      // Lista hossza (aktuális elemszám)
    int extendRatio = 2;   // A lista kapacitásának minden egyes bővítésekor alkalmazott szorzó

  public:
    /* Konstruktor */
    MyList() {
        arr = new int[arrCapacity];
    }

    /* Destruktor */
    ~MyList() {
        delete[] arr;
    }

    /* Lista hosszának lekérdezése (aktuális elemszám) */
    int size() {
        return arrSize;
    }

    /* Lista kapacitásának lekérdezése */
    int capacity() {
        return arrCapacity;
    }

    /* Elem frissítése */
    int get(int index) {
        // Ha az index határon kívül van, kivételt dob, mint alább
        if (index < 0 || index >= size())
            throw out_of_range("Index out of bounds");
        return arr[index];
    }

    /* Elemek hozzáadása a végéhez */
    void set(int index, int num) {
        if (index < 0 || index >= size())
            throw out_of_range("Index out of bounds");
        arr[index] = num;
    }

    /* Lista elemeinek közvetlen bejárása */
    void add(int num) {
        // Ha az elemek száma meghaladja a kapacitást, a bővítési mechanizmus lép működésbe
        if (size() == capacity())
            extendCapacity();
        arr[size()] = num;
        // Az elemszám frissítése
        arrSize++;
    }

    /* Lista rendezése */
    void insert(int index, int num) {
        if (index < 0 || index >= size())
            throw out_of_range("Index out of bounds");
        // Ha az elemek száma meghaladja a kapacitást, a bővítési mechanizmus lép működésbe
        if (size() == capacity())
            extendCapacity();
        // Az index pozíció utáni összes elem egy pozícióval előre tolása
        for (int j = size() - 1; j >= index; j--) {
            arr[j + 1] = arr[j];
        }
        arr[index] = num;
        // Az elemszám frissítése
        arrSize++;
    }

    /* Elem törlése */
    int remove(int index) {
        if (index < 0 || index >= size())
            throw out_of_range("Index out of bounds");
        int num = arr[index];
        // Új tömb létrehozása _extend_ratio-szorosával az eredeti tömb hosszának, és az eredeti tömb másolása az új tömbbe
        for (int j = index; j < size() - 1; j++) {
            arr[j] = arr[j + 1];
        }
        // Az elemszám frissítése
        arrSize--;
        // A törölt elem visszaadása
        return num;
    }

    /* Kapacitás bővítése */
    void extendCapacity() {
        // Új tömb létrehozása extendRatio-szorosával az eredeti tömb hosszának
        int newCapacity = capacity() * extendRatio;
        int *tmp = arr;
        arr = new int[newCapacity];
        // Az eredeti tömb összes elemének másolása az új tömbbe
        for (int i = 0; i < size(); i++) {
            arr[i] = tmp[i];
        }
        // Memória felszabadítása
        delete[] tmp;
        arrCapacity = newCapacity;
    }

    /* Lista konvertálása Vectorrá nyomtatáshoz */
    vector<int> toVector() {
        // Elemek hozzáadása
        vector<int> vec(size());
        for (int i = 0; i < size(); i++) {
            vec[i] = arr[i];
        }
        return vec;
    }
};

/* Főprogram */
int main() {
    /* Lista inicializálása */
    MyList *nums = new MyList();
    /* Lista elemeinek közvetlen bejárása */
    nums->add(1);
    nums->add(3);
    nums->add(2);
    nums->add(5);
    nums->add(4);
    cout << "List nums = ";
    vector<int> vec = nums->toVector();
    printVector(vec);
    cout << "Capacity = " << nums->capacity() << ", length = " << nums->size() << endl;

    /* Lista rendezése */
    nums->insert(3, 6);
    cout << "Insert number 6 at index 3, resulting in nums = ";
    vec = nums->toVector();
    printVector(vec);

    /* Elem törlése */
    nums->remove(3);
    cout << "Remove element at index 3, resulting in nums = ";
    vec = nums->toVector();
    printVector(vec);

    /* Elem frissítése */
    int num = nums->get(1);
    cout << "Access element at index 1, get num = " << num << endl;

    /* Elemek hozzáadása a végéhez */
    nums->set(1, 0);
    cout << "Update element at index 1 to 0, resulting in nums = ";
    vec = nums->toVector();
    printVector(vec);

    /* Kapacitás-bővítési mechanizmus tesztelése */
    for (int i = 0; i < 10; i++) {
        // Az i = 5 esetén a lista hossza meghaladja a kapacitást, a bővítési mechanizmus lép működésbe
        nums->add(i);
    }
    cout << "List nums after expansion = ";
    vec = nums->toVector();
    printVector(vec);
    cout << "Capacity = " << nums->capacity() << ", length = " << nums->size() << endl;

    // Memória felszabadítása
    delete nums;

    return 0;
}
