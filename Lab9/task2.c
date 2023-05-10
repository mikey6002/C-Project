int poly(int x, int a, int b, int c) {
    
    return a*(x*x) + b*x + c;
}

.global poly

poly:
 
	movl	%edi, %eax	# x = 2
	imull	%eax, %eax	# 2 * 2 = 4
	movl	%esi, %eax	# a = 2
	imull	%eax, %eax	# 4 * 2 = 8
	movl	%ebx, %eax	# b = 3
	addl	%eax, %eax	# 8 + 3 = 11
	movl	%ecx, %eax	# c = 5
	addl	%eax, %eax	# 11 + 5 = 16
	ret

.global main

main:

       movl #2, %eax
       movl #3, %ebx
       movl #5, %ecx
       movl #2, %edx
       call poly
       movl %eax, result
       ret