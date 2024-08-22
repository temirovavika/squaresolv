#include <TXLib.h>

int squaresol(double coef_a, double coef_b, double therdcoef, double *sol1, double *sol2 );
int vvod(void);


int main(void)
{


    while(vvod() == 1) { }

    return 0;
}

int squaresol( double coef_a, double coef_b,  double coef_c, double *sol1, double *sol2)
{


    if (coef_a != 0)
    {
        // quadratic
        double diskr = coef_b *  coef_b - 4 * coef_a * coef_c;
        if (diskr == 0)
        {
            *sol1 = -coef_b / (2 * coef_a);
            *sol2 = *sol1;
            return 1;
        }
        else if (diskr > 0)
        {
            *sol1 = (-coef_b + sqrtf(diskr)) / (2 * coef_a);
            *sol2 = (-coef_b - sqrtf(diskr)) / (2 * coef_a);
            return 2;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        // linear
        if(coef_b == 0)
        {
            if(coef_c == 0)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            *sol1 = -coef_c / coef_b;
            return 1;
        }
    }



}

int  vvod(void)
{
    double coef_a = 0;
    double coef_b = 0;
    double coef_c = 0;
    double sol1   = 0;
    double sol2   = 0;
    int kolvo     = 0;
    int save_scanf = 0;

    printf("Введите коэффициенты квадратного уравнения:");
    while(scanf("%lg %lg %lg", &coef_a, &coef_b, &coef_c ) != 3)
    {
     while(getchar() != '\n') {};
     printf("Введите другие значения:");
    }

      kolvo = squaresol(coef_a, coef_b, coef_c, &sol1, &sol2);

            switch (kolvo)
            {
                case -1: printf("Бесконечное количество корней\n");
                     break;
                case  0: printf("Корней нет\n");
                     break;
                case  1: printf("Количество корней:%d корень равен: %lg\n", kolvo, sol1);
                     break;
                case  2: printf("Количество корней:%d корни равны соответсвенно: %lg, %lg\n",kolvo, sol1, sol2);
                     break;
                default: printf("# Ошибка!!! Необычное количество корней\n");
                     break;

            }
     return 1;
}
