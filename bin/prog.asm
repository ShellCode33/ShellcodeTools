section .text
global _start

_start:

	; write
	mov eax, 4
	mov ebx, 1
	mov ecx, offset string
	mov edx, stringSize
	int 0x80
