#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Program Outline:
 * 
 * Prompt user to enter 2 doubles. The first will be tax percentage, and the second will be tip percentage.
 * Randomly choose meal cost.
 * Calculate tax and tip.
 * Display meal cost, tax amount, tip amount, and total bill on screen.
 * 
 */

void main()
{
    // initialize tax, tip, meal, and total variables
    double tax,tip,meal,total;
    // initialize t for time
    time_t t;

    // get user input for tax and tip
    printf("Format for entering percentages: 12.5% = 12.5\n");
    printf("Enter the tax percentage: ");
    scanf("%lf", &tax);
    printf("Enter the tip percentage: ");
    scanf("%lf", &tip);
    
    // seed pseudorandom number generator
    srand((unsigned) time(&t));

    // randomly select 1 of 4 meal options 
    switch (rand() % 4)
    {
        case 0: // salad
            meal = 9.95;
            break;
        case 1: // soup
            meal = 4.55;
            break;
        case 2: // sandwich
            meal = 13.25;
            break;
        case 3: // pizza
            meal = 22.35;
            break;
        default:
            break;
    }

    // Calculate the total bill
    total = meal * (tax/100 + tip/100 + 1);
    printf("Tax percentage: %.2f%\nTip percentage: %.2f%\nMeal cost: $%.2f\nTotal bill: $%.2f", tax, tip, meal, total);
}