#ifndef __DOG_H__
#define __DOG_H__

#include "animal.h"

/**
 * @brief 'Dog' class, inherits 'Animal' 
 */
typedef struct Dog {
  Object      object;   /**< Base object definition   */
  Animal      animal;   /**< Inherited Class 'Animal' */
  const char *greeting; /**< Dog's greeting           */
} Dog;

/** 'Dog' Class type */
extern Dog DogClass[ ];

/**
 * @brief 'Dog' Class initializer
 * @hideinitializer
 * @param next offset of the next class in the object
 * @param start distance from the beginning of the object
 */
#define DogClassInit( next, start ) {                        \
    ObjectInit( sizeof( Dog ), offsetof( Dog, animal ) + start, \
                start, Dog_ctor, Dog_dtor, DogClass ),          \
      AnimalClassInit( next, offsetof( Dog, animal ) + start,   \
                       Dog_getGreeting ),                       \
      }

Dog        *Dog_ctor( Dog *dog );
void        Dog_dtor( Dog *dog );
const char *Dog_getGreeting( void *obj );

#endif
