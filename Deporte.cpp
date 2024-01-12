#include "Deporte.h"

Deporte::Deporte()
{
    _estado=true;
}

Deporte::~Deporte(){}

void Deporte::setIdDeporte(int n)
{
    _idDeporte = n;
}

bool Deporte::setTipo(int n)
{
    if(n>0 && n<22)
    {
        _tipo = n;
        return 1;
    }
    std::cout<<"Error, el tipo de deporte ingresado NO es valido..."<<std::endl;
    return 0;
}

bool Deporte::setOrigen(int n)
{
    Fecha fecha;
    if(n>=1800 && n<= fecha.getYear())
    {
        _origen = n;
        return 1;
    }
    std::cout<<"Error, el a"<<(char)164<<"o ingresado NO es valido..."<<std::endl;
    return 0;
}

void Deporte::setNombre(const char *name)
{
    strcpy(_nombre, name);
}

void Deporte::setEstado(bool e)
{
    _estado = e;
}


int Deporte::getIdDeporte() { return _idDeporte;}

int Deporte::getTipo() {return _tipo;}

int Deporte::getOrigen() { return _origen;}

const char *Deporte::getNombre() {return _nombre;}

bool Deporte::getEstado() { return _estado;}


bool Deporte::cargar(int id)
{
    int tipo=0, origen=0;
    char nom[30]{};

    setIdDeporte(id);
    std::cout<<"NOMBRE: ";
    cargarCadena(nom, 30);
    setNombre(nom);
    std::cout<<"TIPO DE DEPORTE: ";
    std::cin>>tipo;
    if( setTipo(tipo) )
    {
        std::cout<<"A"<<(char)165<<"O DE ORIGEN: ";
        std::cin>>origen;
        if( setOrigen(origen) )
        {
            _estado=true;
            return 1;
        }
    }
    return 0;
}

void Deporte::mostrar()
{
    if(_estado)
    {
        std::cout<<"ID: ";
        std::cout<<_idDeporte<<std::endl;
        std::cout<<"NOMBRE: ";
        std::cout<<_nombre<<std::endl;
        std::cout<<"TIPO DE DEPORTE: ";
        std::cout<<_tipo<<std::endl;
        std::cout<<"A"<<(char)165<<"O DE ORIGEN: ";
        std::cout<<_origen<<std::endl;
    }
}
