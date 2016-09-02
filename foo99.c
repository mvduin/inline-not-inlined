#define UNIT "foo99.c"
#include "foo.h"

// The "extern inline" is optional but ensures you'll get a compiler warning
// if no definition is provided (typically as inline function in a header).
// This is more useful then the linker errors further down the road.
extern inline void foo();
