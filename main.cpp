
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
            cout<<"Numero de interface invalida\n";
        }else{
            break;
        }
    }
    for(i = 0; i <n; i++){        
        d->next;
    }
    return d;
}
Filtro *especificarFiltros(){
    cout<<"Especificar filtros:\n";
    while(true){
        
    }

}
int main(void){
    pcap_if_t *interface;
    Filtro *filtros;
    interface = seleccionarInterface();
    filtros = especificarFiltros();

}
