g++ -c -o dialog3.o dialog3.cpp
windres -i dialog3_res.rc -o dialog3_res.o
g++ -mwindows -o dialog3 dialog3.o dialog3_res.o -lcomctl32
