# Kiválasztásos rendezés

A <u>kiválasztásos rendezés (selection sort)</u> nagyon egyszerűen működik: megnyit egy hurkot, és minden körben kiválasztja a legkisebb elemet a rendezetlen intervallumból, majd a rendezett intervallum végéhez helyezi.

Tegyük fel, hogy a tömb hossza $n$. A kiválasztásos rendezés algoritmusfolyamata az alábbi ábrán látható.

1. Kezdetben minden elem rendezetlen, azaz a rendezetlen (index) intervallum $[0, n-1]$.
2. Válasszuk ki a legkisebb elemet a $[0, n-1]$ intervallumban, és cseréljük fel a $0$ indexű elemmel. Befejezés után a tömb első eleme rendezett.
3. Válasszuk ki a legkisebb elemet a $[1, n-1]$ intervallumban, és cseréljük fel az $1$ indexű elemmel. Befejezés után a tömb első 2 eleme rendezett.
4. És így tovább. $n - 1$ kiválasztási és csere kör után a tömb első $n - 1$ eleme rendezett.
5. A csak fennmaradó elem szükségszerűen a legnagyobb elem, nincs szükség rendezésre, így a tömb rendezése kész.

=== "<1>"
    ![Kiválasztásos rendezés lépései](selection_sort.assets/selection_sort_step1.png)

=== "<2>"
    ![selection_sort_step2](selection_sort.assets/selection_sort_step2.png)

=== "<3>"
    ![selection_sort_step3](selection_sort.assets/selection_sort_step3.png)

=== "<4>"
    ![selection_sort_step4](selection_sort.assets/selection_sort_step4.png)

=== "<5>"
    ![selection_sort_step5](selection_sort.assets/selection_sort_step5.png)

=== "<6>"
    ![selection_sort_step6](selection_sort.assets/selection_sort_step6.png)

=== "<7>"
    ![selection_sort_step7](selection_sort.assets/selection_sort_step7.png)

=== "<8>"
    ![selection_sort_step8](selection_sort.assets/selection_sort_step8.png)

=== "<9>"
    ![selection_sort_step9](selection_sort.assets/selection_sort_step9.png)

=== "<10>"
    ![selection_sort_step10](selection_sort.assets/selection_sort_step10.png)

=== "<11>"
    ![selection_sort_step11](selection_sort.assets/selection_sort_step11.png)

A kódban $k$-t használjuk a rendezetlen intervallumon belüli legkisebb elem nyomon követésére:

```src
[file]{selection_sort}-[class]{}-[func]{selection_sort}
```

## Az algoritmus jellemzői

- **$O(n^2)$ időbonyolultság, nem adaptív rendezés**: A külső hurok összesen $n - 1$ kört tartalmaz. Az első körben a rendezetlen intervallum hossza $n$, az utolsó körben $2$. Vagyis a külső hurok minden köre $n$, $n - 1$, $\dots$, $3$, $2$ belső hurokiterációt tartalmaz, összesen $\frac{(n - 1)(n + 2)}{2}$.
- **$O(1)$ térkomplexitás, helyben történő rendezés**: Az $i$ és $j$ mutatók konstans mennyiségű extra tárhelyet használnak.
- **Nem stabil rendezés**: Ahogy az alábbi ábrán látható, a `nums[i]` elem egy vele egyenlő elem jobb oldalára cserélhető, megváltoztatva relatív sorrendjüket.

![Kiválasztásos rendezés nem stabil példa](selection_sort.assets/selection_sort_instability.png)
