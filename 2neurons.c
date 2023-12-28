#include <stdlib.h>
#include <stdio.h>
#include <time.h>

float train[][2] = {
    
    {1, 3678},
    {2, 3896},
    {3, 4888},
    {4, 6218},
    {5, 6487},
};
#define train_count (sizeof(train)/sizeof(train[0]))


// x1, x2, x3..
// w1, w2, w3, ..
// y = x1*w1 + x2*w2 + ...



float rand_float(void)
{
    return (float) rand()/ (float)  RAND_MAX;
}

float cost(float w, float b){

    float result = 0.0f;
    for (size_t i = 0; i < train_count; ++i) {
        float x = train[i][0];
        float  y = x*w + b;
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
    float b = rand_float()*5.0f;


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


   
    
    
    printf("%f\n", cost(w, b));
    for (size_t i = 0; i < 100; ++i){
    float dw = (cost(w + eps, b) - cost(w, b))/ eps;
    float db = (cost(w, b + eps) - cost(w, b))/ eps;
    w -= rate*dw;
    b -= rate*db;
    printf("cost = %f, w = %f, b = %f\n", cost(w, b), w, b);
    }
    printf("w = %f, b = %f\n", w, b);
    printf("expected yoy eps growth, %f\n", w);
    return 0;

}