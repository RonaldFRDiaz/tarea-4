#include "doble.hpp"

int menu(){
    int opcion = 0;
    cout<<endl<<endl;
    cout<<"\t    !!!BUENOS DIAS!!!   "<<endl;
   
    cout<<"\t---------------------------"<<endl;
    cout << endl << "1) Agregar usuario." << endl;
    cout << "2) mostrar historial." << endl;
    cout << "3) eliminar usuario." << endl;
    cout << "4) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(void){
    ListaDoble saga;
    
    bool continuar = true;
    usuario p;
    usuario pref;
    do{
        switch(menu()){
            case 1: 
               p = solicitarnombre();
                saga.agregarnombre(p);
                cout << "usuario agregado exitosamente!" << endl;
                break;
            case 2: 
                if(saga.empty())
                    cout << "El historial esta vacio! " << endl;
                else{
                    saga.mostrarnombre();
                }
                
                break;
            case 3: 
                if(saga.empty())
                    cout << "No hay usuario por eliminar" << endl;
                else{
                    p = solicitarnombre();
                    saga.eliminarnombre(p);
                }
                break;
            case 4: 
                continuar = false;
                break;
            default: 
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}
