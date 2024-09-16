#include "status_flags.h"



status_flags_t* status_flags_get(void)
{
    static status_flags_t instance;
    return &instance;
}

void status_flags_init(status_flags_t* status_flags)
{
    status_flags_t* pstatus_flags = status_flags_get();
    pstatus_flags->temperature_data_available = false;
}
