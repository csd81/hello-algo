# Összefoglalás

### Kulcsfontosságú áttekintés

- A mohó algoritmusokat általában optimalizálási problémák megoldásához használják. Az elv az, hogy minden döntési szakaszban lokálisan optimális döntéseket hozzunk abban a reményben, hogy globálisan optimális megoldást kapjunk.
- A mohó algoritmusok iteratívan hoznak egymás után mohó döntéseket, minden körben kisebb részproblémává alakítva a problémát, amíg a probléma meg nem oldódik.
- A mohó algoritmusok nemcsak egyszerűen valósíthatók meg, hanem magas problémamegoldó hatékonysággal is rendelkeznek. A dinamikus programozáshoz képest a mohó algoritmusok általában alacsonyabb időbonyolultsággal rendelkeznek.
- A pénzváltás problémájában bizonyos érmekombinációk esetén a mohó algoritmusok garantálhatják az optimális megoldás megtalálását; más érmekombinációk esetén azonban a mohó algoritmusok nagyon rossz megoldásokat is adhatnak.
- A mohó algoritmusokkal való megoldásra alkalmas problémák két fő tulajdonsággal rendelkeznek: mohó választás tulajdonsága és optimális részstruktúra. A mohó választás tulajdonsága a mohó stratégia hatékonyságát reprezentálja.
- Néhány összetett probléma esetén a mohó választás tulajdonságának bizonyítása nem egyszerű. Viszonylag könnyebb cáfolni, mint a pénzváltás problémájában.
- A mohó problémák megoldása főként három lépésből áll: problémaelemzés, a mohó stratégia meghatározása és helyességbizonyítás. Ezek közül a mohó stratégia meghatározása az alapvető lépés, a helyességbizonyítás pedig gyakran a nehézségi pont.
- A töredékes hátizsák probléma a 0-1 hátizsák probléma alapján lehetővé teszi a tárgyak egy részének kiválasztását, ezért mohó algoritmusokkal megoldható. A mohó stratégia helyessége ellentmondásos bizonyítással igazolható.
- A maximális kapacitás probléma kimerítő felsorolással $O(n^2)$ időbonyolultsággal megoldható. Egy mohó stratégia tervezésével, amely minden körben a rövid válaszfalat mozgatja befelé, az időbonyolultság $O(n)$-re optimalizálható.
- A maximális szorzatdarabolás problémájában egymás után két mohó stratégiát vezetünk le: a $\geq 4$ egész számokat mind tovább kell osztani, és az optimális felosztási tényező $3$. A kód tartalmaz hatványozási műveleteket, és az időbonyolultság a hatványozás megvalósítási módjától függ, általában $O(1)$ vagy $O(\log n)$.
