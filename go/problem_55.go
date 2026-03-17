package main

import (
	"crypto/rand"
	"encoding/hex"
)

type URLShortener struct {
	short2long map[string]string
	long2short map[string]string
}

func newURLShortener() *URLShortener {
	return &URLShortener{
		short2long: map[string]string{},
		long2short: map[string]string{},
	}
}

func (u *URLShortener) shorten(url string) string {
	if s, ok := u.long2short[url]; ok {
		return s
	}
	b := make([]byte, 3)
	rand.Read(b)
	s := hex.EncodeToString(b)
	u.short2long[s] = url
	u.long2short[url] = s
	return s
}

func (u *URLShortener) restore(short string) (string, bool) {
	v, ok := u.short2long[short]
	return v, ok
}

func problem55() {
	println("Problem 55:")
	us := newURLShortener()
	s1 := us.shorten("https://example.com")
	if len(s1) == 0 {
		panic("empty short")
	}
	orig, ok := us.restore(s1)
	if !ok || orig != "https://example.com" {
		panic("restore failed")
	}
	s2 := us.shorten("https://example.com")
	if s1 != s2 {
		panic("same URL should map to same short")
	}
	_, ok = us.restore("notexist")
	if ok {
		panic("should not exist")
	}
	println("All Tests Passed")
}
