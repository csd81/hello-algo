# Kupac építése

Bizonyos esetekben egy lista összes eleméből kupacot szeretnénk felépíteni, ezt a folyamatot „kupac építési műveletnek" nevezzük.

## Megvalósítás elembeillesztéssel

Először létrehozunk egy üres kupacot, majd végigiterálunk a listán, és minden egyes elemen sorban elvégezzük az „elembeillesztési műveletet". Ez azt jelenti, hogy az elemet a kupac aljára adjuk, majd „alulról felfelé" kupacosítást végzünk azon az elemen.

Minden egyes elembeillesztéssel a kupac hossza eggyel nő. Mivel a csomópontokat felülről lefelé haladva adjuk a bináris fához sorban, a kupac „felülről lefelé" épül fel.

$n$ elem esetén minden elembeillesztési művelet $O(\log{n})$ időt igényel, így ez a kupac-felépítési módszer időbonyolultsága $O(n \log n)$.

## Megvalósítás kupacosítási bejárással

Valójában egy hatékonyabb kupac-felépítési módszert is megvalósíthatunk két lépésben.

1. A lista összes elemét változtatás nélkül hozzáadjuk a kupachoz, ekkor a kupac tulajdonsága még nem teljesül.
2. A kupacot fordított sorrendben bejárjuk (a szintenkénti bejárás fordítottja), és minden nem-levél csomóponton sorban „felülről lefelé kupacosítást" végzünk.

**Egy csomópont kupacosítása után az adott csomópontból gyökerező részfa érvényes al-kupaccá válik**. Mivel fordított sorrendben járjuk be, a kupac „alulról felfelé" épül fel.

A fordított sorrendű bejárás azért lett választva, mert biztosítja, hogy az aktuális csomópont alatti részfa már érvényes al-kupac legyen, így az aktuális csomópont kupacosítása hatékony.

Érdemes megjegyezni, hogy **mivel a levélcsomópontoknak nincsenek gyerekeik, természetesen érvényes al-kupacok, és nem igényelnek kupacosítást**. Ahogy az alábbi kódban látható, az utolsó nem-levél csomópont az utolsó csomópont szülője; ettől kezdve járjuk be fordított sorrendben a kupacosítás elvégzéséhez:

```src
[file]{my_heap}-[class]{max_heap}-[func]{__init__}
```

## Bonyolultságelemzés

Következőként megpróbáljuk levezetni ennek a második kupac-felépítési módszernek az időbonyolultságát.

- Feltéve, hogy a teljes bináris fának $n$ csomópontja van, akkor a levélcsomópontok száma $(n + 1) / 2$, ahol $/$ egészrész osztás. Ezért a kupacosítást igénylő csomópontok száma $(n - 1) / 2$.
- A felülről lefelé kupacosítási folyamatban minden csomópontot legfeljebb a levélcsomópontokig kupacosítanak, így az iterációk maximális száma a bináris fa $\log n$ magassága.

E kettőt összeszorozva $O(n \log n)$ időbonyolultságot kapunk a kupac-felépítési folyamatra. **Ez a becslés azonban nem pontos, mivel nem veszi figyelembe azt a tulajdonságot, hogy a bináris fáknak sokkal több csomópontjuk van az alsóbb szinteken, mint a felsőbb szinteken**.

Végezzünk pontosabb számítást. A számítás nehézségének csökkentése érdekében feltételezzük, hogy egy „tökéletes bináris fa" $n$ csomóponttal és $h$ magassággal rendelkezik; ez a feltételezés nem befolyásolja az eredmény helyességét.

![Csomópontok száma egy tökéletes bináris fa egyes szintjein](build_heap.assets/heapify_operations_count.png)

Ahogy a fenti ábrán látható, egy csomópont „felülről lefelé kupacosításának" maximális iterációszáma egyenlő a csomóponttól a levélcsomópontokig tartó távolsággal, ami pontosan a „csomópont magassága". Ezért összegezhetjük az egyes szinteken a „csomópontok száma × csomópont magassága" értékeket az **összes csomópont kupacosítási iterációinak összesített számának meghatározásához**.

$$
T(h) = 2^0h + 2^1(h-1) + 2^2(h-2) + \dots + 2^{(h-1)}\times1
$$

A fenti kifejezés egyszerűsítéséhez középiskolai sorozatismeretekre van szükségünk. Először szorozzuk meg $T(h)$-t $2$-vel:

$$
\begin{aligned}
T(h) & = 2^0h + 2^1(h-1) + 2^2(h-2) + \dots + 2^{h-1}\times1 \newline
2 T(h) & = 2^1h + 2^2(h-1) + 2^3(h-2) + \dots + 2^{h}\times1 \newline
\end{aligned}
$$

A különbségmódszer alkalmazásával vonjuk ki az első egyenletet $T(h)$-t a második egyenletből $2 T(h)$-ból:

$$
2T(h) - T(h) = T(h) = -2^0h + 2^1 + 2^2 + \dots + 2^{h-1} + 2^h
$$

A fenti kifejezést megfigyelve látjuk, hogy $T(h)$ egy mértani sor, amely közvetlenül kiszámítható az összegképlettel, és az időbonyolultság:

$$
\begin{aligned}
T(h) & = 2 \frac{1 - 2^h}{1 - 2} - h \newline
& = 2^{h+1} - h - 2 \newline
& = O(2^h)
\end{aligned}
$$

Továbbá egy $h$ magasságú tökéletes bináris fának $n = 2^{h+1} - 1$ csomópontja van, így a bonyolultság $O(2^h) = O(n)$. Ez a levezetés megmutatja, hogy **egy bemeneti listából kupac felépítésének időbonyolultsága $O(n)$, ami rendkívül hatékony**.
