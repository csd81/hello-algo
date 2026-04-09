# Maximális szorzatdarabolás probléma

!!! question

    Adott egy $n$ pozitív egész szám, ossza fel legalább két pozitív egész szám összegére, és keresse meg az összes egész szám maximális szorzatát a felosztás után, ahogy az alábbi ábra mutatja.

![A maximális szorzatdarabolás problémájának definíciója](max_product_cutting_problem.assets/max_product_cutting_definition.png)

Tegyük fel, hogy $n$-t $m$ egész tényezőre osztjuk fel, ahol az $i$-edik tényezőt $n_i$-vel jelöljük, vagyis

$$
n = \sum_{i=1}^{m}n_i
$$

Ennek a problémának a célja az összes egész tényező maximális szorzatának megtalálása, azaz

$$
\max(\prod_{i=1}^{m}n_i)
$$

Elgondolkodnunk kell azon: mekkora legyen a felosztások száma $m$, és mik legyenek az egyes $n_i$ értékek?

### Mohó stratégia meghatározása

Tapasztalat alapján két egész szám szorzata gyakran nagyobb, mint összegük. Tegyük fel, hogy $n$-ből kivezetünk egy $2$ tényezőt, ekkor szorzatuk $2(n-2)$. Ezt a szorzatot összehasonlítjuk $n$-nel:

$$
\begin{aligned}
2(n-2) & \geq n \newline
2n - n - 4 & \geq 0 \newline
n & \geq 4
\end{aligned}
$$

Ahogy az alábbi ábra mutatja, ha $n \geq 4$, egy $2$ kivezetése növeli a szorzatot, **ami azt jelenti, hogy a $4$-nél nagyobb vagy egyenlő egész számokat mind fel kell osztani**.

**Mohó stratégia 1**: Ha a felosztási séma $\geq 4$ tényezőket tartalmaz, akkor azokat tovább kell osztani. A végső felosztási sémának csak $1$, $2$ és $3$ tényezőket szabad tartalmaznia.

![A felosztás miatt a szorzat növekszik](max_product_cutting_problem.assets/max_product_cutting_greedy_infer1.png)

Ezután gondoljuk meg, melyik tényező az optimális. A három $1$, $2$ és $3$ tényező közül az $1$ nyilván a legrosszabb, mert az $1 \times (n-1) < n$ mindig teljesül, ami azt jelenti, hogy az $1$ kivezetése valójában csökkenti a szorzatot.

Ahogy az alábbi ábra mutatja, ha $n = 6$, akkor $3 \times 3 > 2 \times 2 \times 2$. **Ez azt jelenti, hogy a $3$ kivezetése jobb, mint a $2$ kivezetése**.

**Mohó stratégia 2**: A felosztási sémában legfeljebb két $2$ lehet. Mert három $2$-t mindig fel lehet cserélni két $3$-ra, hogy nagyobb szorzatot kapjunk.

![Optimális felosztási tényező](max_product_cutting_problem.assets/max_product_cutting_greedy_infer2.png)

Összefoglalva a következő mohó stratégiák vezethetők le.

1. Adott $n$ egész szám, folyamatosan kivezetünk $3$ tényezőt, amíg a maradék $0$, $1$ vagy $2$ nem lesz.
2. Ha a maradék $0$, az azt jelenti, hogy $n$ $3$ többszöröse, ezért nincs szükség további műveletre.
3. Ha a maradék $2$, ne folytassuk az osztást, tartsuk meg.
4. Ha a maradék $1$, mivel $2 \times 2 > 1 \times 3$, az utolsó $3$-at $2$-vel kell felváltani.

### Kód megvalósítása

Ahogy az alábbi ábra mutatja, nem kell ciklusokat használnunk az egész szám felosztásához, hanem egész osztással megkaphatjuk a $3$-ok számát $a$-ként, és moduló művelettel a maradékot $b$-ként, ekkor:

$$
n = 3 a + b
$$

Megjegyezzük, hogy az $n \leq 3$ éles esetére egy $1$-et kötelező kivezetni, a szorzat $1 \times (n - 1)$.

```src
[file]{max_product_cutting}-[class]{}-[func]{max_product_cutting}
```

![Számítási módszer a maximális szorzatdaraboláshoz](max_product_cutting_problem.assets/max_product_cutting_greedy_calculation.png)

**Az időbonyolultság a programozási nyelvben az exponenciálás műveleti megvalósításától függ**. Pythont például véve, három általánosan használt hatványozási függvény van.

- A `**` operátor és a `pow()` függvény időbonyolultsága egyaránt $O(\log⁡ a)$.
- A `math.pow()` függvény belsőleg a C könyvtár `pow()` függvényét hívja, amely lebegőpontos hatványozást végez, $O(1)$ időbonyolultsággal.

Az $a$ és $b$ változók állandó mennyiségű extra helyet használnak, **ezért a térbonyolultság $O(1)$**.

### Helyességbizonyítás

Ellentmondásos bizonyítással, csak az $n \geq 4$ esetet elemezve.

1. **Minden tényező $\leq 3$**: Tegyük fel, hogy az optimális felosztási séma tartalmaz egy $x \geq 4$ tényezőt, akkor azt biztosan tovább lehet osztani $2(x-2)$-re, hogy nagyobb (vagy egyenlő) szorzatot kapjunk. Ez ellentmond a feltevésnek.
2. **A felosztási séma nem tartalmaz $1$-et**: Tegyük fel, hogy az optimális felosztási séma tartalmaz egy $1$-es tényezőt, akkor azt biztosan össze lehet vonni egy másik tényezővel, hogy nagyobb szorzatot kapjunk. Ez ellentmond a feltevésnek.
3. **A felosztási séma legfeljebb két $2$-t tartalmaz**: Tegyük fel, hogy az optimális felosztási séma három $2$-t tartalmaz, akkor azokat biztosan fel lehet cserélni két $3$-ra a nagyobb szorzatért. Ez ellentmond a feltevésnek.
