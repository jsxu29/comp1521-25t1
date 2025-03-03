main:
	# x - $t0
	li	$t0, 24 	# x = 24

while_cond:
	bge	$t0, 42, while_post

while_body:
	li	$v0, 1
	move	$a0, $t0
	syscall			# print x

	li	$v0, 11
	li	$a0, '\n'
	syscall			# print '\n'

while_step:
	addi 	$t0, $t0, 3	# x = x + 3
	j	while_cond
	
while_post:
	li	$v0, 0
	jr 	$ra