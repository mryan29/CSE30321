.equ		SWI_PrInt, 0x6b		@ write an integer
.equ		SWI_EXIT, 0x11		@ exit code
.equ		Stdout, 1			@ set output mode to be output view

		ldr	r3, =image		@ get starting address of image
		mov	r4, #0			@ set image array index
		ldr r5, =filter_one	@ starting address of filter
		mov r6, #0			@ filter array index
		ldr	r7, =feature_map_one	@ feature map starting address
		mov	r8, #0			@ feature map index
		mov	r11, #8			@ comparative value
		mov r14, #32		@ comparative value
		mov	r12, #0			@ counter
		mov r13, #12		@ comparative value


loop:
		ldr	r1, [r3, r4]		@ load element into array
		ldr r2, [r5, r6]		@ load first filter element into array
		mul	r9, r1, r2			@ calculate image[i][j]*filter[i][j] to be appended
		ldr	r10, [r7, r8]		@ load first element of feature map 			
		add	r10, r10, r9		@ add result to output map entry
		str r10, [r7, r8]		@ save

		add r4, r4, #4			@ increment image index
		add	r6, r6, #4			@ increment filter index
		add r12, r12, #4		@ increment counter
		cmp r6, r14				@ check if we've exceeded bounds of filter array
		beq	shift
		cmp r12, r11			@ if we reach the end of a filter row, skip some lines in the image array
		bgt	skip
		ble	loop

skip:
		mov	r12, #0				@ reset counter
		add r4, r4, #12			@ skip 3 entries in image - assume 6x6 matrix
		b	loop

shift:
		ldr r10, [r7, r8] 		@ print result
		mov	r0, #Stdout
		swi	SWI_PrInt
		add	r8, r8, #4			@ increment output index
		cmp r8, r13				@ if we haven't filled it don't exit 
		bgt	exit
		mov r4, #4				@ start image index at second value
		mov r6, #0				@ filter index is just at 0 again
		
exit:
		swi	SWI_EXIT

.data
		filter_one:
			.word 1
			.word 1
			.word 1
			.word 0
			.word 0
			.word 0
			.word 0
			.word 0
			.word 0
		
		image:
			.word 71
			.word 76
			.word 87
			.word 102
			.word 103
			.word 103
			.word 82
			.word 71
			.word 84
			.word 100
			.word 103
			.word 104
			.word 85
			.word 71
			.word 81
			.word 97
			.word 102
			.word 105
			.word 87
			.word 73
			.word 78
			.word 98
			.word 105
			.word 104
			.word 91
			.word 74
			.word 76
			.word 95
			.word 103
			.word 105
			.word 108
			.word 71
			.word 48
			.word 42
			.word 50
			.word 16
		


		filter_two:
			.word 1
			.word 0
			.word 0
			.word 1
			.word 0
			.word 0
			.word 1
			.word 0
			.word 0

		filter_three:
			.word 1
			.word 0
			.word 0
			.word 0
			.word 1
			.word 0
			.word 0
			.word 0
			.word 1

		feature_map_one:
			.word 1
			.word 1
			.word 1
			.word 1

		feature_map_two:
			.word 1
			.word 1
			.word 1
			.word 1

		feature_map_three:
			.word 1
			.word 1
			.word 1
			.word 1

		
