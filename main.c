#include <TXLib.h>

void squaresol(double, double, double);
int main(void)
{
    double firstcoef = 0;
    double secondcoef = 0;
    double thirdcoef = 0;


    printf("Введите коэффициенты квадратного уравнения:");
    while (scanf("%lg %lg %lg", &firstcoef, &secondcoef, &thirdcoef)==3)
    {
        squaresol(firstcoef, secondcoef, thirdcoef);
        printf("Введите следующие значения:");
    }

return 0;
}

void squaresol( double firstcoef, double secondcoef,  double thirdcoef)
{
    double diskr = 0;
    double sol1 = 0;
    double sol2 = 0;

    diskr = secondcoef *  secondcoef - 4 * firstcoef * thirdcoef;

    if (firstcoef == 0 && secondcoef == 0 && thirdcoef == 0)
            printf("Бесконечное количество кореней\n");

    else if (firstcoef == 0 && secondcoef != 0)
            printf("Линейный случай корень равен: %lg \n", (-thirdcoef) / secondcoef);

    else if (diskr > 0)
    {
        sol1 = ((-secondcoef) + sqrt(diskr)) / 2 * firstcoef;
        sol2 = ((-secondcoef) - sqrt(diskr)) / 2 * firstcoef;
        printf("Корни уравнения равны соответсвенно %lg и %lg \n", sol1, sol2);
    }

    else if (diskr == 0)
    {
        sol1 = (-secondcoef) / 2 * firstcoef;
        sol2 = sol1;
        printf("Единственный корень равен %lg\n",sol1);
    }

    else
        printf("Корней нет\n");

}
