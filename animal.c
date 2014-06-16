
#include <stdio.h>

#include "animal.h"

/**
 * Class: Animal, type and initializer
 */
Animal AnimalClass[ 1 ] = { AnimalClassInit( 0, 0, 0x00 ) };

/**
 * @brief Print out the animal's greeting
 * @param object class object
 */
void Animal_sayGreeting( void *object ) {
  printf( "%s\n", Animal_greeting( object ) );
}
