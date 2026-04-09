/**
 * File: edit_distance.js
 * Created Time: 2023-08-23
 * Author: Gaofer Chou (gaofer-chou@qq.com)
 */

/* Szerkesztési távolság: Nyers erő keresés */
function editDistanceDFS(s, t, i, j) {
    // Ha s és t is üres, visszaadjuk 0-t
    if (i === 0 && j === 0) return 0;

    // Ha s üres, visszaadjuk t hosszát
    if (i === 0) return j;

    // Ha t üres, visszaadjuk s hosszát
    if (j === 0) return i;

    // Ha a két karakter egyenlő, mindkét karaktert kihagyjuk
    if (s.charAt(i - 1) === t.charAt(j - 1))
        return editDistanceDFS(s, t, i - 1, j - 1);

    // Minimális szerkesztési lépések = a beillesztés, törlés, csere minimális szerkesztési lépései + 1
    const insert = editDistanceDFS(s, t, i, j - 1);
    const del = editDistanceDFS(s, t, i - 1, j);
    const replace = editDistanceDFS(s, t, i - 1, j - 1);
    // Visszaadjuk a minimális szerkesztési lépéseket
    return Math.min(insert, del, replace) + 1;
}

/* Szerkesztési távolság: Memoizált keresés */
function editDistanceDFSMem(s, t, mem, i, j) {
    // Ha s és t is üres, visszaadjuk 0-t
    if (i === 0 && j === 0) return 0;

    // Ha s üres, visszaadjuk t hosszát
    if (i === 0) return j;

    // Ha t üres, visszaadjuk s hosszát
    if (j === 0) return i;

    // Ha van bejegyzés, közvetlenül visszaadjuk
    if (mem[i][j] !== -1) return mem[i][j];

    // Ha a két karakter egyenlő, mindkét karaktert kihagyjuk
    if (s.charAt(i - 1) === t.charAt(j - 1))
        return editDistanceDFSMem(s, t, mem, i - 1, j - 1);

    // Minimális szerkesztési lépések = a beillesztés, törlés, csere minimális szerkesztési lépései + 1
    const insert = editDistanceDFSMem(s, t, mem, i, j - 1);
    const del = editDistanceDFSMem(s, t, mem, i - 1, j);
    const replace = editDistanceDFSMem(s, t, mem, i - 1, j - 1);
    // Rögzítjük és visszaadjuk a minimális szerkesztési lépéseket
    mem[i][j] = Math.min(insert, del, replace) + 1;
    return mem[i][j];
}

/* Szerkesztési távolság: Dinamikus programozás */
function editDistanceDP(s, t) {
    const n = s.length,
        m = t.length;
    const dp = Array.from({ length: n + 1 }, () => new Array(m + 1).fill(0));
    // Állapotátmenet: első sor és első oszlop
    for (let i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for (let j = 1; j <= m; j++) {
        dp[0][j] = j;
    }
    // Állapotátmenet: többi sor és oszlop
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= m; j++) {
            if (s.charAt(i - 1) === t.charAt(j - 1)) {
                // Ha a két karakter egyenlő, mindkét karaktert kihagyjuk
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Minimális szerkesztési lépések = a beillesztés, törlés, csere minimális szerkesztési lépései + 1
                dp[i][j] =
                    Math.min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
            }
        }
    }
    return dp[n][m];
}

/* Szerkesztési távolság: Helytakarékos dinamikus programozás */
function editDistanceDPComp(s, t) {
    const n = s.length,
        m = t.length;
    const dp = new Array(m + 1).fill(0);
    // Állapotátmenet: első sor
    for (let j = 1; j <= m; j++) {
        dp[j] = j;
    }
    // Állapotátmenet: többi sor
    for (let i = 1; i <= n; i++) {
        // Állapotátmenet: első oszlop
        let leftup = dp[0]; // Ideiglenesen tároljuk dp[i-1, j-1]-et
        dp[0] = i;
        // Állapotátmenet: többi oszlop
        for (let j = 1; j <= m; j++) {
            const temp = dp[j];
            if (s.charAt(i - 1) === t.charAt(j - 1)) {
                // Ha a két karakter egyenlő, mindkét karaktert kihagyjuk
                dp[j] = leftup;
            } else {
                // Minimális szerkesztési lépések = a beillesztés, törlés, csere minimális szerkesztési lépései + 1
                dp[j] = Math.min(dp[j - 1], dp[j], leftup) + 1;
            }
            leftup = temp; // Frissítés a következő kör dp[i-1, j-1]-éhez
        }
    }
    return dp[m];
}

const s = 'bag';
const t = 'pack';
const n = s.length,
    m = t.length;

// Nyers erő keresés
let res = editDistanceDFS(s, t, n, m);
console.log(`Changing ${s} to ${t} requires minimum ${res} edits`);

// Memoizált keresés
const mem = Array.from(new Array(n + 1), () => new Array(m + 1).fill(-1));
res = editDistanceDFSMem(s, t, mem, n, m);
console.log(`Changing ${s} to ${t} requires minimum ${res} edits`);

// Dinamikus programozás
res = editDistanceDP(s, t);
console.log(`Changing ${s} to ${t} requires minimum ${res} edits`);

// Helytakarékos dinamikus programozás
res = editDistanceDPComp(s, t);
console.log(`Changing ${s} to ${t} requires minimum ${res} edits`);
