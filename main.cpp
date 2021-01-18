
#include <bits/stdc++.h>
#include "capturador.hpp"
#include "filtro.hpp"

#include "pcap.h"


#define HAVE_REMOTE


using namespace std;
Capturador capturador;
pcap_if_t *seleccionarInterface(){
    cout<<"Seleccion de dispositivo\n";
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevs, *d;    
    int n;
    register int i;
    if (pcap_findalldevs(&alldevs, errbuf) == -1){
        fprintf(stderr,"Error al encontrar dispositivos: %s\n", errbuf);
        exit(1);
    }
    for(i=0,d = alldevs; d != NULL; d= d->next){  
        if (d->description)
            cout<<++i<<". "<<d->name<<" ("<<d->description<<")\n";              
        else
            cout<<++i<<". "<<d->name<<" (sin descripcion)\n";          
    }    
    while(true){    
        cout<<"Ingrese el numero de la interface a utilizar: "; 
        cin>>n;
        if(n>=i){
            cout<<"Numero de interfaz invalida\n";
        }else{
            break;
        }
    }
    for(i = 0; i <n; i++){        
        d->next;
    }
    return d;
}
vector<Filtro> especificarFiltros(){
    vector<Filtro> filtros;
    String strTemp;
    int intTemp;
    cout<<"Especificar filtros:\n";
    while(true){        
        cout<<"Desea agregar un filtro?\n1)SI\n2)NO\n>>";
        cin>>opcion;
        if(opcion == 2)
            break;
        Filtro filtro = new Filtro();
        cout<<"Desea filtrar la ip de origen?\n1)SI\n2)NO\n>>";        
        cin>>opcion;        
        if(opcion == 1){
            cout<<"Ingrese la ip de origen: ";
            cin>>strTemp;
            filtro.setIpOrigen(strTemp);
        }
        cout<<"Desea filtrar la ip de destino?\n1)SI\n2)NO\n>>";        
        cin>>opcion;        
        if(opcion == 1){
            cout<<"Ingrese la ip de destino: ";
            cin>>strTemp;
            filtro.setIpDestino(strTemp);
        }
        cout<<"Desea filtrar el puerto de origen?\n1)SI\n2)NO\n>>";        
        cin>>opcion;        
        if(opcion == 1){
            cout<<"Ingrese el puerto de origen: ";
            cin>>intTemp;
            filtro.setPuertoOrigen(intTemp);
        }
        filtros.push_back(filtro);
        
    }
    return filtros;
}
int main(void){
    pcap_if_t *interface;
    Vector<Filtro> filtros;
    interface = seleccionarInterface();
    filtros = especificarFiltros();

}
