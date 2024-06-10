#include<string>
#include<iostream>
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

    Persona(string nacionalidad_ , string fecha_nacimiento_ ,string tipo_visita_ ,string duracion_estancia_ 
    , string estado_civil_ , string pais_residencia_ , string propocito_ , string acompañante_);
    ~Persona();
    void mostrar_info_nivel_1(){
        std::cout<<"Nacionalidad: "<<nacinalidad<<endl;
        std::cout<<"Fecha nacimiento: "<<fecha_nacimiento<<endl;
        std::cout<<"Tipo visita: "<<tipo_visita<<endl;
        std::cout<<"Duracion estancia "<<duracion_estancia<<endl;
        std::cout<<"Estado civil: "<<estado_civil<<endl;

    }
};

Persona::Persona(string nacionalidad_ , string fecha_nacimiento_ ,string tipo_visita_ ,string duracion_estancia_ 
    , string estado_civil_ , string pais_residencia_ , string propocito_ , string acompañante_)
{
nacinalidad=nacionalidad_;
fecha_nacimiento=fecha_nacimiento_;
tipo_visita=tipo_visita_;
duracion_estancia=duracion_estancia_;
estado_civil=estado_civil_;
pais_residencia=pais_residencia_;
propocito=propocito_;
acompañante=acompañante_;


}

Persona::~Persona()
{
}

class Aldeano : public Persona
{

public:
  
  int correcta;
  int incorrecta;//puntos si acierta o no
   
  Aldeano(string nacionalidad_ , string fecha_nacimiento_ ,string tipo_visita_ ,string duracion_estancia_ 
    , string estado_civil_ , string pais_residencia_ , string propocito_ , string acompañante_) : Persona(nacionalidad_ , fecha_nacimiento_ , tipo_visita_ , duracion_estancia_ 
    ,estado_civil_ ,pais_residencia_ ,propocito_ ,acompañante_){
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
  Politico(string nacionalidad_ , string fecha_nacimiento_ ,string tipo_visita_ ,string duracion_estancia_ 
    , string estado_civil_ , string pais_residencia_ , string propocito_ , string acompañante_) : Persona(nacionalidad_ , fecha_nacimiento_ , tipo_visita_ , duracion_estancia_ 
    ,estado_civil_ ,pais_residencia_ ,propocito_ ,acompañante_){
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
    
     Aldeano aldeano1("Argentino","02/08/2000","Trabajo","15 dias","Casado","Brasil","Trabajo","1 familiar");
     aldeano1.mostrar_info_nivel_1();
     



    return 0;
}


