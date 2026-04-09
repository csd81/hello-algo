"""
File: simple_hash.py
Created Time: 2023-06-15
Author: krahets (krahets@163.com)
"""


def add_hash(key: str) -> int:
    """Additív hash"""
    hash = 0
    modulus = 1000000007
    for c in key:
        hash += ord(c)
    return hash % modulus


def mul_hash(key: str) -> int:
    """Multiplikatív hash"""
    hash = 0
    modulus = 1000000007
    for c in key:
        hash = 31 * hash + ord(c)
    return hash % modulus


def xor_hash(key: str) -> int:
    """XOR hash"""
    hash = 0
    modulus = 1000000007
    for c in key:
        hash ^= ord(c)
    return hash % modulus


def rot_hash(key: str) -> int:
    """Rotációs hash"""
    hash = 0
    modulus = 1000000007
    for c in key:
        hash = (hash << 4) ^ (hash >> 28) ^ ord(c)
    return hash % modulus


"""Fő kód"""
if __name__ == "__main__":
    key = "Hello algo"

    hash = add_hash(key)
    print(f"Az additív hash értéke: {hash}")

    hash = mul_hash(key)
    print(f"A multiplikatív hash értéke: {hash}")

    hash = xor_hash(key)
    print(f"Az XOR hash értéke: {hash}")

    hash = rot_hash(key)
    print(f"A rotációs hash értéke: {hash}")
