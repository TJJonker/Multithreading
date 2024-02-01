#include "SSESupport.h"
#include <iostream>

#if defined(_MSC_VER)
#include <intrin.h>
#elif defined(__GNU__) || defined(__clang__)
#include <cpuid.h>	
#endif

void SSESupport::CheckSupport()
{
#if defined(_MSC_VER)
    int info[4];
    __cpuid(info, 1);
    if (info[2] & (1 << 25))
        std::cout << "SSE is supported." << std::endl;
    if (info[2] & (1 << 26))
        std::cout << "SSE2 is supported." << std::endl;
    if (info[2] & (1 << 28))
        std::cout << "AVX is supported." << std::endl;
    // Add more checks for other SIMD instruction sets if needed

        // Check for AVX-512 using extended CPUID
    __cpuidex(info, 7, 0);
    if (info[1] & (1 << 16))
        std::cout << "AVX-512 is supported." << std::endl;

#elif defined(__GNUC__) || defined(__clang__)
    unsigned int eax, ebx, ecx, edx;
    __get_cpuid(1, &eax, &ebx, &ecx, &edx);
    if (ecx & bit_SSE)
        std::cout << "SSE is supported." << std::endl;
    if (ecx & bit_SSE2)
        std::cout << "SSE2 is supported." << std::endl;
    if (ecx & bit_AVX)
        std::cout << "AVX is supported." << std::endl;
    // Add more checks for other SIMD instruction sets if needed

    // Check for AVX-512 using extended CPUID
    __get_cpuid(7, &eax, &ebx, &ecx, &edx);
    if (ebx & (1 << 16))
        std::cout << "AVX-512 is supported." << std::endl;

#else
    std::cout << "CPUID detection not supported on this platform." << std::endl;
#endif
    std::cout << std::endl;
}
