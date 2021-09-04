main: main.c target/debug/libproject.a

build:
	cargo build

target/debug/libproject.a: build

run: main
	./target/debug/project
	./main

clean:
	$(RM) -r main target *.lock
