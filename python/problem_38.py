def n_queens(n: int) -> int:
    cols   = set()
    diag1  = set()
    diag2  = set()
    count  = [0]

    def place(row):
        if row == n:
            count[0] += 1
            return
        for col in range(n):
            if col in cols or (row - col) in diag1 or (row + col) in diag2:
                continue
            cols.add(col); diag1.add(row - col); diag2.add(row + col)
            place(row + 1)
            cols.remove(col); diag1.remove(row - col); diag2.remove(row + col)

    place(0)
    return count[0]


def main():
    print("Problem 38:")
    assert n_queens(1) == 1
    assert n_queens(4) == 2
    assert n_queens(8) == 92
    print("All Tests Passed")
