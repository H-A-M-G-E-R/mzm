.align 2

.global track_449

track_449_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 78
	.byte PAN, c_v-20
	.byte N08
	.byte Cn3, En6
	.byte W08
	.byte Cn3, Gs0
	.byte W08
	.byte Cn3, GsM2
	.byte W08

	.byte FINE

.align 2

track_449:
	.byte 1
	.byte 0
	.byte 202
	.byte 0
	.word voice_group10
	.word track_449_0

.align 2
