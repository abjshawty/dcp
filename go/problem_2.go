func productOfArrayExceptSelf(numbers []int) []int {
	var product int = 1;
	for i:= 0; i < len(numbers); i++ {
		product *= numbers[i]
	}
	return []int{}
}

func main() {
	fmt.Println(productOfArrayExceptSelf([]int{1, 2, 3, 4, 5}))
}