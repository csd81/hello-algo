# Összefoglalás

### Kulcsfontosságú áttekintés

- Adott egy `key` bemenet, a hash tábla $O(1)$ időben képes visszaadni a megfelelő `value` értéket, ami igen hatékony.
- A hash táblák gyakori műveletei közé tartozik a lekérdezés, kulcs-érték párok hozzáadása, kulcs-érték párok törlése és a hash tábla bejárása.
- A hash függvény a `key`-t tömbindexre képezi le, lehetővé téve a megfelelő vödör elérését és a `value` visszakeresését.
- Két különböző kulcs hashelés után ugyanolyan tömbindexet kaphat, ami helytelen lekérdezési eredményekhez vezet. Ezt a jelenséget hash ütközésnek nevezzük.
- Minél nagyobb a hash tábla kapacitása, annál kisebb a hash ütközések valószínűsége. Ezért a hash tábla bővítése enyhítheti a hash ütközéseket. A tömbbővítéshez hasonlóan a hash tábla bővítése is költséges.
- A terhelési tényező, amelyet az elemek száma osztva a vödrök számával kapunk, tükrözi a hash ütközések súlyosságát, és gyakran a hash tábla bővítésének feltételeként használják.
- A láncolás úgy kezeli a hash ütközéseket, hogy minden elemet láncolt listává alakít, és az összes ütköző elemet ugyanabban a láncolt listában tárolja. Az azonban, hogy a túl hosszú láncolt listák csökkenthetik a lekérdezési hatékonyságot, javítható azzal, ha a láncolt listákat piros-fekete fákká alakítjuk.
- A nyílt címzés többszörös próbálkozásokon keresztül kezeli a hash ütközéseket. A lineáris próbálkozás rögzített lépésközöt alkalmaz, de nem tud elemeket törölni és hajlamos klaszteresedésre. A kettős hashelés több hash függvényt alkalmaz a próbálkozáshoz, ami csökkenti a klaszteresedést a lineáris próbálkozáshoz képest, de növeli a számítási terhelést.
- A különböző programozási nyelvek különböző hash tábla megvalósításokat alkalmaznak. Például a Java `HashMap`-je láncolást alkalmaz, míg a Python `dict`-je nyílt címzést használ.
- A hash táblákban determinizmussal, magas hatékonysággal és egyenletes eloszlással rendelkező hash algoritmusokat keresünk. A kriptográfiában a hash algoritmusoknak ütközési ellenállással és lavina-hatással is kell rendelkezniük.
- A hash algoritmusok általában nagy prímszámokat használnak modulusként a hash értékek egyenletes eloszlásának maximalizálása és a hash ütközések csökkentése érdekében.
- A gyakori hash algoritmusok közé tartozik az MD5, SHA-1, SHA-2 és SHA-3. Az MD5-öt gyakran fájlintegritás-ellenőrzésre használják, míg a SHA-2-t általánosan alkalmazzák biztonságos alkalmazásokban és protokollokban.
- A programozási nyelvek általában beépített hash algoritmusokat biztosítanak az adattípusokhoz a hash táblák vödörindexeinek kiszámításához. Általában csak megváltoztathatatlan objektumok hashelhető.

### Kérdések és válaszok

**K**: Mikor romlik $O(n)$-re egy hash tábla időbonyolultsága?

Egy hash tábla időbonyolultsága $O(n)$-re romolhat, ha a hash ütközések súlyosak. Ha a hash függvény jól tervezett, a kapacitás megfelelően van beállítva és az ütközések egyenletesen oszlanak el, az időbonyolultság $O(1)$. A programozási nyelvekben lévő beépített hash táblák használatakor általában $O(1)$ időbonyolultságnak tekintjük.

**K**: Miért ne használjuk a $f(x) = x$ hash függvényt? Ez kiküszöbölné az ütközéseket.

A $f(x) = x$ hash függvény esetén minden elem egyedi vödörindexnek felel meg, ami egyenértékű egy tömbbel. Azonban a bemeneti tér általában sokkal nagyobb a kimeneti térnél (tömb hosszánál), ezért a hash függvény utolsó lépése általában a tömb hosszával való modulózás. Más szóval, a hash tábla célja egy nagyobb állapottér kisebbre való leképezése $O(1)$ lekérdezési hatékonysággal.

**K**: Miért lehetnek a hash táblák hatékonyabbak a tömböknél, láncolt listáknál vagy bináris fáknál, annak ellenére, hogy a hash táblákat éppen ezekkel a struktúrákkal valósítják meg?

Először is, a hash tábláknak magasabb az időhatékonyságuk, de alacsonyabb a térhatékonyságuk. A hash táblákban a memória jelentős része felhasználatlan marad.

Másodszor, a hash táblák csak bizonyos felhasználási esetekben hatékonyabbak időben. Ha egy funkció azonos időbonyolultsággal megvalósítható tömbök vagy láncolt listák segítségével, ez általában gyorsabb, mint hash tábla használata. Ennek oka az, hogy a hash függvény kiszámítása terhelést jelent, ami nagyobbá teszi az időbonyolultság konstans tényezőjét.

Végül, a hash táblák időbonyolultsága romolhat. Például láncolás esetén a keresési műveletek láncolt listában vagy piros-fekete fában hajtódnak végre, ami még mindig $O(n)$ időre romolhat.

**K**: A kettős hashelésnek is megvan az a hibája, hogy nem lehet közvetlenül elemeket törölni? Fel lehet-e újra használni a töröltként megjelölt tárhelyet?

A kettős hashelés a nyílt címzés egy formája, és minden nyílt címzési módszernek megvan az a hátránya, hogy nem tud közvetlenül elemeket törölni; töröltként kell megjelölniük az elemeket. A megjelölt helyek újra felhasználhatók. Amikor új elemeket szúrunk be a hash táblába, és a hash függvény egy töröltként megjelölt pozícióra mutat, azt a pozíciót az új elem használhatja. Ez fenntartja a hash tábla próbálkozási sorozatát, miközben biztosítja a tárhelyek hatékony kihasználását.

**K**: Miért fordulnak elő hash ütközések a lineáris próbálkozásos keresési folyamat során?

A keresési folyamat során a hash függvény a megfelelő vödörre és kulcs-érték párra mutat. Ha a `key` nem egyezik, ez hash ütközést jelez. Ezért a lineáris próbálkozás előre halad egy előre meghatározott lépésközzel, amíg meg nem találja a helyes kulcs-érték párt, vagy a keresés sikertelenül zárul.

**K**: Miért enyhítheti a hash tábla bővítése a hash ütközéseket?

Egy hash függvény utolsó lépése általában a tömb hosszával $n$ való modulózás, hogy a kimenet a tömb indexhatárain belül maradjon. Bővítéskor a tömb hossza $n$ megváltozik, és a kulcsoknak megfelelő indexek is megváltozhatnak. Azok a kulcsok, amelyek korábban ugyanabba a vödörbe kerültek, bővítés után több vödörbe oszlódhatnak, ezáltal enyhítve a hash ütközéseket.
