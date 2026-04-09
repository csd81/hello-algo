/**
 * File: time_complexity.c
 * Created Time: 2023-01-03
 * Author: codingonion (coderonion@gmail.com)
 */

#include "../utils/common.h"

/* Konstans rend */
int constant(int n) {
    int count = 0;
    int size = 100000;
    int i = 0;
    for (int i = 0; i < size; i++) {
        count++;
    }
    return count;
}

/* Lineáris rend */
int linear(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
    }
    return count;
}

/* Lineáris rend (tömb bejárása) */
int arrayTraversal(int *nums, int n) {
    int count = 0;
    // Az iterációk száma arányos a tömb hosszával
    for (int i = 0; i < n; i++) {
        count++;
    }
    return count;
}

/* Exponenciális rend */
int quadratic(int n) {
    int count = 0;
    // Az iterációk száma négyzetes összefüggésben van az n adatmérettel
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count++;
        }
    }
    return count;
}

/* Négyzetes rend (buborékrendezés) */
int bubbleSort(int *nums, int n) {
    int count = 0; // Számláló
    // Külső ciklus: a rendezetlen tartomány [0, i]
    for (int i = n - 1; i > 0; i--) {
        // Belső ciklus: a legnagyobb elemet a rendezetlen [0, i] tartomány jobb végére csere
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j + 1]) {
                // nums[j] és nums[j + 1] felcserélése
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
                count += 3; // Az elemcsere 3 egységnyi műveletet tartalmaz
            }
        }
    }
    return count;
}

/* Exponenciális rend (ciklus megvalósítás) */
int exponential(int n) {
    int count = 0;
    int bas = 1;
    // A sejtek minden körben kettéoszlanak, alkotva az 1, 2, 4, 8, ..., 2^(n-1) sorozatot
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bas; j++) {
            count++;
        }
        bas *= 2;
    }
    // count = 1 + 2 + 4 + 8 + .. + 2^(n-1) = 2^n - 1
    return count;
}

/* Exponenciális rend (rekurzív megvalósítás) */
int expRecur(int n) {
    if (n == 1)
        return 1;
    return expRecur(n - 1) + expRecur(n - 1) + 1;
}

/* Logaritmikus rend (ciklus megvalósítás) */
int logarithmic(int n) {
    int count = 0;
    while (n > 1) {
        n = n / 2;
        count++;
    }
    return count;
}

/* Logaritmikus rend (rekurzív megvalósítás) */
int logRecur(int n) {
    if (n <= 1)
        return 0;
    return logRecur(n / 2) + 1;
}

/* Lineáris-logaritmikus rend */
int linearLogRecur(int n) {
    if (n <= 1)
        return 1;
    int count = linearLogRecur(n / 2) + linearLogRecur(n / 2);
    for (int i = 0; i < n; i++) {
        count++;
    }
    return count;
}

/* Faktoriális rend (rekurzív megvalósítás) */
int factorialRecur(int n) {
    if (n == 0)
        return 1;
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += factorialRecur(n - 1);
    }
    return count;
}

/* Vezérlő kód */
int main(int argc, char *argv[]) {
    // Az n módosításával futtathatja és megfigyelheti a különböző bonyolultságú műveletek számának trendjét
    int n = 8;
    printf("Input data size n = %d\n", n);

    int count = constant(n);
    printf("Constant-time operations count = %d\n", count);

    count = linear(n);
    printf("Linear-time operations count = %d\n", count);
    // Halommemória foglalása (1D változó hosszú tömb létrehozása: n db int típusú elem)
    int *nums = (int *)malloc(n * sizeof(int));
    count = arrayTraversal(nums, n);
    printf("Linear-time (array traversal) operations count = %d\n", count);

    count = quadratic(n);
    printf("Quadratic-time operations count = %d\n", count);
    for (int i = 0; i < n; i++) {
        nums[i] = n - i; // [n,n-1,...,2,1]
    }
    count = bubbleSort(nums, n);
    printf("Quadratic-time (bubble sort) operations count = %d\n", count);

    count = exponential(n);
    printf("Exponential-time (iterative) operations count = %d\n", count);
    count = expRecur(n);
    printf("Exponential-time (recursive) operations count = %d\n", count);

    count = logarithmic(n);
    printf("Logarithmic-time (iterative) operations count = %d\n", count);
    count = logRecur(n);
    printf("Logarithmic-time (recursive) operations count = %d\n", count);

    count = linearLogRecur(n);
    printf("Linearithmic-time (recursive) operations count = %d\n", count);

    count = factorialRecur(n);
    printf("Factorial-time (recursive) operations count = %d\n", count);

    // Halommemória felszabadítása
    if (nums != NULL) {
        free(nums);
        nums = NULL;
    }
    getchar();

    return 0;
}
