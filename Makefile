glitexbase.a: glitex.go
	@echo "glitexbase.a"
	go build -buildmode=c-archive -o glitexbase.a glitex.go
	
glitexbase.h: glitex.go
	@echo "glitexbase.h"
	go build -buildmode=c-archive -o glitexbase.a glitex.go
	
archive: glitexbase.a glitexbase.h
	
	
c_string: archive tests/c_string.c
	gcc -o run_test run_glitex.c glitexbase.a -lpthread

go_string: archive tests/go_string.c
	gcc -o run_test tests/go_string.c glitexbase.a -lpthread
    
clean:
	rm -f glitexbase.* run_test
