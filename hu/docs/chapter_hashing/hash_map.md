# Hash Tábla

A <u>hash tábla</u>, más néven <u>hash map</u>, leképezést hoz létre a kulcsok `key` és értékek `value` között, lehetővé téve az elemek hatékony visszakeresését. Konkrétan, amikor egy `key` kulcsot adunk meg a hash táblának, az $O(1)$ időben visszaadja a megfelelő `value` értéket.

Az alábbi ábrán látható módon, adott $n$ tanuló, mindegyikhez két adat tartozik: „név" és „diákazonosító". Ha egy olyan lekérdező függvényt szeretnénk megvalósítani, amely „diákazonosítót kap bemenetként és visszaadja a megfelelő nevet", használhatjuk az alábbi hash táblát.

![Hash tábla elvont ábrázolása](hash_map.assets/hash_table_lookup.png)

A hash táblákon kívül tömbök és láncolt listák is megvalósíthatják a lekérdezési funkcionalitást. Hatékonyságuk összehasonlítása az alábbi táblázatban látható.

- **Elem hozzáadása**: Egyszerűen adjuk hozzá az elemet a tömb (láncolt lista) végéhez, $O(1)$ időben.
- **Elem lekérdezése**: Mivel a tömb (láncolt lista) rendezetlen, az összes elemet be kell járni, $O(n)$ időt igényel.
- **Elem törlése**: Az elemet először meg kell keresni, majd törölni kell a tömbből (láncolt listából), $O(n)$ időt igényel.

<p align="center"> Table <id> &nbsp; Elemek lekérdezési hatékonyságának összehasonlítása </p>

|                 | Tömb   | Láncolt lista | Hash tábla |
| --------------- | ------ | ------------- | ---------- |
| Elem keresése   | $O(n)$ | $O(n)$        | $O(1)$     |
| Elem hozzáadása | $O(1)$ | $O(1)$        | $O(1)$     |
| Elem törlése    | $O(n)$ | $O(n)$        | $O(1)$     |

Mint látható, **a hash táblában végzett beszúrás, törlés, keresés és módosítás műveletek időbonyolultsága $O(1)$**, ami igen hatékony.

## A Hash Tábla Gyakori Műveletei

A hash táblák gyakori műveletei közé tartozik: inicializálás, lekérdezési műveletek, kulcs-érték párok hozzáadása és törlése. A példakód a következő:

=== "Python"

    ```python title="hash_map.py"
    # Hash tábla inicializálása
    hmap: dict = {}

    # Hozzáadás művelet
    # Kulcs-érték pár (key, value) hozzáadása a hash táblához
    hmap[12836] = "XiaoHa"
    hmap[15937] = "XiaoLuo"
    hmap[16750] = "XiaoSuan"
    hmap[13276] = "XiaoFa"
    hmap[10583] = "XiaoYa"

    # Lekérdezés művelet
    # Kulcs beadása a hash táblába az érték lekérdezéséhez
    name: str = hmap[15937]

    # Törlés művelet
    # Kulcs-érték pár (key, value) törlése a hash táblából
    hmap.pop(10583)
    ```

=== "C++"

    ```cpp title="hash_map.cpp"
    /* Hash tábla inicializálása */
    unordered_map<int, string> map;

    /* Hozzáadás művelet */
    // Kulcs-érték pár (key, value) hozzáadása a hash táblához
    map[12836] = "XiaoHa";
    map[15937] = "XiaoLuo";
    map[16750] = "XiaoSuan";
    map[13276] = "XiaoFa";
    map[10583] = "XiaoYa";

    /* Lekérdezés művelet */
    // Kulcs beadása a hash táblába az érték lekérdezéséhez
    string name = map[15937];

    /* Törlés művelet */
    // Kulcs-érték pár (key, value) törlése a hash táblából
    map.erase(10583);
    ```

=== "Java"

    ```java title="hash_map.java"
    /* Hash tábla inicializálása */
    Map<Integer, String> map = new HashMap<>();

    /* Hozzáadás művelet */
    // Kulcs-érték pár (key, value) hozzáadása a hash táblához
    map.put(12836, "XiaoHa");
    map.put(15937, "XiaoLuo");
    map.put(16750, "XiaoSuan");
    map.put(13276, "XiaoFa");
    map.put(10583, "XiaoYa");

    /* Lekérdezés művelet */
    // Kulcs beadása a hash táblába az érték lekérdezéséhez
    String name = map.get(15937);

    /* Törlés művelet */
    // Kulcs-érték pár (key, value) törlése a hash táblából
    map.remove(10583);
    ```

=== "C#"

    ```csharp title="hash_map.cs"
    /* Hash tábla inicializálása */
    Dictionary<int, string> map = new() {
        /* Hozzáadás művelet */
        // Kulcs-érték pár (key, value) hozzáadása a hash táblához
        { 12836, "XiaoHa" },
        { 15937, "XiaoLuo" },
        { 16750, "XiaoSuan" },
        { 13276, "XiaoFa" },
        { 10583, "XiaoYa" }
    };

    /* Lekérdezés művelet */
    // Kulcs beadása a hash táblába az érték lekérdezéséhez
    string name = map[15937];

    /* Törlés művelet */
    // Kulcs-érték pár (key, value) törlése a hash táblából
    map.Remove(10583);
    ```

=== "Go"

    ```go title="hash_map_test.go"
    /* Hash tábla inicializálása */
    hmap := make(map[int]string)

    /* Hozzáadás művelet */
    // Kulcs-érték pár (key, value) hozzáadása a hash táblához
    hmap[12836] = "XiaoHa"
    hmap[15937] = "XiaoLuo"
    hmap[16750] = "XiaoSuan"
    hmap[13276] = "XiaoFa"
    hmap[10583] = "XiaoYa"

    /* Lekérdezés művelet */
    // Kulcs beadása a hash táblába az érték lekérdezéséhez
    name := hmap[15937]

    /* Törlés művelet */
    // Kulcs-érték pár (key, value) törlése a hash táblából
    delete(hmap, 10583)
    ```

=== "Swift"

    ```swift title="hash_map.swift"
    /* Hash tábla inicializálása */
    var map: [Int: String] = [:]

    /* Hozzáadás művelet */
    // Kulcs-érték pár (key, value) hozzáadása a hash táblához
    map[12836] = "XiaoHa"
    map[15937] = "XiaoLuo"
    map[16750] = "XiaoSuan"
    map[13276] = "XiaoFa"
    map[10583] = "XiaoYa"

    /* Lekérdezés művelet */
    // Kulcs beadása a hash táblába az érték lekérdezéséhez
    let name = map[15937]!

    /* Törlés művelet */
    // Kulcs-érték pár (key, value) törlése a hash táblából
    map.removeValue(forKey: 10583)
    ```

=== "JS"

    ```javascript title="hash_map.js"
    /* Hash tábla inicializálása */
    const map = new Map();
    /* Hozzáadás művelet */
    // Kulcs-érték pár (key, value) hozzáadása a hash táblához
    map.set(12836, 'XiaoHa');
    map.set(15937, 'XiaoLuo');
    map.set(16750, 'XiaoSuan');
    map.set(13276, 'XiaoFa');
    map.set(10583, 'XiaoYa');

    /* Lekérdezés művelet */
    // Kulcs beadása a hash táblába az érték lekérdezéséhez
    let name = map.get(15937);

    /* Törlés művelet */
    // Kulcs-érték pár (key, value) törlése a hash táblából
    map.delete(10583);
    ```

=== "TS"

    ```typescript title="hash_map.ts"
    /* Hash tábla inicializálása */
    const map = new Map<number, string>();
    /* Hozzáadás művelet */
    // Kulcs-érték pár (key, value) hozzáadása a hash táblához
    map.set(12836, 'XiaoHa');
    map.set(15937, 'XiaoLuo');
    map.set(16750, 'XiaoSuan');
    map.set(13276, 'XiaoFa');
    map.set(10583, 'XiaoYa');
    console.info('\nHozzáadás után, a hash tábla tartalma\nKulcs -> Érték');
    console.info(map);

    /* Lekérdezés művelet */
    // Kulcs beadása a hash táblába az érték lekérdezéséhez
    let name = map.get(15937);
    console.info('\n15937 diákazonosítóval lekérdezett név ' + name);

    /* Törlés művelet */
    // Kulcs-érték pár (key, value) törlése a hash táblából
    map.delete(10583);
    console.info('\n10583 törlése után, a hash tábla tartalma\nKulcs -> Érték');
    console.info(map);
    ```

=== "Dart"

    ```dart title="hash_map.dart"
    /* Hash tábla inicializálása */
    Map<int, String> map = {};

    /* Hozzáadás művelet */
    // Kulcs-érték pár (key, value) hozzáadása a hash táblához
    map[12836] = "XiaoHa";
    map[15937] = "XiaoLuo";
    map[16750] = "XiaoSuan";
    map[13276] = "XiaoFa";
    map[10583] = "XiaoYa";

    /* Lekérdezés művelet */
    // Kulcs beadása a hash táblába az érték lekérdezéséhez
    String name = map[15937];

    /* Törlés művelet */
    // Kulcs-érték pár (key, value) törlése a hash táblából
    map.remove(10583);
    ```

=== "Rust"

    ```rust title="hash_map.rs"
    use std::collections::HashMap;

    /* Hash tábla inicializálása */
    let mut map: HashMap<i32, String> = HashMap::new();

    /* Hozzáadás művelet */
    // Kulcs-érték pár (key, value) hozzáadása a hash táblához
    map.insert(12836, "XiaoHa".to_string());
    map.insert(15937, "XiaoLuo".to_string());
    map.insert(16750, "XiaoSuan".to_string());
    map.insert(13279, "XiaoFa".to_string());
    map.insert(10583, "XiaoYa".to_string());

    /* Lekérdezés művelet */
    // Kulcs beadása a hash táblába az érték lekérdezéséhez
    let _name: Option<&String> = map.get(&15937);

    /* Törlés művelet */
    // Kulcs-érték pár (key, value) törlése a hash táblából
    let _removed_value: Option<String> = map.remove(&10583);
    ```

=== "C"

    ```c title="hash_map.c"
    // C nem rendelkezik beépített hash táblával
    ```

=== "Kotlin"

    ```kotlin title="hash_map.kt"
    /* Hash tábla inicializálása */
    val map = HashMap<Int,String>()

    /* Hozzáadás művelet */
    // Kulcs-érték pár (key, value) hozzáadása a hash táblához
    map[12836] = "XiaoHa"
    map[15937] = "XiaoLuo"
    map[16750] = "XiaoSuan"
    map[13276] = "XiaoFa"
    map[10583] = "XiaoYa"

    /* Lekérdezés művelet */
    // Kulcs beadása a hash táblába az érték lekérdezéséhez
    val name = map[15937]

    /* Törlés művelet */
    // Kulcs-érték pár (key, value) törlése a hash táblából
    map.remove(10583)
    ```

=== "Ruby"

    ```ruby title="hash_map.rb"
    # Hash tábla inicializálása
    hmap = {}

    # Hozzáadás művelet
    # Kulcs-érték pár (key, value) hozzáadása a hash táblához
    hmap[12836] = "XiaoHa"
    hmap[15937] = "XiaoLuo"
    hmap[16750] = "XiaoSuan"
    hmap[13276] = "XiaoFa"
    hmap[10583] = "XiaoYa"

    # Lekérdezés művelet
    # Kulcs beadása a hash táblába az érték lekérdezéséhez
    name = hmap[15937]

    # Törlés művelet
    # Kulcs-érték pár (key, value) törlése a hash táblából
    hmap.delete(10583)
    ```

??? pythontutor "Vizualizált végrehajtás"

    https://pythontutor.com/render.html#code=%22%22%22Driver%20Code%22%22%22%0Aif%20__name__%20%3D%3D%20%22__main__%22%3A%0A%20%20%20%20%23%20%E5%88%9D%E5%A7%8B%E5%8C%96%E5%93%88%E5%B8%8C%E8%A1%A8%0A%20%20%20%20hmap%20%3D%20%7B%7D%0A%20%20%20%20%0A%20%20%20%20%23%20%E6%B7%BB%E5%8A%A0%E6%93%8D%E4%BD%9C%0A%20%20%20%20%23%20%E5%9C%A8%E5%93%88%E5%B8%8C%E8%A1%A8%E4%B8%AD%E6%B7%BB%E5%8A%A0%E9%94%AE%E5%80%BC%E5%AF%B9%20%28key,%20value%29%0A%20%20%20%20hmap%5B12836%5D%20%3D%20%22%E5%B0%8F%E5%93%88%22%0A%20%20%20%20hmap%5B15937%5D%20%3D%20%22%E5%B0%8F%E5%95%B0%22%0A%20%20%20%20hmap%5B16750%5D%20%3D%20%22%E5%B0%8F%E7%AE%97%22%0A%20%20%20%20hmap%5B13276%5D%20%3D%20%22%E5%B0%8F%E6%B3%95%22%0A%20%20%20%20hmap%5B10583%5D%20%3D%20%22%E5%B0%8F%E9%B8%AD%22%0A%20%20%20%20%0A%20%20%20%20%23%20%E6%9F%A5%E8%AF%A2%E6%93%8D%E4%BD%9C%0A%20%20%20%20%23%20%E5%90%91%E5%93%88%E5%B8%8C%E8%A1%A8%E4%B8%AD%E8%BE%93%E5%85%A5%E9%94%AE%20key%20%EF%BC%8C%E5%BE%97%E5%88%B0%E5%80%BC%20value%0A%20%20%20%20name%20%3D%20hmap%5B15937%5D%0A%20%20%20%20%0A%20%20%20%20%23%20%E5%88%A0%E9%99%A4%E6%93%8D%E4%BD%9C%0A%20%20%20%20%23%20%E5%9C%A8%E5%93%88%E5%B8%8C%E8%A1%A8%E4%B8%AD%E5%88%A0%E9%99%A4%E9%94%AE%E5%80%BC%E5%AF%B9%20%28key,%20value%29%0A%20%20%20%20hmap.pop%2810583%29&cumulative=false&curInstr=2&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=311&rawInputLstJSON=%5B%5D&textReferences=false

A hash táblát háromféleképpen lehet bejárni: kulcs-érték párok bejárása, kulcsok bejárása és értékek bejárása. A példakód a következő:

=== "Python"

    ```python title="hash_map.py"
    # Hash tábla bejárása
    # Kulcs-érték párok bejárása key->value
    for key, value in hmap.items():
        print(key, "->", value)
    # Csak kulcsok bejárása
    for key in hmap.keys():
        print(key)
    # Csak értékek bejárása
    for value in hmap.values():
        print(value)
    ```

=== "C++"

    ```cpp title="hash_map.cpp"
    /* Hash tábla bejárása */
    // Kulcs-érték párok bejárása key->value
    for (auto kv: map) {
        cout << kv.first << " -> " << kv.second << endl;
    }
    // Bejárás iterátorral key->value
    for (auto iter = map.begin(); iter != map.end(); iter++) {
        cout << iter->first << "->" << iter->second << endl;
    }
    ```

=== "Java"

    ```java title="hash_map.java"
    /* Hash tábla bejárása */
    // Kulcs-érték párok bejárása key->value
    for (Map.Entry<Integer, String> kv: map.entrySet()) {
        System.out.println(kv.getKey() + " -> " + kv.getValue());
    }
    // Csak kulcsok bejárása
    for (int key: map.keySet()) {
        System.out.println(key);
    }
    // Csak értékek bejárása
    for (String val: map.values()) {
        System.out.println(val);
    }
    ```

=== "C#"

    ```csharp title="hash_map.cs"
    /* Hash tábla bejárása */
    // Kulcs-érték párok bejárása Key->Value
    foreach (var kv in map) {
        Console.WriteLine(kv.Key + " -> " + kv.Value);
    }
    // Csak kulcsok bejárása
    foreach (int key in map.Keys) {
        Console.WriteLine(key);
    }
    // Csak értékek bejárása
    foreach (string val in map.Values) {
        Console.WriteLine(val);
    }
    ```

=== "Go"

    ```go title="hash_map_test.go"
    /* Hash tábla bejárása */
    // Kulcs-érték párok bejárása key->value
    for key, value := range hmap {
        fmt.Println(key, "->", value)
    }
    // Csak kulcsok bejárása
    for key := range hmap {
        fmt.Println(key)
    }
    // Csak értékek bejárása
    for _, value := range hmap {
        fmt.Println(value)
    }
    ```

=== "Swift"

    ```swift title="hash_map.swift"
    /* Hash tábla bejárása */
    // Kulcs-érték párok bejárása Key->Value
    for (key, value) in map {
        print("\(key) -> \(value)")
    }
    // Csak kulcsok bejárása
    for key in map.keys {
        print(key)
    }
    // Csak értékek bejárása
    for value in map.values {
        print(value)
    }
    ```

=== "JS"

    ```javascript title="hash_map.js"
    /* Hash tábla bejárása */
    console.info('\nKulcs-érték párok bejárása Key->Value');
    for (const [k, v] of map.entries()) {
        console.info(k + ' -> ' + v);
    }
    console.info('\nCsak kulcsok bejárása Key');
    for (const k of map.keys()) {
        console.info(k);
    }
    console.info('\nCsak értékek bejárása Value');
    for (const v of map.values()) {
        console.info(v);
    }
    ```

=== "TS"

    ```typescript title="hash_map.ts"
    /* Hash tábla bejárása */
    console.info('\nKulcs-érték párok bejárása Key->Value');
    for (const [k, v] of map.entries()) {
        console.info(k + ' -> ' + v);
    }
    console.info('\nCsak kulcsok bejárása Key');
    for (const k of map.keys()) {
        console.info(k);
    }
    console.info('\nCsak értékek bejárása Value');
    for (const v of map.values()) {
        console.info(v);
    }
    ```

=== "Dart"

    ```dart title="hash_map.dart"
    /* Hash tábla bejárása */
    // Kulcs-érték párok bejárása Key->Value
    map.forEach((key, value) {
      print('$key -> $value');
    });

    // Csak kulcsok bejárása
    map.keys.forEach((key) {
      print(key);
    });

    // Csak értékek bejárása
    map.values.forEach((value) {
      print(value);
    });
    ```

=== "Rust"

    ```rust title="hash_map.rs"
    /* Hash tábla bejárása */
    // Kulcs-érték párok bejárása Key->Value
    for (key, value) in &map {
        println!("{key} -> {value}");
    }

    // Csak kulcsok bejárása
    for key in map.keys() {
        println!("{key}");
    }

    // Csak értékek bejárása
    for value in map.values() {
        println!("{value}");
    }
    ```

=== "C"

    ```c title="hash_map.c"
    // C nem rendelkezik beépített hash táblával
    ```

=== "Kotlin"

    ```kotlin title="hash_map.kt"
    /* Hash tábla bejárása */
    // Kulcs-érték párok bejárása key->value
    for ((key, value) in map) {
        println("$key -> $value")
    }
    // Csak kulcsok bejárása
    for (key in map.keys) {
        println(key)
    }
    // Csak értékek bejárása
    for (_val in map.values) {
        println(_val)
    }
    ```

=== "Ruby"

    ```ruby title="hash_map.rb"
    # Hash tábla bejárása
    # Kulcs-érték párok bejárása key->value
    hmap.entries.each { |key, value| puts "#{key} -> #{value}" }

    # Csak kulcsok bejárása
    hmap.keys.each { |key| puts key }

    # Csak értékek bejárása
    hmap.values.each { |val| puts val }
    ```

??? pythontutor "Vizualizált végrehajtás"

    https://pythontutor.com/render.html#code=%22%22%22Driver%20Code%22%22%22%0Aif%20__name__%20%3D%3D%20%22__main__%22%3A%0A%20%20%20%20%23%20%E5%88%9D%E5%A7%8B%E5%8C%96%E5%93%88%E5%B8%8C%E8%A1%A8%0A%20%20%20%20hmap%20%3D%20%7B%7D%0A%20%20%20%20%0A%20%20%20%20%23%20%E6%B7%BB%E5%8A%A0%E6%93%8D%E4%BD%9C%0A%20%20%20%20%23%20%E5%9C%A8%E5%93%88%E5%B8%8C%E8%A1%A8%E4%B8%AD%E6%B7%BB%E5%8A%A0%E9%94%AE%E5%80%BC%E5%AF%B9%20%28key,%20value%29%0A%20%20%20%20hmap%5B12836%5D%20%3D%20%22%E5%B0%8F%E5%93%88%22%0A%20%20%20%20hmap%5B15937%5D%20%3D%20%22%E5%B0%8F%E5%95%B0%22%0A%20%20%20%20hmap%5B16750%5D%20%3D%20%22%E5%B0%8F%E7%AE%97%22%0A%20%20%20%20hmap%5B13276%5D%20%3D%20%22%E5%B0%8F%E6%B3%95%22%0A%20%20%20%20hmap%5B10583%5D%20%3D%20%22%E5%B0%8F%E9%B8%AD%22%0A%20%20%20%20%0A%20%20%20%20%23%20%E9%81%8D%E5%8E%86%E5%93%88%E5%B8%8C%E8%A1%A8%0A%20%20%20%20%23%20%E9%81%8D%E5%8E%86%E9%94%AE%E5%80%BC%E5%AF%B9%20key-%3Evalue%0A%20%20%20%20for%20key,%20value%20in%20hmap.items%28%29%3A%0A%20%20%20%20%20%20%20%20print%28key,%20%22-%3E%22,%20value%29%0A%20%20%20%20%23%20%E5%8D%95%E7%8B%AC%E9%81%8D%E5%8E%86%E9%94%AE%20key%0A%20%20%20%20for%20key%20in%20hmap.keys%28%29%3A%0A%20%20%20%20%20%20%20%20print%28key%29%0A%20%20%20%20%23%20%E5%8D%95%E7%8B%AC%E9%81%8D%E5%8E%86%E5%80%BC%20value%0A%20%20%20%20for%20value%20in%20hmap.values%28%29%3A%0A%20%20%20%20%20%20%20%20print%28value%29&cumulative=false&curInstr=8&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=311&rawInputLstJSON=%5B%5D&textReferences=false

## Egyszerű Hash Tábla Megvalósítása

Először is tekintsük a legegyszerűbb esetet: **hash tábla megvalósítása kizárólag tömb segítségével**. A hash táblában a tömb minden üres pozícióját <u>vödörnek</u> nevezzük, és minden vödör tárolhat egy kulcs-érték párt. Ezért a lekérdezési művelet azt jelenti, hogy megkeressük a `key`-nek megfelelő vödröt, és visszaolvasunk belőle egy `value` értéket.

Hogyan határozzuk meg a megfelelő vödröt a `key` alapján? Ezt egy <u>hash függvény</u> segítségével érjük el. A hash függvény szerepe az, hogy egy nagyobb bemeneti teret egy kisebb kimeneti térre képez le. A hash táblában a bemeneti tér az összes `key`, a kimeneti tér pedig az összes vödör (tömbindexek). Más szóval, adott egy `key`, **a hash függvénnyel meghatározhatjuk az adott `key`-hez tartozó kulcs-érték pár tárolási helyét a tömbben**.

Egy `key` bevitelekor a hash függvény számítási folyamata a következő két lépésből áll:

1. A hash érték kiszámítása a `hash()` hash algoritmus segítségével.
2. A hash érték modulójának vétele a vödrök számával (tömb hosszával) `capacity`, hogy megkapjuk a `key`-nek megfelelő vödöt (tömbindexet) `index`.

```shell
index = hash(key) % capacity
```

Ezt követően az `index` segítségével hozzáférhetünk a hash tábla megfelelő vödréhez és visszakereshetjük a `value` értéket.

Tegyük fel, hogy a tömb hossza `capacity = 100` és a hash algoritmus `hash(key) = key`, akkor a hash függvény `key % 100` lesz. Az alábbi ábra a hash függvény működési elvét mutatja be, ahol `key` a diákazonosító, `value` pedig a név.

![A hash függvény működési elve](hash_map.assets/hash_function.png)

A következő kód egy egyszerű hash táblát valósít meg. A `key` és `value` egy `Pair` osztályba van csomagolva, hogy kulcs-érték párt képviseljen.

```src
[file]{array_hash_map}-[class]{array_hash_map}-[func]{}
```

## Hash Ütközés és Átméretezés

Alapvetően a hash függvény szerepe az, hogy az összes `key`-ből álló bemeneti teret az összes tömbindexet tartalmazó kimeneti térre képezze le, és a bemeneti tér általában sokkal nagyobb a kimeneti térnél. Ezért **elméletileg elkerülhetetlen, hogy „több bemenetnek ugyanaz az kimenet legyen"**.

A fenti példában szereplő hash függvény esetén, ha a bemeneti `key`-ek azonos utolsó két számjeggyel rendelkeznek, a hash függvény azonos kimenetet ad. Például, ha két tanulót keresünk 12836 és 20336 azonosítóval:

```shell
12836 % 100 = 36
20336 % 100 = 36
```

Az alábbi ábrán látható módon két diákazonosító ugyanarra a névre mutat, ami nyilvánvalóan helytelen. Ezt a helyzetet, amikor több bemenetnek azonos kimenete van, <u>hash ütközésnek</u> nevezzük.

![Hash ütközés példa](hash_map.assets/hash_collision.png)

Könnyen belátható, hogy minél nagyobb a hash tábla kapacitása $n$, annál kisebb a valószínűsége, hogy több `key` ugyanabba a vödörbe kerüljön, és annál kevesebb az ütközés. Ezért **hash ütközéseket csökkenthetjük a hash tábla bővítésével**.

Az alábbi ábrán látható, hogy a bővítés előtt a `(136, A)` és `(236, D)` kulcs-érték párok ütköztek, de a bővítés után az ütközés eltűnik.

![Hash tábla átméretezése](hash_map.assets/hash_table_reshash.png)

A tömbbővítéshez hasonlóan a hash tábla bővítése is az összes kulcs-érték pár áttelepítését igényli az eredeti hash táblából az újba, ami igen időigényes. Ráadásul, mivel a hash tábla kapacitása `capacity` megváltozik, a hash függvényen keresztül újra kell számítani az összes kulcs-érték pár tárolási helyét, ami tovább növeli a bővítési folyamat számítási terhelését. Ezért a programozási nyelvek általában elég nagy hash tábla kapacitást tartanak fenn a gyakori bővítések elkerülése érdekében.

A <u>terhelési tényező</u> a hash táblák fontos fogalma. Definíció szerint a hash táblában lévő elemek számát osztjuk a vödrök számával, és a hash ütközések súlyosságának mérésére szolgál. **Általában a hash tábla bővítésének kiváltó feltételeként is használják**. Például Java-ban, ha a terhelési tényező meghaladja a $0.75$-öt, a rendszer az eredeti méret $2$-szeresére bővíti a hash táblát.
