#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double F(double i, double absError, int numberMax)
{
    double sum=1;
    double term=1;
    for (double j=1;j<numberMax;j++)
    {
        double q=j;
        while(q!=0)//считаем слагаемые
        {
            term*=(q*2-1)/(q*2);
            q-=1;
        }
        q=2*j;
        while(q!=0)
        {
            term*=i;
            q--;
        }
        if(j==numberMax-1)//проверка последнего слагаемого
        {
            if(term>absError)
                return -1;
        }
        sum+=term;//сумма всех слагаемых
        term=1;
    }
    if(numberMax==1 && absError<1)
        return -1;
    return sum;
}
int main() {
    int numberMax;
    double intervalStep;
    double x_1,x_2, absError;
    double i;
    cout<<"Введите начальное значение промежутка: ";
    try {
        cin >> x_1;//ввод переменных
        if (!cin)
            throw "Ошибка. Введите число.";
        if((x_1>=1) || x_1<=-1)
            throw "начальное значение не принадлежит промежутку (-1;1)";
        cout<<"Введите конечное значение промежутка: ";
        cin>>x_2;
        if (!cin)
            throw "Ошибка. Введите число.";
        if((x_2>=1) || x_2<=-1)
            throw "конечное значение не принадлежит промежутку (-1;1)";
        if(x_1>=x_2)
            throw "Начальное значение должно быть меньше конечного";
        cout<<"Введите absError: ";
        cin>> absError;
        if (!cin)
            throw "Ошибка. Введите положительное число.";
        if(absError<=0)
            throw "Ошибка. Введите положительное число.";
        cout<<"Введите numberMax: ";
        cin>>numberMax;
        if (!cin)
            throw "Ошибка. Введите целое число.";
        cout<<"Введите значение шага: ";
        cin>>intervalStep;
        if (!cin)
            throw "Ошибка. Введите положительное число.";
        if(intervalStep<=0)
            throw "Ошибка. Введите положительное число";

    }
    catch(const char*errorString)
    {
        cerr<<endl<<errorString<<endl;
        return -1;
    }
    cout<<"x"<<"\t   1/sqrt(1-x^2)"<<"\tзначение функции"<<"\t  Точность"<<endl;
    for( i=x_1;i<=x_2;i+=intervalStep)//вывод
    {
        if(F(i,absError,numberMax)!=-1)
            cout<<i<<"\t"<<"\t"<<setw(10)<<1/sqrt(1-(i)*(i))<<"\t"<<"\t"<<"\t"<<F(i,absError,numberMax)<<
            "\t"<<"\t"<<"\t"<<"достигнута"<<endl;
        else
            cout<<i<<"\t"<<"\t"<<setw(10)<<1/sqrt(1-(i)*(i))<<"\t"<<"\t"<<"\t"<<F(i,absError,numberMax)<<"\t"<<"\t"<<"\t"<<"\t"<<"не достигнута"<<endl;
    }
    return 0;
}
