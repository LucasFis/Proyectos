#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <unistd.h>
#include "utils.h"

using namespace std;

struct s_input_bin{
    char nombre_cuenta[127];
    char contrasenia_cuenta[127];
    char uso[127];
};

const char* archivo_binario = "passwords.dat";

static void obtener_datos(){
    ifstream data(archivo_binario,ios::binary);
    s_input_bin readed_data;
    char searched_name[127];

    cout << "Ingrese el nombre de la cuenta que quiere buscar sus datos: ";
    cin >> searched_name;

    data.read((char*) &readed_data, sizeof(readed_data));
    while(!data.eof()){
        if(strcmp(searched_name,readed_data.nombre_cuenta)==0)
            break;
        data.read((char*) &readed_data, sizeof(readed_data));
    }
    if(data.eof()){
        system("cls");
        cout << "La cuenta no se encontro o no existe!\n";
    } else{
        data.close();
        cout << "HIT! \nCuenta: " << readed_data.nombre_cuenta << endl;
        cout <<  "Password: " << readed_data.contrasenia_cuenta << endl;
        cout <<  "Aplicacion de uso: " << readed_data.uso << endl;
    }
    cout << "Enter para continuar... ";
    getch();
}

static void iterar_archivo(){
    ifstream data(archivo_binario,ios::binary);
    s_input_bin readed_data;

    data.read((char*) &readed_data, sizeof(readed_data));
    while(!data.eof()){
        cout << "Nombre: " << readed_data.nombre_cuenta << ", password: " << readed_data.contrasenia_cuenta << ", uso:" << readed_data.uso << endl;
        data.read((char*) &readed_data, sizeof(readed_data));
    } 
    data.close();
    cout << "Enter para continuar... ";
    getch();
}

static void agregar_cuenta(){
    ofstream data(archivo_binario, ios::binary | ios::app);
    s_input_bin written_data;

    data.seekp(0);

    cout << "Ingrese un nombre de cuenta: ";
    cin >> written_data.nombre_cuenta;
    cout << "Ingrese una password vinculada al nombre anterior: ";
    cin >> written_data.contrasenia_cuenta;
    cout << "Uso de la cuenta: ";
    cin >> written_data.uso;
    data.write((char*) &written_data,sizeof(written_data));

    cout << "Cuenta agregada con exito" << endl;
    data.close();
    cout << "Enter para continuar... ";
    getch();
}

static void cambiar_password(){
    fstream data(archivo_binario,ios::binary| ios::in | ios::out);
    s_input_bin readed_data;
    char searched_name[127],new_pass[127];
    
    cout << "Ingrese el nombre de la cuenta que quiere cambiar sus datos: ";
    cin >> searched_name;

    data.read((char*) &readed_data, sizeof(readed_data));

    while(!data.eof()){

        if(strcmp(searched_name,readed_data.nombre_cuenta)==0)
            break;

        data.read((char*) &readed_data, sizeof(readed_data));
    }

    if(data.eof()){

        cout << "No se encontro esta cuenta!\n";
        data.close();

        return;
    }

    int f_pointer = data.tellg() - sizeof(readed_data);

    cout << "Cuenta encontrada exitosamente!\n";
    cout << "Ingrese la password nueva: ";
    cin >> new_pass;

    strcpy(readed_data.contrasenia_cuenta, new_pass);

    data.seekp(f_pointer);

    data.write((char*) &readed_data,sizeof(readed_data));

    cout << "password cambiada correctamente!";
    
    data.close();
    cout << "Enter para continuar... ";
    getch();
}

static void eliminar_cuenta(){
    fstream data(archivo_binario, ios::binary | ios::in | ios::out);
    s_input_bin readed_data;

    fstream new_data("aux.dat", ios::binary | ios::out);

    char searched_name[127];

    cout << "Ingrese el nombre de la cuenta a borrar: ";

    cin >> searched_name ;

    while(data.read((char*) &readed_data,sizeof(readed_data))){

        if(strcmp(readed_data.nombre_cuenta,searched_name) == 0){
            printf("HIT!");
            continue;
        }
        new_data.write((char*)&readed_data,sizeof(readed_data));
    }

    cout << "Enter para continuar... ";
    data.close();
    new_data.close();
    remove(archivo_binario);
    rename("aux.dat",archivo_binario);
    getch();
}

void menu(){
    char Opc;

    while(Opc != 'F'){
        system("cls");
        printf("Seleccionar Opcion:\n");
        printf("A) Datos de cuenta\n");
        printf("B) Agregar Cuenta\n");
        printf("C) Cambiar password de una cuenta\n");
        printf("D) Iterar en archivo\n");
        printf("E) Eliminar una cuenta\n");
        printf("F) Finalizar\n");
        cin >> Opc;
        
        if(Opc >= 'A' && Opc <= 'Z')
            switch(Opc){
                case 'A':

                    obtener_datos();
                    break;
                case 'B':

                    agregar_cuenta();
                    break;
                case 'C':

                    cambiar_password();
                    break;

                case 'D':

                    iterar_archivo();
                    break;

                case 'E':

                    eliminar_cuenta();
                    break;
            }
    }
}