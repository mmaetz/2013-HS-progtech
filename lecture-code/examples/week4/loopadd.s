	.file	"loopadd.C"
	.text
	.p2align 4,,15
	.globl	_Z3sumPdPKdS1_
	.type	_Z3sumPdPKdS1_, @function
_Z3sumPdPKdS1_:
.LFB0:
	.cfi_startproc
	leaq	16(%rdi), %rax
	leaq	16(%rdx), %rcx
	cmpq	%rax, %rdx
	setae	%r8b
	cmpq	%rcx, %rdi
	setae	%cl
	orb	%cl, %r8b
	je	.L2
	cmpq	%rax, %rsi
	leaq	16(%rsi), %rax
	setae	%cl
	cmpq	%rax, %rdi
	setae	%al
	orb	%al, %cl
	je	.L2
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L4:
	movsd	(%rsi,%rax), %xmm0
	movsd	(%rdx,%rax), %xmm1
	movhpd	8(%rsi,%rax), %xmm0
	movhpd	8(%rdx,%rax), %xmm1
	addpd	%xmm1, %xmm0
	movlpd	%xmm0, (%rdi,%rax)
	movhpd	%xmm0, 8(%rdi,%rax)
	addq	$16, %rax
	cmpq	$81920, %rax
	jne	.L4
	rep ret
.L2:
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L5:
	movsd	(%rsi,%rax), %xmm0
	addsd	(%rdx,%rax), %xmm0
	movsd	%xmm0, (%rdi,%rax)
	addq	$8, %rax
	cmpq	$81920, %rax
	jne	.L5
	rep ret
	.cfi_endproc
.LFE0:
	.size	_Z3sumPdPKdS1_, .-_Z3sumPdPKdS1_
	.ident	"GCC: (GNU) 4.8.2 20131219 (prerelease)"
	.section	.note.GNU-stack,"",@progbits
