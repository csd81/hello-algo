/**
 * File: array.c
 * Created Time: 2022-12-20
 * Author: MolDuM (moldum@163.com)
 */

#include "../utils/common.h"

/* Véletlen hozzáférés elemhez */
int randomAccess(int *nums, int size) {
    // Véletlenszerűen válasszon egy számot a [0, size) intervallumból
    int randomIndex = rand() % size;
    // A véletlen elem lekérése és visszaadása
    int randomNum = nums[randomIndex];
    return randomNum;
}

/* Tömb hosszának bővítése */
int *extend(int *nums, int size, int enlarge) {
    // Bővített hosszú tömb inicializálása
    int *res = (int *)malloc(sizeof(int) * (size + enlarge));
    // Az eredeti tömb összes elemének másolása az új tömbbe
    for (int i = 0; i < size; i++) {
        res[i] = nums[i];
    }
    // A bővített terület inicializálása
    for (int i = size; i < size + enlarge; i++) {
        res[i] = 0;
    }
    // A bővített új tömb visszaadása
    return res;
}

/* A num elem beillesztése a tömb index indexű pozíciójába */
void insert(int *nums, int size, int num, int index) {
    // Az index pozíciótól kezdve minden elem eltolása egy pozícióval hátra
    for (int i = size - 1; i > index; i--) {
        nums[i] = nums[i - 1];
    }
    // A num értékének hozzárendelése az index indexű elemhez
    nums[index] = num;
}

/* Az index indexű elem törlése */
// Megjegyzés: a stdio.h foglalja a remove kulcsszót
void removeItem(int *nums, int size, int index) {
    // Az index pozíció utáni összes elem eltolása egy pozícióval előre
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

/* Vezérlő kód */
int main() {
    /* Tömb inicializálása */
    int size = 5;
    int arr[5];
    printf("Array arr = ");
    printArray(arr, size);

    int nums[] = {1, 3, 2, 5, 4};
    printf("Array nums = ");
    printArray(nums, size);

    /* Elem beillesztése */
    int randomNum = randomAccess(nums, size);
    printf("Get random element %d from nums", randomNum);

    /* Tömb bejárása */
    int enlarge = 3;
    int *res = extend(nums, size, enlarge);
    size += enlarge;
    printf("Extend array length to 8, resulting in nums = ");
    printArray(res, size);

    /* Elem beillesztése */
    insert(res, size, 6, 3);
    printf("Insert number 6 at index 3, resulting in nums = ");
    printArray(res, size);

    /* Elem törlése */
    removeItem(res, size, 2);
    printf("Remove element at index 2, resulting in nums = ");
    printArray(res, size);

    /* Tömb bejárása */
    traverse(res, size);

    /* Elem keresése */
    int index = find(res, size, 3);
    printf("Find element 3 in res, index = %d\n", index);

    /* Memória felszabadítása */
    free(res);
    return 0;
}
