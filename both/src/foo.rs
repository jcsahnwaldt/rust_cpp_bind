#![allow(improper_ctypes_definitions)] // dyn Foo return types

pub trait Foo {
  extern "C" fn foo(&self);
}

#[repr(C)]
pub struct Bar {
  pub i: i32
}

#[repr(C)]
pub struct Baz {
  pub j: i32
}

impl Foo for Bar {
  #[export_name = "Bar_foo"]
  extern "C" fn foo(&self) {
    println!("Rust (Bar::foo): bar: {:p} Bar::foo: {:p}", self, Bar::foo as *const ());
  }
}

impl Foo for Baz {
  #[export_name = "Baz_foo"]
  extern "C" fn foo(&self) {
    println!("Rust (Baz::foo): baz: {:p} Baz::foo: {:p}", self, Baz::foo as *const ());
  }
}

#[no_mangle]
pub extern "C" fn get_bar() -> &'static Bar {
  return &Bar {i: 123};
}

#[no_mangle]
pub extern "C" fn get_baz() -> &'static Baz {
  return &Baz {j: 456};
}

#[no_mangle]
pub extern "C" fn get_foo_bar() -> &'static dyn Foo {
  return get_bar();
}

#[no_mangle]
pub extern "C" fn get_foo_baz() -> &'static dyn Foo {
  return get_baz();
}

#[no_mangle]
pub extern "C" fn run_rs() {
  println!("Hello Rust!");

  let bar = get_bar();
  println!("Rust: bar: {:p}", bar);
  bar.foo();
  let foo_bar = get_foo_bar();
  foo_bar.foo();

  let baz = get_baz();
  println!("Rust: baz: {:p}", baz);
  baz.foo();
  let foo_baz = get_foo_baz();
  foo_baz.foo();
}
