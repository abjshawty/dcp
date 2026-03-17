// estimatePi estimates π using Monte Carlo simulation.
// Random points thrown at a unit square; those inside the inscribed
// quarter-circle (x²+y² ≤ 1) approximate π/4.
export function estimatePi(samples: number, seed = 42): number {
    // simple seeded LCG for reproducibility
    let s = seed;
    const rand = () => { s = (s * 1664525 + 1013904223) & 0xffffffff; return (s >>> 0) / 0xffffffff; };
    let inside = 0;
    for (let i = 0; i < samples; i++) {
        const x = rand(), y = rand();
        if (x * x + y * y <= 1) inside++;
    }
    return 4 * inside / samples;
}

export function problem14(): void {
    console.log("Problem 14:");
    const pi = estimatePi(1_000_000);
    if (Math.abs(pi - Math.PI) > 0.01)
        throw new Error(`assertion failed: got ${pi}`);
    console.log("All Tests Passed");
}
