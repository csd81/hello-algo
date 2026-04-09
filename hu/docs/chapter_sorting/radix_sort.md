# Alaprendezés

Az előző fejezet bevezette a számlálórendezést, amely olyan helyzetekhez alkalmas, ahol az adatmennyiség $n$ nagy, de az adattartomány $m$ kicsi. Tegyük fel, hogy $n = 10^6$ hallgatói azonosítót kell rendeznünk, és a hallgatói azonosító 8 jegyű szám, ami azt jelenti, hogy az adattartomány $m = 10^8$ nagyon nagy. A számlálórendezés alkalmazása nagy mennyiségű memória tárhelyet igényelne, míg az alaprendezés ezt a helyzetet el tudja kerülni.

Az <u>alaprendezés (radix sort)</u> alapgondolata megegyezik a számlálórendezéssel, amely szintén mennyiségek megszámlálásával éri el a rendezést. Erre építve az alaprendezés felhasználja a számjegyek közötti progresszív kapcsolatot, sorban rendezve az egyes számjegyeket, hogy megkapja a végső rendezési eredményt.

## Az algoritmus folyamata

A hallgatói azonosító adatokat példaként véve, tegyük fel, hogy a legalsó jegy az $1$. jegy, a legfelső jegy a $8$. jegy. Az alaprendezés folyamata az alábbi ábrán látható.

1. Inicializáljuk a $k = 1$ jegyet.
2. Végezzük el a "számlálórendezést" a hallgatói azonosítók $k$. jegyén. Befejezés után az adatok a $k$. jegy szerint növekvő sorrendbe rendeződnek.
3. Növeljük $k$-t $1$-gyel, majd térjünk vissza a `2.` lépéshez és folytassuk az iterációt, amíg az összes jegy rendezve nincs, ekkor a folyamat véget ér.

![Alaprendezés algoritmusfolyamata](radix_sort.assets/radix_sort_overview.png)

Az alábbiakban elemezzük a kód megvalósítását. Egy $d$ alapú $x$ szám esetén a $k$. jegy $x_k$ kiszámításához a következő képlet használható:

$$
x_k = \lfloor\frac{x}{d^{k-1}}\rfloor \bmod d
$$

Ahol $\lfloor a \rfloor$ az $a$ lebegőpontos szám lefelé kerekítését jelöli, és $\bmod \: d$ a $d$-vel való modulo (maradék) számítást jelöli. A hallgatói azonosító adatoknál $d = 10$ és $k \in [1, 8]$.

Ezenkívül kissé módosítanunk kell a számlálórendezés kódját, hogy a szám $k$. jegye alapján rendezzen:

```src
[file]{radix_sort}-[class]{}-[func]{radix_sort}
```

!!! question "Miért a legalacsonyabb jegytől kezdjük a rendezést?"

    Az egymást követő rendezési körökben egy későbbi kör eredménye felülírja egy korábbi kör eredményét. Például, ha az első kör eredménye $a < b$, míg a második kör eredménye $a > b$, akkor a második kör eredménye felváltja az első kör eredményét. Mivel a magasabb rendű jegyek magasabb prioritással bírnak, mint az alacsonyabb rendű jegyek, először az alacsonyabb jegyeket kell rendeznünk, majd a magasabb jegyeket.

## Az algoritmus jellemzői

A számlálórendezéssel összehasonlítva az alaprendezés nagyobb numerikus tartományokhoz alkalmas, **de az előfeltétel az, hogy az adatoknak rögzített számú jegyen kell reprezentálhatónak lenniük, és a jegyek száma nem lehet túl nagy**. Például a lebegőpontos számok nem alkalmasak alaprendezésre, mivel jegyeik $k$ száma túl nagy lehet, ami potenciálisan $O(nk) \gg O(n^2)$ időbonyolultsághoz vezethet.

- **$O(nk)$ időbonyolultság, nem adaptív rendezés**: Legyen az adatmennyiség $n$, az adatok $d$ alapú számok, a jegyek maximális száma $k$. Ekkor egy adott jegy számlálórendezése $O(n + d)$ időt vesz igénybe, és az összes $k$ jegy rendezése $O((n + d)k)$ időt vesz igénybe. Általában mind $d$, mind $k$ viszonylag kicsi, és az időbonyolultság $O(n)$-re tendál.
- **$O(n + d)$ térkomplexitás, nem helyben történő rendezés**: A számlálórendezéshez hasonlóan az alaprendezés $n$ és $d$ hosszúságú `res` és `counter` segédtömböket igényel.
- **Stabil rendezés**: Ha a számlálórendezés stabil, az alaprendezés is stabil; ha a számlálórendezés nem stabil, az alaprendezés nem garantálhat helyes rendezési eredményeket.
