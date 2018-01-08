.equ		SWI_PrInt, 0x6b		@ write an integer
.equ		SWI_EXIT, 0x11		@ exit code
.equ		Stdout, 1			@ set output mode to be output view

		ldr	r3, =image		@ get starting address of image




.data
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
		.end

		
