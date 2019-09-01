#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
}*pilanicio, *colanicio, *fin;
class Pila{
    public:
        Pila(){
            pilanicio=nullptr;
        }
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n->dato = valor;
            n->sig = nullptr;
            return n;
        }
        void push(int valor){
            Nodo *n = crearNodo(valor);
            n->sig = pilanicio;
            pilanicio = n;
        }
        void pop(){
            Nodo *temp = pilanicio;
            pilanicio = pilanicio->sig;
            free(temp);
        }
        void mostrarPila(){
            Nodo *temp = pilanicio;
            if(!pilanicio)
                cout << "Pila vacia" << endl;
            else
                while(temp){
                    cout << temp->dato << ",";
                    temp = temp->sig;
                }
        }

};
class Cola{
    public:
        Cola(){
            colanicio = nullptr;
        }
        
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n->dato = valor;
            n->sig = nullptr;
            return n;
        }
        void push(int valor){
            Nodo *n = crearNodo(valor);
            if(!colanicio){
                colanicio = n;
                fin = n;
            }
            else{
                fin->sig = n;
                fin = n;
            }
        }
        int pop(){
            Nodo *temp = colanicio;
            int aux;
            colanicio = colanicio->sig;
            aux = temp->dato;
            free(temp);
            return aux;
        }
        void mostrarCola(){
            Nodo *temp = colanicio;
            if(!colanicio)
                cout << "Cola vacia" << endl;
            else
                while(temp){
                    cout << temp->dato<<",";
                    temp = temp->sig;
                }
        }  
}; //me confundi y lo borre :c
int main()
{
    Cola c;
    c.push(1);
    c.push(2);
    c.push(3);
    cout << "Cola"<<endl;
    c.mostrarCola();
    cout << endl;
    return 0;
}
