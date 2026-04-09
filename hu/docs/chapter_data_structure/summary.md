# Összefoglalás

### Kulcsfogalmak áttekintése

- Az adatszerkezetek két nézőpontból osztályozhatók: logikai szerkezet és fizikai szerkezet. A logikai szerkezet az adatelemek közötti logikai kapcsolatokat írja le, míg a fizikai szerkezet azt írja le, hogyan tárolódnak az adatok a számítógép memóriájában.
- A közismert logikai szerkezetek közé tartoznak a lineáris, fa- és hálózati szerkezetek. Az adatszerkezeteket általában logikai szerkezetük alapján soroljuk lineárisra (tömbök, láncolt listák, veremek, sorok) és nemlineárisra (fák, gráfok, kupacok). A hasítótáblák megvalósítása lineáris és nemlineáris adatszerkezeteket egyaránt tartalmazhat.
- Amikor egy program fut, az adatok a számítógép memóriájában tárolódnak. Minden memóriahely rendelkezik egy megfelelő memóriacímmel, és a program ezeken a memóriacímeken keresztül fér hozzá az adatokhoz.
- A fizikai szerkezetek főként összefüggő tárterület-tárolásra (tömbök) és szétszórt tárterület-tárolásra (láncolt listák) oszthatók. Minden adatszerkezet tömbök, láncolt listák alapján vagy mindkettő kombinációján valósul meg.
- A számítógépek alapvető adattípusai közé tartoznak az egész számok `byte`, `short`, `int`, `long`, lebegőpontos számok `float`, `double`, karakterek `char` és logikai értékek `bool`. Értékkészletük a foglalt hely méretétől és az ábrázolási módszertől függ.
- Az előjel-abszolút érték, az egyes komplemens és a kettes komplemens a számítógépekben lévő számok kódolásának három módszere, és kölcsönösen átválthatók egymásba. Az előjel-abszolút érték legjelentősebb bitje az előjelbit, a többi bit a szám értékét adja meg.
- Az egész számok a számítógépekben kettes komplemens formában tárolódnak. Kettes komplemens ábrázolásban a számítógépek egységesen tudják kezelni a pozitív és negatív számok összeadását, anélkül hogy speciális hardveres áramköröket kellene tervezni a kivonáshoz, és a pozitív és negatív nulla kétértelműsége sem jelent problémát.
- A lebegőpontos számok kódolása 1 előjelbitből, 8 kitevő bitből és 23 törtbitből áll. A kitevő bitek miatt a lebegőpontos számok tartománya sokkal nagyobb, mint az egész számoké, a pontosság feláldozásának árán.
- Az ASCII a legkorábbi angol karakterkészlet, 1 bájt hosszúságú, összesen 127 karaktert tartalmaz. A GBK egy közismert kínai karakterkészlet, több mint 20 000 kínai karaktert tartalmaz. A Unicode egy átfogó karakterkészlet-szabvány biztosítására törekszik, amely a világ összes nyelvének karakterét összegyűjti, megoldva ezzel a különböző karakterkódolási módszerek által okozott torz szöveg problémáját.
- Az UTF-8 a legnépszerűbb Unicode kódolási módszer, kiváló általánossággal. Ez egy változó hosszúságú kódolási módszer, jó skálázhatósággal, hatékonyan javítja a tárhelyek hatékonyságát. Az UTF-16 és az UTF-32 rögzített hosszúságú kódolási módszerek. Kínai karakterek kódolásakor az UTF-16 kevesebb helyet foglal el, mint az UTF-8. Programozási nyelvek, mint a Java és a C#, alapértelmezés szerint UTF-16 kódolást alkalmaznak.

### Kérdések és válaszok

**K**: Miért tartalmaznak a hasítótáblák lineáris és nemlineáris adatszerkezeteket egyaránt?

A hasítótábla alapszerkezete egy tömb. Az ütközések feloldásához „láncolást" alkalmazhatunk (amelyet a későbbi „Hasításütközés" fejezet tárgyal): a tömb minden vedrére egy láncolt lista mutat, amely bizonyos listaméret-küszöb túllépésekor fává (általában vörös-fekete fává) konvertálható.

Tárolási szempontból a hasítótábla alapszerkezete egy tömb, ahol minden vödörhelyen szerepelhet egy érték, egy láncolt lista vagy egy fa. Ezért a hasítótáblák tartalmazhatnak lineáris adatszerkezeteket (tömbök, láncolt listák) és nemlineáris adatszerkezeteket (fák) egyaránt.

**K**: A `char` típus hossza 1 bájt?

A `char` típus hossza a programozási nyelv által alkalmazott kódolási módszertől függ. Például a Java, JavaScript, TypeScript és C# mind UTF-16 kódolást alkalmaz (Unicode kódpontok tárolásához), így a `char` típus hossza 2 bájt.

**K**: Félreértelmezés-e a tömbön alapuló adatszerkezetekre „statikus adatszerkezetként" hivatkozni? A veremek is tudnak „dinamikus" műveleteket végezni, mint a push és pop.

A veremek valóban képesek dinamikus adatműveletek végrehajtására, de maga az adatszerkezet továbbra is „statikus" (rögzített hosszúságú). Bár a tömbalapú adatszerkezetek dinamikusan adhatnak hozzá vagy vehetnek el elemeket, kapacitásuk rögzített. Ha az adatmennyiség meghaladja az előre lefoglalt méretet, egy új, nagyobb tömböt kell létrehozni, és a régi tömb tartalmát az újba kell másolni.

**K**: Verem (sor) felépítésekor a mérete nincs megadva. Miért „statikus adatszerkezetek" ezek?

A magas szintű programozási nyelvekben nincs szükség a verem (sor) kezdeti kapacitásának manuális megadására; ezt a munka automatikusan elvégzi az osztály belsejében. Például a Java `ArrayList` kezdeti kapacitása általában 10. Emellett a bővítési műveletek is automatikusan megvalósulnak. Részletekért lásd a következő „Lista" fejezetet.

**K**: Az előjel-abszolút értékről kettes komplemensre való átváltás módszere az „először negálj, majd adj hozzá 1-et". Tehát a kettes komplemensről előjel-abszolút értékre való visszaváltás az inverz művelet lenne: „először vonj le 1-et, majd negálj". Miért hajtható végre ez az átváltás is az „először negálj, majd adj hozzá 1-et" módszerrel?

Ez azért van, mert az előjel-abszolút érték és a kettes komplemens közötti kölcsönös átváltás valójában a „komplemens" kiszámításának folyamata. Először definiáljuk a komplementset: feltételezve, hogy $a + b = c$, azt mondjuk, hogy $a$ a $b$ komplementse $c$-hez képest, és fordítva, $b$ az $a$ komplementse $c$-hez képest.

Adott egy $n = 4$ bites bináris szám: $0010$. Ha ezt a számot előjel-abszolút értékként kezeljük (az előjelbit figyelmen kívül hagyásával), kettes komplemense az „először negálj, majd adj hozzá 1-et" módszerrel kapható meg:

$$
0010 \rightarrow 1101 \rightarrow 1110
$$

Megfigyeljük, hogy az előjel-abszolút érték és a kettes komplemens összege $0010 + 1110 = 10000$, ami azt jelenti, hogy a kettes komplemens $1110$ az előjel-abszolút érték $0010$ „komplementse" $10000$-hez képest. **Ez azt jelenti, hogy a fenti „először negálj, majd adj hozzá 1-et" valójában a $10000$-hez vett komplemens kiszámításának folyamata**.

Mi tehát a kettes komplemens $1110$ komplementse $10000$-hez képest? Ezt szintén az „először negálj, majd adj hozzá 1-et" módszerrel kaphatjuk meg:

$$
1110 \rightarrow 0001 \rightarrow 0010
$$

Más szóval, az előjel-abszolút érték és a kettes komplemens kölcsönösen egymás „komplementsei" $10000$-hez képest, ezért az „előjel-abszolút értékről kettes komplemensre" és a „kettes komplemensről előjel-abszolút értékre" való átváltás ugyanazzal a művelettel (először negálj, majd adj hozzá 1-et) valósítható meg.

Természetesen az inverz műveletet is alkalmazhatjuk a kettes komplemens $1110$ előjel-abszolút értékének meghatározásához, vagyis az „először vonj le 1-et, majd negálj" módszerrel:

$$
1110 \rightarrow 1101 \rightarrow 0010
$$

Összefoglalva, mind az „először negálj, majd adj hozzá 1-et", mind az „először vonj le 1-et, majd negálj" a $10000$-hez vett komplementst számítja ki, és ezek egyenértékűek.

Lényegében a „negálás" művelet valójában az $1111$-hez vett komplementst számolja ki (mivel az `előjel-abszolút érték + egyes komplemens = 1111` mindig igaz); és az egyes komplemenshez 1-et adva kapjuk a kettes komplementst, ami a $10000$-hez vett komplemens.

A fenti példa $n = 4$ értéket használ, és tetszőleges bites bináris számokra általánosítható.
