#[repr(C)]
pub struct Foo {
  pub i: i32
}

impl Foo {
  #[no_mangle]
  pub extern "C" fn foo(&self) {
    println!("Rust (Foo::foo): self: {:p}", self);
  }
}

#[no_mangle]
pub extern "C" fn get_foo() -> &'static Foo {
  return &Foo {i: 1};
}
