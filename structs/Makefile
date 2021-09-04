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

$(BIN)/main_rs: $(SRC)/main_rs.rs $(SRC)/foo.rs
	$(CARGO) build --bins

$(BIN)/main_c.o: $(SRC)/main_c.c $(SRC)/foo.h
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(BIN)/main_cpp.o: $(SRC)/main_cpp.cpp $(SRC)/foo.hpp
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

$(BIN)/main_c: $(BIN)/main_c.o $(BIN)/libfoo.a
	$(LINK.o) $^ $(LDLIBS) -o $@

$(BIN)/main_cpp: $(BIN)/main_cpp.o $(BIN)/libfoo.a
	$(LINK.cpp) $^ $(LDLIBS) -o $@

cbindgen: cbindgen-c cbindgen-cpp

$(SRC)/foo.h: $(SRC)/foo.rs
	cbindgen --config cbindgen-c.toml --output $(SRC)/foo.h
	touch $(SRC)/foo.h

$(SRC)/foo.hpp: $(SRC)/foo.rs
	cbindgen --config cbindgen-cpp.toml --output $(SRC)/foo.hpp
	touch $(SRC)/foo.hpp

zip:
	$(RM) *.zip
	zip -r foo.zip Makefile *.toml $(SRC)/*

clean:
	$(RM) -r *.zip target/ *.lock
