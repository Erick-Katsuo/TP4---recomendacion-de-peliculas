#ifndef _NODO_H_
#define _NODO_H_

#include <iostream>

using namespace std;

const int PUNTERO_NULO = 0;

template<typename Dato>
class Nodo{
    private:
    /*ATRIBUTOS*/
        Dato contenido;
        Nodo* siguiente;
    public:
    /*CONSTRUCTOR*/

        /*Descripcion: Constructor de la clase Nodo. Inicializa los atributos correspondientes.
         *Pre: -.
         *Post: Crea el objeto con los parametros obtenidos.
        */
        Nodo(Dato recibir_contenido, Nodo* recibir_siguiente);
    public:
    /*METODOS*/
        /*Descripcion: Asigna un valor al atributo "contenido".
         *Pre: El tipo de dato debe corresponder al definido para "Dato".
         *Post: Queda asignado un nuevo valor para el atributo "contenido".
        */
        void asignar_contenido(Dato recibir_contenido);

        /*Descripcion: Asigna una direccion al atributo "siguiente".
         *Pre: La direccion recibida debe corresponder a un puntero de la clase Nodo.
         *Post: Asigna una nueva direccion para el atributo "siguiente".
        */
        void asignar_siguiente(Nodo* recibir_siguiente);

        /*Descripcion: Devuelve el atributo "contenido".
         *Pre: -.
         *Post: Devuelve el atributo "contenido".
        */
        Dato obtener_contenido();

        /*Descripcion: Devuelve la direccion correspondiente al atributo "siguiente".
         *Pre: -.
         *Post: Devuelve la direccion correspondiente al atributo "siguiente".
        */
        Nodo* obtener_siguiente();
};


/*CONSTRUCTOR*/
template<typename Dato>
Nodo<Dato>::Nodo(Dato recibir_contenido, Nodo<Dato>* recibir_siguiente){
    cout<<"Constructor Nodo"<<endl;
    contenido = recibir_contenido;
    siguiente = recibir_siguiente;
}

/*METODOS ASIGNAR-OBTENER*/
template<typename Dato>
void Nodo<Dato>::asignar_contenido(Dato recibir_contenido){
    contenido = recibir_contenido;
}
template<typename Dato>
void Nodo<Dato>::asignar_siguiente(Nodo* recibir_siguiente){
    siguiente = recibir_siguiente;
}
template<typename Dato>
Dato Nodo<Dato>::obtener_contenido(){
    return contenido;
}
template<typename Dato>
Nodo<Dato>* Nodo<Dato>::obtener_siguiente(){
    return siguiente;
}


#endif /*_NODO_H_*/
