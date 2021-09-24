#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double tax_function(double tax, double fee) {
    return (fee * tax / 100);
}

double tips_function(double tips, double fee) {
    return (fee * tips / 100);
}

char* meal_select() {
    srand(time(NULL));
    int rd = rand() % 4;
    if (rd == 0)
    {
        return "9.95";
    }
    else if (rd == 1)
    {
        return "4.55";
    }
    else if (rd == 2)
    {
        return "13.25";
    }
    else if (rd == 3)
    {
        return "22.35";
    }
}

const char* meal_name(double fee) {
    if (fee == 9.95)
        return "Salad";
    else if (fee == 4.55)
        return "Soup";
    else if (fee == 13.25)
        return "Sandwich";
    else if (fee == 22.35)
        return "Pizza";
}

int main (int argc, char* argv[]) {
    double tax, tips, fee, total;
    fee = 0;
    total = 0;
    char *ptr;
    fee = strtod(meal_select(), &ptr);
    printf("fee is %f.\n", fee);
    tax = strtod(argv[1], &ptr);
    // sscanf(argv[1], "%f", &tax);
    tips = strtod(argv[2], &ptr);
    // sscanf(argv[2], "%f", &tips);
    tax = tax_function(tax, fee);
    tips = tips_function(tips, fee);
    printf("The item is %s.\n", meal_name(fee));
    printf("The price for the meal is: %.2f.\n", fee);
    printf("The tax is: %.2f.\n", tax);
    printf("The tips is: %.2f.\n", tips);
    printf("The total is: %.2f.\n", fee + tax + tips);
}