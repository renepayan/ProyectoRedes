
#include <bits/stdc++.h>
#include "capturador.hpp"
#include "filtro.hpp"

#include "pcap.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

#define HAVE_REMOTE


using namespace std;
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
            cout<<i++<<". "<<d->name<<" ("<<d->description<<")\n";              
        else
            cout<<i++<<". "<<d->name<<" (sin descripcion)\n";          
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
    d = alldevs;
    for(i = 0; i <n; i++){        
        d = d->next;
    }    
    return d;
}
vector<Filtro> especificarFiltros(){
    vector<Filtro> filtros;
    string strTemp;
    int intTemp, opcion;
    cout<<"Especificar filtros:\n";
    while(true){        
        cout<<"Desea agregar un filtro?\n1)SI\n2)NO\n>>";
        cin>>opcion;
        if(opcion == 2)
            break;
        Filtro filtro;
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
        cout<<"Desea filtrar el puerto de destino?\n1)SI\n2)NO\n>>";        
        cin>>opcion;        
        if(opcion == 1){
            cout<<"Ingrese el puerto de destino: ";
            cin>>intTemp;
            filtro.setPuertoDestino(intTemp);
        }
        filtros.push_back(filtro);
        cout<<"Desea filtrar la aplicacion?\n1)SI\n2)NO\n>>";        
        cin>>opcion;        
        if(opcion == 1){
            cout<<"Aplicaciones disponibles:\n1. HTTP\n2. DNS\n3. DHCP\n 4. ARP";
            cout<<"Ingrese el numero de aplicacion: ";
            cin>>intTemp;
            filtro.setAplicacion(intTemp);
        }
        filtros.push_back(filtro);
        cout<<"Filtro agregado!!!!\n";
    }
    return filtros;
}

FILE *especificarArchivo(){
    char ruta[255];
    FILE *archivo;
    cout<<"Ingrese la ruta del archivo dump: ";
    cin>>ruta;
    archivo = fopen(ruta, "w");
    return archivo;
}

int especificarNivelVerbosidad(){
    int nivel;
    cout<<"Que nivel de verbosidad se va a ocupar:\n0. No se muestra nada en consola\n1. Solo se muestra la informacion general del paquete\n2. Muestra informacion del paquete y protocolo (TCP, UDP)\n3. Muestra toda la informacion disponible\n>>";
    cin>>nivel;
    return nivel;    
}

void my_handler(sig_atomic_t s)
    std::cout<<"Cerrando captura\n";
    fclose(Capturador::archivoSalida);
}

int main(void){
    signal (SIGINT,my_handler);
    pcap_if_t *interface;
    vector<Filtro> filtros;    
    FILE *archivoGuardado;
    int nivelVerbosidad;

    interface = seleccionarInterface();
    //filtros = especificarFiltros();    
    archivoGuardado = especificarArchivo();
    //nivelVerbosidad = especificarNivelVerbosidad();

    Capturador capturador(interface, filtros, archivoGuardado, nivelVerbosidad);    
    cout<<capturador.toString()<<'\n';
    capturador.iniciarCaptura();
}
