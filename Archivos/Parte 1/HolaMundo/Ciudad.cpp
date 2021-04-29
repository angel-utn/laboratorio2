#include "Ciudad.h"
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int  Ciudad::getID()
{
    return _ID;
}
char * Ciudad::getNombre()
{
    return _nombre;
}
char * Ciudad::getIDPais()
{
    return _idpais;
}
int  Ciudad::getPoblacion()
{
    return _poblacion;
}
void Ciudad::setID(int val)
{
    _ID = val;
}
void Ciudad::setNombre(const char * val)
{
    strcpy(_nombre, val);
}
void Ciudad::setIDPais(const char * val)
{
    strcpy(_idpais, val);
}
void Ciudad::setPoblacion(int val)
{
    _poblacion = val;
}
void Ciudad::mostrar(){
    cout << _ID << " " << _idpais << " " << _nombre << " " << _poblacion << endl;
}
bool Ciudad::leerDisco(int pos){
    FILE *p;
    p = fopen("ciudades.dat", "rb");
    if (!p)
        return false;
    fseek(p, sizeof(Ciudad) * pos, 0);
    bool ok = fread(this, sizeof(Ciudad), 1, p);
    fclose(p);
    return ok;
}
bool Ciudad::guardarDisco(){
    FILE *p;
    p = fopen("ciudades.dat", "ab");
    if (!p)
    return false;
    bool ok = fwrite(this, sizeof(Ciudad), 1, p);
    fclose(p);
    return ok;
}
bool Ciudad::guardarDisco(int pos){
    FILE *p;
    p = fopen("ciudades.dat", "rb+");
    if (!p)
    return false;
    fseek(p, sizeof(Ciudad) * pos, 0);
    bool ok = fwrite(this, sizeof(Ciudad), 1, p);
    fclose(p);
    return ok;
}


