# Összefoglalás

### Kulcsfontosságú Áttekintés

- A gráfok csúcsokból és élekből állnak, és csúcsok és élek halmazaként ábrázolhatók.
- A lineáris kapcsolatokhoz (láncolt listák) és az oszd meg és uralkodj kapcsolatokhoz (fák) képest a hálózati kapcsolatok (gráfok) magasabb fokú szabadsággal rendelkeznek, ezért összetettebbek.
- Az irányított gráfok élei iránnyal rendelkeznek, az összefüggő gráfokban bármely csúcsból minden más csúcs elérhető, a súlyozott gráfokban pedig minden él tartalmaz egy súlyváltozót.
- A szomszédsági mátrixok mátrixokkal ábrázolják a gráfokat, ahol minden sor (oszlop) egy csúcsot jelöl, a mátrix elemei pedig az éleket jelölik: $1$ vagy $0$ értékkel jelzik, hogy két csúcs között van-e él. A szomszédsági mátrixok hozzáadási, törlési, keresési és módosítási műveletek szempontjából rendkívül hatékonyak, de jelentős tárhelyet foglalnak.
- A szomszédsági listák több láncolt listával ábrázolják a gráfokat, ahol az $i$-edik láncolt lista az $i$-edik csúcsnak felel meg, és tárolja az adott csúcs összes szomszédját. A szomszédsági listák tárhelyhatékonyabbak a szomszédsági mátrixoknál, de az élek megtalálásához be kell járni a láncolt listákat, ezért kisebb az időbeli hatékonyságuk.
- Ha a szomszédsági listák láncolt listái túl hosszúvá válnak, vörös-fekete fákra vagy hash táblákra cserélhetők, ezzel javítva a keresési hatékonyságot.
- Algoritmikus szempontból a szomszédsági mátrix a „tér idő ellenében" elvét testesíti meg, míg a szomszédsági lista az „idő tér ellenében" elvét.
- A gráfok különféle valós rendszerek modellezésére alkalmazhatók, például közösségi hálók és metróvonalak esetén.
- A fák a gráfok speciális esetei, a fabejárás pedig a gráfbejárás speciális esete.
- A gráfok szélességi bejárása (BFS) egy közelitől távoliig, rétegről rétegre bővülő keresési módszer, amelyet általában sorral valósítanak meg.
- A gráfok mélységi bejárása (DFS) olyan keresési módszer, amely az elérhető legmélyebb pontig halad, majd visszalép, ha nincs tovább vezető út; általában rekurzióval valósítják meg.

### Kérdések és Válaszok

**K**: Az út csúcsok sorozataként vagy élek sorozataként van meghatározva?

A Wikipedia különböző nyelvű verzióiban az értelmezések eltérnek: az angol változat szerint „az út élek sorozata", míg a kínai verzió szerint „az út csúcsok sorozata". Az eredeti angol szöveg: In graph theory, a path in a graph is a finite or infinite sequence of edges which joins a sequence of vertices.

Ebben a szövegben az utat élek sorozataként értelmezzük, nem csúcsok sorozataként. Ennek oka, hogy két csúcs között több él is húzódhat, és ilyenkor minden él egy-egy útnak felel meg.

**K**: Egy nem összefüggő gráfban lesznek-e elérhetetlen csúcsok?

Egy nem összefüggő gráfban egy adott csúcsból kiindulva legalább egy csúcs nem érhető el. Egy nem összefüggő gráf bejárásához több kiindulópontot kell megadni, hogy a gráf összes összefüggő komponensét be lehessen járni.

**K**: A szomszédsági listában kötelező-e meghatározott sorrendet betartani „az adott csúcshoz kapcsolódó összes csúcs" tekintetében?

Tetszőleges sorrend alkalmazható. Azonban a gyakorlati alkalmazásokban szükséges lehet meghatározott szabályok szerinti rendezés, például a csúcsok hozzáadásának sorrendje vagy a csúcsértékek sorrendje alapján, ami segít gyorsan megtalálni a „bizonyos szélsőértékekkel rendelkező" csúcsokat.
