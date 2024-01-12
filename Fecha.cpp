#include "Fecha.h"

#include <iostream>
#include <ctime>

Fecha::Fecha()
    : _year(0), _month(0), _day(0)
{
    time_t tiempo= time(nullptr);
    tm* fecha= localtime(&tiempo);

    setDay(fecha->tm_mday);
    setMonth(fecha->tm_mon+1);
    setYear(fecha->tm_year+1900);
}

Fecha::Fecha(int day, int month, int year)
    : _year(0), _month(0), _day(0)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

Fecha::~Fecha(){}

bool Fecha::setYear(int y)
{
    if( y > 0 )
    {
        _year=y;
        return true;
    }
    return false;
}

bool Fecha::setMonth(int m)
{
    if( m > 0 && m <13 )
    {
        _month=m;
        return true;
    }
    return false;
}

bool Fecha::setDay(int d)
{
    if( d>0 && d<32 )
    {
        _day=d;
        return true;
    }
    return false;
}

int Fecha::getYear() {return _year;}
int Fecha::getMonth() {return _month;}
int Fecha::getDay() {return _day;}

bool Fecha::validar(int day, int month, int year)
{
    int dia_maximo;
    bool fecha_correcta = false;

    if(day<1 && month<1 && year<1 ) return fecha_correcta;

    if ( month >= 1 && month <= 12 )
    {
        switch ( month )
        {
            case  1 :
            case  3 :
            case  5 :
            case  7 :
            case  8 :
            case 10 :
            case 12 : dia_maximo = 31;
                      break;

            case  4 :
            case  6 :
            case  9 :
            case 11 : dia_maximo = 30;
                      break;

            case  2 : if ( (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0) )
                          dia_maximo = 29;
                      else
                          dia_maximo = 28;
                      break;
        }

        if ( day >= 1 && day <= dia_maximo )
            fecha_correcta = true;
    }
    return fecha_correcta;
}


bool Fecha::cargar()
{
    int day, month, year;
    std::cout<<"Dia: ";
    std::cin>> day;
    std::cout<<"Mes: ";
    std::cin>> month;
    std::cout<<"A"<<(char)164<<"o: ";
    std::cin>> year;
    if(validar(day, month, year))
    {
        setDay(day);
        setMonth(month);
        setYear(year);
        return true;
    }
    std::cout<<"La fecha no es valida..."<<std::endl;
    return false;
}


void Fecha::mostrar()
{
    std::cout<<_day<<"/"<<_month<<"/"<<_year<<std::endl;
}

