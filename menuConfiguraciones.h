#ifndef MENUCONFIGURACIONES_H_INCLUDED
#define MENUCONFIGURACIONES_H_INCLUDED

#include "JugadoresDat.h"
#include "DeportesDat.h"

void CopiaJugadores();
void CopiaDeportes();
void RestaurarJugadores();
void RestaurarDeportes();
void EstablecerInicio();

void menuConfiguraciones()
{
    int opc;

    while(true)
    {
        system("cls");
        std::cout<< "        MENU CONFIGRACION"<<std::endl;
        std::cout<< "--------------------------------"<<std::endl;
        std::cout<< "1  COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES"<<std::endl;
        std::cout<< "2  COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES"<<std::endl;
        std::cout<< "3  RESTAURAR EL ARCHIVO DE JUGADORES"<<std::endl;
        std::cout<< "4  RESTAURAR EL ARCHIVO DE DEPORTES"<<std::endl;
        std::cout<< "5  ESTABLECER DATOS DE INICIO"<<std::endl;
        std::cout<< "--------------------------------"<<std::endl;
        std::cout<< "0  VOLVER AL MENU PRINCIPAL"<<std::endl;
        std::cout<<std::endl;
        std::cout<< " SELECCIONE UNA OPCION: "<<std::endl;
        std::cin>> opc;

        system("cls");
        switch(opc)
        {
            case 1: CopiaJugadores();
                break;
            case 2: CopiaDeportes();
                break;
            case 3: RestaurarJugadores();
                break;
            case 4: RestaurarDeportes();
                break;
            case 5: EstablecerInicio();
                break;
            case 0: return;
                break;
            default: std::cout<< "Opcion incorrecta..."<<std::endl;
                break;
        }
        system("pause");
        system("cls");
    }
}


void CopiaJugadores()
{
    JugadoresDat file, backup("jugadoresBak.bkp");
    Jugador reg;

    backup.Crear();

    for(int i=0; i<file.getCantRegistros() ; i++ )
    {
        reg= file.leer(i);
        if(reg.getEstado()) backup.agregar(reg);
    }
    std::cout << "La copia de seguridad se creo exitosamente" << std::endl;
}


void CopiaDeportes()
{
    DeportesDat file, backup("deportesBak.bkp");
    Deporte reg;

    backup.Crear();

    for(int i=0; i<file.getCantRegistros() ; i++ )
    {
        reg= file.leer(i);
        if(reg.getEstado()) backup.agregar(reg);
    }
    std::cout << "La copia de seguridad se creo exitosamente" << std::endl;
}

void RestaurarJugadores()
{
    JugadoresDat file, backup("jugadoresBak.bkp");
    Jugador reg;

    file.Crear();

    for(int i=0; i<backup.getCantRegistros() ; i++ )
    {
        reg= backup.leer(i);
        file.agregar(reg);
    }
    std::cout << "Los registros de jugadores se restauraron exitosamente" << std::endl;
}

void RestaurarDeportes()
{
    DeportesDat file, backup("deportesBak.bkp");
    Deporte reg;

    file.Crear();

    for(int i=0; i<backup.getCantRegistros(); i++)
    {
        reg= backup.leer(i);
        file.agregar(reg);
    }
    std::cout << "Los registros de deportes se restauraron exitosamente" << std::endl;
}



void EstablecerInicio()
{
    JugadoresDat jFile, jInicio("jugadoresInit.dat");
    Jugador jugador;

    jFile.Crear();
    for(int i=0; i<jInicio.getCantRegistros(); i++)
    {
        jugador= jInicio.leer(i);
        jFile.agregar(jugador);
    }

    DeportesDat dFile, dInicio("deportesInit.dat");
    Deporte deporte;

    dFile.Crear();
    for(int i=0; i<dInicio.getCantRegistros(); i++)
    {
        deporte= dInicio.leer(i);
        dFile.agregar(deporte);
    }
    std::cout << "Los datos de inicio se han establecido correctamente" << std::endl;

}

#endif // MENUCONFIGURACIONES_H_INCLUDED
