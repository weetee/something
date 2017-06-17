package main

import (
	"bufio"
	"fmt"
	"os"
)

type Value struct {
	Filename []string
	Count    int
}

func main() {
	counts := make(map[string]Value)
	files := os.Args[1:]
	if len(files) == 0 {
		countLines(os.Stdin, counts, "stdin")
	} else {
		for _, arg := range files {
			f, err := os.Open(arg)
			if err != nil {
				fmt.Fprintf(os.Stderr, "DupTest2: %v\n", err)
				continue
			}
			countLines(f, counts, arg)
			f.Close()
		}
	}
	for line, value := range counts {
		if value.Count > 1 {
			fmt.Printf("%d \t %s  in file: %s\n", value.Count, line, value.Filename)
		}
	}
}

func countLines(f *os.File, counts map[string]Value, file string) {
	input := bufio.NewScanner(f)
	for input.Scan() {
		tmp := counts[input.Text()]
		flag := false
		for _, name := range tmp.Filename {
			if name == file {
				flag = true
				break
			}
		}
		if !flag {
			tmp.Filename = append(tmp.Filename, file)
		}
		tmp.Count++
		counts[input.Text()] = tmp
	}
}
