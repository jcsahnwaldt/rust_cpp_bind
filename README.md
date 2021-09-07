## rust_cpp_bind - make Rust methods callable as C++ methods

These toy projects contain simple Rust example code and C++ header files
that show how to make methods in Rust `trait`s and `impl`s callable as
C++ methods.

Motivation: [CBindGen](https://github.com/eqrion/cbindgen) is a cool tool
that generates C/C++ header files from Rust code. These header files can be
used to call Rust code from C/C++. Currently, CBindGen generates only struct
definitions and function declarations, but not C++ classes with methods.
That works, but means that C++ code using these structs and functions
doesn't have an object-oriented look and feel. The examples here show how
CBindGen could make Rust methods available as C++ methods.

Also see [CBindGen issue #707](https://github.com/eqrion/cbindgen/issues/707).

## Usage

The structure of the three projects is identical: a simple Cargo project plus
a Makefile. Running `make run` compiles and runs all code. Tested on macOS
and Ubuntu.

If you change `foo.rs` and call `make run` again, CBindGen will overwrite the
C and C++ headers, which will cause the C and C++ compilation to fail. In that
case, just restore the previous version of `foo.h` and `foo.hpp`.

## References

Rust compiler and library code related to vtables:
- core library: [metadata.rs](https://github.com/rust-lang/rust/blob/master/library/core/src/ptr/metadata.rs)
- compiler: [vtable.rs](https://github.com/rust-lang/rust/blob/master/compiler/rustc_middle/src/ty/vtable.rs)
- compiler tests: [vtable/](https://github.com/rust-lang/rust/tree/master/src/test/ui/traits/vtable)

TODO: Add references showing current layout of `dyn Trait` fat pointers.
