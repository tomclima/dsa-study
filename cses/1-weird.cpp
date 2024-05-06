#include <stdio.h>
using ll = long long int;

int main()
{
    ll number;

    scanf("%lld", &number);

    printf("%lld ", number);
    while (number > 1){
        if(number % 2 == 0){
            number = number/2;
        }
        else{
            number = 3*number + 1;
        }
        printf("%lld ", number);
    }
}