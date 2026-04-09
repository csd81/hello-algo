# A dinamikus programozási feladatok jellemzői

Az előző szakaszban megtanultuk, hogyan oldja meg a dinamikus programozás az eredeti problémát részproblémákra bontással. Valójában a részproblémákra bontás egy általános algoritmikus megközelítés, amely különböző hangsúlyokkal jelenik meg az oszd-meg-és-uralkodj, a dinamikus programozás és a visszalépés esetén.

- Az oszd-meg-és-uralkodj algoritmusok rekurzívan osztják fel az eredeti problémát több független részproblémára, amíg el nem érik a legkisebb részproblémákat, majd visszalépéskor egyesítik a részproblémák megoldásait, hogy végül megkapják az eredeti probléma megoldását.
- A dinamikus programozás szintén rekurzívan bontja fel a problémákat, de a fő különbség az oszd-meg-és-uralkodj algoritmusoktól az, hogy a dinamikus programozásban a részproblémák egymástól függenek, és a felbontási folyamat során sok átfedő részprobléma jelenik meg.
- A visszalépéses algoritmusok próbálkozással és hibával felsorolják az összes lehetséges megoldást, és metszéssel elkerülik a szükségtelen keresési ágakat. Az eredeti probléma megoldása döntési lépések sorozatából áll, és az egyes döntési lépések előtti részsorozatot részproblémának tekinthetjük.

Valójában a dinamikus programozást általában optimalizálási feladatok megoldására használják, amelyek nemcsak átfedő részproblémákat tartalmaznak, hanem két másik fontos jellemzővel is bírnak: optimális részstruktúrával és utóhatás-mentességgel.

## Optimális részstruktúra

Kis módosítást végzünk a lépcsőmászási feladaton, hogy jobban szemléltesse az optimális részstruktúra fogalmát.

!!! question "Lépcsőmászás minimális költséggel"

    Adott egy lépcső, ahol egyszerre $1$ vagy $2$ fokot lehet lépni, és minden foknak van egy nemnegatív egész száma, amely az ott szükséges költséget jelzi. Adott egy nemnegatív egész számokból álló $cost$ tömb, ahol $cost[i]$ az $i$-edik fok költségét jelöli, és $cost[0]$ a talaj (kiindulópont). Mi a minimális szükséges költség a tetejére jutáshoz?

Az alábbi ábrán látható, hogy ha az $1.$ , $2.$ és $3.$ fok költsége rendre $1$, $10$ és $1$, akkor a talajtól a $3.$ fokig való feljutás minimális költsége $2$.

![Minimális költség a 3. fokra jutáshoz](dp_problem_features.assets/min_cost_cs_example.png)

Legyen $dp[i]$ az $i$-edik fokra való feljutás felhalmozott költsége. Mivel az $i$-edik fokra csak az $i-1$-edikről vagy az $i-2$-edikről lehet lépni, $dp[i]$ csak $dp[i-1] + cost[i]$ vagy $dp[i-2] + cost[i]$ lehet. A költség minimalizálásához a kisebbiket kell választani:

$$
dp[i] = \min(dp[i-1], dp[i-2]) + cost[i]
$$

Ez elvezet az optimális részstruktúra jelentéséhez: **az eredeti probléma optimális megoldása a részproblémák optimális megoldásaiból épül fel**.

Ennek a feladatnak egyértelműen van optimális részstruktúrája: a két részprobléma $dp[i-1]$ és $dp[i-2]$ optimális megoldásai közül a jobbat választjuk, és ezzel felépítjük az eredeti probléma $dp[i]$ optimális megoldását.

Akkor az előző szakaszban szereplő lépcsőmászási feladatnak van-e optimális részstruktúrája? Ennek célja az utak számának megtalálása, ami számolási feladatnak tűnik, de ha megváltoztatjuk a kérdést: "Találjuk meg az utak maximális számát". Meglepetésre felfedezzük, hogy **bár a módosítás előtti és utáni feladat egyenértékű, az optimális részstruktúra megjelent**: az $n$-edik fokra vezető utak maximális száma egyenlő az $(n-1)$-edik és $(n-2)$-edik fokra vezető utak maximális számának összegével. Ezért az optimális részstruktúra értelmezése meglehetősen rugalmas, és különböző feladatokban különböző jelentést hordoz.

Az állapot-átmeneti egyenlet és a $dp[1] = cost[1]$, $dp[2] = cost[2]$ kezdeti állapotok alapján megkaphatjuk a dinamikus programozási kódot:

```src
[file]{min_cost_climbing_stairs_dp}-[class]{}-[func]{min_cost_climbing_stairs_dp}
```

Az alábbi ábra a fenti kód dinamikus programozási folyamatát szemlélteti.

![A minimális költségű lépcsőmászás dinamikus programozási folyamata](dp_problem_features.assets/min_cost_cs_dp.png)

Ez a feladat tárhelyoptimalizálható is, egy dimenzióról nullára tömörítve, a tárkomplexitást $O(n)$-ről $O(1)$-re csökkentve:

```src
[file]{min_cost_climbing_stairs_dp}-[class]{}-[func]{min_cost_climbing_stairs_dp_comp}
```

## Utóhatás-mentesség

Az utóhatás-mentesség az egyik fontos jellemző, amely lehetővé teszi a dinamikus programozás hatékony problémamegoldását. Definíciója: **adott egy bizonyos állapot, annak jövőbeli fejlődése csak az aktuális állapottól függ, és semmi köze az összes múltbeli állapothoz**.

Vegyük a lépcsőmászási feladatot példaként: adott az $i$ állapot, amely $i+1$ és $i+2$ állapotokba fejlődik tovább, ami $1$ fokos és $2$ fokos ugrásnak felel meg. Ezen két döntés meghozatalakor nem kell figyelembe venni az $i$ állapot előtti állapotokat, mivel azoknak nincs hatásuk az $i$ állapot jövőjére.

Ha azonban korlátot adunk a lépcsőmászási feladathoz, a helyzet megváltozik.

!!! question "Lépcsőmászás korláttal"

    Adott egy $n$ fokos lépcső, ahol egyszerre $1$ vagy $2$ fokot lehet lépni, **de két egymást követő körben nem lehet $1$ fokot ugrani**. Hányféleképpen lehet felérni a tetejére?

Az alábbi ábrán látható, hogy a $3.$ fokra csak $2$ megvalósítható úton lehet feljutni. A háromszor egymás után $1$ fokot ugró út nem teljesíti a korlátot, ezért elvetjük.

![A 3. fokra vezető utak száma korláttal](dp_problem_features.assets/climbing_stairs_constraint_example.png)

Ebben a feladatban, ha az előző körben $1$ fokot ugrottunk, akkor a következő körben $2$ fokot kell ugrani. Ez azt jelenti, hogy **a következő döntés nem határozható meg kizárólag az aktuális állapot (aktuális lépcsőfok sorszáma) alapján, hanem az előző állapottól (az előző kör lépcsőfok sorszámától) is függ**.

Látható, hogy ez a feladat már nem teljesíti az utóhatás-mentességet, és a $dp[i] = dp[i-1] + dp[i-2]$ állapot-átmeneti egyenlet is meghibásodik, mert $dp[i-1]$ azt jelenti, hogy ebben a körben $1$ fokot ugrunk, de sok olyan megoldást tartalmaz, ahol "az előző körben $1$ fokot ugrottunk", amelyek nem számíthatók be közvetlenül $dp[i]$-be a korlát teljesítéséhez.

Emiatt ki kell bővítenünk az állapotdefiníciót: **az $[i, j]$ állapot azt jelenti, hogy az $i$-edik fokon vagyunk, és az előző körben $j$ fokot ugrottunk**, ahol $j \in \{1, 2\}$. Ez az állapotdefiníció hatékonyan megkülönbözteti, hogy az előző körben $1$ vagy $2$ fokot ugrottunk-e, lehetővé téve annak meghatározását, honnan jött az aktuális állapot.

- Ha az előző körben $1$ fokot ugrottunk, az azt megelőző körben csak $2$ fokot lehetett ugrani, azaz $dp[i, 1]$ csak $dp[i-1, 2]$-ből vezethető át.
- Ha az előző körben $2$ fokot ugrottunk, az azt megelőző körben $1$ vagy $2$ fokot lehetett ugrani, azaz $dp[i, 2]$ átvezethet $dp[i-2, 1]$-ből vagy $dp[i-2, 2]$-ből.

Ahogy az alábbi ábra mutatja, e definíció alatt $dp[i, j]$ az $[i, j]$ állapothoz tartozó utak számát jelöli. Az állapot-átmeneti egyenlet ekkor:

$$
\begin{cases}
dp[i, 1] = dp[i-1, 2] \\
dp[i, 2] = dp[i-2, 1] + dp[i-2, 2]
\end{cases}
$$

![Korlátokat figyelembe vevő rekurzív összefüggés](dp_problem_features.assets/climbing_stairs_constraint_state_transfer.png)

Végül visszaadjuk $dp[n, 1] + dp[n, 2]$ értékét, ahol a kettő összege az $n$-edik fokra való feljutás összes útjának számát jelenti:

```src
[file]{climbing_stairs_constraint_dp}-[class]{}-[func]{climbing_stairs_constraint_dp}
```

A fenti esetben, mivel csak egy előző állapotot kell figyelembe venni, az állapotdefiníció bővítésével még teljesíthetjük az utóhatás-mentességet. Egyes feladatoknál azonban az "utóhatás" nagyon súlyos.

!!! question "Lépcsőmászás akadálygenerálással"

    Adott egy $n$ fokos lépcső, ahol egyszerre $1$ vagy $2$ fokot lehet lépni. **Szabály, hogy ha az $i$-edik fokra lépünk, a rendszer automatikusan akadályt helyez a $2i$-edik fokra, és ezt követően egyetlen körben sem lehet a $2i$-edik fokra ugrani**. Például, ha az első két körben a $2.$ és $3.$ fokra ugrunk, utána nem lehet a $4.$ és $6.$ fokra ugrani. Hányféleképpen lehet felérni a tetejére?

Ebben a feladatban a következő ugrás az összes múltbeli állapottól függ, mert minden ugrás akadályokat helyez a magasabb fokokra, befolyásolva a jövőbeli ugrásokat. Az ilyen feladatoknál a dinamikus programozás nehezen alkalmazható.

Valójában sok összetett kombinatorikus optimalizálási probléma (mint például az utazóügynök-feladat) nem teljesíti az utóhatás-mentességet. Az ilyen feladatoknál általában más módszereket választunk, mint például heurisztikus keresést, genetikus algoritmusokat, megerősítéses tanulást stb., hogy korlátozott idő alatt használható lokálisan optimális megoldásokat kapjunk.
