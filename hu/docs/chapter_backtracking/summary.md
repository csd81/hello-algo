# Összefoglalás

### Kulcsfontosságú áttekintés

- A visszalépéses keresési algoritmus alapvetően egy kimerítő keresési módszer. A megoldástér mélységi bejárásával olyan megoldásokat keres, amelyek megfelelnek a meghatározott feltételeknek. A keresési folyamat során, amikor egy feltételeket kielégítő megoldást talál, rögzíti azt. A keresés az összes megoldás megtalálása után vagy a bejárás befejezésekor fejeződik be.
- A visszalépéses keresési algoritmus keresési folyamata két részből áll: próbálkozásból és visszalépésből. Mélységi kereséssel különböző választásokat próbál ki. Ha olyan helyzetbe kerül, amely megsérti a feltételeket, visszavonja az előző választást, visszatér az előző állapotba, és folytatja más lehetőségek feltárását. A próbálkozás és visszalépés egymással ellentétes irányú műveletek.
- A visszalépéses keresési feladatok általában több feltételt tartalmaznak, amelyek metszési műveletek megvalósítására használhatók. A metszés korán lezárhatja a szükségtelen keresési ágakat, jelentősen javítva a keresési hatékonyságot.
- A visszalépéses keresési algoritmus elsősorban keresési feladatok és feltétel-kielégítési feladatok megoldására használatos. Bár a kombinatorikus optimalizálási feladatok visszalépéses kereséssel megoldhatók, gyakran hatékonyabb vagy jobb teljesítményű megoldások állnak rendelkezésre.
- A permutációs feladat célja a megadott halmaz elemei összes lehetséges permutációjának megkeresése. Egy tömböt használunk annak nyomon követéséhez, hogy minden elem ki lett-e választva, ezáltal metszve azokat a keresési ágakat, amelyek ugyanazt az elemet többször próbálják kiválasztani, biztosítva, hogy minden elemet pontosan egyszer válasszanak ki.
- A permutációs feladatban, ha a halmaz ismétlődő elemeket tartalmaz, a végeredmény ismétlődő permutációkat fog tartalmazni. Olyan feltételt kell bevezetni, amely biztosítja, hogy az egyenlő elemek fordulónként csak egyszer választhatók ki, ami általában egy hash-halmaz segítségével valósítható meg.
- A részösszeg feladat célja a megadott halmaz összes olyan részhalmazának megkeresése, amelyek összege megegyezik egy célértékkel. Mivel a halmaz rendezetlen, de a keresési folyamat az eredményeket minden sorrendben adja ki, ismétlődő részhalmazok keletkeznek. Az adatokat visszalépés előtt rendezzük, és egy változóval jelezzük az egyes fordulók bejárásának kiindulópontját, ezáltal metszve az ismétlődő részhalmazokat generáló keresési ágakat.
- A részösszeg feladatnál a tömbben lévő egyenlő elemek ismétlődő halmazokat produkálnak. Felhasználjuk azt az előfeltételt, hogy a tömb rendezett, és ellenőrizzük, hogy a szomszédos elemek egyenlők-e, a metszés megvalósítása érdekében, biztosítva, hogy az egyenlő elemek fordulónként csak egyszer választhatók ki.
- Az $n$ királynő feladat célja $n$ királynő elhelyezése egy $n \times n$-es sakktáblán úgy, hogy egy sem tudja megtámadni a másikat. A feladat feltételei közé tartoznak a sorfeltételek, az oszlopfeltételek, valamint a fő- és mellékátlós feltételek. A sorfeltételek teljesítéséhez soronkénti elhelyezési stratégiát fogadunk el, biztosítva, hogy minden sorban pontosan egy királynőt helyezünk el.
- Az oszlopfeltételek és az átlóbeliség-feltételek kezelése hasonló. Az oszlopfeltételekhez egy tömböt használunk annak rögzítéséhez, hogy minden oszlopban van-e királynő, ezáltal jelezve, hogy egy kiválasztott mező érvényes-e. Az átlóbeliség-feltételekhez két tömböt használunk a főátlókon vagy mellékátlókon lévő királynők jelenlétének rögzítésére. A kihívás az ugyanazon a fő- (mellék-) átlón lévő mezőket jellemző sor-oszlop indexminta megtalálásában rejlik.

### Kérdések és válaszok

**K**: Hogyan értelmezzük a visszalépéses keresés és a rekurzió kapcsolatát?

Összességében a visszalépéses keresés egy „algoritmikus stratégia", míg a rekurzió inkább egy „eszköz".

- A visszalépéses keresési algoritmust általában rekurzió alapján valósítják meg. A visszalépéses keresés azonban a rekurzió egyik alkalmazási területe, és a rekurzió alkalmazását jelenti a keresési feladatokban.
- A rekurzió struktúrája megtestesíti a „részfeladat felbontás" problémamegoldási paradigmát, amelyet általánosan használnak az oszd meg és uralkodj, visszalépéses keresés és dinamikus programozás (memoizált rekurzió) feladatok megoldásában.
