package main

var reeeee, hehe int = 2, 3
// var b, d, e = a, c + x, 5;
var a = 2
var b int = a
var e int = test2()

func fibonacci(n int) int {

	if n <= 1 {
		return n;
	} else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	};
}

func test2() (int) {
	if true {
		return 6;

	} else if false {
		return 3;

	} else {
		return 4;
	};
}

func test() (int, int) {
	fibonacci(3);

	return 5, 6;
}

func diff_return_types() (int, bool) {
	return 1, true
}

func for_and_if_test() bool {
	var i int = 2;
	i += 2;

	if i == 4 {
		i += 1;
	};
	var (j int = 1);

	for j; j < 5; j++ {
		i += 1;
	};

	return i==9;
}

func main() {
	print(reee)
	var i bool = for_and_if_test()
	print(i);

	var y, h = diff_return_types()
	print(y, h);
	
	var k int = 0;
	for k; k < 10; k++ {
		print(fibonacci(k));
	};

	return;
}

var reee int = test2()
var s,o int = test();
var lmao int;
var lmaobool bool;