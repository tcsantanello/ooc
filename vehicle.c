
#include "vehicle.h"

/**
 * Class: Vehicle, type and initializer
 */
Vehicle VehicleClass[ 1 ] = { VehicleClassInit( 0, 0 ) };

/**
 * @brief Set the speed of the vehicle
 * @param object class object
 * @param speed new speed
 */
void Vehicle_setSpeed( void *object, int speed ) {
  cast_to( object, Vehicle )->speed = speed;
}

/**
 * @brief Get the speed of the vehicle
 * @param object class object
 * @return vehicle speed
 */
int Vehicle_getSpeed( void *object ) {
  return cast_to( object, Vehicle )->speed;
}
