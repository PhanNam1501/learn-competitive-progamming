package main

import "fmt"

func find132pattern(nums []int) bool {
	third := -1 << 31
	st := []int{}

	for i := len(nums) - 1; i >= 0; i-- {

		if nums[i] < third {
			return true
		}

		// Pop những phần tử nhỏ hơn nums[i]
		// phần tử pop ra sẽ là candidate tốt nhất cho nums[k]
		for len(st) > 0 && st[len(st)-1] < nums[i] {
			third = st[len(st)-1]
			st = st[:len(st)-1]
		}

		// Push nums[j]
		st = append(st, nums[i])
	}

	return false
}

func main() {
	input := []int{3, 5, 0, 3, 4}
	c := find132pattern(input)
	fmt.Println(c)

}
