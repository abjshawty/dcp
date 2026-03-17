from typing import List


def word_in_matrix(matrix: List[List[str]], word: str) -> bool:
    rows, cols, n = len(matrix), len(matrix[0]), len(word)
    for r in range(rows):
        for c in range(cols - n + 1):
            if all(matrix[r][c+i] == word[i] for i in range(n)):
                return True
    for c in range(cols):
        for r in range(rows - n + 1):
            if all(matrix[r+i][c] == word[i] for i in range(n)):
                return True
    return False


def main():
    print("Problem 63:")
    m = [['F','A','C','I'],['O','B','Q','P'],['A','N','O','B'],['M','A','S','S']]
    assert     word_in_matrix(m, "FOAM")
    assert     word_in_matrix(m, "MASS")
    assert not word_in_matrix(m, "NOPE")
    print("All Tests Passed")
