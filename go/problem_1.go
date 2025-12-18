package main
import "fmt"

func findPairWithSum(numbers []int, k int) bool {
	for i := 0; i < len(numbers); i++ {
		if k - numbers[i] in numbers:
			return true
	return false
}

func main() {
	fmt.Println(findPairWithSum([]int{10, 15, 3, 7}, 17))
	fmt.Println(findPairWithSum("All tests passed"))
}