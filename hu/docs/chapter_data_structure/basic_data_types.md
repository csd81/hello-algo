# Alapvető adattípusok

Amikor a számítógépekben tárolt adatokra gondolunk, olyan különböző formákra asszociálunk, mint szöveg, képek, videók, hanganyagok, 3D-modellek és egyebek. Bár ezek az adatok különbözőképpen szerveződnek, mindegyikük különféle alapvető adattípusokból épül fel.

**Az alapvető adattípusok olyan típusok, amelyekkel a CPU közvetlenül tud műveleteket végezni**, és közvetlenül alkalmazzák őket az algoritmusokban; főként a következőket foglalják magukban.

- Egész típusok: `byte`, `short`, `int`, `long`.
- Lebegőpontos típusok: `float`, `double`, tizedes törtek ábrázolására.
- Karakter típus: `char`, különböző nyelvek betűinek, írásjeljeinek, sőt emojijainak ábrázolására.
- Logikai típus: `bool`, „igen" és „nem" jellegű döntések ábrázolására.

**Az alapvető adattípusok bináris formában tárolódnak a számítógépekben**. Egy bináris bit $1$ bit. A legtöbb modern operációs rendszerben $1$ bájt $8$ bitből áll.

Az alapvető adattípusok értékkészletének terjedelme a foglalt hely méretétől függ. Az alábbiakban Java-példán keresztül mutatjuk be.

- Az egész típusú `byte` $1$ bájtot = $8$ bitet foglal, és $2^{8}$ számot tud ábrázolni.
- Az egész típusú `int` $4$ bájtot = $32$ bitet foglal, és $2^{32}$ számot tud ábrázolni.

Az alábbi táblázat felsorolja a Java különböző alapvető adattípusainak foglalt helyét, értékkészletét és alapértelmezett értékeit. Nem szükséges ezt a táblázatot fejből megtanulni; elegendő az általános értés, és szükség esetén vissza lehet rá nézni.

<p align="center"> Táblázat <id> &nbsp; Az alapvető adattípusok foglalt helye és értékkészlete </p>

| Típus      | Jelölés  | Foglalt hely | Minimális érték          | Maximális érték         | Alapértelmezett érték |
| ---------- | -------- | ------------ | ------------------------ | ----------------------- | --------------------- |
| Egész szám | `byte`   | 1 bájt       | $-2^7$ ($-128$)          | $2^7 - 1$ ($127$)       | $0$                   |
|            | `short`  | 2 bájt       | $-2^{15}$                | $2^{15} - 1$            | $0$                   |
|            | `int`    | 4 bájt       | $-2^{31}$                | $2^{31} - 1$            | $0$                   |
|            | `long`   | 8 bájt       | $-2^{63}$                | $2^{63} - 1$            | $0$                   |
| Lebegőpontos | `float`  | 4 bájt     | $1.175 \times 10^{-38}$  | $3.403 \times 10^{38}$  | $0.0\text{f}$         |
|            | `double` | 8 bájt       | $2.225 \times 10^{-308}$ | $1.798 \times 10^{308}$ | $0.0$                 |
| Karakter   | `char`   | 2 bájt       | $0$                      | $2^{16} - 1$            | $0$                   |
| Logikai    | `bool`   | 1 bájt       | $\text{false}$           | $\text{true}$           | $\text{false}$        |

Vegyük figyelembe, hogy a fenti táblázat a Java alapvető adattípusaira vonatkozik. Minden programozási nyelvnek megvannak a saját adattípus-meghatározásai, és ezek foglalt helye, értékkészlete és alapértelmezett értékei eltérhetnek.

- Pythonban az egész típusú `int` tetszőleges méretű lehet, csak az elérhető memória szabja meg; a `float` lebegőpontos típus kétszeres pontosságú 64 bites; nincs `char` típus, egyetlen karakter valójában $1$ hosszúságú `str` karakterlánc.
- C és C++ nem határozza meg expliciten az alapvető adattípusok méretét, ez implementációtól és platformtól függ. A fenti táblázat az LP64 [adatmodellt](https://en.cppreference.com/w/cpp/language/types#Properties) követi, amelyet Unix 64 bites operációs rendszereken – köztük Linuxon és macOS-en – használnak.
- A `char` karakterméret C-ben és C++-ban 1 bájt, a legtöbb programozási nyelvben pedig a konkrét karakterkódolási módtól függ, ahogyan azt a „Karakterkódolás" fejezet részletezi.
- Bár egy logikai értéket mindössze 1 bit ($0$ vagy $1$) elegendő lenne tárolni, memóriában általában 1 bájtként tárolódik. Ennek oka, hogy a modern számítógépes CPU-k tipikusan 1 bájtot használnak a legkisebb címezhető memóriaegységként.

Mi a kapcsolat tehát az alapvető adattípusok és az adatszerkezetek között? Tudjuk, hogy az adatszerkezetek az adatok számítógépes szervezésének és tárolásának módjai. Ebben a kijelentésben a hangsúly a „szerkezeten" van, nem az „adaton".

Ha „egy sor számot" szeretnénk ábrázolni, természetesen tömbre gondolunk. Ez azért van, mert a tömb lineáris szerkezete képes megjeleníteni a számok szomszédossági és sorrendiségi viszonyait, de hogy a tartalom egész `int`, lebegőpontos `float` vagy karakter `char`-e, az független az „adatszerkezettől".

Más szóval, **az alapvető adattípusok az adatok „tartalomtípusát" adják meg, míg az adatszerkezetek az adatok „szervezési módját"**. Például az alábbi kódban ugyanazt az adatszerkezetet (tömböt) használjuk különböző alapvető adattípusok – `int`, `float`, `char`, `bool` stb. – tárolására és ábrázolására.

=== "Python"

    ```python title=""
    # Tömbök inicializálása különböző alapvető adattípusokkal
    numbers: list[int] = [0] * 5
    decimals: list[float] = [0.0] * 5
    # Pythonban a karakterek valójában 1 hosszúságú karakterláncok
    characters: list[str] = ['0'] * 5
    bools: list[bool] = [False] * 5
    # A Python listák szabadon tárolhatnak különböző alapvető adattípusokat és objektumhivatkozásokat
    data = [0, 0.0, 'a', False, ListNode(0)]
    ```

=== "C++"

    ```cpp title=""
    // Tömbök inicializálása különböző alapvető adattípusokkal
    int numbers[5];
    float decimals[5];
    char characters[5];
    bool bools[5];
    ```

=== "Java"

    ```java title=""
    // Tömbök inicializálása különböző alapvető adattípusokkal
    int[] numbers = new int[5];
    float[] decimals = new float[5];
    char[] characters = new char[5];
    boolean[] bools = new boolean[5];
    ```

=== "C#"

    ```csharp title=""
    // Tömbök inicializálása különböző alapvető adattípusokkal
    int[] numbers = new int[5];
    float[] decimals = new float[5];
    char[] characters = new char[5];
    bool[] bools = new bool[5];
    ```

=== "Go"

    ```go title=""
    // Tömbök inicializálása különböző alapvető adattípusokkal
    var numbers = [5]int{}
    var decimals = [5]float64{}
    var characters = [5]byte{}
    var bools = [5]bool{}
    ```

=== "Swift"

    ```swift title=""
    // Tömbök inicializálása különböző alapvető adattípusokkal
    let numbers = Array(repeating: 0, count: 5)
    let decimals = Array(repeating: 0.0, count: 5)
    let characters: [Character] = Array(repeating: "a", count: 5)
    let bools = Array(repeating: false, count: 5)
    ```

=== "JS"

    ```javascript title=""
    // A JavaScript tömbök szabadon tárolhatnak különböző alapvető adattípusokat és objektumokat
    const array = [0, 0.0, 'a', false];
    ```

=== "TS"

    ```typescript title=""
    // Tömbök inicializálása különböző alapvető adattípusokkal
    const numbers: number[] = [];
    const characters: string[] = [];
    const bools: boolean[] = [];
    ```

=== "Dart"

    ```dart title=""
    // Tömbök inicializálása különböző alapvető adattípusokkal
    List<int> numbers = List.filled(5, 0);
    List<double> decimals = List.filled(5, 0.0);
    List<String> characters = List.filled(5, 'a');
    List<bool> bools = List.filled(5, false);
    ```

=== "Rust"

    ```rust title=""
    // Tömbök inicializálása különböző alapvető adattípusokkal
    let numbers: Vec<i32> = vec![0; 5];
    let decimals: Vec<f32> = vec![0.0; 5];
    let characters: Vec<char> = vec!['0'; 5];
    let bools: Vec<bool> = vec![false; 5];
    ```

=== "C"

    ```c title=""
    // Tömbök inicializálása különböző alapvető adattípusokkal
    int numbers[10];
    float decimals[10];
    char characters[10];
    bool bools[10];
    ```

=== "Kotlin"

    ```kotlin title=""
    // Tömbök inicializálása különböző alapvető adattípusokkal
    val numbers = IntArray(5)
    val decinals = FloatArray(5)
    val characters = CharArray(5)
    val bools = BooleanArray(5)
    ```

=== "Ruby"

    ```ruby title=""
    # A Ruby listák szabadon tárolhatnak különböző alapvető adattípusokat és objektumhivatkozásokat
    data = [0, 0.0, 'a', false, ListNode(0)]
    ```

??? pythontutor "Vizualizált végrehajtás"

    https://pythontutor.com/render.html#code=class%20ListNode%3A%0A%20%20%20%20%22%22%22%E9%93%BE%E8%A1%A8%E8%8A%82%E7%82%B9%E7%B1%BB%22%22%22%0A%20%20%20%20def%20__init__%28self,%20val%3A%20int%29%3A%0A%20%20%20%20%20%20%20%20self.val%3A%20int%20%3D%20val%20%20%23%20%E8%8A%82%E7%82%B9%E5%80%BC%0A%20%20%20%20%20%20%20%20self.next%3A%20ListNode%20%7C%20None%20%3D%20None%20%20%23%20%E5%90%8E%E7%BB%A7%E8%8A%82%E7%82%B9%E5%BC%95%E7%94%A8%0A%0A%22%22%22Driver%20Code%22%22%22%0Aif%20__name__%20%3D%3D%20%22__main__%22%3A%0A%20%20%20%20%23%20%E4%BD%BF%E7%94%A8%E5%A4%9A%E7%A7%8D%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%B1%BB%E5%9E%8B%E6%9D%A5%E5%88%9D%E5%A7%8B%E5%8C%96%E6%95%B0%E7%BB%84%0A%20%20%20%20numbers%20%3D%20%5B0%5D%20*%205%0A%20%20%20%20decimals%20%3D%20%5B0.0%5D%20*%205%0A%20%20%20%20%23%20Python%20%E7%9A%84%E5%AD%97%E7%AC%A6%E5%AE%9E%E9%99%85%E4%B8%8A%E6%98%AF%E9%95%BF%E5%BA%A6%E4%B8%BA%201%20%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2%0A%20%20%20%20characters%20%3D%20%5B'0'%5D%20*%205%0A%20%20%20%20bools%20%3D%20%5BFalse%5D%20*%205%0A%20%20%20%20%23%20Python%20%E7%9A%84%E5%88%97%E8%A1%A8%E5%8F%AF%E4%BB%A5%E8%87%AA%E7%94%B1%E5%AD%98%E5%82%A8%E5%90%84%E7%A7%8D%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%B1%BB%E5%9E%8B%E5%92%8C%E5%AF%B9%E8%B1%A1%E5%BC%95%E7%94%A8%0A%20%20%20%20data%20%3D%20%5B0,%200.0,%20'a',%20False,%20ListNode%280%29%5D&cumulative=false&curInstr=12&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=311&rawInputLstJSON=%5B%5D&textReferences=false
