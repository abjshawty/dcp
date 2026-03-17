from typing import List


def validate_rules(rules: List[str]) -> bool:
    x_lo: dict = {}
    x_hi: dict = {}
    y_lo: dict = {}
    y_hi: dict = {}

    def mx(d, k, v): d[k] = max(d.get(k, float('-inf')), v)
    def mn(d, k, v): d[k] = min(d.get(k, float('inf')),  v)

    for rule in rules:
        parts = rule.split()
        if len(parts) != 3:
            continue
        a, direction, b = parts
        eps = 1.0
        if direction == 'N':   mx(y_lo, a, y_lo.get(b, 0) + eps)
        elif direction == 'S': mn(y_hi, a, y_hi.get(b, 0) - eps)
        elif direction == 'E': mx(x_lo, a, x_lo.get(b, 0) + eps)
        elif direction == 'W': mn(x_hi, a, x_hi.get(b, 0) - eps)
        elif direction == 'NE':
            mx(y_lo, a, y_lo.get(b, 0) + eps)
            mx(x_lo, a, x_lo.get(b, 0) + eps)
        elif direction == 'NW':
            mx(y_lo, a, y_lo.get(b, 0) + eps)
            mn(x_hi, a, x_hi.get(b, 0) - eps)
        elif direction == 'SE':
            mn(y_hi, a, y_hi.get(b, 0) - eps)
            mx(x_lo, a, x_lo.get(b, 0) + eps)
        elif direction == 'SW':
            mn(y_hi, a, y_hi.get(b, 0) - eps)
            mn(x_hi, a, x_hi.get(b, 0) - eps)
        for p in set(list(x_lo.keys()) + list(x_hi.keys())):
            if x_lo.get(p, float('-inf')) >= x_hi.get(p, float('inf')):
                return False
        for p in set(list(y_lo.keys()) + list(y_hi.keys())):
            if y_lo.get(p, float('-inf')) >= y_hi.get(p, float('inf')):
                return False
    return True


def main():
    print("Problem 87:")
    assert not validate_rules(["A N B", "B NE C", "C N A"])
    assert     validate_rules(["A NW B", "A N B"])
    print("All Tests Passed")
