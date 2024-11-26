section .text
bits 64
default rel
global daxpy

daxpy:
    xor r10, r10              ; Initialize loop counter (r10 = 0)
    
    ; Explicitly load A 
    movsd xmm6, xmm0          ; Move A (from xmm0) into xmm6
    
L1:
    cmp r10, r9               ; Compare r10 with n
    jge .done                  ; Exit loop if r10 >= n
    
    ; Load X[i] into xmm4
    mov rax, rcx              ; Base address of X 
    movsd xmm4, [rax + r10*8] ; xmm4 = X[i]

    ; Load Y[i] into xmm5
    mov rax, rdx              ; Base address of Y 
    movsd xmm5, [rax + r10*8] ; xmm5 = Y[i]

    ; Perform DAXPY: Z[i] = A * X[i] + Y[i]
    mulsd xmm4, xmm6          ; xmm4 = A * X[i] 
    addsd xmm4, xmm5          ; xmm4 = A * X[i] + Y[i]

    ; Store the result in Z[i]
    mov rax, r8               ; Base address of Z 
    movsd [rax + r10*8], xmm4 ; Z[i] = xmm4
    
    ; Increment loop counter
    inc r10
    jmp L1                    ; Repeat the loop

.done:
    movsd xmm0, xmm6 
    ret
