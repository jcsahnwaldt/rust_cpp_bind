# CC := gcc-11
CC := clang -mlinker-version=0 # for Homebrew clang
CFLAGS := -Wall -Wextra -Wpedantic -O3

main: main.c target/debug/libproject.a

build:
	cargo build

target/debug/libproject.a: build

run: main
	./target/debug/project
	./main

clean:
	$(RM) -r main target *.lock
