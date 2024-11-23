section .text
bits 64
default rel
global daxpy

; Arguments:
; - rcx: n (size of the vectors)
; - xmm0: A (scalar)
; - xmm1: address of X (pointer to vector X)
; - xmm2: address of Y (pointer to vector Y)
; - xmm3: address of Z (pointer to vector Z)

daxpy:
    ; Loop counter
    mov r8, rcx         ; r8 = n (number of iterations)
    xor r9, r9          ; r9 = 0 (index counter)

L1:
    movsd xmm4, [xmm1]  ; Store the value in xmm0 (X[i]) to xmm4
    movsd xmm5, [xmm2]  ; Store the value in xmm1 (Y[i]) to xmm5
    mulsd xmm0, xmm4    ; xmm0 = A * X[i]
    addsd xmm0, xmm5    ; xmm0 = xmm0 + Y[i]
    movsd [xmm3], xmm4  ; xmm3 = xmm0 = Z[i]
    addsd xmm1, 8
    addsd xmm2, 8
    ; Increment the loop counter
    inc r9              ; r9++

    ; Loop termination check
    cmp r9, r8          ; compare r9 with n
    jl L1               ; if r9 < n, continue the loop

    ret
