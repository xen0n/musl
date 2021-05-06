#include <math.h>

#if __loongarch_fpr >= 32

float fabsf(float x)
{
	__asm__ ("fabs.s %0, %1" : "=f"(x) : "f"(x));
	return x;
}

#else

#include "../fabsf.c"

#endif
