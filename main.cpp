#include <iostream>

#include "menuJugadores.h"
#include "menuDeportes.h"
#include "reportes.h"
#include "menuConfiguraciones.h"

void menuPrincipal();


int main()
{
    menuPrincipal();
    return 0;
}


void menuPrincipal()
{
    int opc;

    while(true)
    {
        system("cls");
        std::cout<< "         MENU PRINCIPAL"<<std::endl;
        std::cout<< "--------------------------------"<<std::endl;
        std::cout<< "1  MENU JUGADORES"<<std::endl;
        std::cout<< "2  MENU DEPORTES"<<std::endl;
        std::cout<< "3  REPORTES"<<std::endl;
        std::cout<< "4  CONFIGURACION"<<std::endl;
        std::cout<< "--------------------------------"<<std::endl;
        std::cout<< "0  FIN DEL PROGRAMA"<<std::endl;
        std::cout<<std::endl;
        std::cout<< "SELECCIONE UNA OPCION: "<<std::endl;
        std::cin>> opc;
        system("cls");
        switch(opc)
        {
            case 1: menuJugadores();
                break;
            case 2: menuDeportes();
                break;
            case 3: menuReportes();
                break;
            case 4: menuConfiguraciones();
                break;
            case 0: return;
                break;
            default:
                std::cout<< "Opcion incorrecta..."<<std::endl;
                system("pause");
                break;
        }
    }
}


