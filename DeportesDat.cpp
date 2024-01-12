#include "DeportesDat.h"


DeportesDat::DeportesDat(const char *name)
{
    strcpy(_fileName, name);
}

DeportesDat::~DeportesDat(){}

bool DeportesDat::agregar(Deporte deporte)
{
    FILE* pFile = fopen( _fileName, "ab");
    if(pFile == nullptr) return false;

    bool pudoAgregar= fwrite(&deporte, sizeof(Deporte), 1, pFile);

    fclose(pFile);
    return pudoAgregar;
}


Deporte DeportesDat::leer(int numRegistro)
{
    FILE* pFile= fopen( _fileName, "rb");
    if(pFile == nullptr) exit(-1);

    Deporte deporte;

    // fseek mueve el cursor a donde le indico.
    // recibe el stream, cuanto quiero moverme
    fseek(pFile,sizeof(Deporte)*numRegistro, SEEK_SET);

    fread(&deporte, sizeof(Deporte), 1, pFile);

    fclose(pFile);
    return deporte;
}

int DeportesDat::getCantRegistros()
{
    int cantidad= -1;

    FILE* pFile= fopen( _fileName, "rb");
    if(pFile == nullptr) return cantidad;

    fseek(pFile, 0, SEEK_END);

    cantidad = ftell(pFile)/sizeof(Deporte);

    fclose(pFile);
    return cantidad;
}


int DeportesDat::buscarXid(int numID)
{
    int numRegistro = -1;

    FILE* pFile= fopen( _fileName, "rb");
    if(pFile == nullptr) return numRegistro;

    Deporte deporte;

    while( fread(&deporte, sizeof(Deporte), 1, pFile) == 1 )
   {
       if(deporte.getIdDeporte()== numID )
       {
           numRegistro = (ftell(pFile)/sizeof(Deporte));
       }
   }
    fclose(pFile);
    return numRegistro;
}



bool DeportesDat::Modificar(Deporte deporte,int  pos)
{
    FILE* pFile= fopen( _fileName, "rb+");
    if(pFile == nullptr) return false;

    fseek(pFile, sizeof(Deporte)*pos, SEEK_SET);

    if (fwrite(&deporte, sizeof(Deporte), 1, pFile) == 1 )
    {
        std::cout<< "Se han guardado los cambios con exito..."<< std::endl;
        fclose(pFile);
        return true;
    }
    std::cout<< "Error, el registro NO pudo ser modificado..."<< std::endl;
    fclose(pFile);
    return false;
}

bool DeportesDat::Crear()
{
    FILE* pFile = fopen( _fileName, "wb");
    if(pFile == nullptr) return false;

    fclose(pFile);
    return true;;
}
