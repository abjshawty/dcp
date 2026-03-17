type Cell = `${number},${number}`;

function cellKey(r: number, c: number): Cell { return `${r},${c}`; }
function parseCell(k: Cell): [number, number] {
    const [r, c] = k.split(',').map(Number); return [r, c];
}

export function gameOfLifeStep(alive: Set<Cell>): Set<Cell> {
    const counts = new Map<Cell, number>();
    for (const k of alive) {
        const [r, c] = parseCell(k);
        for (let dr = -1; dr <= 1; dr++)
            for (let dc = -1; dc <= 1; dc++) {
                if (dr === 0 && dc === 0) continue;
                const nb = cellKey(r + dr, c + dc);
                counts.set(nb, (counts.get(nb) ?? 0) + 1);
            }
    }
    const next = new Set<Cell>();
    for (const [p, cnt] of counts) {
        if (alive.has(p) && (cnt === 2 || cnt === 3)) next.add(p);
        if (!alive.has(p) && cnt === 3)               next.add(p);
    }
    return next;
}

export function problem39(): void {
    console.log("Problem 39:");
    const blinker = new Set<Cell>([cellKey(0,0), cellKey(0,1), cellKey(0,2)]);
    const s1 = gameOfLifeStep(blinker);
    if (s1.size !== 3) throw new Error("assertion failed");
    const s2 = gameOfLifeStep(s1);
    if (s2.size !== 3) throw new Error("assertion failed");
    if (!s2.has(cellKey(0,0)) || !s2.has(cellKey(0,1)) || !s2.has(cellKey(0,2)))
        throw new Error("assertion failed");
    console.log("All Tests Passed");
}
