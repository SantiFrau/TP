#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Persona {
public:
    string nacionalidad;
    string fecha_nacimiento;
    string tipo_visita;
    string duracion_estancia;
    string estado_civil;
    string pais_r;
    string proposito;
    string tipo;
    string acompaniantes;

    Persona() {}
    virtual ~Persona() {}

    void mostrar_info_nivel_3() const {
        cout << "Nacionalidad: " << nacionalidad << endl;
        cout << "Fecha nacimiento: " << fecha_nacimiento << endl;
        cout << "Tipo visita: " << tipo_visita << endl;
        cout << "Duracion estancia: " << duracion_estancia << endl;
        cout << "Estado civil: " << estado_civil << endl;
        cout<<"Pais de residencia: "<<pais_r<<endl;
        cout<<"Proposito del viaje: "<<proposito<<endl;
        cout<<"Acompañantes: "<<acompaniantes<<endl;
    }

    void set_nacionalidad(const string& nacionalidad_) {
        nacionalidad = nacionalidad_;
    }
    void set_fecha(const string& fecha_) {
        fecha_nacimiento = fecha_;
    }
    void set_visita(const string& visita_) {
        tipo_visita = visita_;
    }
    void set_duracion_estancia(const string& estancia_) {
        duracion_estancia = estancia_;
    }
    void set_estado_civil(const string& estado_) {
        estado_civil = estado_;
    }
    void set_tipo(const string& tipo_) {
        tipo = tipo_;
    }
    void set_pais_r(const string& pais_) {
        pais_r = pais_;
    }
    void set_proposito(const string& proposito_) {
        proposito = proposito_;
    }
     void set_acompaniante(const string& acompaniante_) {
        acompaniantes = acompaniante_;
    }


    virtual int get_puntos_validacion(bool es_valido, bool dejar_pasar) const = 0;
};

class Aldeano : public Persona {
public:
    int get_puntos_validacion(bool es_valido, bool dejar_pasar) const override {
        if (dejar_pasar) {
            return es_valido ? 10 : -15;
        } else {
            return es_valido ? -10 : 10;
        }
    }
};

class Politico : public Persona {
public:
    int get_puntos_validacion(bool es_valido, bool dejar_pasar) const override {
        if (dejar_pasar) {
            return es_valido ? 15 : -25;
        } else {
            return es_valido ? -15 : 25;
        }
    }
};

class Diplomatico : public Persona {
public:
    int get_puntos_validacion(bool es_valido, bool dejar_pasar) const override {
        if (dejar_pasar) {
            return es_valido ? 25 : -25;
        } else {
            return es_valido ? -25 : 25;
        }
    }
};

class Revolucionario : public Persona {
public:
    int get_puntos_validacion(bool es_valido, bool dejar_pasar) const override {
        return dejar_pasar ? -25 : 0;
    }
};

int leer_personas(Persona* personas[], const string& archivo_personas);
void validar_entrada(char decision, Persona* p, Persona* info, int& puntos, int& multas);
bool validar_info(const Persona* p, const Persona* info);
void guardar_persona(Persona *p[], Persona *info[], int multas , int puntos , int c);
void leer_puntos(int &puntos ,int  &multas);

int main(int argc, char const* argv[]) {
    int puntos=0;
    int multas=0 ;
    leer_puntos(puntos,multas);
    cout<<puntos<<" "<<multas<<endl;
     int c ;
    Persona* personas[3];
    c=leer_personas(personas, "../personas.txt");

    Persona* info[3];
    c=leer_personas(info, "../info.txt");
    cout<<c<<endl;

    Persona *p[3] ;
    Persona *inf[3] ;
    int c1 =0;
   

    for (int i = 0; i < c; ++i) {
        personas[i]->mostrar_info_nivel_3();
        cout << endl;
        info[i]->mostrar_info_nivel_3();

        char decision;
        cout << "Dejar pasar : SI(S) / NO(N)" << endl;
        cin >> decision;
        validar_entrada(decision, personas[i], info[i], puntos, multas);
        if(decision == 'S'){
            p[c1] = personas[i];
            inf[c1]=personas[i];
            c1++;
        }

        cout << "------------" << endl;
   
        if (multas > 4 || puntos < 0) {
            exit(1);
        }
    }

    guardar_persona(p, inf, multas, puntos ,c1);

    cout << "Puntos : " << puntos << endl;
    cout << "Multas : " << multas << endl;
    system("pause");

    return 0;
}

void leer_puntos(int &puntos ,int  &multas){
    ifstream archivo;
    archivo.open("../puntuacion.txt");
    int m ,p;
    archivo>>m;
    archivo>>p;
    puntos=p;
    multas=m;
    archivo.close();
}

void guardar_persona(Persona *p[], Persona *info[], int multas , int puntos , int c){
 
 ofstream archivo;
 ofstream archivo1;
 ofstream archivo2;
 archivo.open("../personas.txt");
 archivo1.open("../puntuacion.txt");
 archivo2.open("../info.txt" );

 if(archivo.fail() && archivo1.fail() && archivo2.fail()){
    exit(1);
    
 }

for(int i=0;i<c;i++){
archivo<<p[i]->nacionalidad<<endl;
 archivo<<p[i]->fecha_nacimiento<<endl;
 archivo<<p[i]->tipo_visita<<endl;
 archivo<<p[i]->duracion_estancia<<endl;
 archivo<<p[i]->estado_civil<<endl;
 archivo<<p[i]->tipo<<endl;
 archivo<<p[i]->proposito<<endl;
 archivo<<p[i]->pais_r<<endl;
 archivo<<p[i]->acompaniantes<<endl;
 

 archivo2<<info[i]->nacionalidad<<endl;
 archivo2<<info[i]->fecha_nacimiento<<endl;
 archivo2<<info[i]->tipo_visita<<endl;
 archivo2<<info[i]->duracion_estancia<<endl;
 archivo2<<info[i]->estado_civil<<endl;
 archivo2<<info[i]->tipo<<endl;
 archivo2<<info[i]->proposito<<endl;
 archivo2<<info[i]->pais_r<<endl;
 archivo2<<info[i]->acompaniantes<<endl;
 
 archivo1<<multas<<endl;
 archivo1<<puntos<<endl;
}
 
}
int leer_personas(Persona* personas[], const string& archivo_personas) {
    ifstream archivo(archivo_personas);
    
    if (archivo.fail()) {
        exit(1);
    }

    int c = 0;
    string nacionalidad, fecha, visita, duracion, estado, tipo ,proposito ,pais,acompaniates;

    while (!archivo.eof()) {
        getline(archivo, nacionalidad);
        getline(archivo, fecha);
        getline(archivo, visita);
        getline(archivo, duracion);
        getline(archivo, estado);
        getline(archivo, tipo);
        getline(archivo, proposito);
        getline(archivo, pais);
        getline(archivo, acompaniates);

        if (tipo == "aldeano") {
            personas[c] = new Aldeano();
        } else if (tipo == "politico") {
            personas[c] = new Politico();
        } else if (tipo == "diplomatico") {
            personas[c] = new Diplomatico();
        } else if (tipo == "revolucionario") {
            personas[c] = new Revolucionario();
        }

        personas[c]->set_nacionalidad(nacionalidad);
        personas[c]->set_fecha(fecha);
        personas[c]->set_visita(visita);
        personas[c]->set_duracion_estancia(duracion);
        personas[c]->set_estado_civil(estado);
        personas[c]->set_tipo(tipo);
         personas[c]->set_proposito(proposito);
          personas[c]->set_pais_r(pais);
          personas[c]->set_acompaniante(acompaniates);

        c++;
    }
    
    if( c==1){
     return c;
    }
    return c-1;
}

void validar_entrada(char decision, Persona* p, Persona* info, int& puntos, int& multas) {
    bool es_valido = validar_info(p, info);
    bool dejar_pasar = (decision == 'S');
    puntos += p->get_puntos_validacion(es_valido, dejar_pasar);

    if (p->tipo == "diplomatico" && !es_valido && dejar_pasar) {
        multas++;
    } else if (p->tipo == "revolucionario" && dejar_pasar) {
        multas++;
    }
}

bool validar_info(const Persona* p, const Persona* info) {
    return p->duracion_estancia == info->duracion_estancia &&
           p->estado_civil == info->estado_civil &&
           p->fecha_nacimiento == info->fecha_nacimiento &&
           p->nacionalidad == info->nacionalidad &&
           p->tipo_visita == info->tipo_visita &&
           p->tipo == info->tipo &&
           p->proposito == info->proposito &&
           p->pais_r == info->pais_r &&
           p->acompaniantes == info->acompaniantes;

}