package main

func phoneLetters(mapping map[byte][]string, digits string) []string {
	if len(digits) == 0 {
		return []string{""}
	}
	result := []string{}
	first := mapping[digits[0]]
	rest := phoneLetters(mapping, digits[1:])
	for _, f := range first {
		for _, r := range rest {
			result = append(result, f+r)
		}
	}
	return result
}

func problem81() {
	println("Problem 81:")
	m := map[byte][]string{
		'2': {"a", "b", "c"},
		'3': {"d", "e", "f"},
	}
	got := phoneLetters(m, "23")
	if len(got) != 9 {
		panic("expected 9 combinations")
	}
	println("All Tests Passed")
}
