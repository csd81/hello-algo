# Az algoritmusok mindenhol jelen vannak

Amikor az „algoritmus" kifejezést halljuk, természetesen a matematikára gondolunk. Azonban sok algoritmus nem tartalmaz összetett matematikát, hanem inkább az alapvető logikára támaszkodik, amely mindennapi életünkben mindenhol megfigyelhető.

Mielőtt hivatalosan elkezdenénk tárgyalni az algoritmusokat, érdemes megosztani egy érdekes tényt: **öntudatlanul már sok algoritmust megtanultál, és megszoktad azokat a mindennapi életedben alkalmazni**. Néhány konkrét példával szeretném ezt bizonyítani.

**1. példa: Szótárban keresés**. Egy angol szótárban a szavak ábécé sorrendben szerepelnek. Ha egy $r$ betűvel kezdődő szót keresünk, általában a következőképpen járunk el:

1. Nyisd ki a szótárt nagyjából a közepénél, és ellenőrizd az oldal első szavát; tegyük fel, hogy a betű $m$-mel kezdődik.
2. Mivel $r$ az ábécében $m$ után következik, az első felet figyelmen kívül hagyhatjuk, és a keresési teret a második felére szűkítjük.
3. Ismételd az `1.` és `2.` lépéseket, amíg megtalálod az oldalt, ahol a szó $r$-rel kezdődik.

=== "<1>"
    ![Szótárban keresés folyamata](algorithms_are_everywhere.assets/binary_search_dictionary_step1.png)

=== "<2>"
    ![Bináris keresés szótárban 2. lépés](algorithms_are_everywhere.assets/binary_search_dictionary_step2.png)

=== "<3>"
    ![Bináris keresés szótárban 3. lépés](algorithms_are_everywhere.assets/binary_search_dictionary_step3.png)

=== "<4>"
    ![Bináris keresés szótárban 4. lépés](algorithms_are_everywhere.assets/binary_search_dictionary_step4.png)

=== "<5>"
    ![Bináris keresés szótárban 5. lépés](algorithms_are_everywhere.assets/binary_search_dictionary_step5.png)

A szótárban való keresés, amely az általános iskolások számára alapvető készség, valójában a „bináris keresés" nevű jól ismert algoritmus. Adatszerkezetek szempontjából a szótárt rendezett „tömbnek" tekinthetjük; algoritmus szempontjából a szókereséshez elvégzett műveletek sorozata a „bináris keresés" algoritmusnak felel meg.

**2. példa: Kártyapakli rendezése**. Kártyajátékok során a kézben lévő lapokat növekvő sorrendbe kell rendezni, az alábbi folyamat szerint.

1. Ossza a lapokat „rendezett" és „rendezetlen" részre; kezdetben a bal szélső lap már rendezettnek tekinthető.
2. Vegyél ki egy lapot a rendezetlen részből, és illeszd be a megfelelő helyre a rendezett részbe; ezután a bal szélső két lap már rendezett.
3. Ismételd a `2.` lépést, amíg az összes lap sorrendben van.

![Kártyapakli rendezésének folyamata](algorithms_are_everywhere.assets/playing_cards_sorting.png)

A fenti kártyarendezési módszer lényegében a „beszúrásos rendezés" algoritmus, amely kisebb adatkészletek esetén nagyon hatékony. Sok programozási nyelv rendezési függvénye tartalmaz beszúrásos rendezést.

**3. példa: Visszajáró adása**. Tegyük fel, hogy $69$-et vásárolunk egy szupermarketben. Ha $100$-ast adunk a pénztárosnak, $31$-et kell visszaadnia. Ez a folyamat az alábbi ábra alapján könnyen megérthető.

1. A lehetséges pénzérmék a $31$ alatti értékek: $1$, $5$, $10$ és $20$.
2. Vegyük ki a legnagyobb $20$-ast a lehetőségek közül; marad $31 - 20 = 11$.
3. Vegyük ki a legnagyobb $10$-est a maradék lehetőségek közül; marad $11 - 10 = 1$.
4. Vegyük ki a legnagyobb $1$-est a maradék lehetőségek közül; marad $1 - 1 = 0$.
5. A visszajáró kiadása kész, a megoldás: $20 + 10 + 1 = 31$.

![Visszajáró adásának folyamata](algorithms_are_everywhere.assets/greedy_change.png)

A leírt lépésekben minden szakasznál a legjobb lehetőséget választjuk, felhasználva a legnagyobb elérhető címletet, ami hatékony visszajáró-adási stratégiát eredményez. Adatszerkezetek és algoritmusok szempontjából ezt a megközelítést „mohó" algoritmusnak nevezzük.

Az étkezéstől az intersztelláris utazásig szinte minden problémamegoldás algoritmusokat foglal magában. A számítógépek megjelenése lehetővé teszi, hogy adatszerkezeteket tároljunk a memóriában, és kódot írjunk a CPU és GPU meghívásához az algoritmusok végrehajtásához. Így a valós életbeli problémákat átvihetjük a számítógépekre, és sokkal hatékonyabb módon oldhatunk meg különféle összetett kérdéseket.

!!! tip

    Ha még mindig homályos a fogalmak, mint az adatszerkezetek, algoritmusok, tömbök és bináris keresés, bátorítlak, hogy olvass tovább. Ez a könyv finoman vezet be az adatszerkezetek és algoritmusok megértésének birodalmába.
