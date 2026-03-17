from typing import Dict, List


def phone_letters(mapping: Dict[str, List[str]], digits: str) -> List[str]:
    if not digits:
        return ['']
    result = []
    for letter in mapping[digits[0]]:
        for rest in phone_letters(mapping, digits[1:]):
            result.append(letter + rest)
    return result


def main():
    print("Problem 81:")
    m = {'2': ['a','b','c'], '3': ['d','e','f']}
    got = phone_letters(m, "23")
    assert len(got) == 9
    assert 'ad' in got and 'cf' in got
    print("All Tests Passed")
