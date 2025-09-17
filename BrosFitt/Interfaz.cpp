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
			system("cls");

            switch (opcion) {
            case 1: 
				ingresoDatosGenerales(); 
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
                    case 2: cout << "Mostrando detalle de cliente..." << endl; break;
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


//---------------------------------------------------------------------------------








    void Interfaz::ingresoDatosGenerales()
    {
		char seguir, sexo; 
        int opcion, numeroCelular, telefono, cantidadEspecialidades= 0, cantidadClientes =0;
        string cedula, nombre, correo, fechaNacimiento, fechaInscripcion, especialidad[8], nombreSucursal="", nombreInstructor;
        ColeccionInstructores* coleccionInstructores = new ColeccionInstructores(20);
        Sucursal* s, * m, * k;
        ColeccionClientes* coleccionClientes = NULL;
        Cliente* cli = nullptr;
        Instructor* nuevoInstructor;
        ColeccionSucursal* coleccionSucursales = new ColeccionSucursal(30);

		do {
			cout << "\n--- INGRESO DE DATOS GENERALES ---" << endl;
			cout << "1. Ingreso de sucursales" << endl;
            cout << "2. Ingreso de instructores (asociar sucursal)" << endl;
			cout << "3. Ingreso de clientes (asociar sucursal)" << endl;
			cout << "0. Volver" << endl;
			cout << "Seleccione una opcion: ";
			cin >> opcion;
			switch (opcion) {
			case 1:
				do {
					system("cls");

     //               string codigo, nombre, canton, provincia, telefono, correoElectronico;
					//int capacidadClientes,capacidadInstructores;
					//cout << "Ingrese el codigo de la sucursal: ";
					//cin >> codigo;
					//cout << "Ingrese el nombre de la sucursal: ";
					//cin >> nombre;
					//cout << "Ingrese el canton de la sucursal: ";
					//cin >> canton;
					//cout << "Ingrese la provincia de la sucursal: ";
					//cin >> provincia;
					//cout << "Ingrese el telefono de la sucursal: ";
					//cin >> telefono;
					//cout << "Cual es la capacidad maxima de instructores de la sucursal: ";
					//cin >> capacidadInstructores;
					//cout << "Cual es la capacidad maxima de clientes de la sucursal: ";
					//cin >> capacidadClientes;
					//// crear la sucursal con los datos ingresados por el usuario
     //               s = new Sucursal(codigo, provincia, canton, correoElectronico, telefono, capacidadClientes, capacidadInstructores);

					s = new Sucursal("123", "Pichincha", "Quito", "correo@sucursalA.com", "555-1234", 100, 10);
					m = new Sucursal("456", "Guayas", "Guayaquil", "correo@sucursalB.com", "555-5678", 200, 20);
					k = new Sucursal("789", "Azuay", "Cuenca", "correo@sucursalC.com", "555-9012", 150, 15);

					// insertar la sucursal en el contenedor
					coleccionSucursales->insertarAlFinal(k);
					coleccionSucursales->insertarAlFinal(m);

                    if (coleccionSucursales->insertarAlFinal(s)) {
						cout << "Sucursal agregada exitosamente!" << endl;
					}
					// muestra que se este llenando el contenedor
					cout << "Desea ingresar otra sucursal? (s/n): ";
					cin >> seguir;

					if (seguir != 's' && seguir != 'S') {
						break;
					}



				} while (true);
				//muestra que se este llenando el contenidor por consola 
                //comprobacion rapida de que se llena el contenedor

				cout << "Sucursales actuales: " << coleccionSucursales->toString() << endl;




				break;
			case 2: 
                do {
                    
                   /* cout << "Ingrese la cedula del instructor: ";
                    cin >> cedula;
                    cout << "Ingrese el nombre del instructor: ";
                    cin >> nombre;
                    cout << "Ingrese el telefono del instructor: ";
                    cin >> telefono;
                    cout << "Ingrese la fecha de nacimiento del instructor (DD/MM/AAAA): ";
                    cin >> fechaNacimiento;
                    cout << "Ingrese el correo electronico del instructor: ";
                    cin >> correo;
                    cout << "Ingrese la cantidad de especialidades del instructor (maximo 8): ";
                    cin >> cantidadEspecialidades;
                    while(cantidadEspecialidades>8){
                        cout<<"Sobrepasa la cantidad permitida MAX=8"<<endl; 
						cin >> cantidadEspecialidades;
                    }
					cout << "Ingrese la cantidad de clientes que tendra a cargo el instructor: ";  
					cin >> cantidadClientes;
				*/
				// se debe nombrar la misma cantidad que el numero de especialidades que va a tener el instructor 
					cantidadEspecialidades = 2;
              
					//
					//crossFit, HIIT, TRX , pesas, spinning , cardio, yoga, zumba , estas son las especialides posibles
					//muestrelas al usuario

					// especialidades posibles
					string especialidadesPosibles[8] = { "CrossFit", "HIIT", "TRX", "Pesas", "Spinning", "Cardio", "Yoga", "Zumba" };
                    
					cout << "Especialidades posibles: " << endl;
                    for (int i = 0; i < 8; i++) {
                        cout << i + 1 << ". " << especialidadesPosibles[i] << endl;
					}
					//ingrese las especialidades del instructor


					cout << "Ingrese las especialidades del instructor: " << endl;
					for (int i = 0; i < cantidadEspecialidades; i++) {
						cout << "Especialidad " << (i + 1) << ": ";
						cin >> especialidad[i];
					}			

		
                    
					//Instructor* nuevoInstructor = new Instructor(cedula,nombre,telefono,fechaNacimiento,correo,especialidad,cantidadClientes,cantidadEspecialidades);*/
					//cout << "ingrese el nombre de la sucursal a la que quiere asociar el Instructor: " << coleccionSucursales->toString() << endl;
     //               
					//cin >> nombreSucursal;
					nombreSucursal = "123";
					nuevoInstructor = new Instructor("123456789", "Juan Perez", 5551234, "01/01/1980", "juan.perez@example.com", especialidad, 10, cantidadEspecialidades);

					
					if(s = coleccionSucursales->buscarSucursal(nombreSucursal))
                    {
                        cout << "Sucursal encontrada: " << s->getNombre() << endl;
                    } else {
                        cout << "Sucursal no encontrada. Asegurese de ingresar un nombre valido." << endl;
						continue; // Volver al inicio del bucle para intentar de nuevo
                    }

					s->agregarInstructorXSucursal(nuevoInstructor);
				
				
				
// Mostrar instructores de ESA sucursal:
cout << "Instructores en la sucursal " << s->getNombre() << ":\n"
     << s->getColeccionInstructores()->toString() << endl;
                   
                    cout << "Desea ingresar otro instructor? (s/n): ";
                    cin >> seguir;
                    if (seguir != 's' && seguir != 'S') {
                        break;
                    }

                } while (true);

				

				break;

                case 3: 
         
                do {
                  
               


                    cout << "Ingrese la cedula del cliente: ";
                    cin >> cedula;
                    cout << "Ingrese el nombre del cliente: ";
                    cin >> nombre;
                    cout << "Ingrese el correo electronico del cliente: ";
                    cin >> correo;
                    cout << "Ingrese la fecha de nacimiento del cliente (DD/MM/AAAA): ";
                    cin >> fechaNacimiento;
                    cout << "Ingrese la fecha de inscripcion del cliente (DD/MM/AAAA): ";
                    cin >> fechaInscripcion;
                    cout << "Ingrese el numero de celular del cliente: ";
                    cin >> numeroCelular;
                    cout << "Ingrese el sexo del cliente (M/F): ";
                    cin >> sexo;
                
					Cliente* cli = new Cliente(cedula, nombre, correo, fechaInscripcion, fechaNacimiento, numeroCelular, sexo);
					cout << "ingrese el nombre de la sucursal a la que quiere asociar el cliente: " << coleccionSucursales->toString() << endl;
					cin >> nombreSucursal;

					s = coleccionSucursales->buscarSucursal(nombreSucursal);// Poner Atencion BRR
                    s->agregarClienteXSucursal(cli);
                    //nuevoInstructor = 

					cout << "Ingrese el nombre del instructor que tendra a cargo el cliente: " << s->getColeccionInstructores()->toString() << endl;
                    cin >> nombreInstructor;

					s->getColeccionInstructores()->buscarInstructor(nombreInstructor)->getClientes()->insertarAlFinal(cli);
                        cout << "Cliente agregado exitosamente!" << endl;
                    
                    cout << "Desea ingresar otro cliente? (s/n): ";
                    cin >> seguir;
                } while (seguir == 's' || seguir == 'S');
                break;
			case 0: break;
			default: cout << "Opcion invalida!" << endl;
			}
		    } while (opcion != 0);


    }
   