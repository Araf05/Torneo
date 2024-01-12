#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

#include "JugadoresDat.h"
#include "DeportesDat.h"

void punto1();
void punto2();

void menuReportes()
{
    int opc;

    while(true)
    {
        system("cls");
        std::cout<< "        MENU REPORTES"<<std::endl;
        std::cout<< "--------------------------------"<<std::endl;
        std::cout<< "1  PUNTO 1"<<std::endl;
        std::cout<< "2  PUNTO 2"<<std::endl;
        std::cout<< "--------------------------------"<<std::endl;
        std::cout<< "0  VOLVER AL MENU PRINCIPAL"<<std::endl;
        std::cout<<std::endl;
        std::cout<< "SELECCIONE UNA OPCION: "<<std::endl;
        std::cin>> opc;
        system("cls");

        switch(opc)
        {
            case 1: punto1();
                break;
            case 2: punto2();
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

int contarJugadores(JugadoresDat pArchivo, int deporte )
{
    int cant = 0;
    Jugador reg;
    for(int i=0; i<pArchivo.getCantRegistros(); i++)
    {
        reg = pArchivo.leer(i);
        if(reg.getDeporte()==deporte) cant++;
    }
    return cant;
}

//Listar la cantidad de jugadores inscriptos en cada uno de los deportes

void punto1()
{
    Deporte deporte;
    JugadoresDat fileJ("jugadores.dat");
    DeportesDat fileD("deportes.dat");

    std::cout<<"A) Listar la cantidad de jugadores inscriptos en cada uno de los deportes"<<std::endl;
    for(int i=0 ; i<fileD.getCantRegistros() ; i++)
    {
        deporte = fileD.leer(i);
        std::cout<<deporte.getNombre()<<": "<< contarJugadores(fileJ, deporte.getIdDeporte())<<std::endl;
    }

}


class JugadorPunto2
{
    public:
        JugadorPunto2(int dni=0, const char* nombre="nadie", const char* apellido="nadie", Fecha fecha= Fecha(0,0,0));
        void setDni(int n){_DNI=n;}
        void setNombre(const char* nombre){strcpy(_nombre,nombre);}
        void setApellido(const char* apellido){strcpy(_apellido,apellido);}
        void setFecha(Fecha fecha){_fechaInsc=fecha;}
        void setEstado(bool e){_estado=e;}

        int getDni(){return _DNI;}
        const char* getNombre(){return _nombre;}
        const char* getApellido(){return _apellido;}
        Fecha getFechaInsc(){return _fechaInsc;}
        bool getEstado(){return _estado;}

        void mostrar()
        {
            if(_estado)
            {
                std::cout<<"DNI: ";
                std::cout<<_DNI<<std::endl;
                std::cout<<"NOMBRE: ";
                std::cout<<_nombre<<std::endl;
                std::cout<<"APELLIDO: ";
                std::cout<<_apellido<<std::endl;
                std::cout<<"FECHA DE INSCRIPCION: ";
                _fechaInsc.mostrar();
            }
        }

    private:
        int _DNI;
        char _nombre[30];
        char _apellido[30];
        Fecha _fechaInsc;
        bool _estado;
};

JugadorPunto2::JugadorPunto2(int dni, const char* nombre, const char* apellido, Fecha fecha)
    : _DNI(0), _nombre("nadie"), _apellido("nadie"), _fechaInsc(fecha)
{
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setFecha(fecha);
    _estado=true;
}

class ArchivoPunto2
{
    public:
        ArchivoPunto2(const char *name){ strcpy(_fileName, name);}

        bool Crear()
        {
            FILE* pFile = fopen( _fileName, "wb");
            if(pFile == nullptr) return false;

            fclose(pFile);
            return true;;
        }

        bool agregar(const  JugadorPunto2 noDocente)
        {
            FILE* pFile = fopen( _fileName, "ab");
            if(pFile == nullptr) return false;

            bool pudoAgregar= fwrite(&noDocente, sizeof( JugadorPunto2), 1, pFile);
            fclose(pFile);
            return pudoAgregar;
        }


        JugadorPunto2 leer(int numRegistro)
        {
            FILE* pFile= fopen( _fileName, "rb");
            if(pFile == nullptr) exit(-1);
            JugadorPunto2 noDocente;

            fseek(pFile,sizeof(JugadorPunto2)*numRegistro, SEEK_SET);

            fread(&noDocente, sizeof(JugadorPunto2), 1, pFile);

            fclose(pFile);
            return noDocente;
        }

        int getCantRegistros()
        {
            int cantidad= -1;

            FILE* pFile= fopen( _fileName, "rb");
            if(pFile == nullptr) return cantidad;

            fseek(pFile, 0, SEEK_END);

            cantidad = ftell(pFile)/sizeof(JugadorPunto2);

            fclose(pFile);
            return cantidad;
        }

    private:
        char _fileName[30];
};




//Generar un archivo con los no docentes que participan de deportes pertenecientes al tipo de deporte 5.
//Cada registro del archivo nuevo debe tener el siguiente formato:
//
// DNI, nombre, apellido y fecha de inscripción



void punto2()
{
    ArchivoPunto2 filePunto2("ArchivoPunto2.dat");
    JugadoresDat fileJugadores;
    Jugador jugador;
    JugadorPunto2 jPunto2;
    DeportesDat fileDeportes;
    Deporte deporte;

    filePunto2.Crear();
    int vDeportes[10]{}, pos=0;

    for(int i=0; i<fileDeportes.getCantRegistros(); i++)
    {
        deporte= fileDeportes.leer(i);
        if(deporte.getTipo()==1)
        {
            vDeportes[pos]=1;
        }
        pos++;
    }

    for(int i=0; i<fileJugadores.getCantRegistros() ; i++ )
    {
        jugador= fileJugadores.leer(i);
        if(jugador.getClaustro()==1)
            if(vDeportes[jugador.getDeporte()-1] == 1)
            {
                jPunto2.setDni(jugador.getDni());
                jPunto2.setNombre(jugador.getNombre());
                jPunto2.setApellido(jugador.getApellido());
                jPunto2.setFecha(jugador.getFechaInsc());
                jPunto2.setEstado(jugador.getEstado());
                filePunto2.agregar(jPunto2);
            }
    }

    std::cout << "2) Generar un archivo con los no docentes que participan de deportes pertenecientes al tipo de deporte 5(modificado para testear, muestra caustro 1 y dep tipo 1)." << std::endl;
    std::cout << "Cada registro del archivo nuevo debe tener el siguiente formato:" << std::endl;
    std::cout << "DNI, nombre, apellido y fecha de inscripcion" << std::endl;
    std::cout << "El archivo con los no docentes que participan de deportes pertenecientes al tipo de deporte 5 se genero exitosamente." << std::endl;
    std::cout<<std::endl;
    std::cout<<"Los No docentes que practican el deporte 5 son: "<<std::endl;
    if(filePunto2.getCantRegistros()==0) std::cout<<"No se encuentran jugadores que cumplan con las condiciones"<<std::endl;
    for(int i=0; i<filePunto2.getCantRegistros(); i++)
    {
        jPunto2= filePunto2.leer(i);
        if(jPunto2.getEstado())
        {
            jPunto2.mostrar();
            std::cout<<std::endl;
        }
    }
}




#endif // REPORTES_H_INCLUDED
