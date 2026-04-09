# Összefoglalás

### Kulcsfontosságú áttekintés

- A dinamikus programozás felbontja a problémákat, és a részproblémák megoldásainak tárolásával elkerüli a redundáns számításokat, ezzel jelentősen javítva a számítási hatékonyságot.
- Az időkorlátozásokat figyelmen kívül hagyva az összes dinamikus programozási feladat megoldható visszalépéssel (nyers erő kereséssel), de a rekurziós fa sok átfedő részproblémát tartalmaz, ami rendkívül alacsony hatékonyságot eredményez. Memo lista bevezetésével az összes kiszámított részprobléma megoldását tárolhatjuk, biztosítva, hogy az átfedő részproblémákat csak egyszer számítsuk ki.
- A memoizálás felülről lefelé haladó rekurzív megoldás, míg a megfelelő dinamikus programozás alulról felfelé haladó iteratív megoldás, hasonlóan a "tábla kitöltéséhez". Mivel az aktuális állapot csak bizonyos lokális állapotoktól függ, eltávolíthatjuk a $dp$ tábla egy dimenzióját a tárkomplexitás csökkentéséhez.
- A részproblémákra bontás egy általános algoritmikus megközelítés, különböző tulajdonságokkal az oszd-meg-és-uralkodj, a dinamikus programozás és a visszalépés esetén.
- A dinamikus programozási feladatoknak három fő jellemzője van: átfedő részproblémák, optimális részstruktúra és utóhatás-mentesség.
- Ha az eredeti probléma optimális megoldása felépíthető a részproblémák optimális megoldásaiból, akkor optimális részstruktúráról beszélünk.
- Az utóhatás-mentesség azt jelenti, hogy adott állapot esetén annak jövőbeli fejlődése csak ettől az állapottól függ, és semmi köze az összes múltbeli állapothoz. Sok kombinatorikus optimalizálási feladat nem rendelkezik utóhatás-mentességgel, és nem oldható meg gyorsan dinamikus programozással.

**Hátizsák-feladat**

- A hátizsák-feladat az egyik legtipikusabb dinamikus programozási feladat, változatai között szerepel a 0-1 hátizsák, a korlátlan hátizsák és a többszörös hátizsák.
- A 0-1 hátizsák állapotdefiníciója az első $i$ tárgy közül $c$ kapacitású hátizsákban elérhető maximális érték. A tárgy hátizsákba nem rakásának és berakásának két döntése alapján azonosítható az optimális részstruktúra és megalkotható az állapot-átmeneti egyenlet. A tárhelyoptimalizálásban, mivel minden állapot a közvetlenül felső és a bal felső állapottól függ, a listát fordított sorrendben kell bejárni a bal felső állapot felülírásának elkerülése érdekében.
- A korlátlan hátizsák-feladatban nincs korlátozás az egyes tárgy típusok kiválasztási mennyiségére, ezért a berakás döntésének állapot-átmenete eltér a 0-1 hátizsák-feladatétól. Mivel az állapot a közvetlenül felső és közvetlenül bal oldali állapottól függ, a tárhelyoptimalizáláshoz előre haladó bejárást kell alkalmazni.
- Az érmecserélési feladat a korlátlan hátizsák-feladat változata. A "maximális" értéket kereséséről a "minimális" érmeszám keresésére változik, ezért az állapot-átmeneti egyenletben a $\max()$-ot $\min()$-re kell cserélni. A hátizsák kapacitásának "nem meghaladásáról" a célösszeg "pontos" kifizetésére változik, ezért az $amt + 1$ értéket használjuk a "célösszeg nem fizethető ki" érvénytelen megoldás jelölésére.
- Az érmecserélési feladat II a "minimális érmeszám" keresésről a "érmekombinációk száma" keresésre változik, ezért az állapot-átmeneti egyenlet $\min()$-je ennek megfelelően összegző operátorra változik.

**Szerkesztési távolság feladat**

- A szerkesztési távolság (Levenshtein-távolság) két karakterlánc hasonlóságának mérésére használatos, az egyik karakterláncból a másikba való átmenethez szükséges minimális szerkesztési lépések számaként definiálva, a szerkesztési műveletek közé tartozik a beillesztés, törlés és csere.
- A szerkesztési távolság feladat állapotdefiníciója az $s$ első $i$ karakterét $t$ első $j$ karakterévé alakításához szükséges minimális szerkesztési lépések száma. Ha $s[i] \ne t[j]$, három döntés lehetséges: beillesztés, törlés, csere, mindegyikhez megfelelő fennmaradó részproblémával. Ebből azonosítható az optimális részstruktúra és megalkotható az állapot-átmeneti egyenlet. Ha $s[i] = t[j]$, az aktuális karakterhez nem szükséges szerkesztés.
- A szerkesztési távolságban az állapot a közvetlenül felső, közvetlenül bal oldali és bal felső állapottól függ, ezért tárhelyoptimalizálás után sem az előre haladó, sem a fordított bejárás nem tudja helyesen végrehajtani az állapot-átmeneteket. Emiatt egy változót használunk a bal felső állapot ideiglenes tárolásához, ezzel átalakítva a helyzetet a korlátlan hátizsák-feladattal egyenértékűvé, lehetővé téve az előre haladó bejárást tárhelyoptimalizálás után.
