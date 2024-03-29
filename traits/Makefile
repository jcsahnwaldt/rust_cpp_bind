# CC := gcc
# CXX := g++
CLANG_FIX := -mlinker-version=0  # for Homebrew clang
CC := clang $(CLANG_FIX)
CXX := clang++ $(CLANG_FIX)
CXXFLAGS := -Wall -Wextra -Wpedantic -O3
CFLAGS := $(CXXFLAGS) -Wno-format -Wno-format-pedantic  # suppress %p format warnings
LDLIBS := -pthread -ldl  # for Ubuntu GCC and Clang
CARGO := CARGO_INCREMENTAL=0 cargo  # incremental uses hard links, leads to warnings on VM

SRC := src
BIN := target/debug

run: run_rs run_c run_cpp

run_rs: $(BIN)/main_rs
	./$<

run_c: $(BIN)/main_c
	./$<

run_cpp: $(BIN)/main_cpp
	./$<

$(BIN)/libfoo.a: $(SRC)/foo.rs
	$(CARGO) build --lib

$(BIN)/%: $(SRC)/%.rs $(SRC)/foo.rs
	$(CARGO) build --bins

$(BIN)/%: $(SRC)/%.c $(BIN)/libfoo.a $(SRC)/foo.h
	$(LINK.c) $(filter-out %.h,$^) $(LDLIBS) -o $@

$(BIN)/%: $(SRC)/%.cpp $(BIN)/libfoo.a $(SRC)/foo.hpp
	$(LINK.cpp) $(filter-out %.hpp,$^) $(LDLIBS) -o $@

$(SRC)/%.h: cbindgen-c.toml $(SRC)/%.rs
	cbindgen -c $< -o $@ && touch $@

$(SRC)/%.hpp: cbindgen-cpp.toml $(SRC)/%.rs
	cbindgen -c $< -o $@ && touch $@

clean:
	$(RM) -r target/ *.lock
