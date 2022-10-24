// J. Emilio Soriano Campos 
// Laura Alejandra Mendez Campos
#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"

using namespace std;

// Struct para guardar los atributos de cada ip que se lee
struct ip {
    string ipstring;
    long long key;
    int cantAcc;
    bool operator< (const ip& ipAcc) const {
        return (key < ipAcc.key);
    }
    bool operator== (const ip& ipAcc) const {
        return (key == ipAcc.key);
    }
    bool operator> (const ip& ipAcc) const {
        return (key > ipAcc.key);
    }
};

ostream& operator << (ostream &os, const ip &ipAcc) {
    os << ipAcc.ipstring;
    return os;
}

// Funcion para convertir la ip a un valor numerico
long long iptolong(string ip) {
    long long key = 0, acum = 0;
    int idx = 0;
    while (ip[idx] != ':') {
        if (ip[idx] != '.') {
            acum = acum * 10 + ip[idx] - '0';
        } else {
            key = key * 1000 + acum;
            acum = 0;
        } 
        idx++;
    }
    key = key * 1000 + acum;
    return key;
}

// Funcion para eliminar el puerto de acceso del string de ip
string ipstri(string ip) {
    string strip;
    int idx = 0;
    while (ip[idx] != ':') {
        strip+= ip[idx];
        idx++;
    }
    return strip;
}

// Funcion main donde se declaran las variables usadas en todo el programa, se lee el archivo, 
// se construye el arbol y se mandan a llamar las funciones para imprimir los datos deseados
int main() {
    BST<ip> ipTree; // BST de tipo struct ip
    ip ipstr; 
    string mes, dia, hora, currIp, pastIp, ip1, ip2, con;
    long long cIp, pIp;
    int cont = 0, contTemp = 0;

    ifstream archivo("bitacoraOrdenada.txt");
    while (archivo >> mes >> dia >> hora >> currIp) {
        getline(archivo, con);
        cIp = iptolong(currIp);
        if (cont == 0) { // Si el contador es cero significa que hay una nueva ip
            pIp = cIp;
            pastIp = ipstri(currIp);
        }
        if (cIp == pIp){ // Si la ip actual cambia se mandan a guardar los datos recolectados
            cont++;
            cont = cont + contTemp;
            contTemp = 0;
        } else { // De mandan a guardar los datos y se reinicia el contador
            ipstr.ipstring = pastIp;
            ipstr.key = cont * 1000000000000 + pIp;
            ipstr.cantAcc = cont;
            ipTree.add(ipstr);
            contTemp++;
            cont = 0;
        } 
    }
    if (archivo.eof()) { // Pequeño if para guardar el ultimo dato del archivo
        ipstr.ipstring = ipstri(currIp);
        ipstr.key = cont * 1000000000000 + cIp;
        ipstr.cantAcc = cont;
        ipTree.add(ipstr);
    }

    ipTree.visit(); // Ordena el arbol de manera descendente
    ipTree.muestrax(5); // Imprime los x datos que mas se repiten (5 en este caso)

    return 0;
}