package main

import (
	"crypto/md5"
	"fmt"
)

type FileSyncer struct {
	files map[string]string
}

func newFileSyncer() *FileSyncer {
	return &FileSyncer{files: map[string]string{}}
}

func (f *FileSyncer) put(name, content string) {
	f.files[name] = content
}

func (f *FileSyncer) checksum(name string) string {
	h := md5.Sum([]byte(f.files[name]))
	return fmt.Sprintf("%x", h)
}

func (f *FileSyncer) syncFrom(other *FileSyncer) []string {
	var transferred []string
	for name, content := range other.files {
		if f.checksum(name) != other.checksum(name) {
			f.files[name] = content
			transferred = append(transferred, name)
		}
	}
	return transferred
}

func problem59() {
	println("Problem 59:")
	a := newFileSyncer()
	b := newFileSyncer()
	a.put("foo.txt", "hello world")
	a.put("bar.txt", "same content")
	b.put("bar.txt", "same content")
	changed := b.syncFrom(a)
	if len(changed) != 1 || changed[0] != "foo.txt" {
		panic("expected only foo.txt to be synced")
	}
	if b.files["foo.txt"] != "hello world" {
		panic("sync content wrong")
	}
	println("All Tests Passed")
}
