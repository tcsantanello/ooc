
#include <stdio.h>

#include "dog.h"

/**
 * Class: Dog, type and initializer
 */
Dog DogClass[ 1 ] = { DogClassInit( 0, 0 ) };

/**
 * @brief Get the dog's greeting
 * @param obj class object
 * @return dog greeting
 */
const char *Dog_getGreeting( void *obj ) {
  return cast_to( obj, Dog )->greeting;
}

/**
 * @brief Dog constuctor
 * @param dog class object
 * @return class object, null on failure
 */
Dog *Dog_ctor( Dog *dog ) {
  dog->greeting = "Woof!";
  return dog;
}

/**
 * @brief Dog destructor
 * @param dog class object
 */
void Dog_dtor( Dog *dog ) {
  printf( "Stay boy\n" );
}
