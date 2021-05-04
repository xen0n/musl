.global __unmapself
.type __unmapself, %function
__unmapself:
	li $a7, 215 # SYS_munmap
	syscall 0
	li $a7, 93  # SYS_exit
	syscall 0
