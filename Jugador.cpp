#include "Jugador.h"


Jugador::Jugador()
{
    _estado=true;
}

Jugador::Jugador(int dni, const char* n, const char* a, const char* e, const char* t, int c, int d, int ne, Fecha fi, float m)
    : _dni(0), _claustro(0), _deporte(0), _numEquipo(0), _matricula(0), _nombre("-"), _apellido("-"), _email("-"), _telefono("-"), _fechaInscripcion(fi)
{
    setDni(dni);
    setNombre(n);
    setApellido(a);
    setEmail(e);
    setTelefono(t);
    setClaustro(c);
    setDeporte(d);
    setNumEquipo(ne);
    setInscripcion(fi);
    setMatricula(m);
    _estado=true;
}

Jugador::~Jugador(){}

bool Jugador::setDni(int n)
{
    if(n>0)
    {
        _dni=n;
        return true;
    }
    std::cout<<"Error, el numero de DNI ingresado NO es valido..."<<std::endl;
    return false;

}

bool Jugador::setClaustro(int n)
{
    if(n>0 && n<5)
    {
        _claustro=n;
        return true;
    }
    std::cout<<"Error, el numero de claustro ingresado NO es valido..."<<std::endl;
    return false;
}

bool Jugador::setDeporte(int n)
{
    if(n>0 && n<11)
    {
        _deporte=n;
        return true;
    }
    std::cout<<"Error, el deporte ingresado NO es valido..."<<std::endl;
    return false;
}

bool Jugador::setNumEquipo(int n)
{
    if(n>=0)
    {
        _numEquipo=n;
        return true;
    }
    std::cout<<"Error, el numero de equipo ingresado NO es valido..."<<std::endl;
    return false;
}

bool Jugador::setMatricula(float n)
{
    if(n>=0)
    {
        _matricula=n;
        return true;
    }
    std::cout<<"Error, el valor de matricula ingresado NO es valido..."<<std::endl;
    return false;
}

void Jugador::setNombre(const char* s) {strcpy(_nombre, s);}

void Jugador::setApellido(const char* s) {strcpy(_apellido, s);}

void Jugador::setEmail(const char* s) {strcpy(_email, s);}

void Jugador::setTelefono(const char* s) {strcpy(_telefono, s);}


bool validarInscripcion(Fecha insc)
{
    Fecha hoy;
    long int a= insc.getYear()*10000 + insc.getMonth()*100 + insc.getDay();
    long int b= hoy.getYear()*10000 + hoy.getMonth()*100 + hoy.getDay();

    if(a<= b) return true;

    std::cout<<"Error, la fecha de inscripcion ingresada supera la fecha actual..."<<std::endl;
    return false;
}

bool Jugador::setInscripcion(Fecha insc)
{
    if( validarInscripcion(insc) )
    {
        _fechaInscripcion = insc;
        return true;
    }
     std::cout<<"Error, La fecha ingresada NO es valida..."<<std::endl;
    return false;
}


void Jugador::setEstado(bool e) {_estado=e;}


int Jugador::getDni() {return _dni;}

int Jugador::getClaustro() {return _claustro;}

int Jugador::getDeporte() {return _deporte;}

int Jugador::getNumEquipo() {return _numEquipo;}

float Jugador::getMatricula() {return _matricula;}

const char* Jugador::getNombre() {return _nombre;}

const char* Jugador::getApellido() {return _apellido;}

const char* Jugador::getEmail() {return _email;}

const char* Jugador::getTelefono() {return _telefono;}

Fecha Jugador::getFechaInsc() {return _fechaInscripcion;}

bool Jugador::getEstado() {return _estado;}


bool Jugador::cargar( int dni)
{
    int claus=0, dep=0, numE=0;
    char nom[30]{}, ape[30]{}, email[30]{}, tel[30]{};
    Fecha fechaI;
    float mat=0;

    if( setDni(dni) )
    {
         std::cout<<"NOMBRE: ";
         cargarCadena(nom, 30);
         setNombre(nom);
         std::cout<<"APELLIDO: ";
         cargarCadena(ape, 30);
         setApellido(ape);
         std::cout<<"EMAIL: ";
         cargarCadena(email, 30);
         setEmail(email);
         std::cout<<"TELEFONO: ";
         cargarCadena(tel, 30);
         setTelefono(tel);
         std::cout<<"CLAUSTRO: ";
         std::cin>>claus;
         if( setClaustro(claus) )
         {
             std::cout<<"DEPORTE: ";
             std::cin>>dep;
             if( setDeporte(dep) && validarId(dep) )
             {
                 std::cout<<"NUMERO DE EQUIPO: ";
                 std::cin>>numE;
                 setNumEquipo(numE);
                 std::cout<<"FECHA DE INSCRIPCION: "<<std::endl;
                 if( fechaI.cargar() && setInscripcion(fechaI) )
                 {
                     std::cout<<"MATRICULA: ";
                     std::cin>>mat;
                     if( setMatricula(mat) )
                     {
                        _estado=true;
                        return true;
                     }
                 }
             }
         }
    }

    return false;
}


void Jugador::mostrar()
{
    if(_estado)
    {
        std::cout<<"DNI: ";
        std::cout<<_dni<<std::endl;
        std::cout<<"NOMBRE: ";
        std::cout<<_nombre<<std::endl;
        std::cout<<"APELLIDO: ";
        std::cout<<_apellido<<std::endl;
        std::cout<<"EMAIL: ";
        std::cout<<_email<<std::endl;
        std::cout<<"TELEFONO: ";
        std::cout<<_telefono<<std::endl;
        std::cout<<"CLAUSTRO: ";
        std::cout<<_claustro<<std::endl;
        std::cout<<"DEPORTE: ";
        std::cout<<_deporte<<std::endl;
        std::cout<<"NUMERO DE EQUIPO: ";
        std::cout<<_numEquipo<<std::endl;
        std::cout<<"FECHA DE INSCRIPCION: ";
        _fechaInscripcion.mostrar();
        std::cout<<"MATRICULA: ";
        std::cout<<_matricula<<std::endl;
    }
}

void cargarCadena(char *palabra, int tamano){
    int i=0;
    fflush(stdin);
    for(i=0; i<tamano; i++)
    {
        palabra[i]=std::cin.get();
        if(palabra[i]=='\n') {break;}
    }
    palabra[i]='\0';
    fflush(stdin);
}


