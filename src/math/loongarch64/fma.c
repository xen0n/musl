#include <math.h>

#if __loongarch_fpr >= 64

double fma(double x, double y, double z)
{
	__asm__ ("fmadd.d %0, %1, %2, %3" : "=f"(x) : "f"(x), "f"(y), "f"(z));
	return x;
}

#else

#include "../fma.c"

#endif
