.align 2

.section .rodata
.global track_90

track_90_0:
	.byte 188, 0, 187, 75, 189, 0, 190, 0
	.byte 191, 64, 219, 60, 80, 140, 177

.align 2

track_90:
	.byte 1
	.byte 0
	.byte 0
	.byte 0
	.word voice_group1
	.word track_90_0

.align 2
