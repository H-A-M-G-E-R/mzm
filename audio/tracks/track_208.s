.align 2

.global track_208

track_208_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 44
	.byte PAN, c_v
	.byte N18
	.byte Cn3, Gs4
	.byte W18

	.byte FINE

.align 2

track_208:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voice_group2
	.word track_208_0

.align 2
