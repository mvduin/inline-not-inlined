# inline-not-inlined
If you compiled with optimization (more specifically function inlining) enabled all three versions should produce the same output:
```
~/tmp/inline$ make -B CFLAGS=-O
gcc -O -Wall  -std=gnu89 -DDECL=extern  -o g89  main.c aux.c foo.c
gcc -O -Wall  -std=c99   -DDECL=        -o c99  main.c aux.c foo99.c
g++ -O -Wall             -DDECL=        -o c++  main.c aux.c
./g89; ./c99; ./c++;
./g89: from main() called foo() defined in foo.h, included from main.c
./g89: from aux() called foo() defined in foo.h, included from aux.c
./c99: from main() called foo() defined in foo.h, included from main.c
./c99: from aux() called foo() defined in foo.h, included from aux.c
./c++: from main() called foo() defined in foo.h, included from main.c
./c++: from aux() called foo() defined in foo.h, included from aux.c
```

On the other hand things get more interesting with inlining disabled:
```
~/tmp/inline$ make -B 
gcc -Wall  -std=gnu89 -DDECL=extern  -o g89  main.c aux.c foo.c
gcc -Wall  -std=c99   -DDECL=        -o c99  main.c aux.c foo99.c
g++ -Wall             -DDECL=        -o c++  main.c aux.c
./g89; ./c99; ./c++;
./g89: from main() called foo() defined in foo.c
./g89: from aux() called foo() defined in foo.c
./c99: from main() called foo() defined in foo.h, included from foo99.c
./c99: from aux() called foo() defined in foo.h, included from foo99.c
./c++: from main() called foo() defined in foo.h, included from main.c
./c++: from aux() called foo() defined in foo.h, included from main.c
```
