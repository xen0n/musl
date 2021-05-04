.global __set_thread_area
.type   __set_thread_area, %function
__set_thread_area:
	move $tp, $a0
	li $a0, 0
	jirl $zero, $ra, 0
