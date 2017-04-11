// m_hhs_server.h                                                       -*-C-*-
#ifndef INCLUDED_M_HHS_SERVER
#define INCLUDED_M_HHS_SERVER

#ifndef INCLUDED_STDINT
#include <stdint.h>
#endif

                                 // hhs_byte.h

typedef uint8_t hhs_byte;

                                // hhs_integer.h

typedef int8_t  hhs_integer8;
typedef int16_t hhs_integer16;
typedef int32_t hhs_integer32;
typedef int64_t hhs_integer64;
typedef int64_t hhs_integer;

                                // hhs_natural.h

typedef uint8_t  hhs_natural8;
typedef uint16_t hhs_natural16;
typedef uint32_t hhs_natural32;
typedef uint64_t hhs_natural64;
typedef uint64_t hhs_natural;

                                 // hhs_real.h

typedef float  hhs_real32;
typedef double hhs_real64;
typedef double hhs_real;

                                // hhs_uintptr.h

typedef uintptr_t hhs_uintptr;

                               // hhs_allocate.h

#define Hhs_allocate(type) \
    (type *)hhs_allocate(sizeof(type))

#define Hhs_allocate_array(type, num_elements) \
    (type *)hhs_allocate_array(sizeof(type), num_elements)

#define Hhs_deallocate(object) \
    hhs_deallocate(object);

void *
hhs_allocate(hhs_integer num_bytes);

void *
hhs_allocate_array(hhs_integer num_bytes,
                   hhs_integer num_elements);

void
hhs_deallocate(void *memory_p);

                            // hhs_integer_vector.h

struct hhs_integer_vector {
    hhs_integer *d_begin_p;
    hhs_integer *d_end_p;
};

// CREATORS
void
hhs_integer_vector_init(struct hhs_integer_vector *vector,
                        hhs_integer                num_elements);

void
hhs_integer_vector_init_with_data(struct hhs_integer_vector *vector,
                                  const hhs_integer          elements[],
                                  hhs_integer                num_elements);

void
hhs_integer_vector_copy(struct hhs_integer_vector       *destination,
                        const struct hhs_integer_vector *source);

void
hhs_integer_vector_destroy(struct hhs_integer_vector *vector);

// MANIPULATORS
void
hhs_integer_vector_update(struct hhs_integer_vector *vector,
                          hhs_integer                index,
                          hhs_integer                value);

// ACCESSORS
hhs_integer
hhs_integer_vector_num_elements(const struct hhs_integer_vector *vector);

hhs_integer
hhs_integer_vector_access(const struct hhs_integer_vector *vector);

                            // hhs_integer_matrix.h

struct hhs_integer_matrix {
    hhs_integer *d_begin_p;
    hhs_integer *d_end_p;
    hhs_integer  d_num_columns;
    hhs_integer  d_num_rows;
};

// CREATORS
void
hhs_integer_matrix_init(struct hhs_integer_matrix *matrix,
                        hhs_integer                num_columns,
                        hhs_integer                num_rows);

void
hhs_integer_matrix_init_with_data(struct hhs_integer_matrix *matrix,
                                  const hhs_integer         *elements[],
                                  hhs_integer                num_columns,
                                  hhs_integer                num_rows);

void
hhs_integer_matrix_destroy(struct hhs_integer_matrix *matrix);

// MANIPULATORS

// ACCESSORS

                                  // hhs_gcd.h

hhs_integer
hhs_get_gcd(hhs_integer lhs,
            hhs_integer rhs);

void
hhs_integer_vector_row_reduce(hhs_integer_vector                 *output,
                              const hhs_integer_vector           *lhs,
                              const hhs_integer_vector *restrict  rhs,
                              hhs_integer                         pivot);

                              // hhs_constraint.h

struct hhs_constraint {
    struct hhs_integer_vector d_coefficients;
    struct hhs_integer_vector d_variables;
    hhs_integer               d_lhs;
};

// ============================================================================
//                               IMPLEMENTATION
// ============================================================================

                            // hhs_integer_vector.c

// CREATORS
inline void
hhs_integer_vector_init(struct hhs_integer_vector *vector,
                        hhs_integer                num_elements)
{
    if (0 == num_elements) {
        vector->d_begin_p = 0;
        vector->d_end_p   = 0;
        return;                                                       // RETURN
    }

    vector->d_begin_p = Hhs_allocate_array(hhs_integer, num_elements);
    vector->d_end_p   = vector->d_begin_p + num_elements;
}

inline void
hhs_integer_vector_destroy(struct hhs_integer_vector *vector)
{
    Hhs_deallocate(vector->d_begin_p);

    vector->d_begin_p = 0;
    vector->d_end_p   = 0;
}

// MANIPULATORS
inline void
hhs_integer_vector_update(struct hhs_integer_vector *vector,
                          hhs_integer                index,
                          hhs_integer                value)
{
    vector->d_begin_p[index] = value;
}

// ACCESSORS
inline hhs_integer
hhs_integer_vector_num_elements(const struct hhs_integer_vector *vector)
{
    return vector->d_end_p - vector->d_begin_p;
}

inline hhs_integer
hhs_integer_vector_access(const struct hhs_integer_vector *vector,
                          hhs_integer                      index)
{
    return vector->d_begin_p[index];
}

#endif
