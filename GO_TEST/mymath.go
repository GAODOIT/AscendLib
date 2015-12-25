package mymath

func ADD(a, b int) int {
	return a + b
}

func Sub(a, b int) int {
	return a - b
}

func Mult(a, b int) int {
	return a * b
}

func Div(a, b int) float32 {
	if b != 0 {
		return float32(a) / float32(b)
	} else {
		return 0
	}
}
