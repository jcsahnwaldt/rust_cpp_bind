# CC := gcc-11
CC := clang -mlinker-version=0 # for Homebrew clang
CFLAGS := -Wall -Wextra -Wpedantic -O3
LDLIBS := -pthread -ldl # for Ubuntu GCC and Clang

SRC := src
BIN := target/debug

run: $(BIN)/project $(BIN)/main
	./$(BIN)/project
	./$(BIN)/main

build:
	cargo build

$(BIN)/libproject.a: build
$(BIN)/project: build

$(BIN)/%: $(SRC)/%
	cp $< $@

$(SRC)/main: $(SRC)/main.c $(BIN)/libproject.a

clean:
	$(RM) -r src/main target *.lock
