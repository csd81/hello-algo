# Összefoglalás

### Főbb áttekintés

- Az oszd meg és uralkodj egy közönséges algoritmus-tervezési stratégia, amely két fázisból áll: felosztás (particionálás) és meghódítás (összefésülés), jellemzően rekurzión alapul.
- Az annak meghatározására szolgáló kritériumok, hogy egy probléma oszd meg és uralkodj probléma-e, a következők: lebontható-e a probléma, függetlenek-e a részproblémák, és összefésülhetők-e a részproblémák megoldásai.
- Az összefésüléses rendezés az oszd meg és uralkodj stratégia tipikus alkalmazása. Rekurzívan felezi a tömböt, amíg csak egyetlen elem marad, majd rétegről rétegre összefésüli azokat a rendezés elvégzéséhez.
- Az oszd meg és uralkodj stratégia bevezetése gyakran javítja az algoritmus hatékonyságát. Egyrészt az oszd meg és uralkodj stratégia csökkenti a műveletek számát; másrészt megkönnyíti a felosztás utáni párhuzamos optimalizálást a rendszer számára.
- Az oszd meg és uralkodj egyszerre képes számos algoritmikus problémát megoldani, és széles körben alkalmazzák adatstruktúrák és algoritmusok tervezésében, mindenütt jelen van.
- A nyers erő kereséssel összehasonlítva az adaptív keresés hatékonyabb. Az $O(\log n)$ időbonyolultságú keresési algoritmusok jellemzően az oszd meg és uralkodj stratégia alapján valósíthatók meg.
- A bináris keresés az oszd meg és uralkodj másik tipikus alkalmazása. Nem tartalmaz részproblémák megoldásainak összefésülési lépését. A bináris keresés rekurzív oszd meg és uralkodj segítségével megvalósítható.
- A bináris fa felépítésének problémájánál a fa felépítése (eredeti probléma) felosztható bal részfa és jobb részfa felépítésére (részproblémák), ami az előrendű és középrendű bejárások indexintervallumainak felosztásával érhető el.
- A Hanoi-problémánál az $n$ méretű probléma két $n-1$ méretű részproblémára és egy $1$ méretű részproblémára osztható. A három részprobléma sorban megoldva az eredeti problémát megoldjuk.
