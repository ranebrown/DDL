   1              		.cpu cortex-m0
   2              		.fpu softvfp
   3              		.eabi_attribute 20, 1
   4              		.eabi_attribute 21, 1
   5              		.eabi_attribute 23, 3
   6              		.eabi_attribute 24, 1
   7              		.eabi_attribute 25, 1
   8              		.eabi_attribute 26, 1
   9              		.eabi_attribute 30, 6
  10              		.eabi_attribute 34, 0
  11              		.eabi_attribute 18, 4
  12              		.code	16
  13              		.file	"main.c"
  14              		.text
  15              	.Ltext0:
  16              		.cfi_sections	.debug_frame
  17              		.section	.text.sum,"ax",%progbits
  18              		.align	2
  19              		.global	sum
  20              		.code	16
  21              		.thumb_func
  23              	sum:
  24              	.LFB0:
  25              		.file 1 "../src/main.c"
   1:../src/main.c **** extern int asm_sum(int x, int y);
   2:../src/main.c **** 
   3:../src/main.c **** int sum(int x, int y) {
  26              		.loc 1 3 0
  27              		.cfi_startproc
  28 0000 80B5     		push	{r7, lr}
  29              		.cfi_def_cfa_offset 8
  30              		.cfi_offset 7, -8
  31              		.cfi_offset 14, -4
  32 0002 82B0     		sub	sp, sp, #8
  33              		.cfi_def_cfa_offset 16
  34 0004 00AF     		add	r7, sp, #0
  35              		.cfi_def_cfa_register 7
  36 0006 7860     		str	r0, [r7, #4]
  37 0008 3960     		str	r1, [r7]
   4:../src/main.c **** 	return x + y;
  38              		.loc 1 4 0
  39 000a 7A68     		ldr	r2, [r7, #4]
  40 000c 3B68     		ldr	r3, [r7]
  41 000e D318     		add	r3, r2, r3
   5:../src/main.c **** }
  42              		.loc 1 5 0
  43 0010 181C     		mov	r0, r3
  44 0012 BD46     		mov	sp, r7
  45 0014 02B0     		add	sp, sp, #8
  46              		@ sp needed
  47 0016 80BD     		pop	{r7, pc}
  48              		.cfi_endproc
  49              	.LFE0:
  51              		.section	.text.main,"ax",%progbits
  52              		.align	2
  53              		.global	main
  54              		.code	16
  55              		.thumb_func
  57              	main:
  58              	.LFB1:
   6:../src/main.c **** 
   7:../src/main.c **** int main(void) {
  59              		.loc 1 7 0
  60              		.cfi_startproc
  61 0000 80B5     		push	{r7, lr}
  62              		.cfi_def_cfa_offset 8
  63              		.cfi_offset 7, -8
  64              		.cfi_offset 14, -4
  65 0002 82B0     		sub	sp, sp, #8
  66              		.cfi_def_cfa_offset 16
  67 0004 00AF     		add	r7, sp, #0
  68              		.cfi_def_cfa_register 7
   8:../src/main.c **** 
   9:../src/main.c **** 	int i, j;
  10:../src/main.c **** 
  11:../src/main.c **** 	i = sum(1, 2);
  69              		.loc 1 11 0
  70 0006 0120     		mov	r0, #1
  71 0008 0221     		mov	r1, #2
  72 000a FFF7FEFF 		bl	sum
  73 000e 031C     		mov	r3, r0
  74 0010 7B60     		str	r3, [r7, #4]
  12:../src/main.c **** 	j = asm_sum(5, 6);
  75              		.loc 1 12 0
  76 0012 0520     		mov	r0, #5
  77 0014 0621     		mov	r1, #6
  78 0016 FFF7FEFF 		bl	asm_sum
  79 001a 031C     		mov	r3, r0
  80 001c 3B60     		str	r3, [r7]
  81              	.L4:
  13:../src/main.c **** 
  14:../src/main.c **** 	// Enter an infinite loop, just incrementing a counter
  15:../src/main.c **** 	volatile static int loop = 0;
  16:../src/main.c **** 	while (1) {
  17:../src/main.c **** 		loop++;
  82              		.loc 1 17 0 discriminator 1
  83 001e 034B     		ldr	r3, .L5
  84 0020 1B68     		ldr	r3, [r3]
  85 0022 5A1C     		add	r2, r3, #1
  86 0024 014B     		ldr	r3, .L5
  87 0026 1A60     		str	r2, [r3]
  18:../src/main.c **** 	}
  88              		.loc 1 18 0 discriminator 1
  89 0028 F9E7     		b	.L4
  90              	.L6:
  91 002a C046     		.align	2
  92              	.L5:
  93 002c 00000000 		.word	loop.3639
  94              		.cfi_endproc
  95              	.LFE1:
  97              		.bss
  98              		.align	2
  99              	loop.3639:
 100 0000 00000000 		.space	4
 101              		.text
 102              	.Letext0:
DEFINED SYMBOLS
                            *ABS*:0000000000000000 main.c
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//cc2Ib4Sf.s:18     .text.sum:0000000000000000 $t
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//cc2Ib4Sf.s:23     .text.sum:0000000000000000 sum
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//cc2Ib4Sf.s:52     .text.main:0000000000000000 $t
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//cc2Ib4Sf.s:57     .text.main:0000000000000000 main
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//cc2Ib4Sf.s:93     .text.main:000000000000002c $d
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//cc2Ib4Sf.s:99     .bss:0000000000000000 loop.3639
/var/folders/f1/yf6vpc4d7rv1qk99nz_3kyd00000gn/T//cc2Ib4Sf.s:98     .bss:0000000000000000 $d
                     .debug_frame:0000000000000010 $d
                           .group:0000000000000000 wm4.0.550acd0550274b7e527f4d3bce81d4f2

UNDEFINED SYMBOLS
asm_sum
