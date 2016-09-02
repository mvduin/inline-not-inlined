#pragma once
#include <stdio.h>

DECL inline void foo()
{
	printf( "called foo() defined in foo.h, included from %s\n", UNIT );
}
