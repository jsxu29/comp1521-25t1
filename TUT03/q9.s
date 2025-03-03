# Assume that the variable s is implemented as register $t0
# and variable length is implemented as register $t1.
# the character '\0' can be represented by a value of zero.

str_length_init:
	la	$t0, string
	li	$t1, 0

str_length_cond:
	lb	$t2, ($t1)	# *s
	# if (*s == '\0') goto post
	beqz 	$t2, str_length_post

	addi	$t1, $t1, 1
	addi	$t0, $t0, 1
	j	str_length_cond

str_length_post:


   	.data
string:
   	.asciiz "...."
