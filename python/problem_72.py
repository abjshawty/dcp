from typing import List, Tuple, Optional
from collections import deque


def largest_value_path(labels: str, edges: List[Tuple[int,int]]) -> Optional[int]:
    n = len(labels)
    adj = [[] for _ in range(n)]
    indegree = [0] * n
    for u, v in edges:
        if u == v:
            return None
        adj[u].append(v)
        indegree[v] += 1

    dp = [[0] * 26 for _ in range(n)]
    queue = deque(i for i in range(n) if indegree[i] == 0)
    visited = 0
    best = 0

    while queue:
        node = queue.popleft()
        visited += 1
        dp[node][ord(labels[node]) - ord('A')] += 1
        best = max(best, max(dp[node]))
        for nb in adj[node]:
            for c in range(26):
                dp[nb][c] = max(dp[nb][c], dp[node][c])
            indegree[nb] -= 1
            if indegree[nb] == 0:
                queue.append(nb)

    return best if visited == n else None


def main():
    print("Problem 72:")
    assert largest_value_path("ABACA", [(0,1),(0,2),(2,3),(3,4)]) == 3
    assert largest_value_path("A", [(0,0)]) is None
    print("All Tests Passed")
