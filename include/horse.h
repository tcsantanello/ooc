#ifndef __HORSE_H__
#define __HORSE_H__

#include "animal.h"
#include "vehicle.h"

/**
 * @brief 'Horse' class, inherits 'Animal' and 'Vehicle'
 * 
 * Horses are animals that are used as transportation....
 */
typedef struct Horse {
  Object  object;   /**< Base object definition    */
  Animal  animal;   /**< Inherited Class 'Animal'  */
  Vehicle vehicle;  /**< Inherited Class 'Vehicle' */
} Horse;

/** 'Horse' Class type */
extern Horse HorseClass[ ];

/**
 * @brief 'Horse' Class initializer
 * @hideinitializer
 * @param next offset of the next class in the object
 * @param start distance from the beginning of the object
 */
#define HorseClassInit( next, start ) {                                 \
    ObjectInit( sizeof( Horse ), start + offsetof( Horse, animal ),     \
                start, Horse_ctor, Horse_dtor, HorseClass ),            \
      AnimalClassInit( offsetof( Horse, vehicle ) + start,              \
                       offsetof( Horse, animal ) + start,               \
                       Horse_getGreeting ),                             \
      VehicleClassInit( next, offsetof( Horse, vehicle ) + start ),     \
      }

const char *Horse_getGreeting( void *obj );
Horse      *Horse_ctor( Horse *horse );
void        Horse_dtor( Horse *horse );

#endif
