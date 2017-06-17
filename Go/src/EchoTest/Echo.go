package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	var str, single string
	for _, arg := range os.Args[1:] {
		str += single + arg
		single = " "
	}
	fmt.Println(str)

	fmt.Println("use strings.Join")
	fmt.Println(strings.Join(os.Args[1:], " "))

	fmt.Println(os.Args[1:])
}
