#ifndef DEPORTE_H
#define DEPORTE_H

#include <iostream>
#include <cstring>
#include "Fecha.h"
#include "Funciones_Globales.h"

class Deporte
{
    public:
        Deporte();
        virtual ~Deporte();

        void setIdDeporte(int n);
        bool setTipo(int n = 0);
        bool setOrigen(int n = 0);
        void setNombre(const char *name);
        void setEstado(bool e);

        int getIdDeporte();
        int getTipo();
        int getOrigen();
        const char *getNombre();
        bool getEstado();

        bool cargar(int id);
        void mostrar();

    private:
        int _idDeporte, _tipo, _origen;
        char _nombre[30];
        bool _estado;
};

#endif // DEPORTE_H
