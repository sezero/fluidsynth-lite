
#ifndef _FLUID_ATOMIC_H
#define _FLUID_ATOMIC_H

#include <stdbool.h>

#ifndef STATIC_ASSERT
#if __STDC_VERSION__ >= 201112L
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT(expr, msg) typedef char __static_assertion_ ## __COUNTER__[(expr) ? 1 : -1]
#endif
#endif //STATIC_ASSERT

#if defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4) || defined(__riscos__)

typedef struct {
    volatile int value;
} atomic_int;
typedef struct {
    volatile unsigned value;
} atomic_uint;
typedef struct {
    volatile float value;
} atomic_float;

#define fluid_atomic_int_add(atomic, val) __extension__ ({            \
            STATIC_ASSERT(sizeof((atomic)->value) == sizeof(int),     \
                          "Atomic must be the size of an int");       \
            __sync_fetch_and_add(&(atomic)->value, (val));})

#define fluid_atomic_int_get(atomic) __extension__ ({             \
            STATIC_ASSERT(sizeof((atomic)->value) == sizeof(int), \
                          "Atomic must be the size of an int");   \
            __sync_synchronize();                                 \
            (atomic)->value;})

#define fluid_atomic_int_set(atomic, newval) __extension__ ({         \
                STATIC_ASSERT(sizeof((atomic)->value) == sizeof(int), \
                              "Atomic must be the size of an int");   \
                (atomic)->value = (newval);                           \
                __sync_synchronize();})

#define fluid_atomic_int_inc(atomic) __extension__ ({             \
            STATIC_ASSERT(sizeof((atomic)->value) == sizeof(int), \
                          "Atomic must be the size of an int");   \
            __sync_synchronize();                                 \
            __sync_fetch_and_add(&(atomic)->value, 1);})

#define fluid_atomic_float_get(atomic) __extension__ ({   \
  STATIC_ASSERT(sizeof((atomic)->value) == sizeof(float), \
                "Atomic must be the size of a float");    \
  __sync_synchronize();                                   \
  (atomic)->value;})

#define fluid_atomic_float_set(atomic, val) __extension__ ({  \
      STATIC_ASSERT(sizeof((atomic)->value) == sizeof(float), \
                    "Atomic must be the size of a float");    \
      (atomic)->value = (val);                                \
      __sync_synchronize();})

#elif defined(__GNUC__)

typedef struct {
    volatile int value;
} atomic_int;
typedef struct {
    volatile unsigned value;
} atomic_uint;
typedef struct {
    volatile float value;
} atomic_float;

#if defined(__i386__) || defined(__x86_64__)
static inline int fluid_atomic_float_get(atomic_float *atomic) {
    return atomic->value;
}
static inline int fluid_atomic_int_get(atomic_int *atomic) {
    return atomic->value;
}
static inline int fluid_atomic_int_set(atomic_int *atomic, int val) {
    int ret;
    __asm__ __volatile__("lock; xchgl %0,(%1)"
                         : "=r" (ret) : "r" (&atomic->value), "0" (val) : "memory");
    return ret;
}
static inline int fluid_atomic_int_add(atomic_int *atomic, int val) {
    int ret;
    __asm__ __volatile__("lock; xaddl %0,(%1)"
                         : "=r" (ret) : "r" (&atomic->value), "0" (val) : "memory");
    return ret + val;
}
static inline int fluid_atomic_int_inc(atomic_int *atomic) {
    return fluid_atomic_int_add(atomic, 1);
}
#else
#error define atomics for your cpu
#endif
static inline void
fluid_atomic_float_set(atomic_float *atomic, float val) {
    union { float f; int i; } u;
    u.f = val;
    fluid_atomic_int_set((atomic_int *)atomic, u.i);
}

#elif defined(__WATCOMC__) && defined(__386__)
typedef volatile int atomic_int;
typedef volatile unsigned int atomic_uint;
typedef volatile float atomic_float;

extern __inline int _xadd_watcom(volatile int *a, int v);
extern __inline int _xchg_watcom(volatile int *a, int v);
#pragma aux _xadd_watcom = \
  "lock xadd [ecx], eax" \
  parm [ecx] [eax] \
  value [eax] \
  modify exact [eax];

#pragma aux _xchg_watcom = \
  "lock xchg [ecx], eax" \
  parm [ecx] [eax] \
  value [eax] \
  modify exact [eax];

static __inline int fluid_atomic_int_add(atomic_int *i, int val) {
  int r = _xadd_watcom(i,val);
  return r + val;
}
#define fluid_atomic_int_inc(atomic) fluid_atomic_int_add((atomic), 1)
#define fluid_atomic_int_set(atomic, val) _xchg_watcom((atomic), (val))
#define fluid_atomic_int_get(atomic) (*(int*)(atomic))
#define fluid_atomic_float_get(atomic) (*(atomic))
static __inline void
fluid_atomic_float_set(atomic_float *atomic, float val) {
    int ival = *(int *)&val;
    _xchg_watcom((volatile int *)atomic, ival);
}

#elif defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

typedef volatile LONG atomic_int;
typedef volatile ULONG atomic_uint;
typedef volatile LONG atomic_float;

#define fluid_atomic_int_inc(atomic) InterlockedIncrement((atomic))
#define fluid_atomic_int_add(atomic, val) InterlockedAdd((atomic), (val))
#define fluid_atomic_int_get(atomic) (*(LONG*)(atomic))
#define fluid_atomic_int_set(atomic, val) InterlockedExchange((atomic), (val))

#define fluid_atomic_float_get(atomic) (*(FLOAT*)(atomic))

static inline float
fluid_atomic_float_set(atomic_float *atomic, float val)
{
    LONG ival = *(LONG*)&val;
    LONG rval = InterlockedExchange(atomic, ival);
    return *(float*)&rval;
}

#endif

#endif /* _FLUID_ATOMIC_H */
