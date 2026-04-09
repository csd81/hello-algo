# Összefoglalás

### Kulcsfontosságú áttekintés

- A bináris fa egy nemlineáris adatszerkezet, amely az "egy kettőre bomlik" osztd-meg-és-uralkodj logikát testesíti meg. Minden bináris fa csomópont tartalmaz egy értéket és két mutatót, amelyek rendre a bal és jobb gyermek csomópontjára mutatnak.
- A bináris fa egy adott csomópontjára nézve a bal (jobb) gyermek csomópontja és az alatta lévő összes csomópont által alkotott fát az adott csomópont bal (jobb) részfájának nevezzük.
- A bináris fákhoz kapcsolódó terminológia magában foglalja a gyökér csomópontot, a levél csomópontot, a szintet, a fokszámot, az élt, a magasságot és a mélységet.
- A bináris fák inicializálási, csomópont-beszúrási és csomópont-törlési műveletei hasonlóak a láncolt listákéhoz.
- A bináris fák általánosan előforduló típusai közé tartoznak a tökéletes bináris fák, a teljes bináris fák, a szigorúan bináris fák és a kiegyensúlyozott bináris fák. A tökéletes bináris fa az ideális állapot, míg a láncolt lista a legrosszabb degenerált állapot.
- A bináris fák tömbben is ábrázolhatók úgy, hogy a csomópontértékeket és az üres helyeket szintenkénti bejárás sorrendjében rendezzük el, és a mutatókat a szülő és gyermek csomópontok közötti indexleképezési kapcsolat alapján valósítjuk meg.
- A bináris fa szintenkénti bejárása szélességi keresési módszer, amely egy "köröket kifelé terjesztve" szintenként haladó bejárási megközelítést testesít meg, és általában sor segítségével valósítják meg.
- Az előrendű, szimmetrikus rendű és utórendű bejárások mind mélységi kereséshez tartoznak, amelyek a "először menj a végéig, aztán visszalépve folytasd" bejárási megközelítést testesítik meg, és általában rekurzió segítségével valósítják meg.
- A bináris keresőfa hatékony adatszerkezet az elemek kereséséhez, ahol a keresési, beszúrási és törlési műveletek időbonyolultsága egyaránt $O(\log n)$. Ha a bináris keresőfa láncolt listává degenerálódik, minden időbonyolultság $O(n)$-re romlik.
- Az AVL-fa, más néven kiegyensúlyozott bináris keresőfa, forgatási műveletek révén biztosítja, hogy a fa a folyamatos csomópont-beszúrás és -törlés után is kiegyensúlyozott maradjon.
- Az AVL-fák forgatási műveletei közé tartozik a jobbra forgatás, a balra forgatás, a balra majd jobbra forgatás, és a jobbra majd balra forgatás. Csomópontok beszúrása vagy törlése után az AVL-fák alulról felfelé haladva végeznek forgatási műveleteket a fa egyensúlyának helyreállítása érdekében.

### Kérdések és válaszok

**K**: Egy csupán egyetlen csomópontot tartalmazó bináris fa esetén a fa magassága és a gyökér csomópont mélysége is $0$?

Igen, mert a magasságot és a mélységet általában "az átlépett élek számával" definiálják.

**K**: A bináris fában végzett beszúrás és törlés általában egy műveletsorra van bontva. Mit jelent ez a "műveletsora" kifejezés? Jelenti-e ez a gyermek csomópontok erőforrásainak felszabadítását?

A bináris keresőfát példaként véve, egy csomópont törlési műveletét három különböző esetben kell kezelni, amelyek mindegyike csomópontok több lépéses működtetését igényli.

**K**: Miért van a bináris fa mélységi keresési bejárásának három sorrendje: előrendű, szimmetrikus rendű és utórendű, és mi a hasznuk?

A tömbök előre és visszafelé irányú bejárásához hasonlóan az előrendű, szimmetrikus rendű és utórendű bejárások a bináris fa bejárásának három módszere, amelyek lehetővé teszik egy adott sorrendű bejárási eredmény megszerzését. Például egy bináris keresőfában, ahol a csomópontok kielégítik a "bal gyermek csomópont értéke < gyökér csomópont értéke < jobb gyermek csomópont értéke" kapcsolatot, csupán annyi szükséges, hogy a fát a "bal $\rightarrow$ gyökér $\rightarrow$ jobb" prioritással járjuk be a rendezett csomópontsorozat eléréséhez.

**K**: A jobbra forgatási műveletben a kiegyensúlyozatlan `node`, `child` és `grand_child` csomópontok kapcsolatának kezelése során nem veszik-e el a `node` és szülő csomópontja közötti kapcsolat a jobbra forgatás után?

Rekurzív szemszögből kell megvizsgálni ezt a problémát. A jobbra forgatás `right_rotate(root)` művelet átkapja a részfa gyökér csomópontját, és végül visszaadja a forgatás utáni részfa gyökér csomópontját `return child`-dal. A részfa gyökér csomópontja és szülő csomópontja közötti kapcsolat a függvény visszatérése után jön létre, ami nem tartozik a jobbra forgatás műveleti hatáskörébe.

**K**: C++-ban a függvények `private` és `public` részekre vannak osztva. Milyen szempontok alapján történik ez? Miért kerül a `height()` függvény a `public`, az `updateHeight()` függvény pedig a `private` részbe?

Elsősorban a módszer felhasználási köre a döntő. Ha egy módszert csak az osztályon belül használnak, akkor `private` típusúnak tervezik. Például az `updateHeight()` önálló felhasználása a felhasználó számára értelmetlen, mivel csupán egy lépés a beszúrási vagy törlési műveleten belül. Ugyanakkor a `height()` a csomópont magasságának elérésére szolgál, a `vector.size()`-hoz hasonlóan, ezért `public` típusúra van állítva a könnyű felhasználhatóság érdekében.

**K**: Hogyan lehet bináris keresőfát felépíteni egy bemeneti adathalmazból? A gyökér csomópont megválasztása fontos?

Igen, a fa felépítésének módszerét a bináris keresőfa kódjában lévő `build_tree()` metódus tartalmazza. A gyökér csomópont megválasztása tekintetében általában rendezzük a bemeneti adatokat, majd a középső elemet választjuk gyökér csomópontként, és rekurzívan felépítjük a bal és jobb részfákat. Ez a megközelítés maximalizálja a fa egyensúlyát.

**K**: Java-ban mindig az `equals()` metódust kell használni a karakterlánc-összehasonlításhoz?

Java-ban primitív adattípusoknál a `==` jelöli, hogy két változó értéke egyenlő-e. Referencia típusoknál a két szimbólum működési elve különböző.

- `==`: Annak ellenőrzésére szolgál, hogy két változó ugyanarra az objektumra mutat-e, vagyis memóriabeli pozíciójuk megegyezik-e.
- `equals()`: Annak ellenőrzésére szolgál, hogy két objektum értéke egyenlő-e.

Ezért ha értékeket kívánunk összehasonlítani, az `equals()` metódust kell használni. Ugyanakkor a `String a = "hi"; String b = "hi";` módon inicializált karakterláncok a karakterlánc-konstans poolban tárolódnak, és ugyanarra az objektumra mutatnak, ezért az `a == b` szintén alkalmazható a két karakterlánc tartalmának összehasonlítására.

**K**: Az alsó szint elérése előtt a sorban lévő csomópontok száma $2^h$ szélességi keresési bejárásban?

Igen, például egy $h = 2$ magasságú tökéletes bináris fának összesen $n = 7$ csomópontja van, az alsó szinten $4 = 2^h = (n + 1) / 2$ csomópont található.
