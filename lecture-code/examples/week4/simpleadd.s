	.file	"simpleadd.C"
	.text
	.p2align 4,,15
	.globl	_Z3sumdd
	.type	_Z3sumdd, @function
_Z3sumdd:
.LFB0:
	.cfi_startproc
	addsd	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE0:
	.size	_Z3sumdd, .-_Z3sumdd
	.ident	"GCC: (GNU) 4.8.2 20131219 (prerelease)"
	.section	.note.GNU-stack,"",@progbits
