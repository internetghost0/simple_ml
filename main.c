#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
};

#define train_count (sizeof(train) / sizeof(train[0]))
#define TIMES_OF_TRAIN 500

float rand_flost(void) 
{
    return (float) rand() / (float) RAND_MAX;
}

float cost(float w) {
    float result = 0.0f;
    for (size_t i = 0; i < train_count; i++) {
        float x = train[i][0];
        float y = x*w;
        float d = y - train[i][1];
        result += d*d;
    }
    result /= train_count;
    return result;
}

int main(void) 
{
    srand(time(0));

    float w = rand_flost() * 10.f;
    
    float eps = 1e-3;
    float rate = 1e-3;

    for (size_t i = 0; i < TIMES_OF_TRAIN; i++) {
        float dcost = (cost(w + eps) - cost(w)) / eps;
        printf("result: %f\n", cost(w));
        w -= rate * dcost;
        printf("result: %f\n", cost(w));
    }
    printf("%f\n", w);

    return 0;
}
