"""
File: hash_map.py
Created Time: 2022-12-14
Author: msk397 (machangxinq@gmail.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import print_dict

"""Fő kód"""
if __name__ == "__main__":
    # Hash tábla inicializálása
    hmap = dict[int, str]()

    # Hozzáadás
    # Kulcs-érték pár (kulcs, érték) hozzáadása a hash táblához
    hmap[12836] = "Xiao Ha"
    hmap[15937] = "Xiao Luo"
    hmap[16750] = "Xiao Suan"
    hmap[13276] = "Xiao Fa"
    hmap[10583] = "Xiao Ya"
    print("\nHozzáadás után a hash tábla:\nKulcs -> Érték")
    print_dict(hmap)

    # Lekérdezés
    # Kulcs beírása a hash táblába az érték lekérdezéséhez
    name: str = hmap[15937]
    print("\nA 15937-es diákigazolvány alapján a név: " + name)

    # Törlés
    # Kulcs-érték pár (kulcs, érték) törlése a hash táblából
    hmap.pop(10583)
    print("\nA 10583-as törlése után a hash tábla:\nKulcs -> Érték")
    print_dict(hmap)

    # Hash tábla bejárása
    print("\nKulcs-érték párok bejárása Kulcs->Érték")
    for key, value in hmap.items():
        print(key, "->", value)

    print("\nCsak kulcsok bejárása")
    for key in hmap.keys():
        print(key)

    print("\nCsak értékek bejárása")
    for val in hmap.values():
        print(val)
