# CC := gcc-11
# CXX := g++-11
CC := clang -mlinker-version=0 # for Homebrew clang
CXX := clang++ -mlinker-version=0 # for Homebrew clang
CFLAGS := -Wall -Wextra -Wpedantic -O3
CXXFLAGS := $(CFLAGS)
LDLIBS := -pthread -ldl # for Ubuntu GCC and Clang
CARGO := CARGO_INCREMENTAL=0 cargo  # incremental uses hard links, leads to warnings on VM

SRC := src
BIN := target/debug

run: $(BIN)/main_rs $(BIN)/main_c $(BIN)/main_cpp
	./$(BIN)/main_rs
	./$(BIN)/main_c
	./$(BIN)/main_cpp

$(BIN)/libfoo.a: $(SRC)/foo.rs
	$(CARGO) build --lib

$(BIN)/%: $(SRC)/%.rs
	$(CARGO) build --bins

$(BIN)/%: $(SRC)/%.c $(BIN)/libfoo.a
	$(LINK.c) $^ $(LDLIBS) -o $@

$(BIN)/%: $(SRC)/%.cpp $(BIN)/libfoo.a
	$(LINK.cpp) $^ $(LDLIBS) -o $@

cbindgen-c:
	cbindgen --config cbindgen-c.toml --output src/foo.h

cbindgen-cpp:
	cbindgen --config cbindgen-cpp.toml --output src/foo.hpp

zip:
	$(RM) *.zip
	zip -r foo.zip Makefile *.toml src/*

clean:
	$(RM) -r *.zip target/ *.lock
