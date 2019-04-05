	.file	"arr1.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movl	%edi, -100(%rbp)
	movq	%rsi, -112(%rbp)
	movq	%fs:40, %rbx
	movq	%rbx, -56(%rbp)
	xorl	%ebx, %ebx
	movq	%rsp, %rcx
	movq	%rcx, %r15
	movl	-100(%rbp), %ecx
	movl	-100(%rbp), %esi
	movslq	%ecx, %rdi
	subq	$1, %rdi
	movq	%rdi, -80(%rbp)
	movslq	%ecx, %rdi
	movq	%rdi, -128(%rbp)
	movq	$0, -120(%rbp)
	movslq	%ecx, %rdi
	leaq	0(,%rdi,4), %rbx
	movslq	%esi, %rdi
	subq	$1, %rdi
	movq	%rdi, -72(%rbp)
	movslq	%ecx, %rdi
	movq	%rdi, %r12
	movl	$0, %r13d
	movslq	%esi, %rdi
	movq	%rdi, %rax
	movl	$0, %edx
	movq	%r13, %r14
	imulq	%rax, %r14
	movq	%rdx, %rdi
	imulq	%r12, %rdi
	addq	%r14, %rdi
	mulq	%r12
	addq	%rdx, %rdi
	movq	%rdi, %rdx
	movslq	%ecx, %rax
	movq	%rax, %r10
	movl	$0, %r11d
	movslq	%esi, %rax
	movq	%rax, %r8
	movl	$0, %r9d
	movq	%r11, %rdx
	imulq	%r8, %rdx
	movq	%r9, %rax
	imulq	%r10, %rax
	leaq	(%rdx,%rax), %rdi
	movq	%r10, %rax
	mulq	%r8
	addq	%rdx, %rdi
	movq	%rdi, %rdx
	movslq	%ecx, %rdx
	movslq	%esi, %rax
	imulq	%rdx, %rax
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ecx
	movl	$0, %edx
	divq	%rcx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -64(%rbp)
	movl	$0, -84(%rbp)
	jmp	.L2
.L5:
	movl	$0, -88(%rbp)
	jmp	.L3
.L4:
	call	random@PLT
	movq	%rbx, %rsi
	shrq	$2, %rsi
	movl	%eax, %edi
	movq	-64(%rbp), %rax
	movl	-88(%rbp), %edx
	movslq	%edx, %rcx
	movl	-84(%rbp), %edx
	movslq	%edx, %rdx
	imulq	%rsi, %rdx
	addq	%rcx, %rdx
	movl	%edi, (%rax,%rdx,4)
	addl	$1, -88(%rbp)
.L3:
	movl	-88(%rbp), %eax
	cmpl	-100(%rbp), %eax
	jl	.L4
	addl	$1, -84(%rbp)
.L2:
	movl	-84(%rbp), %eax
	cmpl	-100(%rbp), %eax
	jl	.L5
	movl	-100(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -92(%rbp)
	jmp	.L6
.L9:
	movl	-100(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -96(%rbp)
	jmp	.L7
.L8:
	movq	%rbx, %rsi
	shrq	$2, %rsi
	movq	-64(%rbp), %rax
	movl	-96(%rbp), %edx
	movslq	%edx, %rcx
	movl	-92(%rbp), %edx
	movslq	%edx, %rdx
	imulq	%rsi, %rdx
	addq	%rcx, %rdx
	movl	(%rax,%rdx,4), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	subl	$1, -96(%rbp)
.L7:
	cmpl	$0, -96(%rbp)
	jns	.L8
	subl	$1, -92(%rbp)
.L6:
	cmpl	$0, -92(%rbp)
	jns	.L9
	movl	$0, %eax
	movq	%r15, %rsp
	movq	-56(%rbp), %rbx
	xorq	%fs:40, %rbx
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
