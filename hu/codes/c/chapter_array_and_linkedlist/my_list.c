/**
 * File: my_list.c
 * Created Time: 2023-01-12
 * Author: Zero (glj0@outlook.com)
 */

#include "../utils/common.h"

/* Lista osztály */
typedef struct {
    int *arr;        // Tömb (lista elemeit tárolja)
    int capacity;    // Lista kapacitása
    int size;        // Lista mérete
    int extendRatio; // Lista bővítési szorzója
} MyList;

void extendCapacity(MyList *nums);

/* Konstruktor */
MyList *newMyList() {
    MyList *nums = malloc(sizeof(MyList));
    nums->capacity = 10;
    nums->arr = malloc(sizeof(int) * nums->capacity);
    nums->size = 0;
    nums->extendRatio = 2;
    return nums;
}

/* Destruktor */
void delMyList(MyList *nums) {
    free(nums->arr);
    free(nums);
}

/* Lista hosszának lekérdezése */
int size(MyList *nums) {
    return nums->size;
}

/* Lista kapacitásának lekérdezése */
int capacity(MyList *nums) {
    return nums->capacity;
}

/* Elem frissítése */
int get(MyList *nums, int index) {
    assert(index >= 0 && index < nums->size);
    return nums->arr[index];
}

/* Elem hozzáadása a lista végéhez */
void set(MyList *nums, int index, int num) {
    assert(index >= 0 && index < nums->size);
    nums->arr[index] = num;
}

/* Lista elemeinek közvetlen bejárása */
void add(MyList *nums, int num) {
    if (size(nums) == capacity(nums)) {
        extendCapacity(nums); // Kapacitás bővítése
    }
    nums->arr[size(nums)] = num;
    nums->size++;
}

/* Lista rendezése */
void insert(MyList *nums, int index, int num) {
    assert(index >= 0 && index < size(nums));
    // Ha az elemek száma eléri a kapacitást, a bővítési mechanizmus aktiválódik
    if (size(nums) == capacity(nums)) {
        extendCapacity(nums); // Kapacitás bővítése
    }
    for (int i = size(nums); i > index; --i) {
        nums->arr[i] = nums->arr[i - 1];
    }
    nums->arr[index] = num;
    nums->size++;
}

/* Elem törlése */
// Megjegyzés: a stdio.h foglalja a remove kulcsszót
int removeItem(MyList *nums, int index) {
    assert(index >= 0 && index < size(nums));
    int num = nums->arr[index];
    for (int i = index; i < size(nums) - 1; i++) {
        nums->arr[i] = nums->arr[i + 1];
    }
    nums->size--;
    return num;
}

/* Vezérlő kód */
void extendCapacity(MyList *nums) {
    // Először helyet foglalunk
    int newCapacity = capacity(nums) * nums->extendRatio;
    int *extend = (int *)malloc(sizeof(int) * newCapacity);
    int *temp = nums->arr;

    // A régi adatok másolása az új helyre
    for (int i = 0; i < size(nums); i++)
        extend[i] = nums->arr[i];

    // A régi adatok felszabadítása
    free(temp);

    // Az új adatok frissítése
    nums->arr = extend;
    nums->capacity = newCapacity;
}

/* Lista konvertálása tömbbé nyomtatáshoz */
int *toArray(MyList *nums) {
    return nums->arr;
}

/* Vezérlő kód */
int main() {
    /* Lista inicializálása */
    MyList *nums = newMyList();
    /* Lista elemeinek közvetlen bejárása */
    add(nums, 1);
    add(nums, 3);
    add(nums, 2);
    add(nums, 5);
    add(nums, 4);
    printf("List nums = ");
    printArray(toArray(nums), size(nums));
    printf("Capacity = %d, Length = %d\n", capacity(nums), size(nums));

    /* Lista rendezése */
    insert(nums, 3, 6);
    printf("Insert number 6 at index 3, resulting in nums = ");
    printArray(toArray(nums), size(nums));

    /* Elem törlése */
    removeItem(nums, 3);
    printf("Remove element at index 3, resulting in nums = ");
    printArray(toArray(nums), size(nums));

    /* Elem frissítése */
    int num = get(nums, 1);
    printf("Access element at index 1, get num = %d\n", num);

    /* Elem hozzáadása a lista végéhez */
    set(nums, 1, 0);
    printf("Update element at index 1 to 0, resulting in nums = ");
    printArray(toArray(nums), size(nums));

    /* Kapacitásbővítési mechanizmus tesztelése */
    for (int i = 0; i < 10; i++) {
        // i = 5-nél a lista hossza meghaladja a kapacitást, a bővítési mechanizmus aktiválódik
        add(nums, i);
    }

    printf("List nums after expansion = ");
    printArray(toArray(nums), size(nums));
    printf("Capacity = %d, Length = %d\n", capacity(nums), size(nums));

    /* A lefoglalt memória felszabadítása */
    delMyList(nums);

    return 0;
}
