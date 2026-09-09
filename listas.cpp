#include <iostream>
#include <string>
using namespace std;

const int CAPACIDAD_MAXIMA = 10;

class ListaArreglo {
    private:
    int datos[CAPACIDAD_MAXIMA];
    int tamano; // cantidad de elementos actualmente almacenados

    public:
    ListaArreglo() {
        tamano = 0;

    }

    bool estaVacia() {
        return tamano == 0;
    }

    bool estaLlena(){
        return tamano == CAPACIDAD_MAXIMA;
    }

    int obtenerTamano(){
        return tamano;
    }

    //inserta "valor" en la posicion "posicion" (0-indexada)
    //caso limite 1: lista llena -> no se debe insertar
    // caso limite 2: posicion invalida (posicion < 0 o posicion > tamano)
    bool insertar(int valor, int posicion){
        if (estaLlena()){
            cout << "Error: la lista esta llena, no se puede insertar."<< endl;
            return false;
        }
        if(posicion < 0 || posicion > tamano){
            cout << "Error: posicion invalida ("<< posicion << ")." << endl;
            return false;
        }
        
        // Desplazar elementos hacia la derecha para abrir espacio
        for (int i = tamano; i > posicion; i--){
            datos[i]= datos[i - 1];
        }

        datos[posicion] = valor;
        tamano++;
        return true;
    }

    //elimina el elemnto "posicion"
    //caso limite 1: lista vacia; no se puede eliminar
    //caso limite 2: posicion invalida (posicion >= tamano), no se puede
    bool eliminar (int posicion){
        if (estaVacia()){
            cout << "Error: la lista esta vacia, no se puede eliminar. "<< endl;
            return false;
        }
        if (posicion < 0 || posicion >= tamano){
            cout << "Error: posicion invalida (" << posicion << ")." << endl;
            return false;
        }
        // Desplazar elementos hacia la izquierda para cerrar el espacio
        for (int i = posicion; i < tamano - 1; i++){
            datos[i] = datos[i + 1];
        }

        tamano--;
        return true;

    }

    // busca "valor" y retorna su posicion, o -1 si o existe
    int buscar(int valor){
        for(int i = 0; i < tamano; i++){
            if (datos[i]== valor){
                return i;
            }
        }
        return -1;
    }
    // recorre  imprime todos los elemntos de la lista
    void recorrer(){
        if (estaVacia()){
            cout << "[ lista vacia]" << endl;
            return;
        }
        cout << "[";
        for (int i = 0; i < tamano; i++){
            cout << datos[i];
            if (i < tamano - 1) cout << ", ";
        }
        cout << " ]" << endl;
    }
    
};

int main (){
    ListaArreglo lista;

    cout << "--- Insertado elementos---" << endl;
    lista.insertar(10,0);
    lista.insertar(20,1);
    lista.insertar(15,1); //queda 10, 15, 20
    lista.recorrer();

    cout << "\n---buscando el valor 15---" << endl;
    int pos = lista.buscar(15);
    cout << (pos != -1 ? "encontrando en l posicion " + to_string(pos): "no encontrado") << endl;

    cout << "\n--- eliminando la posicion 0---" << endl;
    lista.eliminar(0);
    lista.recorrer();

    cout << "\n=== casos limite (taller practico con ia) ===" << endl;

    cout <<"\n--- caso 1: lista vacia (eliminar)---" << endl;
    ListaArreglo listaVacia;
    listaVacia.eliminar(0); //debe reportar, no debe fallar

    cout <<"\n--- caso 2: lista llena (insertar)---" << endl;
    ListaArreglo listaLlena;
    for(int i = 0; i < CAPACIDAD_MAXIMA; i++){
        listaLlena.insertar(i,i);
    }
    listaLlena.recorrer();
    listaLlena.insertar(99,0); // debe reportar error: lista llena

    cout << "\n--caso 3: posicion invalida (insertar y eliminar)---" << endl;
    ListaArreglo listaPruebas;
    listaPruebas.insertar(1,0);
    listaPruebas.insertar(2,1);
    listaPruebas.insertar(50,-1); //Error: posicion negativa
    listaPruebas.insertar(50,10); //Error: posicion mayor al tamano
    listaPruebas.eliminar(-1);  //Error: poicion negativa
    listaPruebas.eliminar(10);  //Error: posicion fuera de rango
    listaPruebas.recorrer();   // la lista no debe haberse alterado

    return 0;

}