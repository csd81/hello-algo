# Hash Ütközés

Az előző szakaszban megemlítettük, hogy **a legtöbb esetben a hash függvény bemeneti tere sokkal nagyobb a kimeneti térnél**, ezért elméletileg a hash ütközések elkerülhetetlenek. Például, ha a bemeneti tér az összes egész szám, a kimeneti tér pedig a tömb kapacitásának mérete, akkor elkerülhetetlen, hogy több egész szám ugyanahhoz a vödörindexhez legyen rendelve.

A hash ütközések helytelen lekérdezési eredményekhez vezethetnek, ami komolyan rontja a hash tábla használhatóságát. E probléma kezelésére, ha hash ütközés lép fel, kibővíthetjük a hash táblát, amíg az ütközés el nem tűnik. Ez a megközelítés egyszerű, közvetlen és hatékony, de nagyon nem hatékony, mert a hash tábla bővítése nagy mennyiségű adatmigrációval és hash érték újraszámolással jár. A hatékonyság javítása érdekében a következő stratégiákat alkalmazhatjuk:

1. Javítsuk a hash tábla adatszerkezetét úgy, hogy **a hash tábla normálisan működhessen hash ütközések esetén is**.
2. Csak szükség esetén bővítsünk, azaz csak akkor, ha a hash ütközések súlyosak.

A hash táblák szerkezetének javítására szolgáló fő módszerek a „láncolás" és a „nyílt címzés".

## Láncolás

Az eredeti hash táblában minden vödör csak egy kulcs-érték párt tárolhat. A <u>láncolás</u> az egyetlen elemet láncolt listává alakítja, a kulcs-érték párokat láncolt lista csomópontokként kezeli, és az összes ütköző kulcs-érték párt ugyanabban a láncolt listában tárolja. Az alábbi ábra egy láncolást alkalmazó hash tábla példáját mutatja be.

![Láncolást alkalmazó hash tábla](hash_collision.assets/hash_table_chaining.png)

A láncolással megvalósított hash tábla műveletei a következőképpen változtak:

- **Elem lekérdezése**: Beadjuk a `key`-t, a hash függvénnyel megkapjuk a vödörindexet, majd hozzáférünk a láncolt lista fejcsomópontjához, bejárjuk a láncolt listát és összehasonlítjuk a `key`-t, hogy megtaláljuk a célul szolgáló kulcs-érték párt.
- **Elem hozzáadása**: Először a hash függvényen keresztül hozzáférünk a láncolt lista fejcsomópontjához, majd hozzáfűzzük a csomópontot (kulcs-érték párt) a láncolt listához.
- **Elem törlése**: A hash függvény eredménye alapján hozzáférünk a láncolt lista fejéhez, majd bejárjuk a láncolt listát, hogy megtaláljuk a célcsomópontot és töröljük azt.

A láncolásnak a következő korlátai vannak:

- **Megnövekedett tárhelyhasználat**: A láncolt lista csomópontmutatókat tartalmaz, amelyek több memóriaterületet foglalnak el, mint a tömbök.
- **Csökkent lekérdezési hatékonyság**: Ez azért van, mert a megfelelő elem megtalálásához lineáris bejárást kell végezni a láncolt listán.

Az alábbi kód egy egyszerű láncolást alkalmazó hash tábla megvalósítását adja meg, két fontos megjegyzéssel:

- Láncolt listák helyett listákat (dinamikus tömböket) használunk a kód egyszerűsítése érdekében. Ebben a beállításban a hash tábla (tömb) több vödröt tartalmaz, amelyek mindegyike egy lista.
- Ez a megvalósítás tartalmaz egy hash tábla bővítési módszert. Ha a terhelési tényező meghaladja a $\frac{2}{3}$-ot, az eredeti méret $2$-szeresére bővítjük a hash táblát.

```src
[file]{hash_map_chaining}-[class]{hash_map_chaining}-[func]{}
```

Megjegyzendő, hogy ha a láncolt lista nagyon hosszú, a lekérdezési hatékonyság $O(n)$ gyenge. **Ebben az esetben a lista „AVL fára" vagy „piros-fekete fára" konvertálható**, hogy a lekérdezési művelet időbonyolultságát $O(\log n)$-re optimalizáljuk.

## Nyílt Címzés

A <u>nyílt címzés</u> nem vezet be további adatszerkezeteket, hanem „többszörös próbálkozásokon" keresztül kezeli a hash ütközéseket. A próbálkozási módszerek főként a lineáris próbálkozást, a négyzetes próbálkozást és a kettős hashelést foglalják magukban.

Vegyük a lineáris próbálkozást példaként a nyílt címzést alkalmazó hash táblák mechanizmusának bemutatásához.

### Lineáris Próbálkozás

A lineáris próbálkozás rögzített lépésközű lineáris keresést alkalmaz a próbálkozáshoz, és működési módja eltér a hagyományos hash tábláktól.

- **Elemek beszúrása**: A hash függvénnyel kiszámítjuk a vödörindexet. Ha a vödör már tartalmaz elemet, lineárisan haladunk előre az ütközési pozíciótól (általában $1$-es lépésközzel) addig, amíg üres vödröt nem találunk, majd beszúrjuk az elemet.
- **Elemek keresése**: Ha hash ütközéssel találkozunk, ugyanolyan lépésközzel lineárisan haladunk előre, amíg meg nem találjuk a megfelelő elemet és visszaadja a `value` értéket; ha üres vödörrel találkozunk, ez azt jelenti, hogy a célelem nincs a hash táblában, ezért `None` értéket adunk vissza.

Az alábbi ábra a kulcs-érték párok eloszlását mutatja egy nyílt címzést (lineáris próbálkozást) alkalmazó hash táblában. E hash függvény szerint az azonos utolsó két számjeggyel rendelkező kulcsok ugyanabba a vödörbe kerülnek. A lineáris próbálkozás révén ezek sorban tárolódnak az adott vödörben és az alatta lévő vödrökben.

![Kulcs-érték párok eloszlása nyílt címzést (lineáris próbálkozást) alkalmazó hash táblában](hash_collision.assets/hash_table_linear_probing.png)

Azonban **a lineáris próbálkozás hajlamos „klaszteresedést" létrehozni**. Konkrétan, minél hosszabb a tömbben folyamatosan elfoglalt pozíciók sora, annál nagyobb a valószínűsége, hogy hash ütközések fordulnak elő ezeken a folyamatos pozíciókon, ami tovább serkenti a klaszter növekedését az adott pozícióban, ördögi kört alkotva, és végül a beszúrás, törlés, lekérdezés és frissítés műveletek hatékonyságának romlásához vezet.

Fontos megjegyezni, hogy **nem törölhetünk közvetlenül elemeket egy nyílt címzést alkalmazó hash táblában**. Egy elem törlése üres vödröt `None` hoz létre a tömbben. Elemek keresésekor, ha a lineáris próbálkozás ezt az üres vödröt találja, visszatér, és az e mögötti vödrökben lévő elemek elérhetetlenné válnak. A program tévesen azt feltételezheti, hogy ezek az elemek nem léteznek, ahogy az alábbi ábra mutatja.

![A nyílt címzésben törlés által okozott lekérdezési problémák](hash_collision.assets/hash_table_open_addressing_deletion.png)

E probléma megoldásához alkalmazhatjuk a <u>lusta törlés</u> mechanizmust: ahelyett, hogy közvetlenül eltávolítanánk az elemeket a hash táblából, **egy `TOMBSTONE` konstanssal jelöljük meg a vödröt**. Ebben a mechanizmusban mind a `None`, mind a `TOMBSTONE` üres vödröket jelöl és kulcs-érték párokat tárolhat. Azonban, ha a lineáris próbálkozás `TOMBSTONE`-ra bukkan, folytatnia kell a bejárást, mivel alatta még lehetnek kulcs-érték párok.

Azonban **a lusta törlés felgyorsíthatja a hash tábla teljesítményromlását**. Minden törlési művelet törlési jelölést hoz létre, és ahogy a `TOMBSTONE` számok nőnek, a keresési idő is növekedni fog, mivel a lineáris próbálkozásnak esetleg több `TOMBSTONE`-t kell kihagynia a célelem megtalálásához.

E probléma kezelésére érdemes megfontolni az első `TOMBSTONE` index rögzítését a lineáris próbálkozás során, és a keresett célelemet felcserélni ezzel a `TOMBSTONE`-nal. Ennek az az előnye, hogy minden egyes elem lekérdezésekor vagy hozzáadásakor az elem az ideális pozíciójához (a próbálkozás kiindulópontjához) közelebb lévő vödörbe kerül, ezáltal optimalizálva a lekérdezési hatékonyságot.

Az alábbi kód egy nyílt címzést (lineáris próbálkozást) és lusta törlést alkalmazó hash táblát valósít meg. A hash tábla terének jobb kihasználása érdekében a hash táblát „körkörös tömbként" kezeljük. Ha a tömb végén túlmegyünk, visszatérünk az elejéhez és folytatjuk a bejárást.

```src
[file]{hash_map_open_addressing}-[class]{hash_map_open_addressing}-[func]{}
```

### Négyzetes Próbálkozás

A négyzetes próbálkozás hasonló a lineáris próbálkozáshoz, és a nyílt címzés egyik gyakori stratégiája. Ütközés esetén a négyzetes próbálkozás nem egyszerűen rögzített számú lépést ugrik, hanem „a próbálkozások számának négyzetével" egyenlő számú lépést ugrik, azaz $1, 4, 9, \dots$ lépést.

A négyzetes próbálkozásnak a következő előnyei vannak:

- A négyzetes próbálkozás a próbálkozások számának négyzetével egyenlő távolságok kihagyásával igyekszik enyhíteni a lineáris próbálkozás klaszteresedési hatását.
- A négyzetes próbálkozás nagyobb távolságokat ugrik az üres pozíciók megtalálásához, ami segít az adatok egyenletesebb elosztásában.

A négyzetes próbálkozás azonban nem tökéletes:

- Klaszteresedés még mindig létezik, azaz egyes pozíciók nagyobb valószínűséggel foglaltak, mint mások.
- A négyzetek növekedése miatt a négyzetes próbálkozás esetleg nem tudja bejárni az egész hash táblát, ami azt jelenti, hogy még ha vannak is üres vödrök a hash táblában, a négyzetes próbálkozás esetleg nem fér hozzájuk.

### Kettős Hashelés

Ahogy a neve is mutatja, a kettős hashelés módszer több hash függvényt $f_1(x)$, $f_2(x)$, $f_3(x)$, $\dots$ használ a próbálkozáshoz.

- **Elemek beszúrása**: Ha a $f_1(x)$ hash függvény ütközést észlel, próbáljuk meg a $f_2(x)$-et, és így tovább, amíg üres pozíciót nem találunk és be nem szúrjuk az elemet.
- **Elemek keresése**: Keresünk a hash függvények ugyanolyan sorrendjében, amíg meg nem találjuk a célelemet és vissza nem adjuk; ha üres pozícióval találkozunk, vagy az összes hash függvényt kipróbáltuk, ez azt jelzi, hogy az elem nincs a hash táblában, ekkor `None` értéket adunk vissza.

A lineáris próbálkozáshoz képest a kettős hashelés módszer kevésbé hajlamos klaszteresedésre, de a több hash függvény további számítási terhelést vezet be.

!!! tip

    Kérjük, vegye figyelembe, hogy a nyílt címzést (lineáris próbálkozás, négyzetes próbálkozás és kettős hashelés) alkalmazó hash táblák mind rendelkeznek azzal a problémával, hogy „nem lehet közvetlenül elemeket törölni".

## Programozási Nyelvek Választása

A különböző programozási nyelvek eltérő hash tábla megvalósítási stratégiákat alkalmaznak. Íme néhány példa:

- A Python nyílt címzést alkalmaz. A `dict` szótár pszeudo-véletlenszámokat használ a próbálkozáshoz.
- A Java láncolást alkalmaz. A JDK 1.8 óta, ha a `HashMap`-ben a tömb hossza eléri a 64-et és egy láncolt lista hossza eléri a 8-at, a láncolt lista piros-fekete fává alakul a keresési teljesítmény javítása érdekében.
- A Go láncolást alkalmaz. A Go előírja, hogy minden vödör legfeljebb 8 kulcs-érték párt tárolhat, és ha a kapacitás túllépésre kerül, egy túlcsordulási vödröt láncolunk hozzá; ha túl sok a túlcsordulási vödör, egy speciális azonos kapacitású bővítési műveletet hajtanak végre a teljesítmény biztosítása érdekében.
