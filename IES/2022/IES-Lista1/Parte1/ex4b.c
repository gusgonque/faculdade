#include <stdio.h>

void CalculaTemperaturaCelcius(int x) {
    int temperatura = ((x-32)*(5/9));
    printf("Temperatura em Celcius: %d", temperatura);

}


int main (){
    int x;
    printf("Digite a temperatura em Fahrenheit.\n - ");
    scanf("%d", &x);
    CalculaTemperaturaCelcius(x);
    return 0;
}
