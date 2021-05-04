.global __cp_begin
.hidden __cp_begin
.global __cp_end
.hidden __cp_end
.global __cp_cancel
.hidden __cp_cancel
.hidden __cancel
.global __syscall_cp_asm
.hidden __syscall_cp_asm
.type __syscall_cp_asm, %function
__syscall_cp_asm:
__cp_begin:
	ld.w $t0, $a0, 0
	bnez $t0, __cp_cancel

	move $t0, $a1
	move $a0, $a2
	move $a1, $a3
	move $a2, $a4
	move $a3, $a5
	move $a4, $a6
	move $a5, $a7
	ld.d $a6, $sp, 0
	move $a7, $t0
	syscall 0
__cp_end:
	jirl $zero, $ra, 0
__cp_cancel:
	b __cancel
