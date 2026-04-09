"""
File: time_complexity.py
Created Time: 2022-11-25
Author: krahets (krahets@163.com)
"""


def constant(n: int) -> int:
    """Konstans rend"""
    count = 0
    size = 100000
    for _ in range(size):
        count += 1
    return count


def linear(n: int) -> int:
    """Lineáris rend"""
    count = 0
    for _ in range(n):
        count += 1
    return count


def array_traversal(nums: list[int]) -> int:
    """Lineáris rend (tömb bejárása)"""
    count = 0
    # Az iterációk száma arányos a tömb hosszával
    for num in nums:
        count += 1
    return count


def quadratic(n: int) -> int:
    """Négyzetes rend"""
    count = 0
    # Az iterációk száma négyzetesen függ az n adatmérettől
    for i in range(n):
        for j in range(n):
            count += 1
    return count


def bubble_sort(nums: list[int]) -> int:
    """Négyzetes rend (buborékrendezés)"""
    count = 0  # Számláló
    # Külső ciklus: a rendezetlen tartomány [0, i]
    for i in range(len(nums) - 1, 0, -1):
        # Belső ciklus: a rendezetlen [0, i] tartomány legnagyobb elemét a tartomány jobb végére csere
        for j in range(i):
            if nums[j] > nums[j + 1]:
                # nums[j] és nums[j + 1] felcserélése
                tmp: int = nums[j]
                nums[j] = nums[j + 1]
                nums[j + 1] = tmp
                count += 3  # Az elemcsere 3 alap műveletet tartalmaz
    return count


def exponential(n: int) -> int:
    """Exponenciális rend (ciklusos megvalósítás)"""
    count = 0
    base = 1
    # A sejtek minden körben kettéosztódnak, így az 1, 2, 4, 8, ..., 2^(n-1) sorozatot alkotják
    for _ in range(n):
        for _ in range(base):
            count += 1
        base *= 2
    # count = 1 + 2 + 4 + 8 + .. + 2^(n-1) = 2^n - 1
    return count


def exp_recur(n: int) -> int:
    """Exponenciális rend (rekurzív megvalósítás)"""
    if n == 1:
        return 1
    return exp_recur(n - 1) + exp_recur(n - 1) + 1


def logarithmic(n: int) -> int:
    """Logaritmikus rend (ciklusos megvalósítás)"""
    count = 0
    while n > 1:
        n = n / 2
        count += 1
    return count


def log_recur(n: int) -> int:
    """Logaritmikus rend (rekurzív megvalósítás)"""
    if n <= 1:
        return 0
    return log_recur(n / 2) + 1


def linear_log_recur(n: int) -> int:
    """Lineáris-logaritmikus rend"""
    if n <= 1:
        return 1
    # Kettéosztás: a részproblémák mérete felére csökken
    count = linear_log_recur(n // 2) + linear_log_recur(n // 2)
    # Az aktuális részprobléma n műveletet tartalmaz
    for _ in range(n):
        count += 1
    return count


def factorial_recur(n: int) -> int:
    """Faktoriális rend (rekurzív megvalósítás)"""
    if n == 0:
        return 1
    count = 0
    # 1-ből n-be osztás
    for _ in range(n):
        count += factorial_recur(n - 1)
    return count


"""Fő kód"""
if __name__ == "__main__":
    # Az n módosításával futtathatja és megfigyelheti a különböző bonyolultságú műveletek számának trendjét
    n = 8
    print("Bemeneti adatméret n =", n)

    count = constant(n)
    print("Konstans rendű műveletek száma =", count)

    count = linear(n)
    print("Lineáris rendű műveletek száma =", count)
    count = array_traversal([0] * n)
    print("Lineáris rendű műveletek száma (tömb bejárása) =", count)

    count = quadratic(n)
    print("Négyzetes rendű műveletek száma =", count)
    nums = [i for i in range(n, 0, -1)]  # [n, n-1, ..., 2, 1]
    count = bubble_sort(nums)
    print("Négyzetes rendű műveletek száma (buborékrendezés) =", count)

    count = exponential(n)
    print("Exponenciális rendű műveletek száma (ciklusos megvalósítás) =", count)
    count = exp_recur(n)
    print("Exponenciális rendű műveletek száma (rekurzív megvalósítás) =", count)

    count = logarithmic(n)
    print("Logaritmikus rendű műveletek száma (ciklusos megvalósítás) =", count)
    count = log_recur(n)
    print("Logaritmikus rendű műveletek száma (rekurzív megvalósítás) =", count)

    count = linear_log_recur(n)
    print("Lineáris-logaritmikus rendű műveletek száma (rekurzív megvalósítás) =", count)

    count = factorial_recur(n)
    print("Faktoriális rendű műveletek száma (rekurzív megvalósítás) =", count)
