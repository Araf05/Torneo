#ifndef DEPORTESDAT_H
#define DEPORTESDAT_H

#include "Deporte.h"

class DeportesDat
{
    public:
        DeportesDat(const char *name= "deportes.dat");
        virtual ~DeportesDat();

        bool agregar(const Deporte deporte);
        Deporte leer(int numRegistro);
        int getCantRegistros();
        int buscarXid(int numID);
        bool Modificar(Deporte deporte, int pos);
        bool Crear();

    private:
        char _fileName[30];
};

#endif // DEPORTESDAT_H
