#ifndef JUGADORESDAT_H
#define JUGADORESDAT_H

#include "Jugador.h"

class JugadoresDat
{
    public:
        JugadoresDat(const char *name= "jugadores.dat");
        virtual ~JugadoresDat();

        bool agregar(const Jugador jugador);
        Jugador leer(int numRegistro);
        int getCantRegistros();
        int buscarXdni(int numDni);
        bool Modificar(Jugador jugador, int pos);
        bool Crear();

    private:
        char _fileName[30];

};

#endif // JUGADORESDAT_H
