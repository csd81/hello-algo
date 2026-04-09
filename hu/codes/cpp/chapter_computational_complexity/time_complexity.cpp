/**
 * File: time_complexity.cpp
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* Konstans rend */
int constant(int n) {
    int count = 0;
    int size = 100000;
    for (int i = 0; i < size; i++)
        count++;
    return count;
}

/* Lineáris rend */
int linear(int n) {
    int count = 0;
    for (int i = 0; i < n; i++)
        count++;
    return count;
}

/* Lineáris rend (tömb bejárása) */
int arrayTraversal(vector<int> &nums) {
    int count = 0;
    // Az iterációk száma arányos a tömb hosszával
    for (int num : nums) {
        count++;
    }
    return count;
}

/* Négyzetes rend */
int quadratic(int n) {
    int count = 0;
    // Az iterációk száma négyzetesen függ az n adatmérettől
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count++;
        }
    }
    return count;
}

/* Négyzetes rend (buborékrendezés) */
int bubbleSort(vector<int> &nums) {
    int count = 0; // Számláló
    // Külső ciklus: a rendezetlen tartomány [0, i]
    for (int i = nums.size() - 1; i > 0; i--) {
        // Belső ciklus: a [0, i] rendezetlen tartomány legnagyobb elemének a jobb szélére cserélése
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j + 1]) {
                // nums[j] és nums[j + 1] felcserélése
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
                count += 3; // Elemcsere 3 egységnyi műveletet tartalmaz
            }
        }
    }
    return count;
}

/* Exponenciális rend (ciklus implementáció) */
int exponential(int n) {
    int count = 0, base = 1;
    // A sejtek minden körben kettéosztódnak, 1, 2, 4, 8, ..., 2^(n-1) sorozatot alkotva
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < base; j++) {
            count++;
        }
        base *= 2;
    }
    // count = 1 + 2 + 4 + 8 + .. + 2^(n-1) = 2^n - 1
    return count;
}

/* Exponenciális rend (rekurzív implementáció) */
int expRecur(int n) {
    if (n == 1)
        return 1;
    return expRecur(n - 1) + expRecur(n - 1) + 1;
}

/* Logaritmikus rend (ciklus implementáció) */
int logarithmic(int n) {
    int count = 0;
    while (n > 1) {
        n = n / 2;
        count++;
    }
    return count;
}

/* Logaritmikus rend (rekurzív implementáció) */
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

/* Faktoriális rend (rekurzív implementáció) */
int factorialRecur(int n) {
    if (n == 0)
        return 1;
    int count = 0;
    // 1-ről n-re osztódik szét
    for (int i = 0; i < n; i++) {
        count += factorialRecur(n - 1);
    }
    return count;
}

/* Főprogram */
int main() {
    // Az n módosításával futtatható és megfigyelhető a műveletek számának trendje különböző bonyolultságok esetén
    int n = 8;
    cout << "Input data size n = " << n << endl;

    int count = constant(n);
    cout << "Constant order operation count = " << count << endl;

    count = linear(n);
    cout << "Linear order operation count = " << count << endl;
    vector<int> arr(n);
    count = arrayTraversal(arr);
    cout << "Linear order (array traversal) operation count = " << count << endl;

    count = quadratic(n);
    cout << "Quadratic order operation count = " << count << endl;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        nums[i] = n - i; // [n,n-1,...,2,1]
    count = bubbleSort(nums);
    cout << "Quadratic order (bubble sort) operation count = " << count << endl;

    count = exponential(n);
    cout << "Exponential order (loop implementation) operation count = " << count << endl;
    count = expRecur(n);
    cout << "Exponential order (recursive implementation) operation count = " << count << endl;

    count = logarithmic(n);
    cout << "Logarithmic order (loop implementation) operation count = " << count << endl;
    count = logRecur(n);
    cout << "Logarithmic order (recursive implementation) operation count = " << count << endl;

    count = linearLogRecur(n);
    cout << "Linearithmic order (recursive implementation) operation count = " << count << endl;

    count = factorialRecur(n);
    cout << "Factorial order (recursive implementation) operation count = " << count << endl;

    return 0;
}
