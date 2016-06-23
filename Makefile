glitexbase.a: glitex.go
	@echo "glitexbase.a"
	go build -buildmode=c-archive -o glitexbase.a glitex.go
	
glitexbase.h: glitex.go
	@echo "glitexbase.h"
	go build -buildmode=c-archive -o glitexbase.a glitex.go
	
archive: glitexbase.a glitexbase.h
	
	
c_string: archive run_glitex.c
	gcc -o c_string run_glitex.c glitexbase.a -lpthread

go_string: archive tests/go_string.c
	gcc -o go_string tests/go_string.c glitexbase.a -lpthread
    
clean:
	rm -f glitexbase.* c_string
