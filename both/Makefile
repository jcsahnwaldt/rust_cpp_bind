# CC := gcc-11
# CXX := g++-11
CC := clang -mlinker-version=0  # for Homebrew clang
CXX := clang++ -mlinker-version=0  # for Homebrew clang
CFLAGS := -Wall -Wextra -Wpedantic -Wno-format-pedantic -O3
CXXFLAGS := $(CFLAGS)
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

clean:
	$(RM) -r target/ *.lock
