
#include "horse.h"

/**
 * Class: Horse, type and initializer
 */
Horse HorseClass[ 1 ] = { HorseClassInit( 0, 0 ) };

/**
 * @brief Get the horse's greeting
 * @param obj class object
 * @return dog greeting
 */
const char *Horse_getGreeting( void *obj ) {
  return "Neigh!";
}

/**
 * @brief Horse constuctor
 * @param horse class object
 * @return class object, null on failure
 */
Horse *Horse_ctor( Horse *horse ) {
  horse->vehicle.speed = 25;

  return horse;
}

/**
 * @brief Horse destructor
 * @param horse class object
 */
void Horse_dtor( Horse *horse ) { }
