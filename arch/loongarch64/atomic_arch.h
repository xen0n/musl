#define a_barrier a_barrier
static inline void a_barrier()
{
	__asm__ __volatile__ ("dbar 0" : : : "memory");
}

#define a_ll a_ll
static inline int a_ll(volatile int *p)
{
	int v;
	__asm__ __volatile__ (
		"ll.w %0, %1"
		: "=r"(v) : "m"(*p));
	return v;
}

#define a_sc a_sc
static inline int a_sc(volatile int *p, int v)
{
	int r;
	__asm__ __volatile__ (
		"sc.w %0, %1"
		: "=r"(r), "=m"(*p) : "0"(v) : "memory");
	return r;
}

#define a_ll_p a_ll_p
static inline void *a_ll_p(volatile void *p)
{
	void *v;
	__asm__ __volatile__ (
		"ll.d %0, %1"
		: "=r"(v) : "m"(*(void *volatile *)p));
	return v;
}

#define a_sc_p a_sc_p
static inline int a_sc_p(volatile void *p, void *v)
{
	long r;
	__asm__ __volatile__ (
		"sc.d %0, %1"
		: "=r"(r), "=m"(*(void *volatile *)p) : "0"(v) : "memory");
	return r;
}

#define a_ctz_64 a_ctz_64
static inline int a_ctz_64(uint64_t x)
{
	__asm__("ctz.d %0, %1" : "=r"(x) : "r"(x));
	return x;
}

#define a_clz_64 a_clz_64
static inline int a_clz_64(uint64_t x)
{
	__asm__("clz.d %0, %1" : "=r"(x) : "r"(x));
	return x;
}
