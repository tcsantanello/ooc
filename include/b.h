#ifndef __B_H__
#define __B_H__

#include "object.h"
#include "a.h"

/**
 * @brief Function template to get the value of B.b
 * @param obj class object
 * @return B.b value
 */
typedef int  ( *B_GetValue )( void *obj );

/**
 * @brief Function template to set the value of B.b
 * @param obj class object
 * @param value new value for B.b
 */
typedef void ( *B_SetValue )( void *obj, int value );

/**
 * @brief 'B' class, inherits 'A' (basic inheritance)
 */
typedef struct B {
  Object      object;    /**< Base object definition */
  A           a;         /**< Inherited Class 'A'    */
  B_GetValue  get_value; /**< Get the value of B.b   */
  B_SetValue  set_value; /**< Set the value of B.b   */
  int         b;         /**< Member integer         */
} B;

/** 'B' Class type */
extern B BClass[ ];

/**
 * @brief 'B' Class initializer
 * @hideinitializer
 * @param next offset of the next class in the object
 * @param start distance from the beginning of the object
 */
#define BClassInit( next, start ) {                                     \
    ObjectInit( sizeof( B ), offsetof( B, a ) + start, start, 0x00, 0x00, BClass ), \
      AClassInit( next, offsetof( B, a ) + start ), B_getValue, B_setValue, 0 }

int  B_getValue( void *obj );
void B_setValue( void *obj, int value );

/**
 * @brief Get the value of 'b' from an instance of 'B'
 * @param obj class object
 * @return 'b' value
 */
static inline int B_get_value( void *obj ) {
  B *b = cast_to( obj, B );
  return b->get_value( b );
}

/**
 * @brief Set the value of 'b' in an instance of 'B'
 * @param obj class object
 * @param value new 'b' value
 */
static inline void B_set_value( void *obj, int value ) {
  B *b = cast_to( obj, B );
  b->set_value( b, value );
}


#endif
