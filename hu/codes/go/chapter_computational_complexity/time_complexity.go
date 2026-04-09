// File: time_complexity.go
// Created Time: 2022-12-13
// Author: msk397 (machangxinq@gmail.com)

package chapter_computational_complexity

/* Konstans rend */
func constant(n int) int {
	count := 0
	size := 100000
	for i := 0; i < size; i++ {
		count++
	}
	return count
}

/* Lineáris rend */
func linear(n int) int {
	count := 0
	for i := 0; i < n; i++ {
		count++
	}
	return count
}

/* Lineáris rend (tömb bejárása) */
func arrayTraversal(nums []int) int {
	count := 0
	// Az iterációk száma arányos a tömb hosszával
	for range nums {
		count++
	}
	return count
}

/* Exponenciális rend */
func quadratic(n int) int {
	count := 0
	// Az iterációk száma négyzetesen függ az n adatmérettől
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			count++
		}
	}
	return count
}

/* Négyzetes rend (buborékrendezés) */
func bubbleSort(nums []int) int {
	count := 0 // Számláló
	// Külső ciklus: a rendezetlen tartomány [0, i]
	for i := len(nums) - 1; i > 0; i-- {
		// Belső ciklus: a [0, i] rendezetlen tartomány legnagyobb elemét csere a jobb szélre
		for j := 0; j < i; j++ {
			if nums[j] > nums[j+1] {
				// nums[j] és nums[j + 1] cseréje
				tmp := nums[j]
				nums[j] = nums[j+1]
				nums[j+1] = tmp
				count += 3 // Az elemcsere 3 elemi műveletet tartalmaz
			}
		}
	}
	return count
}

/* Exponenciális rend (ciklus implementáció) */
func exponential(n int) int {
	count, base := 0, 1
	// A sejtek minden körben kettéoszlanak, így az 1, 2, 4, 8, ..., 2^(n-1) sorozat jön létre
	for i := 0; i < n; i++ {
		for j := 0; j < base; j++ {
			count++
		}
		base *= 2
	}
	// count = 1 + 2 + 4 + 8 + .. + 2^(n-1) = 2^n - 1
	return count
}

/* Exponenciális rend (rekurzív implementáció) */
func expRecur(n int) int {
	if n == 1 {
		return 1
	}
	return expRecur(n-1) + expRecur(n-1) + 1
}

/* Logaritmikus rend (ciklus implementáció) */
func logarithmic(n int) int {
	count := 0
	for n > 1 {
		n = n / 2
		count++
	}
	return count
}

/* Logaritmikus rend (rekurzív implementáció) */
func logRecur(n int) int {
	if n <= 1 {
		return 0
	}
	return logRecur(n/2) + 1
}

/* Lineáris-logaritmikus rend */
func linearLogRecur(n int) int {
	if n <= 1 {
		return 1
	}
	count := linearLogRecur(n/2) + linearLogRecur(n/2)
	for i := 0; i < n; i++ {
		count++
	}
	return count
}

/* Faktoriális rend (rekurzív implementáció) */
func factorialRecur(n int) int {
	if n == 0 {
		return 1
	}
	count := 0
	// 1-től n-re osztás
	for i := 0; i < n; i++ {
		count += factorialRecur(n - 1)
	}
	return count
}
