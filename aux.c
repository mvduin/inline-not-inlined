#define UNIT "aux.c"
#include "foo.h"

void aux( char *arg0 )
{
	printf( "%s: from %s() ", arg0, __func__ );
	foo();
}
