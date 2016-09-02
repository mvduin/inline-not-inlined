#define UNIT "foo.c"
#include "foo.h"

void foo()
{
	printf( "called foo() defined in %s\n", UNIT );
}
