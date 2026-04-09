"""
File: list.py
Created Time: 2022-11-25
Author: krahets (krahets@163.com)
"""

"""Fő kód"""
if __name__ == "__main__":
    # Lista inicializálása
    nums: list[int] = [1, 3, 2, 5, 4]
    print("\nLista nums =", nums)

    # Elem elérése
    x: int = nums[1]
    print("\nAz 1-es indexű elem elérése, x =", x)

    # Elem frissítése
    nums[1] = 0
    print("\nAz 1-es indexű elem 0-ra frissítése után nums =", nums)

    # Lista törlése
    nums.clear()
    print("\nA lista törlése után nums =", nums)

    # Elemek hozzáadása a véghez
    nums.append(1)
    nums.append(3)
    nums.append(2)
    nums.append(5)
    nums.append(4)
    print("\nElemek hozzáadása után nums =", nums)

    # Elem beszúrása a közepére
    nums.insert(3, 6)
    print("\nA 6-os szám 3-as indexre szúrása után nums =", nums)

    # Elem törlése
    nums.pop(3)
    print("\nA 3-as indexű elem törlése után nums =", nums)

    # Lista bejárása index szerint
    count = 0
    for i in range(len(nums)):
        count += nums[i]
    # Lista elemeinek közvetlen bejárása
    for num in nums:
        count += num

    # Két lista összefűzése
    nums1 = [6, 8, 7, 10, 9]
    nums += nums1
    print("\nA nums1 lista hozzáfűzése a nums-hoz, nums =", nums)

    # Lista rendezése
    nums.sort()
    print("\nA lista rendezése után nums =", nums)
