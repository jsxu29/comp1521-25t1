.text

main: 
	# x - $t0 
	# y - $t1

	# set $v0 to be 4
	li	$v0, 4
	# set $a0 to be address of the string we want to print
	la	$a0, prompt_str
	syscall 	# printf("Enter a number: "); 

	li	$v0, 5
	syscall 	# scanf("%d", &x);
	# $v0 stores x

	mul	$t1, $v0, $v0 	# y = x * x;

	li 	$v0, 1
	# set $a0 to be y
	move 	$a0, $t1
	syscall

	li 	$v0, 11
	# set $a to be \n
	li	$a0, '\n'
	syscall

	li	$v0, 0
	jr 	$ra

.data
	prompt_str: .asciiz "Enter a number: "
