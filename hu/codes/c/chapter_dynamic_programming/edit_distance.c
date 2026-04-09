/**
 * File: edit_distance.c
 * Created Time: 2023-10-02
 * Author: Zuoxun (845242523@qq.com)
 */

#include "../utils/common.h"

/* Minimum érték meghatározása */
int myMin(int a, int b) {
    return a < b ? a : b;
}

/* Szerkesztési távolság: nyers erő keresés */
int editDistanceDFS(char *s, char *t, int i, int j) {
    // Ha s és t is üres, visszaad 0-t
    if (i == 0 && j == 0)
        return 0;
    // Ha s üres, visszaadja t hosszát
    if (i == 0)
        return j;
    // Ha t üres, visszaadja s hosszát
    if (j == 0)
        return i;
    // Ha a két karakter egyenlő, kihagyja mindkét karaktert
    if (s[i - 1] == t[j - 1])
        return editDistanceDFS(s, t, i - 1, j - 1);
    // Minimális szerkesztési lépések = beillesztés, törlés, csere minimális szerkesztési lépései + 1
    int insert = editDistanceDFS(s, t, i, j - 1);
    int del = editDistanceDFS(s, t, i - 1, j);
    int replace = editDistanceDFS(s, t, i - 1, j - 1);
    // Minimális szerkesztési lépések visszaadása
    return myMin(myMin(insert, del), replace) + 1;
}

/* Szerkesztési távolság: memorizálásos keresés */
int editDistanceDFSMem(char *s, char *t, int memCols, int **mem, int i, int j) {
    // Ha s és t is üres, visszaad 0-t
    if (i == 0 && j == 0)
        return 0;
    // Ha s üres, visszaadja t hosszát
    if (i == 0)
        return j;
    // Ha t üres, visszaadja s hosszát
    if (j == 0)
        return i;
    // Ha létezik rekord, közvetlenül visszaadja
    if (mem[i][j] != -1)
        return mem[i][j];
    // Ha a két karakter egyenlő, kihagyja mindkét karaktert
    if (s[i - 1] == t[j - 1])
        return editDistanceDFSMem(s, t, memCols, mem, i - 1, j - 1);
    // Minimális szerkesztési lépések = beillesztés, törlés, csere minimális szerkesztési lépései + 1
    int insert = editDistanceDFSMem(s, t, memCols, mem, i, j - 1);
    int del = editDistanceDFSMem(s, t, memCols, mem, i - 1, j);
    int replace = editDistanceDFSMem(s, t, memCols, mem, i - 1, j - 1);
    // A minimális szerkesztési lépések rögzítése és visszaadása
    mem[i][j] = myMin(myMin(insert, del), replace) + 1;
    return mem[i][j];
}

/* Szerkesztési távolság: dinamikus programozás */
int editDistanceDP(char *s, char *t, int n, int m) {
    int **dp = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = calloc(m + 1, sizeof(int));
    }
    // Állapotátmenet: első sor és első oszlop
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }
    // Állapotátmenet: többi sor és oszlop
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                // Ha a két karakter egyenlő, kihagyja mindkét karaktert
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Minimális szerkesztési lépések = beillesztés, törlés, csere minimális szerkesztési lépései + 1
                dp[i][j] = myMin(myMin(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    int res = dp[n][m];
    // Memória felszabadítása
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    return res;
}

/* Szerkesztési távolság: helytakarékos dinamikus programozás */
int editDistanceDPComp(char *s, char *t, int n, int m) {
    int *dp = calloc(m + 1, sizeof(int));
    // Állapotátmenet: első sor
    for (int j = 1; j <= m; j++) {
        dp[j] = j;
    }
    // Állapotátmenet: többi sor
    for (int i = 1; i <= n; i++) {
        // Állapotátmenet: első oszlop
        int leftup = dp[0]; // Ideiglenes tárolás dp[i-1, j-1] értékéhez
        dp[0] = i;
        // Állapotátmenet: többi oszlop
        for (int j = 1; j <= m; j++) {
            int temp = dp[j];
            if (s[i - 1] == t[j - 1]) {
                // Ha a két karakter egyenlő, kihagyja mindkét karaktert
                dp[j] = leftup;
            } else {
                // Minimális szerkesztési lépések = beillesztés, törlés, csere minimális szerkesztési lépései + 1
                dp[j] = myMin(myMin(dp[j - 1], dp[j]), leftup) + 1;
            }
            leftup = temp; // Frissítés a következő kör dp[i-1, j-1] értékéhez
        }
    }
    int res = dp[m];
    // Memória felszabadítása
    free(dp);
    return res;
}

/* Vezérlő kód */
int main() {
    char *s = "bag";
    char *t = "pack";
    int n = strlen(s), m = strlen(t);

    // Nyers erő keresés
    int res = editDistanceDFS(s, t, n, m);
    printf("Changing %s to %s requires a minimum of %d edits\n", s, t, res);

    // Memorizálásos keresés
    int **mem = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        mem[i] = malloc((m + 1) * sizeof(int));
        memset(mem[i], -1, (m + 1) * sizeof(int));
    }
    res = editDistanceDFSMem(s, t, m + 1, mem, n, m);
    printf("Changing %s to %s requires a minimum of %d edits\n", s, t, res);
    // Memória felszabadítása
    for (int i = 0; i <= n; i++) {
        free(mem[i]);
    }
    free(mem);

    // Dinamikus programozás
    res = editDistanceDP(s, t, n, m);
    printf("Changing %s to %s requires a minimum of %d edits\n", s, t, res);

    // Helytakarékos dinamikus programozás
    res = editDistanceDPComp(s, t, n, m);
    printf("Changing %s to %s requires a minimum of %d edits\n", s, t, res);

    return 0;
}
