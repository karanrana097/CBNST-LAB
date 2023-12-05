#include <stdio.h>
#include <math.h>

#define f(x) (cos(x) - x * exp(x))

int main()
{
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1;

    // Input initial guesses and tolerable error
    printf("Enter two initial guesses:\n");
    if (scanf("%f%f", &x0, &x1) != 2)
    {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    printf("Enter tolerable error:\n");
    if (scanf("%f", &e) != 1)
    {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    f0 = f(x0);
    f1 = f(x1);

    if (f0 * f1 > 0.0)
    {
        printf("Incorrect Initial Guesses.\n");
        return 1;
    }

    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do
    {
        x2 = (x0 + x1) / 2;
        f2 = f(x2);

        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);

        if (f0 * f2 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }
        step = step + 1;
    } while (fabs(f2) > e);

    printf("\nRoot is: %f\n", x2);

    return 0;
}
