c++ -O2 -march=x86-64-v2 -I ../libs/windows/JoltPhysics -c ../GPhysics.cpp -o GPhysics.o
ar x ../libs/windows/JoltPhysics/libJolt.a
ar rcs libgphysics.a *.o*
del *.o*