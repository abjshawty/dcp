export function shuffle(deck: number[]): void {
    for (let i = deck.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [deck[i], deck[j]] = [deck[j], deck[i]];
    }
}

export function problem51(): void {
    console.log("Problem 51:");
    const deck = Array.from({length: 52}, (_, i) => i);
    shuffle(deck);
    if (JSON.stringify([...deck].sort((a,b)=>a-b)) !== JSON.stringify(Array.from({length:52},(_,i)=>i)))
        throw new Error("assertion failed");
    console.log("All Tests Passed");
}
