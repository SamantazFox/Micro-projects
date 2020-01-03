
#include "rng.hxx"
using namespace std;


/*
 * Random number generator initialization
*/

static mt19937 rngInit_32(void)
{
	mt19937 rng ( static_cast<mt19937::result_type> (time(nullptr)) );
	return rng;
}

static mt19937_64 rngInit_64(void)
{
	mt19937_64 rng ( static_cast<mt19937_64::result_type> (time(nullptr)) );
	return rng;
}


/*
 * Single number functions
*/

int32_t __stdcall randomInt32(int32_t min, int32_t max)
{
	mt19937 rng32 = rngInit_32();
	uniform_int_distribution<int32_t> distrib (min, max);
	return distrib(rng32);
}
int64_t __stdcall randomInt64(int64_t min, int64_t max)
{
	mt19937_64 rng64 = rngInit_64();
	uniform_int_distribution<int64_t> distrib (min, max);
	return distrib(rng64);
}


uint32_t __stdcall randomUInt32(uint32_t min, uint32_t max)
{
	mt19937 rng32 = rngInit_32();
	uniform_int_distribution<uint32_t> distrib (min, max);
	return distrib(rng32);

}
uint64_t __stdcall randomUInt64(uint64_t min, uint64_t max)
{
	mt19937_64 rng64 = rngInit_64();
	uniform_int_distribution<uint64_t> distrib (min, max);
	return distrib(rng64);
}


float __stdcall randomFloat(float min, float max)
{
	mt19937 rng32 = rngInit_32();
	uniform_real_distribution<float> distrib (min, max);
	return distrib(rng32);
}
double __stdcall randomDouble(double min, double max)
{
	mt19937_64 rng64 = rngInit_64();
	uniform_real_distribution<double> distrib (min, max);
	return distrib(rng64);
}



/*
 * Number arrays functions
*/

int32_t* __stdcall randomInt32Array(int32_t min, int32_t max, size_t len)
{
	// Initialize RNG
	mt19937 rng32 = rngInit_32();
	uniform_int_distribution<int32_t> distrib (min, max);

	// Allocate memory
	const constexpr size_t sizeBytes = sizeof(int32_t);
	int32_t* data = (int32_t*) malloc(len * sizeBytes);
	if (data == nullptr) return NULL;

	// Fill data and return to caller
	for (size_t i = 0; i < len; i ++) data[i] = (int32_t) distrib(rng32);
	return data;
}
int64_t* __stdcall randomInt64Array(int64_t min, int64_t max, size_t len)
{
	// Initialize RNG
	mt19937_64 rng64 = rngInit_64();
	uniform_int_distribution<int64_t> distrib (min, max);

	// Allocate memory
	const constexpr size_t sizeBytes = sizeof(int64_t);
	int64_t* data = (int64_t*) malloc(len * sizeBytes);
	if (data == nullptr) return NULL;

	// Fill data and return to caller
	for (size_t i = 0; i < len; i ++) data[i] = (int64_t) distrib(rng64);
	return data;
}


uint32_t* __stdcall randomUInt32Array(uint32_t min, uint32_t max, size_t len)
{
	// Initialize RNG
	mt19937 rng32 = rngInit_32();
	uniform_int_distribution<uint32_t> distrib (min, max);

	// Allocate memory
	const constexpr size_t sizeBytes = sizeof(uint32_t);
	uint32_t* data = (uint32_t*) malloc(len * sizeBytes);
	if (data == nullptr) return NULL;

	// Fill data and return to caller
	for (size_t i = 0; i < len; i ++) data[i] = (uint32_t) distrib(rng32);
	return data;
}
uint64_t* __stdcall randomUInt64Array(uint64_t min, uint64_t max, size_t len)
{
	// Initialize RNG
	mt19937_64 rng64 = rngInit_64();
	uniform_int_distribution<uint64_t> distrib (min, max);

	// Allocate memory
	const constexpr size_t sizeBytes = sizeof(uint64_t);
	uint64_t* data = (uint64_t*) malloc(len * sizeBytes);
	if (data == nullptr) return NULL;

	// Fill data and return to caller
	for (size_t i = 0; i < len; i ++) data[i] = (uint64_t) distrib(rng64);
	return data;
}


float* __stdcall randomFloatArray(float min, float max, size_t len)
{
	// Initialize RNG
	mt19937 rng32 = rngInit_32();
	uniform_real_distribution<float> distrib (min, max);

	// Allocate memory
	const constexpr size_t sizeBytes = sizeof(float);
	float* data = (float*) malloc(len * sizeBytes);
	if (data == nullptr) return NULL;

	// Fill data and return to caller
	for (size_t i = 0; i < len; i ++) data[i] = (float) distrib(rng32);
	return data;
}
double* __stdcall randomDoubleArray(double min, double max, size_t len)
{
	// Initialize RNG
	mt19937_64 rng64 = rngInit_64();
	uniform_real_distribution<double> distrib (min, max);

	// Allocate memory
	const constexpr size_t sizeBytes = sizeof(double);
	double* data = (double*) malloc(len * sizeBytes);
	if (data == nullptr) return NULL;

	// Fill data and return to caller
	for (size_t i = 0; i < len; i ++) data[i] = (double) distrib(rng64);
	return data;
}
