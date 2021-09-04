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

run: $(BIN)/project $(BIN)/main_c $(BIN)/main_cpp
	./$(BIN)/project
	./$(BIN)/main_c
	./$(BIN)/main_cpp

$(BIN)/libproject.a: $(SRC)/lib.rs
	$(CARGO) build --lib

$(BIN)/project: $(SRC)/main.rs
	$(CARGO) build --bins

$(BIN)/%: $(SRC)/%.c $(BIN)/libproject.a
	$(LINK.c) $^ $(LDLIBS) -o $@

$(BIN)/%: $(SRC)/%.cpp $(BIN)/libproject.a
	$(LINK.cpp) $^ $(LDLIBS) -o $@

cbindgen-c:
	cbindgen --config cbindgen-c.toml --output src/lib.h

cbindgen-cpp:
	cbindgen --config cbindgen-cpp.toml --output src/lib.hpp

zip:
	$(RM) *.zip
	zip -r project.zip Makefile *.toml src/*

clean:
	$(RM) -r *.zip target/ *.lock
