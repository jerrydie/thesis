#include "RandomPermutation.hpp"

#include <iostream>

#define n 10
namespace rp = thesis::random_permutation;

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<uint16_t> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    rp::Permutation perm(arr, n, gen);
    std::cout << "Content:         " << perm;
    perm.permute();
    std::cout << "Permuted Content:" << perm;
    return 0;
}