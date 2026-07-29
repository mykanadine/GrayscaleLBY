section .data
	divisor dq 255.0

section .text
default rel
bits 64 
global imgCvtGrayIntToDouble

imgCvtGrayIntToDouble:

	; convert int to float
	cvtsi2sd xmm0, ecx
	; load 255.0 into xmm1
	movsd xmm1, [divisor]    
	; divide
	divsd xmm0, xmm1
	ret