.align 2

.section .rodata
.global track_365

track_365_0:
	.byte 188, 0, 187, 75, 189, 30, 190, 14
	.byte 191, 64, 186, 1, 234, 71, 92, 130
	.byte 190, 20, 130, 36, 129, 55, 130, 69
	.byte 130, 70, 130, 63, 129, 55, 130, 41
	.byte 130, 30, 130, 21, 130, 16, 130, 12
	.byte 130, 8, 130, 4, 130, 2, 130, 0
	.byte 129, 0, 129, 177

track_365_1:
	.byte 188, 0, 189, 31, 196, 40, 190, 14
	.byte 191, 64, 193, 12, 194, 127, 192, 17
	.byte 233, 64, 72, 1, 130, 190, 17, 192
	.byte 22, 130, 190, 21, 192, 28, 130, 190
	.byte 29, 192, 33, 130, 190, 42, 192, 38
	.byte 130, 190, 53, 192, 43, 130, 190, 56
	.byte 192, 49, 130, 190, 55, 192, 54, 130
	.byte 190, 49, 192, 59, 130, 190, 36, 192
	.byte 64, 130, 190, 26, 192, 70, 130, 190
	.byte 18, 192, 75, 130, 190, 12, 192, 80
	.byte 130, 190, 7, 192, 85, 130, 190, 3
	.byte 192, 91, 130, 190, 0, 192, 96, 129
	.byte 177

.align 2

track_365:
	.byte 2
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_365_0
	.word track_365_1

.align 2
