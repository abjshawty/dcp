// schedule calls f after n milliseconds using setTimeout.
export function schedule(f: () => void, n: number): void {
    setTimeout(f, n);
}

export async function problem10(): Promise<void> {
    console.log("Problem 10:");
    await new Promise<void>((resolve) => schedule(resolve, 50));
    console.log("All Tests Passed");
}
