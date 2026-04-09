# Összefoglalás

### Főbb áttekintés

- A kupac egy teljes bináris fa, amely tulajdonsága alapján max-kupacként vagy min-kupacként kategorizálható. A max-kupac (min-kupac) tetején lévő elem a legnagyobb (legkisebb).
- A prioritásos sor prioritás szerinti rendezéssel rendelkező sorként van definiálva, és általában kupacokkal valósítják meg.
- A kupac leggyakoribb műveletei és azok megfelelő időbonyolultságai: elembeillesztés $O(\log n)$, kupac tetején lévő elem eltávolítása $O(\log n)$, és a kupac tetején lévő elem elérése $O(1)$.
- A teljes bináris fák jól alkalmasak tömb alapú reprezentációra, ezért általában tömböket használunk a kupacok tárolásához.
- A kupacosítási műveletek a kupac tulajdonságának fenntartására szolgálnak, és mind az elembeillesztési, mind az eltávolítási műveletekben alkalmazzák őket.
- $n$ bemeneti elemmel rendelkező kupac felépítésének időbonyolultsága $O(n)$-re optimalizálható, ami rendkívül hatékony.
- A top-k egy klasszikus algoritmus-probléma, amely hatékonyan megoldható a kupac adatstruktúra segítségével, $O(n \log k)$ időbonyolultsággal.

### Kérdések és válaszok

**K**: Az adatstruktúrákban lévő „kupac" és a memóriakezelésben lévő „kupac" ugyanaz a fogalom?

A kettő nem ugyanaz a fogalom; csupán véletlenszerűen osztoznak a „kupac" névben. A számítógépes rendszer memóriájában lévő kupac a dinamikus memória-kiosztás része, ahol a programok futás közben adatok tárolására használhatják. A programok bizonyos mennyiségű kupacmemóriát igényelhetnek összetett struktúrák, például objektumok és tömbök tárolásához. Ha ezekre az adatokra már nincs szükség, a programnak fel kell szabadítania ezt a memóriát a memóriaszivárgás megelőzése érdekében. A verem memóriához képest a kupacmemória kezelése és használata több óvatosságot igényel, mivel nem megfelelő használat esetén olyan problémák merülhetnek fel, mint a memóriaszivárgás és a lógó mutatók.
