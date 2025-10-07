package main

func removeElement(nums []int, val int) int {
    read := 0
    write := 0

    for read < len(nums) {
        if (nums[read] != val) {
            nums[write] = nums[read]
            write++
        }
        read++
    }
    return write
}