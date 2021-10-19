#include <iostream>
#include <string>
using namespace std;

struct usuario{
    string descripcion;
    int id, perfil;
};

usuario solicitarnombre(void){
    usuario p;
    cout << "usuario: ";
    getline(cin, p.descripcion);
    cout << "agrege el id: ";
    cin >> p.id; cin.ignore();
    cout<<endl;
    cout<<"elija una opcion"<<endl;
    cout<<"1)administrador"<<endl;
    cout<<"2)cliente"<<endl;
    cout<<"3)trabajador"<<endl;
    cout<<"opcion"<<endl;
    cin>>p.perfil;
    return p;
}

void mostrardescripcion(usuario p){
    cout << "usuario: " << p.descripcion;
    cout << " (" << p.id << ")  ";
    switch (p.perfil)
    {
    case 1:
        cout<<"es un administrador: "<<endl;
        break;
    case 2:
        cout<<"es un cliente."<<endl;
        break;
    case 3:
        cout<<"es un trabajador."<<endl;
        break;
    default:
        cout<<"la opcion no es valida."<<endl;
        break;
    }
}

typedef usuario T;
const T noValido = {"",0};

struct nodo{
    T dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble{
    private:
        nodo *pInicio;
    public:
        ListaDoble();
        ~ListaDoble();
        void agregarnombre(T);
        void mostrarnombre(void);
        void eliminarnombre(T);
        bool empty(void);
};

ListaDoble::ListaDoble(void){
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void){
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::agregarnombre(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin = pInicio;
        while(saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}

void ListaDoble::mostrarnombre(void){
    nodo *saltarin = pInicio;
    while(saltarin != NULL){
        mostrardescripcion(saltarin->dato);
        saltarin = saltarin->sig;
    }
}

void ListaDoble::eliminarnombre(T datoB){
    if(!pInicio){ 
        cout << "Actualmente no hay usuarios registrado." << endl;
    }
    else{ 
        nodo *saltarin = pInicio;
        while(saltarin && (saltarin->dato).descripcion.compare(datoB.descripcion)!=0) 
            saltarin = saltarin->sig; 
        if(!saltarin) 
            cout << "El usuario no esta registrado" << endl;
        else{ 
            if(!saltarin->ant && saltarin->sig){ 
                pInicio = pInicio->sig;
                pInicio->ant = NULL;
                delete saltarin;
            }
            else
                if(saltarin->ant && !saltarin->sig){
                    saltarin->ant->sig = NULL;
                    delete saltarin;
                }
                else
                    if(saltarin->ant && saltarin->sig){
                        saltarin->ant->sig = saltarin->sig;
                        saltarin->sig->ant = saltarin->ant;
                        delete saltarin;
                    }
                    else{
                        pInicio = NULL;
                        delete saltarin;
                    }
            cout << "usuario eliminada exitosamente!" << endl;
        }
    }
}

bool ListaDoble::empty(void){
    return pInicio == NULL;
}