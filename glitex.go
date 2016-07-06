/*
 *   Experimental extension for SQLite implemented in Go
 *   Copyright (C) 2016  Milosz Piglas
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */ 

package main

import (
    "C"
    "strings"
)

const (
	license string = "GPLv3"
)

//export License
func License() string {
	return license
}

//export Version
func Version() string {
	return "1"
}

// Under specific circumstances program which calls this function might start panic
//export PureJoin
func PureJoin(sep string, values []string) string {
    result :=  strings.Join(values, sep)
    return result
}

//export CJoin
func CJoin(sep string, values []string) (*C.char, int) {
    result :=  strings.Join(values, sep)
    return C.CString(result), len(result)
}

func main() {
}
