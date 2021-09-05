pub trait Foo {
  extern "C" fn foo(&self);
}

struct Bar {
  pub i: i32
}

struct Baz {
  pub j: i32
}

impl Foo for Bar {
  extern "C" fn foo(&self) {
    println!("Rust Bar! bar: {:p} bar.i: {} Bar::foo: {:p}", self, self.i, Bar::foo as *const ());
  }
}

impl Foo for Baz {
  extern "C" fn foo(&self) {
    println!("Rust Baz! baz: {:p} baz.j: {} Baz::foo: {:p}", self, self.j, Baz::foo as *const ());
  }
}

#[no_mangle]
pub extern "C" fn get_bar() -> &'static dyn Foo {
  return &Bar {i: 123};
}

#[no_mangle]
pub extern "C" fn get_baz() -> &'static dyn Foo {
  return &Baz {j: 456};
}

#[no_mangle]
pub extern "C" fn foo() {
  let bar = get_bar();
  println!("bar: {:p}", &bar);
  bar.foo();
  let baz = get_baz();
  println!("baz: {:p}", &baz);
  baz.foo();
}
