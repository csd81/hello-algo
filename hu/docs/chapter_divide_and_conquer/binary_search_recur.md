# Oszd meg és uralkodj keresési stratégia

Már megismertük, hogy a keresési algoritmusok két fő kategóriára oszthatók.

- **Nyers erő keresés**: Adatstruktúra bejárásával valósítható meg, időbonyolultsága $O(n)$.
- **Adaptív keresés**: Egyedi adatszervezési formákat vagy előzetes információkat használ fel, időbonyolultsága $O(\log n)$ vagy akár $O(1)$.

Valójában **az $O(\log n)$ időbonyolultságú keresési algoritmusokat jellemzően az oszd meg és uralkodj stratégia alapján valósítják meg**, mint például a bináris keresés és a fák.

- A bináris keresés minden lépése a problémát (egy célelem keresése egy tömbben) kisebb problémává alakítja (a célelem keresése a tömb felében), és addig folytatódik, amíg a tömb üres nem lesz, vagy meg nem találja a célelemet.
- A fák az oszd meg és uralkodj gondolat reprezentatív képviselői. Bináris keresési fák, AVL-fák és kupacok esetén a különböző műveletek időbonyolultsága $O(\log n)$.

A bináris keresés oszd meg és uralkodj stratégiája a következő.

- **A probléma lebontható**: A bináris keresés rekurzívan lebontja az eredeti problémát (keresés egy tömbben) részproblémákra (keresés a tömb felében), amit a középső elem és a célelem összehasonlításával ér el.
- **A részproblémák függetlenek**: A bináris keresésben minden körben csak egy részproblémát kezelünk, amelyet más részproblémák nem befolyásolnak.
- **A részproblémák megoldásait nem kell összefésülni**: A bináris keresés célja egy adott elem megkeresése, ezért nincs szükség a részproblémák megoldásainak összefésülésére. Amikor egy részproblémát megoldunk, az eredeti problémát is megoldottuk.

Az oszd meg és uralkodj azért javítja a keresési hatékonyságot, mert a nyers erő keresés köréből csak egy lehetőséget tud minden körben kizárni, **míg az oszd meg és uralkodj keresés minden körben a lehetőségek felét zárja ki**.

### Bináris keresés megvalósítása oszd meg és uralkodj alapján

Az előző fejezetekben a bináris keresést iteráció alapján valósítottuk meg. Most oszd meg és uralkodj (rekurzió) alapján valósítjuk meg.

!!! question

    Adott egy $n$ hosszúságú rendezett `nums` tömb, amelynek minden eleme egyedi. Keressük meg a `target` elemet.

Az oszd meg és uralkodj szempontjából a $[i, j]$ keresési intervallumnak megfelelő részproblémát $f(i, j)$-vel jelöljük.

Az eredeti $f(0, n-1)$ problémától kiindulva a bináris keresést a következő lépésekkel végezzük el.

1. Kiszámítjuk a $[i, j]$ keresési intervallum $m$ középső pontját, és ezzel a keresési intervallum felét kizárjuk.
2. Rekurzívan megoldjuk a felére csökkentett méretű részproblémát, amely $f(i, m-1)$ vagy $f(m+1, j)$ lehet.
3. Megismételjük az `1.` és `2.` lépéseket, amíg meg nem találjuk a `target`-et, vagy az intervallum üres nem lesz, majd visszatérünk.

Az alábbi ábra bemutatja a bináris keresés oszd meg és uralkodj folyamatát a $6$ elem keresésére egy tömbben.

![A bináris keresés oszd meg és uralkodj folyamata](binary_search_recur.assets/binary_search_recur.png)

A megvalósítási kódban egy `dfs()` rekurzív függvényt deklarálunk az $f(i, j)$ probléma megoldására:

```src
[file]{binary_search_recur}-[class]{}-[func]{binary_search}
```
