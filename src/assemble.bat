nasm -f win64 daxpy.asm
gcc -c main.c -o main.obj -m64
gcc main.obj daxpy.obj -o main.exe -m64
main.exe