# Bináris keresés határesetek

## A bal határ megkeresése

!!! question

    Adott egy rendezett `nums` tömb, amelynek hossza $n$, és amely ismétlődő elemeket is tartalmazhat. Adja vissza a `target` elem legbaloldalibb előfordulásának indexét a tömbben. Ha a tömb nem tartalmazza az elemet, adjon vissza $-1$-et.

Emlékezzünk vissza a bináris keresés beillesztési pontjának megtalálási módszerére. A keresés befejezése után $i$ a legbaloldalibb `target` elemre mutat, **tehát a beillesztési pont megkeresése lényegében a legbaloldalibb `target` indexének megkeresése**.

Valósítsuk meg a bal határ keresést a beillesztési pont megtalálási függvény segítségével. Figyeljük meg, hogy a tömb nem feltétlenül tartalmazza a `target` elemet, ami a következő két esetet eredményezheti:

- A beillesztési pont $i$ indexe kívül esik a határon.
- A `nums[i]` elem nem egyenlő a `target` értékkel.

Ha ezen helyzetek valamelyike fennáll, egyszerűen adjunk vissza $-1$-et. A kód az alábbiakban látható:

```src
[file]{binary_search_edge}-[class]{}-[func]{binary_search_left_edge}
```

## A jobb határ megkeresése

Hogyan keressük meg a legjobboldalibb `target` elemet? A legközvetlenebb megközelítés a kód módosítása és a mutatócsökkentési művelet cseréje a `nums[m] == target` esetben. A kód itt kimarad; az érdeklődő olvasók maguk is megvalósíthatják.

Az alábbiakban két ennél elegánsabb módszert mutatunk be.

### A bal határ keresésének újrahasznosítása

Valójában a legbaloldalibb elem megkereséséhez használt függvény felhasználható a legjobboldalibb elem megkeresésére is. A konkrét módszer: **a legjobboldalibb `target` keresését alakítsuk át a legbaloldalibb `target + 1` keresésévé**.

Ahogy az alábbi ábra mutatja, a keresés befejezése után az $i$ mutató a legbaloldalibb `target + 1` elemre mutat (ha létezik), míg a $j$ mutató a legjobboldalibb `target` elemre mutat, **tehát egyszerűen a $j$ értékét adjuk vissza**.

![A jobb határ keresésének átalakítása bal határ kereséssé](binary_search_edge.assets/binary_search_right_edge_by_left_edge.png)

Figyeljük meg, hogy a visszaadott beillesztési pont $i$, ezért $1$-et kell kivonni belőle a $j$ megszerzéséhez:

```src
[file]{binary_search_edge}-[class]{}-[func]{binary_search_right_edge}
```

### Átalakítás elemeléréssé

Tudjuk, hogy ha a tömb nem tartalmazza a `target` elemet, az $i$ és $j$ mutatók végül az első `target`-nél nagyobb, illetve kisebb elemekre mutatnak.

Ezért, ahogy az alábbi ábra mutatja, létrehozhatunk egy olyan elemet, amely nem létezik a tömbben, hogy megtaláljuk a bal és jobb határokat.

- A legbaloldalibb `target` megkeresése: Átalakítható `target - 0.5` keresésévé, és az $i$ mutató visszaadásával.
- A legjobboldalibb `target` megkeresése: Átalakítható `target + 0.5` keresésévé, és a $j$ mutató visszaadásával.

![A határkeresés átalakítása elemeléréssé](binary_search_edge.assets/binary_search_edge_by_element.png)

A kód itt kimarad, de a következő két pontot érdemes megjegyezni:

- Mivel az adott tömb nem tartalmaz tizedes törteket, nem kell aggódnunk az egyenlő esetek kezelése miatt.
- Mivel ez a módszer tizedes törteket vezet be, a `target` változót a függvényben lebegőpontos típusra kell változtatni (Python esetén ez a változtatás nem szükséges).
