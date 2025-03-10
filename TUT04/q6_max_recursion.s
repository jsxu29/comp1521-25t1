max:
	# Frame:    [$ra, $s0]    
	# Uses:     [$ra, $s0, $v0, $a0, $a1, $t1]
	# Clobbers: [$ra, $v0, $a0, $a1, $t1]
	#
	# Locals:           
	#   - $s0: first_element 
	#   - $t1: max_so_far
	#   - $a0: 
	#   - $a1:
	#   - $v0: ...
	#
	# Structure:       
	#   max
	#   -> [prologue]
	#       -> body
	#	    -> base_case
	# 	    -> recursive_case
	# 		-> first_is_max
	#		-> first_is_not_max
	#   -> [epilogue]

max__prologue:
	begin
	push	$ra
	push	$s0		

max__body:
	lw	$s0, ($a0)			# $s0 = first_element

	beq	$a1, 1, max__base_case		# if length == 1, goto base_case
	j	max__recursive_case		# else goto recursive_case

max__base_case:
	move	$v0, $s0
	j	max__epilogue

max__recursive_case:
	addi	$a0, $a0, 4			# &array[1]
	addi	$a1, $a1, -1			# length - 1
	jal 	max				# $v0 = max_so_far = max(&array[1], length - 1)

	bgt	$s0, $v0, max__first_is_max	# if (first_element > max_so_far), goto first_is_max
	j	max__first_is_not_max

max__first_is_max:
	move	$v0, $s0			# max_so_far = first_element

max__first_is_not_max: 				# $v0 = max_so_far

max__epilogue:
	pop 	$s0
	pop	$ra
	end

	jr	$ra

# some simple test code which calls max
main:
main__prologue:
	push	$ra

main__body:
	la	$a0, array
	li	$a1, 10
	jal	max			# result = max(array, 10)

	move	$a0, $v0
	li	$v0, 1			# syscall 1: print_int
	syscall				# printf("%d", result)

	li	$a0, '\n'
	li	$v0, 11			# syscall 11: print_char
	syscall				# printf("%c", '\n');

	li	$v0, 0

main__epilogue:
	pop	$ra
	jr	$ra			# return 0;


.data
array:
	.word 1, 2, 3, 4, 5, 6, 4, 3, 2, 1
	