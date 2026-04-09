# Összefoglalás

### Kulcsfontosságú áttekintés

**Algoritmus hatékonysági értékelése**

- Az időhatékonyság és a térhatékonyság az algoritmus teljesítményének mérésére szolgáló két elsődleges értékelési mérőszám.
- Az algoritmus hatékonyságát tényleges teszteléssel értékelhetjük, de nehéz kiküszöbölni a tesztkörnyezet hatását, és ez jelentős számítási erőforrásokat fogyaszt.
- A bonyolultságelemzés kiküszöbölheti a tényleges tesztelés hátrányait, az eredmények minden futtatási platformra alkalmazhatók, és képes feltárni az algoritmus hatékonyságát különböző adatméretekben.

**Időbonyolultság**

- Az időbonyolultságot az algoritmus futási ideje növekedési trendjének mérésére használják az adatmennyiség növekedésével. Hatékonyan értékeli az algoritmus hatékonyságát, de bizonyos helyzetekben meghibásodhat, például ha a bemeneti adatmennyiség kicsi, vagy ha az időbonyolultságok azonosak, ami lehetetlenné teszi az algoritmus hatékonyságának pontos összehasonlítását.
- A legrosszabb esetű időbonyolultságot Nagy $O$ jelöléssel ábrázolják, amely egy függvény aszimptotikus felső korlátjának felel meg, tükrözve az $n$ pozitív végtelenhez közeledésekor a műveletek száma $T(n)$ növekedési szintjét.
- Az időbonyolultság levezetése két lépésből áll: először megszámolja a műveletek számát, majd meghatározza az aszimptotikus felső korlátot.
- A gyakori időbonyolultságok alacsonyból magasba rendezve a következők: $O(1)$, $O(\log n)$, $O(n)$, $O(n \log n)$, $O(n^2)$, $O(2^n)$ és $O(n!)$.
- Egyes algoritmusok időbonyolultsága nem rögzített, hanem a bemeneti adatok eloszlásától függ. Az időbonyolultságot legrosszabb esetű, legjobb esetű és átlagos esetű időbonyolultságra osztják. A legjobb esetű időbonyolultságot ritkán használják, mivel a bemeneti adatoknak általában szigorú feltételeket kell teljesíteniük a legjobb eset eléréséhez.
- Az átlagos időbonyolultság tükrözi az algoritmus futási idő hatékonyságát véletlenszerű adatbemenet esetén, és ez a legközelebb áll az algoritmus teljesítményéhez a gyakorlati alkalmazásokban. Az átlagos időbonyolultság kiszámításához statisztikai elemzés szükséges a bemeneti adatok eloszlásáról és a kombinált matematikai várható értékről.

**Térbonyolultság**

- A térbonyolultság az időbonyolultsághoz hasonló célt szolgál, az algoritmus memóriahasználata növekedési trendjének mérésére az adatmennyiség növekedésével.
- Az algoritmus végrehajtásához kapcsolódó memóriaterület bemeneti térre, ideiglenes térre és kimeneti térre osztható. Általában a bemeneti tér nem szerepel a térbonyolultság számításában. Az ideiglenes tér ideiglenes adatokra, veremkeret-térre és utasítástérre osztható, ahol a veremkeret-tér általában csak a rekurzív függvényeknél befolyásolja a térbonyolultságot.
- Általában csak a legrosszabb esetű térbonyolultságra koncentrálunk, ami egy algoritmus térbonyolultsága a legrosszabb esetű bemeneti adatok és a legrosszabb esetű futási idő esetén.
- A gyakori térbonyolultságok alacsonyból magasba rendezve a következők: $O(1)$, $O(\log n)$, $O(n)$, $O(n^2)$ és $O(2^n)$.

### Kérdések és válaszok

**K**: A farokrekurzió térbonyolultsága $O(1)$?

Elméletileg a farokrekurzív függvények térbonyolultsága optimalizálható $O(1)$-re. Azonban a legtöbb programozási nyelv (például Java, Python, C++, Go, C# stb.) nem támogatja az automatikus farokrekurzió optimalizálást, ezért a térbonyolultságot általában $O(n)$-nek tekintik.

**K**: Mi a különbség a függvény és a metódus kifejezések között?

Egy <u>függvény</u> önállóan futtatható, az összes paraméter explicit módon átadható. Egy <u>metódus</u> egy objektumhoz van társítva, implicit módon átadódik az azt meghívó objektumnak, és képes művelni az osztálypéldányokban tárolt adatokat.

Az alábbi példák néhány általánosan használt programozási nyelvet illusztrálnak.

- A C egy procedurális programozási nyelv, objektumorientált fogalmak nélkül, ezért csak függvényei vannak. Azonban struktúrák (struct) létrehozásával szimulálhatjuk az objektumorientált programozást, és a struktúrákhoz kapcsolódó függvények egyenértékűek a metódusokkal más programozási nyelveken.
- A Java és a C# objektumorientált programozási nyelvek, ahol a kódblokkok (metódusok) általában egy osztály részei. A statikus metódusok függvényként viselkednek, mivel az osztályhoz vannak kötve és nem férnek hozzá specifikus példányváltozókhoz.
- A C++ és a Python egyaránt támogatja a procedurális programozást (függvények) és az objektumorientált programozást (metódusok).

**K**: A "gyakori térbonyolultság típusok" ábrája a foglalt tér abszolút méretét tükrözi?

Nem, az ábra a térbonyolultságot mutatja, amely a növekedési trendeket tükrözi, nem a foglalt tér abszolút méretét.

Feltéve, hogy $n = 8$, előfordulhat, hogy az egyes görbék értékei nem felelnek meg a függvényeknek. Ez azért van, mert minden görbe egy konstans tagot tartalmaz, amellyel az értéktartomány vizuálisan kényelmes tartományba szűkül.

A gyakorlatban, mivel általában nem tudjuk, hogy az egyes módszerek "konstans tag" bonyolultsága mi, általában nem tudjuk kiválasztani az optimális megoldást $n = 8$ esetén csak a bonyolultság alapján. De $n = 8^5$ esetén a választás egyértelmű, mivel a növekedési trend már domináns.

**K**: Vannak olyan helyzetek, amikor az algoritmusokat tényleges felhasználási esetük alapján az idő (vagy tér) feláldozásával tervezik?

A gyakorlati alkalmazásokban a legtöbb helyzetben a tér feláldozása az időért választják. Például adatbázis-indexeknél általában B+ fák vagy hash indexek létrehozását választják, amelyek jelentős memóriaterületet foglalnak el a hatékony, $O(\log n)$ vagy akár $O(1)$ lekérdezésekért cserébe.

Olyan forgatókönyvekben, ahol a tér erőforrások értékesek, az idő feláldozható a térért. Például beágyazott fejlesztésben, ahol az eszközmemória értékes, a mérnökök lemondhatnak a hash táblák használatáról, és helyette tömbök szekvenciális keresését választhatják a memóriahasználat megtakarítása érdekében, a lassabb keresések árán.
