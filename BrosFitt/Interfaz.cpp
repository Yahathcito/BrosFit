#include "Interfaz.h"


ColeccionSucursal* Interfaz::coleccionSucursales = nullptr;
ColeccionClientes* Interfaz::coleccionClientes = nullptr;
ColeccionInstructores* Interfaz::coleccionInstructores = nullptr;
ColeccionMediciones* Interfaz::coleccionMediciones = nullptr;

void Interfaz::menu() {
    if (!coleccionSucursales) {
        coleccionSucursales = new ColeccionSucursal(30);
    }
    if (!coleccionClientes)
    {
        coleccionClientes = new ColeccionClientes(100);
    }
	if (!coleccionInstructores)
	{
		coleccionInstructores = new ColeccionInstructores(100);
	}
	if (!coleccionMediciones)
	{
		coleccionMediciones = new ColeccionMediciones(100);
	}


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
				subMenuIngresoDatosGenerales();
                break;
            case 2:
				subMenuInformeDeClientes();
                break;
            case 3: 
                subMenuInformeDeInstructores();
                break;
            case 4: 
				subMenuHistorialDeMediciones();
                break;
            case 5: 
				subMenuReporteIMC();
                break;
            case 6: 
				subMenuRutinas();
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


        void Interfaz::subMenuIngresoDatosGenerales() {

		char seguir, sexo;
		int opcion, numeroCelular, telefono = 0, cantidadEspecialidades = 0, cantidadClientes = 0;
		string cedula, nombre, correo, fechaNacimiento, fechaInscripcion, especialidad[8], codigoSucu, nombreInstructor, nombreSucursal;
		Sucursal* s = NULL, * m, * k;

		Cliente* cli = nullptr;
		Instructor* nuevoInstructor = nullptr;
       

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



					//compruebe que exista al menos una sucursal antes de agregar un instructor
					if (!coleccionSucursales || coleccionSucursales->getCantidad() == 0) {
						cout << "No hay sucursales disponibles. Por favor, ingrese una sucursal primero." << endl;
						system("pause");
						break; // Salir del bucle do-while y volver al menú principal
					}

                    
                 /*   cout << "Ingrese la cedula del instructor: ";
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
					cin >> cantidadClientes;*/
				
				
              
					
					cantidadEspecialidades = 1;
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
		
                    
					//Instructor* nuevoInstructor = new Instructor(cedula,nombre,telefono,fechaNacimiento,correo,especialidad,cantidadClientes,cantidadEspecialidades);
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
					nuevoInstructor = new Instructor("111", "Juan Perez", 123, "15/03/1985", "juanperez@hah", especialidad, cantidadEspecialidades, cantidadClientes);

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
						//compruebe que exista al menos una sucursal y un instructor antes de agregar un cliente
      //                  if (!coleccionSucursales || coleccionSucursales->getCantidad() == 0) {
      //                      cout << "No hay sucursales disponibles. Por favor, ingrese una sucursal primero." << endl;
      //                      system("pause");
      //                      break; // Salir del bucle do-while y volver al menú principal
						//}
						////verificar que la sucursal tenga instructores
						//cout << "Sucursales disponibles:" << endl;
						//cout << coleccionSucursales->toString() << endl;
						//cout << "Digite el codigo de sucursal para verificar instructores:"; cin >> codigoSucu;
						//s = coleccionSucursales->buscarSucursal(codigoSucu);
      //                  if (!s || !s->getColeccionInstructores() || s->getColeccionInstructores()->getCantidad() == 0) {
      //                      cout << "No hay instructores disponibles en esta sucursal. Por favor, ingrese un instructor primero." << endl;
      //                      system("pause");
      //                      break; // Salir del bucle do-while y volver al menú principal
						//}





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
						Cliente* cli = new Cliente("12345", "Maria Gomez", "gagaga@hah", "01/01/2023", "20/05/1990", 987, 'F');
						// Mostrar sucursales disponibles para asociar el cliente
						cout << "Sucursales disponibles para asociar:" << endl;
						cout << coleccionSucursales->toString() << endl;
						cout << "Digite el codigo de sucursal a asociar:"; cin >> codigoSucu;
						s = coleccionSucursales->buscarSucursal(codigoSucu);
						s->agregarClienteXSucursal(cli);

						cout << "Instructores de la sucursal " << codigoSucu << ": " << endl; cout << s->getColeccionInstructores()->toString() << endl;
						cout << "Digite la cedula del instructor deseado: "; cin >> cedula;

						nuevoInstructor = s->getColeccionInstructores()->buscarInstructor(cedula);
						nuevoInstructor->getClientes()->insertarAlFinal(cli);

						cout << "Desea ingresar otro cliente? (s/n): ";
						cin >> seguir;
					} while (seguir == 's' || seguir == 'S');
					system("cls");
					//comprobacion rapida de que se crea el cliente
					cout << "Clientes actuales a cargo del instructor : " << nuevoInstructor->getNombre() << endl;
					cout << nuevoInstructor->getClientes()->toString() << endl;
					cout << "Clientes actuales en la sucursal " << s->getCodigo() << ": " << endl;
					cout << s->getClientes()->toString() << endl;
					system("pause");
					break;
				
			case 0: 
                system("cls");
                break;
			default: cout << "Opcion invalida!" << endl;
			}
		    } while (opcion != 0);


    }
   

        void Interfaz::subMenuInformeDeClientes() {
        system("cls");
        if (!coleccionSucursales || coleccionSucursales->getCantidad() == 0) {
            cout << "No hay sucursales cargadas.\n";
            return;
        }
        int opcion;
        do {
            cout << "\n--- INFORMES DE CLIENTES ---\n"
                << "1. Lista de clientes por sucursal\n"
                << "2. Detalle de un cliente especifico\n"
                << "3. Lista de clientes por instructor\n"
                << "0. Volver\n"
                << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
            case 1: {
                cout << "Sucursales disponibles:\n" << coleccionSucursales->toString() << endl;
                string codigo;
                cout << "Digite el codigo de la sucursal: ";
                cin >> codigo;
                Sucursal* suc = coleccionSucursales->buscarSucursal(codigo);
                if (!suc) {
                    cout << "Sucursal no encontrada.\n";
                    break;
                }
                coleccionClientes = suc->getClientes();
                if (!coleccionClientes || coleccionClientes->getCantidad() == 0) {
                    cout << "No hay clientes en esta sucursal.\n";
                }
                else {
                    cout << "Clientes de la sucursal " << codigo << ":\n"
                        << coleccionClientes->listarClientes() << endl;
                }
                system("pause");
                break;
            }
          
            case 2: {
                cout << "=== Buscar cliente por cedula ===\n";
                string cedBuscada;
                cout << "Cedula del cliente: ";
                cin >> cedBuscada;

                Cliente* encontrado = nullptr;
                Sucursal* sucDondeEsta = nullptr;
                Instructor* instructorAsignado = nullptr;

                for (int i = 0; i < coleccionSucursales->getCantidad() && !encontrado; ++i) {
                    Sucursal* suc = coleccionSucursales->getPorIndice(i);
                    if (!suc || !suc->getClientes()) continue;

                    encontrado = suc->getClientes()->buscarCliente(cedBuscada);
                    if (encontrado) {
                        sucDondeEsta = suc;
                        ColeccionInstructores* ci = suc->getColeccionInstructores();
                        if (ci) {
                            for (int j = 0; j < ci->getCantidad() && !instructorAsignado; ++j) {
                                Instructor* ins = ci->getPorIndice(j);
                                if (ins && ins->getClientes()
                                    && ins->getClientes()->buscarCliente(cedBuscada)) {
                                    instructorAsignado = ins;
                                }
                            }
                        }
                    }
                }

                if (!encontrado) {
                    cout << "Cliente no encontrado.\n";
                }
                else {
                    cout << "\n--- Detalle Cliente ---\n";
                    cout << encontrado->toString();
                    cout << "Sucursal: " << (sucDondeEsta ? sucDondeEsta->getCodigo() : "(?)") << "\n";
                    if (instructorAsignado) {
                        cout << "Instructor asignado: "
                            << instructorAsignado->getCedula() << " - "
                            << instructorAsignado->getNombre() << "\n";
                    }
                    else {
                        cout << "Instructor asignado: (ninguno)\n";
                    }
                }
                system("pause");
                break;
            }
            case 3: {
                // ocupo listar clientes por instructor especifico
                cout << "=== Listar clientes por instructor ===\n";
                string cedulaInstructor;
                cout << "Cedula del instructor: ";
                cin >> cedulaInstructor;
                Instructor* instrEncontrado = nullptr;
                for (int i = 0; i < coleccionSucursales->getCantidad() && !instrEncontrado; ++i) {
                    Sucursal* suc = coleccionSucursales->getPorIndice(i);
                    if (!suc || !suc->getColeccionInstructores()) continue;
                    instrEncontrado = suc->getColeccionInstructores()->buscarInstructor(cedulaInstructor);
                }
                if (!instrEncontrado) {
                    cout << "Instructor no encontrado.\n";
                }
                else {
                    ColeccionClientes* clientesDelInstructor = instrEncontrado->getClientes();
                    if (!clientesDelInstructor || clientesDelInstructor->getCantidad() == 0) {
                        cout << "El instructor no tiene clientes asignados.\n";
                    }
                    else {
                        cout << "Clientes del instructor " << instrEncontrado->getNombre() << ":\n"
                            << clientesDelInstructor->listarClientes() << endl;
                    }
                }
            }
                system("pause");
                break;
            case 0: break;
            default: cout << "Opcion invalida!\n";
            }
            } while (opcion != 0);
        }


		void Interfaz::subMenuInformeDeInstructores() {
            system("cls");
            if (!coleccionSucursales || coleccionSucursales->getCantidad() == 0) {
                cout << "No hay sucursales cargadas.\n";
                return;
            }
            int opcion;
            do {
                cout << "\n--- INFORMES DE INSTRUCTORES ---\n"
                    << "1. Lista de instructores por sucursal\n"
                    << "2. Lista de instructores por especialidad\n"
                    << "0. Volver\n"
                    << "Seleccione una opcion: ";
                cin >> opcion;
                switch (opcion) {
                case 1: {
                    cout << "Sucursales disponibles:\n" << coleccionSucursales->toString() << endl;
                    string codigo;
                    cout << "Digite el codigo de la sucursal: ";
                    cin >> codigo;
                    Sucursal* suc = coleccionSucursales->buscarSucursal(codigo);
                    if (!suc) {
                        cout << "Sucursal no encontrada.\n";
                        break;
                    }
                    ColeccionInstructores* coleccionInstructores = suc->getColeccionInstructores();
                    if (!coleccionInstructores || coleccionInstructores->getCantidad() == 0) {
                        cout << "No hay instructores en esta sucursal.\n";
                    }
                    else {
                        cout << "Instructores de la sucursal " << codigo << ":\n"
                            << coleccionInstructores->listarInstructores() << endl;
                    }
                    system("pause");
                    break;
                }
                      // SOLO SE MUESTRA LA PARTE MODIFICADA DEL case 2 EN informeDeClientes
                  // SOLO SE MUESTRA LA PARTE MODIFICADA DEL case 2 EN informeDeClientes
                case 2: {
                    // debe haber al menos un instructor ingresado para que no se pidan los datos cuando no hay instructores
                    cout << "=== Buscar instructores por especialidad ===\n";
                    int opcionEspecialidad;
                    string especialidadesPosibles[8] = { "CrossFit", "HIIT", "TRX", "Pesas", "Spinning", "Cardio", "Yoga", "Zumba" };
                    cout << "Especialidades posibles: " << endl;
					
                    for (int i = 0; i < 8; i++) {
                        cout << i + 1 << ". " << especialidadesPosibles[i] << endl;
					}
                    cout << "Ingrese el numero de la especialidad a buscar: ";
                    cin >> opcionEspecialidad;
                    while (opcionEspecialidad < 1 || opcionEspecialidad > 8) {
                        cout << "Opcion invalida. Ingrese un numero entre 1 y 8: ";
                        cin >> opcionEspecialidad;
                    }
                    string especialidadBuscada = especialidadesPosibles[opcionEspecialidad - 1];
                    ColeccionInstructores* instructoresConEspecialidad = new ColeccionInstructores(100);
                    for (int i = 0; i < coleccionSucursales->getCantidad(); ++i) {
                        Sucursal* suc = coleccionSucursales->getPorIndice(i);
                        if (!suc || !suc->getColeccionInstructores()) continue;
                        ColeccionInstructores* ci = suc->getColeccionInstructores();
                        for (int j = 0; j < ci->getCantidad(); ++j) {
                            Instructor* ins = ci->getPorIndice(j);
                            if (ins) {
                                for (int k = 0; k < ins->getCantEspecialidades(); ++k) {
                                    if (ins->getEspecialidades()[k] == especialidadBuscada) {
                                        instructoresConEspecialidad->insertarAlFinal(ins);
                                        break; // Evitar agregar el mismo instructor varias veces
                                    }
                                }
                            }
                        }
                    }
                    if (instructoresConEspecialidad->getCantidad() == 0) {
                        cout << "No se encontraron instructores con la especialidad " << especialidadBuscada << ".\n";
                    }
                    else {
                        cout << "Instructores con la especialidad " << especialidadBuscada << ":\n"
                            << instructoresConEspecialidad->listarInstructores() << endl;
                    }
                    delete instructoresConEspecialidad; // Liberar memoria
                }
                    system("pause");
                    break;
                case 0: break;
                default: cout << "Opcion invalida!\n";
                }
                } while (opcion != 0);
		}

   
        void Interfaz::subMenuHistorialDeMediciones() {
            system("cls");
            if (!coleccionSucursales || coleccionSucursales->getCantidad() == 0) {
                cout << "No hay sucursales cargadas.\n";
                return;
            }
            int opcion;
            do {
                cout << "\n--- HISTORIAL DE MEDICIONES ---\n"
                    << "1. Ingresar registro de medicion a un cliente\n"
                    << "2. Mostrar historial de mediciones de un cliente\n"
                    << "0. Volver\n"
                    << "Seleccione una opcion: ";
                cin >> opcion;

                switch (opcion) {
                case 1: {
                    cout << "=== Ingresar medicion a cliente ===\n";
                    string cedulaCliente;
                    cout << "Cedula del cliente: ";
                    cin >> cedulaCliente;

                    Cliente* cliEncontrado = nullptr;
                    Sucursal* sucDondeEsta = nullptr;
                    Instructor* instructorAsignado = nullptr;

                    if (!coleccionSucursales || coleccionSucursales->getCantidad() == 0) {
                        cout << "No hay sucursales registradas.\n";
                        break;
                    }

                    // Buscar cliente en las sucursales
                    for (int i = 0; i < coleccionSucursales->getCantidad() && !cliEncontrado; ++i) {
                        Sucursal* suc = coleccionSucursales->getPorIndice(i);
                        if (!suc) continue;
                        if (!suc->getClientes()) continue;

                        cliEncontrado = suc->getClientes()->buscarCliente(cedulaCliente);
                        if (cliEncontrado) {
                            sucDondeEsta = suc;
                            ColeccionInstructores* ci = suc->getColeccionInstructores();
                            if (!ci || ci->getCantidad() == 0) continue;

                            for (int j = 0; j < ci->getCantidad() && !instructorAsignado; ++j) {
                                Instructor* ins = ci->getPorIndice(j);
                                if (!ins) continue;
                                if (!ins->getClientes()) continue;
                                if (ins->getClientes()->buscarCliente(cedulaCliente)) {
                                    instructorAsignado = ins;
                                }
                            }
                        }
                    }

                    if (!cliEncontrado) {
                        cout << "Cliente no encontrado.\n";
                        break;
                    }
                    if (!instructorAsignado) {
                        cout << "El cliente no tiene un instructor asignado.\n";
                        break;
                    }

                    cout << "Cliente encontrado y con instructor asignado.\n";
                    cout << "Sucursal: " << sucDondeEsta->getCodigo() << endl;
                    cout << "Instructor: " << instructorAsignado->getNombre() << endl;

                    Medicion* nuevaMedicion = new Medicion(cliEncontrado->getCedula(),
                        "15/06/2024", instructorAsignado->getNombre(), 70.5, 1.75,
                        15.0, 40.0, 30,
                        10, 80.0, 95.0,
                        100.0, 50.0);

                    if (!cliEncontrado->getHistorialMediciones()) {
                        cliEncontrado->setHistorialMediciones(new ColeccionMediciones(10));
                    }

                    if (cliEncontrado->getHistorialMediciones()->agregarMedicion(nuevaMedicion)) {
                        cout << "Medicion agregada exitosamente al historial del cliente.\n";
                    }
                    else {
                        cout << "No se pudo agregar la medicion. El historial puede estar lleno.\n";
                        delete nuevaMedicion;
                    }

                    system("pause");
                    break;
                }

                case 2: {
                    cout << "=== Mostrar historial de mediciones de un cliente ===\n";
                    string cedulaCliente;
                    cout << "Cedula del cliente: ";
                    cin >> cedulaCliente;

                    Cliente* cliEncontrado = nullptr;
                    Sucursal* sucDondeEsta = nullptr;
                    Instructor* instructorAsignado = nullptr;

                    if (!coleccionSucursales || coleccionSucursales->getCantidad() == 0) {
                        cout << "No hay sucursales registradas.\n";
                        break;
                    }

                    for (int i = 0; i < coleccionSucursales->getCantidad() && !cliEncontrado; ++i) {
                        Sucursal* suc = coleccionSucursales->getPorIndice(i);
                        if (!suc) continue;
                        if (!suc->getClientes()) continue;

                        cliEncontrado = suc->getClientes()->buscarCliente(cedulaCliente);
                        if (cliEncontrado) {
                            sucDondeEsta = suc;
                            ColeccionInstructores* ci = suc->getColeccionInstructores();
                            if (!ci || ci->getCantidad() == 0) continue;

                            for (int j = 0; j < ci->getCantidad() && !instructorAsignado; ++j) {
                                Instructor* ins = ci->getPorIndice(j);
                                if (!ins) continue;
                                if (!ins->getClientes()) continue;
                                if (ins->getClientes()->buscarCliente(cedulaCliente)) {
                                    instructorAsignado = ins;
                                }
                            }
                        }
                    }

                    if (!cliEncontrado) {
                        cout << "Cliente no encontrado.\n";
                        break;
                    }
                    if (!instructorAsignado) {
                        cout << "El cliente no tiene un instructor asignado.\n";
                        break;
                    }

                    cout << "Cliente encontrado y con instructor asignado.\n";
                    cout << "Sucursal: " << sucDondeEsta->getCodigo() << endl;
                    cout << "Instructor: " << instructorAsignado->getNombre() << endl;

                    ColeccionMediciones* historial = cliEncontrado->getHistorialMediciones();
                    if (!historial || historial->getCantidad() == 0) {
                        cout << "El cliente no tiene mediciones registradas.\n";
                    }
                    else {
                        cout << "Historial de mediciones del cliente " << cliEncontrado->getNombre() << ":\n";
                        for (int i = 0; i < historial->getCantidad(); ++i) {
                            Medicion* med = historial->getPorIndice(i);
                            if (med) {
                                cout << i + 1 << ". Fecha: " << med->getFechaMedicion()
                                    << ", Peso: " << med->getPeso() << " kg"
                                    << ", Estatura: " << med->getEstatura() << " m"
                                    << ", % Grasa: " << med->getPorcentajeGrasa() << "%"
                                    << ", % Musculo: " << med->getPorcentajeMusculo() << "%\n";
                            }
                        }
                        int opcionDetalle;
                        cout << "Ingrese el numero de la medicion para ver detalles, o 0 para salir: ";
                        cin >> opcionDetalle;
                        if (opcionDetalle > 0 && opcionDetalle <= historial->getCantidad()) {
                            Medicion* medDetallada = historial->getPorIndice(opcionDetalle - 1);
                            if (medDetallada) {
                                cout << "\n--- Detalle de la Medicion ---\n";
                                cout << medDetallada->toString() << endl;
                            }
                        }
                    }

                    system("pause");
                    break;
                }

                case 0:
                    break;

                default:
                    cout << "Opcion invalida!\n";
                    system("pause");
                    break;
                }

            } while (opcion != 0);
        }

        
		void Interfaz::subMenuReporteIMC() {
           // no uses mapas
        
            system("cls");
            if (!coleccionSucursales || coleccionSucursales->getCantidad() == 0) {
                cout << "No hay sucursales cargadas.\n";
                return;
            }
            int opcion;
            do {
                cout << "\n--- REPORTE DE IMC ---\n"
                    << "1. Generar reporte de IMC por sucursal\n"
                    << "0. Volver\n"
                    << "Seleccione una opcion: ";
                cin >> opcion;
                switch (opcion) {
                case 1: {
                    cout << "Sucursales disponibles:\n" << coleccionSucursales->toString() << endl;
                    string codigo;
                    cout << "Digite el codigo de la sucursal: ";
                    cin >> codigo;
                    Sucursal* suc = coleccionSucursales->buscarSucursal(codigo);
                    if (!suc) {
                        cout << "Sucursal no encontrada.\n";
                        break;
                    }
                    ColeccionClientes* coleccionClientes = suc->getClientes();
                    if (!coleccionClientes || coleccionClientes->getCantidad() == 0) {
                        cout << "No hay clientes en esta sucursal.\n";
                        break;
                    }
                    // Inicializar contadores y listas para cada categoria
                    int conteos[8] = { 0 }; // 8 categorias
                    string listas[8] = { "", "", "", "", "", "", "", "" };
                    for (int i = 0; i < coleccionClientes->getCantidad(); ++i) {
                        Cliente* cli = coleccionClientes->getClientesxIndice(i);//
						// que devuelve un puntero a cliente
                        if (!cli || !cli->getHistorialMediciones() || cli->getHistorialMediciones()->getCantidad() == 0) continue;
                        Medicion* ultimaMedicion = cli->getHistorialMediciones()->getPorIndice(cli->getHistorialMediciones()->getCantidad() - 1);
                        if (!ultimaMedicion) continue;
                        float imc = ultimaMedicion->getIMC();
                        int categoria = -1;
                        if (imc < 16.00) categoria = 0; // Delgadez severa
                        else if (imc >= 16.01 && imc <= 16.99) categoria = 1; // Delgadez moderada
                        else if (imc >= 17.00 && imc <= 18.49) categoria = 2; // Delgadez leve
                        else if (imc >= 18.50 && imc <= 24.99) categoria = 3; // Normal
                        else if (imc >= 25.00 && imc <= 29.99) categoria = 4; // Pre-obesidad
                        else if (imc >= 30.00 && imc <= 34.99) categoria = 5; // Obesidad leve
                        else if (imc >= 35.00 && imc <= 39.99) categoria = 6; // Obesidad media
						else if (imc >= 40.00) categoria = 7; // Obesidad morbida
                        if (categoria != -1) {
                            conteos[categoria]++;
                            listas[categoria] += cli->getNombre() + " (IMC: " + to_string(imc) + ")\n";
                        }
                    }
                    // Mostrar resultados
                    string categoriasNombres[8] = {
                        "Delgadez severa (<16.00)",
                        "Delgadez moderada (16.01-16.99)",
                        "Delgadez leve (17.00-18.49)",
                        "Normal (18.5-24.99)",
                        "Pre-obesidad (25.00-29.99)",
                        "Obesidad leve (30.00-34.99)",
                        "Obesidad media (35.00-39.99)",
                        "Obesidad morbida (>=40.00)"
                    };
                    cout << "\n--- Reporte de IMC para la sucursal " << codigo << " ---\n";
                    for (int j = 0; j < 8; ++j) {
                        cout << categoriasNombres[j] << ": " << conteos[j] << " cliente(s)\n";
                        if (conteos[j] > 0) {
                            cout << listas[j];
                        }
                    }
                }
                    system("pause");
                    break;
                case 0: break;
                default: cout << "Opcion invalida!\n";
                }
                } while (opcion != 0);
		}

        /*Rutinas
            − El sistema debe permitir ingresar ejercicios a la “batería de
            ejercicios”. (4 ptos.)
            − El sistema debe permitir la generación de una nueva rutina a un cliente
            especifico(a partir de la “batería de ejercicios”).Se debe poder
            buscar cualquier cliente de cualquier sucursal y mostrar la rutina
            generada. (14 ptos.)
           El sistema además debe permitir que el instructor genere la rutina actual del cliente
a partir de una batería de ejercicios previamente registrados y clasificados en el
sistema. La rutina se divide en ejercicios para las siguientes áreas del cuerpo:
pecho y tríceps, bíceps, piernas y espalda.
Nota: No se guardan rutinas anteriores asignadas al cliente, únicamente se mantiene en el
sistema la rutina actual, la cual puede cambiar en el momento que así lo considere el
instructor.
 
            hazlo por favor 
            */



		