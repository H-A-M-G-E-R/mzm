.align 2

.section .rodata
.global track_140

track_140_0:
	.byte 188, 0, 187, 75, 189, 18, 190, 28
	.byte 191, 64, 213, 60, 127, 134, 60, 80
	.byte 135, 60, 60, 135, 60, 20, 134, 177
	.byte 

track_140_1:
	.byte 188, 0, 189, 19, 191, 64, 131, 190
	.byte 17, 231, 48, 112, 1, 129, 190, 24
	.byte 129, 29, 129, 32, 129, 35, 129, 36
	.byte 129, 38, 129, 38, 129, 38, 129, 38
	.byte 129, 37, 129, 36, 129, 35, 129, 29
	.byte 129, 23, 129, 18, 129, 14, 129, 10
	.byte 129, 7, 129, 5, 129, 4, 129, 3
	.byte 129, 1, 129, 0, 129, 0, 129, 177
	.byte 

.align 2

track_140:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word voice_group1
	.word track_140_0
	.word track_140_1

.align 2
