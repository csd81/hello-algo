# Hogyan használd ezt a könyvet

!!! tip

    A legjobb olvasási élmény érdekében ajánlott, hogy elolvasd ezt a részt.

## Írási stílus konvenciók

- A `*`-gal jelölt címek opcionális részek, viszonylag nehéz tartalommal. Ha korlátozott az időd, először kihagyhatod őket.
- A műszaki kifejezések félkövérek lesznek (papír- és PDF-verziókban) vagy aláhúzva (webes verziókban), például <u>tömb</u>. Ajánlott megjegyezni őket a szakirodalom olvasásához.
- A kulcsfontosságú tartalom és összefoglaló állítások **félkövérek** lesznek, és az ilyen szövegre különös figyelmet érdemes fordítani.
- A specifikus jelentésű szavakat és kifejezéseket "idézőjelek" jelölik, hogy elkerüljük a kétértelműséget.
- Amikor a programozási nyelvek között inkonzisztens főnevekről van szó, ez a könyv a Pythont használja szabványként, például a `None` használatát a "null" reprezentálására.
- Ez a könyv részben elhagyja a programozási nyelvek megjegyzési konvencióit a kompaktabb tartalomelrendezés érdekében. A megjegyzések főként három típusra oszlanak: cím-megjegyzések, tartalmi megjegyzések és többsoros megjegyzések.

=== "Python"

    ```python title=""
    """Title comment, used to label functions, classes, test cases, etc."""
    
    # Content comment, used to explain code in detail
    
    """
    Multi-line
    comment
    """
    ```

=== "C++"

    ```cpp title=""
    /* Title comment, used to label functions, classes, test cases, etc. */
    
    // Content comment, used to explain code in detail
    
    /**
     * Multi-line
     * comment
     */
    ```

=== "Java"

    ```java title=""
    /* Title comment, used to label functions, classes, test cases, etc. */
    
    // Content comment, used to explain code in detail
    
    /**
     * Multi-line
     * comment
     */
    ```

=== "C#"

    ```csharp title=""
    /* Title comment, used to label functions, classes, test cases, etc. */
    
    // Content comment, used to explain code in detail
    
    /**
     * Multi-line
     * comment
     */
    ```

=== "Go"

    ```go title=""
    /* Title comment, used to label functions, classes, test cases, etc. */
    
    // Content comment, used to explain code in detail
    
    /**
     * Multi-line
     * comment
     */
    ```

=== "Swift"

    ```swift title=""
    /* Title comment, used to label functions, classes, test cases, etc. */
    
    // Content comment, used to explain code in detail
    
    /**
     * Multi-line
     * comment
     */
    ```

=== "JS"

    ```javascript title=""
    /* Title comment, used to label functions, classes, test cases, etc. */
    
    // Content comment, used to explain code in detail
    
    /**
     * Multi-line
     * comment
     */
    ```

=== "TS"

    ```typescript title=""
    /* Title comment, used to label functions, classes, test cases, etc. */
    
    // Content comment, used to explain code in detail
    
    /**
     * Multi-line
     * comment
     */
    ```

=== "Dart"

    ```dart title=""
    /* Title comment, used to label functions, classes, test cases, etc. */
    
    // Content comment, used to explain code in detail
    
    /**
     * Multi-line
     * comment
     */
    ```

=== "Rust"

    ```rust title=""
    /* Title comment, used to label functions, classes, test cases, etc. */
    
    // Content comment, used to explain code in detail
    
    // Multi-line
    // comment
    ```

=== "C"

    ```c title=""
    /* Title comment, used to label functions, classes, test cases, etc. */
    
    // Content comment, used to explain code in detail
    
    /**
     * Multi-line
     * comment
     */
    ```

=== "Kotlin"

    ```kotlin title=""
    /* Title comment, used to label functions, classes, test cases, etc. */
    
    // Content comment, used to explain code in detail
    
    /**
     * Multi-line
     * comment
     */
    ```

=== "Ruby"

    ```ruby title=""
    ### Title comment, used to label functions, classes, test cases, etc. ###
    
    # Content comment, used to explain code in detail
    
    # Multi-line
    # comment
    ```

## Hatékony tanulás animált illusztrációkkal

A szöveghez képest a videók és képek nagyobb információs sűrűséggel és strukturális szervezéssel rendelkeznek, így könnyebben érthetők. Ebben a könyvben a **kulcsfontosságú és nehéz ismereteket főként animált illusztrációk formájában mutatjuk be**, a szöveg pedig magyarázatként és kiegészítésként szolgál.

Ha olvasás közben azt tapasztalod, hogy egy tartalomrész animált illusztrációkat tartalmaz, mint az alábbi ábrán, **kérjük, először az illusztrációkra összpontosíts, a szöveget kiegészítésként használva**, és kombináld a kettőt a tartalom megértéséhez.

![Példa animált illusztrációkra](../index.assets/animation.gif)

## Mélyebb megértés kódgyakorlással

A könyv kísérő kódja a [GitHub repositoryban](https://github.com/krahets/hello-algo) található. Ahogy az alábbi ábrán látható, **a forráskód tesztesetekkel együtt érkezik, és egy kattintással futtatható**.

Ha az időd engedi, **ajánlott, hogy saját kezűleg gépeld be a kódot**. Ha korlátozott a tanulási időd, kérjük, legalább olvasd át és futtasd az összes kódot.

A kód olvasásához képest a kód írásának folyamata gyakran több jutalmat hoz. **A cselekvéssel való tanulás az igazi tanulás**.

![Példa kód futtatására](../index.assets/running_code.gif)

A kód futtatásának előkészítő munkája főként három lépésre oszlik.

**Step 1: Install the local programming environment**. Please follow the [tutorial](https://www.hello-algo.com/chapter_appendix/installation/) shown in the appendix for installation. If already installed, you can skip this step.

**Step 2: Clone or download the code repository**. Visit the [GitHub repository](https://github.com/krahets/hello-algo). If you have already installed [Git](https://git-scm.com/downloads), you can clone this repository with the following command:

```shell
git clone https://github.com/krahets/hello-algo.git
```

Of course, you can also click the "Download ZIP" button at the location shown in the figure below to directly download the code compressed package, and then extract it locally.

![Clone repository and download code](suggestions.assets/download_code.png)

**Step 3: Run the source code**. As shown in the figure below, for code blocks with file names at the top, we can find the corresponding source code files in the `codes` folder of the repository. The source code files can be run with one click, which will help you save unnecessary debugging time and allow you to focus on learning content.

![Code blocks and corresponding source code files](suggestions.assets/code_md_to_repo.png)

In addition to running code locally, **the web version also supports visual running of Python code** (implemented based on [pythontutor](https://pythontutor.com/)). As shown in the figure below, you can click "Visual Run" below the code block to expand the view and observe the execution process of the algorithm code; you can also click "Full Screen View" for a better viewing experience.

![Visual running of Python code](suggestions.assets/pythontutor_example.png)

## Együtt növekedés kérdésekkel és megbeszélésekkel

A könyv olvasása során kérjük, ne hagyd könnyen figyelmen kívül azokat az ismeretpontokat, amelyeket nem tanultál meg jól. **Nyugodtan tedd fel kérdéseidet a megjegyzések szekcióban**, és barátaim és én mindent megteszünk, hogy válaszoljunk neked, általában két napon belül.

Ahogy az alábbi ábrán látható, a webes verzió minden fejezetének alján van egy megjegyzések szekció. Remélem, hogy nagyobb figyelmet fordítasz a megjegyzések szekció tartalmára. Egyrészt megtudhatod, milyen problémákkal találkozik mindenki, így ellenőrizheted a hiányosságokat és mélyebb gondolkodást serkenthetsz. Másrészt remélem, hogy nagyvonalúan válaszolsz más barátok kérdéseire, megosztod betekintéseidet, és segítesz másoknak haladni.

![Példa megjegyzések szekcióra](../index.assets/comment.gif)

## Algoritmus tanulási útvonal

Áttekintő szempontból az adatszerkezetek és algoritmusok tanulási folyamatát három szakaszra oszthatjuk.

1. **1. szakasz: Algoritmus bevezetés**. Meg kell ismernünk a különböző adatszerkezetek jellemzőit és használatát, és meg kell tanulnunk a különböző algoritmusok elveit, folyamatait, felhasználásait és hatékonyságát.
2. **2. szakasz: Algoritmus problémák gyakorlása**. Ajánlott a népszerű problémákkal kezdeni, és először legalább 100 problémát felhalmozni, hogy megismerd a főbb algoritmus problémákat. Amikor először gyakorolsz problémákat, a "tudásfeledés" kihívás lehet, de nyugodtan légy, ez nagyon normális. A problémákat az "Ebbinghaus-felejtési görbe" szerint ismételhetjük, és általában 3-5 ismétlés után szilárdan megjegyezhetjük őket. Ajánlott problémalisták és gyakorlati tervek esetén kérjük, lásd ezt a [GitHub repositoryt](https://github.com/krahets/LeetCode-Book).
3. **3. szakasz: Tudásrendszer felépítése**. A tanulás szempontjából olvashatunk algoritmus rovatcikkeket, problémamegoldó keretrendszereket és algoritmus tankönyveket, hogy folyamatosan gazdagítsuk tudásrendszerünket. A problémagyakorlás szempontjából kipróbálhatunk fejlett problémamegoldó stratégiákat, mint például témakör szerinti kategorizálás, egy probléma több megoldás, egy megoldás több probléma stb. Kapcsolódó problémamegoldó betekintések különböző közösségekben találhatók.

Ahogy az alábbi ábrán látható, a könyv tartalma főként az "1. szakaszt" fedi le, célja, hogy hatékonyabban segítsen a 2. és 3. szakasz tanulásának végrehajtásában.

![Algoritmus tanulási útvonal](suggestions.assets/learning_route.png)
