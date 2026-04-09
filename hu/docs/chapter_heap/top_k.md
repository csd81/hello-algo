# Top-k probléma

!!! question

    Adott egy $n$ hosszú, rendezetlen `nums` tömb, adjuk vissza a tömb legnagyobb $k$ elemét.

Ennél a problémánál először két viszonylag közvetlen megközelítést mutatunk be, majd egy hatékonyabb kupac alapú megoldást.

## 1. módszer: Iteratív kiválasztás

Az alábbi ábrán látható módon $k$ bejárási kört végezhetünk, és minden körben kinyerjük az $1$., $2.$., $\dots$, $k$. legnagyobb elemet, amelynek időbonyolultsága $O(nk)$.

Ez a módszer csak akkor alkalmazható, ha $k \ll n$, mert ha $k$ közel van $n$-hez, az időbonyolultság $O(n^2)$-hez közelít, ami nagyon időigényes.

![A legnagyobb k elem keresése bejárással](top_k.assets/top_k_traversal.png)

!!! tip

    Ha $k = n$, akkor egy teljes rendezett sorozatot kapunk, ami egyenértékű a „kiválasztásos rendezés" algoritmusával.

## 2. módszer: Rendezés

Az alábbi ábrán látható módon először rendezhetjük a `nums` tömböt, majd visszaadjuk a jobb szélső $k$ elemet, amelynek időbonyolultsága $O(n \log n)$.

Nyilvánvalóan ez a módszer „túlteljesíti" a feladatot, hiszen csak a legnagyobb $k$ elemet kell megtalálnunk, a többi elemet nem kell rendeznünk.

![A legnagyobb k elem keresése rendezéssel](top_k.assets/top_k_sorting.png)

## 3. módszer: Kupac

A Top-k problémát hatékonyabban megoldhatjuk kupacok segítségével, ahogy az alábbi ábrán látható.

1. Inicializálunk egy min-kupacot, ahol a kupac tetején lévő elem a legkisebb.
2. Először a tömb első $k$ elemét sorban behelyezzük a kupacba.
3. A $(k + 1)$. elemtől kezdve, ha az aktuális elem nagyobb a kupac tetején lévő elemnél, eltávolítjuk a kupac tetején lévő elemet, és az aktuális elemet behelyezzük a kupacba.
4. A bejárás befejezése után a kupac a legnagyobb $k$ elemet tartalmazza.

=== "<1>"
    ![A legnagyobb k elem keresése kupaccal](top_k.assets/top_k_heap_step1.png)

=== "<2>"
    ![top_k_heap_step2](top_k.assets/top_k_heap_step2.png)

=== "<3>"
    ![top_k_heap_step3](top_k.assets/top_k_heap_step3.png)

=== "<4>"
    ![top_k_heap_step4](top_k.assets/top_k_heap_step4.png)

=== "<5>"
    ![top_k_heap_step5](top_k.assets/top_k_heap_step5.png)

=== "<6>"
    ![top_k_heap_step6](top_k.assets/top_k_heap_step6.png)

=== "<7>"
    ![top_k_heap_step7](top_k.assets/top_k_heap_step7.png)

=== "<8>"
    ![top_k_heap_step8](top_k.assets/top_k_heap_step8.png)

=== "<9>"
    ![top_k_heap_step9](top_k.assets/top_k_heap_step9.png)

A példakód a következő:

```src
[file]{top_k}-[class]{}-[func]{top_k_heap}
```

Összesen $n$ kupacba helyezési és eltávolítási kör hajtódik végre, a kupac maximális hossza $k$, így az időbonyolultság $O(n \log k)$. Ez a módszer rendkívül hatékony; ha $k$ kicsi, az időbonyolultság $O(n)$-hez közelít; ha $k$ nagy, az időbonyolultság nem haladja meg az $O(n \log n)$-t.

Ráadásul ez a módszer dinamikus adatfolyam forgatókönyvekre is alkalmas. Folyamatos adathozzáadással fenntarthatjuk a kupacban lévő elemeket, így a legnagyobb $k$ elem dinamikus frissítését érhetjük el.
