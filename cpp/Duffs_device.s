	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	__Z25copy_with_loop_unrolling8PKcPci ## -- Begin function _Z25copy_with_loop_unrolling8PKcPci
	.p2align	4, 0x90
__Z25copy_with_loop_unrolling8PKcPci:   ## @_Z25copy_with_loop_unrolling8PKcPci
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movl	-20(%rbp), %edx
	movl	%edx, %eax
	addl	$7, %eax
	sarl	$3, %eax
	movl	%eax, -24(%rbp)
	movl	%edx, %esi
	andl	$7, %edx
	movl	%esi, %eax
	andl	$7, %eax
	movl	%eax, %esi
	subl	$7, %edx
	movq	%rsi, -32(%rbp)         ## 8-byte Spill
	movl	%edx, -36(%rbp)         ## 4-byte Spill
	ja	LBB0_10
## BB#14:
	leaq	LJTI0_0(%rip), %rax
	movq	-32(%rbp), %rcx         ## 8-byte Reload
	movslq	(%rax,%rcx,4), %rdx
	addq	%rax, %rdx
	jmpq	*%rdx
LBB0_1:
	jmp	LBB0_2
LBB0_2:
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -8(%rbp)
	movb	(%rax), %dl
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -16(%rbp)
	movb	%dl, (%rax)
LBB0_3:
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -8(%rbp)
	movb	(%rax), %dl
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -16(%rbp)
	movb	%dl, (%rax)
LBB0_4:
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -8(%rbp)
	movb	(%rax), %dl
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -16(%rbp)
	movb	%dl, (%rax)
LBB0_5:
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -8(%rbp)
	movb	(%rax), %dl
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -16(%rbp)
	movb	%dl, (%rax)
LBB0_6:
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -8(%rbp)
	movb	(%rax), %dl
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -16(%rbp)
	movb	%dl, (%rax)
LBB0_7:
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -8(%rbp)
	movb	(%rax), %dl
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -16(%rbp)
	movb	%dl, (%rax)
LBB0_8:
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -8(%rbp)
	movb	(%rax), %dl
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -16(%rbp)
	movb	%dl, (%rax)
LBB0_9:
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -8(%rbp)
	movb	(%rax), %dl
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -16(%rbp)
	movb	%dl, (%rax)
LBB0_10:
	jmp	LBB0_11
LBB0_11:
	movl	-24(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -24(%rbp)
	cmpl	$0, %eax
	jg	LBB0_2
## BB#12:
	jmp	LBB0_13
LBB0_13:
	popq	%rbp
	retq
	.cfi_endproc
	.p2align	2, 0x90
	.data_region jt32
L0_0_set_1 = LBB0_1-LJTI0_0
L0_0_set_9 = LBB0_9-LJTI0_0
L0_0_set_8 = LBB0_8-LJTI0_0
L0_0_set_7 = LBB0_7-LJTI0_0
L0_0_set_6 = LBB0_6-LJTI0_0
L0_0_set_5 = LBB0_5-LJTI0_0
L0_0_set_4 = LBB0_4-LJTI0_0
L0_0_set_3 = LBB0_3-LJTI0_0
LJTI0_0:
	.long	L0_0_set_1
	.long	L0_0_set_9
	.long	L0_0_set_8
	.long	L0_0_set_7
	.long	L0_0_set_6
	.long	L0_0_set_5
	.long	L0_0_set_4
	.long	L0_0_set_3
	.end_data_region
                                        ## -- End function
	.globl	__Z14copy_with_loopPKcPci ## -- Begin function _Z14copy_with_loopPKcPci
	.p2align	4, 0x90
__Z14copy_with_loopPKcPci:              ## @_Z14copy_with_loopPKcPci
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movl	$0, -24(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-24(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jge	LBB1_4
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
	movq	-8(%rbp), %rax
	movb	(%rax), %cl
	movq	-16(%rbp), %rax
	movb	%cl, (%rax)
## BB#3:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	jmp	LBB1_1
LBB1_4:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__Z16copy_with_memcpyPKcPci ## -- Begin function _Z16copy_with_memcpyPKcPci
	.p2align	4, 0x90
__Z16copy_with_memcpyPKcPci:            ## @_Z16copy_with_memcpyPKcPci
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi6:
	.cfi_def_cfa_offset 16
Lcfi7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi8:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movq	-16(%rbp), %rdi
	movq	-8(%rbp), %rsi
	movslq	-20(%rbp), %rdx
	callq	_memcpy
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal16,16byte_literals
	.p2align	4               ## -- Begin function main
LCPI3_0:
	.long	1127219200              ## 0x43300000
	.long	1160773632              ## 0x45300000
	.long	0                       ## 0x0
	.long	0                       ## 0x0
LCPI3_1:
	.quad	4841369599423283200     ## double 4503599627370496
	.quad	4985484787499139072     ## double 1.9342813113834067E+25
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3
LCPI3_2:
	.quad	4652007308841189376     ## double 1000
LCPI3_3:
	.quad	4696837146684686336     ## double 1.0E+6
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
## BB#0:
	pushq	%rbp
Lcfi9:
	.cfi_def_cfa_offset 16
Lcfi10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi11:
	.cfi_def_cfa_register %rbp
	subq	$1936, %rsp             ## imm = 0x790
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -1444(%rbp)
	movl	%edi, -1448(%rbp)
	movq	%rsi, -1456(%rbp)
	movl	$800000000, -1460(%rbp) ## imm = 0x2FAF0800
	leaq	-104(%rbp), %rax
	movq	%rax, -1512(%rbp)
	movq	%rax, -1424(%rbp)
	leaq	L_.str(%rip), %rsi
	movq	%rsi, -1432(%rbp)
	leaq	__Z16copy_with_memcpyPKcPci(%rip), %rsi
	movq	%rsi, -1440(%rbp)
	movq	-1424(%rbp), %rsi
	movq	-1432(%rbp), %rcx
	movq	-1440(%rbp), %rdx
	movq	%rsi, -1400(%rbp)
	movq	%rcx, -1408(%rbp)
	movq	%rdx, -1416(%rbp)
	movq	-1400(%rbp), %rcx
	movq	-1408(%rbp), %rdx
	movq	%rdx, -1392(%rbp)
	movq	-1392(%rbp), %rdx
	movq	%rcx, -1368(%rbp)
	movq	%rdx, -1376(%rbp)
	movq	-1368(%rbp), %rdx
	movq	-1376(%rbp), %rsi
	movq	%rdx, -1352(%rbp)
	movq	%rsi, -1360(%rbp)
	movq	-1352(%rbp), %rdx
	movq	%rdx, -1344(%rbp)
	movq	-1344(%rbp), %rsi
	movq	%rsi, -1336(%rbp)
	movq	-1336(%rbp), %rsi
	movq	%rsi, -1328(%rbp)
	movq	-1328(%rbp), %r8
	movq	$0, 16(%r8)
	movq	$0, 8(%r8)
	movq	$0, (%r8)
	movq	%rsi, -1320(%rbp)
	movq	-1320(%rbp), %rsi
	movq	%rsi, -1312(%rbp)
	movq	-1360(%rbp), %rsi
	movq	%rsi, %rdi
	movq	%rax, -1624(%rbp)       ## 8-byte Spill
	movq	%rcx, -1632(%rbp)       ## 8-byte Spill
	movq	%rdx, -1640(%rbp)       ## 8-byte Spill
	movq	%rsi, -1648(%rbp)       ## 8-byte Spill
	callq	__ZNSt3__111char_traitsIcE6lengthEPKc
Ltmp0:
	movq	-1640(%rbp), %rdi       ## 8-byte Reload
	movq	-1648(%rbp), %rsi       ## 8-byte Reload
	movq	%rax, %rdx
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEPKcm
Ltmp1:
	jmp	LBB3_1
LBB3_1:
	movq	-1416(%rbp), %rax
	movq	%rax, -1384(%rbp)
	movq	-1384(%rbp), %rax
	movq	-1632(%rbp), %rcx       ## 8-byte Reload
	movq	%rax, 24(%rcx)
## BB#2:
	movq	-1624(%rbp), %rax       ## 8-byte Reload
	addq	$32, %rax
	movq	%rax, -1512(%rbp)
	movq	%rax, -1288(%rbp)
	leaq	L_.str.1(%rip), %rcx
	movq	%rcx, -1296(%rbp)
	leaq	__Z14copy_with_loopPKcPci(%rip), %rcx
	movq	%rcx, -1304(%rbp)
	movq	-1288(%rbp), %rcx
	movq	-1296(%rbp), %rdx
	movq	-1304(%rbp), %rsi
	movq	%rcx, -1264(%rbp)
	movq	%rdx, -1272(%rbp)
	movq	%rsi, -1280(%rbp)
	movq	-1264(%rbp), %rcx
	movq	-1272(%rbp), %rdx
	movq	%rdx, -1256(%rbp)
	movq	-1256(%rbp), %rdx
	movq	%rcx, -1232(%rbp)
	movq	%rdx, -1240(%rbp)
	movq	-1232(%rbp), %rdx
	movq	-1240(%rbp), %rsi
	movq	%rdx, -1216(%rbp)
	movq	%rsi, -1224(%rbp)
	movq	-1216(%rbp), %rdx
	movq	%rdx, -1208(%rbp)
	movq	-1208(%rbp), %rsi
	movq	%rsi, -1200(%rbp)
	movq	-1200(%rbp), %rsi
	movq	%rsi, -1192(%rbp)
	movq	-1192(%rbp), %rdi
	movq	$0, 16(%rdi)
	movq	$0, 8(%rdi)
	movq	$0, (%rdi)
	movq	%rsi, -1184(%rbp)
	movq	-1184(%rbp), %rsi
	movq	%rsi, -1176(%rbp)
	movq	-1224(%rbp), %rsi
	movq	%rsi, %rdi
	movq	%rax, -1656(%rbp)       ## 8-byte Spill
	movq	%rcx, -1664(%rbp)       ## 8-byte Spill
	movq	%rdx, -1672(%rbp)       ## 8-byte Spill
	movq	%rsi, -1680(%rbp)       ## 8-byte Spill
	callq	__ZNSt3__111char_traitsIcE6lengthEPKc
Ltmp2:
	movq	-1672(%rbp), %rdi       ## 8-byte Reload
	movq	-1680(%rbp), %rsi       ## 8-byte Reload
	movq	%rax, %rdx
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEPKcm
Ltmp3:
	jmp	LBB3_3
LBB3_3:
	movq	-1280(%rbp), %rax
	movq	%rax, -1248(%rbp)
	movq	-1248(%rbp), %rax
	movq	-1664(%rbp), %rcx       ## 8-byte Reload
	movq	%rax, 24(%rcx)
## BB#4:
	movq	-1656(%rbp), %rax       ## 8-byte Reload
	addq	$32, %rax
	movq	%rax, -1512(%rbp)
	movq	%rax, -1152(%rbp)
	leaq	L_.str.2(%rip), %rax
	movq	%rax, -1160(%rbp)
	leaq	__Z25copy_with_loop_unrolling8PKcPci(%rip), %rax
	movq	%rax, -1168(%rbp)
	movq	-1152(%rbp), %rax
	movq	-1160(%rbp), %rcx
	movq	-1168(%rbp), %rdx
	movq	%rax, -1128(%rbp)
	movq	%rcx, -1136(%rbp)
	movq	%rdx, -1144(%rbp)
	movq	-1128(%rbp), %rax
	movq	-1136(%rbp), %rcx
	movq	%rcx, -1120(%rbp)
	movq	-1120(%rbp), %rcx
	movq	%rax, -1096(%rbp)
	movq	%rcx, -1104(%rbp)
	movq	-1096(%rbp), %rcx
	movq	-1104(%rbp), %rdx
	movq	%rcx, -1080(%rbp)
	movq	%rdx, -1088(%rbp)
	movq	-1080(%rbp), %rcx
	movq	%rcx, -1072(%rbp)
	movq	-1072(%rbp), %rdx
	movq	%rdx, -1064(%rbp)
	movq	-1064(%rbp), %rdx
	movq	%rdx, -1056(%rbp)
	movq	-1056(%rbp), %rsi
	movq	$0, 16(%rsi)
	movq	$0, 8(%rsi)
	movq	$0, (%rsi)
	movq	%rdx, -1048(%rbp)
	movq	-1048(%rbp), %rdx
	movq	%rdx, -1040(%rbp)
	movq	-1088(%rbp), %rdx
	movq	%rdx, %rdi
	movq	%rax, -1688(%rbp)       ## 8-byte Spill
	movq	%rcx, -1696(%rbp)       ## 8-byte Spill
	movq	%rdx, -1704(%rbp)       ## 8-byte Spill
	callq	__ZNSt3__111char_traitsIcE6lengthEPKc
Ltmp4:
	movq	-1696(%rbp), %rdi       ## 8-byte Reload
	movq	-1704(%rbp), %rsi       ## 8-byte Reload
	movq	%rax, %rdx
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEPKcm
Ltmp5:
	jmp	LBB3_5
LBB3_5:
	movq	-1144(%rbp), %rax
	movq	%rax, -1112(%rbp)
	movq	-1112(%rbp), %rax
	movq	-1688(%rbp), %rcx       ## 8-byte Reload
	movq	%rax, 24(%rcx)
## BB#6:
	leaq	-976(%rbp), %rax
	leaq	-1528(%rbp), %rcx
	leaq	-1488(%rbp), %rdx
	leaq	-104(%rbp), %rsi
	movq	%rsi, -1504(%rbp)
	movq	$3, -1496(%rbp)
	movq	-1504(%rbp), %rsi
	movq	-1496(%rbp), %rdi
	movq	%rsi, -1016(%rbp)
	movq	%rdi, -1008(%rbp)
	movq	%rdx, -1024(%rbp)
	movq	%rcx, -1032(%rbp)
	movq	-1024(%rbp), %rcx
	movq	-1032(%rbp), %rdx
	movq	-1016(%rbp), %rsi
	movq	-1008(%rbp), %rdi
	movq	%rsi, -952(%rbp)
	movq	%rdi, -944(%rbp)
	movq	%rcx, -960(%rbp)
	movq	%rdx, -968(%rbp)
	movq	-960(%rbp), %rcx
	movq	%rax, -936(%rbp)
	movq	-936(%rbp), %rdx
	movq	%rdx, -920(%rbp)
	movq	%rcx, %rdi
	movq	%rax, %rsi
	movq	%rcx, -1712(%rbp)       ## 8-byte Spill
	callq	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEEC1ERKSH_
	leaq	-816(%rbp), %rax
	leaq	-800(%rbp), %rcx
	leaq	-952(%rbp), %rdx
	movq	%rdx, -912(%rbp)
	movq	-912(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rdx, -528(%rbp)
	movq	-528(%rbp), %rdx
	movq	(%rdx), %rdi
	movq	8(%rdx), %rdx
	shlq	$5, %rdx
	addq	%rdx, %rdi
	movq	-1712(%rbp), %rdx       ## 8-byte Reload
	movq	%rdx, -856(%rbp)
	movq	%rsi, -864(%rbp)
	movq	%rdi, -872(%rbp)
	movq	-856(%rbp), %rsi
	movq	%rsi, -848(%rbp)
	movq	-848(%rbp), %rdi
	movq	%rdi, -824(%rbp)
	movq	-824(%rbp), %rdi
	movq	%rdi, -808(%rbp)
	movq	-808(%rbp), %rdi
	movq	%rdi, -792(%rbp)
	movq	-792(%rbp), %rdi
	addq	$8, %rdi
	movq	%rdi, -784(%rbp)
	movq	-784(%rbp), %rdi
	movq	%rdi, -776(%rbp)
	movq	-776(%rbp), %rdi
	movq	%rdi, -768(%rbp)
	movq	-768(%rbp), %rdi
	movq	%rdi, -760(%rbp)
	movq	-760(%rbp), %rdi
	movq	%rcx, -744(%rbp)
	movq	%rdi, -752(%rbp)
	movq	-744(%rbp), %rcx
	movq	-752(%rbp), %rdi
	movq	%rcx, -728(%rbp)
	movq	%rdi, -736(%rbp)
	movq	-728(%rbp), %rcx
	movq	-736(%rbp), %rdi
	movq	%rdi, (%rcx)
	movq	-800(%rbp), %rcx
	movq	%rcx, -832(%rbp)
	movq	-832(%rbp), %rcx
	movq	%rcx, -712(%rbp)
	movq	%rax, -720(%rbp)
	movq	-720(%rbp), %rax
	movq	-712(%rbp), %rcx
	movq	%rcx, -696(%rbp)
	movq	%rax, -704(%rbp)
	movq	-704(%rbp), %rax
	movq	-696(%rbp), %rcx
	movq	%rcx, (%rax)
	movq	-816(%rbp), %rax
	movq	%rax, -840(%rbp)
	movq	-840(%rbp), %rax
	movq	%rax, -880(%rbp)
	movq	%rsi, -1720(%rbp)       ## 8-byte Spill
LBB3_7:                                 ## =>This Inner Loop Header: Depth=1
	movq	-864(%rbp), %rax
	cmpq	-872(%rbp), %rax
	je	LBB3_11
## BB#8:                                ##   in Loop: Header=BB3_7 Depth=1
	movq	-880(%rbp), %rax
	movq	%rax, -896(%rbp)
	movq	-896(%rbp), %rax
	movq	%rax, -552(%rbp)
	leaq	-888(%rbp), %rax
	movq	%rax, -560(%rbp)
	movq	-560(%rbp), %rax
	movq	-552(%rbp), %rcx
	movq	%rcx, -536(%rbp)
	movq	%rax, -544(%rbp)
	movq	-544(%rbp), %rax
	movq	-536(%rbp), %rcx
	movq	%rcx, (%rax)
	movq	-864(%rbp), %rax
	movq	-888(%rbp), %rcx
	movq	%rcx, -656(%rbp)
	movq	-1720(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -664(%rbp)
	movq	%rax, -672(%rbp)
	movq	-664(%rbp), %rax
	movq	-656(%rbp), %rdx
	movq	%rdx, -688(%rbp)
	movq	-672(%rbp), %rdx
	movq	-688(%rbp), %rsi
	movq	%rsi, -616(%rbp)
	movq	%rax, -624(%rbp)
	movq	%rdx, -632(%rbp)
	movq	-624(%rbp), %rdi
	movq	-616(%rbp), %rax
	movq	%rax, -640(%rbp)
	movq	-632(%rbp), %rax
	movq	%rax, -600(%rbp)
	movq	-600(%rbp), %rdx
	movq	-640(%rbp), %rsi
Ltmp33:
	movq	%rax, %rcx
	callq	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE30__emplace_hint_unique_key_argsIS7_JRKNS_4pairIKS7_SC_EEEEENS_15__tree_iteratorISD_PNS_11__tree_nodeISD_PvEElEENS_21__tree_const_iteratorISD_SU_lEERKT_DpOT0_
Ltmp34:
	movq	%rax, -1728(%rbp)       ## 8-byte Spill
	jmp	LBB3_9
LBB3_9:                                 ##   in Loop: Header=BB3_7 Depth=1
	leaq	-648(%rbp), %rax
	movq	-1728(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -608(%rbp)
	movq	-608(%rbp), %rdx
	movq	%rdx, -680(%rbp)
	movq	-680(%rbp), %rdx
	movq	%rdx, -584(%rbp)
	movq	%rax, -592(%rbp)
	movq	-592(%rbp), %rax
	movq	-584(%rbp), %rdx
	movq	%rdx, -568(%rbp)
	movq	%rax, -576(%rbp)
	movq	-576(%rbp), %rax
	movq	-568(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-648(%rbp), %rax
	movq	%rax, -904(%rbp)
	movq	-864(%rbp), %rax
	addq	$32, %rax
	movq	%rax, -864(%rbp)
	jmp	LBB3_7
LBB3_10:
Ltmp35:
	movl	%edx, %ecx
	movq	%rax, -992(%rbp)
	movl	%ecx, -996(%rbp)
	movq	-1712(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEED1Ev
	movq	-992(%rbp), %rax
	movl	-996(%rbp), %ecx
	movq	%rax, -1736(%rbp)       ## 8-byte Spill
	movl	%ecx, -1740(%rbp)       ## 4-byte Spill
	jmp	LBB3_50
LBB3_11:
	jmp	LBB3_12
LBB3_12:
	leaq	-104(%rbp), %rax
	movq	%rax, %rcx
	addq	$96, %rcx
	movq	%rax, -1752(%rbp)       ## 8-byte Spill
	movq	%rcx, -1760(%rbp)       ## 8-byte Spill
LBB3_13:                                ## =>This Inner Loop Header: Depth=1
	movq	-1760(%rbp), %rax       ## 8-byte Reload
	addq	$-32, %rax
	movq	%rax, %rdi
	movq	%rax, -1768(%rbp)       ## 8-byte Spill
	callq	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED1Ev
	movq	-1768(%rbp), %rax       ## 8-byte Reload
	movq	-1752(%rbp), %rdi       ## 8-byte Reload
	cmpq	%rdi, %rax
	movq	%rax, -1760(%rbp)       ## 8-byte Spill
	jne	LBB3_13
## BB#14:
	leaq	-392(%rbp), %rax
	leaq	-376(%rbp), %rcx
	leaq	-504(%rbp), %rdx
	leaq	-488(%rbp), %rsi
	leaq	-1488(%rbp), %rdi
	movq	%rdi, -1536(%rbp)
	movq	-1536(%rbp), %rdi
	movq	%rdi, -512(%rbp)
	movq	-512(%rbp), %rdi
	movq	%rdi, -496(%rbp)
	movq	-496(%rbp), %rdi
	movq	%rdi, -480(%rbp)
	movq	-480(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rsi, -464(%rbp)
	movq	%rdi, -472(%rbp)
	movq	-464(%rbp), %rsi
	movq	-472(%rbp), %rdi
	movq	%rsi, -448(%rbp)
	movq	%rdi, -456(%rbp)
	movq	-448(%rbp), %rsi
	movq	-456(%rbp), %rdi
	movq	%rdi, (%rsi)
	movq	-488(%rbp), %rsi
	movq	%rsi, -520(%rbp)
	movq	-520(%rbp), %rsi
	movq	%rsi, -432(%rbp)
	movq	%rdx, -440(%rbp)
	movq	-440(%rbp), %rdx
	movq	-432(%rbp), %rsi
	movq	%rsi, -416(%rbp)
	movq	%rdx, -424(%rbp)
	movq	-424(%rbp), %rdx
	movq	-416(%rbp), %rsi
	movq	%rsi, (%rdx)
	movq	-504(%rbp), %rdx
	movq	%rdx, -1544(%rbp)
	movq	-1536(%rbp), %rdx
	movq	%rdx, -400(%rbp)
	movq	-400(%rbp), %rdx
	movq	%rdx, -384(%rbp)
	movq	-384(%rbp), %rdx
	movq	%rdx, -368(%rbp)
	movq	-368(%rbp), %rdx
	addq	$8, %rdx
	movq	%rdx, -360(%rbp)
	movq	-360(%rbp), %rdx
	movq	%rdx, -352(%rbp)
	movq	-352(%rbp), %rdx
	movq	%rdx, -344(%rbp)
	movq	-344(%rbp), %rdx
	movq	%rdx, -336(%rbp)
	movq	-336(%rbp), %rdx
	movq	%rcx, -320(%rbp)
	movq	%rdx, -328(%rbp)
	movq	-320(%rbp), %rcx
	movq	-328(%rbp), %rdx
	movq	%rcx, -304(%rbp)
	movq	%rdx, -312(%rbp)
	movq	-304(%rbp), %rcx
	movq	-312(%rbp), %rdx
	movq	%rdx, (%rcx)
	movq	-376(%rbp), %rcx
	movq	%rcx, -408(%rbp)
	movq	-408(%rbp), %rcx
	movq	%rcx, -288(%rbp)
	movq	%rax, -296(%rbp)
	movq	-296(%rbp), %rax
	movq	-288(%rbp), %rcx
	movq	%rcx, -272(%rbp)
	movq	%rax, -280(%rbp)
	movq	-280(%rbp), %rax
	movq	-272(%rbp), %rcx
	movq	%rcx, (%rax)
	movq	-392(%rbp), %rax
	movq	%rax, -1552(%rbp)
LBB3_15:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB3_38 Depth 2
                                        ##     Child Loop BB3_42 Depth 2
	leaq	-1552(%rbp), %rax
	leaq	-1544(%rbp), %rcx
	movq	%rcx, -256(%rbp)
	movq	%rax, -264(%rbp)
	movq	-256(%rbp), %rax
	movq	-264(%rbp), %rcx
	movq	%rax, -240(%rbp)
	movq	%rcx, -248(%rbp)
	movq	-240(%rbp), %rax
	movq	-248(%rbp), %rcx
	movq	%rax, -224(%rbp)
	movq	%rcx, -232(%rbp)
	movq	-224(%rbp), %rax
	movq	(%rax), %rax
	movq	-232(%rbp), %rcx
	cmpq	(%rcx), %rax
	sete	%dl
	xorb	$-1, %dl
	movb	%dl, -1769(%rbp)        ## 1-byte Spill
## BB#16:                               ##   in Loop: Header=BB3_15 Depth=1
	movb	-1769(%rbp), %al        ## 1-byte Reload
	testb	$1, %al
	jne	LBB3_17
	jmp	LBB3_55
LBB3_17:                                ##   in Loop: Header=BB3_15 Depth=1
	leaq	-1544(%rbp), %rax
	movq	%rax, -216(%rbp)
	movq	-216(%rbp), %rax
	movq	%rax, -208(%rbp)
	movq	-208(%rbp), %rax
	movq	%rax, -200(%rbp)
	movq	-200(%rbp), %rax
	movq	(%rax), %rax
	addq	$32, %rax
	movq	%rax, -192(%rbp)
	movq	-192(%rbp), %rax
	movq	%rax, -184(%rbp)
	movq	-184(%rbp), %rax
	movq	%rax, -1784(%rbp)       ## 8-byte Spill
## BB#18:                               ##   in Loop: Header=BB3_15 Depth=1
Ltmp7:
	leaq	-1584(%rbp), %rdi
	movq	-1784(%rbp), %rsi       ## 8-byte Reload
	callq	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEC1ERKSD_
Ltmp8:
	jmp	LBB3_19
LBB3_19:                                ##   in Loop: Header=BB3_15 Depth=1
	movslq	-1460(%rbp), %rax
	testq	%rax, %rax
	movq	$-1, %rcx
	cmovsq	%rcx, %rax
Ltmp10:
	movq	%rax, %rdi
	callq	__Znam
Ltmp11:
	movq	%rax, -1792(%rbp)       ## 8-byte Spill
	jmp	LBB3_20
LBB3_20:                                ##   in Loop: Header=BB3_15 Depth=1
	movq	-1792(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1592(%rbp)
	movslq	-1460(%rbp), %rcx
	testq	%rcx, %rcx
	movq	$-1, %rdx
	cmovsq	%rdx, %rcx
Ltmp12:
	movq	%rcx, %rdi
	callq	__Znam
Ltmp13:
	movq	%rax, -1800(%rbp)       ## 8-byte Spill
	jmp	LBB3_21
LBB3_21:                                ##   in Loop: Header=BB3_15 Depth=1
	movq	-1800(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1600(%rbp)
Ltmp14:
	callq	_clock
Ltmp15:
	movq	%rax, -1808(%rbp)       ## 8-byte Spill
	jmp	LBB3_22
LBB3_22:                                ##   in Loop: Header=BB3_15 Depth=1
	movq	-1808(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1608(%rbp)
	movq	-1560(%rbp), %rcx
	movq	-1592(%rbp), %rdi
	movq	-1600(%rbp), %rsi
	movl	-1460(%rbp), %edx
Ltmp16:
	callq	*%rcx
Ltmp17:
	jmp	LBB3_23
LBB3_23:                                ##   in Loop: Header=BB3_15 Depth=1
Ltmp18:
	callq	_clock
Ltmp19:
	movq	%rax, -1816(%rbp)       ## 8-byte Spill
	jmp	LBB3_24
LBB3_24:                                ##   in Loop: Header=BB3_15 Depth=1
	movq	-1816(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1616(%rbp)
Ltmp20:
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	leaq	L_.str.3(%rip), %rsi
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp21:
	movq	%rax, -1824(%rbp)       ## 8-byte Spill
	jmp	LBB3_25
LBB3_25:                                ##   in Loop: Header=BB3_15 Depth=1
Ltmp22:
	leaq	-1584(%rbp), %rsi
	movq	-1824(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__1lsIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_ostreamIT_T0_EES9_RKNS_12basic_stringIS6_S7_T1_EE
Ltmp23:
	movq	%rax, -1832(%rbp)       ## 8-byte Spill
	jmp	LBB3_26
LBB3_26:                                ##   in Loop: Header=BB3_15 Depth=1
Ltmp24:
	leaq	L_.str.4(%rip), %rsi
	movq	-1832(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp25:
	movq	%rax, -1840(%rbp)       ## 8-byte Spill
	jmp	LBB3_27
LBB3_27:                                ##   in Loop: Header=BB3_15 Depth=1
	movq	-1616(%rbp), %rax
	movq	-1608(%rbp), %rcx
	subq	%rcx, %rax
	movq	%rax, %xmm0
	movaps	LCPI3_0(%rip), %xmm1    ## xmm1 = [1127219200,1160773632,0,0]
	punpckldq	%xmm1, %xmm0    ## xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
	movapd	LCPI3_1(%rip), %xmm1    ## xmm1 = [4.503600e+15,1.934281e+25]
	subpd	%xmm1, %xmm0
	haddpd	%xmm0, %xmm0
	movsd	LCPI3_2(%rip), %xmm1    ## xmm1 = mem[0],zero
	mulsd	%xmm1, %xmm0
	movsd	LCPI3_3(%rip), %xmm1    ## xmm1 = mem[0],zero
	divsd	%xmm1, %xmm0
Ltmp26:
	movq	-1840(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEd
Ltmp27:
	movq	%rax, -1848(%rbp)       ## 8-byte Spill
	jmp	LBB3_28
LBB3_28:                                ##   in Loop: Header=BB3_15 Depth=1
Ltmp28:
	leaq	L_.str.5(%rip), %rsi
	movq	-1848(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp29:
	movq	%rax, -1856(%rbp)       ## 8-byte Spill
	jmp	LBB3_29
LBB3_29:                                ##   in Loop: Header=BB3_15 Depth=1
	movq	-1856(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -168(%rbp)
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rcx
	movq	%rcx, -176(%rbp)
	movq	-168(%rbp), %rdi
	movq	-176(%rbp), %rcx
Ltmp30:
	callq	*%rcx
Ltmp31:
	movq	%rax, -1864(%rbp)       ## 8-byte Spill
	jmp	LBB3_30
LBB3_30:                                ##   in Loop: Header=BB3_15 Depth=1
	jmp	LBB3_31
LBB3_31:                                ##   in Loop: Header=BB3_15 Depth=1
	movq	-1592(%rbp), %rax
	cmpq	$0, %rax
	movq	%rax, -1872(%rbp)       ## 8-byte Spill
	je	LBB3_33
## BB#32:                               ##   in Loop: Header=BB3_15 Depth=1
	movq	-1872(%rbp), %rdi       ## 8-byte Reload
	callq	__ZdaPv
LBB3_33:                                ##   in Loop: Header=BB3_15 Depth=1
	movq	$0, -1592(%rbp)
	movq	-1600(%rbp), %rax
	cmpq	$0, %rax
	movq	%rax, -1880(%rbp)       ## 8-byte Spill
	je	LBB3_35
## BB#34:                               ##   in Loop: Header=BB3_15 Depth=1
	movq	-1880(%rbp), %rdi       ## 8-byte Reload
	callq	__ZdaPv
LBB3_35:                                ##   in Loop: Header=BB3_15 Depth=1
	leaq	-1584(%rbp), %rdi
	movq	$0, -1600(%rbp)
	callq	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED1Ev
## BB#36:                               ##   in Loop: Header=BB3_15 Depth=1
	leaq	-1544(%rbp), %rax
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rax
	movq	%rax, -152(%rbp)
	movq	-152(%rbp), %rax
	movq	(%rax), %rcx
	movq	%rcx, -144(%rbp)
	movq	-144(%rbp), %rcx
	cmpq	$0, 8(%rcx)
	movq	%rax, -1888(%rbp)       ## 8-byte Spill
	je	LBB3_41
## BB#37:                               ##   in Loop: Header=BB3_15 Depth=1
	movq	-144(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -128(%rbp)
LBB3_38:                                ##   Parent Loop BB3_15 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	-128(%rbp), %rax
	cmpq	$0, (%rax)
	je	LBB3_40
## BB#39:                               ##   in Loop: Header=BB3_38 Depth=2
	movq	-128(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -128(%rbp)
	jmp	LBB3_38
LBB3_40:                                ##   in Loop: Header=BB3_15 Depth=1
	movq	-128(%rbp), %rax
	movq	%rax, -136(%rbp)
	jmp	LBB3_45
LBB3_41:                                ##   in Loop: Header=BB3_15 Depth=1
	jmp	LBB3_42
LBB3_42:                                ##   Parent Loop BB3_15 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	-144(%rbp), %rax
	movq	%rax, -120(%rbp)
	movq	-120(%rbp), %rax
	movq	-120(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	sete	%dl
	xorb	$-1, %dl
	testb	$1, %dl
	jne	LBB3_43
	jmp	LBB3_44
LBB3_43:                                ##   in Loop: Header=BB3_42 Depth=2
	movq	-144(%rbp), %rax
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -144(%rbp)
	jmp	LBB3_42
LBB3_44:                                ##   in Loop: Header=BB3_15 Depth=1
	movq	-144(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -136(%rbp)
LBB3_45:                                ##   in Loop: Header=BB3_15 Depth=1
	movq	-136(%rbp), %rax
	movq	-1888(%rbp), %rcx       ## 8-byte Reload
	movq	%rax, (%rcx)
## BB#46:                               ##   in Loop: Header=BB3_15 Depth=1
	jmp	LBB3_15
LBB3_47:
Ltmp6:
	movl	%edx, %ecx
	movq	%rax, -1520(%rbp)
	movl	%ecx, -1524(%rbp)
	movq	-1512(%rbp), %rax
	movq	-1624(%rbp), %rdx       ## 8-byte Reload
	cmpq	%rax, %rdx
	movq	%rax, -1896(%rbp)       ## 8-byte Spill
	je	LBB3_49
LBB3_48:                                ## =>This Inner Loop Header: Depth=1
	movq	-1896(%rbp), %rax       ## 8-byte Reload
	addq	$-32, %rax
	movq	%rax, %rdi
	movq	%rax, -1904(%rbp)       ## 8-byte Spill
	callq	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED1Ev
	movq	-1904(%rbp), %rax       ## 8-byte Reload
	movq	-1624(%rbp), %rdi       ## 8-byte Reload
	cmpq	%rdi, %rax
	movq	%rax, -1896(%rbp)       ## 8-byte Spill
	jne	LBB3_48
LBB3_49:
	jmp	LBB3_58
LBB3_50:
	leaq	-104(%rbp), %rax
	movq	-1736(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1520(%rbp)
	movl	-1740(%rbp), %edx       ## 4-byte Reload
	movl	%edx, -1524(%rbp)
	movq	%rax, %rcx
	addq	$96, %rcx
	movq	%rax, -1912(%rbp)       ## 8-byte Spill
	movq	%rcx, -1920(%rbp)       ## 8-byte Spill
LBB3_51:                                ## =>This Inner Loop Header: Depth=1
	movq	-1920(%rbp), %rax       ## 8-byte Reload
	addq	$-32, %rax
	movq	%rax, %rdi
	movq	%rax, -1928(%rbp)       ## 8-byte Spill
	callq	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED1Ev
	movq	-1928(%rbp), %rax       ## 8-byte Reload
	movq	-1912(%rbp), %rdi       ## 8-byte Reload
	cmpq	%rdi, %rax
	movq	%rax, -1920(%rbp)       ## 8-byte Spill
	jne	LBB3_51
## BB#52:
	jmp	LBB3_58
LBB3_53:
Ltmp9:
	movl	%edx, %ecx
	movq	%rax, -1520(%rbp)
	movl	%ecx, -1524(%rbp)
	jmp	LBB3_57
LBB3_54:
Ltmp32:
	leaq	-1584(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -1520(%rbp)
	movl	%ecx, -1524(%rbp)
	callq	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED1Ev
	jmp	LBB3_57
LBB3_55:
	leaq	-1488(%rbp), %rdi
	movl	$0, -1444(%rbp)
	callq	__ZNSt3__13mapINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciENS_4lessIS6_EENS4_INS_4pairIKS6_SB_EEEEED1Ev
	movl	-1444(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rdi
	movq	(%rdi), %rdi
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rdi
	movl	%eax, -1932(%rbp)       ## 4-byte Spill
	jne	LBB3_59
## BB#56:
	movl	-1932(%rbp), %eax       ## 4-byte Reload
	addq	$1936, %rsp             ## imm = 0x790
	popq	%rbp
	retq
LBB3_57:
	leaq	-1488(%rbp), %rdi
	callq	__ZNSt3__13mapINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciENS_4lessIS6_EENS4_INS_4pairIKS6_SB_EEEEED1Ev
LBB3_58:
	movq	-1520(%rbp), %rdi
	callq	__Unwind_Resume
LBB3_59:
	callq	___stack_chk_fail
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table3:
Lexception0:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\303\200"              ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	65                      ## Call site table length
Lset0 = Ltmp0-Lfunc_begin0              ## >> Call Site 1 <<
	.long	Lset0
Lset1 = Ltmp5-Ltmp0                     ##   Call between Ltmp0 and Ltmp5
	.long	Lset1
Lset2 = Ltmp6-Lfunc_begin0              ##     jumps to Ltmp6
	.long	Lset2
	.byte	0                       ##   On action: cleanup
Lset3 = Ltmp33-Lfunc_begin0             ## >> Call Site 2 <<
	.long	Lset3
Lset4 = Ltmp34-Ltmp33                   ##   Call between Ltmp33 and Ltmp34
	.long	Lset4
Lset5 = Ltmp35-Lfunc_begin0             ##     jumps to Ltmp35
	.long	Lset5
	.byte	0                       ##   On action: cleanup
Lset6 = Ltmp7-Lfunc_begin0              ## >> Call Site 3 <<
	.long	Lset6
Lset7 = Ltmp8-Ltmp7                     ##   Call between Ltmp7 and Ltmp8
	.long	Lset7
Lset8 = Ltmp9-Lfunc_begin0              ##     jumps to Ltmp9
	.long	Lset8
	.byte	0                       ##   On action: cleanup
Lset9 = Ltmp10-Lfunc_begin0             ## >> Call Site 4 <<
	.long	Lset9
Lset10 = Ltmp31-Ltmp10                  ##   Call between Ltmp10 and Ltmp31
	.long	Lset10
Lset11 = Ltmp32-Lfunc_begin0            ##     jumps to Ltmp32
	.long	Lset11
	.byte	0                       ##   On action: cleanup
Lset12 = Ltmp31-Lfunc_begin0            ## >> Call Site 5 <<
	.long	Lset12
Lset13 = Lfunc_end0-Ltmp31              ##   Call between Ltmp31 and Lfunc_end0
	.long	Lset13
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED1Ev ## -- Begin function _ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED1Ev
	.weak_def_can_be_hidden	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED1Ev
	.p2align	4, 0x90
__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED1Ev: ## @_ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED1Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi12:
	.cfi_def_cfa_offset 16
Lcfi13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi14:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEC1ERKSD_ ## -- Begin function _ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEC1ERKSD_
	.weak_def_can_be_hidden	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEC1ERKSD_
	.p2align	4, 0x90
__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEC1ERKSD_: ## @_ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEC1ERKSD_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi15:
	.cfi_def_cfa_offset 16
Lcfi16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi17:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	callq	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEC2ERKSD_
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc ## -- Begin function _ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	.weak_definition	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	.p2align	4, 0x90
__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc: ## @_ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi18:
	.cfi_def_cfa_offset 16
Lcfi19:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi20:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movq	-16(%rbp), %rax
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rsi, -32(%rbp)         ## 8-byte Spill
	callq	__ZNSt3__111char_traitsIcE6lengthEPKc
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	movq	-32(%rbp), %rsi         ## 8-byte Reload
	movq	%rax, %rdx
	callq	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__1lsIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_ostreamIT_T0_EES9_RKNS_12basic_stringIS6_S7_T1_EE ## -- Begin function _ZNSt3__1lsIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_ostreamIT_T0_EES9_RKNS_12basic_stringIS6_S7_T1_EE
	.weak_definition	__ZNSt3__1lsIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_ostreamIT_T0_EES9_RKNS_12basic_stringIS6_S7_T1_EE
	.p2align	4, 0x90
__ZNSt3__1lsIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_ostreamIT_T0_EES9_RKNS_12basic_stringIS6_S7_T1_EE: ## @_ZNSt3__1lsIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_ostreamIT_T0_EES9_RKNS_12basic_stringIS6_S7_T1_EE
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi21:
	.cfi_def_cfa_offset 16
Lcfi22:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi23:
	.cfi_def_cfa_register %rbp
	subq	$256, %rsp              ## imm = 0x100
	movq	%rdi, -200(%rbp)
	movq	%rsi, -208(%rbp)
	movq	-200(%rbp), %rdi
	movq	-208(%rbp), %rsi
	movq	%rsi, -192(%rbp)
	movq	-192(%rbp), %rsi
	movq	%rsi, -184(%rbp)
	movq	-184(%rbp), %rsi
	movq	%rsi, -176(%rbp)
	movq	-176(%rbp), %rax
	movq	%rax, -168(%rbp)
	movq	-168(%rbp), %rax
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rax
	movzbl	(%rax), %ecx
	movl	%ecx, %eax
	andq	$1, %rax
	cmpq	$0, %rax
	movq	%rdi, -216(%rbp)        ## 8-byte Spill
	movq	%rsi, -224(%rbp)        ## 8-byte Spill
	je	LBB7_2
## BB#1:
	movq	-224(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rcx
	movq	%rcx, -104(%rbp)
	movq	-104(%rbp), %rcx
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -232(%rbp)        ## 8-byte Spill
	jmp	LBB7_3
LBB7_2:
	movq	-224(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -152(%rbp)
	movq	-152(%rbp), %rcx
	movq	%rcx, -144(%rbp)
	movq	-144(%rbp), %rcx
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	%rcx, -120(%rbp)
	movq	-120(%rbp), %rcx
	movq	%rcx, -232(%rbp)        ## 8-byte Spill
LBB7_3:
	movq	-232(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rsi
	movq	-208(%rbp), %rax
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rcx
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	%rcx, -56(%rbp)
	movq	-56(%rbp), %rcx
	movzbl	(%rcx), %edx
	movl	%edx, %ecx
	andq	$1, %rcx
	cmpq	$0, %rcx
	movq	%rsi, -240(%rbp)        ## 8-byte Spill
	movq	%rax, -248(%rbp)        ## 8-byte Spill
	je	LBB7_5
## BB#4:
	movq	-248(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	%rcx, -256(%rbp)        ## 8-byte Spill
	jmp	LBB7_6
LBB7_5:
	movq	-248(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rcx
	movzbl	(%rcx), %edx
	sarl	$1, %edx
	movslq	%edx, %rcx
	movq	%rcx, -256(%rbp)        ## 8-byte Spill
LBB7_6:
	movq	-256(%rbp), %rax        ## 8-byte Reload
	movq	-216(%rbp), %rdi        ## 8-byte Reload
	movq	-240(%rbp), %rsi        ## 8-byte Reload
	movq	%rax, %rdx
	callq	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	addq	$256, %rsp              ## imm = 0x100
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.private_extern	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_ ## -- Begin function _ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.globl	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.weak_definition	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.p2align	4, 0x90
__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_: ## @_ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
Lfunc_begin1:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception1
## BB#0:
	pushq	%rbp
Lcfi24:
	.cfi_def_cfa_offset 16
Lcfi25:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi26:
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	movq	%rdi, -72(%rbp)
	movq	-72(%rbp), %rdi
	movq	(%rdi), %rax
	movq	-24(%rax), %rax
	movq	%rdi, %rcx
	addq	%rax, %rcx
	movq	%rcx, -32(%rbp)
	movb	$10, -33(%rbp)
	movq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rax
	movq	%rdi, -80(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rax, -88(%rbp)         ## 8-byte Spill
	callq	__ZNKSt3__18ios_base6getlocEv
	movq	-88(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdi
Ltmp36:
	movq	__ZNSt3__15ctypeIcE2idE@GOTPCREL(%rip), %rsi
	callq	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp37:
	movq	%rax, -96(%rbp)         ## 8-byte Spill
	jmp	LBB8_1
LBB8_1:
	movb	-33(%rbp), %al
	movq	-96(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, -8(%rbp)
	movb	%al, -9(%rbp)
	movq	-8(%rbp), %rdx
	movq	(%rdx), %rsi
	movq	56(%rsi), %rsi
	movsbl	-9(%rbp), %edi
Ltmp38:
	movl	%edi, -100(%rbp)        ## 4-byte Spill
	movq	%rdx, %rdi
	movl	-100(%rbp), %r8d        ## 4-byte Reload
	movq	%rsi, -112(%rbp)        ## 8-byte Spill
	movl	%r8d, %esi
	movq	-112(%rbp), %rdx        ## 8-byte Reload
	callq	*%rdx
Ltmp39:
	movb	%al, -113(%rbp)         ## 1-byte Spill
	jmp	LBB8_3
LBB8_2:
Ltmp40:
	leaq	-48(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -56(%rbp)
	movl	%ecx, -60(%rbp)
	callq	__ZNSt3__16localeD1Ev
	movq	-56(%rbp), %rdi
	callq	__Unwind_Resume
LBB8_3:
	leaq	-48(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
	movq	-80(%rbp), %rdi         ## 8-byte Reload
	movb	-113(%rbp), %al         ## 1-byte Reload
	movsbl	%al, %esi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE3putEc
	movq	-72(%rbp), %rdi
	movq	%rax, -128(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE5flushEv
	movq	-72(%rbp), %rdi
	movq	%rax, -136(%rbp)        ## 8-byte Spill
	movq	%rdi, %rax
	addq	$144, %rsp
	popq	%rbp
	retq
Lfunc_end1:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table8:
Lexception1:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset14 = Lfunc_begin1-Lfunc_begin1      ## >> Call Site 1 <<
	.long	Lset14
Lset15 = Ltmp36-Lfunc_begin1            ##   Call between Lfunc_begin1 and Ltmp36
	.long	Lset15
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset16 = Ltmp36-Lfunc_begin1            ## >> Call Site 2 <<
	.long	Lset16
Lset17 = Ltmp39-Ltmp36                  ##   Call between Ltmp36 and Ltmp39
	.long	Lset17
Lset18 = Ltmp40-Lfunc_begin1            ##     jumps to Ltmp40
	.long	Lset18
	.byte	0                       ##   On action: cleanup
Lset19 = Ltmp39-Lfunc_begin1            ## >> Call Site 3 <<
	.long	Lset19
Lset20 = Lfunc_end1-Ltmp39              ##   Call between Ltmp39 and Lfunc_end1
	.long	Lset20
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__13mapINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciENS_4lessIS6_EENS4_INS_4pairIKS6_SB_EEEEED1Ev ## -- Begin function _ZNSt3__13mapINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciENS_4lessIS6_EENS4_INS_4pairIKS6_SB_EEEEED1Ev
	.weak_def_can_be_hidden	__ZNSt3__13mapINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciENS_4lessIS6_EENS4_INS_4pairIKS6_SB_EEEEED1Ev
	.p2align	4, 0x90
__ZNSt3__13mapINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciENS_4lessIS6_EENS4_INS_4pairIKS6_SB_EEEEED1Ev: ## @_ZNSt3__13mapINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciENS_4lessIS6_EENS4_INS_4pairIKS6_SB_EEEEED1Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi27:
	.cfi_def_cfa_offset 16
Lcfi28:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi29:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__13mapINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciENS_4lessIS6_EENS4_INS_4pairIKS6_SB_EEEEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED2Ev ## -- Begin function _ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED2Ev
	.weak_def_can_be_hidden	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED2Ev
	.p2align	4, 0x90
__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED2Ev: ## @_ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi30:
	.cfi_def_cfa_offset 16
Lcfi31:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi32:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEC2ERKSD_ ## -- Begin function _ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEC2ERKSD_
	.weak_def_can_be_hidden	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEC2ERKSD_
	.p2align	4, 0x90
__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEC2ERKSD_: ## @_ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEC2ERKSD_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi33:
	.cfi_def_cfa_offset 16
Lcfi34:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi35:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	movq	-16(%rbp), %rdi
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rsi, %rdi
	movq	-24(%rbp), %rax         ## 8-byte Reload
	movq	%rsi, -32(%rbp)         ## 8-byte Spill
	movq	%rax, %rsi
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1ERKS5_
	movq	-16(%rbp), %rax
	movq	24(%rax), %rax
	movq	-32(%rbp), %rsi         ## 8-byte Reload
	movq	%rax, 24(%rsi)
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__13mapINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciENS_4lessIS6_EENS4_INS_4pairIKS6_SB_EEEEED2Ev ## -- Begin function _ZNSt3__13mapINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciENS_4lessIS6_EENS4_INS_4pairIKS6_SB_EEEEED2Ev
	.weak_def_can_be_hidden	__ZNSt3__13mapINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciENS_4lessIS6_EENS4_INS_4pairIKS6_SB_EEEEED2Ev
	.p2align	4, 0x90
__ZNSt3__13mapINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciENS_4lessIS6_EENS4_INS_4pairIKS6_SB_EEEEED2Ev: ## @_ZNSt3__13mapINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciENS_4lessIS6_EENS4_INS_4pairIKS6_SB_EEEEED2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi36:
	.cfi_def_cfa_offset 16
Lcfi37:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi38:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEED1Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEED1Ev ## -- Begin function _ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEED1Ev
	.weak_def_can_be_hidden	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEED1Ev
	.p2align	4, 0x90
__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEED1Ev: ## @_ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEED1Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi39:
	.cfi_def_cfa_offset 16
Lcfi40:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi41:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEED2Ev ## -- Begin function _ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEED2Ev
	.weak_def_can_be_hidden	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEED2Ev
	.p2align	4, 0x90
__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEED2Ev: ## @_ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEED2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi42:
	.cfi_def_cfa_offset 16
Lcfi43:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi44:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movq	-56(%rbp), %rdi
	movq	%rdi, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	callq	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE7destroyEPNS_11__tree_nodeISD_PvEE
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE7destroyEPNS_11__tree_nodeISD_PvEE ## -- Begin function _ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE7destroyEPNS_11__tree_nodeISD_PvEE
	.weak_definition	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE7destroyEPNS_11__tree_nodeISD_PvEE
	.p2align	4, 0x90
__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE7destroyEPNS_11__tree_nodeISD_PvEE: ## @_ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE7destroyEPNS_11__tree_nodeISD_PvEE
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi45:
	.cfi_def_cfa_offset 16
Lcfi46:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi47:
	.cfi_def_cfa_register %rbp
	subq	$192, %rsp
	movq	%rdi, -152(%rbp)
	movq	%rsi, -160(%rbp)
	movq	-152(%rbp), %rsi
	cmpq	$0, -160(%rbp)
	movq	%rsi, -176(%rbp)        ## 8-byte Spill
	je	LBB15_4
## BB#1:
	movq	-160(%rbp), %rax
	movq	(%rax), %rax
	movq	-176(%rbp), %rdi        ## 8-byte Reload
	movq	%rax, %rsi
	callq	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE7destroyEPNS_11__tree_nodeISD_PvEE
	movq	-160(%rbp), %rax
	movq	8(%rax), %rax
	movq	-176(%rbp), %rdi        ## 8-byte Reload
	movq	%rax, %rsi
	callq	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE7destroyEPNS_11__tree_nodeISD_PvEE
	movq	-176(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rsi
	addq	$8, %rsi
	movq	%rsi, -80(%rbp)
	movq	-80(%rbp), %rsi
	movq	%rsi, -72(%rbp)
	movq	-72(%rbp), %rsi
	movq	%rsi, -168(%rbp)
	movq	-168(%rbp), %rsi
	movq	-160(%rbp), %rdi
	addq	$32, %rdi
	movq	%rdi, -64(%rbp)
	movq	-64(%rbp), %rdi
	movq	%rdi, -56(%rbp)
	movq	-56(%rbp), %rdi
	movq	%rsi, -184(%rbp)        ## 8-byte Spill
	movq	%rdi, -192(%rbp)        ## 8-byte Spill
## BB#2:
	movq	-184(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -24(%rbp)
	movq	-192(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -32(%rbp)
	movq	-24(%rbp), %rdx
	movq	-32(%rbp), %rsi
	movq	%rdx, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdi
	callq	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED1Ev
## BB#3:
	movq	-168(%rbp), %rax
	movq	-160(%rbp), %rcx
	movq	%rax, -128(%rbp)
	movq	%rcx, -136(%rbp)
	movq	$1, -144(%rbp)
	movq	-128(%rbp), %rax
	movq	-136(%rbp), %rcx
	movq	-144(%rbp), %rdx
	movq	%rax, -104(%rbp)
	movq	%rcx, -112(%rbp)
	movq	%rdx, -120(%rbp)
	movq	-112(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rdi
	callq	__ZdlPv
LBB15_4:
	addq	$192, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.private_extern	___clang_call_terminate ## -- Begin function __clang_call_terminate
	.globl	___clang_call_terminate
	.weak_definition	___clang_call_terminate
	.p2align	4, 0x90
___clang_call_terminate:                ## @__clang_call_terminate
## BB#0:
	pushq	%rax
	callq	___cxa_begin_catch
	movq	%rax, (%rsp)            ## 8-byte Spill
	callq	__ZSt9terminatev
                                        ## -- End function
	.globl	__ZNSt3__111char_traitsIcE6lengthEPKc ## -- Begin function _ZNSt3__111char_traitsIcE6lengthEPKc
	.weak_definition	__ZNSt3__111char_traitsIcE6lengthEPKc
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE6lengthEPKc:  ## @_ZNSt3__111char_traitsIcE6lengthEPKc
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi48:
	.cfi_def_cfa_offset 16
Lcfi49:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi50:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	_strlen
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEEC1ERKSH_ ## -- Begin function _ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEEC1ERKSH_
	.weak_def_can_be_hidden	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEEC1ERKSH_
	.p2align	4, 0x90
__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEEC1ERKSH_: ## @_ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEEC1ERKSH_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi51:
	.cfi_def_cfa_offset 16
Lcfi52:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi53:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	callq	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEEC2ERKSH_
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEEC2ERKSH_ ## -- Begin function _ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEEC2ERKSH_
	.weak_def_can_be_hidden	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEEC2ERKSH_
	.p2align	4, 0x90
__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEEC2ERKSH_: ## @_ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEEC2ERKSH_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi54:
	.cfi_def_cfa_offset 16
Lcfi55:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi56:
	.cfi_def_cfa_register %rbp
	subq	$120, %rsp
	movq	%rdi, -224(%rbp)
	movq	%rsi, -232(%rbp)
	movq	-224(%rbp), %rsi
	movq	%rsi, %rdi
	addq	$8, %rdi
	movq	%rdi, -216(%rbp)
	movq	-216(%rbp), %rdi
	movq	%rdi, -208(%rbp)
	movq	-208(%rbp), %rdi
	movq	%rdi, %rax
	movq	%rax, -200(%rbp)
	movq	-200(%rbp), %rax
	movq	%rax, -192(%rbp)
	movq	-192(%rbp), %rax
	movq	%rax, -184(%rbp)
	movq	-184(%rbp), %rax
	movq	$0, (%rax)
	movq	%rdi, -176(%rbp)
	movq	-176(%rbp), %rax
	movq	%rax, -168(%rbp)
	movq	%rsi, -248(%rbp)        ## 8-byte Spill
## BB#1:
	leaq	-236(%rbp), %rax
	movq	-248(%rbp), %rcx        ## 8-byte Reload
	addq	$16, %rcx
	movl	$0, -236(%rbp)
	movq	-232(%rbp), %rdx
	movq	%rcx, -144(%rbp)
	movq	%rax, -152(%rbp)
	movq	%rdx, -160(%rbp)
	movq	-144(%rbp), %rax
	movq	-152(%rbp), %rcx
	movq	-160(%rbp), %rdx
	movq	%rax, -120(%rbp)
	movq	%rcx, -128(%rbp)
	movq	%rdx, -136(%rbp)
	movq	-120(%rbp), %rax
	movq	%rax, %rcx
	movq	-128(%rbp), %rdx
	movq	%rdx, -112(%rbp)
	movq	-112(%rbp), %rdx
	movq	%rcx, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-64(%rbp), %rcx
	movq	-72(%rbp), %rdx
	movq	%rdx, -56(%rbp)
	movq	-56(%rbp), %rdx
	movslq	(%rdx), %rdx
	movq	%rdx, (%rcx)
	movq	-136(%rbp), %rcx
	movq	%rcx, -80(%rbp)
	movq	-80(%rbp), %rcx
	movq	%rax, -96(%rbp)
	movq	%rcx, -104(%rbp)
	movq	-104(%rbp), %rax
	movq	%rax, -88(%rbp)
## BB#2:
	movq	-248(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rcx
	addq	$8, %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rcx
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rdx
	movq	%rcx, (%rdx)
	addq	$120, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE30__emplace_hint_unique_key_argsIS7_JRKNS_4pairIKS7_SC_EEEEENS_15__tree_iteratorISD_PNS_11__tree_nodeISD_PvEElEENS_21__tree_const_iteratorISD_SU_lEERKT_DpOT0_ ## -- Begin function _ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE30__emplace_hint_unique_key_argsIS7_JRKNS_4pairIKS7_SC_EEEEENS_15__tree_iteratorISD_PNS_11__tree_nodeISD_PvEElEENS_21__tree_const_iteratorISD_SU_lEERKT_DpOT0_
	.weak_definition	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE30__emplace_hint_unique_key_argsIS7_JRKNS_4pairIKS7_SC_EEEEENS_15__tree_iteratorISD_PNS_11__tree_nodeISD_PvEElEENS_21__tree_const_iteratorISD_SU_lEERKT_DpOT0_
	.p2align	4, 0x90
__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE30__emplace_hint_unique_key_argsIS7_JRKNS_4pairIKS7_SC_EEEEENS_15__tree_iteratorISD_PNS_11__tree_nodeISD_PvEElEENS_21__tree_const_iteratorISD_SU_lEERKT_DpOT0_: ## @_ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE30__emplace_hint_unique_key_argsIS7_JRKNS_4pairIKS7_SC_EEEEENS_15__tree_iteratorISD_PNS_11__tree_nodeISD_PvEElEENS_21__tree_const_iteratorISD_SU_lEERKT_DpOT0_
Lfunc_begin2:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception2
## BB#0:
	pushq	%rbp
Lcfi57:
	.cfi_def_cfa_offset 16
Lcfi58:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi59:
	.cfi_def_cfa_register %rbp
	subq	$736, %rsp              ## imm = 0x2E0
	leaq	-608(%rbp), %rax
	leaq	-616(%rbp), %r8
	movq	%rsi, -576(%rbp)
	movq	%rdi, -584(%rbp)
	movq	%rdx, -592(%rbp)
	movq	%rcx, -600(%rbp)
	movq	-584(%rbp), %rcx
	movq	-576(%rbp), %rdx
	movq	%rdx, -632(%rbp)
	movq	-592(%rbp), %rdx
	movq	-632(%rbp), %rsi
	movq	%rcx, %rdi
	movq	%rdx, -688(%rbp)        ## 8-byte Spill
	movq	%rax, %rdx
	movq	%rcx, -696(%rbp)        ## 8-byte Spill
	movq	%r8, %rcx
	movq	-688(%rbp), %r8         ## 8-byte Reload
	callq	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorISD_PNS_11__tree_nodeISD_SM_EElEERPNS_15__tree_end_nodeISO_EESP_RKT_
	movq	%rax, -624(%rbp)
	movq	-624(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -640(%rbp)
	movq	-624(%rbp), %rax
	cmpq	$0, (%rax)
	jne	LBB20_16
## BB#1:
	movq	-600(%rbp), %rax
	movq	%rax, -560(%rbp)
	movq	-560(%rbp), %rdx
	leaq	-664(%rbp), %rax
	movq	%rax, %rdi
	movq	-696(%rbp), %rsi        ## 8-byte Reload
	movq	%rax, -704(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE16__construct_nodeIJRKNS_4pairIKS7_SC_EEEEENS_10unique_ptrINS_11__tree_nodeISD_PvEENS_22__tree_node_destructorINS5_IST_EEEEEEDpOT_
	movq	-608(%rbp), %rsi
	movq	-624(%rbp), %rdx
	movq	-704(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -296(%rbp)
	movq	-296(%rbp), %rdi
	movq	%rdi, -288(%rbp)
	movq	-288(%rbp), %rdi
	movq	%rdi, -280(%rbp)
	movq	-280(%rbp), %rdi
	movq	(%rdi), %rcx
Ltmp41:
	movq	-696(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE16__insert_node_atEPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEERSO_SO_
Ltmp42:
	jmp	LBB20_2
LBB20_2:
	leaq	-664(%rbp), %rax
	movq	%rax, -264(%rbp)
	movq	-264(%rbp), %rcx
	movq	%rcx, -256(%rbp)
	movq	-256(%rbp), %rdx
	movq	%rdx, -248(%rbp)
	movq	-248(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, -272(%rbp)
	movq	%rcx, -240(%rbp)
	movq	-240(%rbp), %rcx
	movq	%rcx, -232(%rbp)
	movq	-232(%rbp), %rcx
	movq	$0, (%rcx)
	movq	-272(%rbp), %rcx
	movq	%rcx, -640(%rbp)
	movq	%rax, -224(%rbp)
	movq	-224(%rbp), %rax
	movq	%rax, -216(%rbp)
	movq	-216(%rbp), %rax
	movq	%rax, -192(%rbp)
	movq	$0, -200(%rbp)
	movq	-192(%rbp), %rax
	movq	%rax, -184(%rbp)
	movq	-184(%rbp), %rcx
	movq	%rcx, -176(%rbp)
	movq	-176(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -208(%rbp)
	movq	-200(%rbp), %rcx
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rdx
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	%rcx, (%rdx)
	cmpq	$0, -208(%rbp)
	movq	%rax, -712(%rbp)        ## 8-byte Spill
	je	LBB20_8
## BB#3:
	movq	-712(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rcx
	addq	$8, %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	-208(%rbp), %rdx
	movq	%rcx, -160(%rbp)
	movq	%rdx, -168(%rbp)
	movq	-160(%rbp), %rcx
	testb	$1, 8(%rcx)
	movq	%rcx, -720(%rbp)        ## 8-byte Spill
	je	LBB20_5
## BB#4:
	movq	-720(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-168(%rbp), %rdx
	addq	$32, %rdx
	movq	%rdx, -152(%rbp)
	movq	-152(%rbp), %rdx
	movq	%rdx, -144(%rbp)
	movq	-144(%rbp), %rdx
	movq	%rcx, -112(%rbp)
	movq	%rdx, -120(%rbp)
	movq	-112(%rbp), %rcx
	movq	-120(%rbp), %rdx
	movq	%rcx, -96(%rbp)
	movq	%rdx, -104(%rbp)
	movq	-104(%rbp), %rdi
	callq	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED1Ev
LBB20_5:
	cmpq	$0, -168(%rbp)
	je	LBB20_7
## BB#6:
	movq	-720(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-168(%rbp), %rdx
	movq	%rcx, -72(%rbp)
	movq	%rdx, -80(%rbp)
	movq	$1, -88(%rbp)
	movq	-72(%rbp), %rcx
	movq	-80(%rbp), %rdx
	movq	-88(%rbp), %rsi
	movq	%rcx, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	-56(%rbp), %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rdi
	callq	__ZdlPv
LBB20_7:
	jmp	LBB20_8
LBB20_8:
	jmp	LBB20_16
LBB20_9:
Ltmp43:
	leaq	-664(%rbp), %rcx
	movl	%edx, %esi
	movq	%rax, -672(%rbp)
	movl	%esi, -676(%rbp)
	movq	%rcx, -520(%rbp)
	movq	-520(%rbp), %rax
	movq	%rax, -512(%rbp)
	movq	-512(%rbp), %rax
	movq	%rax, -488(%rbp)
	movq	$0, -496(%rbp)
	movq	-488(%rbp), %rax
	movq	%rax, -480(%rbp)
	movq	-480(%rbp), %rcx
	movq	%rcx, -472(%rbp)
	movq	-472(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -504(%rbp)
	movq	-496(%rbp), %rcx
	movq	%rax, -328(%rbp)
	movq	-328(%rbp), %rdx
	movq	%rdx, -320(%rbp)
	movq	-320(%rbp), %rdx
	movq	%rcx, (%rdx)
	cmpq	$0, -504(%rbp)
	movq	%rax, -728(%rbp)        ## 8-byte Spill
	je	LBB20_15
## BB#10:
	movq	-728(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -312(%rbp)
	movq	-312(%rbp), %rcx
	addq	$8, %rcx
	movq	%rcx, -304(%rbp)
	movq	-304(%rbp), %rcx
	movq	-504(%rbp), %rdx
	movq	%rcx, -456(%rbp)
	movq	%rdx, -464(%rbp)
	movq	-456(%rbp), %rcx
	testb	$1, 8(%rcx)
	movq	%rcx, -736(%rbp)        ## 8-byte Spill
	je	LBB20_12
## BB#11:
	movq	-736(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-464(%rbp), %rdx
	addq	$32, %rdx
	movq	%rdx, -448(%rbp)
	movq	-448(%rbp), %rdx
	movq	%rdx, -440(%rbp)
	movq	-440(%rbp), %rdx
	movq	%rcx, -408(%rbp)
	movq	%rdx, -416(%rbp)
	movq	-408(%rbp), %rcx
	movq	-416(%rbp), %rdx
	movq	%rcx, -392(%rbp)
	movq	%rdx, -400(%rbp)
	movq	-400(%rbp), %rdi
	callq	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED1Ev
LBB20_12:
	cmpq	$0, -464(%rbp)
	je	LBB20_14
## BB#13:
	movq	-736(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-464(%rbp), %rdx
	movq	%rcx, -368(%rbp)
	movq	%rdx, -376(%rbp)
	movq	$1, -384(%rbp)
	movq	-368(%rbp), %rcx
	movq	-376(%rbp), %rdx
	movq	-384(%rbp), %rsi
	movq	%rcx, -344(%rbp)
	movq	%rdx, -352(%rbp)
	movq	%rsi, -360(%rbp)
	movq	-352(%rbp), %rcx
	movq	%rcx, -336(%rbp)
	movq	-336(%rbp), %rdi
	callq	__ZdlPv
LBB20_14:
	jmp	LBB20_15
LBB20_15:
	jmp	LBB20_17
LBB20_16:
	leaq	-568(%rbp), %rax
	movq	-640(%rbp), %rcx
	movq	%rax, -544(%rbp)
	movq	%rcx, -552(%rbp)
	movq	-544(%rbp), %rax
	movq	-552(%rbp), %rcx
	movq	%rax, -528(%rbp)
	movq	%rcx, -536(%rbp)
	movq	-528(%rbp), %rax
	movq	-536(%rbp), %rcx
	movq	%rcx, (%rax)
	movq	-568(%rbp), %rax
	addq	$736, %rsp              ## imm = 0x2E0
	popq	%rbp
	retq
LBB20_17:
	movq	-672(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end2:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table20:
Lexception2:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset21 = Lfunc_begin2-Lfunc_begin2      ## >> Call Site 1 <<
	.long	Lset21
Lset22 = Ltmp41-Lfunc_begin2            ##   Call between Lfunc_begin2 and Ltmp41
	.long	Lset22
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset23 = Ltmp41-Lfunc_begin2            ## >> Call Site 2 <<
	.long	Lset23
Lset24 = Ltmp42-Ltmp41                  ##   Call between Ltmp41 and Ltmp42
	.long	Lset24
Lset25 = Ltmp43-Lfunc_begin2            ##     jumps to Ltmp43
	.long	Lset25
	.byte	0                       ##   On action: cleanup
Lset26 = Ltmp42-Lfunc_begin2            ## >> Call Site 3 <<
	.long	Lset26
Lset27 = Lfunc_end2-Ltmp42              ##   Call between Ltmp42 and Lfunc_end2
	.long	Lset27
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorISD_PNS_11__tree_nodeISD_SM_EElEERPNS_15__tree_end_nodeISO_EESP_RKT_ ## -- Begin function _ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorISD_PNS_11__tree_nodeISD_SM_EElEERPNS_15__tree_end_nodeISO_EESP_RKT_
	.weak_definition	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorISD_PNS_11__tree_nodeISD_SM_EElEERPNS_15__tree_end_nodeISO_EESP_RKT_
	.p2align	4, 0x90
__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorISD_PNS_11__tree_nodeISD_SM_EElEERPNS_15__tree_end_nodeISO_EESP_RKT_: ## @_ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorISD_PNS_11__tree_nodeISD_SM_EElEERPNS_15__tree_end_nodeISO_EESP_RKT_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi60:
	.cfi_def_cfa_offset 16
Lcfi61:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi62:
	.cfi_def_cfa_register %rbp
	subq	$4256, %rsp             ## imm = 0x10A0
	movb	$1, %al
	leaq	-3640(%rbp), %r9
	leaq	-3600(%rbp), %r10
	leaq	-3576(%rbp), %r11
	movq	%rsi, -3600(%rbp)
	movq	%rdi, -3608(%rbp)
	movq	%rdx, -3616(%rbp)
	movq	%rcx, -3624(%rbp)
	movq	%r8, -3632(%rbp)
	movq	-3608(%rbp), %rcx
	movq	%rcx, -3584(%rbp)
	movq	-3584(%rbp), %rdx
	movq	%rdx, -3568(%rbp)
	movq	-3568(%rbp), %rdx
	addq	$8, %rdx
	movq	%rdx, -3560(%rbp)
	movq	-3560(%rbp), %rdx
	movq	%rdx, -3552(%rbp)
	movq	-3552(%rbp), %rdx
	movq	%rdx, -3544(%rbp)
	movq	-3544(%rbp), %rdx
	movq	%rdx, -3536(%rbp)
	movq	-3536(%rbp), %rdx
	movq	%r11, -3520(%rbp)
	movq	%rdx, -3528(%rbp)
	movq	-3520(%rbp), %rdx
	movq	-3528(%rbp), %rsi
	movq	%rdx, -3504(%rbp)
	movq	%rsi, -3512(%rbp)
	movq	-3504(%rbp), %rdx
	movq	-3512(%rbp), %rsi
	movq	%rsi, (%rdx)
	movq	-3576(%rbp), %rdx
	movq	%rdx, -3648(%rbp)
	movq	-3648(%rbp), %rdx
	movq	%rdx, -3488(%rbp)
	movq	%r9, -3496(%rbp)
	movq	-3496(%rbp), %rdx
	movq	-3488(%rbp), %rsi
	movq	%rsi, -3472(%rbp)
	movq	%rdx, -3480(%rbp)
	movq	-3480(%rbp), %rdx
	movq	-3472(%rbp), %rsi
	movq	%rsi, (%rdx)
	movq	%r10, -2752(%rbp)
	movq	%r9, -2760(%rbp)
	movq	-2752(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-2760(%rbp), %rsi
	cmpq	(%rsi), %rdx
	movq	%rcx, -3712(%rbp)       ## 8-byte Spill
	movb	%al, -3713(%rbp)        ## 1-byte Spill
	je	LBB21_24
## BB#1:
	leaq	-3600(%rbp), %rax
	movq	-3712(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1680(%rbp)
	movq	-1680(%rbp), %rdx
	addq	$16, %rdx
	movq	%rdx, -1672(%rbp)
	movq	-1672(%rbp), %rdx
	movq	%rdx, -1664(%rbp)
	movq	-1664(%rbp), %rdx
	movq	-3632(%rbp), %rsi
	movq	%rax, -1616(%rbp)
	movq	-1616(%rbp), %rax
	movq	%rax, -1608(%rbp)
	movq	-1608(%rbp), %rax
	movq	(%rax), %rax
	addq	$32, %rax
	movq	%rdx, -888(%rbp)
	movq	%rsi, -896(%rbp)
	movq	%rax, -904(%rbp)
	movq	-888(%rbp), %rax
	movq	-896(%rbp), %rdx
	movq	-904(%rbp), %rsi
	movq	%rax, -864(%rbp)
	movq	%rdx, -872(%rbp)
	movq	%rsi, -880(%rbp)
	movq	-872(%rbp), %rax
	movq	-880(%rbp), %rdx
	movq	%rax, -848(%rbp)
	movq	%rdx, -856(%rbp)
	movq	-848(%rbp), %rax
	movq	-856(%rbp), %rdx
	movq	%rax, -816(%rbp)
	movq	%rdx, -824(%rbp)
	movq	-816(%rbp), %rax
	movq	-824(%rbp), %rdx
	movq	%rdx, -808(%rbp)
	movq	-808(%rbp), %rdx
	movq	%rdx, -784(%rbp)
	movq	-784(%rbp), %rsi
	movq	%rsi, -776(%rbp)
	movq	-776(%rbp), %rsi
	movq	%rsi, -768(%rbp)
	movq	-768(%rbp), %rdi
	movq	%rdi, -760(%rbp)
	movq	-760(%rbp), %rdi
	movq	%rdi, -752(%rbp)
	movq	-752(%rbp), %rdi
	movzbl	(%rdi), %r8d
	movl	%r8d, %edi
	andq	$1, %rdi
	cmpq	$0, %rdi
	movq	%rax, -3728(%rbp)       ## 8-byte Spill
	movq	%rdx, -3736(%rbp)       ## 8-byte Spill
	movq	%rsi, -3744(%rbp)       ## 8-byte Spill
	je	LBB21_3
## BB#2:
	movq	-3744(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -704(%rbp)
	movq	-704(%rbp), %rcx
	movq	%rcx, -696(%rbp)
	movq	-696(%rbp), %rcx
	movq	%rcx, -688(%rbp)
	movq	-688(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -3752(%rbp)       ## 8-byte Spill
	jmp	LBB21_4
LBB21_3:
	movq	-3744(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -744(%rbp)
	movq	-744(%rbp), %rcx
	movq	%rcx, -736(%rbp)
	movq	-736(%rbp), %rcx
	movq	%rcx, -728(%rbp)
	movq	-728(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -720(%rbp)
	movq	-720(%rbp), %rcx
	movq	%rcx, -712(%rbp)
	movq	-712(%rbp), %rcx
	movq	%rcx, -3752(%rbp)       ## 8-byte Spill
LBB21_4:
	movq	-3752(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -680(%rbp)
	movq	-680(%rbp), %rax
	movq	-3736(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -672(%rbp)
	movq	-672(%rbp), %rdx
	movq	%rdx, -664(%rbp)
	movq	-664(%rbp), %rsi
	movq	%rsi, -656(%rbp)
	movq	-656(%rbp), %rsi
	movq	%rsi, -648(%rbp)
	movq	-648(%rbp), %rsi
	movzbl	(%rsi), %edi
	movl	%edi, %esi
	andq	$1, %rsi
	cmpq	$0, %rsi
	movq	%rax, -3760(%rbp)       ## 8-byte Spill
	movq	%rdx, -3768(%rbp)       ## 8-byte Spill
	je	LBB21_6
## BB#5:
	movq	-3768(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -616(%rbp)
	movq	-616(%rbp), %rcx
	movq	%rcx, -608(%rbp)
	movq	-608(%rbp), %rcx
	movq	%rcx, -600(%rbp)
	movq	-600(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	%rcx, -3776(%rbp)       ## 8-byte Spill
	jmp	LBB21_7
LBB21_6:
	movq	-3768(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -640(%rbp)
	movq	-640(%rbp), %rcx
	movq	%rcx, -632(%rbp)
	movq	-632(%rbp), %rcx
	movq	%rcx, -624(%rbp)
	movq	-624(%rbp), %rcx
	movzbl	(%rcx), %edx
	sarl	$1, %edx
	movslq	%edx, %rcx
	movq	%rcx, -3776(%rbp)       ## 8-byte Spill
LBB21_7:
	movq	-3776(%rbp), %rax       ## 8-byte Reload
	leaq	-800(%rbp), %rcx
	movq	%rcx, -576(%rbp)
	movq	-3760(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -584(%rbp)
	movq	%rax, -592(%rbp)
	movq	-576(%rbp), %rax
	movq	-584(%rbp), %rdx
	movq	-592(%rbp), %rsi
	movq	%rax, -552(%rbp)
	movq	%rdx, -560(%rbp)
	movq	%rsi, -568(%rbp)
	movq	-552(%rbp), %rax
	movq	-560(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-568(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-800(%rbp), %rax
	movq	-792(%rbp), %rdx
	movq	%rax, -840(%rbp)
	movq	%rdx, -832(%rbp)
	movq	-840(%rbp), %rax
	movq	-832(%rbp), %rdx
	movq	%rax, -512(%rbp)
	movq	%rdx, -504(%rbp)
	movq	-3728(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -520(%rbp)
	movq	-520(%rbp), %rdx
	movq	%rdx, -488(%rbp)
	movq	-488(%rbp), %rsi
	movq	%rsi, -480(%rbp)
	movq	-480(%rbp), %rdi
	movq	%rdi, -472(%rbp)
	movq	-472(%rbp), %rdi
	movq	%rdi, -464(%rbp)
	movq	-464(%rbp), %rdi
	movzbl	(%rdi), %r8d
	movl	%r8d, %edi
	andq	$1, %rdi
	cmpq	$0, %rdi
	movq	%rdx, -3784(%rbp)       ## 8-byte Spill
	movq	%rsi, -3792(%rbp)       ## 8-byte Spill
	je	LBB21_9
## BB#8:
	movq	-3792(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -432(%rbp)
	movq	-432(%rbp), %rcx
	movq	%rcx, -424(%rbp)
	movq	-424(%rbp), %rcx
	movq	%rcx, -416(%rbp)
	movq	-416(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	%rcx, -3800(%rbp)       ## 8-byte Spill
	jmp	LBB21_10
LBB21_9:
	movq	-3792(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -456(%rbp)
	movq	-456(%rbp), %rcx
	movq	%rcx, -448(%rbp)
	movq	-448(%rbp), %rcx
	movq	%rcx, -440(%rbp)
	movq	-440(%rbp), %rcx
	movzbl	(%rcx), %edx
	sarl	$1, %edx
	movslq	%edx, %rcx
	movq	%rcx, -3800(%rbp)       ## 8-byte Spill
LBB21_10:
	movq	-3800(%rbp), %rax       ## 8-byte Reload
	leaq	-512(%rbp), %rcx
	movq	%rax, -528(%rbp)
	movq	%rcx, -408(%rbp)
	movq	-408(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -536(%rbp)
	movq	-3784(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -400(%rbp)
	movq	-400(%rbp), %rcx
	movq	%rcx, -392(%rbp)
	movq	-392(%rbp), %rcx
	movq	%rcx, -384(%rbp)
	movq	-384(%rbp), %rdx
	movq	%rdx, -376(%rbp)
	movq	-376(%rbp), %rdx
	movq	%rdx, -368(%rbp)
	movq	-368(%rbp), %rdx
	movzbl	(%rdx), %esi
	movl	%esi, %edx
	andq	$1, %rdx
	cmpq	$0, %rdx
	movq	%rcx, -3808(%rbp)       ## 8-byte Spill
	je	LBB21_12
## BB#11:
	movq	-3808(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -320(%rbp)
	movq	-320(%rbp), %rcx
	movq	%rcx, -312(%rbp)
	movq	-312(%rbp), %rcx
	movq	%rcx, -304(%rbp)
	movq	-304(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -3816(%rbp)       ## 8-byte Spill
	jmp	LBB21_13
LBB21_12:
	movq	-3808(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -360(%rbp)
	movq	-360(%rbp), %rcx
	movq	%rcx, -352(%rbp)
	movq	-352(%rbp), %rcx
	movq	%rcx, -344(%rbp)
	movq	-344(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -336(%rbp)
	movq	-336(%rbp), %rcx
	movq	%rcx, -328(%rbp)
	movq	-328(%rbp), %rcx
	movq	%rcx, -3816(%rbp)       ## 8-byte Spill
LBB21_13:
	movq	-3816(%rbp), %rax       ## 8-byte Reload
	leaq	-248(%rbp), %rcx
	leaq	-536(%rbp), %rdx
	leaq	-528(%rbp), %rsi
	leaq	-512(%rbp), %rdi
	movq	%rax, -296(%rbp)
	movq	-296(%rbp), %rax
	movq	%rdi, -216(%rbp)
	movq	-216(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rsi, -272(%rbp)
	movq	%rdx, -280(%rbp)
	movq	-272(%rbp), %rdx
	movq	-280(%rbp), %rsi
	movq	%rdx, -256(%rbp)
	movq	%rsi, -264(%rbp)
	movq	-264(%rbp), %rdx
	movq	-256(%rbp), %rsi
	movq	%rcx, -224(%rbp)
	movq	%rdx, -232(%rbp)
	movq	%rsi, -240(%rbp)
	movq	-232(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-240(%rbp), %rdx
	cmpq	(%rdx), %rcx
	movq	%rax, -3824(%rbp)       ## 8-byte Spill
	movq	%rdi, -3832(%rbp)       ## 8-byte Spill
	jae	LBB21_15
## BB#14:
	movq	-264(%rbp), %rax
	movq	%rax, -3840(%rbp)       ## 8-byte Spill
	jmp	LBB21_16
LBB21_15:
	movq	-256(%rbp), %rax
	movq	%rax, -3840(%rbp)       ## 8-byte Spill
LBB21_16:
	movq	-3840(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rdx
	movq	-3824(%rbp), %rdi       ## 8-byte Reload
	movq	-3832(%rbp), %rsi       ## 8-byte Reload
	callq	__ZNSt3__111char_traitsIcE7compareEPKcS3_m
	movl	%eax, -540(%rbp)
	cmpl	$0, -540(%rbp)
	je	LBB21_18
## BB#17:
	movl	-540(%rbp), %eax
	movl	%eax, -492(%rbp)
	jmp	LBB21_23
LBB21_18:
	movq	-528(%rbp), %rax
	cmpq	-536(%rbp), %rax
	jae	LBB21_20
## BB#19:
	movl	$-1, -492(%rbp)
	jmp	LBB21_23
LBB21_20:
	movq	-528(%rbp), %rax
	cmpq	-536(%rbp), %rax
	jbe	LBB21_22
## BB#21:
	movl	$1, -492(%rbp)
	jmp	LBB21_23
LBB21_22:
	movl	$0, -492(%rbp)
LBB21_23:
	cmpl	$0, -492(%rbp)
	setl	%al
	movb	%al, -3713(%rbp)        ## 1-byte Spill
LBB21_24:
	movb	-3713(%rbp), %al        ## 1-byte Reload
	testb	$1, %al
	jne	LBB21_25
	jmp	LBB21_63
LBB21_25:
	movb	$1, %al
	leaq	-3664(%rbp), %rcx
	leaq	-3656(%rbp), %rdx
	leaq	-200(%rbp), %rsi
	movq	-3600(%rbp), %rdi
	movq	%rdi, -3656(%rbp)
	movq	-3712(%rbp), %rdi       ## 8-byte Reload
	movq	%rdi, -208(%rbp)
	movq	-208(%rbp), %r8
	movq	%r8, -192(%rbp)
	movq	-192(%rbp), %r8
	movq	(%r8), %r8
	movq	%rsi, -176(%rbp)
	movq	%r8, -184(%rbp)
	movq	-176(%rbp), %rsi
	movq	-184(%rbp), %r8
	movq	%rsi, -160(%rbp)
	movq	%r8, -168(%rbp)
	movq	-160(%rbp), %rsi
	movq	-168(%rbp), %r8
	movq	%r8, (%rsi)
	movq	-200(%rbp), %rsi
	movq	%rsi, -3672(%rbp)
	movq	-3672(%rbp), %rsi
	movq	%rsi, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rsi
	movq	-24(%rbp), %r8
	movq	%r8, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %r8
	movq	%r8, (%rsi)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-40(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-48(%rbp), %rdx
	cmpq	(%rdx), %rcx
	movb	%al, -3841(%rbp)        ## 1-byte Spill
	je	LBB21_58
## BB#26:
	leaq	-3656(%rbp), %rax
	movq	-3712(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -72(%rbp)
	movq	-72(%rbp), %rdx
	addq	$16, %rdx
	movq	%rdx, -64(%rbp)
	movq	-64(%rbp), %rdx
	movq	%rdx, -56(%rbp)
	movq	-56(%rbp), %rdx
	movq	%rax, -136(%rbp)
	movq	-136(%rbp), %rax
	movq	(%rax), %rsi
	movq	%rsi, -120(%rbp)
	movq	-120(%rbp), %rsi
	cmpq	$0, (%rsi)
	movq	%rdx, -3856(%rbp)       ## 8-byte Spill
	movq	%rax, -3864(%rbp)       ## 8-byte Spill
	je	LBB21_31
## BB#27:
	movq	-120(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -104(%rbp)
LBB21_28:                               ## =>This Inner Loop Header: Depth=1
	movq	-104(%rbp), %rax
	cmpq	$0, 8(%rax)
	je	LBB21_30
## BB#29:                               ##   in Loop: Header=BB21_28 Depth=1
	movq	-104(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -104(%rbp)
	jmp	LBB21_28
LBB21_30:
	movq	-104(%rbp), %rax
	movq	%rax, -112(%rbp)
	jmp	LBB21_35
LBB21_31:
	movq	-120(%rbp), %rax
	movq	%rax, -128(%rbp)
LBB21_32:                               ## =>This Inner Loop Header: Depth=1
	movq	-128(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rax
	movq	-96(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	jne	LBB21_34
## BB#33:                               ##   in Loop: Header=BB21_32 Depth=1
	movq	-128(%rbp), %rax
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -128(%rbp)
	jmp	LBB21_32
LBB21_34:
	movq	-128(%rbp), %rax
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -112(%rbp)
LBB21_35:
	movq	-112(%rbp), %rax
	movq	-3864(%rbp), %rcx       ## 8-byte Reload
	movq	%rax, (%rcx)
	movq	%rcx, -152(%rbp)
	movq	-152(%rbp), %rax
	movq	%rax, -144(%rbp)
	movq	-144(%rbp), %rax
	movq	(%rax), %rax
	addq	$32, %rax
	movq	-3632(%rbp), %rdx
	movq	-3856(%rbp), %rsi       ## 8-byte Reload
	movq	%rsi, -1584(%rbp)
	movq	%rax, -1592(%rbp)
	movq	%rdx, -1600(%rbp)
	movq	-1584(%rbp), %rax
	movq	-1592(%rbp), %rdx
	movq	-1600(%rbp), %rdi
	movq	%rax, -1560(%rbp)
	movq	%rdx, -1568(%rbp)
	movq	%rdi, -1576(%rbp)
	movq	-1568(%rbp), %rax
	movq	-1576(%rbp), %rdx
	movq	%rax, -1544(%rbp)
	movq	%rdx, -1552(%rbp)
	movq	-1544(%rbp), %rax
	movq	-1552(%rbp), %rdx
	movq	%rax, -1512(%rbp)
	movq	%rdx, -1520(%rbp)
	movq	-1512(%rbp), %rax
	movq	-1520(%rbp), %rdx
	movq	%rdx, -1504(%rbp)
	movq	-1504(%rbp), %rdx
	movq	%rdx, -1480(%rbp)
	movq	-1480(%rbp), %rdi
	movq	%rdi, -1472(%rbp)
	movq	-1472(%rbp), %rdi
	movq	%rdi, -1464(%rbp)
	movq	-1464(%rbp), %r8
	movq	%r8, -1456(%rbp)
	movq	-1456(%rbp), %r8
	movq	%r8, -1448(%rbp)
	movq	-1448(%rbp), %r8
	movzbl	(%r8), %r9d
	movl	%r9d, %r8d
	andq	$1, %r8
	cmpq	$0, %r8
	movq	%rax, -3872(%rbp)       ## 8-byte Spill
	movq	%rdx, -3880(%rbp)       ## 8-byte Spill
	movq	%rdi, -3888(%rbp)       ## 8-byte Spill
	je	LBB21_37
## BB#36:
	movq	-3888(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1400(%rbp)
	movq	-1400(%rbp), %rcx
	movq	%rcx, -1392(%rbp)
	movq	-1392(%rbp), %rcx
	movq	%rcx, -1384(%rbp)
	movq	-1384(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -3896(%rbp)       ## 8-byte Spill
	jmp	LBB21_38
LBB21_37:
	movq	-3888(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1440(%rbp)
	movq	-1440(%rbp), %rcx
	movq	%rcx, -1432(%rbp)
	movq	-1432(%rbp), %rcx
	movq	%rcx, -1424(%rbp)
	movq	-1424(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -1416(%rbp)
	movq	-1416(%rbp), %rcx
	movq	%rcx, -1408(%rbp)
	movq	-1408(%rbp), %rcx
	movq	%rcx, -3896(%rbp)       ## 8-byte Spill
LBB21_38:
	movq	-3896(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1376(%rbp)
	movq	-1376(%rbp), %rax
	movq	-3880(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1368(%rbp)
	movq	-1368(%rbp), %rdx
	movq	%rdx, -1360(%rbp)
	movq	-1360(%rbp), %rsi
	movq	%rsi, -1352(%rbp)
	movq	-1352(%rbp), %rsi
	movq	%rsi, -1344(%rbp)
	movq	-1344(%rbp), %rsi
	movzbl	(%rsi), %edi
	movl	%edi, %esi
	andq	$1, %rsi
	cmpq	$0, %rsi
	movq	%rax, -3904(%rbp)       ## 8-byte Spill
	movq	%rdx, -3912(%rbp)       ## 8-byte Spill
	je	LBB21_40
## BB#39:
	movq	-3912(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1312(%rbp)
	movq	-1312(%rbp), %rcx
	movq	%rcx, -1304(%rbp)
	movq	-1304(%rbp), %rcx
	movq	%rcx, -1296(%rbp)
	movq	-1296(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	%rcx, -3920(%rbp)       ## 8-byte Spill
	jmp	LBB21_41
LBB21_40:
	movq	-3912(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1336(%rbp)
	movq	-1336(%rbp), %rcx
	movq	%rcx, -1328(%rbp)
	movq	-1328(%rbp), %rcx
	movq	%rcx, -1320(%rbp)
	movq	-1320(%rbp), %rcx
	movzbl	(%rcx), %edx
	sarl	$1, %edx
	movslq	%edx, %rcx
	movq	%rcx, -3920(%rbp)       ## 8-byte Spill
LBB21_41:
	movq	-3920(%rbp), %rax       ## 8-byte Reload
	leaq	-1496(%rbp), %rcx
	movq	%rcx, -1272(%rbp)
	movq	-3904(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1280(%rbp)
	movq	%rax, -1288(%rbp)
	movq	-1272(%rbp), %rax
	movq	-1280(%rbp), %rdx
	movq	-1288(%rbp), %rsi
	movq	%rax, -1248(%rbp)
	movq	%rdx, -1256(%rbp)
	movq	%rsi, -1264(%rbp)
	movq	-1248(%rbp), %rax
	movq	-1256(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-1264(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-1496(%rbp), %rax
	movq	-1488(%rbp), %rdx
	movq	%rax, -1536(%rbp)
	movq	%rdx, -1528(%rbp)
	movq	-1536(%rbp), %rax
	movq	-1528(%rbp), %rdx
	movq	%rax, -1208(%rbp)
	movq	%rdx, -1200(%rbp)
	movq	-3872(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1216(%rbp)
	movq	-1216(%rbp), %rdx
	movq	%rdx, -1184(%rbp)
	movq	-1184(%rbp), %rsi
	movq	%rsi, -1176(%rbp)
	movq	-1176(%rbp), %rdi
	movq	%rdi, -1168(%rbp)
	movq	-1168(%rbp), %rdi
	movq	%rdi, -1160(%rbp)
	movq	-1160(%rbp), %rdi
	movzbl	(%rdi), %r8d
	movl	%r8d, %edi
	andq	$1, %rdi
	cmpq	$0, %rdi
	movq	%rdx, -3928(%rbp)       ## 8-byte Spill
	movq	%rsi, -3936(%rbp)       ## 8-byte Spill
	je	LBB21_43
## BB#42:
	movq	-3936(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1128(%rbp)
	movq	-1128(%rbp), %rcx
	movq	%rcx, -1120(%rbp)
	movq	-1120(%rbp), %rcx
	movq	%rcx, -1112(%rbp)
	movq	-1112(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	%rcx, -3944(%rbp)       ## 8-byte Spill
	jmp	LBB21_44
LBB21_43:
	movq	-3936(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1152(%rbp)
	movq	-1152(%rbp), %rcx
	movq	%rcx, -1144(%rbp)
	movq	-1144(%rbp), %rcx
	movq	%rcx, -1136(%rbp)
	movq	-1136(%rbp), %rcx
	movzbl	(%rcx), %edx
	sarl	$1, %edx
	movslq	%edx, %rcx
	movq	%rcx, -3944(%rbp)       ## 8-byte Spill
LBB21_44:
	movq	-3944(%rbp), %rax       ## 8-byte Reload
	leaq	-1208(%rbp), %rcx
	movq	%rax, -1224(%rbp)
	movq	%rcx, -1104(%rbp)
	movq	-1104(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -1232(%rbp)
	movq	-3928(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1096(%rbp)
	movq	-1096(%rbp), %rcx
	movq	%rcx, -1088(%rbp)
	movq	-1088(%rbp), %rcx
	movq	%rcx, -1080(%rbp)
	movq	-1080(%rbp), %rdx
	movq	%rdx, -1072(%rbp)
	movq	-1072(%rbp), %rdx
	movq	%rdx, -1064(%rbp)
	movq	-1064(%rbp), %rdx
	movzbl	(%rdx), %esi
	movl	%esi, %edx
	andq	$1, %rdx
	cmpq	$0, %rdx
	movq	%rcx, -3952(%rbp)       ## 8-byte Spill
	je	LBB21_46
## BB#45:
	movq	-3952(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1016(%rbp)
	movq	-1016(%rbp), %rcx
	movq	%rcx, -1008(%rbp)
	movq	-1008(%rbp), %rcx
	movq	%rcx, -1000(%rbp)
	movq	-1000(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -3960(%rbp)       ## 8-byte Spill
	jmp	LBB21_47
LBB21_46:
	movq	-3952(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1056(%rbp)
	movq	-1056(%rbp), %rcx
	movq	%rcx, -1048(%rbp)
	movq	-1048(%rbp), %rcx
	movq	%rcx, -1040(%rbp)
	movq	-1040(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -1032(%rbp)
	movq	-1032(%rbp), %rcx
	movq	%rcx, -1024(%rbp)
	movq	-1024(%rbp), %rcx
	movq	%rcx, -3960(%rbp)       ## 8-byte Spill
LBB21_47:
	movq	-3960(%rbp), %rax       ## 8-byte Reload
	leaq	-944(%rbp), %rcx
	leaq	-1232(%rbp), %rdx
	leaq	-1224(%rbp), %rsi
	leaq	-1208(%rbp), %rdi
	movq	%rax, -992(%rbp)
	movq	-992(%rbp), %rax
	movq	%rdi, -912(%rbp)
	movq	-912(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rsi, -968(%rbp)
	movq	%rdx, -976(%rbp)
	movq	-968(%rbp), %rdx
	movq	-976(%rbp), %rsi
	movq	%rdx, -952(%rbp)
	movq	%rsi, -960(%rbp)
	movq	-960(%rbp), %rdx
	movq	-952(%rbp), %rsi
	movq	%rcx, -920(%rbp)
	movq	%rdx, -928(%rbp)
	movq	%rsi, -936(%rbp)
	movq	-928(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-936(%rbp), %rdx
	cmpq	(%rdx), %rcx
	movq	%rax, -3968(%rbp)       ## 8-byte Spill
	movq	%rdi, -3976(%rbp)       ## 8-byte Spill
	jae	LBB21_49
## BB#48:
	movq	-960(%rbp), %rax
	movq	%rax, -3984(%rbp)       ## 8-byte Spill
	jmp	LBB21_50
LBB21_49:
	movq	-952(%rbp), %rax
	movq	%rax, -3984(%rbp)       ## 8-byte Spill
LBB21_50:
	movq	-3984(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rdx
	movq	-3968(%rbp), %rdi       ## 8-byte Reload
	movq	-3976(%rbp), %rsi       ## 8-byte Reload
	callq	__ZNSt3__111char_traitsIcE7compareEPKcS3_m
	movl	%eax, -1236(%rbp)
	cmpl	$0, -1236(%rbp)
	je	LBB21_52
## BB#51:
	movl	-1236(%rbp), %eax
	movl	%eax, -1188(%rbp)
	jmp	LBB21_57
LBB21_52:
	movq	-1224(%rbp), %rax
	cmpq	-1232(%rbp), %rax
	jae	LBB21_54
## BB#53:
	movl	$-1, -1188(%rbp)
	jmp	LBB21_57
LBB21_54:
	movq	-1224(%rbp), %rax
	cmpq	-1232(%rbp), %rax
	jbe	LBB21_56
## BB#55:
	movl	$1, -1188(%rbp)
	jmp	LBB21_57
LBB21_56:
	movl	$0, -1188(%rbp)
LBB21_57:
	cmpl	$0, -1188(%rbp)
	setl	%al
	movb	%al, -3841(%rbp)        ## 1-byte Spill
LBB21_58:
	movb	-3841(%rbp), %al        ## 1-byte Reload
	testb	$1, %al
	jne	LBB21_59
	jmp	LBB21_62
LBB21_59:
	movq	-3600(%rbp), %rax
	cmpq	$0, (%rax)
	jne	LBB21_61
## BB#60:
	movq	-3600(%rbp), %rax
	movq	-3616(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-3616(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -3592(%rbp)
	jmp	LBB21_144
LBB21_61:
	movq	-3656(%rbp), %rax
	movq	-3616(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-3656(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -3592(%rbp)
	jmp	LBB21_144
LBB21_62:
	movq	-3616(%rbp), %rsi
	movq	-3632(%rbp), %rdx
	movq	-3712(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISO_EERKT_
	movq	%rax, -3592(%rbp)
	jmp	LBB21_144
LBB21_63:
	leaq	-3600(%rbp), %rax
	movq	-3712(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1640(%rbp)
	movq	-1640(%rbp), %rdx
	addq	$16, %rdx
	movq	%rdx, -1632(%rbp)
	movq	-1632(%rbp), %rdx
	movq	%rdx, -1624(%rbp)
	movq	-1624(%rbp), %rdx
	movq	%rax, -1656(%rbp)
	movq	-1656(%rbp), %rax
	movq	%rax, -1648(%rbp)
	movq	-1648(%rbp), %rax
	movq	(%rax), %rax
	addq	$32, %rax
	movq	-3632(%rbp), %rsi
	movq	%rdx, -2360(%rbp)
	movq	%rax, -2368(%rbp)
	movq	%rsi, -2376(%rbp)
	movq	-2360(%rbp), %rax
	movq	-2368(%rbp), %rdx
	movq	-2376(%rbp), %rsi
	movq	%rax, -2336(%rbp)
	movq	%rdx, -2344(%rbp)
	movq	%rsi, -2352(%rbp)
	movq	-2344(%rbp), %rax
	movq	-2352(%rbp), %rdx
	movq	%rax, -2320(%rbp)
	movq	%rdx, -2328(%rbp)
	movq	-2320(%rbp), %rax
	movq	-2328(%rbp), %rdx
	movq	%rax, -2288(%rbp)
	movq	%rdx, -2296(%rbp)
	movq	-2288(%rbp), %rax
	movq	-2296(%rbp), %rdx
	movq	%rdx, -2280(%rbp)
	movq	-2280(%rbp), %rdx
	movq	%rdx, -2256(%rbp)
	movq	-2256(%rbp), %rsi
	movq	%rsi, -2248(%rbp)
	movq	-2248(%rbp), %rsi
	movq	%rsi, -2240(%rbp)
	movq	-2240(%rbp), %rdi
	movq	%rdi, -2232(%rbp)
	movq	-2232(%rbp), %rdi
	movq	%rdi, -2224(%rbp)
	movq	-2224(%rbp), %rdi
	movzbl	(%rdi), %r8d
	movl	%r8d, %edi
	andq	$1, %rdi
	cmpq	$0, %rdi
	movq	%rax, -3992(%rbp)       ## 8-byte Spill
	movq	%rdx, -4000(%rbp)       ## 8-byte Spill
	movq	%rsi, -4008(%rbp)       ## 8-byte Spill
	je	LBB21_65
## BB#64:
	movq	-4008(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -2176(%rbp)
	movq	-2176(%rbp), %rcx
	movq	%rcx, -2168(%rbp)
	movq	-2168(%rbp), %rcx
	movq	%rcx, -2160(%rbp)
	movq	-2160(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -4016(%rbp)       ## 8-byte Spill
	jmp	LBB21_66
LBB21_65:
	movq	-4008(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -2216(%rbp)
	movq	-2216(%rbp), %rcx
	movq	%rcx, -2208(%rbp)
	movq	-2208(%rbp), %rcx
	movq	%rcx, -2200(%rbp)
	movq	-2200(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -2192(%rbp)
	movq	-2192(%rbp), %rcx
	movq	%rcx, -2184(%rbp)
	movq	-2184(%rbp), %rcx
	movq	%rcx, -4016(%rbp)       ## 8-byte Spill
LBB21_66:
	movq	-4016(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -2152(%rbp)
	movq	-2152(%rbp), %rax
	movq	-4000(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -2144(%rbp)
	movq	-2144(%rbp), %rdx
	movq	%rdx, -2136(%rbp)
	movq	-2136(%rbp), %rsi
	movq	%rsi, -2128(%rbp)
	movq	-2128(%rbp), %rsi
	movq	%rsi, -2120(%rbp)
	movq	-2120(%rbp), %rsi
	movzbl	(%rsi), %edi
	movl	%edi, %esi
	andq	$1, %rsi
	cmpq	$0, %rsi
	movq	%rax, -4024(%rbp)       ## 8-byte Spill
	movq	%rdx, -4032(%rbp)       ## 8-byte Spill
	je	LBB21_68
## BB#67:
	movq	-4032(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -2088(%rbp)
	movq	-2088(%rbp), %rcx
	movq	%rcx, -2080(%rbp)
	movq	-2080(%rbp), %rcx
	movq	%rcx, -2072(%rbp)
	movq	-2072(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	%rcx, -4040(%rbp)       ## 8-byte Spill
	jmp	LBB21_69
LBB21_68:
	movq	-4032(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -2112(%rbp)
	movq	-2112(%rbp), %rcx
	movq	%rcx, -2104(%rbp)
	movq	-2104(%rbp), %rcx
	movq	%rcx, -2096(%rbp)
	movq	-2096(%rbp), %rcx
	movzbl	(%rcx), %edx
	sarl	$1, %edx
	movslq	%edx, %rcx
	movq	%rcx, -4040(%rbp)       ## 8-byte Spill
LBB21_69:
	movq	-4040(%rbp), %rax       ## 8-byte Reload
	leaq	-2272(%rbp), %rcx
	movq	%rcx, -2048(%rbp)
	movq	-4024(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -2056(%rbp)
	movq	%rax, -2064(%rbp)
	movq	-2048(%rbp), %rax
	movq	-2056(%rbp), %rdx
	movq	-2064(%rbp), %rsi
	movq	%rax, -2024(%rbp)
	movq	%rdx, -2032(%rbp)
	movq	%rsi, -2040(%rbp)
	movq	-2024(%rbp), %rax
	movq	-2032(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-2040(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-2272(%rbp), %rax
	movq	-2264(%rbp), %rdx
	movq	%rax, -2312(%rbp)
	movq	%rdx, -2304(%rbp)
	movq	-2312(%rbp), %rax
	movq	-2304(%rbp), %rdx
	movq	%rax, -1984(%rbp)
	movq	%rdx, -1976(%rbp)
	movq	-3992(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1992(%rbp)
	movq	-1992(%rbp), %rdx
	movq	%rdx, -1960(%rbp)
	movq	-1960(%rbp), %rsi
	movq	%rsi, -1952(%rbp)
	movq	-1952(%rbp), %rdi
	movq	%rdi, -1944(%rbp)
	movq	-1944(%rbp), %rdi
	movq	%rdi, -1936(%rbp)
	movq	-1936(%rbp), %rdi
	movzbl	(%rdi), %r8d
	movl	%r8d, %edi
	andq	$1, %rdi
	cmpq	$0, %rdi
	movq	%rdx, -4048(%rbp)       ## 8-byte Spill
	movq	%rsi, -4056(%rbp)       ## 8-byte Spill
	je	LBB21_71
## BB#70:
	movq	-4056(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1904(%rbp)
	movq	-1904(%rbp), %rcx
	movq	%rcx, -1896(%rbp)
	movq	-1896(%rbp), %rcx
	movq	%rcx, -1888(%rbp)
	movq	-1888(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	%rcx, -4064(%rbp)       ## 8-byte Spill
	jmp	LBB21_72
LBB21_71:
	movq	-4056(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1928(%rbp)
	movq	-1928(%rbp), %rcx
	movq	%rcx, -1920(%rbp)
	movq	-1920(%rbp), %rcx
	movq	%rcx, -1912(%rbp)
	movq	-1912(%rbp), %rcx
	movzbl	(%rcx), %edx
	sarl	$1, %edx
	movslq	%edx, %rcx
	movq	%rcx, -4064(%rbp)       ## 8-byte Spill
LBB21_72:
	movq	-4064(%rbp), %rax       ## 8-byte Reload
	leaq	-1984(%rbp), %rcx
	movq	%rax, -2000(%rbp)
	movq	%rcx, -1880(%rbp)
	movq	-1880(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -2008(%rbp)
	movq	-4048(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1872(%rbp)
	movq	-1872(%rbp), %rcx
	movq	%rcx, -1864(%rbp)
	movq	-1864(%rbp), %rcx
	movq	%rcx, -1856(%rbp)
	movq	-1856(%rbp), %rdx
	movq	%rdx, -1848(%rbp)
	movq	-1848(%rbp), %rdx
	movq	%rdx, -1840(%rbp)
	movq	-1840(%rbp), %rdx
	movzbl	(%rdx), %esi
	movl	%esi, %edx
	andq	$1, %rdx
	cmpq	$0, %rdx
	movq	%rcx, -4072(%rbp)       ## 8-byte Spill
	je	LBB21_74
## BB#73:
	movq	-4072(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1792(%rbp)
	movq	-1792(%rbp), %rcx
	movq	%rcx, -1784(%rbp)
	movq	-1784(%rbp), %rcx
	movq	%rcx, -1776(%rbp)
	movq	-1776(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -4080(%rbp)       ## 8-byte Spill
	jmp	LBB21_75
LBB21_74:
	movq	-4072(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1832(%rbp)
	movq	-1832(%rbp), %rcx
	movq	%rcx, -1824(%rbp)
	movq	-1824(%rbp), %rcx
	movq	%rcx, -1816(%rbp)
	movq	-1816(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -1808(%rbp)
	movq	-1808(%rbp), %rcx
	movq	%rcx, -1800(%rbp)
	movq	-1800(%rbp), %rcx
	movq	%rcx, -4080(%rbp)       ## 8-byte Spill
LBB21_75:
	movq	-4080(%rbp), %rax       ## 8-byte Reload
	leaq	-1720(%rbp), %rcx
	leaq	-2008(%rbp), %rdx
	leaq	-2000(%rbp), %rsi
	leaq	-1984(%rbp), %rdi
	movq	%rax, -1768(%rbp)
	movq	-1768(%rbp), %rax
	movq	%rdi, -1688(%rbp)
	movq	-1688(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rsi, -1744(%rbp)
	movq	%rdx, -1752(%rbp)
	movq	-1744(%rbp), %rdx
	movq	-1752(%rbp), %rsi
	movq	%rdx, -1728(%rbp)
	movq	%rsi, -1736(%rbp)
	movq	-1736(%rbp), %rdx
	movq	-1728(%rbp), %rsi
	movq	%rcx, -1696(%rbp)
	movq	%rdx, -1704(%rbp)
	movq	%rsi, -1712(%rbp)
	movq	-1704(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-1712(%rbp), %rdx
	cmpq	(%rdx), %rcx
	movq	%rax, -4088(%rbp)       ## 8-byte Spill
	movq	%rdi, -4096(%rbp)       ## 8-byte Spill
	jae	LBB21_77
## BB#76:
	movq	-1736(%rbp), %rax
	movq	%rax, -4104(%rbp)       ## 8-byte Spill
	jmp	LBB21_78
LBB21_77:
	movq	-1728(%rbp), %rax
	movq	%rax, -4104(%rbp)       ## 8-byte Spill
LBB21_78:
	movq	-4104(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rdx
	movq	-4088(%rbp), %rdi       ## 8-byte Reload
	movq	-4096(%rbp), %rsi       ## 8-byte Reload
	callq	__ZNSt3__111char_traitsIcE7compareEPKcS3_m
	movl	%eax, -2012(%rbp)
	cmpl	$0, -2012(%rbp)
	je	LBB21_80
## BB#79:
	movl	-2012(%rbp), %eax
	movl	%eax, -1964(%rbp)
	jmp	LBB21_85
LBB21_80:
	movq	-2000(%rbp), %rax
	cmpq	-2008(%rbp), %rax
	jae	LBB21_82
## BB#81:
	movl	$-1, -1964(%rbp)
	jmp	LBB21_85
LBB21_82:
	movq	-2000(%rbp), %rax
	cmpq	-2008(%rbp), %rax
	jbe	LBB21_84
## BB#83:
	movl	$1, -1964(%rbp)
	jmp	LBB21_85
LBB21_84:
	movl	$0, -1964(%rbp)
LBB21_85:
	cmpl	$0, -1964(%rbp)
	jge	LBB21_142
## BB#86:
	leaq	-2552(%rbp), %rax
	movq	-3600(%rbp), %rcx
	movq	%rcx, -3688(%rbp)
	movq	-3688(%rbp), %rcx
	movq	%rcx, -2552(%rbp)
	movq	$1, -2560(%rbp)
	movq	$0, -2568(%rbp)
	movq	-2560(%rbp), %rcx
	movq	%rax, -2520(%rbp)
	movq	%rcx, -2528(%rbp)
	movq	-2520(%rbp), %rax
	movq	-2528(%rbp), %rcx
	movq	%rax, -2504(%rbp)
	movq	%rcx, -2512(%rbp)
	cmpq	$0, -2512(%rbp)
	jl	LBB21_100
## BB#87:
	jmp	LBB21_88
LBB21_88:                               ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB21_91 Depth 2
                                        ##     Child Loop BB21_95 Depth 2
	cmpq	$0, -2512(%rbp)
	jle	LBB21_99
## BB#89:                               ##   in Loop: Header=BB21_88 Depth=1
	movq	-2504(%rbp), %rax
	movq	%rax, -2488(%rbp)
	movq	-2488(%rbp), %rax
	movq	(%rax), %rcx
	movq	%rcx, -2480(%rbp)
	movq	-2480(%rbp), %rcx
	cmpq	$0, 8(%rcx)
	movq	%rax, -4112(%rbp)       ## 8-byte Spill
	je	LBB21_94
## BB#90:                               ##   in Loop: Header=BB21_88 Depth=1
	movq	-2480(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -2464(%rbp)
LBB21_91:                               ##   Parent Loop BB21_88 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	-2464(%rbp), %rax
	cmpq	$0, (%rax)
	je	LBB21_93
## BB#92:                               ##   in Loop: Header=BB21_91 Depth=2
	movq	-2464(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -2464(%rbp)
	jmp	LBB21_91
LBB21_93:                               ##   in Loop: Header=BB21_88 Depth=1
	movq	-2464(%rbp), %rax
	movq	%rax, -2472(%rbp)
	jmp	LBB21_98
LBB21_94:                               ##   in Loop: Header=BB21_88 Depth=1
	jmp	LBB21_95
LBB21_95:                               ##   Parent Loop BB21_88 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	-2480(%rbp), %rax
	movq	%rax, -2456(%rbp)
	movq	-2456(%rbp), %rax
	movq	-2456(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	sete	%dl
	xorb	$-1, %dl
	testb	$1, %dl
	jne	LBB21_96
	jmp	LBB21_97
LBB21_96:                               ##   in Loop: Header=BB21_95 Depth=2
	movq	-2480(%rbp), %rax
	movq	%rax, -2448(%rbp)
	movq	-2448(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -2480(%rbp)
	jmp	LBB21_95
LBB21_97:                               ##   in Loop: Header=BB21_88 Depth=1
	movq	-2480(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -2472(%rbp)
LBB21_98:                               ##   in Loop: Header=BB21_88 Depth=1
	movq	-2472(%rbp), %rax
	movq	-4112(%rbp), %rcx       ## 8-byte Reload
	movq	%rax, (%rcx)
	movq	-2512(%rbp), %rax
	addq	$-1, %rax
	movq	%rax, -2512(%rbp)
	jmp	LBB21_88
LBB21_99:
	jmp	LBB21_113
LBB21_100:
	jmp	LBB21_101
LBB21_101:                              ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB21_104 Depth 2
                                        ##     Child Loop BB21_108 Depth 2
	cmpq	$0, -2512(%rbp)
	jge	LBB21_112
## BB#102:                              ##   in Loop: Header=BB21_101 Depth=1
	movq	-2504(%rbp), %rax
	movq	%rax, -2440(%rbp)
	movq	-2440(%rbp), %rax
	movq	(%rax), %rcx
	movq	%rcx, -2424(%rbp)
	movq	-2424(%rbp), %rcx
	cmpq	$0, (%rcx)
	movq	%rax, -4120(%rbp)       ## 8-byte Spill
	je	LBB21_107
## BB#103:                              ##   in Loop: Header=BB21_101 Depth=1
	movq	-2424(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -2408(%rbp)
LBB21_104:                              ##   Parent Loop BB21_101 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	-2408(%rbp), %rax
	cmpq	$0, 8(%rax)
	je	LBB21_106
## BB#105:                              ##   in Loop: Header=BB21_104 Depth=2
	movq	-2408(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -2408(%rbp)
	jmp	LBB21_104
LBB21_106:                              ##   in Loop: Header=BB21_101 Depth=1
	movq	-2408(%rbp), %rax
	movq	%rax, -2416(%rbp)
	jmp	LBB21_111
LBB21_107:                              ##   in Loop: Header=BB21_101 Depth=1
	movq	-2424(%rbp), %rax
	movq	%rax, -2432(%rbp)
LBB21_108:                              ##   Parent Loop BB21_101 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	-2432(%rbp), %rax
	movq	%rax, -2400(%rbp)
	movq	-2400(%rbp), %rax
	movq	-2400(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	jne	LBB21_110
## BB#109:                              ##   in Loop: Header=BB21_108 Depth=2
	movq	-2432(%rbp), %rax
	movq	%rax, -2384(%rbp)
	movq	-2384(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -2432(%rbp)
	jmp	LBB21_108
LBB21_110:                              ##   in Loop: Header=BB21_101 Depth=1
	movq	-2432(%rbp), %rax
	movq	%rax, -2392(%rbp)
	movq	-2392(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -2416(%rbp)
LBB21_111:                              ##   in Loop: Header=BB21_101 Depth=1
	movq	-2416(%rbp), %rax
	movq	-4120(%rbp), %rcx       ## 8-byte Reload
	movq	%rax, (%rcx)
	movq	-2512(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -2512(%rbp)
	jmp	LBB21_101
LBB21_112:
	jmp	LBB21_113
LBB21_113:
	movb	$1, %al
	leaq	-3696(%rbp), %rcx
	leaq	-3680(%rbp), %rdx
	leaq	-2648(%rbp), %rsi
	movq	-2552(%rbp), %rdi
	movq	%rdi, -2544(%rbp)
	movq	-2544(%rbp), %rdi
	movq	%rdi, -3680(%rbp)
	movq	-3712(%rbp), %rdi       ## 8-byte Reload
	movq	%rdi, -2656(%rbp)
	movq	-2656(%rbp), %r8
	movq	%r8, -2640(%rbp)
	movq	-2640(%rbp), %r8
	addq	$8, %r8
	movq	%r8, -2632(%rbp)
	movq	-2632(%rbp), %r8
	movq	%r8, -2624(%rbp)
	movq	-2624(%rbp), %r8
	movq	%r8, -2616(%rbp)
	movq	-2616(%rbp), %r8
	movq	%r8, -2608(%rbp)
	movq	-2608(%rbp), %r8
	movq	%rsi, -2592(%rbp)
	movq	%r8, -2600(%rbp)
	movq	-2592(%rbp), %rsi
	movq	-2600(%rbp), %r8
	movq	%rsi, -2576(%rbp)
	movq	%r8, -2584(%rbp)
	movq	-2576(%rbp), %rsi
	movq	-2584(%rbp), %r8
	movq	%r8, (%rsi)
	movq	-2648(%rbp), %rsi
	movq	%rsi, -3704(%rbp)
	movq	-3704(%rbp), %rsi
	movq	%rsi, -2680(%rbp)
	movq	%rcx, -2688(%rbp)
	movq	-2688(%rbp), %rsi
	movq	-2680(%rbp), %r8
	movq	%r8, -2664(%rbp)
	movq	%rsi, -2672(%rbp)
	movq	-2672(%rbp), %rsi
	movq	-2664(%rbp), %r8
	movq	%r8, (%rsi)
	movq	%rdx, -2696(%rbp)
	movq	%rcx, -2704(%rbp)
	movq	-2696(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-2704(%rbp), %rdx
	cmpq	(%rdx), %rcx
	movb	%al, -4121(%rbp)        ## 1-byte Spill
	je	LBB21_137
## BB#114:
	leaq	-3680(%rbp), %rax
	movq	-3712(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -2728(%rbp)
	movq	-2728(%rbp), %rdx
	addq	$16, %rdx
	movq	%rdx, -2720(%rbp)
	movq	-2720(%rbp), %rdx
	movq	%rdx, -2712(%rbp)
	movq	-2712(%rbp), %rdx
	movq	-3632(%rbp), %rsi
	movq	%rax, -2744(%rbp)
	movq	-2744(%rbp), %rax
	movq	%rax, -2736(%rbp)
	movq	-2736(%rbp), %rax
	movq	(%rax), %rax
	addq	$32, %rax
	movq	%rdx, -3440(%rbp)
	movq	%rsi, -3448(%rbp)
	movq	%rax, -3456(%rbp)
	movq	-3440(%rbp), %rax
	movq	-3448(%rbp), %rdx
	movq	-3456(%rbp), %rsi
	movq	%rax, -3416(%rbp)
	movq	%rdx, -3424(%rbp)
	movq	%rsi, -3432(%rbp)
	movq	-3424(%rbp), %rax
	movq	-3432(%rbp), %rdx
	movq	%rax, -3400(%rbp)
	movq	%rdx, -3408(%rbp)
	movq	-3400(%rbp), %rax
	movq	-3408(%rbp), %rdx
	movq	%rax, -3368(%rbp)
	movq	%rdx, -3376(%rbp)
	movq	-3368(%rbp), %rax
	movq	-3376(%rbp), %rdx
	movq	%rdx, -3360(%rbp)
	movq	-3360(%rbp), %rdx
	movq	%rdx, -3336(%rbp)
	movq	-3336(%rbp), %rsi
	movq	%rsi, -3328(%rbp)
	movq	-3328(%rbp), %rsi
	movq	%rsi, -3320(%rbp)
	movq	-3320(%rbp), %rdi
	movq	%rdi, -3312(%rbp)
	movq	-3312(%rbp), %rdi
	movq	%rdi, -3304(%rbp)
	movq	-3304(%rbp), %rdi
	movzbl	(%rdi), %r8d
	movl	%r8d, %edi
	andq	$1, %rdi
	cmpq	$0, %rdi
	movq	%rax, -4136(%rbp)       ## 8-byte Spill
	movq	%rdx, -4144(%rbp)       ## 8-byte Spill
	movq	%rsi, -4152(%rbp)       ## 8-byte Spill
	je	LBB21_116
## BB#115:
	movq	-4152(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -3256(%rbp)
	movq	-3256(%rbp), %rcx
	movq	%rcx, -3248(%rbp)
	movq	-3248(%rbp), %rcx
	movq	%rcx, -3240(%rbp)
	movq	-3240(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -4160(%rbp)       ## 8-byte Spill
	jmp	LBB21_117
LBB21_116:
	movq	-4152(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -3296(%rbp)
	movq	-3296(%rbp), %rcx
	movq	%rcx, -3288(%rbp)
	movq	-3288(%rbp), %rcx
	movq	%rcx, -3280(%rbp)
	movq	-3280(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -3272(%rbp)
	movq	-3272(%rbp), %rcx
	movq	%rcx, -3264(%rbp)
	movq	-3264(%rbp), %rcx
	movq	%rcx, -4160(%rbp)       ## 8-byte Spill
LBB21_117:
	movq	-4160(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -3232(%rbp)
	movq	-3232(%rbp), %rax
	movq	-4144(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -3224(%rbp)
	movq	-3224(%rbp), %rdx
	movq	%rdx, -3216(%rbp)
	movq	-3216(%rbp), %rsi
	movq	%rsi, -3208(%rbp)
	movq	-3208(%rbp), %rsi
	movq	%rsi, -3200(%rbp)
	movq	-3200(%rbp), %rsi
	movzbl	(%rsi), %edi
	movl	%edi, %esi
	andq	$1, %rsi
	cmpq	$0, %rsi
	movq	%rax, -4168(%rbp)       ## 8-byte Spill
	movq	%rdx, -4176(%rbp)       ## 8-byte Spill
	je	LBB21_119
## BB#118:
	movq	-4176(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -3168(%rbp)
	movq	-3168(%rbp), %rcx
	movq	%rcx, -3160(%rbp)
	movq	-3160(%rbp), %rcx
	movq	%rcx, -3152(%rbp)
	movq	-3152(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	%rcx, -4184(%rbp)       ## 8-byte Spill
	jmp	LBB21_120
LBB21_119:
	movq	-4176(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -3192(%rbp)
	movq	-3192(%rbp), %rcx
	movq	%rcx, -3184(%rbp)
	movq	-3184(%rbp), %rcx
	movq	%rcx, -3176(%rbp)
	movq	-3176(%rbp), %rcx
	movzbl	(%rcx), %edx
	sarl	$1, %edx
	movslq	%edx, %rcx
	movq	%rcx, -4184(%rbp)       ## 8-byte Spill
LBB21_120:
	movq	-4184(%rbp), %rax       ## 8-byte Reload
	leaq	-3352(%rbp), %rcx
	movq	%rcx, -3128(%rbp)
	movq	-4168(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -3136(%rbp)
	movq	%rax, -3144(%rbp)
	movq	-3128(%rbp), %rax
	movq	-3136(%rbp), %rdx
	movq	-3144(%rbp), %rsi
	movq	%rax, -3104(%rbp)
	movq	%rdx, -3112(%rbp)
	movq	%rsi, -3120(%rbp)
	movq	-3104(%rbp), %rax
	movq	-3112(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-3120(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-3352(%rbp), %rax
	movq	-3344(%rbp), %rdx
	movq	%rax, -3392(%rbp)
	movq	%rdx, -3384(%rbp)
	movq	-3392(%rbp), %rax
	movq	-3384(%rbp), %rdx
	movq	%rax, -3064(%rbp)
	movq	%rdx, -3056(%rbp)
	movq	-4136(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -3072(%rbp)
	movq	-3072(%rbp), %rdx
	movq	%rdx, -3040(%rbp)
	movq	-3040(%rbp), %rsi
	movq	%rsi, -3032(%rbp)
	movq	-3032(%rbp), %rdi
	movq	%rdi, -3024(%rbp)
	movq	-3024(%rbp), %rdi
	movq	%rdi, -3016(%rbp)
	movq	-3016(%rbp), %rdi
	movzbl	(%rdi), %r8d
	movl	%r8d, %edi
	andq	$1, %rdi
	cmpq	$0, %rdi
	movq	%rdx, -4192(%rbp)       ## 8-byte Spill
	movq	%rsi, -4200(%rbp)       ## 8-byte Spill
	je	LBB21_122
## BB#121:
	movq	-4200(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -2984(%rbp)
	movq	-2984(%rbp), %rcx
	movq	%rcx, -2976(%rbp)
	movq	-2976(%rbp), %rcx
	movq	%rcx, -2968(%rbp)
	movq	-2968(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	%rcx, -4208(%rbp)       ## 8-byte Spill
	jmp	LBB21_123
LBB21_122:
	movq	-4200(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -3008(%rbp)
	movq	-3008(%rbp), %rcx
	movq	%rcx, -3000(%rbp)
	movq	-3000(%rbp), %rcx
	movq	%rcx, -2992(%rbp)
	movq	-2992(%rbp), %rcx
	movzbl	(%rcx), %edx
	sarl	$1, %edx
	movslq	%edx, %rcx
	movq	%rcx, -4208(%rbp)       ## 8-byte Spill
LBB21_123:
	movq	-4208(%rbp), %rax       ## 8-byte Reload
	leaq	-3064(%rbp), %rcx
	movq	%rax, -3080(%rbp)
	movq	%rcx, -2960(%rbp)
	movq	-2960(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -3088(%rbp)
	movq	-4192(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -2952(%rbp)
	movq	-2952(%rbp), %rcx
	movq	%rcx, -2944(%rbp)
	movq	-2944(%rbp), %rcx
	movq	%rcx, -2936(%rbp)
	movq	-2936(%rbp), %rdx
	movq	%rdx, -2928(%rbp)
	movq	-2928(%rbp), %rdx
	movq	%rdx, -2920(%rbp)
	movq	-2920(%rbp), %rdx
	movzbl	(%rdx), %esi
	movl	%esi, %edx
	andq	$1, %rdx
	cmpq	$0, %rdx
	movq	%rcx, -4216(%rbp)       ## 8-byte Spill
	je	LBB21_125
## BB#124:
	movq	-4216(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -2872(%rbp)
	movq	-2872(%rbp), %rcx
	movq	%rcx, -2864(%rbp)
	movq	-2864(%rbp), %rcx
	movq	%rcx, -2856(%rbp)
	movq	-2856(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -4224(%rbp)       ## 8-byte Spill
	jmp	LBB21_126
LBB21_125:
	movq	-4216(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -2912(%rbp)
	movq	-2912(%rbp), %rcx
	movq	%rcx, -2904(%rbp)
	movq	-2904(%rbp), %rcx
	movq	%rcx, -2896(%rbp)
	movq	-2896(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -2888(%rbp)
	movq	-2888(%rbp), %rcx
	movq	%rcx, -2880(%rbp)
	movq	-2880(%rbp), %rcx
	movq	%rcx, -4224(%rbp)       ## 8-byte Spill
LBB21_126:
	movq	-4224(%rbp), %rax       ## 8-byte Reload
	leaq	-2800(%rbp), %rcx
	leaq	-3088(%rbp), %rdx
	leaq	-3080(%rbp), %rsi
	leaq	-3064(%rbp), %rdi
	movq	%rax, -2848(%rbp)
	movq	-2848(%rbp), %rax
	movq	%rdi, -2768(%rbp)
	movq	-2768(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rsi, -2824(%rbp)
	movq	%rdx, -2832(%rbp)
	movq	-2824(%rbp), %rdx
	movq	-2832(%rbp), %rsi
	movq	%rdx, -2808(%rbp)
	movq	%rsi, -2816(%rbp)
	movq	-2816(%rbp), %rdx
	movq	-2808(%rbp), %rsi
	movq	%rcx, -2776(%rbp)
	movq	%rdx, -2784(%rbp)
	movq	%rsi, -2792(%rbp)
	movq	-2784(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-2792(%rbp), %rdx
	cmpq	(%rdx), %rcx
	movq	%rax, -4232(%rbp)       ## 8-byte Spill
	movq	%rdi, -4240(%rbp)       ## 8-byte Spill
	jae	LBB21_128
## BB#127:
	movq	-2816(%rbp), %rax
	movq	%rax, -4248(%rbp)       ## 8-byte Spill
	jmp	LBB21_129
LBB21_128:
	movq	-2808(%rbp), %rax
	movq	%rax, -4248(%rbp)       ## 8-byte Spill
LBB21_129:
	movq	-4248(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rdx
	movq	-4232(%rbp), %rdi       ## 8-byte Reload
	movq	-4240(%rbp), %rsi       ## 8-byte Reload
	callq	__ZNSt3__111char_traitsIcE7compareEPKcS3_m
	movl	%eax, -3092(%rbp)
	cmpl	$0, -3092(%rbp)
	je	LBB21_131
## BB#130:
	movl	-3092(%rbp), %eax
	movl	%eax, -3044(%rbp)
	jmp	LBB21_136
LBB21_131:
	movq	-3080(%rbp), %rax
	cmpq	-3088(%rbp), %rax
	jae	LBB21_133
## BB#132:
	movl	$-1, -3044(%rbp)
	jmp	LBB21_136
LBB21_133:
	movq	-3080(%rbp), %rax
	cmpq	-3088(%rbp), %rax
	jbe	LBB21_135
## BB#134:
	movl	$1, -3044(%rbp)
	jmp	LBB21_136
LBB21_135:
	movl	$0, -3044(%rbp)
LBB21_136:
	cmpl	$0, -3044(%rbp)
	setl	%al
	movb	%al, -4121(%rbp)        ## 1-byte Spill
LBB21_137:
	movb	-4121(%rbp), %al        ## 1-byte Reload
	testb	$1, %al
	jne	LBB21_138
	jmp	LBB21_141
LBB21_138:
	leaq	-3600(%rbp), %rax
	movq	%rax, -3464(%rbp)
	movq	-3464(%rbp), %rax
	movq	(%rax), %rax
	cmpq	$0, 8(%rax)
	jne	LBB21_140
## BB#139:
	movq	-3600(%rbp), %rax
	movq	-3616(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-3600(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -3592(%rbp)
	jmp	LBB21_144
LBB21_140:
	movq	-3680(%rbp), %rax
	movq	-3616(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-3616(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -3592(%rbp)
	jmp	LBB21_144
LBB21_141:
	movq	-3616(%rbp), %rsi
	movq	-3632(%rbp), %rdx
	movq	-3712(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISO_EERKT_
	movq	%rax, -3592(%rbp)
	jmp	LBB21_144
LBB21_142:
	jmp	LBB21_143
LBB21_143:
	movq	-3600(%rbp), %rax
	movq	-3616(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-3600(%rbp), %rax
	movq	-3624(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-3624(%rbp), %rax
	movq	%rax, -3592(%rbp)
LBB21_144:
	movq	-3592(%rbp), %rax
	addq	$4256, %rsp             ## imm = 0x10A0
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE16__construct_nodeIJRKNS_4pairIKS7_SC_EEEEENS_10unique_ptrINS_11__tree_nodeISD_PvEENS_22__tree_node_destructorINS5_IST_EEEEEEDpOT_ ## -- Begin function _ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE16__construct_nodeIJRKNS_4pairIKS7_SC_EEEEENS_10unique_ptrINS_11__tree_nodeISD_PvEENS_22__tree_node_destructorINS5_IST_EEEEEEDpOT_
	.weak_definition	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE16__construct_nodeIJRKNS_4pairIKS7_SC_EEEEENS_10unique_ptrINS_11__tree_nodeISD_PvEENS_22__tree_node_destructorINS5_IST_EEEEEEDpOT_
	.p2align	4, 0x90
__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE16__construct_nodeIJRKNS_4pairIKS7_SC_EEEEENS_10unique_ptrINS_11__tree_nodeISD_PvEENS_22__tree_node_destructorINS5_IST_EEEEEEDpOT_: ## @_ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE16__construct_nodeIJRKNS_4pairIKS7_SC_EEEEENS_10unique_ptrINS_11__tree_nodeISD_PvEENS_22__tree_node_destructorINS5_IST_EEEEEEDpOT_
Lfunc_begin3:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception3
## BB#0:
	pushq	%rbp
Lcfi63:
	.cfi_def_cfa_offset 16
Lcfi64:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi65:
	.cfi_def_cfa_register %rbp
	subq	$1152, %rsp             ## imm = 0x480
	movq	%rdi, %rax
	movabsq	$288230376151711743, %rcx ## imm = 0x3FFFFFFFFFFFFFF
	movq	%rsi, -1000(%rbp)
	movq	%rdx, -1008(%rbp)
	movq	-1000(%rbp), %rdx
	movq	%rdx, -992(%rbp)
	movq	-992(%rbp), %rdx
	addq	$8, %rdx
	movq	%rdx, -984(%rbp)
	movq	-984(%rbp), %rdx
	movq	%rdx, -976(%rbp)
	movq	-976(%rbp), %rdx
	movq	%rdx, -1016(%rbp)
	movb	$0, -1017(%rbp)
	movq	-1016(%rbp), %rdx
	movq	%rdx, -736(%rbp)
	movq	$1, -744(%rbp)
	movq	-736(%rbp), %rdx
	movq	-744(%rbp), %rsi
	movq	%rdx, -712(%rbp)
	movq	%rsi, -720(%rbp)
	movq	$0, -728(%rbp)
	movq	-712(%rbp), %rdx
	movq	-720(%rbp), %rsi
	movq	%rdx, -704(%rbp)
	cmpq	%rcx, %rsi
	movq	%rax, -1064(%rbp)       ## 8-byte Spill
	movq	%rdi, -1072(%rbp)       ## 8-byte Spill
	jbe	LBB22_4
## BB#1:
	leaq	L_.str.6(%rip), %rax
	movq	%rax, -672(%rbp)
	movl	$16, %ecx
	movl	%ecx, %edi
	callq	___cxa_allocate_exception
	movq	%rax, %rdi
	movq	-672(%rbp), %rdx
	movq	%rax, -656(%rbp)
	movq	%rdx, -664(%rbp)
	movq	-656(%rbp), %rax
	movq	-664(%rbp), %rdx
	movq	%rax, -640(%rbp)
	movq	%rdx, -648(%rbp)
	movq	-640(%rbp), %rax
	movq	-648(%rbp), %rsi
Ltmp47:
	movq	%rdi, -1080(%rbp)       ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rax, -1088(%rbp)       ## 8-byte Spill
	callq	__ZNSt11logic_errorC2EPKc
Ltmp48:
	jmp	LBB22_2
LBB22_2:
	movq	__ZTISt12length_error@GOTPCREL(%rip), %rax
	movq	__ZNSt12length_errorD1Ev@GOTPCREL(%rip), %rcx
	movq	__ZTVSt12length_error@GOTPCREL(%rip), %rdx
	addq	$16, %rdx
	movq	-1088(%rbp), %rsi       ## 8-byte Reload
	movq	%rdx, (%rsi)
	movq	-1080(%rbp), %rdi       ## 8-byte Reload
	movq	%rax, %rsi
	movq	%rcx, %rdx
	callq	___cxa_throw
LBB22_3:
Ltmp49:
	movl	%edx, %ecx
	movq	%rax, -680(%rbp)
	movl	%ecx, -684(%rbp)
	movq	-1080(%rbp), %rdi       ## 8-byte Reload
	callq	___cxa_free_exception
	movq	-680(%rbp), %rax
	movq	%rax, -1096(%rbp)       ## 8-byte Spill
	jmp	LBB22_24
LBB22_4:
	movq	-720(%rbp), %rax
	shlq	$6, %rax
	movq	%rax, -696(%rbp)
	movq	-696(%rbp), %rdi
	callq	__Znwm
	leaq	-552(%rbp), %rdi
	leaq	-1040(%rbp), %rcx
	movq	-1016(%rbp), %rdx
	movq	%rcx, -616(%rbp)
	movq	%rdx, -624(%rbp)
	movb	$0, -625(%rbp)
	movq	-616(%rbp), %rdx
	movq	-624(%rbp), %rsi
	movb	-625(%rbp), %r8b
	movq	%rdx, -592(%rbp)
	movq	%rsi, -600(%rbp)
	andb	$1, %r8b
	movb	%r8b, -601(%rbp)
	movq	-592(%rbp), %rdx
	movq	-600(%rbp), %rsi
	movq	%rsi, (%rdx)
	movb	-601(%rbp), %r8b
	andb	$1, %r8b
	movb	%r8b, 8(%rdx)
	movq	-1072(%rbp), %rdx       ## 8-byte Reload
	movq	%rdx, -568(%rbp)
	movq	%rax, -576(%rbp)
	movq	%rcx, -584(%rbp)
	movq	-568(%rbp), %rax
	movq	-576(%rbp), %rcx
	movq	-584(%rbp), %rsi
	movq	%rax, -544(%rbp)
	movq	%rcx, -552(%rbp)
	movq	%rsi, -560(%rbp)
	movq	-544(%rbp), %rax
	movq	-560(%rbp), %rcx
	movq	%rcx, -536(%rbp)
	movq	-536(%rbp), %rcx
	movq	%rax, -512(%rbp)
	movq	%rdi, -520(%rbp)
	movq	%rcx, -528(%rbp)
	movq	-512(%rbp), %rax
	movq	-520(%rbp), %rcx
	movq	-528(%rbp), %rsi
	movq	%rax, -488(%rbp)
	movq	%rcx, -496(%rbp)
	movq	%rsi, -504(%rbp)
	movq	-488(%rbp), %rax
	movq	%rax, %rcx
	movq	-496(%rbp), %rsi
	movq	%rsi, -480(%rbp)
	movq	-480(%rbp), %rsi
	movq	%rcx, -432(%rbp)
	movq	%rsi, -440(%rbp)
	movq	-432(%rbp), %rcx
	movq	-440(%rbp), %rsi
	movq	%rsi, -424(%rbp)
	movq	-424(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, (%rcx)
	addq	$8, %rax
	movq	-504(%rbp), %rcx
	movq	%rcx, -448(%rbp)
	movq	-448(%rbp), %rcx
	movq	%rax, -464(%rbp)
	movq	%rcx, -472(%rbp)
	movq	-464(%rbp), %rax
	movq	-472(%rbp), %rcx
	movq	%rcx, -456(%rbp)
	movq	-456(%rbp), %rcx
	movq	(%rcx), %rsi
	movq	%rsi, (%rax)
	movq	8(%rcx), %rcx
	movq	%rcx, 8(%rax)
	movq	-1016(%rbp), %rax
	movq	%rdx, -416(%rbp)
	movq	-416(%rbp), %rcx
	movq	%rcx, -408(%rbp)
	movq	-408(%rbp), %rcx
	movq	%rcx, -400(%rbp)
	movq	-400(%rbp), %rcx
	movq	(%rcx), %rcx
	addq	$32, %rcx
	movq	%rcx, -392(%rbp)
	movq	-392(%rbp), %rcx
	movq	%rcx, -384(%rbp)
	movq	-384(%rbp), %rcx
	movq	%rax, -1104(%rbp)       ## 8-byte Spill
	movq	%rcx, -1112(%rbp)       ## 8-byte Spill
## BB#5:
	movq	-1008(%rbp), %rax
	movq	%rax, -376(%rbp)
	movq	-376(%rbp), %rax
	movq	-1104(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -336(%rbp)
	movq	-1112(%rbp), %rdx       ## 8-byte Reload
	movq	%rdx, -344(%rbp)
	movq	%rax, -352(%rbp)
	movq	-336(%rbp), %rax
	movq	-344(%rbp), %rsi
	movq	-352(%rbp), %rdi
	movq	%rdi, -328(%rbp)
	movq	-328(%rbp), %rdi
	movq	%rax, -304(%rbp)
	movq	%rsi, -312(%rbp)
	movq	%rdi, -320(%rbp)
	movq	-304(%rbp), %rax
	movq	-312(%rbp), %rsi
	movq	-320(%rbp), %rdi
	movq	%rdi, -288(%rbp)
	movq	-288(%rbp), %rdi
	movq	%rax, -264(%rbp)
	movq	%rsi, -272(%rbp)
	movq	%rdi, -280(%rbp)
	movq	-272(%rbp), %rdi
	movq	-280(%rbp), %rax
	movq	%rax, -256(%rbp)
	movq	-256(%rbp), %rsi
Ltmp44:
	callq	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEC1ERKSD_
Ltmp45:
	jmp	LBB22_6
LBB22_6:
	jmp	LBB22_7
LBB22_7:
	movq	-1072(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -248(%rbp)
	movq	-248(%rbp), %rcx
	movq	%rcx, -240(%rbp)
	movq	-240(%rbp), %rcx
	addq	$8, %rcx
	movq	%rcx, -232(%rbp)
	movq	-232(%rbp), %rcx
	movb	$1, 8(%rcx)
	movb	$1, -1017(%rbp)
	testb	$1, -1017(%rbp)
	jne	LBB22_22
	jmp	LBB22_15
LBB22_8:
Ltmp46:
	movl	%edx, %ecx
	movq	%rax, -1048(%rbp)
	movl	%ecx, -1052(%rbp)
	movq	-1072(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -224(%rbp)
	movq	-224(%rbp), %rdx
	movq	%rdx, -216(%rbp)
	movq	-216(%rbp), %rdx
	movq	%rdx, -192(%rbp)
	movq	$0, -200(%rbp)
	movq	-192(%rbp), %rdx
	movq	%rdx, -184(%rbp)
	movq	-184(%rbp), %rsi
	movq	%rsi, -176(%rbp)
	movq	-176(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -208(%rbp)
	movq	-200(%rbp), %rsi
	movq	%rdx, -32(%rbp)
	movq	-32(%rbp), %rdi
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rdi
	movq	%rsi, (%rdi)
	cmpq	$0, -208(%rbp)
	movq	%rdx, -1120(%rbp)       ## 8-byte Spill
	je	LBB22_14
## BB#9:
	movq	-1120(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rcx
	addq	$8, %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	-208(%rbp), %rdx
	movq	%rcx, -160(%rbp)
	movq	%rdx, -168(%rbp)
	movq	-160(%rbp), %rcx
	testb	$1, 8(%rcx)
	movq	%rcx, -1128(%rbp)       ## 8-byte Spill
	je	LBB22_11
## BB#10:
	movq	-1128(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-168(%rbp), %rdx
	addq	$32, %rdx
	movq	%rdx, -152(%rbp)
	movq	-152(%rbp), %rdx
	movq	%rdx, -144(%rbp)
	movq	-144(%rbp), %rdx
	movq	%rcx, -112(%rbp)
	movq	%rdx, -120(%rbp)
	movq	-112(%rbp), %rcx
	movq	-120(%rbp), %rdx
	movq	%rcx, -96(%rbp)
	movq	%rdx, -104(%rbp)
	movq	-104(%rbp), %rdi
	callq	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED1Ev
LBB22_11:
	cmpq	$0, -168(%rbp)
	je	LBB22_13
## BB#12:
	movq	-1128(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-168(%rbp), %rdx
	movq	%rcx, -72(%rbp)
	movq	%rdx, -80(%rbp)
	movq	$1, -88(%rbp)
	movq	-72(%rbp), %rcx
	movq	-80(%rbp), %rdx
	movq	-88(%rbp), %rsi
	movq	%rcx, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	-56(%rbp), %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rdi
	callq	__ZdlPv
LBB22_13:
	jmp	LBB22_14
LBB22_14:
	jmp	LBB22_23
LBB22_15:
	movq	-1072(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -968(%rbp)
	movq	-968(%rbp), %rcx
	movq	%rcx, -960(%rbp)
	movq	-960(%rbp), %rcx
	movq	%rcx, -936(%rbp)
	movq	$0, -944(%rbp)
	movq	-936(%rbp), %rcx
	movq	%rcx, -928(%rbp)
	movq	-928(%rbp), %rdx
	movq	%rdx, -920(%rbp)
	movq	-920(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, -952(%rbp)
	movq	-944(%rbp), %rdx
	movq	%rcx, -776(%rbp)
	movq	-776(%rbp), %rsi
	movq	%rsi, -768(%rbp)
	movq	-768(%rbp), %rsi
	movq	%rdx, (%rsi)
	cmpq	$0, -952(%rbp)
	movq	%rcx, -1136(%rbp)       ## 8-byte Spill
	je	LBB22_21
## BB#16:
	movq	-1136(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -760(%rbp)
	movq	-760(%rbp), %rcx
	addq	$8, %rcx
	movq	%rcx, -752(%rbp)
	movq	-752(%rbp), %rcx
	movq	-952(%rbp), %rdx
	movq	%rcx, -904(%rbp)
	movq	%rdx, -912(%rbp)
	movq	-904(%rbp), %rcx
	testb	$1, 8(%rcx)
	movq	%rcx, -1144(%rbp)       ## 8-byte Spill
	je	LBB22_18
## BB#17:
	movq	-1144(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-912(%rbp), %rdx
	addq	$32, %rdx
	movq	%rdx, -896(%rbp)
	movq	-896(%rbp), %rdx
	movq	%rdx, -888(%rbp)
	movq	-888(%rbp), %rdx
	movq	%rcx, -856(%rbp)
	movq	%rdx, -864(%rbp)
	movq	-856(%rbp), %rcx
	movq	-864(%rbp), %rdx
	movq	%rcx, -840(%rbp)
	movq	%rdx, -848(%rbp)
	movq	-848(%rbp), %rdi
	callq	__ZNSt3__14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEED1Ev
LBB22_18:
	cmpq	$0, -912(%rbp)
	je	LBB22_20
## BB#19:
	movq	-1144(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-912(%rbp), %rdx
	movq	%rcx, -816(%rbp)
	movq	%rdx, -824(%rbp)
	movq	$1, -832(%rbp)
	movq	-816(%rbp), %rcx
	movq	-824(%rbp), %rdx
	movq	-832(%rbp), %rsi
	movq	%rcx, -792(%rbp)
	movq	%rdx, -800(%rbp)
	movq	%rsi, -808(%rbp)
	movq	-800(%rbp), %rcx
	movq	%rcx, -784(%rbp)
	movq	-784(%rbp), %rdi
	callq	__ZdlPv
LBB22_20:
	jmp	LBB22_21
LBB22_21:
	jmp	LBB22_22
LBB22_22:
	movq	-1064(%rbp), %rax       ## 8-byte Reload
	addq	$1152, %rsp             ## imm = 0x480
	popq	%rbp
	retq
LBB22_23:
	movq	-1048(%rbp), %rax
	movq	%rax, -1096(%rbp)       ## 8-byte Spill
LBB22_24:
	movq	-1096(%rbp), %rax       ## 8-byte Reload
	movq	%rax, %rdi
	callq	__Unwind_Resume
Lfunc_end3:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table22:
Lexception3:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\303\200"              ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	65                      ## Call site table length
Lset28 = Lfunc_begin3-Lfunc_begin3      ## >> Call Site 1 <<
	.long	Lset28
Lset29 = Ltmp47-Lfunc_begin3            ##   Call between Lfunc_begin3 and Ltmp47
	.long	Lset29
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset30 = Ltmp47-Lfunc_begin3            ## >> Call Site 2 <<
	.long	Lset30
Lset31 = Ltmp48-Ltmp47                  ##   Call between Ltmp47 and Ltmp48
	.long	Lset31
Lset32 = Ltmp49-Lfunc_begin3            ##     jumps to Ltmp49
	.long	Lset32
	.byte	0                       ##   On action: cleanup
Lset33 = Ltmp48-Lfunc_begin3            ## >> Call Site 3 <<
	.long	Lset33
Lset34 = Ltmp44-Ltmp48                  ##   Call between Ltmp48 and Ltmp44
	.long	Lset34
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset35 = Ltmp44-Lfunc_begin3            ## >> Call Site 4 <<
	.long	Lset35
Lset36 = Ltmp45-Ltmp44                  ##   Call between Ltmp44 and Ltmp45
	.long	Lset36
Lset37 = Ltmp46-Lfunc_begin3            ##     jumps to Ltmp46
	.long	Lset37
	.byte	0                       ##   On action: cleanup
Lset38 = Ltmp45-Lfunc_begin3            ## >> Call Site 5 <<
	.long	Lset38
Lset39 = Lfunc_end3-Ltmp45              ##   Call between Ltmp45 and Lfunc_end3
	.long	Lset39
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE16__insert_node_atEPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEERSO_SO_ ## -- Begin function _ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE16__insert_node_atEPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEERSO_SO_
	.weak_definition	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE16__insert_node_atEPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEERSO_SO_
	.p2align	4, 0x90
__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE16__insert_node_atEPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEERSO_SO_: ## @_ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE16__insert_node_atEPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEERSO_SO_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi66:
	.cfi_def_cfa_offset 16
Lcfi67:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi68:
	.cfi_def_cfa_register %rbp
	subq	$128, %rsp
	movq	%rdi, -96(%rbp)
	movq	%rsi, -104(%rbp)
	movq	%rdx, -112(%rbp)
	movq	%rcx, -120(%rbp)
	movq	-96(%rbp), %rcx
	movq	-120(%rbp), %rdx
	movq	$0, (%rdx)
	movq	-120(%rbp), %rdx
	movq	$0, 8(%rdx)
	movq	-104(%rbp), %rdx
	movq	-120(%rbp), %rsi
	movq	%rdx, 16(%rsi)
	movq	-120(%rbp), %rdx
	movq	-112(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	%rcx, -88(%rbp)
	movq	-88(%rbp), %rdx
	movq	(%rdx), %rdx
	cmpq	$0, (%rdx)
	movq	%rcx, -128(%rbp)        ## 8-byte Spill
	je	LBB23_2
## BB#1:
	movq	-128(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	(%rcx), %rcx
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	%rcx, (%rdx)
LBB23_2:
	movq	-128(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rcx
	addq	$8, %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rcx
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	(%rcx), %rdi
	movq	-112(%rbp), %rcx
	movq	(%rcx), %rsi
	callq	__ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_
	movq	-128(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rcx
	addq	$16, %rcx
	movq	%rcx, -72(%rbp)
	movq	-72(%rbp), %rcx
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	(%rcx), %rsi
	addq	$1, %rsi
	movq	%rsi, (%rcx)
	addq	$128, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISO_EERKT_ ## -- Begin function _ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISO_EERKT_
	.weak_definition	__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISO_EERKT_
	.p2align	4, 0x90
__ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISO_EERKT_: ## @_ZNSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISO_EERKT_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi69:
	.cfi_def_cfa_offset 16
Lcfi70:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi71:
	.cfi_def_cfa_register %rbp
	subq	$1840, %rsp             ## imm = 0x730
	movq	%rdi, -1560(%rbp)
	movq	%rsi, -1568(%rbp)
	movq	%rdx, -1576(%rbp)
	movq	-1560(%rbp), %rdx
	movq	%rdx, -1544(%rbp)
	movq	-1544(%rbp), %rsi
	movq	%rsi, -1536(%rbp)
	movq	-1536(%rbp), %rsi
	addq	$8, %rsi
	movq	%rsi, -1528(%rbp)
	movq	-1528(%rbp), %rsi
	movq	%rsi, -1520(%rbp)
	movq	-1520(%rbp), %rsi
	movq	%rsi, -1512(%rbp)
	movq	-1512(%rbp), %rsi
	movq	%rsi, -1504(%rbp)
	movq	-1504(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -1584(%rbp)
	movq	%rdx, %rdi
	movq	%rdx, -1600(%rbp)       ## 8-byte Spill
	callq	__ZNKSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE10__root_ptrEv
	movq	%rax, -1592(%rbp)
	cmpq	$0, -1584(%rbp)
	je	LBB24_59
## BB#1:
	jmp	LBB24_2
LBB24_2:                                ## =>This Inner Loop Header: Depth=1
	movq	-1600(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -752(%rbp)
	movq	-752(%rbp), %rcx
	addq	$16, %rcx
	movq	%rcx, -744(%rbp)
	movq	-744(%rbp), %rcx
	movq	%rcx, -736(%rbp)
	movq	-736(%rbp), %rcx
	movq	-1576(%rbp), %rdx
	movq	-1584(%rbp), %rsi
	addq	$32, %rsi
	movq	%rcx, -680(%rbp)
	movq	%rdx, -688(%rbp)
	movq	%rsi, -696(%rbp)
	movq	-680(%rbp), %rcx
	movq	-688(%rbp), %rdx
	movq	-696(%rbp), %rsi
	movq	%rcx, -656(%rbp)
	movq	%rdx, -664(%rbp)
	movq	%rsi, -672(%rbp)
	movq	-664(%rbp), %rcx
	movq	-672(%rbp), %rdx
	movq	%rcx, -640(%rbp)
	movq	%rdx, -648(%rbp)
	movq	-640(%rbp), %rcx
	movq	-648(%rbp), %rdx
	movq	%rcx, -608(%rbp)
	movq	%rdx, -616(%rbp)
	movq	-608(%rbp), %rcx
	movq	-616(%rbp), %rdx
	movq	%rdx, -600(%rbp)
	movq	-600(%rbp), %rdx
	movq	%rdx, -576(%rbp)
	movq	-576(%rbp), %rsi
	movq	%rsi, -568(%rbp)
	movq	-568(%rbp), %rsi
	movq	%rsi, -560(%rbp)
	movq	-560(%rbp), %rdi
	movq	%rdi, -552(%rbp)
	movq	-552(%rbp), %rdi
	movq	%rdi, -544(%rbp)
	movq	-544(%rbp), %rdi
	movzbl	(%rdi), %r8d
	movl	%r8d, %edi
	andq	$1, %rdi
	cmpq	$0, %rdi
	movq	%rcx, -1608(%rbp)       ## 8-byte Spill
	movq	%rdx, -1616(%rbp)       ## 8-byte Spill
	movq	%rsi, -1624(%rbp)       ## 8-byte Spill
	je	LBB24_4
## BB#3:                                ##   in Loop: Header=BB24_2 Depth=1
	movq	-1624(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -496(%rbp)
	movq	-496(%rbp), %rcx
	movq	%rcx, -488(%rbp)
	movq	-488(%rbp), %rcx
	movq	%rcx, -480(%rbp)
	movq	-480(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -1632(%rbp)       ## 8-byte Spill
	jmp	LBB24_5
LBB24_4:                                ##   in Loop: Header=BB24_2 Depth=1
	movq	-1624(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -536(%rbp)
	movq	-536(%rbp), %rcx
	movq	%rcx, -528(%rbp)
	movq	-528(%rbp), %rcx
	movq	%rcx, -520(%rbp)
	movq	-520(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -512(%rbp)
	movq	-512(%rbp), %rcx
	movq	%rcx, -504(%rbp)
	movq	-504(%rbp), %rcx
	movq	%rcx, -1632(%rbp)       ## 8-byte Spill
LBB24_5:                                ##   in Loop: Header=BB24_2 Depth=1
	movq	-1632(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -472(%rbp)
	movq	-472(%rbp), %rax
	movq	-1616(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -464(%rbp)
	movq	-464(%rbp), %rdx
	movq	%rdx, -456(%rbp)
	movq	-456(%rbp), %rsi
	movq	%rsi, -448(%rbp)
	movq	-448(%rbp), %rsi
	movq	%rsi, -440(%rbp)
	movq	-440(%rbp), %rsi
	movzbl	(%rsi), %edi
	movl	%edi, %esi
	andq	$1, %rsi
	cmpq	$0, %rsi
	movq	%rax, -1640(%rbp)       ## 8-byte Spill
	movq	%rdx, -1648(%rbp)       ## 8-byte Spill
	je	LBB24_7
## BB#6:                                ##   in Loop: Header=BB24_2 Depth=1
	movq	-1648(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -408(%rbp)
	movq	-408(%rbp), %rcx
	movq	%rcx, -400(%rbp)
	movq	-400(%rbp), %rcx
	movq	%rcx, -392(%rbp)
	movq	-392(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	%rcx, -1656(%rbp)       ## 8-byte Spill
	jmp	LBB24_8
LBB24_7:                                ##   in Loop: Header=BB24_2 Depth=1
	movq	-1648(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -432(%rbp)
	movq	-432(%rbp), %rcx
	movq	%rcx, -424(%rbp)
	movq	-424(%rbp), %rcx
	movq	%rcx, -416(%rbp)
	movq	-416(%rbp), %rcx
	movzbl	(%rcx), %edx
	sarl	$1, %edx
	movslq	%edx, %rcx
	movq	%rcx, -1656(%rbp)       ## 8-byte Spill
LBB24_8:                                ##   in Loop: Header=BB24_2 Depth=1
	movq	-1656(%rbp), %rax       ## 8-byte Reload
	leaq	-592(%rbp), %rcx
	movq	%rcx, -368(%rbp)
	movq	-1640(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -376(%rbp)
	movq	%rax, -384(%rbp)
	movq	-368(%rbp), %rax
	movq	-376(%rbp), %rdx
	movq	-384(%rbp), %rsi
	movq	%rax, -344(%rbp)
	movq	%rdx, -352(%rbp)
	movq	%rsi, -360(%rbp)
	movq	-344(%rbp), %rax
	movq	-352(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-360(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-592(%rbp), %rax
	movq	-584(%rbp), %rdx
	movq	%rax, -632(%rbp)
	movq	%rdx, -624(%rbp)
	movq	-632(%rbp), %rax
	movq	-624(%rbp), %rdx
	movq	%rax, -304(%rbp)
	movq	%rdx, -296(%rbp)
	movq	-1608(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -312(%rbp)
	movq	-312(%rbp), %rdx
	movq	%rdx, -280(%rbp)
	movq	-280(%rbp), %rsi
	movq	%rsi, -272(%rbp)
	movq	-272(%rbp), %rdi
	movq	%rdi, -264(%rbp)
	movq	-264(%rbp), %rdi
	movq	%rdi, -256(%rbp)
	movq	-256(%rbp), %rdi
	movzbl	(%rdi), %r8d
	movl	%r8d, %edi
	andq	$1, %rdi
	cmpq	$0, %rdi
	movq	%rdx, -1664(%rbp)       ## 8-byte Spill
	movq	%rsi, -1672(%rbp)       ## 8-byte Spill
	je	LBB24_10
## BB#9:                                ##   in Loop: Header=BB24_2 Depth=1
	movq	-1672(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -224(%rbp)
	movq	-224(%rbp), %rcx
	movq	%rcx, -216(%rbp)
	movq	-216(%rbp), %rcx
	movq	%rcx, -208(%rbp)
	movq	-208(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	%rcx, -1680(%rbp)       ## 8-byte Spill
	jmp	LBB24_11
LBB24_10:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1672(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -248(%rbp)
	movq	-248(%rbp), %rcx
	movq	%rcx, -240(%rbp)
	movq	-240(%rbp), %rcx
	movq	%rcx, -232(%rbp)
	movq	-232(%rbp), %rcx
	movzbl	(%rcx), %edx
	sarl	$1, %edx
	movslq	%edx, %rcx
	movq	%rcx, -1680(%rbp)       ## 8-byte Spill
LBB24_11:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1680(%rbp), %rax       ## 8-byte Reload
	leaq	-304(%rbp), %rcx
	movq	%rax, -320(%rbp)
	movq	%rcx, -200(%rbp)
	movq	-200(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -328(%rbp)
	movq	-1664(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -192(%rbp)
	movq	-192(%rbp), %rcx
	movq	%rcx, -184(%rbp)
	movq	-184(%rbp), %rcx
	movq	%rcx, -176(%rbp)
	movq	-176(%rbp), %rdx
	movq	%rdx, -168(%rbp)
	movq	-168(%rbp), %rdx
	movq	%rdx, -160(%rbp)
	movq	-160(%rbp), %rdx
	movzbl	(%rdx), %esi
	movl	%esi, %edx
	andq	$1, %rdx
	cmpq	$0, %rdx
	movq	%rcx, -1688(%rbp)       ## 8-byte Spill
	je	LBB24_13
## BB#12:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1688(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rcx
	movq	%rcx, -104(%rbp)
	movq	-104(%rbp), %rcx
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -1696(%rbp)       ## 8-byte Spill
	jmp	LBB24_14
LBB24_13:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1688(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -152(%rbp)
	movq	-152(%rbp), %rcx
	movq	%rcx, -144(%rbp)
	movq	-144(%rbp), %rcx
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	%rcx, -120(%rbp)
	movq	-120(%rbp), %rcx
	movq	%rcx, -1696(%rbp)       ## 8-byte Spill
LBB24_14:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1696(%rbp), %rax       ## 8-byte Reload
	leaq	-40(%rbp), %rcx
	leaq	-328(%rbp), %rdx
	leaq	-320(%rbp), %rsi
	leaq	-304(%rbp), %rdi
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rsi, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-64(%rbp), %rdx
	movq	-72(%rbp), %rsi
	movq	%rdx, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	-56(%rbp), %rdx
	movq	-48(%rbp), %rsi
	movq	%rcx, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-32(%rbp), %rdx
	cmpq	(%rdx), %rcx
	movq	%rax, -1704(%rbp)       ## 8-byte Spill
	movq	%rdi, -1712(%rbp)       ## 8-byte Spill
	jae	LBB24_16
## BB#15:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-56(%rbp), %rax
	movq	%rax, -1720(%rbp)       ## 8-byte Spill
	jmp	LBB24_17
LBB24_16:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-48(%rbp), %rax
	movq	%rax, -1720(%rbp)       ## 8-byte Spill
LBB24_17:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1720(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rdx
	movq	-1704(%rbp), %rdi       ## 8-byte Reload
	movq	-1712(%rbp), %rsi       ## 8-byte Reload
	callq	__ZNSt3__111char_traitsIcE7compareEPKcS3_m
	movl	%eax, -332(%rbp)
	cmpl	$0, -332(%rbp)
	je	LBB24_19
## BB#18:                               ##   in Loop: Header=BB24_2 Depth=1
	movl	-332(%rbp), %eax
	movl	%eax, -284(%rbp)
	jmp	LBB24_24
LBB24_19:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-320(%rbp), %rax
	cmpq	-328(%rbp), %rax
	jae	LBB24_21
## BB#20:                               ##   in Loop: Header=BB24_2 Depth=1
	movl	$-1, -284(%rbp)
	jmp	LBB24_24
LBB24_21:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-320(%rbp), %rax
	cmpq	-328(%rbp), %rax
	jbe	LBB24_23
## BB#22:                               ##   in Loop: Header=BB24_2 Depth=1
	movl	$1, -284(%rbp)
	jmp	LBB24_24
LBB24_23:                               ##   in Loop: Header=BB24_2 Depth=1
	movl	$0, -284(%rbp)
LBB24_24:                               ##   in Loop: Header=BB24_2 Depth=1
	cmpl	$0, -284(%rbp)
	jge	LBB24_29
## BB#25:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1584(%rbp), %rax
	cmpq	$0, (%rax)
	je	LBB24_27
## BB#26:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1584(%rbp), %rax
	movq	%rax, -704(%rbp)
	movq	-704(%rbp), %rax
	movq	%rax, -1592(%rbp)
	movq	-1584(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -1584(%rbp)
	jmp	LBB24_28
LBB24_27:
	movq	-1584(%rbp), %rax
	movq	-1568(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-1568(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -1552(%rbp)
	jmp	LBB24_60
LBB24_28:                               ##   in Loop: Header=BB24_2 Depth=1
	jmp	LBB24_58
LBB24_29:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1600(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -728(%rbp)
	movq	-728(%rbp), %rcx
	addq	$16, %rcx
	movq	%rcx, -720(%rbp)
	movq	-720(%rbp), %rcx
	movq	%rcx, -712(%rbp)
	movq	-712(%rbp), %rcx
	movq	-1584(%rbp), %rdx
	addq	$32, %rdx
	movq	-1576(%rbp), %rsi
	movq	%rcx, -1432(%rbp)
	movq	%rdx, -1440(%rbp)
	movq	%rsi, -1448(%rbp)
	movq	-1432(%rbp), %rcx
	movq	-1440(%rbp), %rdx
	movq	-1448(%rbp), %rsi
	movq	%rcx, -1408(%rbp)
	movq	%rdx, -1416(%rbp)
	movq	%rsi, -1424(%rbp)
	movq	-1416(%rbp), %rcx
	movq	-1424(%rbp), %rdx
	movq	%rcx, -1392(%rbp)
	movq	%rdx, -1400(%rbp)
	movq	-1392(%rbp), %rcx
	movq	-1400(%rbp), %rdx
	movq	%rcx, -1360(%rbp)
	movq	%rdx, -1368(%rbp)
	movq	-1360(%rbp), %rcx
	movq	-1368(%rbp), %rdx
	movq	%rdx, -1352(%rbp)
	movq	-1352(%rbp), %rdx
	movq	%rdx, -1328(%rbp)
	movq	-1328(%rbp), %rsi
	movq	%rsi, -1320(%rbp)
	movq	-1320(%rbp), %rsi
	movq	%rsi, -1312(%rbp)
	movq	-1312(%rbp), %rdi
	movq	%rdi, -1304(%rbp)
	movq	-1304(%rbp), %rdi
	movq	%rdi, -1296(%rbp)
	movq	-1296(%rbp), %rdi
	movzbl	(%rdi), %r8d
	movl	%r8d, %edi
	andq	$1, %rdi
	cmpq	$0, %rdi
	movq	%rcx, -1728(%rbp)       ## 8-byte Spill
	movq	%rdx, -1736(%rbp)       ## 8-byte Spill
	movq	%rsi, -1744(%rbp)       ## 8-byte Spill
	je	LBB24_31
## BB#30:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1744(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1248(%rbp)
	movq	-1248(%rbp), %rcx
	movq	%rcx, -1240(%rbp)
	movq	-1240(%rbp), %rcx
	movq	%rcx, -1232(%rbp)
	movq	-1232(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -1752(%rbp)       ## 8-byte Spill
	jmp	LBB24_32
LBB24_31:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1744(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1288(%rbp)
	movq	-1288(%rbp), %rcx
	movq	%rcx, -1280(%rbp)
	movq	-1280(%rbp), %rcx
	movq	%rcx, -1272(%rbp)
	movq	-1272(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -1264(%rbp)
	movq	-1264(%rbp), %rcx
	movq	%rcx, -1256(%rbp)
	movq	-1256(%rbp), %rcx
	movq	%rcx, -1752(%rbp)       ## 8-byte Spill
LBB24_32:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1752(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1224(%rbp)
	movq	-1224(%rbp), %rax
	movq	-1736(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1216(%rbp)
	movq	-1216(%rbp), %rdx
	movq	%rdx, -1208(%rbp)
	movq	-1208(%rbp), %rsi
	movq	%rsi, -1200(%rbp)
	movq	-1200(%rbp), %rsi
	movq	%rsi, -1192(%rbp)
	movq	-1192(%rbp), %rsi
	movzbl	(%rsi), %edi
	movl	%edi, %esi
	andq	$1, %rsi
	cmpq	$0, %rsi
	movq	%rax, -1760(%rbp)       ## 8-byte Spill
	movq	%rdx, -1768(%rbp)       ## 8-byte Spill
	je	LBB24_34
## BB#33:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1768(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1160(%rbp)
	movq	-1160(%rbp), %rcx
	movq	%rcx, -1152(%rbp)
	movq	-1152(%rbp), %rcx
	movq	%rcx, -1144(%rbp)
	movq	-1144(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	%rcx, -1776(%rbp)       ## 8-byte Spill
	jmp	LBB24_35
LBB24_34:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1768(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1184(%rbp)
	movq	-1184(%rbp), %rcx
	movq	%rcx, -1176(%rbp)
	movq	-1176(%rbp), %rcx
	movq	%rcx, -1168(%rbp)
	movq	-1168(%rbp), %rcx
	movzbl	(%rcx), %edx
	sarl	$1, %edx
	movslq	%edx, %rcx
	movq	%rcx, -1776(%rbp)       ## 8-byte Spill
LBB24_35:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1776(%rbp), %rax       ## 8-byte Reload
	leaq	-1344(%rbp), %rcx
	movq	%rcx, -1120(%rbp)
	movq	-1760(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1128(%rbp)
	movq	%rax, -1136(%rbp)
	movq	-1120(%rbp), %rax
	movq	-1128(%rbp), %rdx
	movq	-1136(%rbp), %rsi
	movq	%rax, -1096(%rbp)
	movq	%rdx, -1104(%rbp)
	movq	%rsi, -1112(%rbp)
	movq	-1096(%rbp), %rax
	movq	-1104(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-1112(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-1344(%rbp), %rax
	movq	-1336(%rbp), %rdx
	movq	%rax, -1384(%rbp)
	movq	%rdx, -1376(%rbp)
	movq	-1384(%rbp), %rax
	movq	-1376(%rbp), %rdx
	movq	%rax, -1056(%rbp)
	movq	%rdx, -1048(%rbp)
	movq	-1728(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1064(%rbp)
	movq	-1064(%rbp), %rdx
	movq	%rdx, -1032(%rbp)
	movq	-1032(%rbp), %rsi
	movq	%rsi, -1024(%rbp)
	movq	-1024(%rbp), %rdi
	movq	%rdi, -1016(%rbp)
	movq	-1016(%rbp), %rdi
	movq	%rdi, -1008(%rbp)
	movq	-1008(%rbp), %rdi
	movzbl	(%rdi), %r8d
	movl	%r8d, %edi
	andq	$1, %rdi
	cmpq	$0, %rdi
	movq	%rdx, -1784(%rbp)       ## 8-byte Spill
	movq	%rsi, -1792(%rbp)       ## 8-byte Spill
	je	LBB24_37
## BB#36:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1792(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -976(%rbp)
	movq	-976(%rbp), %rcx
	movq	%rcx, -968(%rbp)
	movq	-968(%rbp), %rcx
	movq	%rcx, -960(%rbp)
	movq	-960(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	%rcx, -1800(%rbp)       ## 8-byte Spill
	jmp	LBB24_38
LBB24_37:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1792(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1000(%rbp)
	movq	-1000(%rbp), %rcx
	movq	%rcx, -992(%rbp)
	movq	-992(%rbp), %rcx
	movq	%rcx, -984(%rbp)
	movq	-984(%rbp), %rcx
	movzbl	(%rcx), %edx
	sarl	$1, %edx
	movslq	%edx, %rcx
	movq	%rcx, -1800(%rbp)       ## 8-byte Spill
LBB24_38:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1800(%rbp), %rax       ## 8-byte Reload
	leaq	-1056(%rbp), %rcx
	movq	%rax, -1072(%rbp)
	movq	%rcx, -952(%rbp)
	movq	-952(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -1080(%rbp)
	movq	-1784(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -944(%rbp)
	movq	-944(%rbp), %rcx
	movq	%rcx, -936(%rbp)
	movq	-936(%rbp), %rcx
	movq	%rcx, -928(%rbp)
	movq	-928(%rbp), %rdx
	movq	%rdx, -920(%rbp)
	movq	-920(%rbp), %rdx
	movq	%rdx, -912(%rbp)
	movq	-912(%rbp), %rdx
	movzbl	(%rdx), %esi
	movl	%esi, %edx
	andq	$1, %rdx
	cmpq	$0, %rdx
	movq	%rcx, -1808(%rbp)       ## 8-byte Spill
	je	LBB24_40
## BB#39:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1808(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -864(%rbp)
	movq	-864(%rbp), %rcx
	movq	%rcx, -856(%rbp)
	movq	-856(%rbp), %rcx
	movq	%rcx, -848(%rbp)
	movq	-848(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -1816(%rbp)       ## 8-byte Spill
	jmp	LBB24_41
LBB24_40:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1808(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -904(%rbp)
	movq	-904(%rbp), %rcx
	movq	%rcx, -896(%rbp)
	movq	-896(%rbp), %rcx
	movq	%rcx, -888(%rbp)
	movq	-888(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -880(%rbp)
	movq	-880(%rbp), %rcx
	movq	%rcx, -872(%rbp)
	movq	-872(%rbp), %rcx
	movq	%rcx, -1816(%rbp)       ## 8-byte Spill
LBB24_41:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1816(%rbp), %rax       ## 8-byte Reload
	leaq	-792(%rbp), %rcx
	leaq	-1080(%rbp), %rdx
	leaq	-1072(%rbp), %rsi
	leaq	-1056(%rbp), %rdi
	movq	%rax, -840(%rbp)
	movq	-840(%rbp), %rax
	movq	%rdi, -760(%rbp)
	movq	-760(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rsi, -816(%rbp)
	movq	%rdx, -824(%rbp)
	movq	-816(%rbp), %rdx
	movq	-824(%rbp), %rsi
	movq	%rdx, -800(%rbp)
	movq	%rsi, -808(%rbp)
	movq	-808(%rbp), %rdx
	movq	-800(%rbp), %rsi
	movq	%rcx, -768(%rbp)
	movq	%rdx, -776(%rbp)
	movq	%rsi, -784(%rbp)
	movq	-776(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-784(%rbp), %rdx
	cmpq	(%rdx), %rcx
	movq	%rax, -1824(%rbp)       ## 8-byte Spill
	movq	%rdi, -1832(%rbp)       ## 8-byte Spill
	jae	LBB24_43
## BB#42:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-808(%rbp), %rax
	movq	%rax, -1840(%rbp)       ## 8-byte Spill
	jmp	LBB24_44
LBB24_43:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-800(%rbp), %rax
	movq	%rax, -1840(%rbp)       ## 8-byte Spill
LBB24_44:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1840(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rdx
	movq	-1824(%rbp), %rdi       ## 8-byte Reload
	movq	-1832(%rbp), %rsi       ## 8-byte Reload
	callq	__ZNSt3__111char_traitsIcE7compareEPKcS3_m
	movl	%eax, -1084(%rbp)
	cmpl	$0, -1084(%rbp)
	je	LBB24_46
## BB#45:                               ##   in Loop: Header=BB24_2 Depth=1
	movl	-1084(%rbp), %eax
	movl	%eax, -1036(%rbp)
	jmp	LBB24_51
LBB24_46:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1072(%rbp), %rax
	cmpq	-1080(%rbp), %rax
	jae	LBB24_48
## BB#47:                               ##   in Loop: Header=BB24_2 Depth=1
	movl	$-1, -1036(%rbp)
	jmp	LBB24_51
LBB24_48:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1072(%rbp), %rax
	cmpq	-1080(%rbp), %rax
	jbe	LBB24_50
## BB#49:                               ##   in Loop: Header=BB24_2 Depth=1
	movl	$1, -1036(%rbp)
	jmp	LBB24_51
LBB24_50:                               ##   in Loop: Header=BB24_2 Depth=1
	movl	$0, -1036(%rbp)
LBB24_51:                               ##   in Loop: Header=BB24_2 Depth=1
	cmpl	$0, -1036(%rbp)
	jge	LBB24_56
## BB#52:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1584(%rbp), %rax
	cmpq	$0, 8(%rax)
	je	LBB24_54
## BB#53:                               ##   in Loop: Header=BB24_2 Depth=1
	movq	-1584(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -1456(%rbp)
	movq	-1456(%rbp), %rax
	movq	%rax, -1592(%rbp)
	movq	-1584(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -1584(%rbp)
	jmp	LBB24_55
LBB24_54:
	movq	-1584(%rbp), %rax
	movq	-1568(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-1584(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -1552(%rbp)
	jmp	LBB24_60
LBB24_55:                               ##   in Loop: Header=BB24_2 Depth=1
	jmp	LBB24_57
LBB24_56:
	movq	-1584(%rbp), %rax
	movq	-1568(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-1592(%rbp), %rax
	movq	%rax, -1552(%rbp)
	jmp	LBB24_60
LBB24_57:                               ##   in Loop: Header=BB24_2 Depth=1
	jmp	LBB24_58
LBB24_58:                               ##   in Loop: Header=BB24_2 Depth=1
	jmp	LBB24_2
LBB24_59:
	movq	-1600(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1496(%rbp)
	movq	-1496(%rbp), %rcx
	addq	$8, %rcx
	movq	%rcx, -1488(%rbp)
	movq	-1488(%rbp), %rcx
	movq	%rcx, -1480(%rbp)
	movq	-1480(%rbp), %rcx
	movq	%rcx, -1472(%rbp)
	movq	-1472(%rbp), %rcx
	movq	%rcx, -1464(%rbp)
	movq	-1464(%rbp), %rcx
	movq	-1568(%rbp), %rdx
	movq	%rcx, (%rdx)
	movq	-1568(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -1552(%rbp)
LBB24_60:
	movq	-1552(%rbp), %rax
	addq	$1840, %rsp             ## imm = 0x730
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__111char_traitsIcE7compareEPKcS3_m ## -- Begin function _ZNSt3__111char_traitsIcE7compareEPKcS3_m
	.weak_definition	__ZNSt3__111char_traitsIcE7compareEPKcS3_m
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE7compareEPKcS3_m: ## @_ZNSt3__111char_traitsIcE7compareEPKcS3_m
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi72:
	.cfi_def_cfa_offset 16
Lcfi73:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi74:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -32(%rbp)
	jne	LBB25_2
## BB#1:
	movl	$0, -4(%rbp)
	jmp	LBB25_3
LBB25_2:
	movq	-16(%rbp), %rdi
	movq	-24(%rbp), %rsi
	movq	-32(%rbp), %rdx
	callq	_memcmp
	movl	%eax, -4(%rbp)
LBB25_3:
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNKSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE10__root_ptrEv ## -- Begin function _ZNKSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE10__root_ptrEv
	.weak_definition	__ZNKSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE10__root_ptrEv
	.p2align	4, 0x90
__ZNKSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE10__root_ptrEv: ## @_ZNKSt3__16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPFvPKcPciEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE10__root_ptrEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi75:
	.cfi_def_cfa_offset 16
Lcfi76:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi77:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -56(%rbp)
	movq	-56(%rbp), %rdi
	movq	%rdi, -48(%rbp)
	movq	-48(%rbp), %rdi
	addq	$8, %rdi
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rdi
	movq	%rdi, -32(%rbp)
	movq	-32(%rbp), %rdi
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rdi
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_ ## -- Begin function _ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_
	.weak_definition	__ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_
	.p2align	4, 0x90
__ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_: ## @_ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi78:
	.cfi_def_cfa_offset 16
Lcfi79:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi80:
	.cfi_def_cfa_register %rbp
	subq	$304, %rsp              ## imm = 0x130
	movq	%rdi, -152(%rbp)
	movq	%rsi, -160(%rbp)
	movq	-160(%rbp), %rsi
	cmpq	-152(%rbp), %rsi
	sete	%al
	movq	-160(%rbp), %rsi
	andb	$1, %al
	movb	%al, 24(%rsi)
LBB27_1:                                ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
	movb	%al, %cl
	movq	-160(%rbp), %rdx
	cmpq	-152(%rbp), %rdx
	movb	%cl, -177(%rbp)         ## 1-byte Spill
	je	LBB27_4
## BB#2:                                ##   in Loop: Header=BB27_1 Depth=1
	movq	-160(%rbp), %rax
	movq	%rax, -144(%rbp)
	movq	-144(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -192(%rbp)        ## 8-byte Spill
## BB#3:                                ##   in Loop: Header=BB27_1 Depth=1
	movq	-192(%rbp), %rax        ## 8-byte Reload
	movb	24(%rax), %cl
	xorb	$-1, %cl
	movb	%cl, -177(%rbp)         ## 1-byte Spill
LBB27_4:                                ##   in Loop: Header=BB27_1 Depth=1
	movb	-177(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB27_5
	jmp	LBB27_35
LBB27_5:                                ##   in Loop: Header=BB27_1 Depth=1
	movq	-160(%rbp), %rax
	movq	%rax, -136(%rbp)
	movq	-136(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -200(%rbp)        ## 8-byte Spill
## BB#6:                                ##   in Loop: Header=BB27_1 Depth=1
	movq	-200(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	-128(%rbp), %rdx
	movq	16(%rdx), %rdx
	cmpq	(%rdx), %rcx
	jne	LBB27_21
## BB#7:                                ##   in Loop: Header=BB27_1 Depth=1
	movq	-160(%rbp), %rax
	movq	%rax, -104(%rbp)
	movq	-104(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -208(%rbp)        ## 8-byte Spill
## BB#8:                                ##   in Loop: Header=BB27_1 Depth=1
	movq	-208(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -216(%rbp)        ## 8-byte Spill
## BB#9:                                ##   in Loop: Header=BB27_1 Depth=1
	movq	-216(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	%rcx, -168(%rbp)
	cmpq	$0, -168(%rbp)
	je	LBB27_14
## BB#10:                               ##   in Loop: Header=BB27_1 Depth=1
	movq	-168(%rbp), %rax
	testb	$1, 24(%rax)
	jne	LBB27_14
## BB#11:                               ##   in Loop: Header=BB27_1 Depth=1
	movq	-160(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -224(%rbp)        ## 8-byte Spill
## BB#12:                               ##   in Loop: Header=BB27_1 Depth=1
	movq	-224(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	movb	$1, 24(%rcx)
	movq	-160(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -232(%rbp)        ## 8-byte Spill
## BB#13:                               ##   in Loop: Header=BB27_1 Depth=1
	movq	-232(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	cmpq	-152(%rbp), %rcx
	sete	%dl
	movq	-160(%rbp), %rcx
	andb	$1, %dl
	movb	%dl, 24(%rcx)
	movq	-168(%rbp), %rcx
	movb	$1, 24(%rcx)
	jmp	LBB27_20
LBB27_14:
	movq	-160(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	-16(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	je	LBB27_17
## BB#15:
	movq	-160(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -240(%rbp)        ## 8-byte Spill
## BB#16:
	movq	-240(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rdi
	callq	__ZNSt3__118__tree_left_rotateIPNS_16__tree_node_baseIPvEEEEvT_
LBB27_17:
	movq	-160(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -248(%rbp)        ## 8-byte Spill
## BB#18:
	movq	-248(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	movb	$1, 24(%rcx)
	movq	-160(%rbp), %rcx
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -256(%rbp)        ## 8-byte Spill
## BB#19:
	movq	-256(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	movb	$0, 24(%rcx)
	movq	-160(%rbp), %rdi
	callq	__ZNSt3__119__tree_right_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	jmp	LBB27_35
LBB27_20:                               ##   in Loop: Header=BB27_1 Depth=1
	jmp	LBB27_34
LBB27_21:                               ##   in Loop: Header=BB27_1 Depth=1
	movq	-160(%rbp), %rax
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -264(%rbp)        ## 8-byte Spill
## BB#22:                               ##   in Loop: Header=BB27_1 Depth=1
	movq	-264(%rbp), %rax        ## 8-byte Reload
	movq	16(%rax), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -176(%rbp)
	cmpq	$0, -176(%rbp)
	je	LBB27_27
## BB#23:                               ##   in Loop: Header=BB27_1 Depth=1
	movq	-176(%rbp), %rax
	testb	$1, 24(%rax)
	jne	LBB27_27
## BB#24:                               ##   in Loop: Header=BB27_1 Depth=1
	movq	-160(%rbp), %rax
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -272(%rbp)        ## 8-byte Spill
## BB#25:                               ##   in Loop: Header=BB27_1 Depth=1
	movq	-272(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	movb	$1, 24(%rcx)
	movq	-160(%rbp), %rcx
	movq	%rcx, -80(%rbp)
	movq	-80(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -280(%rbp)        ## 8-byte Spill
## BB#26:                               ##   in Loop: Header=BB27_1 Depth=1
	movq	-280(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	cmpq	-152(%rbp), %rcx
	sete	%dl
	movq	-160(%rbp), %rcx
	andb	$1, %dl
	movb	%dl, 24(%rcx)
	movq	-176(%rbp), %rcx
	movb	$1, 24(%rcx)
	jmp	LBB27_33
LBB27_27:
	movq	-160(%rbp), %rax
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movq	-88(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	jne	LBB27_30
## BB#28:
	movq	-160(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -288(%rbp)        ## 8-byte Spill
## BB#29:
	movq	-288(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rdi
	callq	__ZNSt3__119__tree_right_rotateIPNS_16__tree_node_baseIPvEEEEvT_
LBB27_30:
	movq	-160(%rbp), %rax
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -296(%rbp)        ## 8-byte Spill
## BB#31:
	movq	-296(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	movb	$1, 24(%rcx)
	movq	-160(%rbp), %rcx
	movq	%rcx, -120(%rbp)
	movq	-120(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -304(%rbp)        ## 8-byte Spill
## BB#32:
	movq	-304(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	movb	$0, 24(%rcx)
	movq	-160(%rbp), %rdi
	callq	__ZNSt3__118__tree_left_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	jmp	LBB27_35
LBB27_33:                               ##   in Loop: Header=BB27_1 Depth=1
	jmp	LBB27_34
LBB27_34:                               ##   in Loop: Header=BB27_1 Depth=1
	jmp	LBB27_1
LBB27_35:
	addq	$304, %rsp              ## imm = 0x130
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__118__tree_left_rotateIPNS_16__tree_node_baseIPvEEEEvT_ ## -- Begin function _ZNSt3__118__tree_left_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	.weak_definition	__ZNSt3__118__tree_left_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	.p2align	4, 0x90
__ZNSt3__118__tree_left_rotateIPNS_16__tree_node_baseIPvEEEEvT_: ## @_ZNSt3__118__tree_left_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi81:
	.cfi_def_cfa_offset 16
Lcfi82:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi83:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -56(%rbp)
	movq	-56(%rbp), %rdi
	movq	8(%rdi), %rdi
	movq	%rdi, -64(%rbp)
	movq	-64(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-56(%rbp), %rax
	movq	%rdi, 8(%rax)
	movq	-56(%rbp), %rax
	cmpq	$0, 8(%rax)
	je	LBB28_3
## BB#1:
	movq	-56(%rbp), %rax
	movq	8(%rax), %rax
	movq	-56(%rbp), %rcx
	movq	%rax, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	%rcx, 16(%rax)
## BB#2:
	jmp	LBB28_3
LBB28_3:
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	movq	-64(%rbp), %rcx
	movq	%rax, 16(%rcx)
	movq	-56(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	-32(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	jne	LBB28_5
## BB#4:
	movq	-64(%rbp), %rax
	movq	-56(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rax, (%rcx)
	jmp	LBB28_7
LBB28_5:
	movq	-64(%rbp), %rax
	movq	-56(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	movq	%rcx, -80(%rbp)         ## 8-byte Spill
## BB#6:
	movq	-80(%rbp), %rax         ## 8-byte Reload
	movq	-72(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, 8(%rax)
LBB28_7:
	movq	-56(%rbp), %rax
	movq	-64(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-56(%rbp), %rax
	movq	-64(%rbp), %rcx
	movq	%rax, -16(%rbp)
	movq	%rcx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rcx
	movq	%rcx, 16(%rax)
## BB#8:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__119__tree_right_rotateIPNS_16__tree_node_baseIPvEEEEvT_ ## -- Begin function _ZNSt3__119__tree_right_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	.weak_definition	__ZNSt3__119__tree_right_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	.p2align	4, 0x90
__ZNSt3__119__tree_right_rotateIPNS_16__tree_node_baseIPvEEEEvT_: ## @_ZNSt3__119__tree_right_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi84:
	.cfi_def_cfa_offset 16
Lcfi85:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi86:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -56(%rbp)
	movq	-56(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -64(%rbp)
	movq	-64(%rbp), %rdi
	movq	8(%rdi), %rdi
	movq	-56(%rbp), %rax
	movq	%rdi, (%rax)
	movq	-56(%rbp), %rax
	cmpq	$0, (%rax)
	je	LBB29_3
## BB#1:
	movq	-56(%rbp), %rax
	movq	(%rax), %rax
	movq	-56(%rbp), %rcx
	movq	%rax, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	%rcx, 16(%rax)
## BB#2:
	jmp	LBB29_3
LBB29_3:
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	movq	-64(%rbp), %rcx
	movq	%rax, 16(%rcx)
	movq	-56(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	-32(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	jne	LBB29_5
## BB#4:
	movq	-64(%rbp), %rax
	movq	-56(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rax, (%rcx)
	jmp	LBB29_7
LBB29_5:
	movq	-64(%rbp), %rax
	movq	-56(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	movq	%rcx, -80(%rbp)         ## 8-byte Spill
## BB#6:
	movq	-80(%rbp), %rax         ## 8-byte Reload
	movq	-72(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, 8(%rax)
LBB29_7:
	movq	-56(%rbp), %rax
	movq	-64(%rbp), %rcx
	movq	%rax, 8(%rcx)
	movq	-56(%rbp), %rax
	movq	-64(%rbp), %rcx
	movq	%rax, -16(%rbp)
	movq	%rcx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rcx
	movq	%rcx, 16(%rax)
## BB#8:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m ## -- Begin function _ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	.weak_definition	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	.p2align	4, 0x90
__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m: ## @_ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
Lfunc_begin4:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception4
## BB#0:
	pushq	%rbp
Lcfi87:
	.cfi_def_cfa_offset 16
Lcfi88:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi89:
	.cfi_def_cfa_register %rbp
	subq	$384, %rsp              ## imm = 0x180
	movq	%rdi, -184(%rbp)
	movq	%rsi, -192(%rbp)
	movq	%rdx, -200(%rbp)
	movq	-184(%rbp), %rsi
Ltmp50:
	leaq	-216(%rbp), %rdi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_
Ltmp51:
	jmp	LBB30_1
LBB30_1:
	leaq	-216(%rbp), %rax
	movq	%rax, -176(%rbp)
	movq	-176(%rbp), %rax
	movb	(%rax), %cl
	movb	%cl, -249(%rbp)         ## 1-byte Spill
## BB#2:
	movb	-249(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB30_3
	jmp	LBB30_26
LBB30_3:
	leaq	-248(%rbp), %rax
	movq	-184(%rbp), %rcx
	movq	%rax, -160(%rbp)
	movq	%rcx, -168(%rbp)
	movq	-160(%rbp), %rax
	movq	-168(%rbp), %rcx
	movq	%rax, -144(%rbp)
	movq	%rcx, -152(%rbp)
	movq	-144(%rbp), %rax
	movq	-152(%rbp), %rcx
	movq	(%rcx), %rdx
	movq	-24(%rdx), %rdx
	addq	%rdx, %rcx
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	40(%rcx), %rcx
	movq	%rcx, (%rax)
	movq	-192(%rbp), %rsi
	movq	-184(%rbp), %rax
	movq	(%rax), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rax
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movl	8(%rax), %edi
	movq	%rsi, -264(%rbp)        ## 8-byte Spill
	movl	%edi, -268(%rbp)        ## 4-byte Spill
## BB#4:
	movl	-268(%rbp), %eax        ## 4-byte Reload
	andl	$176, %eax
	cmpl	$32, %eax
	jne	LBB30_6
## BB#5:
	movq	-192(%rbp), %rax
	addq	-200(%rbp), %rax
	movq	%rax, -280(%rbp)        ## 8-byte Spill
	jmp	LBB30_7
LBB30_6:
	movq	-192(%rbp), %rax
	movq	%rax, -280(%rbp)        ## 8-byte Spill
LBB30_7:
	movq	-280(%rbp), %rax        ## 8-byte Reload
	movq	-192(%rbp), %rcx
	addq	-200(%rbp), %rcx
	movq	-184(%rbp), %rdx
	movq	(%rdx), %rsi
	movq	-24(%rsi), %rsi
	addq	%rsi, %rdx
	movq	-184(%rbp), %rsi
	movq	(%rsi), %rdi
	movq	-24(%rdi), %rdi
	addq	%rdi, %rsi
	movq	%rsi, -72(%rbp)
	movq	-72(%rbp), %rsi
	movq	%rax, -288(%rbp)        ## 8-byte Spill
	movq	%rcx, -296(%rbp)        ## 8-byte Spill
	movq	%rdx, -304(%rbp)        ## 8-byte Spill
	movq	%rsi, -312(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__111char_traitsIcE3eofEv
	movq	-312(%rbp), %rcx        ## 8-byte Reload
	movl	144(%rcx), %esi
	movl	%eax, %edi
	callq	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	testb	$1, %al
	jne	LBB30_8
	jmp	LBB30_13
LBB30_8:
	movq	-312(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -32(%rbp)
	movb	$32, -33(%rbp)
	movq	-32(%rbp), %rsi
Ltmp53:
	leaq	-48(%rbp), %rdi
	callq	__ZNKSt3__18ios_base6getlocEv
Ltmp54:
	jmp	LBB30_9
LBB30_9:
	leaq	-48(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdi
Ltmp55:
	movq	__ZNSt3__15ctypeIcE2idE@GOTPCREL(%rip), %rsi
	callq	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp56:
	movq	%rax, -320(%rbp)        ## 8-byte Spill
	jmp	LBB30_10
LBB30_10:
	movb	-33(%rbp), %al
	movq	-320(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -8(%rbp)
	movb	%al, -9(%rbp)
	movq	-8(%rbp), %rdx
	movq	(%rdx), %rsi
	movq	56(%rsi), %rsi
	movsbl	-9(%rbp), %edi
Ltmp57:
	movl	%edi, -324(%rbp)        ## 4-byte Spill
	movq	%rdx, %rdi
	movl	-324(%rbp), %r8d        ## 4-byte Reload
	movq	%rsi, -336(%rbp)        ## 8-byte Spill
	movl	%r8d, %esi
	movq	-336(%rbp), %rdx        ## 8-byte Reload
	callq	*%rdx
Ltmp58:
	movb	%al, -337(%rbp)         ## 1-byte Spill
	jmp	LBB30_12
LBB30_11:
Ltmp59:
	movl	%edx, %ecx
	movq	%rax, -56(%rbp)
	movl	%ecx, -60(%rbp)
	leaq	-48(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
	movq	-56(%rbp), %rax
	movl	-60(%rbp), %ecx
	movq	%rax, -352(%rbp)        ## 8-byte Spill
	movl	%ecx, -356(%rbp)        ## 4-byte Spill
	jmp	LBB30_21
LBB30_12:
	leaq	-48(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
	movb	-337(%rbp), %al         ## 1-byte Reload
	movsbl	%al, %ecx
	movq	-312(%rbp), %rdi        ## 8-byte Reload
	movl	%ecx, 144(%rdi)
LBB30_13:
	movq	-312(%rbp), %rax        ## 8-byte Reload
	movl	144(%rax), %ecx
	movb	%cl, %dl
	movb	%dl, -357(%rbp)         ## 1-byte Spill
## BB#14:
	movq	-248(%rbp), %rdi
Ltmp60:
	movb	-357(%rbp), %al         ## 1-byte Reload
	movsbl	%al, %r9d
	movq	-264(%rbp), %rsi        ## 8-byte Reload
	movq	-288(%rbp), %rdx        ## 8-byte Reload
	movq	-296(%rbp), %rcx        ## 8-byte Reload
	movq	-304(%rbp), %r8         ## 8-byte Reload
	callq	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
Ltmp61:
	movq	%rax, -368(%rbp)        ## 8-byte Spill
	jmp	LBB30_15
LBB30_15:
	leaq	-240(%rbp), %rax
	movq	-368(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -240(%rbp)
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	cmpq	$0, (%rax)
	jne	LBB30_25
## BB#16:
	movq	-184(%rbp), %rax
	movq	(%rax), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rax
	movq	%rax, -112(%rbp)
	movl	$5, -116(%rbp)
	movq	-112(%rbp), %rax
	movl	-116(%rbp), %edx
	movq	%rax, -96(%rbp)
	movl	%edx, -100(%rbp)
	movq	-96(%rbp), %rax
	movl	32(%rax), %edx
	movl	-100(%rbp), %esi
	orl	%esi, %edx
Ltmp62:
	movq	%rax, %rdi
	movl	%edx, %esi
	callq	__ZNSt3__18ios_base5clearEj
Ltmp63:
	jmp	LBB30_17
LBB30_17:
	jmp	LBB30_18
LBB30_18:
	jmp	LBB30_25
LBB30_19:
Ltmp52:
	movl	%edx, %ecx
	movq	%rax, -224(%rbp)
	movl	%ecx, -228(%rbp)
	jmp	LBB30_22
LBB30_20:
Ltmp64:
	movl	%edx, %ecx
	movq	%rax, -352(%rbp)        ## 8-byte Spill
	movl	%ecx, -356(%rbp)        ## 4-byte Spill
	jmp	LBB30_21
LBB30_21:
	movl	-356(%rbp), %eax        ## 4-byte Reload
	movq	-352(%rbp), %rcx        ## 8-byte Reload
	leaq	-216(%rbp), %rdi
	movq	%rcx, -224(%rbp)
	movl	%eax, -228(%rbp)
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev
LBB30_22:
	movq	-224(%rbp), %rdi
	callq	___cxa_begin_catch
	movq	-184(%rbp), %rdi
	movq	(%rdi), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rdi
Ltmp65:
	movq	%rax, -376(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__18ios_base33__set_badbit_and_consider_rethrowEv
Ltmp66:
	jmp	LBB30_23
LBB30_23:
	callq	___cxa_end_catch
LBB30_24:
	movq	-184(%rbp), %rax
	addq	$384, %rsp              ## imm = 0x180
	popq	%rbp
	retq
LBB30_25:
	jmp	LBB30_26
LBB30_26:
	leaq	-216(%rbp), %rdi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev
	jmp	LBB30_24
LBB30_27:
Ltmp67:
	movl	%edx, %ecx
	movq	%rax, -224(%rbp)
	movl	%ecx, -228(%rbp)
Ltmp68:
	callq	___cxa_end_catch
Ltmp69:
	jmp	LBB30_28
LBB30_28:
	jmp	LBB30_29
LBB30_29:
	movq	-224(%rbp), %rdi
	callq	__Unwind_Resume
LBB30_30:
Ltmp70:
	movl	%edx, %ecx
	movq	%rax, %rdi
	movl	%ecx, -380(%rbp)        ## 4-byte Spill
	callq	___clang_call_terminate
Lfunc_end4:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table30:
Lexception4:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\201\201\200\200"      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	117                     ## Call site table length
Lset40 = Ltmp50-Lfunc_begin4            ## >> Call Site 1 <<
	.long	Lset40
Lset41 = Ltmp51-Ltmp50                  ##   Call between Ltmp50 and Ltmp51
	.long	Lset41
Lset42 = Ltmp52-Lfunc_begin4            ##     jumps to Ltmp52
	.long	Lset42
	.byte	5                       ##   On action: 3
Lset43 = Ltmp53-Lfunc_begin4            ## >> Call Site 2 <<
	.long	Lset43
Lset44 = Ltmp54-Ltmp53                  ##   Call between Ltmp53 and Ltmp54
	.long	Lset44
Lset45 = Ltmp64-Lfunc_begin4            ##     jumps to Ltmp64
	.long	Lset45
	.byte	5                       ##   On action: 3
Lset46 = Ltmp55-Lfunc_begin4            ## >> Call Site 3 <<
	.long	Lset46
Lset47 = Ltmp58-Ltmp55                  ##   Call between Ltmp55 and Ltmp58
	.long	Lset47
Lset48 = Ltmp59-Lfunc_begin4            ##     jumps to Ltmp59
	.long	Lset48
	.byte	3                       ##   On action: 2
Lset49 = Ltmp60-Lfunc_begin4            ## >> Call Site 4 <<
	.long	Lset49
Lset50 = Ltmp63-Ltmp60                  ##   Call between Ltmp60 and Ltmp63
	.long	Lset50
Lset51 = Ltmp64-Lfunc_begin4            ##     jumps to Ltmp64
	.long	Lset51
	.byte	5                       ##   On action: 3
Lset52 = Ltmp63-Lfunc_begin4            ## >> Call Site 5 <<
	.long	Lset52
Lset53 = Ltmp65-Ltmp63                  ##   Call between Ltmp63 and Ltmp65
	.long	Lset53
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset54 = Ltmp65-Lfunc_begin4            ## >> Call Site 6 <<
	.long	Lset54
Lset55 = Ltmp66-Ltmp65                  ##   Call between Ltmp65 and Ltmp66
	.long	Lset55
Lset56 = Ltmp67-Lfunc_begin4            ##     jumps to Ltmp67
	.long	Lset56
	.byte	0                       ##   On action: cleanup
Lset57 = Ltmp66-Lfunc_begin4            ## >> Call Site 7 <<
	.long	Lset57
Lset58 = Ltmp68-Ltmp66                  ##   Call between Ltmp66 and Ltmp68
	.long	Lset58
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset59 = Ltmp68-Lfunc_begin4            ## >> Call Site 8 <<
	.long	Lset59
Lset60 = Ltmp69-Ltmp68                  ##   Call between Ltmp68 and Ltmp69
	.long	Lset60
Lset61 = Ltmp70-Lfunc_begin4            ##     jumps to Ltmp70
	.long	Lset61
	.byte	5                       ##   On action: 3
Lset62 = Ltmp69-Lfunc_begin4            ## >> Call Site 9 <<
	.long	Lset62
Lset63 = Lfunc_end4-Ltmp69              ##   Call between Ltmp69 and Lfunc_end4
	.long	Lset63
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.byte	0                       ## >> Action Record 1 <<
                                        ##   Cleanup
	.byte	0                       ##   No further actions
	.byte	1                       ## >> Action Record 2 <<
                                        ##   Catch TypeInfo 1
	.byte	125                     ##   Continue to action 1
	.byte	1                       ## >> Action Record 3 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.private_extern	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_ ## -- Begin function _ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.globl	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.weak_definition	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.p2align	4, 0x90
__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_: ## @_ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
Lfunc_begin5:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception5
## BB#0:
	pushq	%rbp
Lcfi90:
	.cfi_def_cfa_offset 16
Lcfi91:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi92:
	.cfi_def_cfa_register %rbp
	subq	$480, %rsp              ## imm = 0x1E0
	movb	%r9b, %al
	movq	%rdi, -320(%rbp)
	movq	%rsi, -328(%rbp)
	movq	%rdx, -336(%rbp)
	movq	%rcx, -344(%rbp)
	movq	%r8, -352(%rbp)
	movb	%al, -353(%rbp)
	cmpq	$0, -320(%rbp)
	jne	LBB31_2
## BB#1:
	movq	-320(%rbp), %rax
	movq	%rax, -312(%rbp)
	jmp	LBB31_26
LBB31_2:
	movq	-344(%rbp), %rax
	movq	-328(%rbp), %rcx
	subq	%rcx, %rax
	movq	%rax, -368(%rbp)
	movq	-352(%rbp), %rax
	movq	%rax, -304(%rbp)
	movq	-304(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -376(%rbp)
	movq	-376(%rbp), %rax
	cmpq	-368(%rbp), %rax
	jle	LBB31_4
## BB#3:
	movq	-368(%rbp), %rax
	movq	-376(%rbp), %rcx
	subq	%rax, %rcx
	movq	%rcx, -376(%rbp)
	jmp	LBB31_5
LBB31_4:
	movq	$0, -376(%rbp)
LBB31_5:
	movq	-336(%rbp), %rax
	movq	-328(%rbp), %rcx
	subq	%rcx, %rax
	movq	%rax, -384(%rbp)
	cmpq	$0, -384(%rbp)
	jle	LBB31_9
## BB#6:
	movq	-320(%rbp), %rax
	movq	-328(%rbp), %rcx
	movq	-384(%rbp), %rdx
	movq	%rax, -232(%rbp)
	movq	%rcx, -240(%rbp)
	movq	%rdx, -248(%rbp)
	movq	-232(%rbp), %rax
	movq	(%rax), %rcx
	movq	96(%rcx), %rcx
	movq	-240(%rbp), %rsi
	movq	-248(%rbp), %rdx
	movq	%rax, %rdi
	callq	*%rcx
	cmpq	-384(%rbp), %rax
	je	LBB31_8
## BB#7:
	movq	$0, -320(%rbp)
	movq	-320(%rbp), %rax
	movq	%rax, -312(%rbp)
	jmp	LBB31_26
LBB31_8:
	jmp	LBB31_9
LBB31_9:
	cmpq	$0, -376(%rbp)
	jle	LBB31_21
## BB#10:
	xorl	%esi, %esi
	movl	$24, %eax
	movl	%eax, %edx
	leaq	-408(%rbp), %rcx
	movq	-376(%rbp), %rdi
	movb	-353(%rbp), %r8b
	movq	%rcx, -208(%rbp)
	movq	%rdi, -216(%rbp)
	movb	%r8b, -217(%rbp)
	movq	-208(%rbp), %rcx
	movq	-216(%rbp), %rdi
	movb	-217(%rbp), %r8b
	movq	%rcx, -184(%rbp)
	movq	%rdi, -192(%rbp)
	movb	%r8b, -193(%rbp)
	movq	-184(%rbp), %rcx
	movq	%rcx, -176(%rbp)
	movq	-176(%rbp), %rdi
	movq	%rdi, -168(%rbp)
	movq	-168(%rbp), %rdi
	movq	%rdi, %r9
	movq	%r9, -160(%rbp)
	movq	-160(%rbp), %r9
	movq	%rdi, -432(%rbp)        ## 8-byte Spill
	movq	%r9, %rdi
	movq	%rcx, -440(%rbp)        ## 8-byte Spill
	callq	_memset
	movq	-432(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -152(%rbp)
	movq	-152(%rbp), %rcx
	movq	%rcx, -144(%rbp)
	movq	-192(%rbp), %rsi
	movq	-440(%rbp), %rdi        ## 8-byte Reload
	movsbl	-193(%rbp), %edx
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEmc
	leaq	-408(%rbp), %rcx
	movq	-320(%rbp), %rsi
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	%rcx, -120(%rbp)
	movq	-120(%rbp), %rdi
	movq	%rdi, -112(%rbp)
	movq	-112(%rbp), %rdi
	movq	%rdi, -104(%rbp)
	movq	-104(%rbp), %rdi
	movzbl	(%rdi), %eax
	movl	%eax, %edi
	andq	$1, %rdi
	cmpq	$0, %rdi
	movq	%rsi, -448(%rbp)        ## 8-byte Spill
	movq	%rcx, -456(%rbp)        ## 8-byte Spill
	je	LBB31_12
## BB#11:
	movq	-456(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -464(%rbp)        ## 8-byte Spill
	jmp	LBB31_13
LBB31_12:
	movq	-456(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rcx
	movq	%rcx, -88(%rbp)
	movq	-88(%rbp), %rcx
	movq	%rcx, -80(%rbp)
	movq	-80(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -72(%rbp)
	movq	-72(%rbp), %rcx
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	%rcx, -464(%rbp)        ## 8-byte Spill
LBB31_13:
	movq	-464(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	-376(%rbp), %rcx
	movq	-448(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -8(%rbp)
	movq	%rax, -16(%rbp)
	movq	%rcx, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rcx
	movq	96(%rcx), %rcx
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdx
Ltmp71:
	movq	%rax, %rdi
	callq	*%rcx
Ltmp72:
	movq	%rax, -472(%rbp)        ## 8-byte Spill
	jmp	LBB31_14
LBB31_14:
	jmp	LBB31_15
LBB31_15:
	movq	-472(%rbp), %rax        ## 8-byte Reload
	cmpq	-376(%rbp), %rax
	je	LBB31_18
## BB#16:
	movq	$0, -320(%rbp)
	movq	-320(%rbp), %rax
	movq	%rax, -312(%rbp)
	movl	$1, -424(%rbp)
	jmp	LBB31_19
LBB31_17:
Ltmp73:
	leaq	-408(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -416(%rbp)
	movl	%ecx, -420(%rbp)
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
	jmp	LBB31_27
LBB31_18:
	movl	$0, -424(%rbp)
LBB31_19:
	leaq	-408(%rbp), %rdi
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
	movl	-424(%rbp), %eax
	testl	%eax, %eax
	movl	%eax, -476(%rbp)        ## 4-byte Spill
	je	LBB31_20
	jmp	LBB31_29
LBB31_29:
	movl	-476(%rbp), %eax        ## 4-byte Reload
	subl	$1, %eax
	movl	%eax, -480(%rbp)        ## 4-byte Spill
	je	LBB31_26
	jmp	LBB31_28
LBB31_20:
	jmp	LBB31_21
LBB31_21:
	movq	-344(%rbp), %rax
	movq	-336(%rbp), %rcx
	subq	%rcx, %rax
	movq	%rax, -384(%rbp)
	cmpq	$0, -384(%rbp)
	jle	LBB31_25
## BB#22:
	movq	-320(%rbp), %rax
	movq	-336(%rbp), %rcx
	movq	-384(%rbp), %rdx
	movq	%rax, -256(%rbp)
	movq	%rcx, -264(%rbp)
	movq	%rdx, -272(%rbp)
	movq	-256(%rbp), %rax
	movq	(%rax), %rcx
	movq	96(%rcx), %rcx
	movq	-264(%rbp), %rsi
	movq	-272(%rbp), %rdx
	movq	%rax, %rdi
	callq	*%rcx
	cmpq	-384(%rbp), %rax
	je	LBB31_24
## BB#23:
	movq	$0, -320(%rbp)
	movq	-320(%rbp), %rax
	movq	%rax, -312(%rbp)
	jmp	LBB31_26
LBB31_24:
	jmp	LBB31_25
LBB31_25:
	movq	-352(%rbp), %rax
	movq	%rax, -280(%rbp)
	movq	$0, -288(%rbp)
	movq	-280(%rbp), %rax
	movq	24(%rax), %rcx
	movq	%rcx, -296(%rbp)
	movq	-288(%rbp), %rcx
	movq	%rcx, 24(%rax)
	movq	-320(%rbp), %rax
	movq	%rax, -312(%rbp)
LBB31_26:
	movq	-312(%rbp), %rax
	addq	$480, %rsp              ## imm = 0x1E0
	popq	%rbp
	retq
LBB31_27:
	movq	-416(%rbp), %rdi
	callq	__Unwind_Resume
LBB31_28:
Lfunc_end5:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table31:
Lexception5:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset64 = Lfunc_begin5-Lfunc_begin5      ## >> Call Site 1 <<
	.long	Lset64
Lset65 = Ltmp71-Lfunc_begin5            ##   Call between Lfunc_begin5 and Ltmp71
	.long	Lset65
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset66 = Ltmp71-Lfunc_begin5            ## >> Call Site 2 <<
	.long	Lset66
Lset67 = Ltmp72-Ltmp71                  ##   Call between Ltmp71 and Ltmp72
	.long	Lset67
Lset68 = Ltmp73-Lfunc_begin5            ##     jumps to Ltmp73
	.long	Lset68
	.byte	0                       ##   On action: cleanup
Lset69 = Ltmp72-Lfunc_begin5            ## >> Call Site 3 <<
	.long	Lset69
Lset70 = Lfunc_end5-Ltmp72              ##   Call between Ltmp72 and Lfunc_end5
	.long	Lset70
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__111char_traitsIcE11eq_int_typeEii ## -- Begin function _ZNSt3__111char_traitsIcE11eq_int_typeEii
	.weak_definition	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE11eq_int_typeEii: ## @_ZNSt3__111char_traitsIcE11eq_int_typeEii
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi93:
	.cfi_def_cfa_offset 16
Lcfi94:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi95:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %esi
	cmpl	-8(%rbp), %esi
	sete	%al
	andb	$1, %al
	movzbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__111char_traitsIcE3eofEv ## -- Begin function _ZNSt3__111char_traitsIcE3eofEv
	.weak_definition	__ZNSt3__111char_traitsIcE3eofEv
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE3eofEv:       ## @_ZNSt3__111char_traitsIcE3eofEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi96:
	.cfi_def_cfa_offset 16
Lcfi97:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi98:
	.cfi_def_cfa_register %rbp
	movl	$4294967295, %eax       ## imm = 0xFFFFFFFF
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"0copy_with_memcpy"

L_.str.1:                               ## @.str.1
	.asciz	"1copy_with_loop"

L_.str.2:                               ## @.str.2
	.asciz	"2copy_with_loop_unrolling8"

L_.str.3:                               ## @.str.3
	.asciz	"time of "

L_.str.4:                               ## @.str.4
	.asciz	": "

L_.str.5:                               ## @.str.5
	.asciz	"ms"

L_.str.6:                               ## @.str.6
	.asciz	"allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size"


.subsections_via_symbols
