g++ -c -o dialog2.o dialog2.cpp
windres -i dialog2_res.rc -o dialog2_res.o
g++ -mwindows -o dialog2 dialog2.o dialog2_res.o -lcomctl32
