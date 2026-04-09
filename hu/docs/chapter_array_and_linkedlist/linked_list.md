# Láncolt Lista

A memóriaterület az összes program közös erőforrása. Összetett rendszer futási környezetben a szabad memóriaterület szétszórtan helyezkedhet el a memóriában. Tudjuk, hogy egy tömb tárolásához szükséges memóriaterületnek összefüggőnek kell lennie, és ha a tömb nagyon nagy, a memória esetleg nem tud ekkora összefüggő területet biztosítani. Ebben válik nyilvánvalóvá a láncolt listák rugalmasságának előnye.

A <u>láncolt lista</u> egy lineáris adatstruktúra, amelyben minden elem egy csomópont objektum, és a csomópontok "hivatkozásokon" keresztül kapcsolódnak egymáshoz. A hivatkozás a következő csomópont memóriacímét tárolja, amelyen keresztül az aktuális csomópontból a következőhöz lehet eljutni.

A láncolt listák felépítése lehetővé teszi, hogy a csomópontok szétszórtan helyezkedjenek el a memóriában, és memóriacímeiknek nem kell összefüggőnek lenniük.

![Láncolt lista definíciója és tárolási módszere](linked_list.assets/linkedlist_definition.png)

A fenti ábrát megvizsgálva a láncolt lista alapegysége a <u>csomópont</u> objektum. Minden csomópont két adatot tartalmaz: a csomópont "értékét" és a következő csomópontra mutató "hivatkozást".

- A láncolt lista első csomópontját "fejcsomópontnak", az utolsót "farokcsomópontnak" nevezzük.
- A farokcsomópont a "nullára" mutat, amelyet Java-ban `null`, C++-ban `nullptr`, Pythonban pedig `None` jelöl.
- A mutatókat támogató nyelvekben, mint a C, C++, Go és Rust, a fent említett "hivatkozást" "mutatóra" kell cserélni.

Ahogy az alábbi kódban látható, a láncolt lista `ListNode` csomópontja nemcsak értéket, hanem egy további hivatkozást (mutatót) is tartalmaz. Ezért **a láncolt listák több memóriaterületet foglalnak el, mint a tömbök, azonos mennyiségű adat tárolásakor**.

=== "Python"

    ```python title=""
    class ListNode:
        """Láncolt lista csomópont osztálya"""
        def __init__(self, val: int):
            self.val: int = val               # Csomópont értéke
            self.next: ListNode | None = None # Hivatkozás a következő csomópontra
    ```

=== "C++"

    ```cpp title=""
    /* Láncolt lista csomópont struktúrája */
    struct ListNode {
        int val;         // Csomópont értéke
        ListNode *next;  // Mutató a következő csomópontra
        ListNode(int x) : val(x), next(nullptr) {}  // Konstruktor
    };
    ```

=== "Java"

    ```java title=""
    /* Láncolt lista csomópont osztálya */
    class ListNode {
        int val;        // Csomópont értéke
        ListNode next;  // Hivatkozás a következő csomópontra
        ListNode(int x) { val = x; }  // Konstruktor
    }
    ```

=== "C#"

    ```csharp title=""
    /* Láncolt lista csomópont osztálya */
    class ListNode(int x) {  // Konstruktor
        int val = x;         // Csomópont értéke
        ListNode? next;      // Hivatkozás a következő csomópontra
    }
    ```

=== "Go"

    ```go title=""
    /* Láncolt lista csomópont struktúrája */
    type ListNode struct {
        Val  int       // Csomópont értéke
        Next *ListNode // Mutató a következő csomópontra
    }

    // NewListNode Konstruktor, új láncolt listát hoz létre
    func NewListNode(val int) *ListNode {
        return &ListNode{
            Val:  val,
            Next: nil,
        }
    }
    ```

=== "Swift"

    ```swift title=""
    /* Láncolt lista csomópont osztálya */
    class ListNode {
        var val: Int // Csomópont értéke
        var next: ListNode? // Hivatkozás a következő csomópontra

        init(x: Int) { // Konstruktor
            val = x
        }
    }
    ```

=== "JS"

    ```javascript title=""
    /* Láncolt lista csomópont osztálya */
    class ListNode {
        constructor(val, next) {
            this.val = (val === undefined ? 0 : val);       // Csomópont értéke
            this.next = (next === undefined ? null : next); // Hivatkozás a következő csomópontra
        }
    }
    ```

=== "TS"

    ```typescript title=""
    /* Láncolt lista csomópont osztálya */
    class ListNode {
        val: number;
        next: ListNode | null;
        constructor(val?: number, next?: ListNode | null) {
            this.val = val === undefined ? 0 : val;        // Csomópont értéke
            this.next = next === undefined ? null : next;  // Hivatkozás a következő csomópontra
        }
    }
    ```

=== "Dart"

    ```dart title=""
    /* Láncolt lista csomópont osztálya */
    class ListNode {
      int val; // Csomópont értéke
      ListNode? next; // Hivatkozás a következő csomópontra
      ListNode(this.val, [this.next]); // Konstruktor
    }
    ```

=== "Rust"

    ```rust title=""
    use std::rc::Rc;
    use std::cell::RefCell;
    /* Láncolt lista csomópont osztálya */
    #[derive(Debug)]
    struct ListNode {
        val: i32, // Csomópont értéke
        next: Option<Rc<RefCell<ListNode>>>, // Mutató a következő csomópontra
    }
    ```

=== "C"

    ```c title=""
    /* Láncolt lista csomópont struktúrája */
    typedef struct ListNode {
        int val;               // Csomópont értéke
        struct ListNode *next; // Mutató a következő csomópontra
    } ListNode;

    /* Konstruktor */
    ListNode *newListNode(int val) {
        ListNode *node;
        node = (ListNode *) malloc(sizeof(ListNode));
        node->val = val;
        node->next = NULL;
        return node;
    }
    ```

=== "Kotlin"

    ```kotlin title=""
    /* Láncolt lista csomópont osztálya */
    // Konstruktor
    class ListNode(x: Int) {
        val _val: Int = x          // Csomópont értéke
        val next: ListNode? = null // Hivatkozás a következő csomópontra
    }
    ```

=== "Ruby"

    ```ruby title=""
    # Láncolt lista csomópont osztálya
    class ListNode
      attr_accessor :val  # Csomópont értéke
      attr_accessor :next # Hivatkozás a következő csomópontra

      def initialize(val=0, next_node=nil)
        @val = val
        @next = next_node
      end
    end
    ```

## A Láncolt Lista Általános Műveletei

### Láncolt Lista Inicializálása

Egy láncolt lista felépítése két lépésből áll: először minden csomópont objektum inicializálása; másodszor a csomópontok közötti hivatkozási kapcsolatok kiépítése. Az inicializálás befejezése után a `next` hivatkozás segítségével végigjárhatjuk az összes csomópontot a láncolt lista fejcsomópontjától kezdve.

=== "Python"

    ```python title="linked_list.py"
    # Láncolt lista inicializálása 1 -> 3 -> 2 -> 5 -> 4
    # Minden csomópont inicializálása
    n0 = ListNode(1)
    n1 = ListNode(3)
    n2 = ListNode(2)
    n3 = ListNode(5)
    n4 = ListNode(4)
    # Csomópontok közötti hivatkozások kiépítése
    n0.next = n1
    n1.next = n2
    n2.next = n3
    n3.next = n4
    ```

=== "C++"

    ```cpp title="linked_list.cpp"
    /* Láncolt lista inicializálása 1 -> 3 -> 2 -> 5 -> 4 */
    // Minden csomópont inicializálása
    ListNode* n0 = new ListNode(1);
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(5);
    ListNode* n4 = new ListNode(4);
    // Csomópontok közötti hivatkozások kiépítése
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    ```

=== "Java"

    ```java title="linked_list.java"
    /* Láncolt lista inicializálása 1 -> 3 -> 2 -> 5 -> 4 */
    // Minden csomópont inicializálása
    ListNode n0 = new ListNode(1);
    ListNode n1 = new ListNode(3);
    ListNode n2 = new ListNode(2);
    ListNode n3 = new ListNode(5);
    ListNode n4 = new ListNode(4);
    // Csomópontok közötti hivatkozások kiépítése
    n0.next = n1;
    n1.next = n2;
    n2.next = n3;
    n3.next = n4;
    ```

=== "C#"

    ```csharp title="linked_list.cs"
    /* Láncolt lista inicializálása 1 -> 3 -> 2 -> 5 -> 4 */
    // Minden csomópont inicializálása
    ListNode n0 = new(1);
    ListNode n1 = new(3);
    ListNode n2 = new(2);
    ListNode n3 = new(5);
    ListNode n4 = new(4);
    // Csomópontok közötti hivatkozások kiépítése
    n0.next = n1;
    n1.next = n2;
    n2.next = n3;
    n3.next = n4;
    ```

=== "Go"

    ```go title="linked_list.go"
    /* Láncolt lista inicializálása 1 -> 3 -> 2 -> 5 -> 4 */
    // Minden csomópont inicializálása
    n0 := NewListNode(1)
    n1 := NewListNode(3)
    n2 := NewListNode(2)
    n3 := NewListNode(5)
    n4 := NewListNode(4)
    // Csomópontok közötti hivatkozások kiépítése
    n0.Next = n1
    n1.Next = n2
    n2.Next = n3
    n3.Next = n4
    ```

=== "Swift"

    ```swift title="linked_list.swift"
    /* Láncolt lista inicializálása 1 -> 3 -> 2 -> 5 -> 4 */
    // Minden csomópont inicializálása
    let n0 = ListNode(x: 1)
    let n1 = ListNode(x: 3)
    let n2 = ListNode(x: 2)
    let n3 = ListNode(x: 5)
    let n4 = ListNode(x: 4)
    // Csomópontok közötti hivatkozások kiépítése
    n0.next = n1
    n1.next = n2
    n2.next = n3
    n3.next = n4
    ```

=== "JS"

    ```javascript title="linked_list.js"
    /* Láncolt lista inicializálása 1 -> 3 -> 2 -> 5 -> 4 */
    // Minden csomópont inicializálása
    const n0 = new ListNode(1);
    const n1 = new ListNode(3);
    const n2 = new ListNode(2);
    const n3 = new ListNode(5);
    const n4 = new ListNode(4);
    // Csomópontok közötti hivatkozások kiépítése
    n0.next = n1;
    n1.next = n2;
    n2.next = n3;
    n3.next = n4;
    ```

=== "TS"

    ```typescript title="linked_list.ts"
    /* Láncolt lista inicializálása 1 -> 3 -> 2 -> 5 -> 4 */
    // Minden csomópont inicializálása
    const n0 = new ListNode(1);
    const n1 = new ListNode(3);
    const n2 = new ListNode(2);
    const n3 = new ListNode(5);
    const n4 = new ListNode(4);
    // Csomópontok közötti hivatkozások kiépítése
    n0.next = n1;
    n1.next = n2;
    n2.next = n3;
    n3.next = n4;
    ```

=== "Dart"

    ```dart title="linked_list.dart"
    /* Láncolt lista inicializálása 1 -> 3 -> 2 -> 5 -> 4 */\
    // Minden csomópont inicializálása
    ListNode n0 = ListNode(1);
    ListNode n1 = ListNode(3);
    ListNode n2 = ListNode(2);
    ListNode n3 = ListNode(5);
    ListNode n4 = ListNode(4);
    // Csomópontok közötti hivatkozások kiépítése
    n0.next = n1;
    n1.next = n2;
    n2.next = n3;
    n3.next = n4;
    ```

=== "Rust"

    ```rust title="linked_list.rs"
    /* Láncolt lista inicializálása 1 -> 3 -> 2 -> 5 -> 4 */
    // Minden csomópont inicializálása
    let n0 = Rc::new(RefCell::new(ListNode { val: 1, next: None }));
    let n1 = Rc::new(RefCell::new(ListNode { val: 3, next: None }));
    let n2 = Rc::new(RefCell::new(ListNode { val: 2, next: None }));
    let n3 = Rc::new(RefCell::new(ListNode { val: 5, next: None }));
    let n4 = Rc::new(RefCell::new(ListNode { val: 4, next: None }));

    // Csomópontok közötti hivatkozások kiépítése
    n0.borrow_mut().next = Some(n1.clone());
    n1.borrow_mut().next = Some(n2.clone());
    n2.borrow_mut().next = Some(n3.clone());
    n3.borrow_mut().next = Some(n4.clone());
    ```

=== "C"

    ```c title="linked_list.c"
    /* Láncolt lista inicializálása 1 -> 3 -> 2 -> 5 -> 4 */
    // Minden csomópont inicializálása
    ListNode* n0 = newListNode(1);
    ListNode* n1 = newListNode(3);
    ListNode* n2 = newListNode(2);
    ListNode* n3 = newListNode(5);
    ListNode* n4 = newListNode(4);
    // Csomópontok közötti hivatkozások kiépítése
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    ```

=== "Kotlin"

    ```kotlin title="linked_list.kt"
    /* Láncolt lista inicializálása 1 -> 3 -> 2 -> 5 -> 4 */
    // Minden csomópont inicializálása
    val n0 = ListNode(1)
    val n1 = ListNode(3)
    val n2 = ListNode(2)
    val n3 = ListNode(5)
    val n4 = ListNode(4)
    // Csomópontok közötti hivatkozások kiépítése
    n0.next = n1;
    n1.next = n2;
    n2.next = n3;
    n3.next = n4;
    ```

=== "Ruby"

    ```ruby title="linked_list.rb"
    # Láncolt lista inicializálása 1 -> 3 -> 2 -> 5 -> 4
    # Minden csomópont inicializálása
    n0 = ListNode.new(1)
    n1 = ListNode.new(3)
    n2 = ListNode.new(2)
    n3 = ListNode.new(5)
    n4 = ListNode.new(4)
    # Csomópontok közötti hivatkozások kiépítése
    n0.next = n1
    n1.next = n2
    n2.next = n3
    n3.next = n4
    ```

??? pythontutor "Kód Vizualizáció"

    https://pythontutor.com/render.html#code=class%20ListNode%3A%0A%20%20%20%20%22%22%22%E9%93%BE%E8%A1%A8%E8%8A%82%E7%82%B9%E7%B1%BB%22%22%22%0A%20%20%20%20def%20__init__%28self,%20val%3A%20int%29%3A%0A%20%20%20%20%20%20%20%20self.val%3A%20int%20%3D%20val%20%20%23%20%E8%8A%82%E7%82%B9%E5%80%BC%0A%20%20%20%20%20%20%20%20self.next%3A%20ListNode%20%7C%20None%20%3D%20None%20%20%23%20%E5%90%8E%E7%BB%A7%E8%8A%82%E7%82%B9%E5%BC%95%E7%94%A8%0A%0A%22%22%22Driver%20Code%22%22%22%0Aif%20__name__%20%3D%3D%20%22__main__%22%3A%0A%20%20%20%20%23%20%E5%88%9D%E5%A7%8B%E5%8C%96%E9%93%BE%E8%A1%A8%201%20-%3E%203%20-%3E%202%20-%3E%205%20-%3E%204%0A%20%20%20%20%23%20%E5%88%9D%E5%A7%8B%E5%8C%96%E5%90%84%E4%B8%AA%E8%8A%82%E7%82%B9%0A%20%20%20%20n0%20%3D%20ListNode%281%29%0A%20%20%20%20n1%20%3D%20ListNode%283%29%0A%20%20%20%20n2%20%3D%20ListNode%282%29%0A%20%20%20%20n3%20%3D%20ListNode%285%29%0A%20%20%20%20n4%20%3D%20ListNode%284%29%0A%20%20%20%20%23%20%E6%9E%84%E5%BB%BA%E8%8A%82%E7%82%B9%E4%B9%8B%E9%97%B4%E7%9A%84%E5%BC%95%E7%94%A8%0A%20%20%20%20n0.next%20%3D%20n1%0A%20%20%20%20n1.next%20%3D%20n2%0A%20%20%20%20n2.next%20%3D%20n3%0A%20%20%20%20n3.next%20%3D%20n4&cumulative=false&curInstr=3&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=311&rawInputLstJSON=%5B%5D&textReferences=false

A tömb egyetlen változó; például egy `nums` tömb tartalmazza a `nums[0]`, `nums[1]` stb. elemeket. A láncolt lista azonban több független csomópont objektumból épül fel. **Általában a fejcsomópontot használjuk a láncolt lista hivatkozásaként**; például a fenti kódban szereplő láncolt listát `n0` láncolt listaként nevezhetjük.

### Csomópont Beszúrása

Egy csomópont láncolt listába való beszúrása nagyon egyszerű. Ahogy az alábbi ábra mutatja, tegyük fel, hogy egy új `P` csomópontot szeretnénk beszúrni két szomszédos `n0` és `n1` csomópont közé. **Csak két csomópont hivatkozását (mutatóját) kell megváltoztatnunk**, az időbonyolultság $O(1)$.

Ezzel szemben egy elem tömbhöz való hozzáadásának időbonyolultsága $O(n)$, ami nagy adatmennyiség esetén nem hatékony.

![Csomópont láncolt listába való beszúrásának példája](linked_list.assets/linkedlist_insert_node.png)

```src
[file]{linked_list}-[class]{}-[func]{insert}
```

### Csomópont Törlése

Ahogy az alábbi ábra mutatja, egy csomópont törlése a láncolt listából szintén nagyon kényelmes. **Csak egy csomópont hivatkozását (mutatóját) kell megváltoztatni**.

Vegyük észre, hogy bár a `P` csomópont a törlési művelet befejezése után is az `n1`-re mutat, a láncolt lista bejárása során a lista már nem tud hozzáférni `P`-hez, ami azt jelenti, hogy `P` már nem tartozik ehhez a láncolt listához.

![Csomópont eltávolítása láncolt listából](linked_list.assets/linkedlist_remove_node.png)

```src
[file]{linked_list}-[class]{}-[func]{remove}
```

### Csomópont Elérése

**A láncolt lista csomópontjainak elérése kevésbé hatékony**. Ahogy az előző szakaszban említettük, egy tömbben bármely elemet $O(1)$ idő alatt elérhetjük. A láncolt listáknál ez nem így van. A programnak a fejcsomóponttól kezdve kell visszafele haladnia, amíg meg nem találja a célcsomópontot. Azaz az $i$-edik csomópont eléréséhez a láncolt listában $i - 1$ iterációra van szükség, az időbonyolultság $O(n)$.

```src
[file]{linked_list}-[class]{}-[func]{access}
```

### Csomópont Keresése

Járjuk be a láncolt listát, hogy megtaláljuk a `target` értékű csomópontot, és adjuk vissza annak indexét a láncolt listában. Ez a folyamat szintén lineáris keresés. Az alábbi kód szemlélteti:

```src
[file]{linked_list}-[class]{}-[func]{find}
```

## Tömbök versus Láncolt Listák

Az alábbi táblázat összefoglalja a tömbök és a láncolt listák jellemzőit, és összehasonlítja azok működési hatékonyságát. Mivel két egymással ellentétes tárolási stratégiát alkalmaznak, különböző tulajdonságaik és működési hatékonyságuk is ellentétes jellemzőket mutat.

<p align="center"> Table <id> &nbsp; Tömb és láncolt lista hatékonyságának összehasonlítása </p>

|                        | Tömb                                          | Láncolt Lista              |
| ---------------------- | --------------------------------------------- | -------------------------- |
| Tárolási módszer       | Összefüggő memóriaterület                     | Szétszórt memóriaterület   |
| Kapacitásbővítés       | Változtathatatlan hossz                       | Rugalmas bővítés           |
| Memória hatékonyság    | Az elemek kevés memóriát foglalnak, de hely pazarolódhat | Az elemek több memóriát foglalnak |
| Elem elérése           | $O(1)$                                        | $O(n)$                     |
| Elem hozzáadása        | $O(n)$                                        | $O(1)$                     |
| Elem törlése           | $O(n)$                                        | $O(1)$                     |

## A Láncolt Listák Általános Típusai

Ahogy az alábbi ábra mutatja, három általános típusú láncolt lista létezik:

- **Egyirányú láncolt lista**: Ez a korábban bemutatott szokásos láncolt lista. Az egyirányú láncolt lista csomópontjai egy értéket és a következő csomópontra mutató hivatkozást tartalmaznak. Az első csomópontot fejcsomópontnak, az utolsót farokcsomópontnak nevezzük, amely nullára (`None`) mutat.
- **Körkörös láncolt lista**: Ha az egyirányú láncolt lista farokcsomópontját a fejcsomópontra mutattatjuk (a farokot a fejhez kötjük), körkörös láncolt listát kapunk. A körkörös láncolt listában bármely csomópont tekinthető fejcsomópontnak.
- **Kétirányú láncolt lista**: Az egyirányú láncolt listával összehasonlítva a kétirányú láncolt lista mindkét irányban tárolja a hivatkozásokat. A kétirányú láncolt lista csomópontjának definíciója hivatkozásokat tartalmaz mind az utódcsomópontra (következő csomópontra), mind az előd csomópontra (előző csomópontra). Az egyirányú láncolt listával összehasonlítva a kétirányú láncolt lista rugalmasabb és mindkét irányban bejárható, de több memóriaterületet is igényel.

=== "Python"

    ```python title=""
    class ListNode:
        """Kétirányú láncolt lista csomópont osztálya"""
        def __init__(self, val: int):
            self.val: int = val                # Csomópont értéke
            self.next: ListNode | None = None  # Hivatkozás az utódcsomópontra
            self.prev: ListNode | None = None  # Hivatkozás az előd csomópontra
    ```

=== "C++"

    ```cpp title=""
    /* Kétirányú láncolt lista csomópont struktúrája */
    struct ListNode {
        int val;         // Csomópont értéke
        ListNode *next;  // Mutató az utódcsomópontra
        ListNode *prev;  // Mutató az előd csomópontra
        ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}  // Konstruktor
    };
    ```

=== "Java"

    ```java title=""
    /* Kétirányú láncolt lista csomópont osztálya */
    class ListNode {
        int val;        // Csomópont értéke
        ListNode next;  // Hivatkozás az utódcsomópontra
        ListNode prev;  // Hivatkozás az előd csomópontra
        ListNode(int x) { val = x; }  // Konstruktor
    }
    ```

=== "C#"

    ```csharp title=""
    /* Kétirányú láncolt lista csomópont osztálya */
    class ListNode(int x) {  // Konstruktor
        int val = x;    // Csomópont értéke
        ListNode next;  // Hivatkozás az utódcsomópontra
        ListNode prev;  // Hivatkozás az előd csomópontra
    }
    ```

=== "Go"

    ```go title=""
    /* Kétirányú láncolt lista csomópont struktúrája */
    type DoublyListNode struct {
        Val  int             // Csomópont értéke
        Next *DoublyListNode // Mutató az utódcsomópontra
        Prev *DoublyListNode // Mutató az előd csomópontra
    }

    // NewDoublyListNode Inicializálás
    func NewDoublyListNode(val int) *DoublyListNode {
        return &DoublyListNode{
            Val:  val,
            Next: nil,
            Prev: nil,
        }
    }
    ```

=== "Swift"

    ```swift title=""
    /* Kétirányú láncolt lista csomópont osztálya */
    class ListNode {
        var val: Int // Csomópont értéke
        var next: ListNode? // Hivatkozás az utódcsomópontra
        var prev: ListNode? // Hivatkozás az előd csomópontra

        init(x: Int) { // Konstruktor
            val = x
        }
    }
    ```

=== "JS"

    ```javascript title=""
    /* Kétirányú láncolt lista csomópont osztálya */
    class ListNode {
        constructor(val, next, prev) {
            this.val = val  ===  undefined ? 0 : val;        // Csomópont értéke
            this.next = next  ===  undefined ? null : next;  // Hivatkozás az utódcsomópontra
            this.prev = prev  ===  undefined ? null : prev;  // Hivatkozás az előd csomópontra
        }
    }
    ```

=== "TS"

    ```typescript title=""
    /* Kétirányú láncolt lista csomópont osztálya */
    class ListNode {
        val: number;
        next: ListNode | null;
        prev: ListNode | null;
        constructor(val?: number, next?: ListNode | null, prev?: ListNode | null) {
            this.val = val  ===  undefined ? 0 : val;        // Csomópont értéke
            this.next = next  ===  undefined ? null : next;  // Hivatkozás az utódcsomópontra
            this.prev = prev  ===  undefined ? null : prev;  // Hivatkozás az előd csomópontra
        }
    }
    ```

=== "Dart"

    ```dart title=""
    /* Kétirányú láncolt lista csomópont osztálya */
    class ListNode {
        int val;        // Csomópont értéke
        ListNode? next;  // Hivatkozás az utódcsomópontra
        ListNode? prev;  // Hivatkozás az előd csomópontra
        ListNode(this.val, [this.next, this.prev]);  // Konstruktor
    }
    ```

=== "Rust"

    ```rust title=""
    use std::rc::Rc;
    use std::cell::RefCell;

    /* Kétirányú láncolt lista csomópont típusa */
    #[derive(Debug)]
    struct ListNode {
        val: i32, // Csomópont értéke
        next: Option<Rc<RefCell<ListNode>>>, // Mutató az utódcsomópontra
        prev: Option<Rc<RefCell<ListNode>>>, // Mutató az előd csomópontra
    }

    /* Konstruktor */
    impl ListNode {
        fn new(val: i32) -> Self {
            ListNode {
                val,
                next: None,
                prev: None,
            }
        }
    }
    ```

=== "C"

    ```c title=""
    /* Kétirányú láncolt lista csomópont struktúrája */
    typedef struct ListNode {
        int val;               // Csomópont értéke
        struct ListNode *next; // Mutató az utódcsomópontra
        struct ListNode *prev; // Mutató az előd csomópontra
    } ListNode;

    /* Konstruktor */
    ListNode *newListNode(int val) {
        ListNode *node;
        node = (ListNode *) malloc(sizeof(ListNode));
        node->val = val;
        node->next = NULL;
        node->prev = NULL;
        return node;
    }
    ```

=== "Kotlin"

    ```kotlin title=""
    /* Kétirányú láncolt lista csomópont osztálya */
    // Konstruktor
    class ListNode(x: Int) {
        val _val: Int = x           // Csomópont értéke
        val next: ListNode? = null  // Hivatkozás az utódcsomópontra
        val prev: ListNode? = null  // Hivatkozás az előd csomópontra
    }
    ```

=== "Ruby"

    ```ruby title=""
    # Kétirányú láncolt lista csomópont osztálya
    class ListNode
      attr_accessor :val    # Csomópont értéke
      attr_accessor :next   # Hivatkozás az utódcsomópontra
      attr_accessor :prev   # Hivatkozás az előd csomópontra

      def initialize(val=0, next_node=nil, prev_node=nil)
        @val = val
        @next = next_node
        @prev = prev_node
      end
    end
    ```

![Láncolt listák általános típusai](linked_list.assets/linkedlist_common_types.png)

## A Láncolt Listák Tipikus Alkalmazásai

Az egyirányú láncolt listákat általában veremek, sorok, hasítótáblák és gráfok megvalósítására használják.

- **Veremek és sorok**: Ha a láncolt lista egyik végén egyszerre történik a beszúrás és a törlés, utolsó be, első ki (LIFO) jelleget mutat, ami a veremnek felel meg. Ha a láncolt lista egyik végén történik a beszúrás, a másik végén pedig a törlés, első be, első ki (FIFO) jelleget mutat, ami a sornak felel meg.
- **Hasítótáblák**: A láncolási módszer a hasítóütközések megoldásának egyik fő módszere. Ebben a megközelítésben az összes ütköző elemet egy láncolt listában helyezzük el.
- **Gráfok**: A szomszédsági lista egy gráf ábrázolásának általános módja, ahol a gráf minden csúcsához egy láncolt lista kapcsolódik, és a láncolt lista minden eleme a csúcshoz kapcsolódó másik csúcsot képviseli.

A kétirányú láncolt listákat általában olyan forgatókönyvekben alkalmazzák, ahol gyorsan kell hozzáférni az előző és a következő elemekhez.

- **Fejlett adatstruktúrák**: Például piros-fekete fákban és B-fákban szükség van a csomópont szülőcsomópontjának elérésére, ami a csomópontban a szülőcsomópontra mutató hivatkozás elmentésével érhető el, hasonlóan a kétirányú láncolt listához.
- **Böngésző előzmények**: Webböngészőkben, amikor a felhasználó az előre vagy vissza gombra kattint, a böngészőnek tudnia kell a felhasználó által korábban és ezután meglátogatott weboldalakat. A kétirányú láncolt listák jellemzői ezt a műveletet egyszerűvé teszik.
- **LRU algoritmus**: A gyorsítótár-kizárási (LRU) algoritmusokban szükség van a legrégebben használt adatok gyors megtalálására, és a csomópontok gyors hozzáadásának és törlésének támogatására. A kétirányú láncolt lista használata erre nagyon alkalmas.

A körkörös láncolt listákat általában periodikus műveleteket igénylő forgatókönyvekben alkalmazzák, például az operációs rendszer erőforrás-ütemezésében.

- **Körbenforgó ütemezési algoritmus**: Az operációs rendszerekben a körbenforgó ütemezés egy általános CPU ütemezési algoritmus, amelynek egy folyamatkészleten kell végigciklizálni. Minden folyamathoz egy időszelet van hozzárendelve, és az időszelet lejártakor a CPU a következő folyamatra vált. Ez a ciklikus működés körkörös láncolt listával valósítható meg.
- **Adatpufferek**: Egyes adatpuffer megvalósításokban körkörös láncolt listákat is alkalmaznak. Például audió- és videolejátszókban az adatfolyamot több pufferblokkra lehet osztani, és egy körkörös láncolt listában elhelyezni a zökkenőmentes lejátszás érdekében.
