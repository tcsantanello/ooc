
#include "a.h"

/**
 * Class: A, type and initializer
 */
A AClass[ 1 ] = { AClassInit( 0, 0 ) };

/**
 * @brief Get the value of A.a
 * @param obj class object
 * @return object member 'a' value
 */
int A_getValue( void *obj ) {
  return cast_to( obj, A )->a;
}

/**
 * @brief Set the value of A.a
 * @param obj class object
 * @param value new value
 */
void A_setValue( void *obj, int value ) {
  cast_to( obj, A )->a = value;
}
