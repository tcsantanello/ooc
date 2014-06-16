#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include "object.h"

/**
 * @brief Function template to get the animal's greeting
 * @param object class object
 * @return animal's greeting
 */
typedef const char *( *Animal_Greeting    )( void *object );

/**
 * @brief Function template to say the animal's greeting
 * @param object class object
 */
typedef void        ( *Animal_SayGreeting )( void *object );

/**
 * @brief Abstract 'Animal' Class, animals can speak a greeting
 * 
 * Inheriting classes must implement 'greeting'
 */
typedef struct Animal {
  Object             object;   /**< Base object definition */
  Animal_Greeting    greeting; /**< Greeting getter        */
  Animal_SayGreeting speak;    /**< Greeting display       */
} Animal;

/** 'Animal' Class type */
extern Animal AnimalClass[ ];

/**
 * @brief 'Animal' Class initializer
 * @hideinitializer
 * @param next offset of the next class in the object
 * @param start distance from the beginning of the object
 * @param greeting virtual member 'Animal.greeting' getter
 */
#define AnimalClassInit( next, start, greeting ) {                      \
    ObjectInit( sizeof( Animal ), next, start, 0x00, 0x00, AnimalClass ), \
      greeting, Animal_sayGreeting,                                     \
      }

void Animal_sayGreeting( void *object );

/**
 * @brief Say the animal's greeting
 * @param obj class object
 */
static inline void Animal_speek( void *obj ) {
  Animal *animal = cast_to( obj, Animal );
  animal->speak( animal );
}

/**
 * @brief Get the animal's greeting
 * @param obj class object
 * @return animal's greeting
 */
static inline const char *Animal_greeting( void *obj ) {
  Animal *animal = cast_to( obj, Animal );
  return animal->greeting( animal );
}

#endif
