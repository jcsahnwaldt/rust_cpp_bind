#[repr(C)]
pub struct Foo {
  pub i: i32
}

impl Foo {

  #[no_mangle]
  pub extern "C" fn set_i(&mut self, i: i32) {
    self.i = i;
  }

  #[no_mangle]
  pub extern "C" fn get_i(&self) -> i32 {
    return self.i;
  }
}

#[no_mangle]
pub extern "C" fn rs_foo(f: Foo) -> Foo {
  println!("Hello Rust World: {}", f.i);
  return Foo { i: f.i + 1 };
}
