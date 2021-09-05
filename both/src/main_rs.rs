use foo::*;

fn main() {
  let bar = get_bar();
  println!("Rust: bar: {:p}", bar);
  println!("Rust: bar.foo():");
  bar.foo();
  let foo_bar = get_foo_bar();
  println!("Rust: foo_bar.foo():");
  foo_bar.foo();

  let baz = get_baz();
  println!("Rust: baz: {:p}", baz);
  println!("Rust: baz.foo():");
  baz.foo();
  let foo_baz = get_foo_baz();
  println!("Rust: foo_baz.foo():");
  foo_baz.foo();
}
