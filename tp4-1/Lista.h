#ifndef _LISTA_H_
#define _LISTA_H_

#include "Nodo.h"

const int LISTA_VACIA = 0;
const int PRIMER_NODO = 1;
const int NODO_ANTERIOR = 1;

template<typename Dato>
class Lista{
    private:
    /*ATRIBUTOS*/
        Nodo<Dato>* primer_nodo;
        int tam_lista;
    public:
    /*CONSTRUCTOR*/

        /*Descripcion: Constructor de la clase Lista. Inicializa los atributos correspondientes.
         *Pre: -.
         *Post: Inicializa los atributos.
        */
        Lista();
    public:
    /*METODOS ASIGNAR-OBTENER*/

        /*Descripcion: Asigna un valor al atributo "primer_nodo".
         *Pre: -.
         *Post: Queda asignado una nueva direccion para el atributo "primer_nodo".
        */
        void asignar_primer_nodo(Nodo<Dato>* recibir_primer_nodo);

        /*Descripcion: Devuelve la direccion del atributo "primer_nodo".
         *Pre: La lista no debe estar vacia, primer_nodo != 0.
         *Post: Devuelve la direccion del atributo "primer_nodo".
        */
        Nodo<Dato>* obtener_primer_nodo();

        /*Descripcion: Asigna un valor al atributo "tam_lista".
         *Pre: Valor de "recibir_tamaño" correspondiente al tamaño de la lista.
               "recibir_tamaño" >= 0.
         *Post: Actualiza el atributo "tam_lista" al correspondiente.
        */
        void asignar_tam_lista(int recibir_tam_lista);

        /*Descripcion: Devuelve el tamaño de la lista mediante el atributo "tam_lista".
         *Pre: -.
         *Post: Devuelve el tamaño actual de la lista.
        */
        int obtener_tam_lista();
    public:
    /*METODOS*/

        /*Descripcion: Verifica si la lista esta vacia consultando el atributo "tam_lista".
         *Pre: El atributo "tam_lista" debe estar correctamente actualizado.
         *Post: Si el atributo "tam_lista" tiene valor cero(0), devuelve "true".
                Caso contrario, devuelve "false".
        */
        bool lista_vacia();

        /*Descripcion: Devuelve el contenido del Nodo requerido mediante su posicion.
         *Pre: La lista no debe estar vacia, atributo tam_lista != 0. La posicion requerida debe ser > 0 y <= tam_lista.
         *Post: Devuelve el contenido del Nodo requerido.
        */
        Dato consultar_lista(int posicion_consulta);

        /*Descripcion: Devuelve la direccion del Nodo requerido mediante su posicion.
         *Pre: La lista no debe estar vacia, atributo tam_lista != 0. La posicion requerida debe ser > 0 y <= tam_lista.
         *Post: Devuelve la direccion Nodo requerido.
        */
        Nodo<Dato>* obtener_nodo(int posicion_consulta);

        /*Descripcion: Dependiendo de los dos casos(2) generales, es creado el Nodo en la posicion requerida.
                       Quedan asignados y actualizados los valores correspondientes.
         *Pre: La posicion requerida debe ser > 0 y <= tam_lista+1. El tipo de dato debe corresponder al definido para "Dato".
         *Post: Agrega un nuevo Nodo a la lista, actualiza los punteros correctamente.
        */
        void agregar_nodo(Dato recibir_contenido, int posicion_agregar);

        /*Descripcion: Dependiendo de la posicion se ejecutan en general dos (2) casos, al implementarse alguno se
                procedera a actualizar el atributo "primer_nodo", el puntero del Nodo anterior al eliminar y el
                tamaño de ser necesario.
         *Pre: La lista no debe estar vacia, atributo tam_lista != 0.
         *Post: Elimina el Nodo correspondiente de la lista en la posicion requerida, actualiza los atributos afectados.
        */
        void eliminar_nodo(int posicion_eliminar);

    /*DESTRUCTOR*/

        /*Descripcion: Destructor de la clase Lista, libera la memoria dinamica usada.
         *Pre: -.
         *Post: Libera la memoria dinamica usada.
        */
        ~Lista();
};


/*CONSTRUCTOR*/
template<typename Dato>
Lista<Dato>::Lista(){
    cout<<"Constructor Lista"<<endl;
    tam_lista = LISTA_VACIA;
}

/*METODOS ASIGNAR-OBTENER*/
template<typename Dato>
void Lista<Dato>::asignar_primer_nodo(Nodo<Dato>* recibir_primer_nodo){
    primer_nodo = recibir_primer_nodo;
}
template<typename Dato>
Nodo<Dato>* Lista<Dato>::obtener_primer_nodo(){
    return primer_nodo;
}
template<typename Dato>
void Lista<Dato>::asignar_tam_lista(int recibir_tam_lista){
    tam_lista = recibir_tam_lista;
}
template<typename Dato>
int Lista<Dato>::obtener_tam_lista(){
    return tam_lista;
}

/*METODOS*/
template<typename Dato>
bool Lista<Dato>::lista_vacia(){
    return (tam_lista == LISTA_VACIA);
}
template<typename Dato>
Dato Lista<Dato>::consultar_lista(int posicion_consulta){
    Nodo<Dato>* nodo_buscado = obtener_nodo(posicion_consulta);
    return (nodo_buscado->obtener_contenido());
}

template<typename Dato>
Nodo<Dato>* Lista<Dato>::obtener_nodo(int posicion_consulta){
    Nodo<Dato>* nodo_obtenido = primer_nodo;
    for(int i = PRIMER_NODO; i<posicion_consulta ; i++){
        nodo_obtenido = nodo_obtenido->obtener_siguiente();
    }
    return nodo_obtenido;
}

template<typename Dato>
void Lista<Dato>::agregar_nodo(Dato recibir_contenido, int posicion_agregar){
    Nodo<Dato>* nodo_agregar = new Nodo<Dato>(recibir_contenido, (Nodo<Dato>*)PUNTERO_NULO);
    if( posicion_agregar == PRIMER_NODO ){
        nodo_agregar->asignar_siguiente(primer_nodo);
        primer_nodo = nodo_agregar;
    }else{
        Nodo<Dato>* nodo_anterior = obtener_nodo(posicion_agregar - NODO_ANTERIOR);
        nodo_agregar->asignar_siguiente(nodo_anterior->obtener_siguiente());
        nodo_anterior->asignar_siguiente(nodo_agregar);
    }
    tam_lista++;
}
template<typename Dato>
void Lista<Dato>::eliminar_nodo(int posicion_eliminar){
    cout<<"Eliminando Nodo: "<<posicion_eliminar<<endl;
    Nodo<Dato>* nodo_eliminar;
    if( posicion_eliminar == PRIMER_NODO){
        nodo_eliminar = primer_nodo;
        primer_nodo = primer_nodo->obtener_siguiente();
    }else{
        Nodo<Dato>* nodo_anterior = obtener_nodo(posicion_eliminar - NODO_ANTERIOR);
        nodo_eliminar = nodo_anterior->obtener_siguiente();
        nodo_anterior->asignar_siguiente(nodo_eliminar->obtener_siguiente());
    }
    tam_lista--;
    delete nodo_eliminar;
}

/*DESTRUCTOR*/
template<typename Dato>
Lista<Dato>::~Lista(){
    while(tam_lista > LISTA_VACIA){
        cout<<"Destructor Lista"<<endl;
        eliminar_nodo(PRIMER_NODO);
    }
}


#endif /*_LISTA_H_*/










