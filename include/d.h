#ifndef __D_H__
#define __D_H__

#include "object.h"
#include "b.h"
#include "c.h"

/**
 * @brief Function template to get the value of D.d
 * @param obj class object
 * @return D.d value
 */
typedef int  ( *D_GetValue )( void *obj );

/**
 * @brief Function template to set the value of D.d
 * @param obj class object
 * @param value new value for D.d
 */
typedef void ( *D_SetValue )( void *obj, int value );

/**
 * @brief 'D' Class, inherits 'B' and 'C' classes (compound / complex inheritance)
 */
typedef struct D {
  Object      object;    /**< Base object definition */
  B           b;         /**< Inherited Class 'B'    */
  C           c;         /**< Inherited Class 'C'    */
  D_GetValue  get_value; /**< Get the value of D.d   */
  D_SetValue  set_value; /**< Set the value of D.d   */
  int         d;         /**< Member integer         */
} D;

/** 'D' Class type */
extern D DClass[ ];

/**
 * @brief 'D' Class initializer
 * @hideinitializer
 * @param next offset of the next class in the object
 * @param start distance from the beginning of the object
 */
#define DClassInit( next, start ) {                                     \
    ObjectInit( sizeof( D ), offsetof( D, b ) + start, start,           \
                0x00, 0x00, DClass ),                                   \
      BClassInit( offsetof( D, c ) + start,  offsetof( D, b ) + start ), \
      CClassInit( next, offsetof( D, c ) + start ),                     \
      D_getValue, D_setValue, 0, }

int  D_getValue( void *obj );
void D_setValue( void *obj, int value );

/**
 * @brief Get the value of 'd' from an instance of 'D'
 * @param obj class object
 * @return 'd' value
 */
static inline int D_get_value( void *obj ) {
  D *d = cast_to( obj, D );
  return d->get_value( d );
}

/**
 * @brief Set the value of 'd' in an instance of 'D'
 * @param obj class object
 * @param value new 'd' value
 */
static inline void D_set_value( void *obj, int value ) {
  D *d = cast_to( obj, D );
  d->set_value( d, value );
}

#endif
