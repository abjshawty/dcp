from typing import List, Tuple, Optional
from collections import defaultdict


def find_itinerary(flights: List[Tuple[str, str]], start: str) -> Optional[List[str]]:
    graph = defaultdict(list)
    for src, dst in flights:
        graph[src].append(dst)
    for k in graph:
        graph[k].sort()

    result = []

    def dfs(airport: str):
        while graph[airport]:
            nxt = graph[airport].pop(0)
            dfs(nxt)
        result.append(airport)

    dfs(start)
    result.reverse()
    if len(result) != len(flights) + 1:
        return None
    return result


def main():
    print("Problem 41:")
    f1 = [('SFO','HKO'),('YYZ','SFO'),('YUL','YYZ'),('HKO','ORD')]
    assert find_itinerary(f1, 'YUL') == ['YUL','YYZ','SFO','HKO','ORD']

    f2 = [('SFO','COM'),('COM','YYZ')]
    assert find_itinerary(f2, 'COM') is None

    f3 = [('A','B'),('A','C'),('B','C'),('C','A')]
    assert find_itinerary(f3, 'A') == ['A','B','C','A','C']
    print("All Tests Passed")
