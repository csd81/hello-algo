# Összefoglaló

### Kulcsfontosságú áttekintés

- Az algoritmusok mindenütt jelen vannak a mindennapi életben, és nem távoli, homályos tudás. Valójában már öntudatlanul sok algoritmust megtanultunk, és azokat az élet nagy és kis problémáinak megoldásához használjuk.
- A szótárban keresés elve megfelel a bináris keresés algoritmusának. A bináris keresés megtestesíti az oszd meg és uralkodj fontos algoritmikus elvét.
- A kártyák rendezésének folyamata nagyon hasonlít a beszúrásos rendezés algoritmusához. A beszúrásos rendezés kis adatkészletek rendezéséhez alkalmas.
- A visszajáró adásának lépései lényegében egy mohó algoritmus, amelynél minden lépésben a jelenlegi helyzet alapján a legjobb választást tesszük.
- Az algoritmus olyan utasítások vagy műveleti lépések halmaza, amely egy adott problémát véges idő alatt old meg, míg az adatszerkezet az a mód, ahogyan a számítógépek az adatokat szervezik és tárolják.
- Az adatszerkezetek és az algoritmusok szorosan összefüggenek. Az adatszerkezetek az algoritmusok alapjai, az algoritmusok pedig életet lehelnek az adatszerkezetekbe.
- Az adatszerkezeteket és algoritmusokat összehasonlíthatjuk építőkövek összerakásával. A kövek az adatokat képviselik, a kövek alakja és kapcsolódási módja az adatszerkezetet, a kövek összerakásának lépései pedig az algoritmusnak felelnek meg.

### Kérdések és válaszok

**K**: Programozóként soha nem használtam algoritmusokat a mindennapi munkám során felmerülő problémák megoldásához. A programozási nyelvek már tartalmazzák a szokásos algoritmusokat, amelyek közvetlenül használhatók. Ez azt jelenti, hogy a munkánkban felmerülő problémák még nem érték el azt a szintet, ahol algoritmusokra lenne szükség?

Ha a konkrét munkakészségeket a harcművészet „technikáihoz" hasonlítjuk, akkor az alapvető tantárgyak inkább az „belső erőre" hasonlítanak.

Úgy vélem, az algoritmusok (és más alapvető tantárgyak) tanulásának jelentősége nem az, hogy azokat a munkában a semmiből valósítsuk meg, hanem az, hogy a tanult ismeretek alapján profi reakciókra és ítéletekre legyünk képesek a problémák megoldásakor, ezáltal javítva a munka általános minőségét. Íme egy egyszerű példa. Minden programozási nyelvnek van beépített rendezési funkciója:

- Ha nem tanulmányoztuk az adatszerkezeteket és algoritmusokat, egyszerűen bármilyen adatot betápláltunk ebbe a rendezési funkcióba. Simán fut, jó teljesítménnyel, és látszólag nincs probléma.
- De ha tanulmányoztuk az algoritmusokat, tudni fogjuk, hogy a beépített rendezési funkció időbonyolultsága $O(n \log n)$. Ha azonban az adatok fix jegyű egészekből állnak (például diákazonosítókból), a hatékonyabb „radix sort" algoritmust használhatjuk, az időbonyolultságot $O(nk)$-ra csökkentve, ahol $k$ a jegyek száma. Nagy adatmennyiségnél a megtakarított futási idő jelentős értéket teremthet (csökkentett költségek, jobb élmény stb.).

A mérnöki területen sok probléma nehezen ér el optimális megoldásokat, és sok problémát csak „közelítőleg" oldanak meg. A probléma nehézségét egyrészt maga a probléma természete, másrészt a problémát vizsgáló személy tudásrezerve határozza meg. Minél teljesebb valakinek a tudása és minél több tapasztalata van, annál mélyebb lesz a probléma elemzése, és annál elegánsabban oldható meg a probléma.
