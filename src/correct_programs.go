package main

var a int = sum(5, 6);

// AND operator function
func and(bool1 bool, bool2 bool) bool{
	return bool1 && bool2
}

// OR operator function
func or(bool1 bool, bool2 bool) bool{
	return bool1 || bool2
}

// SUM function
func sum(num1 int, num2 int) int{
	return num1 + num2;
}

// Recursive version of Fibonacci. Calculates the n'th Fibonacci number.
func recursive_fibonacci(n int) int {
	if n <= 1 {
		return n;
	} else {
		return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
	};
}
 
// Helper function to simulate the modulo operator (since I have not implemented modulo)
func get_remainder(num int, divisor int) int{
	return num - (divisor * (num / divisor))
}

// Returns true if n is a prime number and false when it is not.
func is_prime(n int) bool{
	
	var i int = 1

	for i; i <= n; i++ {
		if get_remainder(n, i) == 0 && i != 1 && i != n {
			return false
		}
	}
	return true
}

// Compares 2 numbers. Returns 1 if n1 > n2, returns -1 if n2 > n1 and 0 when they are equal.
func num_compare(n1 int, n2 int) int{
	if n1 > n2{
		return 1
	} else if n2 > n1{
		return -1
	} else {
		return -0
	}
}

func main() {
	// AND and OR operation
	var b1 = true;
	var b2 = false;
	print(and(b1, b2));
	print(or(b1, b2));

	// Check if a certain integer is prime.
	print(is_prime(7919));

	// Compare 2 integer
	print(num_compare(1, 1));
}

// Shows which default values are assigned to integer and boolean literals
var defaultint int;
var defaultbool bool;
