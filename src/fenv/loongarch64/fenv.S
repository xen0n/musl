#ifdef __loongarch_hard_float

.global feclearexcept
.type feclearexcept, %function
feclearexcept:
	andi        $a0, $a0, 0x1f
	movfcsr2gr  $t0, $r1
	orn         $t0, $t0, $a0
	movgr2fcsr  $r1, $t0
	li          $a0, 0
	jirl        $zero, $ra, 0

.global feraiseexcept
.type feraiseexcept, %function
feraiseexcept:
	andi        $a0, $a0, 0x1f
	movfcsr2gr  $t0, $r1
	or          $t0, $t0, $a0
	movgr2fcsr  $r1, $t0
	li          $a0, 0
	jirl        $zero, $ra, 0

.global fetestexcept
.type fetestexcept, %function
fetestexcept:
	andi        $a0, $a0, 0x1f
	movfcsr2gr  $t0, $r1
	and         $a0, $t0, $a0
	jirl        $zero, $ra, 0

.global fegetround
.type fegetround, %function
fegetround:
	movfcsr2gr  $a0, $r3
	bstrpick.w  $a0, $a0, 9, 8
	jirl        $zero, $ra, 0

.global __fesetround
.type __fesetround, %function
__fesetround:
	andi        $a0, $a0, 0x3
	slli.w      $a0, $a0, 8
	movgr2fcsr  $r3, $a0
	li          $a0, 0
	jirl        $zero, $ra, 0

.global fegetenv
.type fegetenv, %function
fegetenv:
	movfcsr2gr  $t0, $r0
	st.w        $t0, $a0, 0
	li          $a0, 0
	jirl        $zero, $ra, 0

.global fesetenv
.type fesetenv, %function
fesetenv:
	li          $t1, -1
	li          $t0, 0
	beq         $a0, $t1, 1f
	ld.w        $t0, $a0, 0
1:	movgr2fcsr  $r0, $t0
	li          $a0, 0
	jirl        $zero, $ra, 0

#endif
