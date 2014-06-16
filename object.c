
#include <string.h>

#include "object.h"

#undef obj_new

/**
 * @brief Delete the object, calling the destructors
 * @param obj object to delete
 */
void obj_delete( void *obj ) {
  if ( obj != 0x00 ) {
    Object *object = ( Object * ) obj;

    WALKIT( object, {
        if ( object->dtor != 0x00 ) {
          object->dtor( object );
        }
      } );

    free( object );
  }
}

/**
 * @brief Create a new object, and call the constructors
 * @param type object type
 * @return constructed object or null on failure
 */
void *obj_new( void *type ) {
  Object *object = ( Object * ) calloc( 1, __cast( type, Object )->size );

  if ( object != 0x00 ) {
    memcpy( object, type, __cast( type, Object )->size );

    WALKIT( object, {
        if ( object->ctor != 0x00 ) {
          if ( object->ctor( object ) == 0x00 ) {
            obj_delete( object );

            return 0x00;
          }
        }
      } );
  }

  return object;
}
