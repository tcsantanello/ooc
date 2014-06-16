#ifndef __C_H__
#define __C_H__

#include "object.h"
#include "a.h"

/**
 * @brief Function template to get the value of C.c
 * @param obj class object
 * @return C.c value
 */
typedef int  ( *C_GetValue )( void *obj );

/**
 * @brief Function template to set the value of C.c
 * @param obj class object
 * @param value new value for C.c
 */
typedef void ( *C_SetValue )( void *obj, int value );

/**
 * @brief 'C' Class, inherits 'A' (basic inheritance)
 */
typedef struct C {
  Object      object;    /**< Base object definition */
  A           a;         /**< Inherited Class 'A'    */
  C_GetValue  get_value; /**< Get the value of C.c   */
  C_SetValue  set_value; /**< Set the value of C.c   */
  int         c;         /**< Member integer         */
} C;

/** 'C' Class type */
extern C CClass[ ];

/**
 * @brief 'C' Class initializer
 * @hideinitializer
 * @param next offset of the next class in the object
 * @param start distance from the beginning of the object
 */
#define CClassInit( next, start ) {                                  \
    ObjectInit( sizeof( C ), offsetof( C, a ) + start, start, 0x00, 0x00, CClass ), \
      AClassInit( next, offsetof( C, a ) + start ), C_getValue, C_setValue, 0 }

int  C_getValue( void *obj );
void C_setValue( void *obj, int value );

/**
 * @brief Get the value of 'c' from an instance of 'C'
 * @param obj class object
 * @return 'c' value
 */
static inline int C_get_value( void *obj ) {
  C *c = cast_to( obj, C );
  return c->get_value( c );
}

/**
 * @brief Set the value of 'c' in an instance of 'C'
 * @param obj class object
 * @param value new 'c' value
 */
static inline void C_set_value( void *obj, int value ) {
  C *c = cast_to( obj, C );
  c->set_value( c, value );
}

#endif
