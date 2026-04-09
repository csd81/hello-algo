# Lista

A <u>lista</u> egy absztrakt adatstruktúra-fogalom, amely elemek rendezett gyűjteményét jelenti, és olyan műveleteket támogat, mint az elemek elérése, módosítása, beszúrása, törlése és bejárása, anélkül hogy a felhasználónak kapacitáskorlátokkal kellene foglalkoznia. A listák megvalósíthatók láncolt listák vagy tömbök alapján.

- A láncolt lista természetesen tekinthető listaként, amely támogatja az elemek beszúrását, törlését, keresését és módosítását, és rugalmasan bővíthető dinamikusan.
- A tömb szintén támogatja az elemek beszúrását, törlését, keresését és módosítását, de mivel hossza nem változtatható, csak hosszkorláttal rendelkező listaként tekinthető.

Tömbök alapján listák megvalósításakor **a változtathatatlan hossz tulajdonság csökkenti a lista hasznosságát**. Ez azért van, mert általában nem tudjuk előre, mennyi adatot kell tárolni, ezért nehéz megfelelő lista hosszt választani. Ha a hossz túl kicsi, nem felelhet meg a használati igényeknek; ha túl nagy, memóriaterületet pazarol.

Ennek a problémának a megoldásához <u>dinamikus tömböt</u> használhatunk lista megvalósítására. Ez örökli a tömbök összes előnyét, és a program végrehajtása során dinamikusan bővíthető.

Valójában **sok programozási nyelv standard könyvtárában található lista dinamikus tömbök alapján valósul meg**, mint például a Pythonban lévő `list`, a Java-ban az `ArrayList`, a C++-ban a `vector`, és a C#-ban a `List`. Az alábbi tárgyalásban a "lista" és a "dinamikus tömb" fogalmakat egyenértékűként kezeljük.

## A Lista Általános Műveletei

### Lista Inicializálása

Általában két inicializálási módszert alkalmazunk: "kezdőértékek nélkül" és "kezdőértékekkel":

=== "Python"

    ```python title="list.py"
    # Lista inicializálása
    # Kezdőértékek nélkül
    nums1: list[int] = []
    # Kezdőértékekkel
    nums: list[int] = [1, 3, 2, 5, 4]
    ```

=== "C++"

    ```cpp title="list.cpp"
    /* Lista inicializálása */
    // Megjegyzés: a C++-ban a vector egyenértékű az ebben a cikkben leírt nums-szal
    // Kezdőértékek nélkül
    vector<int> nums1;
    // Kezdőértékekkel
    vector<int> nums = { 1, 3, 2, 5, 4 };
    ```

=== "Java"

    ```java title="list.java"
    /* Lista inicializálása */
    // Kezdőértékek nélkül
    List<Integer> nums1 = new ArrayList<>();
    // Kezdőértékekkel (megjegyzés: a tömbelemekhez Integer[] wrapper osztályt kell használni int[] helyett)
    Integer[] numbers = new Integer[] { 1, 3, 2, 5, 4 };
    List<Integer> nums = new ArrayList<>(Arrays.asList(numbers));
    ```

=== "C#"

    ```csharp title="list.cs"
    /* Lista inicializálása */
    // Kezdőértékek nélkül
    List<int> nums1 = [];
    // Kezdőértékekkel
    int[] numbers = [1, 3, 2, 5, 4];
    List<int> nums = [.. numbers];
    ```

=== "Go"

    ```go title="list_test.go"
    /* Lista inicializálása */
    // Kezdőértékek nélkül
    nums1 := []int{}
    // Kezdőértékekkel
    nums := []int{1, 3, 2, 5, 4}
    ```

=== "Swift"

    ```swift title="list.swift"
    /* Lista inicializálása */
    // Kezdőértékek nélkül
    let nums1: [Int] = []
    // Kezdőértékekkel
    var nums = [1, 3, 2, 5, 4]
    ```

=== "JS"

    ```javascript title="list.js"
    /* Lista inicializálása */
    // Kezdőértékek nélkül
    const nums1 = [];
    // Kezdőértékekkel
    const nums = [1, 3, 2, 5, 4];
    ```

=== "TS"

    ```typescript title="list.ts"
    /* Lista inicializálása */
    // Kezdőértékek nélkül
    const nums1: number[] = [];
    // Kezdőértékekkel
    const nums: number[] = [1, 3, 2, 5, 4];
    ```

=== "Dart"

    ```dart title="list.dart"
    /* Lista inicializálása */
    // Kezdőértékek nélkül
    List<int> nums1 = [];
    // Kezdőértékekkel
    List<int> nums = [1, 3, 2, 5, 4];
    ```

=== "Rust"

    ```rust title="list.rs"
    /* Lista inicializálása */
    // Kezdőértékek nélkül
    let nums1: Vec<i32> = Vec::new();
    // Kezdőértékekkel
    let nums: Vec<i32> = vec![1, 3, 2, 5, 4];
    ```

=== "C"

    ```c title="list.c"
    // A C nem biztosít beépített dinamikus tömböt
    ```

=== "Kotlin"

    ```kotlin title="list.kt"
    /* Lista inicializálása */
    // Kezdőértékek nélkül
    var nums1 = listOf<Int>()
    // Kezdőértékekkel
    var numbers = arrayOf(1, 3, 2, 5, 4)
    var nums = numbers.toMutableList()
    ```

=== "Ruby"

    ```ruby title="list.rb"
    # Lista inicializálása
    # Kezdőértékek nélkül
    nums1 = []
    # Kezdőértékekkel
    nums = [1, 3, 2, 5, 4]
    ```

??? pythontutor "Kód Vizualizáció"

    https://pythontutor.com/render.html#code=%22%22%22Driver%20Code%22%22%22%0Aif%20__name__%20%3D%3D%20%22__main__%22%3A%0A%20%20%20%20%23%20%E5%88%9D%E5%A7%8B%E5%8C%96%E5%88%97%E8%A1%A8%0A%20%20%20%20%23%20%E6%97%A0%E5%88%9D%E5%A7%8B%E5%80%BC%0A%20%20%20%20nums1%20%3D%20%5B%5D%0A%20%20%20%20%23%20%E6%9C%89%E5%88%9D%E5%A7%8B%E5%80%BC%0A%20%20%20%20nums%20%3D%20%5B1,%203,%202,%205,%204%5D&cumulative=false&curInstr=4&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=311&rawInputLstJSON=%5B%5D&textReferences=false

### Elemek Elérése

Mivel a lista lényegében egy tömb, az elemeket $O(1)$ időbonyolultsággal érhetjük el és frissíthetjük, ami nagyon hatékony.

=== "Python"

    ```python title="list.py"
    # Elem elérése
    num: int = nums[1]  # Az 1-es indexű elem elérése

    # Elem frissítése
    nums[1] = 0    # Az 1-es indexű elem frissítése 0-ra
    ```

=== "C++"

    ```cpp title="list.cpp"
    /* Elem elérése */
    int num = nums[1];  // Az 1-es indexű elem elérése

    /* Elem frissítése */
    nums[1] = 0;  // Az 1-es indexű elem frissítése 0-ra
    ```

=== "Java"

    ```java title="list.java"
    /* Elem elérése */
    int num = nums.get(1);  // Az 1-es indexű elem elérése

    /* Elem frissítése */
    nums.set(1, 0);  // Az 1-es indexű elem frissítése 0-ra
    ```

=== "C#"

    ```csharp title="list.cs"
    /* Elem elérése */
    int num = nums[1];  // Az 1-es indexű elem elérése

    /* Elem frissítése */
    nums[1] = 0;  // Az 1-es indexű elem frissítése 0-ra
    ```

=== "Go"

    ```go title="list_test.go"
    /* Elem elérése */
    num := nums[1]  // Az 1-es indexű elem elérése

    /* Elem frissítése */
    nums[1] = 0     // Az 1-es indexű elem frissítése 0-ra
    ```

=== "Swift"

    ```swift title="list.swift"
    /* Elem elérése */
    let num = nums[1] // Az 1-es indexű elem elérése

    /* Elem frissítése */
    nums[1] = 0 // Az 1-es indexű elem frissítése 0-ra
    ```

=== "JS"

    ```javascript title="list.js"
    /* Elem elérése */
    const num = nums[1];  // Az 1-es indexű elem elérése

    /* Elem frissítése */
    nums[1] = 0;  // Az 1-es indexű elem frissítése 0-ra
    ```

=== "TS"

    ```typescript title="list.ts"
    /* Elem elérése */
    const num: number = nums[1];  // Az 1-es indexű elem elérése

    /* Elem frissítése */
    nums[1] = 0;  // Az 1-es indexű elem frissítése 0-ra
    ```

=== "Dart"

    ```dart title="list.dart"
    /* Elem elérése */
    int num = nums[1];  // Az 1-es indexű elem elérése

    /* Elem frissítése */
    nums[1] = 0;  // Az 1-es indexű elem frissítése 0-ra
    ```

=== "Rust"

    ```rust title="list.rs"
    /* Elem elérése */
    let num: i32 = nums[1];  // Az 1-es indexű elem elérése
    /* Elem frissítése */
    nums[1] = 0;             // Az 1-es indexű elem frissítése 0-ra
    ```

=== "C"

    ```c title="list.c"
    // A C nem biztosít beépített dinamikus tömböt
    ```

=== "Kotlin"

    ```kotlin title="list.kt"
    /* Elem elérése */
    val num = nums[1]       // Az 1-es indexű elem elérése
    /* Elem frissítése */
    nums[1] = 0             // Az 1-es indexű elem frissítése 0-ra
    ```

=== "Ruby"

    ```ruby title="list.rb"
    # Elem elérése
    num = nums[1] # Az 1-es indexű elem elérése
    # Elem frissítése
    nums[1] = 0 # Az 1-es indexű elem frissítése 0-ra
    ```

??? pythontutor "Kód Vizualizáció"

    https://pythontutor.com/render.html#code=%22%22%22Driver%20Code%22%22%22%0Aif%20__name__%20%3D%3D%20%22__main__%22%3A%0A%20%20%20%20%23%20%E5%88%9D%E5%A7%8B%E5%8C%96%E5%88%97%E8%A1%A8%0A%20%20%20%20nums%20%3D%20%5B1,%203,%202,%205,%204%5D%0A%0A%20%20%20%20%23%20%E8%AE%BF%E9%97%AE%E5%85%83%E7%B4%A0%0A%20%20%20%20num%20%3D%20nums%5B1%5D%20%20%23%20%E8%AE%BF%E9%97%AE%E7%B4%A2%E5%BC%95%201%20%E5%A4%84%E7%9A%84%E5%85%83%E7%B4%A0%0A%0A%20%20%20%20%23%20%E6%9B%B4%E6%96%B0%E5%85%83%E7%B4%A0%0A%20%20%20%20nums%5B1%5D%20%3D%200%20%20%20%20%23%20%E5%B0%86%E7%B4%A2%E5%BC%95%201%20%E5%A4%84%E7%9A%84%E5%85%83%E7%B4%A0%E6%9B%B4%E6%96%B0%E4%B8%BA%200&cumulative=false&curInstr=3&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=311&rawInputLstJSON=%5B%5D&textReferences=false

### Elemek Beszúrása és Törlése

A tömbökkel összehasonlítva a listák szabadon adhatnak hozzá és törölhetnek elemeket. Az elem lista végéhez való hozzáadásának időbonyolultsága $O(1)$, de az elemek közbenső beszúrása és törlése hatékonysága megegyezik a tömbökével, az időbonyolultság $O(n)$.

=== "Python"

    ```python title="list.py"
    # Lista törlése
    nums.clear()

    # Elemek hozzáadása a végéhez
    nums.append(1)
    nums.append(3)
    nums.append(2)
    nums.append(5)
    nums.append(4)

    # Elem beszúrása középre
    nums.insert(3, 6)  # A 6-os szám beszúrása a 3-as indexre

    # Elem törlése
    nums.pop(3)        # A 3-as indexű elem törlése
    ```

=== "C++"

    ```cpp title="list.cpp"
    /* Lista törlése */
    nums.clear();

    /* Elemek hozzáadása a végéhez */
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(4);

    /* Elem beszúrása középre */
    nums.insert(nums.begin() + 3, 6);  // A 6-os szám beszúrása a 3-as indexre

    /* Elem törlése */
    nums.erase(nums.begin() + 3);      // A 3-as indexű elem törlése
    ```

=== "Java"

    ```java title="list.java"
    /* Lista törlése */
    nums.clear();

    /* Elemek hozzáadása a végéhez */
    nums.add(1);
    nums.add(3);
    nums.add(2);
    nums.add(5);
    nums.add(4);

    /* Elem beszúrása középre */
    nums.add(3, 6);  // A 6-os szám beszúrása a 3-as indexre

    /* Elem törlése */
    nums.remove(3);  // A 3-as indexű elem törlése
    ```

=== "C#"

    ```csharp title="list.cs"
    /* Lista törlése */
    nums.Clear();

    /* Elemek hozzáadása a végéhez */
    nums.Add(1);
    nums.Add(3);
    nums.Add(2);
    nums.Add(5);
    nums.Add(4);

    /* Elem beszúrása középre */
    nums.Insert(3, 6);  // A 6-os szám beszúrása a 3-as indexre

    /* Elem törlése */
    nums.RemoveAt(3);  // A 3-as indexű elem törlése
    ```

=== "Go"

    ```go title="list_test.go"
    /* Lista törlése */
    nums = nil

    /* Elemek hozzáadása a végéhez */
    nums = append(nums, 1)
    nums = append(nums, 3)
    nums = append(nums, 2)
    nums = append(nums, 5)
    nums = append(nums, 4)

    /* Elem beszúrása középre */
    nums = append(nums[:3], append([]int{6}, nums[3:]...)...) // A 6-os szám beszúrása a 3-as indexre

    /* Elem törlése */
    nums = append(nums[:3], nums[4:]...) // A 3-as indexű elem törlése
    ```

=== "Swift"

    ```swift title="list.swift"
    /* Lista törlése */
    nums.removeAll()

    /* Elemek hozzáadása a végéhez */
    nums.append(1)
    nums.append(3)
    nums.append(2)
    nums.append(5)
    nums.append(4)

    /* Elem beszúrása középre */
    nums.insert(6, at: 3) // A 6-os szám beszúrása a 3-as indexre

    /* Elem törlése */
    nums.remove(at: 3) // A 3-as indexű elem törlése
    ```

=== "JS"

    ```javascript title="list.js"
    /* Lista törlése */
    nums.length = 0;

    /* Elemek hozzáadása a végéhez */
    nums.push(1);
    nums.push(3);
    nums.push(2);
    nums.push(5);
    nums.push(4);

    /* Elem beszúrása középre */
    nums.splice(3, 0, 6); // A 6-os szám beszúrása a 3-as indexre

    /* Elem törlése */
    nums.splice(3, 1);  // A 3-as indexű elem törlése
    ```

=== "TS"

    ```typescript title="list.ts"
    /* Lista törlése */
    nums.length = 0;

    /* Elemek hozzáadása a végéhez */
    nums.push(1);
    nums.push(3);
    nums.push(2);
    nums.push(5);
    nums.push(4);

    /* Elem beszúrása középre */
    nums.splice(3, 0, 6); // A 6-os szám beszúrása a 3-as indexre

    /* Elem törlése */
    nums.splice(3, 1);  // A 3-as indexű elem törlése
    ```

=== "Dart"

    ```dart title="list.dart"
    /* Lista törlése */
    nums.clear();

    /* Elemek hozzáadása a végéhez */
    nums.add(1);
    nums.add(3);
    nums.add(2);
    nums.add(5);
    nums.add(4);

    /* Elem beszúrása középre */
    nums.insert(3, 6); // A 6-os szám beszúrása a 3-as indexre

    /* Elem törlése */
    nums.removeAt(3); // A 3-as indexű elem törlése
    ```

=== "Rust"

    ```rust title="list.rs"
    /* Lista törlése */
    nums.clear();

    /* Elemek hozzáadása a végéhez */
    nums.push(1);
    nums.push(3);
    nums.push(2);
    nums.push(5);
    nums.push(4);

    /* Elem beszúrása középre */
    nums.insert(3, 6);  // A 6-os szám beszúrása a 3-as indexre

    /* Elem törlése */
    nums.remove(3);    // A 3-as indexű elem törlése
    ```

=== "C"

    ```c title="list.c"
    // A C nem biztosít beépített dinamikus tömböt
    ```

=== "Kotlin"

    ```kotlin title="list.kt"
    /* Lista törlése */
    nums.clear();

    /* Elemek hozzáadása a végéhez */
    nums.add(1);
    nums.add(3);
    nums.add(2);
    nums.add(5);
    nums.add(4);

    /* Elem beszúrása középre */
    nums.add(3, 6);  // A 6-os szám beszúrása a 3-as indexre

    /* Elem törlése */
    nums.remove(3);  // A 3-as indexű elem törlése
    ```

=== "Ruby"

    ```ruby title="list.rb"
    # Lista törlése
    nums.clear

    # Elemek hozzáadása a végéhez
    nums << 1
    nums << 3
    nums << 2
    nums << 5
    nums << 4

    # Elem beszúrása középre
    nums.insert(3, 6) # A 6-os szám beszúrása a 3-as indexre

    # Elem törlése
    nums.delete_at(3) # A 3-as indexű elem törlése
    ```

??? pythontutor "Kód Vizualizáció"

    https://pythontutor.com/render.html#code=%22%22%22Driver%20Code%22%22%22%0Aif%20__name__%20%3D%3D%20%22__main__%22%3A%0A%20%20%20%20%23%20%E6%9C%89%E5%88%9D%E5%A7%8B%E5%80%BC%0A%20%20%20%20nums%20%3D%20%5B1,%203,%202,%205,%204%5D%0A%20%20%20%20%0A%20%20%20%20%23%20%E6%B8%85%E7%A9%BA%E5%88%97%E8%A1%A8%0A%20%20%20%20nums.clear%28%29%0A%20%20%20%20%0A%20%20%20%20%23%20%E5%9C%A8%E5%B0%BE%E9%83%A8%E6%B7%BB%E5%8A%A0%E5%85%83%E7%B4%A0%0A%20%20%20%20nums.append%281%29%0A%20%20%20%20nums.append%283%29%0A%20%20%20%20nums.append%282%29%0A%20%20%20%20nums.append%285%29%0A%20%20%20%20nums.append%284%29%0A%20%20%20%20%0A%20%20%20%20%23%20%E5%9C%A8%E4%B8%AD%E9%97%B4%E6%8F%92%E5%85%A5%E5%85%83%E7%B4%A0%0A%20%20%20%20nums.insert%283,%206%29%20%20%23%20%E5%9C%A8%E7%B4%A2%E5%BC%95%203%20%E5%A4%84%E6%8F%92%E5%85%A5%E6%95%B0%E5%AD%97%206%0A%20%20%20%20%0A%20%20%20%20%23%20%E5%88%A0%E9%99%A4%E5%85%83%E7%B4%A0%0A%20%20%20%20nums.pop%283%29%20%20%20%20%20%20%20%20%23%20%E5%88%A0%E9%99%A4%E7%B4%A2%E5%BC%95%203%20%E5%A4%84%E7%9A%84%E5%85%83%E7%B4%A0&cumulative=false&curInstr=3&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=311&rawInputLstJSON=%5B%5D&textReferences=false

### Lista Bejárása

A tömbökhez hasonlóan a listák bejárhatók index szerint vagy közvetlenül az elemek iterálásával.

=== "Python"

    ```python title="list.py"
    # A lista bejárása index szerint
    count = 0
    for i in range(len(nums)):
        count += nums[i]

    # Lista elemeinek közvetlen bejárása
    for num in nums:
        count += num
    ```

=== "C++"

    ```cpp title="list.cpp"
    /* A lista bejárása index szerint */
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        count += nums[i];
    }

    /* Lista elemeinek közvetlen bejárása */
    count = 0;
    for (int num : nums) {
        count += num;
    }
    ```

=== "Java"

    ```java title="list.java"
    /* A lista bejárása index szerint */
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        count += nums.get(i);
    }

    /* Lista elemeinek közvetlen bejárása */
    for (int num : nums) {
        count += num;
    }
    ```

=== "C#"

    ```csharp title="list.cs"
    /* A lista bejárása index szerint */
    int count = 0;
    for (int i = 0; i < nums.Count; i++) {
        count += nums[i];
    }

    /* Lista elemeinek közvetlen bejárása */
    count = 0;
    foreach (int num in nums) {
        count += num;
    }
    ```

=== "Go"

    ```go title="list_test.go"
    /* A lista bejárása index szerint */
    count := 0
    for i := 0; i < len(nums); i++ {
        count += nums[i]
    }

    /* Lista elemeinek közvetlen bejárása */
    count = 0
    for _, num := range nums {
        count += num
    }
    ```

=== "Swift"

    ```swift title="list.swift"
    /* A lista bejárása index szerint */
    var count = 0
    for i in nums.indices {
        count += nums[i]
    }

    /* Lista elemeinek közvetlen bejárása */
    count = 0
    for num in nums {
        count += num
    }
    ```

=== "JS"

    ```javascript title="list.js"
    /* A lista bejárása index szerint */
    let count = 0;
    for (let i = 0; i < nums.length; i++) {
        count += nums[i];
    }

    /* Lista elemeinek közvetlen bejárása */
    count = 0;
    for (const num of nums) {
        count += num;
    }
    ```

=== "TS"

    ```typescript title="list.ts"
    /* A lista bejárása index szerint */
    let count = 0;
    for (let i = 0; i < nums.length; i++) {
        count += nums[i];
    }

    /* Lista elemeinek közvetlen bejárása */
    count = 0;
    for (const num of nums) {
        count += num;
    }
    ```

=== "Dart"

    ```dart title="list.dart"
    /* A lista bejárása index szerint */
    int count = 0;
    for (var i = 0; i < nums.length; i++) {
        count += nums[i];
    }

    /* Lista elemeinek közvetlen bejárása */
    count = 0;
    for (var num in nums) {
        count += num;
    }
    ```

=== "Rust"

    ```rust title="list.rs"
    // A lista bejárása index szerint
    let mut _count = 0;
    for i in 0..nums.len() {
        _count += nums[i];
    }

    // Lista elemeinek közvetlen bejárása
    _count = 0;
    for num in &nums {
        _count += num;
    }
    ```

=== "C"

    ```c title="list.c"
    // A C nem biztosít beépített dinamikus tömböt
    ```

=== "Kotlin"

    ```kotlin title="list.kt"
    /* A lista bejárása index szerint */
    var count = 0
    for (i in nums.indices) {
        count += nums[i]
    }

    /* Lista elemeinek közvetlen bejárása */
    for (num in nums) {
        count += num
    }
    ```

=== "Ruby"

    ```ruby title="list.rb"
    # A lista bejárása index szerint
    count = 0
    for i in 0...nums.length
        count += nums[i]
    end

    # Lista elemeinek közvetlen bejárása
    count = 0
    for num in nums
        count += num
    end
    ```

??? pythontutor "Kód Vizualizáció"

    https://pythontutor.com/render.html#code=%22%22%22Driver%20Code%22%22%22%0Aif%20__name__%20%3D%3D%20%22__main__%22%3A%0A%20%20%20%20%23%20%E5%88%9D%E5%A7%8B%E5%8C%96%E5%88%97%E8%A1%A8%0A%20%20%20%20nums%20%3D%20%5B1,%203,%202,%205,%204%5D%0A%20%20%20%20%0A%20%20%20%20%23%20%E9%80%9A%E8%BF%87%E7%B4%A2%E5%BC%95%E9%81%8D%E5%8E%86%E5%88%97%E8%A1%A8%0A%20%20%20%20count%20%3D%200%0A%20%20%20%20for%20i%20in%20range%28len%28nums%29%29%3A%0A%20%20%20%20%20%20%20%20count%20%2B%3D%20nums%5Bi%5D%0A%0A%20%20%20%20%23%20%E7%9B%B4%E6%8E%A5%E9%81%8D%E5%8E%86%E5%88%97%E8%A1%A8%E5%85%83%E7%B4%A0%0A%20%20%20%20for%20num%20in%20nums%3A%0A%20%20%20%20%20%20%20%20count%20%2B%3D%20num&cumulative=false&curInstr=3&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=311&rawInputLstJSON=%5B%5D&textReferences=false

### Listák Összefűzése

Egy új `nums1` lista megadásával azt az eredeti lista végéhez fűzhetjük.

=== "Python"

    ```python title="list.py"
    # Két lista összefűzése
    nums1: list[int] = [6, 8, 7, 10, 9]
    nums += nums1  # A nums1 lista hozzáfűzése a nums lista végéhez
    ```

=== "C++"

    ```cpp title="list.cpp"
    /* Két lista összefűzése */
    vector<int> nums1 = { 6, 8, 7, 10, 9 };
    // A nums1 lista hozzáfűzése a nums lista végéhez
    nums.insert(nums.end(), nums1.begin(), nums1.end());
    ```

=== "Java"

    ```java title="list.java"
    /* Két lista összefűzése */
    List<Integer> nums1 = new ArrayList<>(Arrays.asList(new Integer[] { 6, 8, 7, 10, 9 }));
    nums.addAll(nums1);  // A nums1 lista hozzáfűzése a nums lista végéhez
    ```

=== "C#"

    ```csharp title="list.cs"
    /* Két lista összefűzése */
    List<int> nums1 = [6, 8, 7, 10, 9];
    nums.AddRange(nums1);  // A nums1 lista hozzáfűzése a nums lista végéhez
    ```

=== "Go"

    ```go title="list_test.go"
    /* Két lista összefűzése */
    nums1 := []int{6, 8, 7, 10, 9}
    nums = append(nums, nums1...)  // A nums1 lista hozzáfűzése a nums lista végéhez
    ```

=== "Swift"

    ```swift title="list.swift"
    /* Két lista összefűzése */
    let nums1 = [6, 8, 7, 10, 9]
    nums.append(contentsOf: nums1) // A nums1 lista hozzáfűzése a nums lista végéhez
    ```

=== "JS"

    ```javascript title="list.js"
    /* Két lista összefűzése */
    const nums1 = [6, 8, 7, 10, 9];
    nums.push(...nums1);  // A nums1 lista hozzáfűzése a nums lista végéhez
    ```

=== "TS"

    ```typescript title="list.ts"
    /* Két lista összefűzése */
    const nums1: number[] = [6, 8, 7, 10, 9];
    nums.push(...nums1);  // A nums1 lista hozzáfűzése a nums lista végéhez
    ```

=== "Dart"

    ```dart title="list.dart"
    /* Két lista összefűzése */
    List<int> nums1 = [6, 8, 7, 10, 9];
    nums.addAll(nums1);  // A nums1 lista hozzáfűzése a nums lista végéhez
    ```

=== "Rust"

    ```rust title="list.rs"
    /* Két lista összefűzése */
    let nums1: Vec<i32> = vec![6, 8, 7, 10, 9];
    nums.extend(nums1);
    ```

=== "C"

    ```c title="list.c"
    // A C nem biztosít beépített dinamikus tömböt
    ```

=== "Kotlin"

    ```kotlin title="list.kt"
    /* Két lista összefűzése */
    val nums1 = intArrayOf(6, 8, 7, 10, 9).toMutableList()
    nums.addAll(nums1)  // A nums1 lista hozzáfűzése a nums lista végéhez
    ```

=== "Ruby"

    ```ruby title="list.rb"
    # Két lista összefűzése
    nums1 = [6, 8, 7, 10, 9]
    nums += nums1
    ```

??? pythontutor "Kód Vizualizáció"

    https://pythontutor.com/render.html#code=%22%22%22Driver%20Code%22%22%22%0Aif%20__name__%20%3D%3D%20%22__main__%22%3A%0A%20%20%20%20%23%20%E5%88%9D%E5%A7%8B%E5%8C%96%E5%88%97%E8%A1%A8%0A%20%20%20%20nums%20%3D%20%5B1,%203,%202,%205,%204%5D%0A%20%20%20%20%0A%20%20%20%20%23%20%E6%8B%BC%E6%8E%A5%E4%B8%A4%E4%B8%AA%E5%88%97%E8%A1%A8%0A%20%20%20%20nums1%20%3D%20%5B6,%208,%207,%2010,%209%5D%0A%20%20%20%20nums%20%2B%3D%20nums1%20%20%23%20%E5%B0%86%E5%88%97%E8%A1%A8%20nums1%20%E6%8B%BC%E6%8E%A5%E5%88%B0%20nums%20%E4%B9%8B%E5%90%8E&cumulative=false&curInstr=3&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=311&rawInputLstJSON=%5B%5D&textReferences=false

### Lista Rendezése

Egy lista rendezése után "bináris keresés" és "kétmutatós" algoritmusokat alkalmazhatunk, amelyeket tömbalgoritmus-feladatokban gyakran tesztelnek.

=== "Python"

    ```python title="list.py"
    # Lista rendezése
    nums.sort()  # Rendezés után a lista elemei a legkisebbtől a legnagyobbig rendezve vannak
    ```

=== "C++"

    ```cpp title="list.cpp"
    /* Lista rendezése */
    sort(nums.begin(), nums.end());  // Rendezés után a lista elemei a legkisebbtől a legnagyobbig rendezve vannak
    ```

=== "Java"

    ```java title="list.java"
    /* Lista rendezése */
    Collections.sort(nums);  // Rendezés után a lista elemei a legkisebbtől a legnagyobbig rendezve vannak
    ```

=== "C#"

    ```csharp title="list.cs"
    /* Lista rendezése */
    nums.Sort(); // Rendezés után a lista elemei a legkisebbtől a legnagyobbig rendezve vannak
    ```

=== "Go"

    ```go title="list_test.go"
    /* Lista rendezése */
    sort.Ints(nums)  // Rendezés után a lista elemei a legkisebbtől a legnagyobbig rendezve vannak
    ```

=== "Swift"

    ```swift title="list.swift"
    /* Lista rendezése */
    nums.sort() // Rendezés után a lista elemei a legkisebbtől a legnagyobbig rendezve vannak
    ```

=== "JS"

    ```javascript title="list.js"
    /* Lista rendezése */
    nums.sort((a, b) => a - b);  // Rendezés után a lista elemei a legkisebbtől a legnagyobbig rendezve vannak
    ```

=== "TS"

    ```typescript title="list.ts"
    /* Lista rendezése */
    nums.sort((a, b) => a - b);  // Rendezés után a lista elemei a legkisebbtől a legnagyobbig rendezve vannak
    ```

=== "Dart"

    ```dart title="list.dart"
    /* Lista rendezése */
    nums.sort(); // Rendezés után a lista elemei a legkisebbtől a legnagyobbig rendezve vannak
    ```

=== "Rust"

    ```rust title="list.rs"
    /* Lista rendezése */
    nums.sort(); // Rendezés után a lista elemei a legkisebbtől a legnagyobbig rendezve vannak
    ```

=== "C"

    ```c title="list.c"
    // A C nem biztosít beépített dinamikus tömböt
    ```

=== "Kotlin"

    ```kotlin title="list.kt"
    /* Lista rendezése */
    nums.sort() // Rendezés után a lista elemei a legkisebbtől a legnagyobbig rendezve vannak
    ```

=== "Ruby"

    ```ruby title="list.rb"
    # Lista rendezése
    nums = nums.sort { |a, b| a <=> b } # Rendezés után a lista elemei a legkisebbtől a legnagyobbig rendezve vannak
    ```

??? pythontutor "Kód Vizualizáció"

    https://pythontutor.com/render.html#code=%22%22%22Driver%20Code%22%22%22%0Aif%20__name__%20%3D%3D%20%22__main__%22%3A%0A%20%20%20%20%23%20%E5%88%9D%E5%A7%8B%E5%8C%96%E5%88%97%E8%A1%A8%0A%20%20%20%20nums%20%3D%20%5B1,%203,%202,%205,%204%5D%0A%20%20%20%20%0A%20%20%20%20%23%20%E6%8E%92%E5%BA%8F%E5%88%97%E8%A1%A8%0A%20%20%20%20nums.sort%28%29%20%20%23%20%E6%8E%92%E5%BA%8F%E5%90%8E%EF%BC%8C%E5%88%97%E8%A1%A8%E5%85%83%E7%B4%A0%E4%BB%8E%E5%B0%8F%E5%88%B0%E5%A4%A7%E6%8E%92%E5%88%97&cumulative=false&curInstr=3&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=311&rawInputLstJSON=%5B%5D&textReferences=false

## Lista Megvalósítása

Sok programozási nyelvnek van beépített listája, például a Java-nak, a C++-nak és a Pythonnak. Megvalósításuk meglehetősen összetett, és a paraméterek gondosan vannak meghatározva, például a kezdeti kapacitás, a bővítési szorzó és így tovább. Az érdeklődő olvasók a forráskódban tájékozódhatnak bővebben.

Annak érdekében, hogy mélyebben megértsük a listák működését, megpróbálunk megvalósítani egy egyszerű listát három fő tervezési szempontot figyelembe véve:

- **Kezdeti kapacitás**: Válasszunk megfelelő kezdeti kapacitást az alapul szolgáló tömbhöz. Ebben a példában 10-et választunk kezdeti kapacitásként.
- **Méret nyomon követése**: Deklaráljunk egy `size` változót a listában lévő elemek aktuális számának rögzítésére, és frissítsük valós időben az elemek beszúrása és törlése során. E változó alapján meghatározhatjuk a lista végét, és eldönthetjük, hogy szükség van-e bővítésre.
- **Bővítési mechanizmus**: Ha egy elem beillesztésekor a lista kapacitása megtelt, bővíteni kell. Létrehozunk egy nagyobb tömböt a bővítési szorzó alapján, majd az aktuális tömb összes elemét sorrendben átmásoljuk az új tömbbe. Ebben a példában meghatározzuk, hogy a tömböt minden alkalommal 2-szeresére kell bővíteni.

```src
[file]{my_list}-[class]{my_list}-[func]{}
```
