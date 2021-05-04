#if defined __loongarch_soft_float
#define LOONGARCH_FP_SUFFIX "-sf"
#elif defined __loongarch_hard_float
#define LOONGARCH_FP_SUFFIX ""
#endif

#define LDSO_ARCH "loongarch64" LOONGARCH_FP_SUFFIX

#define TPOFF_K 0

#define REL_SYMBOLIC    R_LARCH_64
#define REL_PLT         R_LARCH_JUMP_SLOT
#define REL_RELATIVE    R_LARCH_RELATIVE
#define REL_COPY        R_LARCH_COPY
#define REL_DTPMOD      R_LARCH_TLS_DTPMOD64
#define REL_DTPOFF      R_LARCH_TLS_DTPREL64
#define REL_TPOFF       R_LARCH_TLS_TPREL64

#define CRTJMP(pc,sp) __asm__ __volatile__( \
	"move $sp, %1 ; jirl $zero, %0, 0" : : "r"(pc), "r"(sp) : "memory" )
