#include <math.h>

#if __loongarch_fpr >= 64

double sqrt(double x)
{
	__asm__ ("fsqrt.d %0, %1" : "=f"(x) : "f"(x));
	return x;
}

#else

#include "../sqrt.c"

#endif
