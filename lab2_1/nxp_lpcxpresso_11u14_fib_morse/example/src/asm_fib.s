 	.syntax unified
 	.cpu cortex-m0
 	.align	2
 	.global	asm_fib
 	.thumb
 	.thumb_func

asm_fib:
	push {r4, r5, lr} 	// push to stack
	mov r4, r0 			// store value of n in r4

	// if(n==0) return 0
	cmp r0, #0
	ble neq0

	// if(n==1) return 1
	cmp r4, #1
	beq neq1

	// fib(n-1)
	subs r0, r4, #1
	bl asm_fib
	mov r5, r0 // r5 holds fib(n-1)

	// fib(n-2)
	subs r0, r4, #2
	bl asm_fib

	// r0 = fib(n-2) + fib(n-1)
	adds r0, r5, r0
	pop {r4, r5, pc}

neq0: // n==0
	movs r0, #0
	pop {r4, r5, pc}

neq1: // n==1
	movs r0, #1
	pop {r4, r5, pc}

