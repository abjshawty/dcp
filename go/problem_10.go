package main

import (
	"fmt"
	"time"
)

// schedule calls f after a delay of n milliseconds in a background goroutine.
func schedule(f func(), n int) {
	go func() {
		time.Sleep(time.Duration(n) * time.Millisecond)
		f()
	}()
}

func problem10() {
	fmt.Println("Problem 10:")
	done := make(chan struct{})
	schedule(func() {
		close(done)
	}, 50)
	<-done // block until the scheduled function fires
	fmt.Println("All Tests Passed")
}
