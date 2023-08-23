//1. Write a program in C to find absolute, relative and percentage error for round- off and truncation cases.
#include <stdio.h>
#include <math.h>

int main() {
    double trueValue, approximateValueRounded, approximateValueTruncated;

    // Input from user
    printf("Enter the true value: ");
    scanf("%lf", &trueValue);

    printf("Enter the approximate value (rounded): ");
    scanf("%lf", &approximateValueRounded);

    printf("Enter the approximate value (truncated): ");
    scanf("%lf", &approximateValueTruncated);

    // Calculate absolute error
    double absoluteErrorRounded = fabs(trueValue - approximateValueRounded);
    double absoluteErrorTruncated = fabs(trueValue - approximateValueTruncated);

    // Calculate relative error
    double relativeErrorRounded = absoluteErrorRounded / trueValue;
    double relativeErrorTruncated = absoluteErrorTruncated / trueValue;

    // Calculate percentage error
    double percentageErrorRounded = (absoluteErrorRounded / trueValue) * 100;
    double percentageErrorTruncated = (absoluteErrorTruncated / trueValue) * 100;

    // Display results
    printf("\nTrue Value: %f\n", trueValue);
    printf("Approximate Value (Rounded): %f\n", approximateValueRounded);
    printf("Approximate Value (Truncated): %f\n", approximateValueTruncated);
    printf("Absolute Error (Rounded): %f\n", absoluteErrorRounded);
    printf("Relative Error (Rounded): %f\n", relativeErrorRounded);
    printf("Percentage Error (Rounded): %f%%\n", percentageErrorRounded);
    printf("Absolute Error (Truncated): %f\n", absoluteErrorTruncated);
    printf("Relative Error (Truncated): %f\n", relativeErrorTruncated);
    printf("Percentage Error (Truncated): %f%%\n", percentageErrorTruncated);

    return 0;
}
