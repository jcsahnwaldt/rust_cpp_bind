#[repr(C)]
pub struct Foo {
  pub i: i32
}

#[no_mangle]
pub extern "C" fn rs_foo(f: Foo) -> Foo {
  println!("Hello Rust World: {}", f.i);
  return Foo { i: f.i + 1 };
}
