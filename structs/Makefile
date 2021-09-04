# CC := gcc-11
# CXX := g++-11
CC := clang -mlinker-version=0 # for Homebrew clang
CXX := clang++ -mlinker-version=0 # for Homebrew clang
CFLAGS := -Wall -Wextra -Wpedantic -O3
CXXFLAGS := $(CFLAGS)
LDLIBS := -pthread -ldl # for Ubuntu GCC and Clang

SRC := src
BIN := target/debug

run: $(BIN)/project $(BIN)/main_c $(BIN)/main_cpp
	./$(BIN)/project
	./$(BIN)/main_c
	./$(BIN)/main_cpp

$(BIN)/libproject.a: $(SRC)/lib.rs
	CARGO_INCREMENTAL=0 cargo build --lib

$(BIN)/project: $(SRC)/main.rs
	CARGO_INCREMENTAL=0 cargo build --bins

$(BIN)/%: $(SRC)/%
	cp $< $@

$(SRC)/main_c: $(SRC)/main_c.c $(BIN)/libproject.a
$(SRC)/main_cpp: $(SRC)/main_cpp.cpp $(BIN)/libproject.a

cbindgen-c:
	cbindgen --config cbindgen-c.toml --output src/lib.h

cbindgen-cpp:
	cbindgen --config cbindgen-cpp.toml --output src/lib.hpp

clean:
	$(RM) -r src/main target *.lock
