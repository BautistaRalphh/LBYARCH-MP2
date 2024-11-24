section .text
bits 64
default rel
global daxpy

daxpy:
    ; rcx = n 
    ; xmm0 = scalar A 
    ; rdx = pointer to array X 
    ; r8 = pointer to array Y 
    ; r9 = pointer to array Z 

    mov r10, rcx              ; r10 = n 
    mov r11, r11              ; r11 = 0 

L1:
    ; Load X[i] into xmm4
    mov rax, rdx              
    mov rbx, r11              
    movsd xmm4, [rax + rbx*8] ; xmm4 = X[i] 

    ; Load Y[i] into xmm5
    mov rax, r8               ; rax = base address of Y
    movsd xmm5, [rax + rbx*8] ; xmm5 = Y[i] 

    ; Perform DAXPY: Z[i] = A * X[i] + Y[i]
    mulsd xmm4, xmm0          ; xmm4 = A * X[i] 
    addsd xmm4, xmm5          ; xmm4 = A * X[i] + Y[i]

    ; Store the result in Z[i]
    mov rax, r9               
    movsd [rax + rbx*8], xmm4 ; Z[i] = A * X[i] + Y[i] 

    ; Increment the index counter (r11++)
    inc r11                    

    cmp r11, r10               ; Compare r11 with n
    jl L1                      ; If r11 < n, jump to L1

    ret
