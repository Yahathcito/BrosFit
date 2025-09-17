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
		int opcion, numeroCelular, telefono=0, cantidadEspecialidades = 0, cantidadClientes = 0 ;
        string cedula, nombre, correo, fechaNacimiento, fechaInscripcion, especialidad[8], codigoSucu, nombreInstructor,nombreSucursal  ;
        ColeccionInstructores* coleccionInstructores = new ColeccionInstructores(20);
        Sucursal* s, * m, * k;
        ColeccionClientes* coleccionClientes = NULL;
        Cliente* cli = nullptr;
		Instructor* nuevoInstructor = nullptr;
        ColeccionSucursal* coleccionSucursales = new ColeccionSucursal(30);

		do {
			system("cls");

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

					s = new Sucursal("123", "Quito", "Pichincha", "correo@sucursalA.com", "555-1234", 100, 10);
					//m = new Sucursal("456", "Guayaquil", "Guayas", "correo@sucursalB.com", "555-5678", 200, 20);
					//k = new Sucursal("789", "Cuenca", "Azuay", "correo@sucursalC.com", "555-9012", 150, 15);

					// insertar la sucursal en el contenedor
		/*			coleccionSucursales->insertarAlFinal(k);
					coleccionSucursales->insertarAlFinal(m);*/

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
					system("cls");
                    
                    cout << "Ingrese la cedula del instructor: ";
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
				
				
              
					

					// especialidades posibles
					string especialidadesPosibles[8] = { "CrossFit", "HIIT", "TRX", "Pesas", "Spinning", "Cardio", "Yoga", "Zumba" };
                    
					cout << "Especialidades posibles: " << endl;
                    for (int i = 0; i < 8; i++) {
                        cout << i + 1 << ". " << especialidadesPosibles[i] << endl;
					}

					//ingrese las especialidades del instructor

                    for (int i = 0; i < cantidadEspecialidades; i++) {
                        int opcionEspecialidad;
                        cout << "Ingrese el numero de la especialidad " << i + 1 << ": ";
                        cin >> opcionEspecialidad;
                        while (opcionEspecialidad < 1 || opcionEspecialidad > 8) {
                            cout << "Opcion invalida. Ingrese un numero entre 1 y 8: ";
                            cin >> opcionEspecialidad;
                        }
                        especialidad[i] = especialidadesPosibles[opcionEspecialidad - 1];
					}
						
					system("cls");
		
                    
					Instructor* nuevoInstructor = new Instructor(cedula,nombre,telefono,fechaNacimiento,correo,especialidad,cantidadClientes,cantidadEspecialidades);
                    cout << "ingrese el nombre de la sucursal a la que quiere asociar el Instructor: " << endl<<endl;
                    cout<<"Esta es la lista de las sucursales disponibles" <<endl<<endl<<
                    coleccionSucursales->toString() << endl;
                    cin >> codigoSucu;

					if(s = coleccionSucursales->buscarSucursal(codigoSucu))
                    {
                        cout << "Sucursal encontrada, codigo: " << s->getCodigo() << endl;
                    } else {
                        cout << "Sucursal no encontrada. Asegurese de ingresar un nombre valido." << endl;
						continue; // Volver al inicio del bucle para intentar de nuevo
                    }
					

					s->agregarInstructorXSucursal(nuevoInstructor);
				
				
				


                  
                   
                    cout << "Desea ingresar otro instructor? (s/n): ";
                    cin >> seguir;
                    if (seguir != 's' && seguir != 'S') {
						
						break;

					}
                    

                } while (true);

                system("cls");
                cout << "Instructores en la sucursal con el codigo " << s->getCodigo() << ":\n"
                    << s->getColeccionInstructores()->toString() << endl;//se mostra que se llena el contenedor
                system("pause");

                break;

                case 3: 
         
                do {

                /*     cout << "Ingrese la cedula del cliente: ";
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
                
					Cliente* cli = new Cliente(cedula, nombre, correo, fechaInscripcion, fechaNacimiento, numeroCelular, sexo);*/
					Cliente* cli = new Cliente("0912345678", "Maria Gomez", "gagaga@hah", "01/01/2023", "20/05/1990", 987, 'F');
					// Mostrar sucursales disponibles para asociar el cliente
				    cout << "Sucursales disponibles para asociar:" <<endl; 
                    cout << coleccionSucursales->toString() << endl;
                    cout << "Digite el codigo de sucursal a asociar:";cin>>codigoSucu;
					s = coleccionSucursales->buscarSucursal(codigoSucu);
                    s->agregarClienteXSucursal(cli);

                    cout<<"Instructores de la sucursal "<<codigoSucu<<": "<<endl; cout<< s->getColeccionInstructores()->toString() << endl;
                    cout<<"Digite la cedula del instructor deseado: "; cin >> cedula;

					s->getColeccionInstructores()->buscarInstructor(cedula)->getClientes()->insertarAlFinal(cli);
                        cout << "Cliente agregado exitosamente!" << endl;
                    
                    cout << "Desea ingresar otro cliente? (s/n): ";
                    cin >> seguir;
                } while (seguir == 's' || seguir == 'S');

				//comprobacion rapida de que se crea el cliente
				cout << "Clientes actuales en la sucursal " << s->getCodigo() << ": " << s->getClientes()->listarClientes() << endl;

                break;
				
			case 0: break;
			default: cout << "Opcion invalida!" << endl;
			}
		    } while (opcion != 0);


    }
   