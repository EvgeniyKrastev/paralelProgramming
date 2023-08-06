# paralelProgramming
Simple program for learning how to use OpenMP and vectorization to speed up a C++ code.
In this case, we use parallel collection of 16 elements from two arrays in the third array, along with threading and parallelization with omp simd. For this scenario, we multiply 2 matrices with 2048 elements horizontally and vertically. Without the modifications, the result for my laptop is 50 seconds, and after the modifications, it is 7 seconds.

To run the code, you need to execute it on Linux and install gcc and g++ from the command line. Then, follow the steps mentioned in the matrix.cpp file.

Technologies: C++, OpenMP Parallelization, OpenMP threads, Vectorization

![paint](https://github.com/EvgeniyKrastev/paralelProgramming/assets/65820929/4a490330-54d6-499f-955a-d064491a1184)
