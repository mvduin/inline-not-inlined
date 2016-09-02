#define UNIT "main.c"
#include "foo.h"

void aux( char *arg0 );

int main( int argc, char **argv )
{
	printf( "%s: from %s() ", argv[0], __func__ );
	foo();
	aux( argv[0] );
	return 0;
}
