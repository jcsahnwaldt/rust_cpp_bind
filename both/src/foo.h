#ifndef FOO_H
#define FOO_H

typedef struct Foo Foo;

typedef struct FooFns {
  void (*foo)(Foo*);
} FooFns;

typedef struct FooDyn {
  Foo* foo;
  FooFns* fns;
} FooDyn;

FooDyn get_bar(void);
FooDyn get_baz(void);

void foo(void);

#endif /* FOO_H */
