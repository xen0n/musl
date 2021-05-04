.global dlsym
.hidden __dlsym
.type dlsym, %function
dlsym:
	move $a2, $ra
	b __dlsym
