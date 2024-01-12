#include "JugadoresDat.h"

JugadoresDat::JugadoresDat(const char *name)
{
    strcpy(_fileName, name);
}

JugadoresDat::~JugadoresDat(){}

bool JugadoresDat::agregar(const Jugador jugador)
{
    FILE* pFile = fopen( _fileName, "ab");
    if(pFile == nullptr) return false;

    bool pudoAgregar= fwrite(&jugador, sizeof(Jugador), 1, pFile);
    fclose(pFile);
    return pudoAgregar;
}


Jugador JugadoresDat::leer(int numRegistro)
{
    FILE* pFile= fopen( _fileName, "rb");
    if(pFile == nullptr) exit(-1);
    Jugador jugador;

    fseek(pFile,sizeof(Jugador)*numRegistro, SEEK_SET);

    fread(&jugador, sizeof(Jugador), 1, pFile);

    fclose(pFile);
    return jugador;
}

int JugadoresDat::getCantRegistros()
{
    int cantidad= -1;

    FILE* pFile= fopen( _fileName, "rb");
    if(pFile == nullptr) return cantidad;

    fseek(pFile, 0, SEEK_END);

    cantidad = ftell(pFile)/sizeof(Jugador);

    fclose(pFile);
    return cantidad;
}


int JugadoresDat::buscarXdni(int numDni)
{
    int numRegistro = -1;

    FILE* pFile= fopen( _fileName, "rb");
    if(pFile == nullptr) return numRegistro;

    Jugador jugador;

    while( fread(&jugador, sizeof(Jugador), 1, pFile) == 1 )
   {
       if(jugador.getDni()== numDni)
       {
           numRegistro = (ftell(pFile)/sizeof(Jugador));
       }
   }
    fclose(pFile);
    return numRegistro;
}

bool JugadoresDat::Modificar(Jugador jugador,int  pos)
{
    FILE* pFile= fopen( _fileName, "rb+");
    if(pFile == nullptr) return false;

    fseek(pFile, sizeof(Jugador)*pos, SEEK_SET);

    if (fwrite(&jugador, sizeof(Jugador), 1, pFile) == 1 )
    {
        std::cout<< "Se han guardado los cambios con exito..."<< std::endl;
        fclose(pFile);
        return true;
    }
    std::cout<< "Error, el registro NO pudo ser modificado..."<< std::endl;
    fclose(pFile);
    return false;
}

bool JugadoresDat::Crear()
{
    FILE* pFile = fopen( _fileName, "wb");
    if(pFile == nullptr) return false;

    fclose(pFile);
    return true;
}



//restauracion es al reves. Primero abro el bak para leer y despues abro el dat para escribir en wb y copio los registros.
