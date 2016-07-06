# sqlite-go-extension
Experimental SQLite extension implemented in Go. 

Aim of the project is to check the possiblity of implementing extension for [SQLite](http://sqlite.org) in [Go language](http://golang.org). Experimental extension was built with Go 1.6 and tested on Linux.

## Project structure
 - glitex.go - implementation of functions which are exported to c-archive.
 - extension/glitex.c - facade for shared library implemented in C. Initialize SQLite extension and registers functions exported from `glitex.go`.
 - tests/c_string.c - standalone, valid C application, that calls functions exported from `glitex.go`.
 - tests/go_string.c - standalone C application, that panic when function returning `go string` is called.
 - Makefile - builds SQLite extension and test programs

## Demo

![gif](https://github.com/miloszpiglas/sqlite-go-extension/blob/master/tty.gif)
