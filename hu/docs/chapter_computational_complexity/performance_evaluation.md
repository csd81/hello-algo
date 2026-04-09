# Algoritmusok hatékonyságának kiértékelése

Az algoritmus-tervezésben a következő két szintű célkitűzést követjük sorban.

1. **A probléma megoldásának megtalálása**: Az algoritmusnak megbízhatóan helyes megoldást kell adnia a megadott bemeneti tartományon belül.
2. **Az optimális megoldás keresése**: Ugyanarra a problémára több megoldás is létezhet, és olyan algoritmust szeretnénk találni, amely a lehető leghatékonyabb.

Más szóval, a probléma megoldhatóságának feltételezése mellett az algoritmus hatékonysága vált az elsődleges értékelési szemponttá az algoritmusok minőségének mérésére. Ez a következő két dimenziót foglalja magában.

- **Időhatékonyság**: Az algoritmus futási ideje.
- **Térhatékonyság**: Az algoritmus által elfoglalt memóriaterület mérete.

Röviden összefoglalva, **célunk olyan adatszerkezetek és algoritmusok tervezése, amelyek „egyszerre gyorsak és memóriahatékonyak"**. Az algoritmusok hatékonyságának eredményes értékelése elengedhetetlen, mert csak így tudjuk összehasonlítani a különböző algoritmusokat, és irányítani az algoritmus-tervezési és optimalizálási folyamatot.

A hatékonyságértékelési módszerek főként két típusra oszthatók: tényleges tesztelés és elméleti becslés.

## Tényleges tesztelés

Tegyük fel, hogy van egy `A` algoritmusunk és egy `B` algoritmusunk, mindkettő ugyanazt a problémát oldja meg, és össze kell hasonlítanunk a két algoritmus hatékonyságát. A legközvetlenebb módszer egy számítógép megkeresése, mindkét algoritmus futtatása, valamint futási idejük és memóriahasználatuk megfigyelése és rögzítése. Ez az értékelési megközelítés a valós helyzetet tükrözi, de számos korlátja is van.

Egyrészt **nehéz kiküszöbölni a tesztkörnyezet zavaró tényezőit**. A hardverkonfiguráció befolyásolja az algoritmusok teljesítményét. Például ha egy algoritmus magas párhuzamossági fokú, jobban futtatható több processzormagos CPU-n; ha egy algoritmusnak intenzív memóriaoperációi vannak, jobban teljesít nagy teljesítményű memóriával. Más szóval, egy algoritmus tesztelési eredményei különböző gépeken eltérőek lehetnek. Ez azt jelenti, hogy különböző gépeken kell tesztelni és kiszámítani az átlagos hatékonyságot, ami nem praktikus.

Másrészt **a teljes körű tesztelés nagyon erőforrás-igényes**. Ahogy a bemeneti adatok mennyisége változik, az algoritmus különböző hatékonyságokat mutat. Például ha a bemeneti adatok mennyisége kicsi, az `A` algoritmus futási ideje rövidebb, mint a `B` algoritmusé; de ha a bemeneti adatok mennyisége nagy, a tesztelési eredmények ennek pontosan az ellenkezőjét mutathatják. Ezért meggyőző következtetések levonásához különböző léptékű bemeneti adatokat kell tesztelni, ami nagy számítási erőforrásokat igényel.

## Elméleti becslés

Mivel a tényleges tesztelésnek jelentős korlátai vannak, megfontolhatjuk az algoritmusok hatékonyságának kizárólag számítások útján történő értékelését. Ezt a becslési módszert <u>aszimptotikus komplexitáselemzésnek</u>, röviden <u>komplexitáselemzésnek</u> nevezzük.

A komplexitáselemzés tükrözi az algoritmus végrehajtásához szükséges idő- és térerőforrások, valamint a bemeneti adatok léptéke közötti összefüggést. **Leírja az algoritmus végrehajtásához szükséges idő és tér növekedési tendenciáját a bemeneti adatok léptékének növekedésével**. Ez a meghatározás némileg bonyolult, ezért három kulcsfontosságú pontra bonthatjuk le a megértés érdekében.

- Az „idő- és térerőforrások" az <u>időbonyolultságnak</u> és a <u>térbonyolultságnak</u> felelnek meg.
- A „bemeneti adatok léptékének növekedésével" azt jelenti, hogy a komplexitás tükrözi az algoritmus futási hatékonyságának és a bemeneti adatok léptékének összefüggését.
- Az „idő és tér növekedési tendenciája" azt jelzi, hogy a komplexitáselemzés nem a futási idő vagy az elfoglalt tér konkrét értékeire összpontosít, hanem arra, hogy az idő vagy tér milyen „gyorsan" növekszik.

**A komplexitáselemzés leküzdi a tényleges tesztelési módszer hátrányait**, amelyek a következő szempontokban tükröződnek.

- Nem szükséges ténylegesen futtatni a kódot, ami környezetbarátabbá és energiahatékonyabbá teszi.
- Független a tesztkörnyezettől, és az elemzési eredmények minden futtatási platformon alkalmazhatók.
- Tükrözheti az algoritmusok hatékonyságát különböző adatmennyiségek esetén, különösen nagy adatmennyiségek esetén.

!!! tip

    Ha még mindig homályos a komplexitás fogalma, ne aggódj – a következő fejezetekben részletesen tárgyaljuk.

A komplexitáselemzés „mérőeszközt" nyújt az algoritmusok hatékonyságának értékeléséhez, lehetővé téve, hogy megmérjük egy adott algoritmus végrehajtásához szükséges idő- és térerőforrásokat, és összehasonlítsuk a különböző algoritmusok hatékonyságát.

A komplexitás matematikai fogalom, amely a kezdők számára viszonylag elvont lehet, és viszonylag magas a tanulási nehézség. Ebből a szempontból a komplexitáselemzés nem feltétlenül a legalkalmasabb első tárgyalandó tartalom. Azonban amikor egy adott adatszerkezet vagy algoritmus jellemzőiről tárgyalunk, nehéz elkerülni a futási sebesség és a memóriahasználat elemzését.

Összefoglalva, ajánlott, hogy mielőtt mélyen elmerülnél az adatszerkezetekben és algoritmusokban, **először alakíts ki egy előzetes megértést a komplexitáselemzésről, hogy képes legyél egyszerű algoritmusok komplexitáselemzésére**.
