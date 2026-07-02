
OPTION CASEMAP:NONE

EXTERN Profiler_GetCurReturn:PROC

.code

Profiler_Return PROC

	lea rsp, qword ptr [rsp-128]
	movdqu [rsp+104], xmm0
	movdqu [rsp+88], xmm1
	mov qword ptr [rsp+80], rax
	mov qword ptr [rsp+72], rcx
	mov qword ptr [rsp+64], rdx
	mov qword ptr [rsp+56], r8
	mov qword ptr [rsp+48], r9
	mov qword ptr [rsp+40], r10
	mov qword ptr [rsp+32], r11

	call Profiler_GetCurReturn
	mov qword ptr [rsp+120], rax

	movdqu xmm0, [rsp+104]
	movdqu xmm1, [rsp+88]
	mov rax, qword ptr [rsp+80]
	mov rcx, qword ptr [rsp+72]
	mov rdx, qword ptr [rsp+64]
	mov r8, qword ptr [rsp+56]
	mov r9, qword ptr [rsp+48]
	mov r10, qword ptr [rsp+40]
	mov r11, qword ptr [rsp+32]

	lea rsp, qword ptr [rsp+128]
	jmp qword ptr [rsp-8]

Profiler_Return ENDP

END
