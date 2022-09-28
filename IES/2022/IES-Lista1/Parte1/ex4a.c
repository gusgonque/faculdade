#include <stdio.h>

void CalculaTemperaturaCelcius(double x) {
    double temperatura = ((x-32.0)*(5.0/9.0));
    printf("Temperatura em Celcius: %f", temperatura);

}


int main (){
    double x;
    printf("Digite a temperatura em Fahrenheit.\n - ");
    scanf("%d", &x);
    CalculaTemperaturaCelcius(x);
    return 0;
}
