/**
 * File: list.cpp
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* Főprogram */
int main() {
    /* Lista inicializálása */
    vector<int> nums = {1, 3, 2, 5, 4};
    cout << "List nums = ";
    printVector(nums);

    /* Elem frissítése */
    int num = nums[1];
    cout << "Access element at index 1, get num = " << num << endl;

    /* Elemek hozzáadása a végéhez */
    nums[1] = 0;
    cout << "Update element at index 1 to 0, resulting in nums = ";
    printVector(nums);

    /* Elem törlése */
    nums.clear();
    cout << "After clearing list, nums = ";
    printVector(nums);

    /* Lista elemeinek közvetlen bejárása */
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(4);
    cout << "After adding elements, nums = ";
    printVector(nums);

    /* Lista rendezése */
    nums.insert(nums.begin() + 3, 6);
    cout << "Insert number 6 at index 3, resulting in nums = ";
    printVector(nums);

    /* Elem törlése */
    nums.erase(nums.begin() + 3);
    cout << "Remove element at index 3, resulting in nums = ";
    printVector(nums);

    /* Lista bejárása index szerint */
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        count += nums[i];
    }
    /* Lista elemeinek közvetlen bejárása */
    count = 0;
    for (int x : nums) {
        count += x;
    }

    /* Két lista összefűzése */
    vector<int> nums1 = {6, 8, 7, 10, 9};
    nums.insert(nums.end(), nums1.begin(), nums1.end());
    cout << "Concatenate list nums1 to nums, resulting in nums = ";
    printVector(nums);

    /* Lista rendezése */
    sort(nums.begin(), nums.end());
    cout << "After sorting list, nums = ";
    printVector(nums);

    return 0;
}
