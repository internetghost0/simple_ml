#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define train_count (sizeof(train) / sizeof(train[0]))
#define TIMES_OF_TRAIN 1500

// our model, [input, output]
float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
};

float rand_flost(void) 
{
    return (float) rand() / (float) RAND_MAX;
}

// if return value is closer to 0 then params are more correct
float cost(float w, float b) {
    float result = 0.0f;
    for (size_t i = 0; i < train_count; i++) {
        float x = train[i][0];
        float y = x*w + b;
        float d = y - train[i][1];
        result += d*d;
    }
    result /= train_count;
    return result;
}

int main(void) 
{
    srand(time(0));

    // weight
    float w = rand_flost() * 10.f;
    // bias
    float b = rand_flost() * 5.f;

    // magic numbers
    const float eps = 1e-3;
    const float rate = 1e-3;

    // training
    for (size_t i = 0; i < TIMES_OF_TRAIN; i++) {
        // calculating step of weight
        float dw = (cost(w + eps, b) - cost(w, b)) / eps;
        // calculating step of bias
        float db = (cost(w, b + eps) - cost(w, b)) / eps;
        // weight - weight_step * k
        w -= rate * dw;
        // bias - bias_step * k
        b -= rate * db;
        printf("try #%zu, cost: %f, w = %f, b = %f \n", i + 1, cost(w, b), w, b);
    }
    printf("-----------------------------------\n");
    printf("w = %f, b = %f\n", w, b);

    return 0;
}
