#include "Pelicula.h"

/*CONSTRUCTOR*/
Pelicula::Pelicula(){
    cout<<"Constructor Pelicula"<<endl;
    nombre = NOMBRE_NULO;
    genero = GENERO_NULO;
    puntaje = PUNTAJE_NULO;
    director = DIRECTOR_NULO;
}

/*METODOS ASIGNAR-OBTENER*/

string Pelicula::obtener_nombre(){
	return nombre;
}

string Pelicula::obtener_genero(){
	return genero;
}

string Pelicula::obtener_director(){
	return director;
}

int Pelicula::obtener_puntaje(){
	return puntaje;
}

void Pelicula::asignar_nombre(string nuevo_nombre){
	nombre = nuevo_nombre;
}

void Pelicula::asignar_genero(string nuevo_genero){
	genero = nuevo_genero;
}

void Pelicula::asignar_director(string nuevo_director){
	director = nuevo_director;
}

void Pelicula::asignar_puntaje(int nuevo_puntaje){
	puntaje = nuevo_puntaje;
}

/*METODOS ESPECIFICOS PARA EL ATRIBUTO "actores"*/

void Pelicula::agregar_actores(string nombre_actor){
    cout<<"agregar actores"<<endl;
    actores.agregar_nodo(nombre_actor,POSICION_DEFECTO_ACTOR);
    cout<< actores.consultar_lista(POSICION_DEFECTO_ACTOR)<<endl;
}

string Pelicula::consultar_actores(int pos){
    return actores.consultar_lista(pos);
}

int Pelicula::cant_actores(){
    return actores.obtener_tam_lista();
}

bool Pelicula::sin_actores(){
    cout<<"verif lista actores"<<endl;
    return actores.lista_vacia();
}
