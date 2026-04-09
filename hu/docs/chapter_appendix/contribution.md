# Közös hozzájárulás

Korlátozott kapacitásunk miatt ebben a könyvben elkerülhetetlen hiányosságok és hibák lehetnek. Megértését értékeljük, és hálásak vagyunk, hogy segít ezeket kijavítani. Ha gépelési hibákat, megszakadt hivatkozásokat, hiányzó tartalmat, kétértelmű megfogalmazást, nem egyértelmű magyarázatokat vagy szerkezeti problémákat fedez fel, kérjük, segítsen nekünk a javításokban, hogy magasabb minőségű tanulási forrásokat nyújthasunk az olvasóknak.

Az összes [közreműködő](https://github.com/krahets/hello-algo/graphs/contributors) GitHub-azonosítója megjelenik a könyvtár főoldalán, a webes verzióban és a PDF verzióban, elismerve önzetlen hozzájárulásukat a nyílt forráskódú közösséghez.

!!! success "A nyílt forráskód varázsa"

    Egy nyomtatott könyv két kiadása között az intervallum gyakran elég hosszú, ami a tartalomfrissítéseket nagyon kényelmetlenné teszi.

    Ebben a nyílt forráskódú könyvben a tartalomfrissítések ideje napokra vagy akár órákra rövidült.

### Kisebb tartalommódosítások

Az alábbi ábrán látható módon minden oldal jobb felső sarkában van egy „szerkesztési ikon". A következő lépések szerint módosíthatja a szöveget vagy a kódot.

1. Kattintson a „szerkesztési ikonra". Ha egy üzenet jelenik meg, amelyben a „Tárház elágaztatása" műveletet kéri, hagyja jóvá a műveletet.
2. Módosítsa a Markdown forrásfájl tartalmát, ellenőrizze a tartalom helyességét, és tartsa fenn a következetes formázást lehetőség szerint.
3. Töltse ki a változtatások leírását az oldal alján, majd kattintson a „Fájlváltoztatás javaslása" gombra. Miután az oldal átváltott, kattintson a „Pull request létrehozása" gombra a pull request benyújtásához.

![Oldalszerkesztési gomb](contribution.assets/edit_markdown.png)

A képek közvetlenül nem módosíthatók. Kérjük, írja le a problémát egy új [Issue](https://github.com/krahets/hello-algo/issues) létrehozásával vagy megjegyzés hagyásával. Mi azonnal újrarajzoljuk és kicseréljük a képeket.

### Tartalom létrehozása

Ha érdekli, hogy hozzájáruljon ehhez a nyílt forráskódú projekthez, beleértve a kód fordítását más programozási nyelvekre vagy a cikk tartalmának bővítését, kövesse az alábbi Pull Request munkafolyamatot.

1. Jelentkezzen be a GitHubra, és elágaztassa (Fork) a könyv [kódtárát](https://github.com/krahets/hello-algo) a személyes fiókjába.
2. Lépjen be az elágaztatott tárház weblapjára, és a `git clone` paranccsal klónozza a tárházt a helyi gépére.
3. Hozzon létre tartalmat helyben, és végezzen átfogó teszteket a kód helyességének ellenőrzéséhez.
4. Commitolja a helyi változtatásokat, és tolja fel azokat a távoli tárházba.
5. Frissítse a tárház weblapját, és kattintson a „Pull request létrehozása" gombra a pull request benyújtásához.

### Docker telepítés

A `hello-algo` gyökérkönyvtárából futtassa a következő Docker-szkriptet a projekt eléréséhez a `http://localhost:8000` címen:

```shell
docker-compose up -d
```

A következő paranccsal távolíthatja el a telepítést:

```shell
docker-compose down
```
