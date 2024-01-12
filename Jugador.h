#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <cstring>
#include "Fecha.h"
#include "Funciones_Globales.h"


class Jugador
{
    public:
        Jugador();
        Jugador(int dni, const char* n, const char* a, const char* e, const char* t, int c, int d, int ne, Fecha fi, float m);
        virtual ~Jugador();

        bool setDni(int n);
        bool setClaustro(int n);
        bool setDeporte(int n);
        bool setNumEquipo(int n);
        bool setMatricula(float n);
        void setNombre(const char* s);
        void setApellido(const char* s);
        void setEmail(const char* s);
        void setTelefono(const char* s);
        bool setInscripcion(Fecha insc);
        void setEstado(bool e);

        int getDni();
        int getClaustro();
        int getDeporte();
        int getNumEquipo();
        float getMatricula();
        const char* getNombre();
        const char* getApellido();
        const char* getEmail();
        const char* getTelefono();
        bool getEstado();
        Fecha getFechaInsc();

        bool cargar(int dni);
        void mostrar();

    private:
        int _dni, _claustro,_deporte, _numEquipo;
        float _matricula;
        char _nombre[30], _apellido[30], _email[30], _telefono[30];
        Fecha _fechaInscripcion;
        bool _estado;
};

#endif // JUGADOR_H
