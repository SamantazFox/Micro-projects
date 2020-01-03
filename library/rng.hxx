
#ifndef _RNG_UTILS_H_
#define _RNG_UTILS_H_


/*
 * Allow header to be included in C and C++
*/

#ifdef __cplusplus
 #include <random>
 #include <ctime>
#else
 #include <stdint.h>
#endif


/*
 * Redefine __stdcall for non-win builds
*/

#ifndef _WIN32
#define __stdcall
#endif


/*
 * Prototypes
*/

#ifdef __cplusplus
extern "C"
{
#endif

extern int32_t  __stdcall randomInt32 (int32_t  min, int32_t  max);
extern int64_t  __stdcall randomInt64 (int64_t  min, int64_t  max);
extern uint32_t __stdcall randomUInt32(uint32_t min, uint32_t max);
extern uint64_t __stdcall randomUInt64(uint64_t min, uint64_t max);
extern float    __stdcall randomFloat (float    min, float    max);
extern double   __stdcall randomDouble(double   min, double   max);

extern int32_t*  __stdcall randomInt32Array (int32_t  min, int32_t  max, size_t len);
extern int64_t*  __stdcall randomInt64Array (int64_t  min, int64_t  max, size_t len);
extern uint32_t* __stdcall randomUInt32Array(uint32_t min, uint32_t max, size_t len);
extern uint64_t* __stdcall randomUInt64Array(uint64_t min, uint64_t max, size_t len);
extern float*    __stdcall randomFloatArray (float    min, float    max, size_t len);
extern double*   __stdcall randomDoubleArray(double   min, double   max, size_t len);

#ifdef __cplusplus
}
#endif


#endif  /* !_RNG_UTILS_H_ */
