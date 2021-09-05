use foo::*;

fn main() {
  let bar = get_bar();
  println!("Rust: bar: {:p}", bar);
  println!("Rust: bar.foo():");
  bar.foo();

  let baz = get_baz();
  println!("Rust: baz: {:p}", baz);
  println!("Rust: baz.foo():");
  baz.foo();
}
