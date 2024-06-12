#include<iostream>
#include<string>
#include<fstream>
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

    Persona();
    ~Persona();
    void mostrar_info_nivel_1(){
        std::cout<<"Nacionalidad: "<<nacinalidad<<endl;
        std::cout<<"Fecha nacimiento: "<<fecha_nacimiento<<endl;
        std::cout<<"Tipo visita: "<<tipo_visita<<endl;
        std::cout<<"Duracion estancia: "<<duracion_estancia<<endl;
        std::cout<<"Estado civil: "<<estado_civil<<endl;

    }

    void set_nacionalidad(string nacionalidad_){
        nacinalidad=nacionalidad_;
    }
     void set_fecha(string fecha_){
        fecha_nacimiento=fecha_;
    }
     void set_visita(string visita_){
        tipo_visita=visita_;
    }
     void set_duracion_estancia(string estancia_){
        duracion_estancia=estancia_;
    }
     void set_estado_civil(string estado_){
        estado_civil=estado_;
    }



};

Persona::Persona()
{

}

Persona::~Persona()
{
}
/*
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


*/
void leer_personas(Persona &p){

ifstream archivo;
archivo.open("personas.txt");
if(archivo.fail()){
    exit(1);
}

string nacinalidad,fecha,visita,duracion,estado;
while (!archivo.eof())
{

getline(archivo,nacinalidad);    
p.set_nacionalidad(nacinalidad);


getline(archivo,fecha);    
p.set_fecha(fecha);

getline(archivo,visita);    
p.set_visita(visita);

getline(archivo,duracion);    
p.set_duracion_estancia(duracion);


getline(archivo,estado);    
p.set_estado_civil(estado);


}


}



int main(int argc, char const *argv[])
{
    
Persona persona1;
leer_personas(persona1);
persona1.mostrar_info_nivel_1();



     



    return 0;
}


