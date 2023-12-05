//Write a program in C to find the roots of any polynomial / transcendental equation using bisection method correct up to three decimal places.

#include <stdio.h>
#include <math.h>

// Function for which we want to find the root
double f(double x) {
    return x * x - 4; // Example equation: x^2 - 4
}

// Bisection method implementation
double bisection(double a, double b, double epsilon) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval. f(a) and f(b) should have opposite signs.\n");
        return NAN;
    }

    double c;
    while ((b - a) >= epsilon) {
        c = (a + b) / 2;

        if (f(c) == 0.0) {
            printf("Root found: %0.3lf\n", c);
            return c;
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    printf("Approximate root: %0.3lf\n", c);
    return c;
}

int main() {
    double a, b, epsilon;
    
    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    
    printf("Enter the desired accuracy (epsilon): ");
    scanf("%lf", &epsilon);

    printf("Solving equation x^2 - 4 using Bisection method:\n");
    double root = bisection(a, b, epsilon);

    if (!isnan(root)) {
        printf("Final root: %0.3lf\n", root);
    }

    return 0;
}
