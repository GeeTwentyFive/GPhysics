c++ -O2 -march=x86-64-v2 -I ../libs -c ../GPhysics.cpp -o GPhysics.o &&
ar rcs libgphysics.a GPhysics.o
rm GPhysics.o