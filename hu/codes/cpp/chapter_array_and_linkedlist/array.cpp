/**
 * File: array.cpp
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* Véletlenszerű hozzáférés elemhez */
int randomAccess(int *nums, int size) {
    // Véletlenszerűen kiválasztott szám a [0, size) intervallumból
    int randomIndex = rand() % size;
    // A véletlenszerű elem lekérése és visszaadása
    int randomNum = nums[randomIndex];
    return randomNum;
}

/* Tömb hosszának bővítése */
int *extend(int *nums, int size, int enlarge) {
    // Bővített hosszúságú tömb inicializálása
    int *res = new int[size + enlarge];
    // Az eredeti tömb összes elemének másolása az új tömbbe
    for (int i = 0; i < size; i++) {
        res[i] = nums[i];
    }
    // Memória felszabadítása
    delete[] nums;
    // A bővített új tömb visszaadása
    return res;
}

/* A num elem beszúrása a tömb index indexébe */
void insert(int *nums, int size, int num, int index) {
    // Az index pozíción lévő és utána következő összes elem egy pozícióval hátrafelé tolása
    for (int i = size - 1; i > index; i--) {
        nums[i] = nums[i - 1];
    }
    // A num értékének hozzárendelése az index pozíción lévő elemhez
    nums[index] = num;
}

/* Az index indexen lévő elem törlése */
void remove(int *nums, int size, int index) {
    // Az index pozíció utáni összes elem egy pozícióval előre tolása
    for (int i = index; i < size - 1; i++) {
        nums[i] = nums[i + 1];
    }
}

/* Tömb bejárása */
void traverse(int *nums, int size) {
    int count = 0;
    // Tömb bejárása index szerint
    for (int i = 0; i < size; i++) {
        count += nums[i];
    }
}

/* A megadott elem keresése a tömbben */
int find(int *nums, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (nums[i] == target)
            return i;
    }
    return -1;
}

/* Főprogram */
int main() {
    /* Tömb inicializálása */
    int size = 5;
    int *arr = new int[size];
    cout << "Array arr = ";
    printArray(arr, size);

    int *nums = new int[size]{1, 3, 2, 5, 4};
    cout << "Array nums = ";
    printArray(nums, size);

    /* Elem beszúrása */
    int randomNum = randomAccess(nums, size);
    cout << "Get random element in nums " << randomNum << endl;

    /* Tömb bejárása */
    int enlarge = 3;
    nums = extend(nums, size, enlarge);
    size += enlarge;
    cout << "Extend array length to 8, resulting in nums = ";
    printArray(nums, size);

    /* Elem beszúrása */
    insert(nums, size, 6, 3);
    cout << "Insert number 6 at index 3, resulting in nums = ";
    printArray(nums, size);

    /* Elem törlése */
    remove(nums, size, 2);
    cout << "Remove element at index 2, resulting in nums = ";
    printArray(nums, size);

    /* Tömb bejárása */
    traverse(nums, size);

    /* Elem keresése */
    int index = find(nums, size, 3);
    cout << "Find element 3 in nums, get index = " << index << endl;

    // Memória felszabadítása
    delete[] arr;
    delete[] nums;

    return 0;
}
