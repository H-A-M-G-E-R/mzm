.align 2

.section .rodata
.global track_128

track_128_0:
	.byte 188, 0, 187, 75, 189, 41, 190, 11
	.byte 191, 64, 193, 12, 192, 17, 222, 62
	.byte 80, 129, 190, 14, 192, 22, 129, 190
	.byte 18, 192, 28, 129, 190, 24, 192, 33
	.byte 129, 190, 35, 192, 38, 129, 190, 44
	.byte 192, 43, 129, 190, 47, 192, 49, 129
	.byte 190, 46, 192, 54, 129, 190, 41, 192
	.byte 59, 129, 190, 35, 192, 64, 129, 190
	.byte 31, 192, 70, 129, 190, 28, 192, 75
	.byte 129, 190, 26, 192, 80, 129, 190, 25
	.byte 192, 85, 129, 190, 23, 192, 91, 129
	.byte 177

.align 2

track_128:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group1
	.word track_128_0

.align 2
