#ifndef MENUDEPORTES_H_INCLUDED
#define MENUDEPORTES_H_INCLUDED

#include "Fecha.h"
#include "DeportesDat.h"


bool AgregarDeporte();
void ListarXid();
void ListarTodos();
bool ModificarOrigen();
bool EliminarDeporte();

void menuDeportes()
{
    int opc;
    while(true)
    {
        std::cout<< "         MENU DEPORTES"<<std::endl;
        std::cout<< "--------------------------------"<<std::endl;
        std::cout<< "1  AGREGAR DEPORTE"<<std::endl;
        std::cout<< "2  LISTAR DEPORTE POR ID"<<std::endl;
        std::cout<< "3  LISTAR TODO"<<std::endl;
        std::cout<< "4  MODIFICAR  A"<<(char)165<<"O DE ORIGEN"<<std::endl;
        std::cout<< "5  ELIMINAR REGISTRO"<<std::endl;
        std::cout<< "--------------------------------"<<std::endl;
        std::cout<< "0  VOLVER AL MENU PRINCIPAL"<<std::endl;
        std::cout<<std::endl;
        std::cout<< "SELECCIONE UNA OPCION: "<<std::endl;
        std::cin>> opc;
        system("cls");

        switch(opc)
        {
            case 1:
                if(AgregarDeporte())
                 {
                     std::cout<<"Deporte agregado..." <<std::endl;
                     break;
                 }
                 std::cout<<"El deporte no pudo ser agregado al archivo..." <<std::endl;
                break;
            case 2: ListarXid();
                break;
            case 3: ListarTodos();
                break;
            case 4:
                if( ModificarOrigen() ) std::cout<<"El registro ha sido modificado con exito..."<<std::endl;
                else std::cout<<"No se pudo realizar la modificacion del registro..."<<std::endl;
                break;
            case 5:
                if( EliminarDeporte() )
                 {
                     std::cout<<"Registro de deporte eliminado..." <<std::endl;
                     break;
                 }
                 std::cout<<"El deporte no pudo ser eliminado del archivo..." <<std::endl;
                break;
            case 0: return;
                break;
            default:
                std::cout<<"Opcion incorrecta..."<<std::endl;
                break;
        }
        system("pause");
        system("cls");
    }
}

bool AgregarDeporte()
{
    DeportesDat file;
    Deporte reg;
    int id= file.getCantRegistros() +1;
    if( id == 0 ) id = 1;

    std::cout<<"ID: "<< id<< std::endl;
    if (reg.cargar(id) )
    {
        return file.agregar(reg);
    }
    return false;
}


void  ListarXid()
{
    DeportesDat file;
    Deporte reg;
    int id, pos;
    std::cout<<"INGRESE UN ID: ";
    std::cin>>id;
    pos = file.buscarXid(id);
    if (pos!= -1)
    {
        reg = file.leer(pos -1);
        if(reg.getEstado())
        {
            reg.mostrar();
        } else std::cout<<"El registro se encuentra dado de baja..."<<std::endl;
    }
    else std::cout<<"No se encuetra el ID en archivo..."<<std::endl;

}

void ListarTodos()
{
    DeportesDat file;
    Deporte reg;

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


bool ModificarOrigen()
{
    DeportesDat file;
    Deporte reg;
    int id, anio;
    std::cout<<"INGRESE UN ID: ";
    std::cin>>id;
    int pos = file.buscarXid(id);
    if (pos!= -1)
    {
        reg = file.leer(pos -1);
        if(reg.getEstado())
        {
            std::cout<<"INGRESE NUEVO A"<<(char)165<<"O DE ORIGEN: "<<std::endl;
            std::cin>>anio;
            if(reg.setOrigen(anio))
            {
                return file.Modificar(reg, pos-1);
            }
        }
    }
    else std::cout<<"No se encuetra el ID en archivo..."<<std::endl;
    return false;
}


bool EliminarDeporte()
{
    DeportesDat file;
    Deporte reg;
    int id, pos;
    std::cout<<"ID: "<< std::endl;
    std::cin>> id;
    pos = file.buscarXid(id);
    if(pos<0)
    {
        std::cout<<"Error, el id ingresado NO existe en el archivo..."<<std::endl;
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


#endif // MENUDEPORTES_H_INCLUDED
