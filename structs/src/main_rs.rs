use foo::*;

fn main() {
  let f = get_foo();
  println!("Rust: f: {:p}", f);
  println!("Rust: f.foo():");
  f.foo();
}
