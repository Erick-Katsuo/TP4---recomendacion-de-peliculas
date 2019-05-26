#ifndef _PELICULA_H_
#define _PELICULA_H_

#include "Lista.h"

const string NOMBRE_NULO = "SIN NOMBRE";
const string GENERO_NULO = "SIN GENERO";
const int PUNTAJE_NULO = -10;
const string DIRECTOR_NULO = "SIN_DIRECTOR";

const int POSICION_DEFECTO_ACTOR = 1;

class Pelicula{

	private:
    /*ATRIBUTOS*/
		string nombre;
		string genero;
		int puntaje;
		string director;
		Lista<string> actores;

	public:
    /*CONSTRUCTOR*/

        /*Descripcion: Constructor de la clase Pelicula. Inicializa los atributos.
                       El objeto "actores" no es inicializado.
        *Pre: -.
        *Post: Inicializa los atributos..
        */
		Pelicula();
    public:
    /*METODOS ASIGNAR-OBTENER*/

        /*Descripcion: Asigna el valor para el atributo "nombre".
        *Pre: -.
        *Post: Asigna el valor para el atributo "nombre".
        */
		void asignar_nombre(string nuevo_nombre);

		/*Descripcion: Asigna el valor para el atributo "director".
        *Pre: -.
        *Post: Asigna el valor para el atributo "director".
        */
		void asignar_director(string nuevo_director);

		/*Descripcion: Asigna el valor para el atributo "genero".
        *Pre: -.
        *Post: Asigna el valor para el atributo "genero".
        */
		void asignar_genero(string nuevo_genero);

		/*Descripcion: Asigna el valor para el atributo "puntaje".
        *Pre: -.
        *Post: Asigna el valor para el atributo "puntaje".
        */
		void asignar_puntaje(int nuevo_puntaje);

        /*Descripcion: Devuelve el valor del atributo "nombre".
        *Pre: -.
        *Post: Devuelve el valor del atributo "nombre".
        */
		string obtener_nombre();

        /*Descripcion: Devuelve el valor del atributo "genero".
        *Pre: -.
        *Post: Devuelve el valor del atributo "genero".
        */
		string obtener_genero();

        /*Descripcion: Devuelve el valor del atributo "director".
        *Pre: -.
        *Post: Devuelve el valor del atributo "director".
        */
		string obtener_director();

        /*Descripcion: Devuelve el valor del atributo "puntaje".
        *Pre: -.
        *Post: Devuelve el valor del atributo "puntaje".
        */
		int obtener_puntaje();

    /*METODOS ESPECIFICOS PARA EL ATRIBUTO "actores"*/

        /*Descripcion: Verifica si la Lista de "actores" esta vacia.
        *Pre: -.
        *Post: Dependiendo de si la lista esta vacia devuelve True o False.
        */
		bool sin_actores();

        /*Descripcion: Agrega "nombre_actor" a la Lista de "actores".
        *Pre: -.
        *Post: Devuelve el atributo "opcion_actual".
        */
        void agregar_actores(string nombre_actor);

        /*Descripcion: Consulta la Lista "actores" en el Nodo requerido.
        *Pre: pos >0.
        *Post: Devuelve el contenido de la Lista de "actores" en el Nodo requerido.
        */
        string consultar_actores(int pos);

        /*Descripcion: Devuelve el tamaño de la Lista "actores".
        *Pre: -.
        *Post: Devuelve el tamaño de la Lista "actores".
        */
        int cant_actores();
};


#endif
