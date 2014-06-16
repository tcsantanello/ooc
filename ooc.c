#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "d.h"
#include "dog.h"
#include "horse.h"

/**
 * Simple inheritance test
 */
void dog_test( void ) {
  Animal *animal = cast_to( obj_new( Dog ), Animal );

  Animal_speek( animal );

  obj_delete( animal );
}

/**
 * Simple multiple inheritance test
 */
void horse_test( void ) {
  Horse *horse = obj_new( Horse );

  printf( "Hi horsie.  " );
  Animal_speek( horse );

  printf( "How fast are you ?\t%d MPH\n", Vehicle_get_speed( horse ) );
  printf( "Go faster !\n" );

  Vehicle_set_speed( horse, Vehicle_get_speed( horse ) + 5 );
  printf( "Now how fast are you ?\t%d MPH\n", Vehicle_get_speed( horse ) );

  obj_delete( horse );
}

/**
 * Complex multiple inheritance test (nested inheritance)
 */
void letter_test( void ) {
  D *d = obj_new( D );

  A_set_value( d, 1 );
  B_set_value( d, 2 );
  C_set_value( d, 3 );
  D_set_value( d, 4 );

  printf( "A: %d\n"
          "B: %d\n"
          "C: %d\n"
          "D: %d\n",
          A_get_value( d ),
          B_get_value( d ),
          C_get_value( d ),
          D_get_value( d ) );

  obj_delete( d );
}

int main( int argc, char *argv[ ] ) {
  struct tests {
    const char   *name;
    void       ( *func )( void );
  } tests[ ] = {
#define DEF_TEST( x ) { #x, x }
    DEF_TEST( dog_test    ),
    DEF_TEST( horse_test  ),
    DEF_TEST( letter_test ),
  };
  size_t pos = 0;

  for ( pos = 0; pos < sizeof( tests ) / sizeof( tests[ 0 ] ); ++pos ) {
    printf( "+-------------------------------------------------------\n"
            "| Test: %s\n\n", tests[ pos ].name );
    tests[ pos ].func( );
    printf( "+-------------------------------------------------------\n\n" );
  }

  return 0;
}
