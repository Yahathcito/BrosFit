#include "Interfaz.h"
        void Interfaz::menu() {
        int opcion;
        do {
            cout << "\n===== SISTEMA DE GIMNASIO =====" << endl;
            cout << "1. Ingreso de Datos Generales" << endl;
            cout << "2. Informes de Clientes" << endl;
            cout << "3. Informes de Instructores" << endl;
            cout << "4. Historial de Mediciones" << endl;
            cout << "5. Reporte IMC" << endl;
            cout << "6. Rutinas" << endl;
            cout << "7. Matricula de Clases Grupales" << endl;
            cout << "0. Salir" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
            case 1: 
                int opcion;
                do {
                    cout << "\n--- INGRESO DE DATOS GENERALES ---" << endl;
                    cout << "1. Ingreso de sucursales" << endl;
                    cout << "2. Ingreso de clientes (asociar sucursal)" << endl;
                    cout << "3. Ingreso de instructores (asociar sucursal)" << endl;
                    cout << "0. Volver" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> opcion;
                    switch (opcion) {
                    case 1: cout << "Ingreso de sucursales..." << endl; 
                        
                        break;
                    case 2: cout << "Ingreso de clientes..." << endl; 
                        
                        break;
                    case 3: cout << "Ingreso de instructores..." << endl; 
                        
                        break;
                    case 0: break;
                    default: cout << "Opcion invalida!" << endl;
                    }
                } while (opcion != 0);

                break;
            case 2: 
                do {
                    cout << "\n--- INFORMES DE CLIENTES ---" << endl;
                    cout << "1. Lista de clientes por sucursal" << endl;
                    cout << "2. Detalle de un cliente especifico" << endl;
                    cout << "3. Lista de clientes por instructor" << endl;
                    cout << "0. Volver" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> opcion;
                    switch (opcion) {
                    case 1: cout << "Mostrando clientes por sucursal..." << endl; break;
                    case 2: cout << "Mostrando detalle de cliente..." << endl; 
                        break;

                    case 3: cout << "Mostrando clientes por instructor..." << endl; break;
                    case 0: break;
                    default: cout << "Opcion invalida!" << endl;
                    }
                } while (opcion != 0);
                
                break;
            case 3: 
                
                do {
                    cout << "\n--- INFORMES DE INSTRUCTORES ---" << endl;
                    cout << "1. Lista de instructores por sucursal" << endl;
                    cout << "2. Lista de instructores por especialidad" << endl;
                    cout << "0. Volver" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> opcion;
                    switch (opcion) {
                    case 1: cout << "Mostrando instructores por sucursal..." << endl; break;
                    case 2: cout << "Mostrando instructores por especialidad..." << endl; break;
                    case 0: break;
                    default: cout << "Opcion invalida!" << endl;
                    }
                } while (opcion != 0);
                
                break;
            case 4: 
                
                do {
                    cout << "\n--- HISTORIAL DE MEDICIONES ---" << endl;
                    cout << "1. Ingresar medicion de cliente" << endl;
                    cout << "2. Mostrar historial de mediciones de cliente" << endl;
                    cout << "0. Volver" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> opcion;
                    switch (opcion) {
                    case 1: cout << "Ingresando medicion..." << endl; break;
                    case 2: cout << "Mostrando historial de mediciones..." << endl; break;
                    case 0: break;
                    default: cout << "Opcion invalida!" << endl;
                    }
                } while (opcion != 0);
                
                break;
            case 5: 
                cout << "\n--- REPORTE IMC ---" << endl;
                cout << "Mostrando clientes por rangos de IMC en sucursal..." << endl;
                
                break;
            case 6: 
                
                do {
                    cout << "\n--- RUTINAS ---" << endl;
                    cout << "1. Ingresar ejercicios a la bateria" << endl;
                    //Creo que la batería ya viene por defecto con los ejercicios, entonces sería mas como mostrar la batería de ejercicios solamente
                    cout << "2. Generar nueva rutina a cliente" << endl;
                    cout << "0. Volver" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> opcion;
                    switch (opcion) {
                    case 1: cout << "Ingresando ejercicios..." << endl; 
                        //lo mismo que dije antes 
                        break;
                    case 2: cout << "Generando rutina de cliente..." << endl; 
                        break;
                    case 0: break;
                    default: cout << "Opcion invalida!" << endl;
                    }
                } while (opcion != 0);
                
                break;
            case 7: 
                
                do {
                    cout << "\n--- CLASES GRUPALES ---" << endl;
                    cout << "1. Crear clase grupal por sucursal" << endl;
                    cout << "2. Matricular cliente en clase grupal" << endl;
                    cout << "3. Ver lista de clientes por clase" << endl;
                    cout << "4. Ver clases matriculadas por cliente" << endl;
                    cout << "0. Volver" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> opcion;
                    switch (opcion) {
                    case 1: cout << "Creando clase grupal..." << endl; 
                        
                        break;
                    case 2: cout << "Matriculando cliente..." << endl; 
                        
                        break;
                    case 3: cout << "Mostrando clientes de clase..." << endl; 
                        
                        break;
                    case 4: cout << "Mostrando clases por cliente..." << endl; 
                        
                        break;
                    case 0: break;
                    default: cout << "Opcion invalida!" << endl;
                    }
                } while (opcion != 0);
                
                break;
            case 0: 
                
                cout << "Saliendo del sistema..." << endl; 
                
                break;
            default: cout << "Opcion invalida!" << endl;
                break;
            }
        } while (opcion != 0);
    }
//---------------------------------------------------------------------

   