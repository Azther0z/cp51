# COMP SYS ARCH: Assignment 1
## 1. Instruction Analysis

```c
int max1(int a, int b) {
	return (a > b) ? a : b;
}
int max2(int a, int b) {
	int isaGTb = a > b;
	int max;
	if (isaGTb)
		max = a;
	else
		max = b;
	return max;
}
```

```asm
	.file	"max.c"
	.text
	.globl	max1
	.type	max1, @function
max1:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	cmpl	%eax, %edx
	cmovge	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	max1, .-max1
	.globl	max2
	.type	max2, @function
max2:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	-20(%rbp), %eax
	cmpl	-24(%rbp), %eax
	setg	%al
	movzbl	%al, %eax
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	je	.L4
	movl	-20(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.L5
.L4:
	movl	-24(%rbp), %eax
	movl	%eax, -8(%rbp)
.L5:
	movl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	max2, .-max2
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
```

> What does the code hint about the kind of instruction set? (e.g. Accumulator, Register Memory, Memory Memory, Register Register) Please justify your answer. 

The instruction set is both Register-Register and Register-Memory. Hinted from

- `cmpl	%eax, %edx` receive 2 registers address as operands, therefore it is Register-Register
- `cmpl	-24(%rbp), %eax` receive `%eax` register and `-24(%rbp)` memory address as operands, therefore it also is Register-Memory

> Can you tell whether the architecture is either Restricted Alignment or Unrestricted Alignment? Please explain how you came up with your answer.

It used Restricted Alignment. The evidence is that it relied on relative displacement of memory address, which required precise data placement, therefore it is Restricted Alignment. For example,

- `movl	%edi, -4(%rbp)`
- `cmpl	$0, -4(%rbp)`

> Create a new function (e.g. testMax) to call max1. Generate new assembly code. What does the result suggest regarding the register saving (caller save vs. callee save)? Please provide your analysis.

```asm
	.file	"testMax.c"
	.text
	.globl	max1
	.type	max1, @function
max1:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	cmpl	%eax, %edx
	cmovge	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	max1, .-max1
	.globl	max2
	.type	max2, @function
max2:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	-20(%rbp), %eax
	cmpl	-24(%rbp), %eax
	setg	%al
	movzbl	%al, %eax
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	je	.L4
	movl	-20(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.L5
.L4:
	movl	-24(%rbp), %eax
	movl	%eax, -8(%rbp)
.L5:
	movl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	max2, .-max2
	.globl	testMax
	.type	testMax, @function
testMax:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$8, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	max1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	testMax, .-testMax
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
```

Let's look at where `push` or `pop` occured. 

- In `testMax` function, it explicitly saved only `pushq %rbp` once before `call max1`, while other registers weren't saved. This action was done as callee when it called by another function.
- In `max1` function, it explicitly saved and restored a register through `pushq %rbp` and `popq %rbp`. This action was done as callee saved when it called by `testMax`.
Therefore, this code is likely to perform Callee-Save.

> How do the arguments be passed and the return value returned from a function? Please explain the code. 

From `movl	%edx, %esi; movl %eax, %edi` in `testMax` and `movl	%edi, -4(%rbp); movl %esi, -8(%rbp)` in `max1`, argument value of `max1` a and b were passed through `%esi` and `%edi`. While return value was returned using `%eax` according to `movl -4(%rbp), %eax; cmpl %eax, %edx; cmovge %edx, %eax`


> Find the part of code (snippet) that does comparison and conditional branch. Explain how it works.

- In `max1`, `cmpl` set the flag to the result of comparison between `%eax` and `edx`, then `cmovge` read the flag set before and decide whether to move `%edx` to `%eax` according to the flag read.
- In `max2`, `cmpl` set the flag like before. `je` read the flag and decide whether to jump to `.L4`. 



> If max.c is compiled with optimization turned on (using “gcc -O2 -S max.c”), what are the differences that you may observe from the result (as compared to that without optimization). Please provide your analysis.

It shortened the argument passing step in both functions and it utilized `cmovge` in `max2`. The shorter instruction length might help the code faster.

> Please estimate the CPU Time required by the max1 function (using the equation CPI=ICxCPIxTc). If possible, create a main function to call max1 and use the time command to measure the performance. Compare the measure to your estimation. What do you think are the factors that cause the difference? Please provide your analysis. (You may find references online regarding the CPI of each instruction.)

```c
int max1(int a, int b) {
	return (a > b) ? a : b;
}
int main() {
	int a = 0, b = 1;
	int result;
	for (int i = 0; i < 1e8; i++) {
		result = max1(a, b);
	}
	return 1;
}
```

Let's run main for 1e8 times and for convenience, let's assume that we have $IC=10$ and $CPI=1$. My device has $T_c=\frac{1}{3.4\times10^9}$ second. Therefore, $CPU=10\times1\times\frac{1}{3.4\times10^9}\times10^8=0.294$ second. The following is the result from running 5 times.
```
real    0m4.770s
user    0m0.981s
sys     0m0.003s

real    0m3.048s
user    0m0.985s
sys     0m0.002s

real    0m2.119s
user    0m1.010s
sys     0m0.005s

real    0m1.967s
user    0m0.964s
sys     0m0.003s

real    0m2.632s
user    0m0.959s
sys     0m0.003s
```
Average actual CPU time = (total user + total sys)/5 = 0.983 second, which is higher than the esimation.

The reason it differed might be function call overhead, inaccurate assumption about IC and CPI, and the CPU running other task simultaneously. 

## 2. Optimization

```c
#include <stdio.h>
long fibo(long a) {
	if (a <= 0L) {
		return 0L;
	}
	if (a == 1L) {
		return 1L;
	}
	return fibo(a - 1L) + fibo(a - 2L);
}
int main (int argc, char *argv[]) {
	for (long i = 1L; i < 45L; i++) {
		long f = fibo(i);
		printf("fibo of %ld is %ld\n", i, f);
	}
}
```

> We will use simple fibonacci calculation as a benchmark. Please measure the execution time (using the time command) of this given program when compiling with optimization level 0 (no optimization), level 1, level 2 and level 3. (Note that some compilers do similar optimization for all level 1, level 2 and level 3. If that is the case, you will see no difference after level 1.) You may want to run each program a few times and use the average value as a result.

- level 0: 55.683
- level 1: 32.126
- level 2: 12.901
- level 3: 11.939

## 3. Analysis

> As suggested by the results in Exercise 2, what kinds of optimization are used by the compiler in each level in order to make the program faster? To answer this question, use “gcc -S” to generate the assembly code for each level (e.g. “gcc -S -O2 fibo.c”) and use this result as a basis for your analysis. (Depending on your version of the compiler, the result may vary.)

level 0: result the same to when no optimization specified

```asm
	.file	"fibo.c"
	.text
	.globl	fibo
	.type	fibo, @function
fibo:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jg	.L2
	movl	$0, %eax
	jmp	.L3
.L2:
	cmpq	$1, -24(%rbp)
	jne	.L4
	movl	$1, %eax
	jmp	.L3
.L4:
	movq	-24(%rbp), %rax
	subq	$1, %rax
	movq	%rax, %rdi
	call	fibo
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	subq	$2, %rax
	movq	%rax, %rdi
	call	fibo
	addq	%rbx, %rax
.L3:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	fibo, .-fibo
	.section	.rodata
.LC0:
	.string	"fibo of %ld is %ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	$1, -16(%rbp)
	jmp	.L6
.L7:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	fibo
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addq	$1, -16(%rbp)
.L6:
	cmpq	$44, -16(%rbp)
	jle	.L7
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
```

level 1: rearrange position of branch condition so less branching step, avoid unnecessary memory instruction

```asm
	.file	"fibo.c"
	.text
	.globl	fibo
	.type	fibo, @function
fibo:
.LFB23:
	.cfi_startproc
	endbr64
	movl	$0, %eax
	testq	%rdi, %rdi
	jle	.L6
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbx
	movq	%rdi, %rax
	cmpq	$1, %rdi
	je	.L1
	leaq	-1(%rdi), %rdi
	call	fibo
	movq	%rax, %rbp
	leaq	-2(%rbx), %rdi
	call	fibo
	addq	%rbp, %rax
.L1:
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L6:
	.cfi_restore 3
	.cfi_restore 6
	ret
	.cfi_endproc
.LFE23:
	.size	fibo, .-fibo
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"fibo of %ld is %ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movl	$1, %ebx
	leaq	.LC0(%rip), %rbp
.L10:
	movq	%rbx, %rdi
	call	fibo
	movq	%rax, %rcx
	movq	%rbx, %rdx
	movq	%rbp, %rsi
	movl	$2, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	addq	$1, %rbx
	cmpq	$45, %rbx
	jne	.L10
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
```


level 2: less recursive level by copy-pasting the whole function multiple times.
```asm
	.file	"fibo.c"
	.text
	.p2align 4
	.globl	fibo
	.type	fibo, @function
fibo:
.LFB23:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$168, %rsp
	.cfi_def_cfa_offset 224
	testq	%rdi, %rdi
	jle	.L28
	movq	%rdi, %r12
	cmpq	$1, %rdi
	je	.L2
	leaq	-1(%rdi), %r15
	xorl	%r12d, %r12d
.L27:
	cmpq	$1, %r15
	je	.L50
	leaq	-1(%r15), %r13
	xorl	%r14d, %r14d
	movq	%r12, 56(%rsp)
	movq	%r13, 64(%rsp)
	movq	%r13, %rbp
	movq	%r14, %r12
.L26:
	cmpq	$1, %rbp
	je	.L49
	movq	%r15, 72(%rsp)
	leaq	-1(%rbp), %rcx
	xorl	%r14d, %r14d
	movq	%rbp, 80(%rsp)
	movq	%rcx, %rbp
.L25:
	cmpq	$1, %rbp
	je	.L48
	movq	%r14, 96(%rsp)
	leaq	-1(%rbp), %rdi
	xorl	%r15d, %r15d
	movq	%rbp, %r13
	movq	%rcx, 104(%rsp)
	movq	%r12, 88(%rsp)
	movq	%rdi, %r12
.L24:
	cmpq	$1, %r12
	je	.L47
	leaq	-1(%r12), %r11
	xorl	%r14d, %r14d
	movq	%r15, 112(%rsp)
	movq	%r14, 32(%rsp)
	movq	%r11, %rbp
	movq	%rdi, 120(%rsp)
	movq	%r11, 128(%rsp)
	movq	%r12, 136(%rsp)
.L23:
	cmpq	$1, %rbp
	je	.L46
	leaq	-1(%rbp), %r12
	movq	%rbp, 152(%rsp)
	xorl	%r15d, %r15d
	movq	%r12, 144(%rsp)
	movq	%r12, %r14
.L22:
	cmpq	$1, %r14
	je	.L45
	leaq	-1(%r14), %rbp
	movq	%r13, 8(%rsp)
	xorl	%ecx, %ecx
	movq	%rbp, 16(%rsp)
	movq	%rbp, %rbx
	movq	%r14, 24(%rsp)
.L21:
	cmpq	$1, %rbx
	je	.L44
	leaq	-1(%rbx), %rbp
	xorl	%r13d, %r13d
	movq	%rbp, %r14
	movq	%rbp, %rdx
	movq	%rcx, %rbp
	movq	%rbx, %rcx
	movq	%r14, %rbx
.L20:
	movq	%rbx, %r14
	cmpq	$1, %rbx
	je	.L43
	movq	%rbx, 40(%rsp)
	xorl	%r12d, %r12d
	movq	%rdx, %rbx
.L16:
	leaq	-1(%r14), %rdi
	movq	%rcx, 48(%rsp)
	call	fibo
	movq	48(%rsp), %rcx
	addq	%rax, %r12
	subq	$2, %r14
	je	.L52
	cmpq	$1, %r14
	jne	.L16
	movq	%rbx, %rdx
	movq	40(%rsp), %rbx
	addq	$1, %r12
.L18:
	addq	%r12, %r13
	subq	$2, %rbx
	jne	.L20
.L43:
	movq	%rcx, %rbx
	leaq	1(%r13), %rsi
	movq	%rbp, %rcx
	addq	%rsi, %rcx
	subq	$2, %rbx
	cmpq	$1, %rdx
	jne	.L21
.L44:
	movq	24(%rsp), %r14
	movq	%rcx, %rbx
	movq	16(%rsp), %rbp
	addq	$1, %rbx
	movq	8(%rsp), %r13
	addq	%rbx, %r15
	subq	$2, %r14
	cmpq	$1, %rbp
	jne	.L22
.L45:
	movq	152(%rsp), %rbp
	movq	144(%rsp), %r12
	addq	$1, %r15
	addq	%r15, 32(%rsp)
	subq	$2, %rbp
	cmpq	$1, %r12
	jne	.L23
.L46:
	movq	32(%rsp), %r14
	movq	112(%rsp), %r15
	movq	136(%rsp), %r12
	movq	128(%rsp), %r11
	addq	$1, %r14
	movq	120(%rsp), %rdi
	addq	%r14, %r15
	subq	$2, %r12
	cmpq	$1, %r11
	jne	.L24
.L47:
	movq	96(%rsp), %r14
	movq	%r13, %rbp
	addq	$1, %r15
	movq	88(%rsp), %r12
	movq	104(%rsp), %rcx
	subq	$2, %rbp
	addq	%r15, %r14
	cmpq	$1, %rdi
	jne	.L25
.L48:
	movq	80(%rsp), %rbp
	addq	$1, %r14
	movq	72(%rsp), %r15
	addq	%r14, %r12
	subq	$2, %rbp
	cmpq	$1, %rcx
	jne	.L26
.L49:
	movq	%r12, %r14
	movq	64(%rsp), %r13
	movq	56(%rsp), %r12
	subq	$2, %r15
	addq	$1, %r14
	addq	%r14, %r12
	cmpq	$1, %r13
	jne	.L27
.L50:
	addq	$1, %r12
.L2:
	addq	$168, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%r12, %rax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L52:
	.cfi_restore_state
	movq	%rbx, %rdx
	movq	40(%rsp), %rbx
	jmp	.L18
.L28:
	xorl	%r12d, %r12d
	jmp	.L2
	.cfi_endproc
.LFE23:
	.size	fibo, .-fibo
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"fibo of %ld is %ld\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	leaq	.LC0(%rip), %rbp
	movl	$1, %ecx
	xorl	%eax, %eax
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movl	$1, %edx
	movq	%rbp, %rsi
	movl	$2, %edi
	movl	$2, %ebx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	__printf_chk@PLT
	.p2align 4,,10
	.p2align 3
.L54:
	movq	%rbx, %r8
	xorl	%r9d, %r9d
.L55:
	leaq	-1(%r8), %rdi
	call	fibo
	addq	%rax, %r9
	subq	$2, %r8
	je	.L56
	cmpq	$1, %r8
	jne	.L55
	addq	$1, %r9
.L56:
	movq	%rbx, %rdx
	movq	%r9, %rcx
	movq	%rbp, %rsi
	movl	$2, %edi
	xorl	%eax, %eax
	addq	$1, %rbx
	call	__printf_chk@PLT
	cmpq	$45, %rbx
	jne	.L54
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
```

level 3: same result as level 2

```asm
	.file	"fibo.c"
	.text
	.p2align 4
	.globl	fibo
	.type	fibo, @function
fibo:
.LFB23:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$168, %rsp
	.cfi_def_cfa_offset 224
	testq	%rdi, %rdi
	jle	.L28
	movq	%rdi, %r12
	cmpq	$1, %rdi
	je	.L2
	leaq	-1(%rdi), %r15
	xorl	%r12d, %r12d
.L27:
	cmpq	$1, %r15
	je	.L50
	leaq	-1(%r15), %r13
	xorl	%r14d, %r14d
	movq	%r12, 56(%rsp)
	movq	%r13, 64(%rsp)
	movq	%r13, %rbp
	movq	%r14, %r12
.L26:
	cmpq	$1, %rbp
	je	.L49
	movq	%r15, 72(%rsp)
	leaq	-1(%rbp), %rcx
	xorl	%r14d, %r14d
	movq	%rbp, 80(%rsp)
	movq	%rcx, %rbp
.L25:
	cmpq	$1, %rbp
	je	.L48
	movq	%r14, 96(%rsp)
	leaq	-1(%rbp), %rdi
	xorl	%r15d, %r15d
	movq	%rbp, %r13
	movq	%rcx, 104(%rsp)
	movq	%r12, 88(%rsp)
	movq	%rdi, %r12
.L24:
	cmpq	$1, %r12
	je	.L47
	leaq	-1(%r12), %r11
	xorl	%r14d, %r14d
	movq	%r15, 112(%rsp)
	movq	%r14, 32(%rsp)
	movq	%r11, %rbp
	movq	%rdi, 120(%rsp)
	movq	%r11, 128(%rsp)
	movq	%r12, 136(%rsp)
.L23:
	cmpq	$1, %rbp
	je	.L46
	leaq	-1(%rbp), %r12
	movq	%rbp, 152(%rsp)
	xorl	%r15d, %r15d
	movq	%r12, 144(%rsp)
	movq	%r12, %r14
.L22:
	cmpq	$1, %r14
	je	.L45
	leaq	-1(%r14), %rbp
	movq	%r13, 8(%rsp)
	xorl	%ecx, %ecx
	movq	%rbp, 16(%rsp)
	movq	%rbp, %rbx
	movq	%r14, 24(%rsp)
.L21:
	cmpq	$1, %rbx
	je	.L44
	leaq	-1(%rbx), %rbp
	xorl	%r13d, %r13d
	movq	%rbp, %r14
	movq	%rbp, %rdx
	movq	%rcx, %rbp
	movq	%rbx, %rcx
	movq	%r14, %rbx
.L20:
	movq	%rbx, %r14
	cmpq	$1, %rbx
	je	.L43
	movq	%rbx, 40(%rsp)
	xorl	%r12d, %r12d
	movq	%rdx, %rbx
.L16:
	leaq	-1(%r14), %rdi
	movq	%rcx, 48(%rsp)
	call	fibo
	movq	48(%rsp), %rcx
	addq	%rax, %r12
	subq	$2, %r14
	je	.L52
	cmpq	$1, %r14
	jne	.L16
	movq	%rbx, %rdx
	movq	40(%rsp), %rbx
	addq	$1, %r12
.L18:
	addq	%r12, %r13
	subq	$2, %rbx
	jne	.L20
.L43:
	movq	%rcx, %rbx
	leaq	1(%r13), %rsi
	movq	%rbp, %rcx
	addq	%rsi, %rcx
	subq	$2, %rbx
	cmpq	$1, %rdx
	jne	.L21
.L44:
	movq	24(%rsp), %r14
	movq	%rcx, %rbx
	movq	16(%rsp), %rbp
	addq	$1, %rbx
	movq	8(%rsp), %r13
	addq	%rbx, %r15
	subq	$2, %r14
	cmpq	$1, %rbp
	jne	.L22
.L45:
	movq	152(%rsp), %rbp
	movq	144(%rsp), %r12
	addq	$1, %r15
	addq	%r15, 32(%rsp)
	subq	$2, %rbp
	cmpq	$1, %r12
	jne	.L23
.L46:
	movq	32(%rsp), %r14
	movq	112(%rsp), %r15
	movq	136(%rsp), %r12
	movq	128(%rsp), %r11
	addq	$1, %r14
	movq	120(%rsp), %rdi
	addq	%r14, %r15
	subq	$2, %r12
	cmpq	$1, %r11
	jne	.L24
.L47:
	movq	96(%rsp), %r14
	movq	%r13, %rbp
	addq	$1, %r15
	movq	88(%rsp), %r12
	movq	104(%rsp), %rcx
	subq	$2, %rbp
	addq	%r15, %r14
	cmpq	$1, %rdi
	jne	.L25
.L48:
	movq	80(%rsp), %rbp
	addq	$1, %r14
	movq	72(%rsp), %r15
	addq	%r14, %r12
	subq	$2, %rbp
	cmpq	$1, %rcx
	jne	.L26
.L49:
	movq	%r12, %r14
	movq	64(%rsp), %r13
	movq	56(%rsp), %r12
	subq	$2, %r15
	addq	$1, %r14
	addq	%r14, %r12
	cmpq	$1, %r13
	jne	.L27
.L50:
	addq	$1, %r12
.L2:
	addq	$168, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%r12, %rax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L52:
	.cfi_restore_state
	movq	%rbx, %rdx
	movq	40(%rsp), %rbx
	jmp	.L18
.L28:
	xorl	%r12d, %r12d
	jmp	.L2
	.cfi_endproc
.LFE23:
	.size	fibo, .-fibo
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"fibo of %ld is %ld\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	leaq	.LC0(%rip), %rbp
	movl	$1, %ecx
	xorl	%eax, %eax
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movl	$1, %edx
	movq	%rbp, %rsi
	movl	$2, %edi
	movl	$2, %ebx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	__printf_chk@PLT
	.p2align 4,,10
	.p2align 3
.L54:
	movq	%rbx, %r8
	xorl	%r9d, %r9d
.L55:
	leaq	-1(%r8), %rdi
	call	fibo
	addq	%rax, %r9
	subq	$2, %r8
	je	.L56
	cmpq	$1, %r8
	jne	.L55
	addq	$1, %r9
.L56:
	movq	%rbx, %rdx
	movq	%r9, %rcx
	movq	%rbp, %rsi
	movl	$2, %edi
	xorl	%eax, %eax
	addq	$1, %rbx
	call	__printf_chk@PLT
	cmpq	$45, %rbx
	jne	.L54
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
```