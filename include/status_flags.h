#ifndef _H_STATUS_FLAGS
#define _H_STATUS_FLAGS
#include <stdint.h>
#include <stdbool.h>


typedef struct status_flags {
    bool temperature_data_available;
}status_flags_t;


status_flags_t* status_flags_get(void);
void status_flags_init(status_flags_t* status_flags);



#endif