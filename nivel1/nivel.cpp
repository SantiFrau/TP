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
    string tipo;

    Persona() {}
    virtual ~Persona() {}

    void mostrar_info_nivel_1() const {
        cout << "Nacionalidad: " << nacionalidad << endl;
        cout << "Fecha nacimiento: " << fecha_nacimiento << endl;
        cout << "Tipo visita: " << tipo_visita << endl;
        cout << "Duracion estancia: " << duracion_estancia << endl;
        cout << "Estado civil: " << estado_civil << endl;
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

void leer_personas(Persona* personas[], const string& archivo_personas);
void validar_entrada(char decision, Persona* p, Persona* info, int& puntos, int& multas);
bool validar_info(const Persona* p, const Persona* info);

int main(int argc, char const* argv[]) {
    int puntos = 0;
    int multas = 0;

    Persona* personas[3];
    leer_personas(personas, "personas.txt");

    Persona* info[3];
    leer_personas(info, "info.txt");

    int c = 3;

    for (int i = 0; i < c; ++i) {
        personas[i]->mostrar_info_nivel_1();
        cout << endl;
        info[i]->mostrar_info_nivel_1();

        char decision;
        cout << "Dejar pasar : SI(S) / NO(N)" << endl;
        cin >> decision;
        validar_entrada(decision, personas[i], info[i], puntos, multas);

        cout << "------------" << endl;

        if (multas > 4 || puntos < 0) {
            exit(1);
        }
    }

    cout << "Puntos : " << puntos << endl;
    cout << "Multas : " << multas << endl;
    system("pause");

    return 0;
}

void leer_personas(Persona* personas[], const string& archivo_personas) {
    ifstream archivo(archivo_personas);
    if (archivo.fail()) {
        exit(1);
    }

    int c = 0;
    string nacionalidad, fecha, visita, duracion, estado, tipo;

    while (!archivo.eof()) {
        getline(archivo, nacionalidad);
        getline(archivo, fecha);
        getline(archivo, visita);
        getline(archivo, duracion);
        getline(archivo, estado);
        getline(archivo, tipo);

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

        c++;
    }
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
           p->tipo == info->tipo;
}