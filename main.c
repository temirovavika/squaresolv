#include <TXLib.h>

int squaresol(double coef_a, double coef_b, double coef_c);
int report(void);
void input(double *coef_a, double *coef_b, double *coef_c );
void output( int kolvo, double sol1, double sol2);
int case_square(double coef_a, double coef_b, double coef_c, double *sol1, double *sol2);
int case_linear(double coef_b, double coef_c, double *sol1);
int main(void)
{


    while(report() == 1) { }

    return 0;
}

int squaresol( double coef_a, double coef_b,  double coef_c, double *sol1, double *sol2)
{
    if (coef_a != 0)
    {
        if (case_square(coef_a, coef_b, coef_c, sol1, sol2 ) == 1)
            return 1;
        else if (case_square(coef_a, coef_b,  coef_c, sol1, sol2) == 2)
            return 2;
        else
            return 0;
        /*// quadratic
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
        } */
    }
    else
    {
        if (case_linear(coef_b, coef_c, sol1) == -1)
            return -1;
        else if (case_linear(coef_b, coef_c, sol1) == 0)
            return 0;
        else
            return 1;
        // linear
        /*if(coef_b == 0)
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
        } */
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

printf("������� ������������ ����������� ���������:");
    while(scanf("%lg %lg %lg", coef_a, coef_b, coef_c ) != 3)
    {
     while(getchar() != '\n') {};
     printf("������� ������ ��������:");
    }
}

void output(int kolvo, double sol1, double sol2)
{
 switch (kolvo)
            {
                case -1: printf("����������� ���������� ������\n");
                     break;
                case  0: printf("������ ���\n");
                     break;
                case  1: printf("���������� ������:%d ������ �����: %lg\n", kolvo, sol1);
                     break;
                case  2: printf("���������� ������:%d ����� ����� �������������: %lg, %lg\n",kolvo, sol1, sol2);
                     break;
                default: printf("# ������!!! ��������� ���������� ������\n");
                     break;

            }
}

int case_square( double coef_a, double coef_b,  double coef_c, double *sol1, double *sol2)
{
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

int case_linear(double coef_b, double coef_c, double *sol1)
{
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
