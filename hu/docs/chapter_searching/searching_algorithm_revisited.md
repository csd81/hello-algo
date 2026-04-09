# Keresési algoritmusok újból áttekintve

<u>A keresési algoritmusok</u> adatszerkezetekben (például tömbökben, láncolt listákban, fákban vagy gráfokban) meghatározott feltételeknek megfelelő egy vagy több elem keresésére szolgálnak.

A keresési algoritmusok implementációs megközelítésük szerint két kategóriába sorolhatók:

- **A célelem megkeresése az adatszerkezet bejárásával**, például tömbök, láncolt listák, fák és gráfok bejárásával.
- **Hatékony elemkeresés elérése az adatszervezési struktúra vagy az adatokban rejlő előzetes információk felhasználásával**, mint például a bináris keresés, hash-alapú keresés és bináris keresőfa keresés.

Könnyen belátható, hogy ezeket a témákat az előző fejezetekben már tárgyaltuk, így a keresési algoritmusok nem ismeretlenek számunkra. Ebben a szakaszban rendszerszemléletűbb megközelítésből vizsgáljuk meg újból a keresési algoritmusokat.

## Nyers erővel való keresés

A nyers erővel való keresés az adatszerkezet minden elemének bejárásával keresi meg a célelemeket.

- A „lineáris keresés" olyan lineáris adatszerkezetekre alkalmazható, mint a tömbök és a láncolt listák. Az adatszerkezet egyik végéről indul, és elemről elemre halad, amíg meg nem találja a célelemet, vagy el nem éri a másik végét anélkül, hogy megtalálná.
- A „szélességi elsőbbségű keresés" és a „mélységi elsőbbségű keresés" gráfok és fák két bejárási stratégiája. A szélességi elsőbbségű keresés a kezdőcsomóponttól rétegről rétegre keres, közelről távolra haladva. A mélységi elsőbbségű keresés a kezdőcsomóponttól indul, egy útvonalat végigkövet a végéig, majd visszalép és más útvonalakat próbál ki, amíg az egész adatszerkezet be nem járódik.

A nyers erővel való keresés előnye az egyszerűsége és jó általánosíthatósága, **nem igényel adatelőkészítést vagy extra adatszerkezeteket**.

Azonban **az ilyen algoritmusok időbonyolultsága $O(n)$**, ahol $n$ az elemek száma, így nagy adatmennyiség kezelésekor a teljesítményük gyenge.

## Adaptív keresés

Az adaptív keresés az adatok egyedi tulajdonságait (például rendezettségét) használja fel a keresési folyamat optimalizálásához, ezáltal hatékonyabban találja meg a célelemeket.

- A „bináris keresés" az adatok rendezettségét használja fel a hatékony kereséshez, csak tömbökre alkalmazható.
- A „hash-alapú keresés" hash táblákat használ kulcs-érték pár leképezések létrehozásához a keresési és célszámok adatai között, ezáltal lekérdezési műveleteket valósít meg.
- A „fa-alapú keresés" bizonyos faszerkezetekben (mint a bináris keresőfák) a csomópontértékek összehasonlítása alapján gyorsan kizárja a csomópontokat a célelemek megkeresésére.

Az ilyen algoritmusok előnye a magas hatékonyság, **időbonyolultságuk $O(\log n)$ vagy akár $O(1)$**.

Azonban **az ilyen algoritmusok használata gyakran adatelőkészítést igényel**. Például a bináris keresés előzetesen rendezett tömböt igényel, míg a hash-alapú keresés és a fa-alapú keresés mindkettő extra adatszerkezeteket igényel, és ezen adatszerkezetek fenntartása szintén extra időt és tárbeli többletet jelent.

!!! tip

    Az adaptív keresési algoritmusokat gyakran keresési algoritmusoknak nevezik, **amelyeket főként specifikus adatszerkezetekben lévő célelemek gyors visszakeresésére alkalmaznak**.

## Keresési módszer kiválasztása

Adott egy $n$ méretű adathalmaz esetén, lineáris keresést, bináris keresést, fa-alapú keresést, hash-alapú keresést és más módszereket alkalmazhatunk a célelem megkeresésére. Az egyes módszerek működési elvei az alábbi ábrán láthatók.

![Több keresési stratégia](searching_algorithm_revisited.assets/searching_algorithms.png)

A fenti módszerek működési hatékonysága és jellemzői a következők:

<p align="center"> Table <id> &nbsp; Keresési algoritmusok hatékonyságának összehasonlítása </p>

|                      | Lineáris keresés | Bináris keresés        | Fa-alapú keresés               | Hash-alapú keresés            |
| -------------------- | ---------------- | ---------------------- | ------------------------------ | ----------------------------- |
| Elem keresése        | $O(n)$           | $O(\log n)$            | $O(\log n)$                    | $O(1)$                        |
| Elem beszúrása       | $O(1)$           | $O(n)$                 | $O(\log n)$                    | $O(1)$                        |
| Elem törlése         | $O(n)$           | $O(n)$                 | $O(\log n)$                    | $O(1)$                        |
| Extra tárterület     | $O(1)$           | $O(1)$                 | $O(n)$                         | $O(n)$                        |
| Adatelőkészítés      | /                | Rendezés $O(n \log n)$ | Faépítés $O(n \log n)$         | Hash tábla építés $O(n)$      |
| Adatok rendezettsége | Rendezetlen      | Rendezett              | Rendezett                      | Rendezetlen                   |

A keresési algoritmus megválasztása az adatmennyiségtől, a keresési teljesítménykövetelményektől, az adatlekérdezési és frissítési gyakoriságtól is függ.

**Lineáris keresés**

- Jó általánosíthatóság, nem igényel adatelőkészítési műveleteket. Ha csak egyszer kell lekérdezni az adatokat, a másik három módszer adatelőkészítési ideje hosszabb lenne, mint a lineáris keresés.
- Kis adatmennyiségre alkalmas, ahol az időbonyolultságnak kisebb hatása van a hatékonyságra.
- Olyan forgatókönyvekre alkalmas, ahol magas az adatfrissítési gyakoriság, mivel ez a módszer nem igényel semmilyen extra adatfenntartást.

**Bináris keresés**

- Nagy adatmennyiségre alkalmas stabil hatékonysági teljesítménnyel, legrosszabb esetben $O(\log n)$ időbonyolultsággal.
- Az adatmennyiség nem lehet túl nagy, mivel a tömbök tárolása folytonos memóriaterületet igényel.
- Nem alkalmas sűrű adatbeszúrási és -törlési forgatókönyvekre, mivel a rendezett tömb fenntartása magas terhelést jelent.

**Hash-alapú keresés**

- Magas lekérdezési teljesítménykövetelményeket igénylő forgatókönyvekre alkalmas, átlagos időbonyolultsága $O(1)$.
- Nem alkalmas rendezett adatokat vagy tartomány-kereséseket igénylő forgatókönyvekre, mivel a hash táblák nem képesek fenntartani az adatok rendezettségét.
- Erősen függ a hash függvénytől és az ütközéskezelési stratégiától, és jelentős teljesítményromlás kockázatával jár.
- Nem alkalmas túlzottan nagy adatmennyiségre, mivel a hash tábláknak extra tárterületre van szükségük az ütközések minimalizálásához, és ezáltal jó lekérdezési teljesítmény nyújtásához.

**Fa-alapú keresés**

- Hatalmas adatmennyiségre alkalmas, mivel a facsomópontok szétszórtan tárolódnak a memóriában.
- Rendezett adatok fenntartását vagy tartomány-kereséseket igénylő forgatókönyvekre alkalmas.
- A folyamatos csomópontbeszúrások és -törlések során a bináris keresőfa ferdevé válhat, az időbonyolultság $O(n)$-re romolhat.
- AVL fa vagy piros-fekete fa alkalmazásával az összes művelet stabil $O(\log n)$ hatékonysággal futhat, de a fa egyensúlyának fenntartásához szükséges műveletek extra terhelést adnak.
