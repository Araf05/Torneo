#ifndef MENUJUGADORES_H_INCLUDED
#define MENUJUGADORES_H_INCLUDED

#include "Fecha.h"
#include "JugadoresDat.h"
#include "DeportesDat.h"

bool agregarJugador();
void ListarXdni();
void ListarJugadores();
bool ModificarFecha();
bool EliminarJugador();

void menuJugadores()
{
    int opc;

    while(true)
    {
        std::cout<< "          MENU JUGADORES"<<std::endl;
        std::cout<< "--------------------------------"<<std::endl;
        std::cout<< "1  AGREGAR JUGADORES"<<std::endl;
        std::cout<< "2  LISTAR JUGADORES POR DNI"<<std::endl;
        std::cout<< "3  LISTAR TODOS LOS JUGADORES"<<std::endl;
        std::cout<< "4  MODIFICAR FECHA DE INSCRIPCION"<<std::endl;
        std::cout<< "5  ELIMINAR REGISTRO DE JUGADOR"<<std::endl;
        std::cout<< "--------------------------------"<<std::endl;
        std::cout<< "0  VOLVER AL MENU PRINCIPAL"<<std::endl;
        std::cout<<std::endl;
        std::cout<< "SELECCIONE UNA OPCION: "<<std::endl;
        std::cin>> opc;
        system("cls");

        switch(opc)
        {
            case 1:
                if( agregarJugador() ) std::cout<<"El jugador ha sido registrado con exito..."<<std::endl;
                else std::cout<<"El registro NO ha sido guardado..."<<std::endl;
                break;
            case 2: ListarXdni();
                break;
            case 3: ListarJugadores();
                break;
            case 4:
                if( ModificarFecha() ) std::cout<<"El registro ha sido modificado con exito..."<<std::endl;
                else std::cout<<"No se pudo realizar la modificacion del registro..."<<std::endl;
                break;
            case 5:
                if( EliminarJugador() ) std::cout<<"El jugador ha sido dado de baja con exito..."<<std::endl;
                else std::cout<<"No se pudo realizar la baja del registro..."<<std::endl;
                break;
            case 0: return;
                break;
            default: std::cout<<"Opcion incorrecta..."<<std::endl;
                break;
        }
        system("pause");
        system("cls");
    }
}

bool validarId(int id)
{
    DeportesDat file;
    if(file.buscarXid(id) != -1 )
    {
        return true;
    }
    else
    {
        std::cout<<"Error, el deporte ingresado NO se encuentra en archivo..."<<std::endl;
        return false;
    }
}



bool agregarJugador()
{
    Jugador reg;
    JugadoresDat file;
    int dni=0;

    std::cout<<"DNI: ";
    std::cin>> dni;
    if(file.buscarXdni(dni)< 0)
    {
        if(reg.cargar(dni) )
        {

            return file.agregar(reg);
        }
    } else std::cout<<"Error, el dni ingresado ya existe..."<<std::endl;

    return false;
}


void  ListarXdni()
{
    JugadoresDat file;
    Jugador reg;
    int dni, pos;
    std::cout<<"INGRESE UN DNI: ";
    std::cin>>dni;
    pos = file.buscarXdni(dni);
    if (pos>=0)
    {
        reg = file.leer(pos-1);
        if(reg.getEstado())
        {
            reg.mostrar();
        } else std::cout<<"El registro se encuentra dado de baja..."<<std::endl;
    }
    else std::cout<<"No se encuetra el DNI en archivo..."<<std::endl;
}

void ListarJugadores()
{
    JugadoresDat file;
    Jugador reg;

    for(int i=0; i<file.getCantRegistros(); i++)
    {
        reg = file.leer(i);
        if(reg.getEstado())
        {
            reg.mostrar();
            std::cout<<std::endl;
        }
    }
}

bool ModificarFecha()
{
    JugadoresDat file;
    Jugador reg;
    int dni;
    Fecha f;
    std::cout<<"INGRESE UN DNI: ";
    std::cin>>dni;
    int pos = file.buscarXdni(dni);
    if (pos!= -1)
    {
        reg = file.leer(pos -1);
        if( reg.getEstado())
        {
            std::cout<<"INGRESE NUEVA FECHA DE INSCRIPCION: "<<std::endl;
            if( f.cargar() )
            {
                if(reg.setInscripcion(f) )
                {
                    return file.Modificar(reg, pos-1);
                }

            }
        } else std::cout<<"El registro se encuentra dado de baja..."<<std::endl;
    }
    else std::cout<<"No se encuetra el DNI en archivo..."<<std::endl;
    return false;
}

bool EliminarJugador()
{
    JugadoresDat file;
    Jugador reg;
    int dni, pos;
    std::cout<<"DNI: ";
    std::cin>> dni;
    pos = file.buscarXdni(dni);
    if(pos<0)
    {
        std::cout<<"Error, el dni ingresado NO existe en el archivo..."<<std::endl;
        return false;
    }
    reg = file.leer(pos-1);
    if(reg.getEstado()==false)
    {
        std::cout<<"Error, el registro existe pero ya esta dado de baja..."<<std::endl;
        return false;
    }
    reg.setEstado(0);

    return file.Modificar(reg, pos-1);
}


#endif // MENUJUGADORES_H_INCLUDED
