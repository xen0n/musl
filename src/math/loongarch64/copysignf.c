#include <math.h>

#if __loongarch_fpr >= 32

float copysignf(float x, float y)
{
	__asm__ ("fcopysign.s %0, %1, %2" : "=f"(x) : "f"(x), "f"(y));
	return x;
}

#else

#include "../copysignf.c"

#endif
