.align 2

.section .rodata
.global track_531

track_531_0:
	.byte 188, 0, 187, 75, 142, 189, 15, 190
	.byte 0, 191, 64, 193, 0, 243, 43, 100
	.byte 1, 243, 48, 100, 1, 129, 190, 2
	.byte 129, 3, 129, 6, 129, 8, 129, 11
	.byte 129, 14, 129, 18, 129, 23, 129, 29
	.byte 129, 38, 129, 44, 129, 48, 129, 52
	.byte 129, 55, 129, 58, 129, 61, 129, 63
	.byte 129, 65, 129, 67, 129, 68, 129, 70
	.byte 130, 70, 129, 71, 129, 70, 130, 70
	.byte 130, 68, 129, 67, 130, 65, 129, 63
	.byte 129, 61, 129, 60, 129, 58, 129, 56
	.byte 129, 54, 129, 52, 129, 50, 129, 47
	.byte 129, 44, 129, 41, 129, 36, 129, 31
	.byte 129, 26, 129, 23, 129, 20, 129, 17
	.byte 129, 14, 129, 13, 129, 10, 129, 9
	.byte 129, 7, 129, 6, 129, 4, 129, 3
	.byte 129, 2, 129, 0, 129, 0, 129, 177
	.byte 

track_531_1:
	.byte 188, 0, 189, 2, 190, 42, 191, 64
	.byte 212, 60, 80, 133, 64, 133, 71, 133
	.byte 71, 32, 133, 71, 12, 133, 177

.align 2

track_531:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group16
	.word track_531_0
	.word track_531_1

.align 2
