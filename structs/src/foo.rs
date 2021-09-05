#[repr(C)]
pub struct Foo {
  pub i: i32
}

impl Foo {

  #[no_mangle]
  pub extern "C" fn inc(&mut self, i: i32) {
    self.i += i;
  }

  #[no_mangle]
  pub extern "C" fn get(&self) -> i32 {
    return self.i;
  }
}

#[no_mangle]
pub extern "C" fn rs_foo(f: &mut Foo) {
  f.inc(1);
  println!("Rust: {}", f.get());
}

#[no_mangle]
pub extern "C" fn get_foo() -> Foo {
  return Foo {i: 0}
}
