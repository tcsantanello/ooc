#ifndef __A_H__
#define __A_H__

#include "object.h"

/**
 * @brief Function template to get the value of A.a
 * @param obj class object
 * @return A.a value
 */
typedef int  ( *A_GetValue )( void *obj );

/**
 * @brief Function template to set the value of A.a
 * @param obj class object
 * @param value new value for A.a
 */
typedef void ( *A_SetValue )( void *obj, int value );

/**
 * @brief 'A' Class, simple object
 */
typedef struct A {
  Object      object;    /**< Base object definition */
  A_GetValue  get_value; /**< Get the value of A.a   */
  A_SetValue  set_value; /**< Set the value of A.a   */
  int         a;         /**< Member integer         */
} A;

/** 'A' Class type */
extern A AClass[ ];

/**
 * @brief 'A' Class initializer
 * @hideinitializer
 * @param next offset of the next class in the object
 * @param start distance from the beginning of the object
 */
#define AClassInit( next, start ) {                                     \
    ObjectInit( sizeof( A ), next, start, 0x00, 0x00, AClass ),         \
      A_getValue, A_setValue, 0                                         \
      }

int  A_getValue( void *obj );
void A_setValue( void *obj, int value );

/**
 * @brief Get the value of 'a' from an instance of 'A'
 * @param obj class object
 * @return 'a' value
 */
static inline int A_get_value( void *obj ) {
  A *a = cast_to( obj, A );
  return a->get_value( a );
}

/**
 * @brief Set the value of 'a' in an instance of 'A'
 * @param obj class object
 * @param value new 'a' value
 */
static inline void A_set_value( void *obj, int value ) {
  A *a = cast_to( obj, A );
  a->set_value( a, value );
}

#endif
