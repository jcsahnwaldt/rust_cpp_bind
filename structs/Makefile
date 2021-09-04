# CC := gcc-11
CC := clang -mlinker-version=0 # for Homebrew clang
CFLAGS := -Wall -Wextra -Wpedantic -O3
LDLIBS := -pthread -ldl # for Ubuntu GCC and Clang

SRC := src
BIN := target/debug

run: $(BIN)/project $(BIN)/main
	./$(BIN)/project
	./$(BIN)/main

$(BIN)/libproject.a: $(SRC)/lib.rs
	CARGO_INCREMENTAL=0 cargo build --lib

$(BIN)/project: $(SRC)/main.rs
	CARGO_INCREMENTAL=0 cargo build --bins

$(BIN)/%: $(SRC)/%
	cp $< $@

$(SRC)/main: $(SRC)/main.c $(BIN)/libproject.a

clean:
	$(RM) -r src/main target *.lock
