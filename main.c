#include <TXLib.h>

int squaresol(double coef_a, double coef_b, double coef_c, double *sol1, double *sol2);
int report(void);
void input(double *coef_a, double *coef_b, double *coef_c );
void output( int kolvo, double sol1, double sol2);
int case_square(double coef_a, double coef_b, double coef_c, double *sol1, double *sol2);
int case_linear(double coef_b, double coef_c, double *sol1, double *sol2);
int Un_test1( double coef_a, double coef_b, double coef_c, double sol1ex, double sol2ex, int kolvoex);
int dablsr(double sol1, double sol2);
int nansr(double sol1, double sol2);
int main(void)
{
    Un_test1(1, -5, 6, 3, 2, 2);
    Un_test1(1, -12, 36, 6, NAN, 1);
    Un_test1(0, 5, -10, 2, NAN, 1);
    Un_test1(0, 0, 0, NAN, NAN, -1);
    Un_test1(2, 3, 4, NAN, NAN, 0);
    Un_test1(0, 0, 4, NAN, NAN, 0);


    while(report() == 1) { }

    return 0;
}

int squaresol( double coef_a, double coef_b,  double coef_c, double *sol1, double *sol2)
{
    assert(sol1 != NULL);
    assert(sol2 != NULL);
    if (coef_a != 0)
    {
        return case_square(coef_a, coef_b, coef_c, sol1, sol2);
    }

    else
    {
        return case_linear(coef_b, coef_c, sol1, sol2);
    }
}

int  report(void)
{
    double coef_a = 0;
    double coef_b = 0;
    double coef_c = 0;
    double sol1   = 0;
    double sol2   = 0;
    int kolvo     = 0;

    input(&coef_a, &coef_b, &coef_c);
    kolvo = squaresol(coef_a, coef_b, coef_c, &sol1, &sol2);
    output(kolvo, sol1, sol2);

    return 1;
}

void input( double *coef_a, double *coef_b, double *coef_c)
{
    assert(coef_a != NULL);
    assert(coef_b != NULL);
    assert(coef_c != NULL);

    printf("Введите коэффициенты квадратного уравнения:");
        while(scanf("%lg %lg %lg", coef_a, coef_b, coef_c ) != 3)
        {
        while(getchar() != '\n') {};
        printf("Введите другие значения:");
        }
}

void output(int kolvo, double sol1, double sol2)
{
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
}

int case_square( double coef_a, double coef_b,  double coef_c, double *sol1, double *sol2)
{
    assert(sol1 != NULL);
    assert(sol2 != NULL);
    double diskr = coef_b *  coef_b - 4 * coef_a * coef_c;
        if (diskr == 0)
        {
            *sol1 = -coef_b / (2 * coef_a);
            *sol2 = NAN;
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
            *sol1 = NAN;
            *sol2 = NAN;

            return 0;
        }

}

int case_linear(double coef_b, double coef_c, double *sol1, double *sol2)
{
    assert(sol1 != NULL);
    if(coef_b == 0)
    {
        if(coef_c == 0)
        {
        *sol1 = NAN;
        *sol2 = NAN;
        return -1;
        }
        else
        {
        *sol1 = NAN;
        *sol2 = NAN;
        return 0;
        }
    }
    else
    {
        *sol1 = -coef_c / coef_b;
        *sol2 = NAN;
        return 1;
    }
}

int Un_test1(double coef_a, double coef_b, double coef_c, double sol1ex, double sol2ex, int kolvoex)
{
    double sol1 = 0;
    double sol2 = 0;
    int kolvo = squaresol(coef_a, coef_b, coef_c, &sol1, &sol2);

    if(!nansr(sol1, sol1ex) || !nansr(sol2, sol2ex) || kolvo != kolvoex)
    printf("Ошибка Test1: coef_a = %lg; coef_b = %lg, coef_c = %lg, sol1 = %lg, sol2 = %lg, kolvo = %d\n"
    "ожидалось: sol1 = %lg, sol2 = %lg, kolvo = %d\n",
    coef_a, coef_b, coef_c, sol1, sol2, kolvo, sol1ex, sol2ex, kolvoex);

    return 1;
}
int dablsr(double sol1, double sol2)
{
    const double p = 0.000000000001;
    if (fabs(sol1 - sol2) < p)
        return 1;
    else
        return 0;
}

int nansr(double sol1, double sol2)
{
    if ((isnan(sol1) && isnan(sol2))
        || (dablsr(sol1, sol2) == 1))
        return 1;
    else
        return 0;

}











