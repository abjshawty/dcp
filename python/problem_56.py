from typing import List


def graph_colorable(adj: List[List[int]], k: int) -> bool:
    n = len(adj)
    colors = [0] * n

    def bt(node: int) -> bool:
        if node == n:
            return True
        for c in range(1, k + 1):
            if all(adj[node][nb] == 0 or colors[nb] != c for nb in range(n)):
                colors[node] = c
                if bt(node + 1):
                    return True
                colors[node] = 0
        return False

    return bt(0)


def main():
    print("Problem 56:")
    triangle = [[0,1,1],[1,0,1],[1,1,0]]
    assert     graph_colorable(triangle, 3)
    assert not graph_colorable(triangle, 2)
    print("All Tests Passed")
