main:
	# set $v0 to be 4
	li	$v0, 4
	# set $a0 to be address of the string we want to print
	la	$a0, prompt_str
	syscall 	# printf("Enter a number: "); 

	li	$v0, 5
	syscall 	# scanf("%d", &x);
	# $v0 stores x

	ble	$v0, 100, small_big
	bge	$v0, 1000, small_big 	# if (x >= 1000) goto small_big;

	# store message in $a0
	la	$a0, medium_str 	# char *message = "medium\n";	

	b	print

small_big:
	la	$a0, small_big_str

print:
	li	$v0, 4
	syscall


	li 	$v0, 0
	jr 	$ra

	

.data
	prompt_str: .asciiz "Enter a number: "
	medium_str: .asciiz "medium\n"
	small_big_str: .asciiz "small/big\n"
