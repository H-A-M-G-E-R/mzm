.align 2

.section .rodata
.global track_341

track_341_0:
	.byte 188, 0, 187, 75, 189, 10, 190, 42
	.byte 191, 64, 211, 60, 100, 132, 189, 8
	.byte 193, 12, 192, 17, 235, 45, 129, 192
	.byte 25, 129, 33, 129, 40, 129, 48, 129
	.byte 56, 129, 67, 139, 190, 42, 130, 30
	.byte 130, 21, 130, 15, 130, 10, 130, 8
	.byte 130, 5, 130, 3, 130, 1, 130, 0
	.byte 149, 177

track_341_1:
	.byte 188, 0, 189, 13, 190, 37, 191, 64
	.byte 193, 4, 192, 1, 231, 59, 100, 129
	.byte 192, 5, 129, 10, 129, 17, 129, 27
	.byte 129, 43, 129, 64, 162, 177

.align 2

track_341:
	.byte 2
	.byte 0
	.byte 164
	.byte 0
	.word voice_group3
	.word track_341_0
	.word track_341_1

.align 2
