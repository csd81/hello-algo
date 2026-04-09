# Rendezési algoritmus

<u>A rendezési algoritmus (sorting algorithm)</u> egy adatcsoport meghatározott sorrendbe rendezésére szolgál. A rendezési algoritmusoknak kiterjedt alkalmazásai vannak, mivel a rendezett adatokon általában hatékonyabban lehet keresni, elemezni és feldolgozni azokat.

Az alábbi ábrán látható módon a rendezési algoritmusokban szereplő adattípusok lehetnek egészek, lebegőpontos számok, karakterek vagy sztringek stb. A rendezési szempont igény szerint állítható be, például numerikus méret, karakterek ASCII-kód szerinti sorrendje vagy egyéni szabályok alapján.

![Adattípus és szempont példák](sorting_algorithm.assets/sorting_examples.png)

## Értékelési dimenziók

**Végrehajtási hatékonyság**: Elvárjuk, hogy a rendezési algoritmusok időbonyolultsága minél kisebb legyen, a műveletek teljes száma minél kevesebb legyen (csökkentve az időbonyolultság konstans tényezőjét). Nagy adatmennyiség esetén a végrehajtási hatékonyság különösen fontos.

**Helyben történő tulajdonság**: Ahogy a neve is sugallja, a <u>helyben történő rendezés (in-place sorting)</u> az eredeti tömbön közvetlenül végzett műveletekkel éri el a rendezést, anélkül hogy kiegészítő segédtömbökre lenne szüksége, ezáltal memóriát takarít meg. Általában a helyben történő rendezés kevesebb adatmozgatási műveletet tartalmaz és gyorsabban fut.

**Stabilitás**: A <u>stabil rendezés (stable sorting)</u> biztosítja, hogy az egyenlő elemek relatív sorrendje a tömbben a rendezés befejezése után sem változik.

A stabil rendezés szükséges feltétel a többszintű rendezési forgatókönyvekben. Tegyük fel, hogy van egy táblázatunk, amely hallgatók adatait tárolja, ahol az 1. és 2. oszlop a nevet, illetve az életkort tartalmazza. Ebben az esetben a <u>nem stabil rendezés (unstable sorting)</u> azt eredményezheti, hogy a bemeneti adatok rendezett jellege elveszik:

```shell
# A bemeneti adatok név szerint vannak rendezve
# (név, kor)
  ('A', 19)
  ('B', 18)
  ('C', 21)
  ('D', 19)
  ('E', 23)

# Tegyük fel, hogy nem stabil rendezési algoritmust alkalmazunk a lista kor szerinti rendezéséhez,
# Az eredményben a ('D', 19) és ('A', 19) relatív pozíciója megváltozik,
# és a bemeneti adatok névszerinti rendezettsége elvész
  ('B', 18)
  ('D', 19)
  ('A', 19)
  ('C', 21)
  ('E', 23)
```

**Alkalmazkodóképesség**: Az <u>adaptív rendezés (adaptive sorting)</u> képes felhasználni a bemeneti adatok meglévő sorrendinformációit a számítási mennyiség csökkentése érdekében, jobb időbeli hatékonyságot érve el. Az adaptív rendezési algoritmusok legjobb esetbeli időbonyolultsága általában jobb az átlagos időbonyolultságnál.

**Összehasonlítás alapú vagy sem**: Az <u>összehasonlítás alapú rendezés (comparison-based sorting)</u> összehasonlítási operátorokra ($<$, $=$, $>$) támaszkodik az elemek relatív sorrendjének meghatározásához, ezáltal rendezve a teljes tömböt, amelynek elméleti optimális időbonyolultsága $O(n \log n)$. A <u>nem összehasonlítás alapú rendezés (non-comparison sorting)</u> nem használ összehasonlítási operátorokat, és $O(n)$ időbonyolultságot képes elérni, de sokoldalúsága viszonylag korlátozott.

## Az ideális rendezési algoritmus

**Gyors végrehajtás, helyben történő, stabil, adaptív, jó sokoldalúság**. Egyértelmű, hogy mindeddig nem fedeztek fel olyan rendezési algoritmust, amely mindezeket a jellemzőket egyszerre ötvözi. Ezért rendezési algoritmus kiválasztásakor az adatok konkrét jellemzői és a feladat követelményei alapján kell dönteni.

A következőkben együtt tanuljuk meg a különböző rendezési algoritmusokat, és elemezzük az egyes rendezési algoritmusok előnyeit és hátrányait a fenti értékelési dimenziók alapján.
