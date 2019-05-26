#ifndef _MENU_H_
#define _MENU_H_

#include <fstream>

#include "Pelicula.h"
#include "Lista.h"

const char OPCION_NULA = 'n';
const char OPCION_SALIR = 'x';
const char OPCION_MENU = 'm';
const char OPCION_MOSTRAR_VISTAS = 'v';
const char OPCION_MOSTRAR_NO_VISTAS = 'n';
const char OPCION_RECOMENDACION = 'r';
const char OPCION_VER_RECOMENDACION = 'e';

const int REVISAR_PUNTAJE = 1;
const int REVISAR_DIRECTOR = 2;
const int REVISAR_ACTORES = 3;

const bool NO_VERIFICADO = false;
const bool VERIFICADO  = true;
const bool RECOMEND_NO_CREADA = false;
const bool RECOMEND_CREADA = true;

const int LEER_VISTAS = -1;
const int LEER_NO_VISTAS = -2;
const int RECOMENDACION = -3;

const int VER_VISTAS = -4;
const int VER_NO_VISTAS = -5;
const int VER_RECOMENDACION = -6;

const int MAX_NOMBRE = 27;
const char PELIS_VISTAS[MAX_NOMBRE] = "peliculas_vistas.txt";
const char PELIS_NO_VISTAS[MAX_NOMBRE] = "peliculas_no_vistas.txt";

const int PRIMER_LINEA = 1;
const int SEGUNDA_LINEA = 2;
const int LINEA_PUNTAJE = 3;
const int CUARTA_LINEA = 4;
const int REINICIAR_LINEA = 0;
const int LINEA_ACTORES = 5;

const int POSICION_DEFECTO = 1;
const int PUNTAJE_INICIAL = -1;

const char SALTO_LINEA = '\n';

class Menu{
    private:
    /*ATRIBUTOS*/
        char opcion_actual;
        Lista<Pelicula*> vistas;
        Lista<Pelicula*> no_vistas;
        Lista<Pelicula*> recomendadas;
        bool recomend_creada;
    public:
    /*CONSTRUCTOR*/

        /*Descripcion: Constructor de la clase Menu. Inicializa los atributos correspondientes.
         *Pre: -.
         *Post: Crea el objeto con el atributo "opcion_actual" asignandole el valor de OPCION_NULA.
        */
        Menu();
    private:
    /*METODOS ASIGNAR-OBTENER*/

        /*Descripcion: Asigna un valor al atributo "opcion_actual".
         *Pre: -.
         *Post: Queda asignado un nuevo valor para el atributo "opcion_actual".
        */
        void asignar_opcion(char recibir_opcion);

        /*Descripcion: Devuelve el atributo "opcion_actual".
         *Pre: -.
         *Post: Devuelve el atributo "opcion_actual".
        */
        char obtener_opcion();
    public:
    /*METODOS*/

        /*Descripcion: Utiliza los metodos necesarios para comenzar la recomendacion de Peliculas.
         *Pre: -.
         *Post: Mediante el proceso se muestra un menu por consola.
        */
        void iniciar();
    private:

         /*Descripcion: Muestra el menu de las opciones permitidas al usuario.
         *Pre: -.
         *Post: Asigna el valor de la opcion elegida al atributo "opcion_actual".
        */
        void mostrar_menu();

        /*Descripcion: Retiene el menu hasta que se ingresa una opcion valida.
         *Pre: -.
         *Post: Muestra el menu.
        */
        void retener_menu();

         /*Descripcion: Dependiendo de la opcion elegida por el usuario se realizaran varios casos.
         *Pre: Listas correctamente creadas.
         *Post: Ejecuta la opcion elegida, por defecto muestra que el ingreso fue invalido.
        */
        void ejecutar_opcion();

        /*Descripcion: Lee el archivo obtenido por parametro, utilizando los metodos necesarios para extraer la informacion.
         *Pre: -.
         *Post: Cierra el archivo previamente obteniendo la informacion del mismo.
        */
        void leer_archivo(int opcion_archivo);

        void seleccionar_informacion(ifstream& leer, int opcion_archivo);

        /*Descripcion: Agrega actores a la Lista del atributo "actores" del objeto "nueva_pelicula".
         *Pre: Valores por parametro asignados correctamente.
         *Post: Crea la Lista de "actores" correspondientes al objeto "nueva_pelicula".
        */
        void agregar_actores(ifstream &leer, string &dato, Pelicula* nueva_pelicula, char &c);

        /*Descripcion: Asigna el dato/puntaje correspondiente al valor de la variable "linea"
         *Pre: valores por parametro asignados correctamente.
         *Post: Asigna el valor correspondiente a los atributos de la "nueva_pelicula".
        */
        void llenar_datos_pelicula(Pelicula* nueva_pelicula, int linea, string dato, int puntaje);

        /*Descripcion: Dependiendo de "opcion_archivo" se guardara el objeto "nueva_pelicula" en la Lista
                       de "vistas" y "no_vistas".
         *Pre: Solo es posible recibir tres opciones, LEER_VISTAS, LEER_RECOMENDACION y LEER_NO_VISTAS.
         *Post: Asigna el valor correspondiente a los atributos de la "nueva_pelicula".
        */
        void guardar_pelicula(Pelicula* nueva_pelicula, int opcion_archivo);

        /*Descripcion: Muestra los detalles del a Pelicula dependiendo de la posicion.
         *Pre: Solo es posible recibir tres opciones, VER_VISTAS, VER_RECOMENDACION y VER_NO_VISTAS.
         *Post: Muestra los detalles de la Pelicula requerida.
        */
        void mostrar_detalles(Lista<Pelicula*>* aux_lista, int i);

        /*Descripcion: Muestra la Lista de Peliculas dependiendo del valor de "opcion_lista".
         *Pre: Solo es posible recibir tres opciones, VER_VISTAS, VER_RECOMENDACION y VER_NO_VISTAS.
         *Post: Muestra la Pelicula.
        */
        void mostrar_pelicula(int opcion_lista);

        /*Descripcion: Utiliza los metodos necesarios para poder agregar Pelicula(s) a la Lista "recomendadas" .
         *Pre: Listas "vistas" y "no_vistas" creadas correctamente.
         *Post: Agrega las Peliculas a la Lista "recomendadas" que cumplan con el criterio de seleccion usado.
        */
        void agregar_peliculas_recomendadas();

        /*Descripcion: Revisa el puntaje de la Pelicula, perteneciente a la Lista "no_vistas", en la posicion requerida.
         *Pre: Listas "vistas" y "no_vistas" creadas correctamente.
         *Post: asdasdas.
        */
        void revisar_puntaje(int j, bool &verificar);

        /*Descripcion: Compara el director de la Pelicula, perteneciente a la Lista "no_vistas", en la posicion requerida
                       con los directores de la Lista de Peliculas "vistas".
         *Pre: Listas "vistas" y "no_vistas" creadas correctamente.
         *Post: asdasdas.
        */
        void comparar_directores(int j, bool &verificar);

        /*Descripcion: Compara los actores de la Pelicula, perteneciente a la Lista "no_vistas", en la posicion requerida
                       con los actores de la Lista de Peliculas "vistas".
         *Pre: Listas "vistas" y "no_vistas" creadas correctamente.
         *Post: En caso de que encuentre comparacion entre actores de ambas Listas asigna VERIFICADO.
        */
        void comparar_actores(int j, bool &verificar);

        /*Descripcion: Utiliza los metodos necesarios para verificar la Pelicula recomendada.
         *Pre: Listas "vistas" y "no_vistas" creadas correctamente.
         *Post: Agrega la Pelicula a la Lista "recomendadas" si es que fue VERIFICADO.
        */
        void verificar_recomendacion(int j);

        /*Descripcion: Verifica que la Lista "recomendadas" posea Peliculas para asi proceder a mostrarla.
         *Pre: las Pelicula(s) de Lista "recomendadas" agregadas correctamente.
         *Post: Muestra la Lista "recomendadas" si el atributo "recomend_creada" fue asignado RECOMEND_CREADA.
        */
        void verificar_lista_recomend();

        /*Descripcion: Copia la informacion de la Pelicula, perteneciente a la Lista "no_vistas" de
                       la posicion requerida, en objeto Pelicula "pelicula_recomendada".
         *Pre: Listas "vistas" y "no_vistas" creadas correctamente.
         *Post: Copa la Pelicula.
        */
        void copiar_pelicula(Pelicula* pelicula_recomendada, int j);


        /*Descripcion: Limita la OPCION_RECOMENDACION, en caso de que "recomend_creada" sea RECOMEND_NO_CREADA
                       procede a implementar el metodo "agregar_peliculas_recomendadas()".
         *Pre: "recomend_creada" con valores asignados correctamente.
         *Post: Limita el uso de la OPCION_RECOMENDACION a uno (1) mediante "recomend_creada", en caso que no se haya usado se procedera a
                implementar "agregar_peliculas_recomendadas()".
        */
        void limitar_opcion_recomend();

        /*Descripcion: Libera la memoria usada en el contenido de las Listas.
         *Pre: -.
         *Post: Devuelve el atributo "opcion_actual".
        */
        void limpiar_listas(Lista<Pelicula*>* aux_lista);

    public:

         /*Descripcion: Destructor de la clase Menu. Se encarga de liberar la memoria utilizada
                        mediante los metodos necesarios. Especificamente la memoria requerida para
                        guardar objetos Pelicula en las listas.
         *Pre: -.
         *Post: Libera la memoria dinamica usada.
        */
        ~Menu();
};

#endif /*_MENU_H_*/
