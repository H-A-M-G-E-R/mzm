.align 2

.section .rodata
.global track_292

track_292_0:
	.byte 188, 0, 187, 75, 189, 20, 190, 37
	.byte 191, 60, 209, 72, 40, 130, 71, 150
	.byte 189, 4, 231, 70, 157, 58, 60, 2
	.byte 152, 130, 189, 7, 190, 44, 211, 72
	.byte 40, 132, 72, 20, 130, 130, 189, 4
	.byte 226, 52, 60, 147, 177

track_292_1:
	.byte 188, 0, 174, 189, 7, 190, 44, 191
	.byte 60, 134, 142, 211, 72, 60, 132, 72
	.byte 20, 132, 177

track_292_2:
	.byte 188, 0, 175, 189, 24, 191, 64, 193
	.byte 4, 190, 37, 235, 72, 32, 131, 190
	.byte 31, 192, 63, 129, 130, 190, 25, 192
	.byte 43, 131, 190, 20, 192, 30, 131, 190
	.byte 17, 192, 19, 131, 190, 13, 192, 12
	.byte 131, 190, 10, 192, 7, 131, 190, 8
	.byte 192, 2, 131, 190, 5, 131, 4, 131
	.byte 2, 131, 1, 130, 0, 129, 177

.align 2

track_292:
	.byte 3
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_292_0
	.word track_292_1
	.word track_292_2

.align 2
