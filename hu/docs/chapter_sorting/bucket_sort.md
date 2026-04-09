# Vödörrendezés

A korábban említett rendezési algoritmusok mind "összehasonlítás alapú rendezési algoritmusok", amelyek elemek méretének összehasonlításával érik el a rendezést. Az ilyen rendezési algoritmusok időbonyolultsága nem haladhatja meg az $O(n \log n)$-t. A következőkben több "nem összehasonlítás alapú rendezési algoritmust" ismerünk meg, amelyek időbonyolultsága elérheti a lineáris rendet.

A <u>vödörrendezés (bucket sort)</u> az oszd meg és uralkodj stratégia tipikus alkalmazása. Méret szerint rendezett vödröket állít fel, minden vödör egy adattartománynak felel meg, az adatokat egyenletesen elosztja az egyes vödrökbe; ezután minden vödrön belül külön rendezi az adatokat; végül a vödrök sorrendjében összefésüli az összes adatot.

## Az algoritmus folyamata

Tekintsünk egy $n$ hosszúságú tömböt, amelynek elemei a $[0, 1)$ tartományba eső lebegőpontos számok. A vödörrendezés folyamata az alábbi ábrán látható.

1. Inicializálunk $k$ vödröt, és elosztjuk az $n$ elemet a $k$ vödörbe.
2. Minden vödröt külön rendezünk (itt a programozási nyelv beépített rendezési függvényét használjuk).
3. A legkisebbtől a legnagyobb vödrig sorban összefésüljük az eredményeket.

![Vödörrendezés algoritmusfolyamata](bucket_sort.assets/bucket_sort_overview.png)

A kód az alábbi:

```src
[file]{bucket_sort}-[class]{}-[func]{bucket_sort}
```

## Az algoritmus jellemzői

A vödörrendezés nagyon nagy adatmennyiség feldolgozásához alkalmas. Például, ha a bemeneti adatok 1 millió elemet tartalmaznak, és a rendszer memóriája nem képes egyszerre betölteni az összes adatot, az adatok feloszthatók 1000 vödörbe, minden vödör külön rendezhető, majd az eredmények összefésülhetők.

- **$O(n + k)$ időbonyolultság**: Feltéve, hogy az elemek egyenletesen oszlanak el a vödrök között, akkor az egyes vödrökben lévő elemek száma $\frac{n}{k}$. Feltéve, hogy egyetlen vödör rendezése $O(\frac{n}{k} \log\frac{n}{k})$ időt vesz igénybe, akkor az összes vödör rendezése $O(n \log\frac{n}{k})$ időt vesz igénybe. **Ha a vödrök $k$ száma viszonylag nagy, az időbonyolultság megközelíti az $O(n)$-t**. Az eredmények összefésülése az összes vödör és elem bejárását igényli, ami $O(n + k)$ időt vesz igénybe. A legrosszabb esetben az összes adat egy vödörbe kerül, és az adott vödör rendezése $O(n^2)$ időt vesz igénybe.
- **$O(n + k)$ térkomplexitás, nem helyben történő rendezés**: Extra tárhelyre van szükség $k$ vödörhöz és összesen $n$ elemhez.
- A vödörrendezés stabilitása attól függ, hogy a vödörökön belüli elemek rendezéséhez használt algoritmus stabil-e.

## Hogyan érhető el az egyenletes elosztás?

Elméletileg a vödörrendezés $O(n)$ időbonyolultságot érhet el. **A kulcs az elemek egyenletes elosztása az egyes vödrökbe**, mivel a valós adatok általában nem egyenletesen oszlanak el. Például, ha az összes Taobao terméket ártartomány szerint 10 vödörbe szeretnénk egyenletesen elosztani, nagyon sok termék lehet 100 yuan alatt, és nagyon kevés 1000 yuan felett. Ha az árintervallumokat egyenletesen osztjuk fel 10 részre, az egyes vödrökben lévő termékek számának különbsége nagyon nagy lesz.

Az egyenletes elosztás eléréséhez először beállíthatunk egy közelítő elválasztóvonalat az adatok három vödörbe való durva felosztásához. **Az elosztás befejezése után folytassuk a több terméket tartalmazó vödrök felosztását 3 vödörre, amíg az összes vödörben lévő elemek száma nagyjából egyenlő nem lesz**.

Az alábbi ábrán látható módon ez a módszer lényegében egy rekurziós fát hoz létre, azzal a céllal, hogy a levélcsomópontok értékei minél egyenletesebbek legyenek. Természetesen nem szükséges minden körben 3 vödörre osztani az adatokat; a konkrét felosztási módszer az adatok jellemzői szerint rugalmasan választható meg.

![Vödrök rekurzív felosztása](bucket_sort.assets/scatter_in_buckets_recursively.png)

Ha előre ismerjük a termékárak valószínűségi eloszlását, **minden vödörhez beállíthatjuk az árfelosztóvonalat az adatok valószínűségi eloszlása alapján**. Megjegyzendő, hogy az adateloszlást nem feltétlenül kell kifejezetten kiszámítani, hanem az adatok jellemzői alapján egy bizonyos valószínűségi modellel is közelíthető.

Az alábbi ábrán látható módon feltételezzük, hogy a termékárak normál eloszlást követnek, ami lehetővé teszi számunkra, hogy ésszerű árintervalumokat állítsunk be a termékek egyenletes elosztásához az egyes vödrökbe.

![Vödrök felosztása valószínűségi eloszlás alapján](bucket_sort.assets/scatter_in_buckets_distribution.png)
