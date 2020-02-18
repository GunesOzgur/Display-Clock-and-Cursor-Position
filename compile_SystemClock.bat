gcc.exe -c main.c -o main.o 
gcc.exe -c drawdigit.c -o drawdigit.o 
gcc.exe -c updatedigit.c -o updatedigit.o 
windres.exe -i resource.rc --input-format=rc -o SystemClock.res -O coff 
gcc.exe main.o drawdigit.o updatedigit.o SystemClock.res -o SystemClock.exe -static-libgcc -mwindows -lwinmm