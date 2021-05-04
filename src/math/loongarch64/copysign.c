#include <math.h>

#if __loongarch_fpr >= 64

double copysign(double x, double y)
{
	__asm__ ("fcopysign.d %0, %1, %2" : "=f"(x) : "f"(x), "f"(y));
	return x;
}

#else

#include "../copysign.c"

#endif
