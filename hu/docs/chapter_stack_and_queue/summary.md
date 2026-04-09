# Összefoglalás

### Főbb pontok áttekintése

- A verem egy adatszerkezet, amely a LIFO elvét követi, és tömbökkel vagy láncolt listákkal valósítható meg.
- Időhatékonyság szempontjából a verem tömbös megvalósítása magasabb átlagos hatékonyságot mutat, de bővítés során az egyszeri push művelet időbonyolultsága $O(n)$-re romlik. Ezzel szemben a verem láncolt listás megvalósítása stabilabb hatékonyságteljesítményt nyújt.
- Területhatékonyság szempontjából a verem tömbös megvalósítása bizonyos mértékű területpazarláshoz vezethet. Megjegyzendő azonban, hogy a láncolt lista csomópontjai által elfoglalt memóriaterület nagyobb, mint a tömbelemek esetén.
- A sor egy adatszerkezet, amely a FIFO elvét követi, és szintén megvalósítható tömbökkel vagy láncolt listákkal. A sorok időhatékonsági és területhatékonsági összehasonlításainak következtetései hasonlóak a fent említett veremekéihez.
- A kétirányú sor egy nagyobb rugalmasságú sor, amely lehetővé teszi elemek hozzáadását és eltávolítását mindkét végén.

### Kérdések és válaszok

**K**: A böngésző előre és visszafelé navigálási funkcionalitása kétszeresen láncolt listával van megvalósítva?

A böngésző előre és visszafelé navigálási funkcionalitása lényegében egy "verem" megnyilvánulása. Amikor a felhasználó új oldalt látogat meg, az oldal a verem tetejére kerül; amikor a felhasználó a vissza gombra kattint, az oldal a verem tetejéről pop-olódik. Kétirányú sor használatával kényelmesen megvalósíthatók egyes kiegészítő műveletek, ahogy azt a "Kétirányú sor" szakasz megemlíti.

**K**: A veremből való pop után fel kell szabadítanunk a pop-olt csomópont memóriáját?

Ha a pop-olt csomópontra később még szükség lesz, akkor a memóriát nem kell felszabadítani. Ha ezután nem lesz rá szükség, az olyan nyelvek, mint a Java és a Python, automatikus szemétgyűjtéssel rendelkeznek, ezért nem szükséges a memória manuális felszabadítása; C-ben és C++-ban azonban szükséges a manuális memória-felszabadítás.

**K**: Úgy tűnik, hogy a kétirányú sor két összekötött verem. Mi a célja?

A kétirányú sor olyan, mint egy verem és egy sor kombinációja, vagy két összekötött verem. Mindkét verem és sor logikáját mutatja, ezért képes megvalósítani veremek és sorok összes alkalmazását, és rugalmasabb.

**K**: Hogyan valósítható meg pontosan a visszavonás és az újra elvégzés?

Két vermet kell használni: az `A` vermet a visszavonáshoz és a `B` vermet az újra elvégzéshez.

1. Minden alkalommal, amikor a felhasználó műveletet hajt végre, push-olja ezt a műveletet az `A` verembe, és törölje a `B` vermet.
2. Amikor a felhasználó "visszavon", pop-olja a legutóbbi műveletet az `A` veremből, és push-olja a `B` verembe.
3. Amikor a felhasználó "újra elvégez", pop-olja a legutóbbi műveletet a `B` veremből, és push-olja az `A` verembe.
