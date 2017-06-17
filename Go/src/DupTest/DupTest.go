package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	counts := make(map[string]int)
	input := bufio.NewScanner(os.Stdin) //Scanner对象，从标准输入中读取内容
	for input.Scan() {
		counts[input.Text()]++ //input.Text()得到输入一行去掉换行符后的结果
	}

	for line, n := range counts {
		if n > 1 {
			fmt.Printf("%d \t%s\n", n, line)
		}
	}
}
