
#include "b.h"

/**
 * Class: B, type and initializer
 */
B BClass[ 1 ] = { BClassInit( 0, 0 ) };

/**
 * @brief Get the value of B.b
 * @param obj class object
 * @return object member 'b' value
 */
int B_getValue( void *obj ) {
  return cast_to( obj, B )->b;
}

/**
 * @brief Set the value of B.b
 * @param obj class object
 * @param value new value
 */
void B_setValue( void *obj, int value ) {
  cast_to( obj, B )->b = value;
}
