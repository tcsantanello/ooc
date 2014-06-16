#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Function template to construct / initialize an object
 * @param object class object
 * @return created object or null on failure
 */
typedef struct Object *( *Object_Ctor )( struct Object *object );

/**
 * @brief Function template to destroy an object
 * @param object class object
 */
typedef void           ( *Object_Dtor )( struct Object *object );

/**
 * @brief Basic object definition
 * 
 * Describes the class instance 
 */
typedef struct Object {
  size_t         size;   /**< Size of the entire object */
  off_t          next;   /**< Offset of the next class  */
  off_t          start;  /**< Offset of this class      */
  Object_Ctor    ctor;   /**< Class constructor         */
  Object_Dtor    dtor;   /**< Class destructor          */
  void          *type;   /**< Class type reference      */
} Object;

/**
 * @brief Base object initializer
 * @hideinitializer
 * @param size structure size
 * @param next offset of the next class in the object
 * @param start distance from the beginning of the object
 * @param ctor object constructor
 * @param dtor object destructor
 * @param type object class definition (used as a type reference)
 */
#define ObjectInit( size, next, start, ctor, dtor, type )               \
  { size, next, start, ( Object_Ctor ) ctor, ( Object_Dtor ) dtor, type }

/**
 * @brief Perform a cast
 * @hideinitializer
 * @param _obj class object
 * @param type class type
 */
#define __cast( _obj, type )  ( ( type * ) ( _obj ) )

/**
 * @brief Walk through all inherited classes of an object, performing 'block' on each
 * @hideinitializer
 * @param _obj class object
 * @param block code to execute
 */
#define WALKIT( _obj, block ) do {                                      \
    Object *_object = __cast( __cast( _obj, char ) -                    \
                              __cast( _obj, Object )->start, Object );  \
    Object *_orig   = _object;                                          \
                                                                        \
    do {                                                                \
      _obj = _object; block;                                            \
                                                                        \
      if ( _object->next == 0 ) {                                       \
        break;                                                          \
      }                                                                 \
                                                                        \
      _object = __cast( __cast( _object, char ) +                       \
                        _object->next - _object->start,                 \
                        Object );                                       \
    } while ( true );                                                   \
                                                                        \
    _obj = _orig;                                                       \
  } while ( false )

/**
 * @brief Dynamically cast an object to another type
 * @param obj class object
 * @param type class to dynamically cast
 * @return casted class or null on failure (input, or not-a-member)
 */
static inline void *cast_to( Object *obj, void *type ) {
  if ( ( obj != 0x00 ) && ( obj->type != type ) ) {
    WALKIT( obj,
            if ( obj->type == type ) {
              return obj;
            } );

    obj = 0x00;
  }

  return obj;
}

void  obj_delete( void *object );
void *obj_new( void *type );

/**
 * @brief Create a new object and cast to the appropriate type
 * @hideinitializer
 * @param type new object type
 * @return casted new object
 */
#define obj_new( type )      __cast( obj_new( type ##Class ), type )

/**
 * @brief Dynamically cast an object to a class
 * @param obj class object
 * @param type class type to cast to
 * @return casted class, or null on failure
 */
#define cast_to( obj, type ) __cast( cast_to( __cast( obj, Object ), type ##Class ), type )


#endif
