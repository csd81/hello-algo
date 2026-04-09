/**
 * File: my_list.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_array_and_linkedlist;

import java.util.*;

/* Lista osztály */
class MyList {
    private int[] arr; // Tömb (a lista elemeit tárolja)
    private int capacity = 10; // Lista kapacitása
    private int size = 0; // Lista hossza (jelenlegi elemszám)
    private int extendRatio = 2; // A lista kapacitásának bővítési szorzója

    /* Konstruktor */
    public MyList() {
        arr = new int[capacity];
    }

    /* Lista hosszának lekérése (jelenlegi elemszám) */
    public int size() {
        return size;
    }

    /* Lista kapacitásának lekérése */
    public int capacity() {
        return capacity;
    }

    /* Elem frissítése */
    public int get(int index) {
        // Ha az index határon kívül van, kivételt dob, ahogy alább is
        if (index < 0 || index >= size)
            throw new IndexOutOfBoundsException("Index out of bounds");
        return arr[index];
    }

    /* Elem hozzáadása a végéhez */
    public void set(int index, int num) {
        if (index < 0 || index >= size)
            throw new IndexOutOfBoundsException("Index out of bounds");
        arr[index] = num;
    }

    /* Lista elemeinek közvetlen bejárása */
    public void add(int num) {
        // Ha az elemszám meghaladja a kapacitást, bővítési mechanizmus indul
        if (size == capacity())
            extendCapacity();
        arr[size] = num;
        // Az elemszám frissítése
        size++;
    }

    /* Lista rendezése */
    public void insert(int index, int num) {
        if (index < 0 || index >= size)
            throw new IndexOutOfBoundsException("Index out of bounds");
        // Ha az elemszám meghaladja a kapacitást, bővítési mechanizmus indul
        if (size == capacity())
            extendCapacity();
        // Az index utáni összes elemet eggyel előrébb lép
        for (int j = size - 1; j >= index; j--) {
            arr[j + 1] = arr[j];
        }
        arr[index] = num;
        // Az elemszám frissítése
        size++;
    }

    /* Elem törlése */
    public int remove(int index) {
        if (index < 0 || index >= size)
            throw new IndexOutOfBoundsException("Index out of bounds");
        int num = arr[index];
        // Az index utáni összes elemet eggyel előrébb lép
        for (int j = index; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        // Az elemszám frissítése
        size--;
        // A törölt elem visszaadása
        return num;
    }

    /* Főprogram */
    public void extendCapacity() {
        // Új tömböt hoz létre, melynek hossza extendRatio-szorosa az eredetinek, és átmásolja az eredeti tömböt
        arr = Arrays.copyOf(arr, capacity() * extendRatio);
        // Elemek hozzáadása a végéhez
        capacity = arr.length;
    }

    /* Lista tömbté konvertálása */
    public int[] toArray() {
        int size = size();
        // Elemek sorba állítása
        int[] arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = get(i);
        }
        return arr;
    }
}

public class my_list {
    /* Főprogram */
    public static void main(String[] args) {
        /* Lista inicializálása */
        MyList nums = new MyList();
        /* Lista elemeinek közvetlen bejárása */
        nums.add(1);
        nums.add(3);
        nums.add(2);
        nums.add(5);
        nums.add(4);
        System.out.println("List nums = " + Arrays.toString(nums.toArray()) +
                ", capacity = " + nums.capacity() + ", length = " + nums.size());

        /* Lista rendezése */
        nums.insert(3, 6);
        System.out.println("Insert number 6 at index 3, resulting in nums = " + Arrays.toString(nums.toArray()));

        /* Elem törlése */
        nums.remove(3);
        System.out.println("Remove element at index 3, resulting in nums = " + Arrays.toString(nums.toArray()));

        /* Elem frissítése */
        int num = nums.get(1);
        System.out.println("Access element at index 1, get num = " + num);

        /* Elem hozzáadása a végéhez */
        nums.set(1, 0);
        System.out.println("Update element at index 1 to 0, resulting in nums = " + Arrays.toString(nums.toArray()));

        /* Kapacitásbővítési mechanizmus tesztelése */
        for (int i = 0; i < 10; i++) {
            // i = 5 esetén a lista hossza meghaladja a kapacitást, és bővítési mechanizmus indul
            nums.add(i);
        }
        System.out.println("List nums after expansion = " + Arrays.toString(nums.toArray()) +
                ", capacity = " + nums.capacity() + ", length = " + nums.size());
    }
}
