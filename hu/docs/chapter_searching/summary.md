# Összefoglalás

### Főbb pontok áttekintése

- A bináris keresés az adatok rendezettségére támaszkodik, és ciklusokon keresztül fokozatosan felezi a keresési intervallumot. Megköveteli, hogy a bemeneti adatok rendezettek legyenek, és csak tömbökre vagy tömbimplementáción alapuló adatszerkezetekre alkalmazható.
- A nyers erővel való keresés az adatszerkezet bejárásával keresi meg az adatokat. A lineáris keresés tömbökre és láncolt listákra alkalmazható, míg a szélességi elsőbbségű keresés és a mélységi elsőbbségű keresés gráfokra és fákra alkalmazható. Az ilyen algoritmusok jó általánosíthatósággal rendelkeznek és nem igényelnek adatelőkészítést, de viszonylag magas, $O(n)$ időbonyolultságuk van.
- A hash-alapú keresés, a fa-alapú keresés és a bináris keresés hatékony keresési módszerek, amelyek gyorsan megtalálják a célelemeket specifikus adatszerkezetekben. Az ilyen algoritmusok nagy hatékonyságúak, időbonyolultságuk $O(\log n)$ vagy akár $O(1)$, de általában extra adatszerkezeteket igényelnek.
- A gyakorlatban olyan tényezőket kell elemeznünk, mint az adatméret, a keresési teljesítménykövetelmények, valamint az adatlekérdezési és frissítési gyakoriság, hogy kiválasszuk a megfelelő keresési módszert.
- A lineáris keresés kis méretű vagy sűrűn frissített adatokra alkalmas; a bináris keresés nagy méretű, rendezett adatokra alkalmas; a hash-alapú keresés magas lekérdezési hatékonysági követelményeket és tartomány-lekérdezést nem igénylő adatokra alkalmas; a fa-alapú keresés nagy méretű dinamikus adatokra alkalmas, amelyeket sorrendben kell tartani és tartomány-lekérdezéseket kell támogatni.
- A lineáris keresés hash-alapú kereséssel való felváltása egy általánosan használt stratégia a futásidő optimalizálásához, amely az időbonyolultságot $O(n)$-ről $O(1)$-re csökkenti.
