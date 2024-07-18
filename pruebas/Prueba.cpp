#include<string>
#include<iostream>
#include <cstdlib> // Para la función rand()

using namespace std;


class Persona
{
public:
   

   string nacinalidad;
   string fecha_nacimiento;
   string tipo_visita;
   string duracion_estancia;
   string estado_civil;
   string pais_residencia;
   string propocito;
   string acompañante;

    Persona(string nacionalidad_ [],string tipo_visita_ [] 
    , string estado_civil_ [], string pais_residencia_[] , string propocito_[] , string acompañante_[]);
    ~Persona();
    void mostrar_info_nivel_1(){
        std::cout<<"Nacionalidad: "<<nacinalidad<<endl;
        std::cout<<"Fecha nacimiento: "<<fecha_nacimiento<<endl;
        std::cout<<"Tipo visita: "<<tipo_visita<<endl;
        std::cout<<"Duracion estancia "<<duracion_estancia<<endl;
        std::cout<<"Estado civil: "<<estado_civil<<endl;

    }
};

Persona::Persona(string nacionalidad_ [],string tipo_visita_ [] 
    , string estado_civil_ [], string pais_residencia_[] , string propocito_[] , string acompañante_[])
{
srand(time(nullptr)); // Se usa el tiempo actual como semilla
// Definir el rango para los números aleatorios
    int min = 0;
    int max = 3;
    // Generar un número aleatorio dentro del rango
    int random_nacionalidad = min + rand() % (max - min + 1);

nacinalidad=nacionalidad_[random_nacionalidad];

   
    srand(time(nullptr)); // Se usa el tiempo actual como semilla
// Definir el rango para los números aleatorios
     min = 0;
     max = 1;
    // Generar un número aleatorio dentro del rango
    int random_vis = min + rand() % (max - min + 1);

tipo_visita=tipo_visita_[random_vis];
  

    srand(time(nullptr)); // Se usa el tiempo actual como semilla
// Definir el rango para los números aleatorios
     min = 0;
     max = 1;
    // Generar un número aleatorio dentro del rango
    int random_estado = min + rand() % (max - min + 1);
    
estado_civil=estado_civil_[random_estado];

    srand(time(nullptr)); // Se usa el tiempo actual como semilla
// Definir el rango para los números aleatorios
     min = 0;
     max = 3;
    // Generar un número aleatorio dentro del rango
    int random_res = min + rand() % (max - min + 1);

pais_residencia=pais_residencia_[random_res];


srand(time(nullptr)); // Se usa el tiempo actual como semilla
// Definir el rango para los números aleatorios
     min = 0;
     max = 1;
    // Generar un número aleatorio dentro del rango
    int random_prop = min + rand() % (max - min + 1);

propocito=propocito_[random_prop];


srand(time(nullptr)); // Se usa el tiempo actual como semilla
// Definir el rango para los números aleatorios
     min = 0;
     max = 1;
    // Generar un número aleatorio dentro del rango
    int random_acompañante = min + rand() % (max - min + 1);

  acompañante=acompañante_[random_acompañante];


srand(time(nullptr)); // Se usa el tiempo actual como semilla
// Definir el rango para los números aleatorios
     min = 1980;
     max = 2024;
    // Generar un número aleatorio dentro del rango
    int random_anio = min + rand() % (max - min + 1);

srand(time(nullptr)); // Se usa el tiempo actual como semilla
// Definir el rango para los números aleatorios
     min = 1;
     max = 12;
    // Generar un número aleatorio dentro del rango
    int random_mes = min + rand() % (max - min + 1);

    srand(time(nullptr)); // Se usa el tiempo actual como semilla
// Definir el rango para los números aleatorios
     min = 1;
     max = 30;
    // Generar un número aleatorio dentro del rango
    int random_dia = min + rand() % (max - min + 1);
    
 fecha_nacimiento= to_string(random_dia)+"/"+ to_string(random_mes) +"/"+to_string(random_anio);


srand(time(nullptr)); // Se usa el tiempo actual como semilla
// Definir el rango para los números aleatorios
     min = 1;
     max = 365;
    // Generar un número aleatorio dentro del rango
    int random_duracion = min + rand() % (max - min + 1);
    
    duracion_estancia=to_string(random_duracion) + " dias ";
}

Persona::~Persona()
{
}

class Aldeano : public Persona
{

public:
  
  int correcta;
  int incorrecta;//puntos si acierta o no
   
  Aldeano(string nacionalidad_ [],string tipo_visita_ [] 
    , string estado_civil_ [], string pais_residencia_[] , string propocito_[] , string acompañante_[]) : Persona(nacionalidad_, tipo_visita_  
    , estado_civil_ ,  pais_residencia_ ,  propocito_ , acompañante_)
    {
        correcta=10;
        incorrecta=-15;
    }
   

};


class Politico : public Persona
{

public:
  
  int correcta;
  int incorrecta;//puntos si acierta o no
  bool multa;   
  Politico(string nacionalidad_ [],string tipo_visita_ [] 
    , string estado_civil_ [], string pais_residencia_[] , string propocito_[] , string acompañante_[]) : Persona(nacionalidad_, tipo_visita_  
    , estado_civil_ ,  pais_residencia_ ,  propocito_ , acompañante_){
        correcta=15;
        incorrecta=-20;
    
    }
   

};


class Diplomatico : public Persona
{

public:
  
  int correcta;
  int incorrecta;//puntos si acierta o no
  bool multa;   
  Diplomatico(string nacionalidad_ , string fecha_nacimiento_ ,string tipo_visita_ ,string duracion_estancia_ 
    , string estado_civil_ , string pais_residencia_ , string propocito_ , string acompañante_) : Persona(nacionalidad_ , fecha_nacimiento_ , tipo_visita_ , duracion_estancia_ 
    ,estado_civil_ ,pais_residencia_ ,propocito_ ,acompañante_){
        correcta=25;
        incorrecta=-25;
        multa=true;
    }
   

};


class Revolucionario : public Persona
{

public:
  
  int correcta;
  int incorrecta;//puntos si acierta o no
  bool multa;   
  Revolucionario(string nacionalidad_ , string fecha_nacimiento_ ,string tipo_visita_ ,string duracion_estancia_ 
    , string estado_civil_ , string pais_residencia_ , string propocito_ , string acompañante_) : Persona(nacionalidad_ , fecha_nacimiento_ , tipo_visita_ , duracion_estancia_ 
    ,estado_civil_ ,pais_residencia_ ,propocito_ ,acompañante_){
        correcta=0;
        incorrecta=-25;
        multa=true;
    }
   

};



int main(int argc, char const *argv[])
{
    
    string nacionalidad[]={"Arg","Par","Cl","Ur"};
    string tipo_visita[]={"Trabajo","turista"};
    string estado_civil[]={"Casado","Soltero"};
    string pais_residencia[]={"Arg","Par","Cl","Ur"};
    string propositos[]={"Trabajo","turista"};
    string acompañantes[]={"familiar","amigos"};

   
    Aldeano aldeano1(nacionalidad,tipo_visita,estado_civil,pais_residencia,propositos,acompañantes);
    aldeano1.mostrar_info_nivel_1();
     



    return 0;
}


