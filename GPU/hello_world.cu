#include <stdio.h>

/*
 * A simple introduction to programming in CUDA. 
 * This program prints "Hello World from GPU! from 10 CUDA threads running on the GPU."
 * (see - https://github.com/deeperlearning/professional-cuda-c-programming )
 */

__global__ void helloFromGPU()
{
    printf("Hello World from GPU!\n");
}

int main(int argc, char **argv)
{
    printf("Hello World from CPU!\n");

    helloFromGPU<<<1, 10>>>();
    cudaDeviceReset();
    return 0;
}
