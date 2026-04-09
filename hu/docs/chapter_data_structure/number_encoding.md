# Számkódolás *

!!! tip

    Ebben a könyvben a csillaggal (*) jelölt fejezetek opcionális olvasmányok. Ha kevés az ideje, vagy nehéznek találja őket, kezdetben kihagyhatja ezeket, és az alapvető fejezetek elvégzése után visszatérhet rájuk.

## Előjel-abszolút érték, egyes komplemens és kettes komplemens

Az előző fejezet táblázatából kiderült, hogy minden egész típus egy értékkel több negatív számot tud ábrázolni, mint amennyit pozitívat. Például a `byte` típus tartománya $[-128, 127]$. Ez a jelenség ellentmondásosnak tűnik, és mögöttes oka az előjel-abszolút értékkel, az egyes komplementssel és a kettes komplementssel kapcsolatos ismeretekhez vezet.

Először is fontos megjegyezni, hogy **a számok a számítógépekben „kettes komplemens" formájában tárolódnak**. Mielőtt megvizsgálnánk ennek okait, definiáljuk ezt a három fogalmat.

- **Előjel-abszolút érték**: Egy szám bináris ábrázolásának legmagasabb bitjét előjelbitnek tekintjük, ahol a $0$ pozitív számot, az $1$ negatív számot jelöl; a többi bit a szám értékét adja meg.
- **Egyes komplemens**: Pozitív szám esetén az egyes komplemens megegyezik az előjel-abszolút értékkel. Negatív szám esetén az egyes komplemens az előjel-abszolút értékből az előjelbit kivételével az összes bit invertálásával kapható meg.
- **Kettes komplemens**: Pozitív szám esetén a kettes komplemens megegyezik az előjel-abszolút értékkel. Negatív szám esetén a kettes komplemens az egyes komplemenshez $1$-et adva kapható meg.

Az alábbi ábra az előjel-abszolút érték, az egyes komplemens és a kettes komplemens közötti átváltási módszereket mutatja be.

![Átváltás az előjel-abszolút érték, az egyes komplemens és a kettes komplemens között](number_encoding.assets/1s_2s_complement.png)

Az <u>előjel-abszolút érték</u>, bár a legszemléletesebb, bizonyos korlátokkal rendelkezik. Egyrészt **a negatív számok előjel-abszolút értéke nem használható közvetlenül műveletekben**. Például az $1 + (-2)$ kiszámítása előjel-abszolút érték alapján $-3$-at adna, ami nyilvánvalóan helytelen.

$$
\begin{aligned}
& 1 + (-2) \newline
& \rightarrow 0000 \; 0001 + 1000 \; 0010 \newline
& = 1000 \; 0011 \newline
& \rightarrow -3
\end{aligned}
$$

E probléma megoldására a számítógépek bevezették az <u>egyes komplementset</u>. Ha az előjel-abszolút értéket egyes komplementssé alakítjuk, és az $1 + (-2)$-t egyes komplemensben számítjuk ki, majd az eredményt visszaalakítjuk előjel-abszolút értékké, megkapjuk a helyes $-1$ eredményt.

$$
\begin{aligned}
& 1 + (-2) \newline
& \rightarrow 0000 \; 0001 \; \text{(Előjel-abszolút érték)} + 1000 \; 0010 \; \text{(Előjel-abszolút érték)} \newline
& = 0000 \; 0001 \; \text{(Egyes komplemens)} + 1111  \; 1101 \; \text{(Egyes komplemens)} \newline
& = 1111 \; 1110 \; \text{(Egyes komplemens)} \newline
& = 1000 \; 0001 \; \text{(Előjel-abszolút érték)} \newline
& \rightarrow -1
\end{aligned}
$$

Másrészt **a nulla előjel-abszolút értékének két reprezentációja létezik: $+0$ és $-0$**. Ez azt jelenti, hogy a nulla számnak két különböző bináris kódolás felel meg, ami félreértésekhez vezethet. Például feltételes elágazásoknál, ha nem teszünk különbséget a pozitív nulla és a negatív nulla között, helytelen eredmény születhet. Ha kezelni szeretnénk a pozitív és negatív nulla kétértelműségét, további összehasonlító műveletekre van szükség, ami csökkenti a számítógép számítási hatékonyságát.

$$
\begin{aligned}
+0 & \rightarrow 0000 \; 0000 \newline
-0 & \rightarrow 1000 \; 0000
\end{aligned}
$$

Az előjel-abszolút értékhez hasonlóan az egyes komplemensnek is megvan a pozitív és negatív nulla kétértelműségének problémája. Ezért a számítógépek bevezették a <u>kettes komplementset</u>. Először figyeljük meg a negatív nulla átváltási folyamatát az előjel-abszolút értéktől az egyes komplemensen át a kettes komplemensig:

$$
\begin{aligned}
-0 \rightarrow \; & 1000 \; 0000 \; \text{(Előjel-abszolút érték)} \newline
= \; & 1111 \; 1111 \; \text{(Egyes komplemens)} \newline
= 1 \; & 0000 \; 0000 \; \text{(Kettes komplemens)} \newline
\end{aligned}
$$

A negatív nulla egyes komplementséhez $1$-et adva átvitel keletkezik, de mivel a `byte` típus hossza mindössze 8 bit, a 9. bitre átvitt $1$ elveszik. Vagyis **a negatív nulla kettes komplemense $0000 \; 0000$, ami megegyezik a pozitív nulla kettes komplemensével**. Ez azt jelenti, hogy kettes komplemens ábrázolásban csak egyféle nulla létezik, és ezzel a pozitív és negatív nulla kétértelműsége megoldódik.

Még egy kérdés maradt: a `byte` típus tartománya $[-128, 127]$, és hogyan keletkezik a plusz egy $-128$ értékű negatív szám? Megfigyelhető, hogy a $[-127, +127]$ intervallumban lévő összes egész számnak megfelel egy előjel-abszolút érték, egyes és kettes komplemens, és az előjel-abszolút érték és a kettes komplemens kölcsönösen átváltható.

Azonban **a $1000 \; 0000$ kettes komplemens kivétel, és nincs megfelelő előjel-abszolút értéke**. Az átváltási módszer szerint ennek a kettes komplemensnek az előjel-abszolút értéke $0000 \; 0000$ lenne. Ez nyilvánvalóan ellentmondásos, hiszen ez az előjel-abszolút érték a $0$ számot jelöli, amelynek kettes komplemense önmaga kellene legyen. A számítógép kikötötte, hogy ez a speciális $1000 \; 0000$ kettes komplemens értéke $-128$. Valójában a $(-1) + (-127)$ kettes komplemensben való kiszámításának eredménye $-128$.

$$
\begin{aligned}
& (-127) + (-1) \newline
& \rightarrow 1111 \; 1111 \; \text{(Előjel-abszolút érték)} + 1000 \; 0001 \; \text{(Előjel-abszolút érték)} \newline
& = 1000 \; 0000 \; \text{(Egyes komplemens)} + 1111  \; 1110 \; \text{(Egyes komplemens)} \newline
& = 1000 \; 0001 \; \text{(Kettes komplemens)} + 1111  \; 1111 \; \text{(Kettes komplemens)} \newline
& = 1000 \; 0000 \; \text{(Kettes komplemens)} \newline
& \rightarrow -128
\end{aligned}
$$

Talán észrevette, hogy a fenti számítások mindegyike összeadási művelet. Ez egy fontos tényre utal: **a számítógépek belső hardveres áramkörei főként összeadási műveleteken alapulnak**. Ennek oka, hogy az összeadás hardverben egyszerűbben valósítható meg más műveletekhez (például szorzás, osztás és kivonás) képest, könnyebben párhuzamosítható, és gyorsabb.

Vegyük figyelembe, hogy ez nem azt jelenti, hogy a számítógépek csak összeadást tudnak végezni. **Az összeadás és néhány alapvető logikai művelet kombinálásával a számítógépek különféle egyéb matematikai műveleteket is el tudnak végezni**. Például az $a - b$ kivonás kiszámítása átváltható az $a + (-b)$ összeadás kiszámítására; a szorzás és osztás kiszámítása átváltható több összeadás vagy kivonás kiszámítására.

Most összefoglalhatjuk, miért használnak a számítógépek kettes komplementst: a kettes komplemens alapú ábrázolással a számítógépek ugyanazokat az áramköröket és műveleteket tudják használni a pozitív és negatív számok összeadásához, anélkül hogy speciális hardveres áramköröket kellene tervezni a kivonáshoz, és anélkül hogy külön kellene kezelni a pozitív és negatív nulla kétértelműségének problémáját. Ez nagyban leegyszerűsíti a hardvertervezést és javítja a működési hatékonyságot.

A kettes komplemens kialakítása nagyon szellemes. Terjedelmi korlátok miatt itt megállunk. Az érdeklődő olvasókat arra bátorítjuk, hogy mélyebben utánanézzenek a témának.

## Lebegőpontos számok kódolása

A figyelmesebb olvasók talán észrevették: az `int` és a `float` azonos hosszúságú, mindkettő 4 bájt, de miért van a `float`-nak jóval nagyobb értékkészlete mint az `int`-nek? Ez nagyon ellentmondásosnak tűnik, hiszen ésszerűen gondolva a `float`-nak tizedes törteket is kell ábrázolnia, tehát kisebb tartományú kellene legyen.

Valójában **ez azért van, mert a `float` lebegőpontos szám eltérő ábrázolási módszert alkalmaz**. Jelöljünk egy 32 bites bináris számot a következőképpen:

$$
b_{31} b_{30} b_{29} \ldots b_2 b_1 b_0
$$

Az IEEE 754 szabvány szerint egy 32 bites `float` a következő három részből áll.

- Előjelbit $\mathrm{S}$: 1 bitet foglal el, a $b_{31}$-nek felel meg.
- Kitevő bit $\mathrm{E}$: 8 bitet foglal el, a $b_{30} b_{29} \ldots b_{23}$-nak felel meg.
- Törtbit $\mathrm{N}$: 23 bitet foglal el, a $b_{22} b_{21} \ldots b_0$-nak felel meg.

A bináris `float` értékének kiszámítási módja:

$$
\text {val} = (-1)^{b_{31}} \times 2^{\left(b_{30} b_{29} \ldots b_{23}\right)_2-127} \times\left(1 . b_{22} b_{21} \ldots b_0\right)_2
$$

Tizedes törtre alakítva a számítási képlet:

$$
\text {val}=(-1)^{\mathrm{S}} \times 2^{\mathrm{E} -127} \times (1 + \mathrm{N})
$$

Az egyes komponensek tartományai:

$$
\begin{aligned}
\mathrm{S} \in & \{ 0, 1\}, \quad \mathrm{E} \in \{ 1, 2, \dots, 254 \} \newline
(1 + \mathrm{N}) = & (1 + \sum_{i=1}^{23} b_{23-i} 2^{-i}) \subset [1, 2 - 2^{-23}]
\end{aligned}
$$

![A float kiszámítási példája az IEEE 754 szabvány szerint](number_encoding.assets/ieee_754_float.png)

A fenti ábrát szemlélve, adott $\mathrm{S} = 0$, $\mathrm{E} = 124$, $\mathrm{N} = 2^{-2} + 2^{-3} = 0.375$ példaadatokkal:

$$
\text { val } = (-1)^0 \times 2^{124 - 127} \times (1 + 0.375) = 0.171875
$$

Most már megválaszolhatjuk a kezdeti kérdést: **a `float` ábrázolása tartalmaz kitevő bitet, aminek következtében a tartomány jóval nagyobb mint az `int`-é**. A fenti számítás szerint a `float` által ábrázolható legnagyobb pozitív szám $2^{254 - 127} \times (2 - 2^{-23}) \approx 3.4 \times 10^{38}$, és a legkisebb negatív szám az előjelbit felcserélésével kapható meg.

**Bár a `float` lebegőpontos szám kibővíti a tartományt, mellékhatásként pontosságot áldoz fel**. Az egész típusú `int` mind a 32 bitet a szám ábrázolására használja, és a számok egyenletesen oszlanak el; azonban a kitevő bit létezése miatt a `float` lebegőpontos szám értékének növekedésével általában egyre nagyobb lesz a különbség két szomszédos szám között.

Ahogy az alábbi táblázat mutatja, a $\mathrm{E} = 0$ és $\mathrm{E} = 255$ kitevő bitek speciális jelentéssel bírnak, **nullák, végtelenségek, $\mathrm{NaN}$ stb. ábrázolására szolgálnak.**

<p align="center"> Táblázat <id> &nbsp; A kitevő bitek jelentése </p>

| Kitevő bit E       | Törtbit $\mathrm{N} = 0$ | Törtbit $\mathrm{N} \ne 0$ | Számítási képlet                                                        |
| ------------------ | ------------------------ | -------------------------- | ----------------------------------------------------------------------- |
| $0$                | $\pm 0$                  | Szubnormális szám          | $(-1)^{\mathrm{S}} \times 2^{-126} \times (0.\mathrm{N})$               |
| $1, 2, \dots, 254$ | Normális szám            | Normális szám              | $(-1)^{\mathrm{S}} \times 2^{(\mathrm{E} -127)} \times (1.\mathrm{N})$ |
| $255$              | $\pm \infty$             | $\mathrm{NaN}$             |                                                                         |

Érdemes megjegyezni, hogy a szubnormális számok jelentősen javítják a lebegőpontos számok pontosságát. A legkisebb pozitív normális szám $2^{-126}$, a legkisebb pozitív szubnormális szám $2^{-126} \times 2^{-23}$.

A dupla pontosságú `double` egy `float`-hoz hasonló ábrázolási módszert alkalmaz, amelyet itt nem fejtünk ki részletesen.
