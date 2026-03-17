package main

type Reader82 struct {
	content string
	pos     int
	buf     string
}

func (r *Reader82) read7() string {
	end := r.pos + 7
	if end > len(r.content) {
		end = len(r.content)
	}
	s := r.content[r.pos:end]
	r.pos = end
	return s
}

func (r *Reader82) readN(n int) string {
	for len(r.buf) < n {
		chunk := r.read7()
		if len(chunk) == 0 {
			break
		}
		r.buf += chunk
	}
	if n > len(r.buf) {
		n = len(r.buf)
	}
	result := r.buf[:n]
	r.buf = r.buf[n:]
	return result
}

func problem82() {
	println("Problem 82:")
	r := &Reader82{content: "Hello world"}
	assertEqual(r.readN(5), "Hello")
	assertEqual(r.readN(1), " ")
	assertEqual(r.readN(5), "world")
	assertEqual(r.readN(5), "")
	println("All Tests Passed")
}
