# Összefoglalás

### Kulcsfogalmak Áttekintése

- A tömbök és a láncolt listák két alapvető adatstruktúra, amelyek kétféle módszert képviselnek az adatok számítógépes memóriában való tárolására: összefüggő memóriatárolás és szétszórt memóriatárolás. A kettő jellemzői kiegészítik egymást.
- A tömbök támogatják a véletlenszerű hozzáférést és kevesebb memóriát használnak; azonban az elemek beszúrása és törlése nem hatékony, és az inicializálás után a hossz nem változtatható.
- A láncolt listák hivatkozások (mutatók) módosításával hatékony csomópontbeszúrást és -törlést tesznek lehetővé, és rugalmasan állítható a hosszuk; azonban a csomópont-hozzáférés nem hatékony és a memóriafogyasztás magasabb. A láncolt listák általános típusai: egyirányú láncolt listák, körkörös láncolt listák és kétirányú láncolt listák.
- A lista elemek rendezett gyűjteménye, amely támogatja a beszúrást, törlést, keresést és módosítást, általában dinamikus tömbök alapján valósul meg. Megőrzi a tömbök előnyeit, miközben lehetővé teszi a hossz rugalmas beállítását.
- A listák megjelenése nagymértékben javította a tömbök praktikusságát, de némi memóriaterület-pazarlást okozhat.
- A program végrehajtása során az adatok elsősorban a memóriában tárolódnak. A tömbök nagyobb memóriahatékonyságot biztosítanak, míg a láncolt listák nagyobb rugalmasságot kínálnak a memória kihasználásában.
- A gyorsítótárak gyors adathozzáférést biztosítanak a CPU számára olyan mechanizmusokon keresztül, mint a gyorsítótár-sorok, az előolvasás, valamint a térbeli és időbeli lokalitás, amelyek jelentősen javítják a program végrehajtási hatékonyságát.
- Mivel a tömböknek magasabb a gyorsítótár-találati arányuk, általában hatékonyabbak a láncolt listáknál. Adatstruktúra választásakor az adott követelmények és forgatókönyvek alapján kell megfelelő döntést hozni.

### Kérdések és Válaszok

**K**: Befolyásolja-e az idő- és tárhelyhatékonyságot, hogy egy tömböt a veremtárolón vagy a halomtárolón tárolunk?

A veremtárolón és a halomtárolón tárolt tömbök egyaránt összefüggő memóriaterületen tárolódnak, ezért az adatműveleti hatékonyság alapvetően azonos. A veremnek és a halomnak azonban megvannak a saját jellemzőik, amelyek a következő különbségekhez vezetnek.

1. Lefoglalás és felszabadítás hatékonysága: A verem viszonylag kis méretű memóriaterület, amelynek lefoglalását automatikusan kezeli a fordítóprogram; a halom viszonylag nagyobb, és kódban dinamikusan foglalható le, jobban hajlamos a töredezettségre. Ezért a halmon végzett lefoglalási és felszabadítási műveletek általában lassabbak, mint a veremtárolón.
2. Méretkorlátozások: A verem memóriája viszonylag kis méretű, a halom mérete általában a rendelkezésre álló memória mennyiségétől függ. Ezért a halom alkalmasabb nagy tömbök tárolására.
3. Rugalmasság: A veremtárolón lévő tömb méretét fordítási időben kell meghatározni, míg a halmon lévő tömb mérete futási időben dinamikusan határozható meg.

**K**: Miért igényelnek a tömbök azonos típusú elemeket, míg a láncolt listák nem hangsúlyozzák ezt a követelményt?

A láncolt listák csomópontokból állnak, amelyek hivatkozásokon (mutatókon) keresztül kapcsolódnak egymáshoz, és minden csomópont különböző típusú adatokat tárolhat, például `int`, `double`, `string`, `object` stb.

Ezzel szemben a tömbelemeknek azonos típusúaknak kell lenniük, hogy a megfelelő elem pozícióját az eltolás kiszámításával meg lehessen határozni. Például ha egy tömb `int` és `long` típusokat is tartalmaz, amelyekben az egyes elemek 4 bájtot, illetve 8 bájtot foglalnak el, akkor a következő képlettel nem számítható ki az eltolás, mert a tömb kétféle "elemhosszt" tartalmaz.

```shell
# Elem memóriacíme = Tömb memóriacíme (első elem memóriacíme) + Elemhossz * Elemindex
```

**K**: A `P` csomópont törlése után be kell-e állítani a `P.next`-et `None`-ra?

Nem szükséges módosítani a `P.next`-et. A láncolt lista szempontjából a fejcsomóponttól a farokcsomópontig való bejárás során már nem találkozunk `P`-vel. Ez azt jelenti, hogy a `P` csomópont el lett távolítva a láncolt listából, és nem számít, hova mutat `P` csomópont – nem befolyásolja a láncolt listát.

Az adatstruktúrák és algoritmusok (feladatmegoldás) szempontjából a mutató leválasztásának elmaradása nem számít, amennyiben a program logikája helyes. A standard könyvtárak szempontjából a leválasztás biztonságosabb és a logika átláthatóbb. Ha nem választjuk le, feltéve, hogy a törölt csomópontot nem szabadítják fel megfelelően, ez befolyásolhatja az utódcsomópontjainak memória-visszanyerését.

**K**: Egy láncolt listában a beszúrás és törlés műveletek időbonyolultsága $O(1)$. Azonban mindkét esetben $O(n)$ időt igényel az elem megkeresése; miért nem $O(n)$ az időbonyolultság?

Ha az elemet először megkeressük, majd töröljük, az időbonyolultság valóban $O(n)$. Azonban a láncolt listáknál az $O(1)$ idejű beszúrás és törlés előnye más alkalmazásokban mutatkozik meg. Például a kétvégű sor (deque) kiválóan alkalmas láncolt lista megvalósítására, ahol fenntartunk mutató változókat, amelyek mindig a fej- és farokcsomópontokra mutatnak, és minden egyes beszúrási és törlési művelet $O(1)$ bonyolultságú.

**K**: A "Láncolt lista definíciója és tárolási módszerei" ábrán a világoskék mutató csomópont egyetlen memóriacímet foglal el, vagy egyenlően osztozik a csomópont értékével?

Ez az ábra kvalitatív ábrázolás; a kvantitatív ábrázoláshoz az adott helyzet alapján kell elemzést végezni.

- A különböző típusú csomópont értékek különböző mennyiségű helyet foglalnak el, például `int`, `long`, `double` és példányobjektumok stb.
- A mutató változók által elfoglalt memóriaterület az operációs rendszertől és a fordítókörnyezettől függ, általában 8 bájt vagy 4 bájt.

**K**: Mindig $O(1)$ egy elem lista végéhez való hozzáfűzése?

Ha egy elem hozzáfűzése meghaladja a lista hosszát, a listát először bővíteni kell, majd hozzáadjuk. A rendszer új memóriablokkot foglal le, és az eredeti lista összes elemét áthelyezi oda, ami esetén az időbonyolultság $O(n)$ lesz.

**K**: "A listák megjelenése nagymértékben javította a tömbök praktikusságát, de némi memóriaterület-pazarlást okozhat" – ez a tárhelypazarlás a kapacitás, hossz és bővítési tényező stb. által elfoglalt további változók memóriájára vonatkozik?

Ez a tárhelypazarlás főként két szempontban nyilvánul meg: egyrészt a listák általában kezdeti hosszt állítanak be, amelyet esetleg nem kell teljesen kihasználni; másrészt a gyakori bővítés megelőzése érdekében a bővítés általában egy együtthatóval szorozza meg a méretet, például $\times 1.5$. Ennek eredményeként sok üres pozíció keletkezik, amelyeket általában nem tudunk teljesen kitölteni.

**K**: Pythonban `n = [1, 2, 3]` inicializálása után ezen 3 elem címei összefüggők, de `m = [2, 1, 3]` inicializálásakor kiderül, hogy minden elem azonosítója nem folytonos; inkább ugyanolyanok, mint az `n`-ben lévők. Mivel ezen elemek címei nem összefüggők, `m` még mindig tömb?

Ha a lista elemeit láncolt lista csomópontokra cseréljük `n = [n1, n2, n3, n4, n5]`, általában ez az 5 csomópontobjektum is szétszórtan helyezkedik el a memóriában. Azonban egy lista index alapján $O(1)$ időben megkaphatjuk a csomópont memóriacímét, ezáltal hozzáférhetünk a megfelelő csomóponthoz. Ez azért van, mert a tömb nem magukra a csomópontokra, hanem a csomópontokra mutató hivatkozásokat tárolja.

Sok más nyelvtől eltérően a Pythonban a számok objektumokként vannak becsomagolva, és a listák nem magukhoz a számokhoz, hanem a számokra mutató hivatkozásokat tárolják. Ezért azt találjuk, hogy a két tömbben lévő azonos számoknak ugyanolyan az azonosítójuk, és ezeknek a számoknak a memóriacímei nem szükségszerűen összefüggők.

**K**: A C++ STL-nek van `std::list`-je, amely már megvalósított egy kétirányú láncolt listát, de úgy tűnik, néhány algoritmikai könyv nem használja közvetlenül. Van-e valamilyen korlátozása?

Egyrészt általában inkább tömbök használatát részesítjük előnyben az algoritmusok megvalósításához, és csak szükség esetén használunk láncolt listákat, főként két ok miatt.

- Tárhelyterhelés: Mivel minden elemhez két további mutató szükséges (egy az előző és egy a következő elemhez), az `std::list` általában több helyet fogyaszt, mint az `std::vector`.
- Gyorsítótár-barátlanság: Mivel az adatok nem összefüggően tárolódnak, az `std::list` alacsonyabb gyorsítótár-kihasználtsággal rendelkezik. Általánosságban az `std::vector` jobb teljesítményt nyújt.

Másrészt azok az esetek, ahol láncolt listákra van szükség, főként bináris fákat és gráfokat érintenek. A veremek és sorok általában a programozási nyelv által biztosított `stack` és `queue` típusokat használják, nem láncolt listákat.

**K**: A `res = [[0]] * n` művelet olyan kétdimenziós listát hoz létre, amelyben minden `[0]` független?

Nem, ezek nem függetlenek. Ebben a kétdimenziós listában az összes `[0]` valójában ugyanarra az objektumra mutató hivatkozás. Ha módosítunk egy elemet, azt tapasztalhatjuk, hogy az összes megfelelő elem ennek megfelelően változik.

Ha azt szeretnénk, hogy a kétdimenziós lista minden `[0]`-ja független legyen, a `res = [[0] for _ in range(n)]` megközelítést alkalmazhatjuk. Ennek az elvnek lényege $n$ független `[0]` lista objektum inicializálása.

**K**: A `res = [0] * n` művelet olyan listát hoz létre, amelyben minden egész 0 független?

Ebben a listában az összes egész 0 ugyanarra az objektumra mutató hivatkozás. Ez azért van, mert a Python egy gyorsítótárazási mechanizmust alkalmaz a kis egészekre (általában -5-tól 256-ig) az objektumok maximális újrafelhasználása és a teljesítmény javítása érdekében.

Bár ugyanarra az objektumra mutatnak, a lista minden elemét mégis módosíthatjuk egymástól függetlenül. Ez azért van, mert a Python egészek "megváltoztathatatlan objektumok". Egy elem módosításakor valójában egy másik objektumra mutató hivatkozásra váltunk, nem az eredeti objektumot módosítjuk.

Azonban amikor a lista elemei "megváltoztatható objektumok" (például listák, szótárak vagy osztálypéldányok), az elem módosítása közvetlenül megváltoztatja az objektumot, és az arra az objektumra hivatkozó összes elem ugyanolyan változást tapasztal.
