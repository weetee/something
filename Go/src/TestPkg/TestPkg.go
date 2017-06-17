package test

import "fmt"

func TestPkg(str string) {
	if str != "" {
		fmt.Println("the string value not null")
	} else {
		fmt.Println("the string value is null")
	}

	comp := 5 + 5i
	fmt.Println("complex value is : ", comp)
}
