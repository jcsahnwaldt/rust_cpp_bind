#[no_mangle]
pub extern "C" fn rs_foo(i: i32) -> i32 {
  println!("Hello Rust World: {}", i);
  return i + 1;
}
