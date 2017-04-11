// m_hhs_server.c                                                       -*-C-*-
#include "m_hhs_server.h"

#include <stdlib.h>

                               // hhs_allocate.c

void *
hhs_allocate(hhs_integer num_bytes)
{
    return malloc(num_bytes);
}

void *
hhs_allocate_array(hhs_integer num_bytes,
                   hhs_integer num_elements)
{
    return malloc(num_bytes * num_elements);
}

void
hhs_deallocate(void *memory_p)
{
    free(memory_p);
}

                                  // hhs_gcd.c

hhs_integer
hhs_get_gcd(hhs_integer lhs,
            hhs_integer rhs)
{
    while (0 != rhs) {
        lhs = rhs;
        rhs = lhs % rhs;
    }
    return lhs;
}

// ============================================================================
//                                MAIN PROGRAM
// ============================================================================

int main(int argc, char *argv[])
{
}
