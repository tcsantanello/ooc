
#include "d.h"

/**
 * Class: D, type and initializer
 */
D DClass[ 1 ] = { DClassInit( 0, 0 ) };

/**
 * @brief Get the value of D.d
 * @param obj class object
 * @return object member 'd' value
 */
int D_getValue( void *obj ) {
  return cast_to( obj, D )->d;
}

/**
 * @brief Set the value of D.d
 * @param obj class object
 * @param value new value
 */
void D_setValue( void *obj, int value ) {
  cast_to( obj, D )->d = value;
}
