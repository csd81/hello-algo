# Hash Algoritmus

Az előző két szakasz bemutatta a hash táblák működési elvét és a hash ütközések kezelési módszereit. Azonban mind a nyílt címzés, mind a láncolás **csak azt tudja biztosítani, hogy a hash tábla normálisan működjön hash ütközések esetén, de nem tudja csökkenteni a hash ütközések gyakoriságát**.

Ha a hash ütközések túl gyakran fordulnak elő, a hash tábla teljesítménye drasztikusan romlik. Ahogy az alábbi ábra mutatja, láncolást alkalmazó hash tábla esetén, ideális esetben a kulcs-érték párok egyenletesen oszlanak el a vödrök között, elérve az optimális lekérdezési hatékonyságot; a legrosszabb esetben az összes kulcs-érték pár ugyanabban a vödörben van tárolva, ami az időbonyolultságot $O(n)$-re rontja.

![A hash ütközések ideális és legrosszabb esetei](hash_algorithm.assets/hash_collision_best_worst_condition.png)

**A kulcs-érték párok eloszlását a hash függvény határozza meg**. Felidézve a hash függvény számítási lépéseit, először kiszámítjuk a hash értéket, majd vesszük a modulót a tömb hosszával:

```shell
index = hash(key) % capacity
```

A fenti képletet megfigyelve, amikor a hash tábla kapacitása `capacity` rögzített, **a `hash()` hash algoritmus határozza meg a kimeneti értéket**, ezáltal meghatározza a kulcs-érték párok eloszlását a hash táblában.

Ez azt jelenti, hogy a hash ütközések valószínűségének csökkentéséhez a `hash()` hash algoritmus tervezésére kell összpontosítani.

## A Hash Algoritmusok Céljai

Egy „gyors és stabil" hash tábla adatszerkezet eléréséhez a hash algoritmusoknak a következő jellemzőkkel kell rendelkezniük:

- **Determinizmus**: Ugyanolyan bemenet esetén a hash algoritmusnak mindig ugyanolyan kimenetet kell produkálnia. Csak akkor lehet a hash tábla megbízható.
- **Magas hatékonyság**: A hash érték kiszámítási folyamatának elég gyorsnak kell lennie. Minél kisebb a számítási terhelés, annál praktikusabb a hash tábla.
- **Egyenletes eloszlás**: A hash algoritmusnak biztosítania kell, hogy a kulcs-érték párok egyenletesen oszlanak el a hash táblában. Minél egyenletesebb az eloszlás, annál kisebb a hash ütközések valószínűsége.

Valójában a hash algoritmusokat nem csak hash táblák megvalósítására használják, hanem más területeken is széles körben alkalmazzák.

- **Jelszótárolás**: A felhasználói jelszavak biztonságának védelme érdekében a rendszerek általában nem a jelszavak szöveges változatát tárolják, hanem a jelszavak hash értékeit. Amikor a felhasználó jelszót ír be, a rendszer kiszámítja a bevitt jelszó hash értékét, és összehasonlítja a tárolt hash értékkel. Ha egyeznek, a jelszó helyesnek tekintendő.
- **Adatintegritás-ellenőrzés**: Az adatküldő kiszámíthatja az adatok hash értékét és elküldheti azt; a fogadó újra kiszámíthatja a fogadott adatok hash értékét és összehasonlíthatja a kapott hash értékkel. Ha egyeznek, az adatok épségét megőrzöttnek tekintik.

Kriptográfiai alkalmazások esetén, hogy megakadályozzák a visszafejtést, mint például a hash értékből az eredeti jelszó levezetését, a hash algoritmusoknak magasabb szintű biztonsági jellemzőkre van szükségük.

- **Egyirányúság**: Lehetetlen legyen bármilyen információt levezetni a bemeneti adatokból a hash értékből.
- **Ütközési ellenállás**: Rendkívül nehéz legyen két különböző bemenetet találni, amelyek ugyanolyan hash értéket produkálnak.
- **Lavina-hatás**: A bemenet kisebb változásai a kimenet jelentős és kiszámíthatatlan változásait eredményezzék.

Vegyük észre, hogy **az „egyenletes eloszlás" és az „ütközési ellenállás" két független fogalom**. Az egyenletes eloszlás teljesítése nem feltétlenül jelent ütközési ellenállást. Például véletlenszerű `key` bemenet esetén a `key % 100` hash függvény egyenletesen elosztott kimenetet produkálhat. Azonban ez a hash algoritmus túl egyszerű, és minden azonos utolsó két számjegyű `key`-nek azonos kimenete lesz, ami megkönnyíti egy használható `key` levezetését a hash értékből, ezáltal a jelszót feltörhetővé téve.

## Hash Algoritmusok Tervezése

A hash algoritmusok tervezése összetett kérdés, amely sok tényező mérlegelését igényli. Azonban néhány kevésbé szigorú követelményű esetben egyszerűbb hash algoritmusokat is tervezhetünk.

- **Összeadásos hash**: Adjuk össze minden karakter ASCII kódjait a bemenetben, és az összeget használjuk hash értékként.
- **Szorzásos hash**: Felhasználjuk a szorzás nem-korreláltságát, minden körben egy konstanssal szorozva, felhalmozva minden karakter ASCII kódjait a hash értékbe.
- **XOR hash**: Felhalmozzuk a hash értéket a bemeneti adatok minden elemének XOR-olásával.
- **Forgásos hash**: Felhalmozzuk minden karakter ASCII kódját egy hash értékbe, minden felhalmozás előtt forgási műveletet végezve a hash értéken.

```src
[file]{simple_hash}-[class]{}-[func]{rot_hash}
```

Megfigyelhető, hogy minden hash algoritmus utolsó lépése a nagy prímszám $1000000007$ modulójának vétele, hogy biztosítsuk, hogy a hash érték megfelelő tartományon belül legyen. Érdemes elgondolkodni, hogy miért hangsúlyozzák a prímszámmal való modulózást, vagy mik a hátránya az összetett számmal való modulózásnak? Ez egy érdekes kérdés.

Összefoglalva: **Nagy prímszám használata modulusként maximálisan biztosítja a hash értékek egyenletes eloszlását**. Mivel a prímszámnak nincsenek közös tényezői más számokkal, csökkenti a modulóval végzett művelet által okozott periodikus mintákat, ezáltal elkerülve a hash ütközéseket.

Például tegyük fel, hogy a $9$ összetett számot választjuk modulusként, amely osztható $3$-mal, akkor minden $3$-mal osztható `key` a $0$, $3$, $6$ hash értékekre lesz leképezve.

$$
\begin{aligned}
\text{modulus} & = 9 \newline
\text{key} & = \{ 0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, \dots \} \newline
\text{hash} & = \{ 0, 3, 6, 0, 3, 6, 0, 3, 6, 0, 3, 6,\dots \}
\end{aligned}
$$

Ha a bemeneti `key` éppen ilyen számtani sorozat eloszlású, akkor a hash értékek klaszteresednek, ezáltal súlyosbítva a hash ütközéseket. Most tegyük fel, hogy a `modulus`-t a $13$ prímszámra cseréljük; mivel nincsenek közös tényezők a `key` és a `modulus` között, a kimeneti hash értékek egyenletes eloszlása jelentősen javul.

$$
\begin{aligned}
\text{modulus} & = 13 \newline
\text{key} & = \{ 0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, \dots \} \newline
\text{hash} & = \{ 0, 3, 6, 9, 12, 2, 5, 8, 11, 1, 4, 7, \dots \}
\end{aligned}
$$

Megjegyzendő, hogy ha a `key` garantáltan véletlenszerűen és egyenletesen oszlik el, akkor prímszám vagy összetett szám modulusként való választása egyaránt egyenletesen elosztott hash értékeket produkálhat. Azonban ha a `key` eloszlása valamiféle periodicitással rendelkezik, az összetett számmal való modulózás nagyobb valószínűséggel eredményez klaszteresedést.

Összefoglalva, általában prímszámot választunk modulusként, és ennek a prímszámnak elég nagynak kell lennie a periodikus minták lehető legnagyobb mértékű kiküszöböléséhez, ezáltal növelve a hash algoritmus robusztusságát.

## Gyakori Hash Algoritmusok

Nem nehéz belátni, hogy a fent említett egyszerű hash algoritmusok eléggé „törékenyek", és messze elmaradnak a hash algoritmusokkal szemben támasztott tervezési céloktól. Például, mivel az összeadás és az XOR engedelmeskednek a kommutatív törvénynek, az összeadásos hash és az XOR hash nem tud megkülönböztetni azonos tartalmú, de eltérő sorrendű karakterláncokat, ami súlyosbíthatja a hash ütközéseket és biztonsági problémákat okozhat.

A gyakorlatban általában szabványos hash algoritmusokat használunk, mint például az MD5, SHA-1, SHA-2 és SHA-3. Ezek tetszőleges hosszúságú bemeneti adatokat képesek rögzített hosszúságú hash értékekre leképezni.

Az elmúlt évszázadban a hash algoritmusok folyamatos fejlesztési és optimalizálási folyamaton mentek keresztül. Egyes kutatók a hash algoritmusok teljesítményének javítására törekednek, míg mások, köztük hackerek, a hash algoritmusok biztonsági problémáinak megtalálásán dolgoznak. Az alábbi táblázat a gyakorlati alkalmazásokban általánosan használt hash algoritmusokat mutatja be.

- Az MD5 és SHA-1 ellen sikeresen hajtottak végre támadásokat, ezért különböző biztonsági alkalmazásokban elhagyják őket.
- A SHA-2 sorozat, különösen a SHA-256, a mai napig az egyik legbiztonságosabb hash algoritmus, amellyel szemben nem számoltak be sikeres támadásról, ezért különböző biztonsági alkalmazásokban és protokollokban általánosan használják.
- A SHA-3 alacsonyabb megvalósítási költséggel és magasabb számítási hatékonysággal rendelkezik a SHA-2-höz képest, de jelenlegi felhasználási köre nem olyan széles, mint a SHA-2 sorozaté.

<p align="center"> Table <id> &nbsp; Gyakori hash algoritmusok </p>

|                 | MD5                                             | SHA-1                               | SHA-2                                                             | SHA-3                        |
| --------------- | ----------------------------------------------- | ----------------------------------- | ----------------------------------------------------------------- | ---------------------------- |
| Kiadás éve      | 1992                                            | 1995                                | 2002                                                              | 2008                         |
| Kimenet hossza  | 128 bit                                         | 160 bit                             | 256/512 bit                                                       | 224/256/384/512 bit          |
| Hash ütközések  | Gyakori                                         | Gyakori                             | Ritka                                                             | Ritka                        |
| Biztonsági szint| Alacsony, sikeresen megtámadták                 | Alacsony, sikeresen megtámadták     | Magas                                                             | Magas                        |
| Alkalmazások    | Elhagyva, még mindig adatintegritás-ellenőrzésre| Elhagyva                            | Kriptovaluta tranzakció-ellenőrzés, digitális aláírások stb.      | Helyettesítheti a SHA-2-t    |

# Hash Értékek az Adatszerkezetekben

Tudjuk, hogy a hash táblában lévő kulcsok különböző adattípusúak lehetnek, mint például egész számok, tizedes törtek vagy karakterláncok. A programozási nyelvek általában beépített hash algoritmusokat biztosítanak ezekhez az adattípusokhoz a hash tábla vödörindexeinek kiszámításához. A Python-t példaként véve, a `hash()` függvénnyel különböző adattípusok hash értékeit számíthatjuk ki.

- Az egész számok és a logikai értékek hash értéke maga az értékük.
- A lebegőpontos számok és a karakterláncok hash értékeinek kiszámítása összetettebb, az érdeklődő olvasókat arra bátorítjuk, hogy önállóan tanulmányozzák ezt.
- Egy tuple hash értéke az egyes elemei hash értékeinek kombinációja, egyetlen hash értéket eredményezve.
- Egy objektum hash értéke a memóriacíme alapján generálódik. Az objektum hash metódusának felülírásával hash értékek generálhatók tartalom alapján.

!!! tip

    Legyen tudatában, hogy a különböző programozási nyelvekben a beépített hash értékszámítási függvények definíciója és módszerei eltérnek.

=== "Python"

    ```python title="built_in_hash.py"
    num = 3
    hash_num = hash(num)
    # A 3 egész szám hash értéke 3

    bol = True
    hash_bol = hash(bol)
    # A True logikai érték hash értéke 1

    dec = 3.14159
    hash_dec = hash(dec)
    # A 3.14159 tizedes tört hash értéke 326484311674566659

    str = "Hello 算法"
    hash_str = hash(str)
    # A "Hello 算法" karakterlánc hash értéke 4617003410720528961

    tup = (12836, "小哈")
    hash_tup = hash(tup)
    # A (12836, '小哈') tuple hash értéke 1029005403108185979

    obj = ListNode(0)
    hash_obj = hash(obj)
    # A 0x1058fd810 memóriacímen lévő ListNode objektum hash értéke 274267521
    ```

=== "C++"

    ```cpp title="built_in_hash.cpp"
    int num = 3;
    size_t hashNum = hash<int>()(num);
    // A 3 egész szám hash értéke 3

    bool bol = true;
    size_t hashBol = hash<bool>()(bol);
    // Az 1 logikai érték hash értéke 1

    double dec = 3.14159;
    size_t hashDec = hash<double>()(dec);
    // A 3.14159 tizedes tört hash értéke 4614256650576692846

    string str = "Hello 算法";
    size_t hashStr = hash<string>()(str);
    // A "Hello 算法" karakterlánc hash értéke 15466937326284535026

    // C++-ban a beépített std::hash() csak alapvető adattípusokhoz biztosít hash értékeket
    // Tömbök és objektumok hash értékeit külön kell megvalósítani
    ```

=== "Java"

    ```java title="built_in_hash.java"
    int num = 3;
    int hashNum = Integer.hashCode(num);
    // A 3 egész szám hash értéke 3

    boolean bol = true;
    int hashBol = Boolean.hashCode(bol);
    // A true logikai érték hash értéke 1231

    double dec = 3.14159;
    int hashDec = Double.hashCode(dec);
    // A 3.14159 tizedes tört hash értéke -1340954729

    String str = "Hello 算法";
    int hashStr = str.hashCode();
    // A "Hello 算法" karakterlánc hash értéke -727081396

    Object[] arr = { 12836, "小哈" };
    int hashTup = Arrays.hashCode(arr);
    // A [12836, 小哈] tömb hash értéke 1151158

    ListNode obj = new ListNode(0);
    int hashObj = obj.hashCode();
    // A utils.ListNode@7dc5e7b4 ListNode objektum hash értéke 2110121908
    ```

=== "C#"

    ```csharp title="built_in_hash.cs"
    int num = 3;
    int hashNum = num.GetHashCode();
    // A 3 egész szám hash értéke 3;

    bool bol = true;
    int hashBol = bol.GetHashCode();
    // A true logikai érték hash értéke 1;

    double dec = 3.14159;
    int hashDec = dec.GetHashCode();
    // A 3.14159 tizedes tört hash értéke -1340954729;

    string str = "Hello 算法";
    int hashStr = str.GetHashCode();
    // A "Hello 算法" karakterlánc hash értéke -586107568;

    object[] arr = [12836, "小哈"];
    int hashTup = arr.GetHashCode();
    // A [12836, 小哈] tömb hash értéke 42931033;

    ListNode obj = new(0);
    int hashObj = obj.GetHashCode();
    // A 0 ListNode objektum hash értéke 39053774;
    ```

=== "Go"

    ```go title="built_in_hash.go"
    // A Go nem biztosít beépített hash kód függvényeket
    ```

=== "Swift"

    ```swift title="built_in_hash.swift"
    let num = 3
    let hashNum = num.hashValue
    // A 3 egész szám hash értéke 9047044699613009734

    let bol = true
    let hashBol = bol.hashValue
    // A true logikai érték hash értéke -4431640247352757451

    let dec = 3.14159
    let hashDec = dec.hashValue
    // A 3.14159 tizedes tört hash értéke -2465384235396674631

    let str = "Hello 算法"
    let hashStr = str.hashValue
    // A "Hello 算法" karakterlánc hash értéke -7850626797806988787

    let arr = [AnyHashable(12836), AnyHashable("小哈")]
    let hashTup = arr.hashValue
    // A [AnyHashable(12836), AnyHashable("小哈")] tömb hash értéke -2308633508154532996

    let obj = ListNode(x: 0)
    let hashObj = obj.hashValue
    // A utils.ListNode ListNode objektum hash értéke -2434780518035996159
    ```

=== "JS"

    ```javascript title="built_in_hash.js"
    // A JavaScript nem biztosít beépített hash kód függvényeket
    ```

=== "TS"

    ```typescript title="built_in_hash.ts"
    // A TypeScript nem biztosít beépített hash kód függvényeket
    ```

=== "Dart"

    ```dart title="built_in_hash.dart"
    int num = 3;
    int hashNum = num.hashCode;
    // A 3 egész szám hash értéke 34803

    bool bol = true;
    int hashBol = bol.hashCode;
    // A true logikai érték hash értéke 1231

    double dec = 3.14159;
    int hashDec = dec.hashCode;
    // A 3.14159 tizedes tört hash értéke 2570631074981783

    String str = "Hello 算法";
    int hashStr = str.hashCode;
    // A "Hello 算法" karakterlánc hash értéke 468167534

    List arr = [12836, "小哈"];
    int hashArr = arr.hashCode;
    // A [12836, 小哈] tömb hash értéke 976512528

    ListNode obj = new ListNode(0);
    int hashObj = obj.hashCode;
    // A 'ListNode' példány ListNode objektum hash értéke 1033450432
    ```

=== "Rust"

    ```rust title="built_in_hash.rs"
    use std::collections::hash_map::DefaultHasher;
    use std::hash::{Hash, Hasher};

    let num = 3;
    let mut num_hasher = DefaultHasher::new();
    num.hash(&mut num_hasher);
    let hash_num = num_hasher.finish();
    // A 3 egész szám hash értéke 568126464209439262

    let bol = true;
    let mut bol_hasher = DefaultHasher::new();
    bol.hash(&mut bol_hasher);
    let hash_bol = bol_hasher.finish();
    // A true logikai érték hash értéke 4952851536318644461

    let dec: f32 = 3.14159;
    let mut dec_hasher = DefaultHasher::new();
    dec.to_bits().hash(&mut dec_hasher);
    let hash_dec = dec_hasher.finish();
    // A 3.14159 tizedes tört hash értéke 2566941990314602357

    let str = "Hello 算法";
    let mut str_hasher = DefaultHasher::new();
    str.hash(&mut str_hasher);
    let hash_str = str_hasher.finish();
    // A "Hello 算法" karakterlánc hash értéke 16092673739211250988

    let arr = (&12836, &"小哈");
    let mut tup_hasher = DefaultHasher::new();
    arr.hash(&mut tup_hasher);
    let hash_tup = tup_hasher.finish();
    // A (12836, "小哈") tuple hash értéke 1885128010422702749

    let node = ListNode::new(42);
    let mut hasher = DefaultHasher::new();
    node.borrow().val.hash(&mut hasher);
    let hash = hasher.finish();
    // A RefCell { value: ListNode { val: 42, next: None } } ListNode objektum hash értéke 15387811073369036852
    ```

=== "C"

    ```c title="built_in_hash.c"
    // A C nem biztosít beépített hash kód függvényeket
    ```

=== "Kotlin"

    ```kotlin title="built_in_hash.kt"
    val num = 3
    val hashNum = num.hashCode()
    // A 3 egész szám hash értéke 3

    val bol = true
    val hashBol = bol.hashCode()
    // A true logikai érték hash értéke 1231

    val dec = 3.14159
    val hashDec = dec.hashCode()
    // A 3.14159 tizedes tört hash értéke -1340954729

    val str = "Hello 算法"
    val hashStr = str.hashCode()
    // A "Hello 算法" karakterlánc hash értéke -727081396

    val arr = arrayOf<Any>(12836, "小哈")
    val hashTup = arr.hashCode()
    // A [12836, 小哈] tömb hash értéke 189568618

    val obj = ListNode(0)
    val hashObj = obj.hashCode()
    // A utils.ListNode@1d81eb93 ListNode objektum hash értéke 495053715
    ```

=== "Ruby"

    ```ruby title="built_in_hash.rb"
    num = 3
    hash_num = num.hash
    # A 3 egész szám hash értéke -4385856518450339636

    bol = true
    hash_bol = bol.hash
    # A true logikai érték hash értéke -1617938112149317027

    dec = 3.14159
    hash_dec = dec.hash
    # A 3.14159 tizedes tört hash értéke -1479186995943067893

    str = "Hello 算法"
    hash_str = str.hash
    # A "Hello 算法" karakterlánc hash értéke -4075943250025831763

    tup = [12836, '小哈']
    hash_tup = tup.hash
    # A (12836, '小哈') tuple hash értéke 1999544809202288822

    obj = ListNode.new(0)
    hash_obj = obj.hash
    # A #<ListNode:0x000078133140ab70> ListNode objektum hash értéke 4302940560806366381
    ```

??? pythontutor "Vizualizált végrehajtás"

    https://pythontutor.com/render.html#code=class%20ListNode%3A%0A%20%20%20%20%22%22%22%E9%93%BE%E8%A1%A8%E8%8A%82%E7%82%B9%E7%B1%BB%22%22%22%0A%20%20%20%20def%20__init__%28self,%20val%3A%20int%29%3A%0A%20%20%20%20%20%20%20%20self.val%3A%20int%20%3D%20val%20%20%23%20%E8%8A%82%E7%82%B9%E5%80%BC%0A%20%20%20%20%20%20%20%20self.next%3A%20ListNode%20%7C%20None%20%3D%20None%20%20%23%20%E5%90%8E%E7%BB%A7%E8%8A%82%E7%82%B9%E5%BC%95%E7%94%A8%0A%0A%22%22%22Driver%20Code%22%22%22%0Aif%20__name__%20%3D%3D%20%22__main__%22%3A%0A%20%20%20%20num%20%3D%203%0A%20%20%20%20hash_num%20%3D%20hash%28num%29%0A%20%20%20%20%23%20%E6%95%B4%E6%95%B0%203%20%E7%9A%84%E5%93%88%E5%B8%8C%E5%80%BC%E4%B8%BA%203%0A%0A%20%20%20%20bol%20%3D%20True%0A%20%20%20%20hash_bol%20%3D%20hash%28bol%29%0A%20%20%20%20%23%20%E5%B8%83%E5%B0%94%E9%87%8F%20True%20%E7%9A%84%E5%93%88%E5%B8%8C%E5%80%BC%E4%B8%BA%201%0A%0A%20%20%20%20dec%20%3D%203.14159%0A%20%20%20%20hash_dec%20%3D%20hash%28dec%29%0A%20%20%20%20%23%20%E5%B0%8F%E6%95%B0%203.14159%20%E7%9A%84%E5%93%88%E5%B8%8C%E5%80%BC%E4%B8%BA%20326484311674566659%0A%0A%20%20%20%20str%20%3D%20%22Hello%20%E7%AE%97%E6%B3%95%22%0A%20%20%20%20hash_str%20%3D%20hash%28str%29%0A%20%20%20%20%23%20%E5%AD%97%E7%AC%A6%E4%B8%B2%E2%80%9CHello%20%E7%AE%97%E6%B3%95%E2%80%9D%E7%9A%84%E5%93%88%E5%B8%8C%E5%80%BC%E4%B8%BA%204617003410720528961%0A%0A%20%20%20%20tup%20%3D%20%2812836,%20%22%E5%B0%8F%E5%93%88%22%29%0A%20%20%20%20hash_tup%20%3D%20hash%28tup%29%0A%20%20%20%20%23%20%E5%85%83%E7%BB%84%20%2812836,%20'%E5%B0%8F%E5%93%88'%29%20%E7%9A%84%E5%93%88%E5%B8%8C%E5%80%BC%E4%B8%BA%201029005403108185979%0A%0A%20%20%20%20obj%20%3D%20ListNode%280%29%0A%20%20%20%20hash_obj%20%3D%20hash%28obj%29%0A%20%20%20%20%23%20%E8%8A%82%E7%82%B9%E5%AF%B9%E8%B1%A1%20%3CListNode%20object%20at%200x1058fd810%3E%20%E7%9A%84%E5%93%88%E5%B8%8C%E5%80%BC%E4%B8%BA%20274267521&cumulative=false&curInstr=19&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=311&rawInputLstJSON=%5B%5D&textReferences=false

Sok programozási nyelvben **csak megváltoztathatatlan objektumok szolgálhatnak `key`-ként a hash táblában**. Ha egy listát (dinamikus tömböt) használunk `key`-ként, amikor a lista tartalma megváltozik, a hash értéke is megváltozik, és többé nem tudnánk megtalálni az eredeti `value` értéket a hash táblában.

Bár egy egyéni objektum (pl. egy láncolt lista csomópont) tagváltozói módosíthatók, hashelhető. **Ez azért van, mert az objektum hash értéke általában a memóriacíme alapján generálódik**, és még ha az objektum tartalma megváltozik is, a memóriacíme változatlan marad, így a hash értéke is változatlan marad.

Talán észrevette, hogy a különböző konzolokban megjelenő hash értékek eltérőek. **Ez azért van, mert a Python értelmező minden egyes indítás alkalmával véletlenszerű sót ad a karakterlánc hash függvényhez**. Ez a megközelítés hatékonyan megelőzi a HashDoS támadásokat és növeli a hash algoritmus biztonságát.
