#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "object.h"

/**
 * @brief Function template to get the vehicle's speed
 * @param object class object
 * @return vehicle's speed
 */
typedef int  ( *Vehicle_GetSpeed )( void *object );

/**
 * @brief Function template to set the vehicle's speed
 * @param object class object
 * @param speed new speed
 */
typedef void ( *Vehicle_SetSpeed )( void *object, int speed );

/**
 * @brief 'Vehicle' Class, vehicles are a type of transportation and have
 * a current speed
 */
typedef struct Vehicle {
  Object            object;       /**< Base object definition   */
  Vehicle_GetSpeed  get_speed;    /**< Get the vehicle's speed  */
  Vehicle_SetSpeed  set_speed;    /**< Set the vehicle's speed  */
  int               speed;        /**< Current speed member     */
} Vehicle;

/** 'Vehicle' Class type */
extern Vehicle VehicleClass[ ];

/**
 * @brief 'Vehicle' Class initializer
 * @hideinitializer
 * @param next offset of the next class in the object
 * @param start distance from the beginning of the object
 */
#define VehicleClassInit( next, start ) {                               \
    ObjectInit( sizeof( Vehicle ), next, start, 0x00, 0x00, VehicleClass ), \
      Vehicle_getSpeed, Vehicle_setSpeed,                               \
      }

void Vehicle_setSpeed( void *object, int speed );
int  Vehicle_getSpeed( void *object );

/**
 * @brief Get the speed of a vehicle
 * @param obj class object
 * @return vehicle speed
 */
static inline int Vehicle_get_speed( void *obj ) {
  Vehicle *vehicle = cast_to( obj, Vehicle );
  return vehicle->get_speed( vehicle );
}

/**
 * @brief Set the speed of a vehicle
 * @param obj class object
 * @param speed new speed
 */
static inline void Vehicle_set_speed( void *obj, int speed ) {
  Vehicle *vehicle = cast_to( obj, Vehicle );
  vehicle->set_speed( vehicle, speed );
}

#endif
