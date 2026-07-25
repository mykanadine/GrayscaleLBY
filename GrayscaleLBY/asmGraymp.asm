section .data
	divisor dq 255.0

section .text
default rel
bits 64 
global imgCvtGrayIntToDouble

imgCvtGrayIntToDouble:

	; convert int to float
	cvtsi2sd xmm0, ecx

	; divide
	divsd xmm0, [divisor]
	ret