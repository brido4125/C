	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w8, #0
	str	w8, [sp, #28]                   ; 4-byte Folded Spill
	stur	wzr, [x29, #-4]
	sub	x8, x29, #8
	mov	w9, #10
	stur	w9, [x29, #-8]
	mov	x9, x8
	stur	x9, [x29, #-16]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-16]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-16]
	ldr	w9, [x8]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	adrp	x8, l___const.main.p1@PAGE
	add	x8, x8, l___const.main.p1@PAGEOFF
	ldr	x9, [x8]
	sub	x8, x29, #24
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	stur	x9, [x29, #-24]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	ldur	w8, [x29, #-24]
                                        ; implicit-def: $x10
	mov	x10, x8
	ldur	w9, [x29, #-20]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x10, [x9]
	str	x8, [x9, #8]
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	str	x8, [sp, #32]
	ldr	x8, [sp, #32]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.5@PAGE
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	ldr	x8, [sp, #32]
	ldr	w8, [x8]
                                        ; implicit-def: $x10
	mov	x10, x8
	ldr	x8, [sp, #32]
	ldr	w9, [x8, #4]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x10, [x9]
	str	x8, [x9, #8]
	adrp	x0, l_.str.6@PAGE
	add	x0, x0, l_.str.6@PAGEOFF
	bl	_printf
	ldr	w0, [sp, #28]                   ; 4-byte Folded Reload
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"x\354\235\230 \354\243\274\354\206\214\352\260\222 : %p\n"

l_.str.1:                               ; @.str.1
	.asciz	"\355\217\254\354\235\270\355\204\260 y\354\235\230 \354\243\274\354\206\214\352\260\222 = %p\n"

l_.str.2:                               ; @.str.2
	.asciz	"\355\217\254\354\235\270\355\204\260 y\352\260\200 \352\260\200\354\247\200\353\212\224 \352\260\222 = %d\n"

	.section	__TEXT,__literal8,8byte_literals
	.p2align	2                               ; @__const.main.p1
l___const.main.p1:
	.long	12                              ; 0xc
	.long	34                              ; 0x22

	.section	__TEXT,__cstring,cstring_literals
l_.str.3:                               ; @.str.3
	.asciz	"p1\354\235\230 \354\243\274\354\206\214 = %p\n"

l_.str.4:                               ; @.str.4
	.asciz	"p1\354\235\230 X\352\260\222 = %d, y\352\260\222 = %d\n"

l_.str.5:                               ; @.str.5
	.asciz	"\355\217\254\354\235\270\355\204\260\354\235\230 P\354\235\230 \354\243\274\354\206\214 = %p\n"

l_.str.6:                               ; @.str.6
	.asciz	"\355\217\254\354\235\270\355\204\260 P\354\235\230 X\352\260\222 = %d, y\352\260\222 = %d\n"

.subsections_via_symbols
