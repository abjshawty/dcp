type Pair = (f: (a: number, b: number) => number) => number;

// cons constructs a pair encoded as a closure. car and cdr extract the first
// and second elements by passing selector functions into the pair.
export function cons(a: number, b: number): Pair {
    return (f) => f(a, b);
}

// car returns the first element of a pair.
export function car(pair: Pair): number {
    return pair((a, _) => a);
}

// cdr returns the second element of a pair.
export function cdr(pair: Pair): number {
    return pair((_, b) => b);
}

export function problem5(): void {
    console.log("Problem 5:");
    if (car(cons(3, 4))  !== 3)  throw new Error("assertion failed");
    if (cdr(cons(3, 4))  !== 4)  throw new Error("assertion failed");
    if (car(cons(0, -1)) !== 0)  throw new Error("assertion failed");
    if (cdr(cons(0, -1)) !== -1) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
