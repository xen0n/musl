#include <math.h>

#if __loongarch_fpr >= 64

double fabs(double x)
{
	__asm__ ("fabs.d %0, %1" : "=f"(x) : "f"(x));
	return x;
}

#else

#include "../fabs.c"

#endif
