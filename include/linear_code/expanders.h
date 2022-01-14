#pragma once

#include "parameter.h"
#include <vector>
#include <linear_gkr/prime_field.h>
class graph
{
public:
    int degree;
    std::vector<std::vector<int>> neighbor;
    std::vector<std::vector<prime_field::field_element>> weight;
    int L, R;
};

graph C[100], D[100];

graph generate_random_expander(int L, int R, int d)
{
    graph ret;
    ret.degree = d;
    ret.neighbor.resize(L);
    ret.weight.resize(L);
    for(int i = 0; i < L; ++i)
    {
        ret.neighbor[i].resize(d);
        ret.weight[i].resize(d);
        for(int j = 0; j < d; ++j)
        {
            ret.neighbor[i][j] = rand() % R;
            ret.weight[i][j] = prime_field::random();
        }
    }
    ret.L = L;
    ret.R = R;
    return ret;
}

int expander_init(int n, int dep = 0)
{
    //random graph
    if(n <= distance_threshold)
    {
        return n;
    }
    else
    {
        C[dep] = generate_random_expander(n, (int)(alpha * n), cn);
        int L = expander_init((int)(alpha * n), dep + 1);
        D[dep] = generate_random_expander(L, (int)(n * (r - 1) - L), dn);
        return n + L + (int)(n * (r - 1) - L);
    }
}