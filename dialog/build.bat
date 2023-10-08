gcc -c -o dialog.o dialog.c
windres -i dialog_res.rc -o dialog_res.o
gcc -mwindows -o dialog dialog.o dialog_res.o -lcomctl32
