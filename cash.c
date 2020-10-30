#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //This program count how many coins do you have to use to give back change. It is optimised to work with USD.

    //Declaration of variable for change represented in dollars.
    float change_value;

    //Asking user for change value in dollars.
    do
    {
        change_value = get_float("Please input how much change is owed, by typing correct value in USD (for example 1.25): ");
    }
    while (change_value <= 0);

    //Converting dollars to cents.
    int change_in_cents = round(change_value * 100);

    //printf("%i\n", change_in_cents);

    //Setting avaiable coin nominations in cents.
    int coin_nominations[4] = {1, 5, 10, 25};

    //Setting variable counting coins for change.
    int coin_counter = 0;

    //Dividing change with avaiable coins.
    while (change_in_cents >= coin_nominations[3])
    {
        coin_counter++;
        change_in_cents = change_in_cents - coin_nominations[3];
    }

    int first_nomination_counter = coin_counter;

    printf("You need %i coins of nomitation cent %i...\n", coin_counter, coin_nominations[3]);

    while (change_in_cents >= coin_nominations[2])
    {
        coin_counter++;
        change_in_cents = change_in_cents - coin_nominations[2];
    }

    int second_nomination_counter = coin_counter - first_nomination_counter;

    printf("You need %i coins of nomitation cent %i...\n", second_nomination_counter, coin_nominations[2]);

    while (change_in_cents >= coin_nominations[1])
    {
        coin_counter++;
        change_in_cents = change_in_cents - coin_nominations[1];
    }

    int third_nomination_counter = coin_counter - first_nomination_counter - second_nomination_counter;

    printf("You need %i coins of nomitation cent %i...\n", third_nomination_counter, coin_nominations[1]);

    while (change_in_cents >= coin_nominations[0])
    {
        coin_counter++;
        change_in_cents = change_in_cents - coin_nominations[0];
    }

    int fourth_nomination_counter = coin_counter - first_nomination_counter - second_nomination_counter - third_nomination_counter;

    printf("You need %i coins of nomitation cent %i...\n", fourth_nomination_counter, coin_nominations[0]);

    //Printing result.
    printf("In total you need:\n");
    printf("%i\n", coin_counter);
}