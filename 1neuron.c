#include <stdlib.h>
#include <stdio.h>
#include <time.h>

float train[][2] = {
    
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
    {5, 10},
};
#define train_count (sizeof(train)/sizeof(train[0]))


// x1, x2, x3..
// w1, w2, w3, ..
// y = x1*w1 + x2*w2 + ...



float rand_float(void)
{
    return (float) rand()/ (float)  RAND_MAX;
}

float cost(float w){

    float result = 0.0f;
    for (size_t i = 0; i < train_count; ++i) {
        float x = train[i][0];
        float  y = x*w;
        float d = y - train[i][1];
        result += d*d;

       // printf("actual: %f, expected: %f\n", y, train[i][1]);
    }
    result /= train_count;
    return result;
}


int main()
{
    //srand(time(0));
    srand(2);
    // y = x*w;
    float w = rand_float()*10.0f;
   // float b = rand_float()*5.0f;

/* // Func 1
     float result = 0.0f;
    for (size_t i = 0; i < train_count; ++i) {
        float x = train[i][0];
        float  y = x*w;
        float d = y - train[i][1];
        result += d*d;

        printf("actual: %f, expected: %f\n", y, train[i][1]);
    }
    result /= train_count;
*/
   
   //parabola
   
    // cost function = w

    float eps = 1e-3;
    float rate = 1e-3;

    //finite difference, not usually used


 
    
    
    printf("%f\n", cost(w));
    for (size_t i = 0; i < 1000; ++i){
    float dcost = (cost(w + eps) - cost(w))/ eps;
    w -= rate*dcost;
    printf("cost = %f, w = %f\n", cost(w), w );
    }

    printf("expected yoy eps growth, %f\n", w);
    return 0;

}