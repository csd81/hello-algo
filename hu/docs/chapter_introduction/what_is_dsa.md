# Mi az algoritmus?

## Az algoritmus definíciója

Az <u>algoritmus</u> egy adott probléma megoldására szolgáló utasítások vagy műveleti lépések halmaza, amely véges idő alatt elvégezhető. A következő jellemzőkkel rendelkezik.

- A probléma jól meghatározott, világos bemeneti és kimeneti definíciókkal.
- Megvalósítható, és véges számú lépésben, időben és memóriaterületben elvégezhető.
- Minden lépésnek egyértelű jelentése van, és azonos bemenet és működési feltételek mellett a kimenet mindig ugyanaz.

## Az adatszerkezet definíciója

Az <u>adatszerkezet</u> az adatok szervezésének és tárolásának módja, amely lefedi az adatok tartalmát, az adatok közötti kapcsolatokat és az adatműveletek módszereit. A következő tervezési célokkal rendelkezik.

- Foglaljon el a lehető legkevesebb tárhelyet a számítógép memóriájának megtakarítása érdekében.
- Az adatműveletek legyenek a lehető leggyorsabbak, beleértve az adatok hozzáférését, hozzáadását, törlését, frissítését stb.
- Nyújtson tömör adatábrázolást és logikai információkat, hogy az algoritmusok hatékonyan futhassanak.

**Az adatszerkezet tervezése kompromisszumokkal teli folyamat**. Ha az egyik területen javítást szeretnénk elérni, gyakran a másik területen kell engedményeket tennünk. Íme két példa.

- A tömbökkel összehasonlítva a láncolt listáknál kényelmesebb az adatok hozzáadása és törlése, de feláldozzák az adathozzáférés sebességét.
- A láncolt listákhoz képest a gráfok gazdagabb logikai információkat nyújtanak, de nagyobb memóriaterületet igényelnek.

## Az adatszerkezetek és algoritmusok kapcsolata

Ahogy az alábbi ábra mutatja, az adatszerkezetek és az algoritmusok szorosan összefüggnek és szorosan kapcsolódnak egymáshoz, amit konkrétan a következő három szempontból lehet megragadni.

- Az adatszerkezetek az algoritmusok alapjai. Az adatszerkezetek strukturált adattárolást és adatkezelési módszereket biztosítanak az algoritmusok számára.
- Az algoritmusok életet lehelnek az adatszerkezetekbe. Az adatszerkezetek önmagukban csak adatinformációkat tárolnak; az algoritmusokkal kombinálva konkrét problémák megoldhatók.
- Az algoritmusok általában különböző adatszerkezetek alapján valósíthatók meg, de a végrehajtás hatékonysága nagymértékben eltérhet. A megfelelő adatszerkezet kiválasztása kulcsfontosságú.

![Az adatszerkezetek és az algoritmusok kapcsolata](what_is_dsa.assets/relationship_between_data_structure_and_algorithm.png)

Az adatszerkezetek és az algoritmusok olyanok, mint az építőkövek összerakása, ahogy az alábbi ábra mutatja. Egy csomag építőkő sok részből áll, és részletes összeszerelési utasításokat is tartalmaz. Az utasítások lépésről lépésre való követésével egy kifinomult építőkő-modellt rakhatunk össze.

![Építőkövek összerakása](what_is_dsa.assets/assembling_blocks.png)

A két fogalom közötti részletes megfeleltetést az alábbi táblázat mutatja.

<p align="center"> Táblázat <id> &nbsp; Az adatszerkezetek és az algoritmusok összehasonlítása az építőkövek összerakásával </p>

| Adatszerkezetek és algoritmusok | Építőkövek összerakása                                            |
| ------------------------------- | ------------------------------------------------------------------ |
| Bemeneti adatok                 | Összeszerelemlen építőkövek                                        |
| Adatszerkezet                   | Építőkövek szervezési formája, beleértve az alakot, méretet, kapcsolási módszert stb. |
| Algoritmus                      | Műveleti lépések sorozata a kövek célformába való összerakásához  |
| Kimeneti adatok                 | Építőkő-modell                                                     |

Érdemes megjegyezni, hogy az adatszerkezetek és az algoritmusok függetlenek a programozási nyelvektől. Emiatt ez a könyv képes több programozási nyelven alapuló megvalósításokat nyújtani.

!!! tip "Hagyományos rövidítés"

    A tényleges megbeszélésekben általában az „adatszerkezetek és algoritmusok" kifejezést „algoritmusokra" rövidítjük. Például a jól ismert LeetCode algoritmus-feladatok valójában mind az adatszerkezetek, mind az algoritmusok ismeretét vizsgálják.
