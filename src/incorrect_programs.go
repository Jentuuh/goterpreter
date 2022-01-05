package main 

// Wrong amount of variables/expressions on left/right-hand side of the assignment
var a,b,c,d = wrongReturnTypes()


func wrongReturnTypes() (bool, int, int){
	return 1, true, 1
}

func moreThan1ReturnValue() (int, int){
	return 1, 1
}

func notAllPathsReturn() int {
	if true {
		return 1
	} else {
		if true{
			// We return nothing in this execution path (base level), which would lead to undefined behaviour
		} else {
			return 1
		}
	}
}

func main(unAllowedParam bool) int{

	// We cannot call a function that returns more than 1 value in a binary expression
	var i = 2 + moreThan1ReturnValue()
	// Boolean operator on integer literal
	var x = !2
	// Integer operator on boolean literal
	var y = -true

	// Undeclared identifier k
	var z = k + 1

	return 0
}
