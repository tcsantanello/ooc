
#include "c.h"

/**
 * Class: C, type and initializer
 */
C CClass[ 1 ] = { CClassInit( 0, 0 ) };

/**
 * @brief Get the value of C.c
 * @param obj class object
 * @return object member 'c' value
 */
int C_getValue( void *obj ) {
  return cast_to( obj, C )->c;
}

/**
 * @brief Set the value of C.c
 * @param obj class object
 * @param value new value
 */
void C_setValue( void *obj, int value ) {
  cast_to( obj, C )->c = value;
}
