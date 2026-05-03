c++ -O2 -march=x86-64-v2 -I ../libs/linux/JoltPhysics -c ../GPhysics.cpp -o GPhysics.o &&
ar x ../libs/linux/JoltPhysics/libJolt.a &&
ar rcs libgphysics.a *.o
rm *.o