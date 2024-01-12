#ifndef FECHA_H
#define FECHA_H

class Fecha
{
    public:
        Fecha();
        Fecha(int day, int month, int year);
        virtual ~Fecha();

        bool setYear(int y);
        bool setMonth(int m);
        bool setDay(int d);

        int getYear();
        int getMonth();
        int getDay();

        void mostrar();
        bool cargar();
        bool validar(int day, int month, int year);

    private:
        int _year;
        int _month;
        int _day;
};

#endif // FECHA_H
