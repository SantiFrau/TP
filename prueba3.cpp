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
   string tipo;
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
     void set_tipo(string tipo_){
       tipo=tipo_;
    }



};
Persona::Persona()
{

}

Persona::~Persona()
{
}

void leer_personas(Persona p []){

ifstream archivo;
archivo.open("personas.txt");
if(archivo.fail()){
    exit(1);
}
int c=0;

string nacinalidad,fecha,visita,duracion,estado,tipo;
while (!archivo.eof())
{

getline(archivo,nacinalidad);    
p[c].set_nacionalidad(nacinalidad);


getline(archivo,fecha);    
p[c].set_fecha(fecha);

getline(archivo,visita);    
p[c].set_visita(visita);

getline(archivo,duracion);    
p[c].set_duracion_estancia(duracion);


getline(archivo,estado);    
p[c].set_estado_civil(estado);

getline(archivo,tipo);    
p[c].set_tipo(tipo);

c++;
}


}
void leer_info(Persona p []){

ifstream archivo;
archivo.open("info.txt");
if(archivo.fail()){
    exit(1);
}
int c=0;

string nacinalidad,fecha,visita,duracion,estado,tipo;
while (!archivo.eof())
{

getline(archivo,nacinalidad);    
p[c].set_nacionalidad(nacinalidad);


getline(archivo,fecha);    
p[c].set_fecha(fecha);

getline(archivo,visita);    
p[c].set_visita(visita);

getline(archivo,duracion);    
p[c].set_duracion_estancia(duracion);


getline(archivo,estado);    
p[c].set_estado_civil(estado);

getline(archivo,tipo);    
p[c].set_tipo(tipo);

c++;
}

}


int main(int argc, char const *argv[])
{
    
Persona persona1[3];
leer_personas(persona1);
Persona info[3];
leer_info(info);
int c=3;


persona1[0].mostrar_info_nivel_1();
cout<<endl;
info[0].mostrar_info_nivel_1();


for(int i=0;i<c;i++){

}
     



    return 0;
}
