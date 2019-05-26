#include "Menu.h"

/*CONSTRUCTOR*/
Menu::Menu(){
    opcion_actual = OPCION_NULA;
    recomend_creada = RECOMEND_NO_CREADA;
}

/*METODOS ASIGNAR-OBTENER*/


/*METODOS*/

void Menu::iniciar(){
    leer_archivo(LEER_VISTAS);
    leer_archivo(LEER_NO_VISTAS);
    while(opcion_actual != OPCION_SALIR){
        mostrar_menu();
        ejecutar_opcion();
    }
}

void Menu::mostrar_menu(){
    cout<<"             --- Notflox ---"<<endl<<endl;
    cout<<" * Ver lista de peliculas vistas       [v]"<<endl;
    cout<<" * Ver lista de peliculas No vistas    [n]"<<endl;
    cout<<" * Generar recomendaciones             [r]"<<endl;
    cout<<" * Ver lista de peliculas Recomendadas [e]"<<endl;
    cout<<" * Salir                               [x]"<<endl;
    cin>>opcion_actual;
}

void Menu::retener_menu(){
    cout<<"\t\t\t*** Volver al Menu [m] ***"<<endl;
    char aux_opcion = OPCION_MENU;
    do{
        if(aux_opcion != OPCION_MENU){
            cout<<"Ingreso invalido"<<endl;
        }
        cin>>aux_opcion;
    }while(aux_opcion != 'm');
    opcion_actual = aux_opcion;
}

void Menu::verificar_lista_recomend(){
    if(!recomend_creada){
        cout<<"Lista de recomendaciones aun no creada :( "<<endl;
    }else{
        mostrar_pelicula(VER_RECOMENDACION);
        retener_menu();
    }
}

void Menu::limitar_opcion_recomend(){
    if(recomend_creada){
        cout<<"Lista de recomendaciones creada previamente"<<endl;
    }else{
        agregar_peliculas_recomendadas();
    }
}


void Menu::ejecutar_opcion(){
    switch(opcion_actual){
        case OPCION_MOSTRAR_VISTAS:
            mostrar_pelicula(VER_VISTAS);
            retener_menu();
            break;
        case OPCION_MOSTRAR_NO_VISTAS:
            mostrar_pelicula(VER_NO_VISTAS);
            retener_menu();
            break;
        case OPCION_RECOMENDACION:
            limitar_opcion_recomend();
            break;
        case OPCION_VER_RECOMENDACION:
            verificar_lista_recomend();
            break;
        case OPCION_SALIR:
            cout<<"Saliendo de Notflox... "<<endl;
            break;
        default:
            cout<<"Ingreso invalido"<<endl;
    }
}

void Menu::llenar_datos_pelicula(Pelicula* nueva_pelicula, int linea, string dato, int puntaje){
    switch(linea){
        case PRIMER_LINEA:
            nueva_pelicula->asignar_nombre(dato);
            break;
        case SEGUNDA_LINEA:
            nueva_pelicula->asignar_genero(dato);
            break;
        case LINEA_PUNTAJE:
            nueva_pelicula->asignar_puntaje(puntaje);
            break;
        case CUARTA_LINEA:
            nueva_pelicula->asignar_director(dato);
            break;
    }
}


void Menu::agregar_actores(ifstream &leer, string &dato, Pelicula* nueva_pelicula, char &c){
    cout<<"ACTORES: "<<endl;
    cout<<dato;
    nueva_pelicula->agregar_actores(dato);
    if(c != SALTO_LINEA){
        while(c != SALTO_LINEA && leer>>dato){
            nueva_pelicula->agregar_actores(dato);
            cout<<" "<<dato;
            leer.get(c);
        }
    }
}

void Menu::guardar_pelicula(Pelicula* nueva_pelicula, int opcion){
    if(opcion == LEER_VISTAS){
        vistas.agregar_nodo(nueva_pelicula,POSICION_DEFECTO);
    }else if(opcion == LEER_NO_VISTAS){
        no_vistas.agregar_nodo(nueva_pelicula,POSICION_DEFECTO);
    }else if(opcion == RECOMENDACION){
        recomendadas.agregar_nodo(nueva_pelicula, POSICION_DEFECTO);
    }
}

void Menu::seleccionar_informacion(ifstream& leer, int opcion_archivo){
    Pelicula* nueva_pelicula = new Pelicula;
    string dato;
    int puntaje=PUNTAJE_INICIAL;
    char c;
    int linea = PRIMER_LINEA;
    while((linea != LINEA_PUNTAJE && leer>>dato) ||(linea == LINEA_PUNTAJE && leer>>puntaje) ){
        leer.get(c);
        if(linea == LINEA_ACTORES){
            agregar_actores(leer ,dato, nueva_pelicula, c);
        }else if(c == SALTO_LINEA){
            cout<<dato;
            cout<<endl;
            llenar_datos_pelicula(nueva_pelicula, linea, dato, puntaje);
        }
        if(linea == LINEA_ACTORES){
            cout<<endl<<endl;
            guardar_pelicula(nueva_pelicula, opcion_archivo);
            cout<<"PELICULA CREADA"<<endl;
            nueva_pelicula = new Pelicula;
            linea = REINICIAR_LINEA;
        }
        linea++;
    }
    delete nueva_pelicula;
}

void Menu::leer_archivo(int opcion_archivo){
    cout<<"LEER"<<endl;
    if(opcion_archivo == LEER_VISTAS){
        ifstream leer(PELIS_VISTAS);
        seleccionar_informacion(leer, opcion_archivo);
        leer.close();
    }else if(opcion_archivo == LEER_NO_VISTAS){
        ifstream leer(PELIS_NO_VISTAS);
        seleccionar_informacion(leer, opcion_archivo);
        leer.close();
    }
}

void Menu::mostrar_detalles(Lista<Pelicula*>* aux_lista, int i){
    int cant_actores = aux_lista->consultar_lista(i)->cant_actores();
    cout<<"\t\tPelicula "<<i<<": "<<aux_lista->consultar_lista(i)->obtener_nombre()<<endl;
    cout<<"Genero: "<<aux_lista->consultar_lista(i)->obtener_genero()<<endl;
    cout<<"Puntaje: "<<aux_lista->consultar_lista(i)->obtener_puntaje()<<endl;
    cout<<"Director: "<<aux_lista->consultar_lista(i)->obtener_director()<<endl;
    cout<<endl<<"Actores "<<cant_actores<<": "<<endl;
    for(int j=1; j <= cant_actores ;j++){
        if(j>1){
            cout<<" - ";
        }
        cout<<aux_lista->consultar_lista(i)->consultar_actores(j);
    }
    cout<<endl<<"-------------------------------------------------------------------------"<<endl;
}


void Menu::mostrar_pelicula(int opcion_lista){
    Lista<Pelicula*>* aux_lista;
    if(opcion_lista == VER_VISTAS){
        cout<<"***Peliculas que viste*** "<<endl;
        aux_lista = &vistas;
    }else if(opcion_lista == VER_NO_VISTAS){
        cout<<"***Peliculas que aun no viste*** "<<endl;
        aux_lista = &no_vistas;
    }else if(opcion_lista == VER_RECOMENDACION){
        aux_lista = &recomendadas;
    }
    for(int i = 1; i <= aux_lista->obtener_tam_lista() ; i++){
        mostrar_detalles(aux_lista, i);
    }
}

void Menu::revisar_puntaje(int j, bool &verificar){
    if(no_vistas.consultar_lista(j)->obtener_puntaje() >= 7){
        cout<<"Puntaje: "<<no_vistas.consultar_lista(j)->obtener_puntaje()<<endl;
        verificar = VERIFICADO;
    }
}

void Menu::comparar_directores(int j, bool &verificar){
    for(int i = 1; i <= vistas.obtener_tam_lista() ; i++){
        if(no_vistas.consultar_lista(j)->obtener_director() == vistas.consultar_lista(i)->obtener_director()){
            cout<<"Directores iguales "<<no_vistas.consultar_lista(j)->obtener_director()<<" y "<<vistas.consultar_lista(i)->obtener_director()<<endl;
            verificar = VERIFICADO;
            i += vistas.obtener_tam_lista();
        }
    }
}

void Menu::comparar_actores(int j, bool &verificar){
    for(int k = 1; k <= no_vistas.consultar_lista(j)->cant_actores() ;k++ ){
        for(int q = 1 ; q <= vistas.obtener_tam_lista() ; q++){
            for(int z = 1; z <= vistas.consultar_lista(q)->cant_actores() ;z++ ){
                if(no_vistas.consultar_lista(j)->consultar_actores(k) == vistas.consultar_lista(q)->consultar_actores(z) ){
                    cout<<"Coinciden actores"<<endl;
                    cout<< no_vistas.consultar_lista(j)->consultar_actores(k)<< "y"<< vistas.consultar_lista(q)->consultar_actores(z)<<endl;
                    verificar = VERIFICADO;
                    z += vistas.consultar_lista(q)->cant_actores();
                }
            }
            if(verificar){
                q += vistas.obtener_tam_lista();
            }
        }
        if(verificar){
            k += no_vistas.consultar_lista(j)->cant_actores();
        }
    }
}


void Menu::copiar_pelicula(Pelicula* pelicula_recomendada, int j){
    pelicula_recomendada->asignar_nombre(no_vistas.consultar_lista(j)->obtener_nombre());
    pelicula_recomendada->asignar_genero(no_vistas.consultar_lista(j)->obtener_genero());
    pelicula_recomendada->asignar_puntaje(no_vistas.consultar_lista(j)->obtener_puntaje());
    pelicula_recomendada->asignar_director(no_vistas.consultar_lista(j)->obtener_director());
    for(int i = 1; i<= no_vistas.consultar_lista(j)->cant_actores(); i++){
        pelicula_recomendada->agregar_actores(no_vistas.consultar_lista(j)->consultar_actores(i));
    }
}

void Menu::verificar_recomendacion(int j){
    bool verificado = NO_VERIFICADO;
    for(int i = 1; i<=3 ; i++){
        if(i == REVISAR_PUNTAJE){
            revisar_puntaje(j, verificado);
        }else if(i == REVISAR_DIRECTOR && verificado != VERIFICADO){
            comparar_directores(j, verificado);
        }else if(i == REVISAR_ACTORES && verificado != VERIFICADO){
            comparar_actores(j, verificado);
        }
    }
    if(verificado){
        recomend_creada = RECOMEND_CREADA;
        cout<<no_vistas.consultar_lista(j)->obtener_nombre()<<endl;
        cout<<"VERIFICADO PARA RECOMENDAR"<<endl;
        Pelicula* pelicula_recomendada = new Pelicula;
        copiar_pelicula(pelicula_recomendada, j);
        guardar_pelicula(pelicula_recomendada, RECOMENDACION);
    }
}

void Menu::agregar_peliculas_recomendadas(){
    for(int j = 1; j <= no_vistas.obtener_tam_lista() ; j++){
        for(int i = 1; i <= vistas.obtener_tam_lista() ; i++){
            if(vistas.consultar_lista(i)->obtener_genero() == no_vistas.consultar_lista(j)->obtener_genero() ){
                cout<<"Coincide genero"<<endl;
                cout<<vistas.consultar_lista(i)->obtener_nombre()<< " = "<<no_vistas.consultar_lista(j)->obtener_nombre()<<endl;
                cout<<vistas.consultar_lista(i)->obtener_genero()<< " = "<< no_vistas.consultar_lista(j)->obtener_genero()<<endl;
                verificar_recomendacion(j);
                i += vistas.obtener_tam_lista();
            }
        }
    }
}



void Menu::limpiar_listas(Lista<Pelicula*>* aux_lista){
    while(!(aux_lista->lista_vacia())){
        cout<<"limpiar lista de actores"<<endl;
        cout<<"titulo: *** "<<aux_lista->consultar_lista(POSICION_DEFECTO)->obtener_nombre()<<endl;
        delete aux_lista->consultar_lista(POSICION_DEFECTO);
        cout<<"eliminando pelicula"<<endl;
        aux_lista->eliminar_nodo(POSICION_DEFECTO);
    }
}

/*DESTRUCTOR*/

Menu::~Menu(){
    Lista<Pelicula*>* aux_lista = &recomendadas;
    cout<<"Destructor Menu"<<endl;
    cout<<vistas.lista_vacia()<<endl;
    limpiar_listas(aux_lista);
    aux_lista = &vistas;
    limpiar_listas(aux_lista);
    aux_lista = &no_vistas;
    limpiar_listas(aux_lista);
    cout<<"contenido de vistas eliminado"<<endl;
}
