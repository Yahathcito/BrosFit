#include "Interfaz.h"


ColeccionSucursal* Interfaz::coleccionSucursales = nullptr;
ColeccionClientes* Interfaz::coleccionClientes = nullptr;
ColeccionInstructores* Interfaz::coleccionInstructores = nullptr;
ColeccionMediciones* Interfaz::coleccionMediciones = nullptr;
ColeccionEjercicios* Interfaz::coleccionEjercicios = nullptr;
ColeccionRutina* Interfaz::coleccionRutinas = nullptr;

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
    if (!coleccionEjercicios)
    {
        coleccionEjercicios = new ColeccionEjercicios(100);
	}

	if (!coleccionRutinas)
	{
		coleccionRutinas = new ColeccionRutina(100);
	}



        int opcion;

        do {
			system("cls");
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
                
				subMenuMatriculaClasesGrupales();
                
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
                    cout<<"Esta es la lista de las sucursales disponibles" <<endl<<endl<<
                    coleccionSucursales->toString() << endl;
                    cin >> codigoSucu;
                    cout << "ingrese el nombre de la sucursal a la que quiere asociar el Instructor: " << endl << endl;
                    system("cls");
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
						system("cls");
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
						system("cls");
						cout << "Instructores de la sucursal " << codigoSucu << ": " << endl; cout << s->getColeccionInstructores()->toString() << endl;
						cout << "Digite la cedula del instructor deseado: "; cin >> cedula;

						nuevoInstructor = s->getColeccionInstructores()->buscarInstructor(cedula);
						nuevoInstructor->getClientes()->insertarAlFinal(cli);
						system("cls");
						cout << "Cliente agregado exitosamente!" << endl;
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
			system("cls");
            cout << "\n--- INFORMES DE CLIENTES ---\n"
                << "1. Lista de clientes por sucursal\n"
                << "2. Detalle de un cliente especifico\n"
                << "3. Lista de clientes por instructor\n"
                << "0. Volver\n"
                << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
            case 1: {
				system("cls");
                cout << "Sucursales disponibles:\n" << coleccionSucursales->toString() << endl;
                string codigo;
                cout << "Digite el codigo de la sucursal: ";
                cin >> codigo;
                Sucursal* suc = coleccionSucursales->buscarSucursal(codigo);
                if (!suc) {
                    cout << "Sucursal no encontrada.\n";
                    break;
                }
				system("cls");
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
				system("cls");
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
				system("cls");
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
						cout << "------------------------------\n";
                    }
                    else {
                        cout << "Instructor asignado: (ninguno)\n";
                    }
                }
			
                system("pause");
                break;
            }
            case 3: {
				system("cls");
                // ocupo listar clientes por instructor especifico
                cout << "=== Listar clientes por instructor ===\n";
                string cedulaInstructor;
                cout << "Cedula del instructor: ";
                cin >> cedulaInstructor;
                Instructor* instrEncontrado = nullptr;
				system("cls");
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
//--------------------------------------------------------------------------
        
		void Interfaz::subMenuInformeDeInstructores() {
            system("cls");
            if (!coleccionSucursales || coleccionSucursales->getCantidad() == 0) {
                cout << "No hay sucursales cargadas.\n";
                return;
            }
            int opcion;
            do {
				system("cls");
                cout << "\n--- INFORMES DE INSTRUCTORES ---\n"
                    << "1. Lista de instructores por sucursal\n"
                    << "2. Lista de instructores por especialidad\n"
                    << "0. Volver\n"
                    << "Seleccione una opcion: ";
                cin >> opcion;
                switch (opcion) {
                case 1: {
					system("cls");
                    cout << "Sucursales disponibles:\n" << coleccionSucursales->toString() << endl;
                    string codigo;
                    cout << "Digite el codigo de la sucursal: ";
                    cin >> codigo;
                    Sucursal* suc = coleccionSucursales->buscarSucursal(codigo);
                    if (!suc) {
                        cout << "Sucursal no encontrada.\n";
                        break;
                    }
					system("cls");
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
					system("cls");
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
					system("cls");
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
                system("cls");
                cout << "\n--- HISTORIAL DE MEDICIONES ---\n"
                    << "1. Ingresar registro de medicion a un cliente\n"
                    << "2. Mostrar historial de mediciones de un cliente\n"
                    << "0. Volver\n"
                    << "Seleccione una opcion: ";
                cin >> opcion;

                switch (opcion) {
                case 1: {
                    system("cls");
                    cout << "=== Ingresar medicion a cliente ===\n";
                    string cedulaCliente;
                    cout << "Cedula del cliente: ";
                    cin >> cedulaCliente;
                    string fechaMedicion;
                    float peso, estatura, porcentajeGrasa, porcentajeMusculo, porcentajeGrasaVisceral;
                    int edadMetabolica;
                    float cintura, cadera, pecho, pierna;
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
                    system("cls");
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

                    
                    cout << "----------------------------" << endl;
                    cout << "Ingrese la fecha de la medicion (DD/MM/AA): ";
                    cin >> fechaMedicion;
                    cout << "Ingrese el peso con decimales, si no cuenta con decimales coloque .0 (51.0): ";
                    cin >> peso;
                    cout << "Ingrese la estatura en metros con decimales, si no cuenta con decimales coloque .0 (1.70): ";
                    cin >> estatura;
                    cout << "Ingrese el porcentaje de grasa corporal, si no cuenta con decimales coloque .0  (ejemplo 20.5): ";
                    cin >> porcentajeGrasa;
                    cout << "Ingrese el porcentaje de grasa visceral, si no cuenta con decimales coloque .0 (ejemplo 5.0): ";
                    cin >> porcentajeGrasaVisceral;
                    cout << "Ingrese el porcentaje de musculo, si no cuenta con decimales coloque .0 (ejemplo 30.5): ";
                    cin >> porcentajeMusculo;
                    cout << "Ingrese la medida de la cintura en cm con decimales, si no cuenta con decimales coloque .0 (70.0): ";
                    cin >> cintura;
                    cout << "Ingrese la edad metabolica en annios, si no cuenta con decimales coloque .0 (ejemplo 25): ";
                    cin >> edadMetabolica;
                    cout << "Ingrese la medida de la cadera en cm con decimales, si no cuenta con decimales coloque .0 (90.0) : ";
                    cin >> cadera;
                    cout << "Ingrese la medida del pecho en cm con decimales, si no cuenta con decimales coloque .0 (30.0): ";
                    cin >> pecho;
                    cout << "Ingrese la medida del muslo en cm con decimales, si no cuenta con decimales coloque .0 (40.0): ";
                    cin >> pierna;

                    Medicion* nuevaMedicion = new Medicion(cliEncontrado->getCedula(), fechaMedicion, instructorAsignado->getNombre(), peso, estatura, porcentajeGrasa, porcentajeMusculo, edadMetabolica, porcentajeGrasaVisceral, cintura, cadera, pecho, pierna);

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
                    system("cls");
                    cout << "=== Mostrar historial de mediciones de un cliente ===\n";
                    string cedulaCliente;
                    cout << "Cedula del cliente: ";
                    cin >> cedulaCliente;
                    int opcionDetalle;
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
                    system("cls");
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

					system("cls");
                    ColeccionMediciones* historial = cliEncontrado->getHistorialMediciones();
                    if (!historial || historial->getCantidad() == 0) {
                        cout << "El cliente no tiene mediciones registradas.\n";
                    }
                    else {
                        cout << "Historial de mediciones del o la cliente " << cliEncontrado->getNombre() << ":\n";
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
					
                        
                        cout << "Ingrese el numero de la medicion para ver detalles, o 0 para salir: ";
                        cin >> opcionDetalle;
                        if (opcionDetalle > 0 && opcionDetalle <= historial->getCantidad()) {
                            Medicion* medDetallada = historial->getPorIndice(opcionDetalle - 1);
                            if (medDetallada) {
                                cout << "\n--- Detalle de la Medicion ---\n";
                                cout << medDetallada->toString() << endl;
                            }
                        }
                        else if (opcionDetalle != 0) {
                            cout << "Opcion invalida.\n";
                        }
                        cout << "------------------------------\n";
                        cout << "Recomendaciones basadas en la ultima medicion:\n";

                        Medicion* ultimaMedicion = historial->getPorIndice(historial->getCantidad() - 1);
                        if (ultimaMedicion) {
                            float imc = ultimaMedicion->calcularIMC();
                            cout << "IMC: " << imc << " - ";
                            if (imc < 16) {
                                cout << "Delgadez severa. Se recomienda consulta medica urgente.\n";
                                cout << "Consumo de proteinas: " << (ultimaMedicion->getPeso() * 0.8) << " g diarios\n";
                                cout << "Vasos de agua: " << (ultimaMedicion->getPeso() / 7) << " vasos diarios\n";
                            }
                            else if (imc >= 16.01 && imc <= 16.99) {
                                cout << "Delgadez moderada. Se recomienda aumentar la ingesta calorica y consultar a un nutricionista.\n";
                                cout << "Consumo de proteinas: " << (ultimaMedicion->getPeso() * 0.8) << " g diarios\n";
                                cout << "Vasos de agua: " << (ultimaMedicion->getPeso() / 7) << " vasos diarios\n";
                            }
                            else if (imc >= 17.00 && imc <= 18.49) {
                                cout << "Delgadez leve. Se recomienda una dieta equilibrada y ejercicio moderado.\n";
                                cout << "Consumo de proteinas: " << (ultimaMedicion->getPeso() * 0.8) << " g diarios\n";
                                cout << "Vasos de agua: " << (ultimaMedicion->getPeso() / 7) << " vasos diarios\n";

                            }
                            else if (imc >= 18.50 && imc <= 24.99) {
                                cout << "Normal. Mantener habitos saludables.\n";
                                cout << "Consumo de proteinas: " << (ultimaMedicion->getPeso() * 0.8) << " g diarios\n";
                                cout << "Vasos de agua: " << (ultimaMedicion->getPeso() / 7) << " vasos diarios\n";
                            }
                            else if (imc >= 25.00 && imc <= 29.99) {
                                cout << "Pre-obesidad. Se recomienda aumentar la actividad fisica y mejorar la dieta.\n";
                                cout << "Consumo de proteinas: " << (ultimaMedicion->getPeso() * 0.8) << " g diarios\n";
                                cout << "Vasos de agua: " << (ultimaMedicion->getPeso() / 7) << " vasos diarios\n";

                            }
                            else if (imc >= 30.00 && imc <= 34.99) {
                                cout << "Obesidad leve. Consultar a un profesional de la salud para un plan de accion.\n";
                                cout << "Consumo de proteinas: " << (ultimaMedicion->getPeso() * 0.8) << " g diarios\n";
                                cout << "Vasos de agua: " << (ultimaMedicion->getPeso() / 7) << " vasos diarios\n";
                            }
                            else if (imc >= 35.00 && imc <= 39.99) {
                                cout << "Obesidad media. Es importante buscar ayuda medica especializada.\n";
                                cout << "Consumo de proteinas: " << (ultimaMedicion->getPeso() * 0.8) << " g diarios\n";
                                cout << "Vasos de agua: " << (ultimaMedicion->getPeso() / 7) << " vasos diarios\n";
                            }
                            else if (imc >= 40.00) {
                                cout << "Obesidad morbida. Atencion medica urgente requerida.\n";
                                cout << "Consumo de proteinas: " << (ultimaMedicion->getPeso() * 0.8) << " g diarios\n";
                                cout << "Vasos de agua: " << (ultimaMedicion->getPeso() / 7) << " vasos diarios\n";

                            }
                            else {
                                cout << "IMC fuera de rango esperado.\n";
                            }
                        }
                    }
                    system("pause");
                    break;
                }
                case 0: break;
                default: cout << "Opcion invalida!\n";
                }
				} while (opcion != 0);
				}

            void Interfaz::subMenuReporteIMC() {


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
                            cout << ultimaMedicion->toString() << endl;
                            if (!ultimaMedicion) continue;

                            float imc = ultimaMedicion->calcularIMC();

                            int categoria = -1;
                            if (imc < 16) categoria = 0; // Delgadez severa
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
                        system("cls");
                        // Mostrar resultados
                        string categoriasNombres[8] = {
                            "Delgadez severa (<16.00)\n",
                            "Delgadez moderada (16.01-16.99)\n",
                            "Delgadez leve (17.00-18.49)\n",
                            "Normal (18.5-24.99)\n",
                            "Pre-obesidad (25.00-29.99)\n",
                            "Obesidad leve (30.00-34.99)\n",
                            "Obesidad media (35.00-39.99)\n",
                            "Obesidad morbida (>=40.00)\n"
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
        

       


		void Interfaz::subMenuRutinas() {
            system("cls");
            if (!coleccionSucursales || coleccionSucursales->getCantidad() == 0) {
                cout << "No hay sucursales cargadas.\n";
                return;
            }
            int opcion;
            do {
				system("cls");
                cout << "\n--- RUTINAS DE EJERCICIOS ---\n"
                    << "1. Ingresar ejercicio a la bateria de ejercicios\n"
                    << "2. Generar rutina para un cliente\n"
                    << "3. Mostrar rutina de un cliente\n"
                    << "0. Volver\n"
                    << "Seleccione una opcion: ";
                cin >> opcion;
                switch (opcion) {
                case 1: {
					system("cls");
                    //muestra por pantalla las opcionees en un vector para que el usario cree un int
                    cout << "=== Ingresar ejercicio a la bateria de ejercicios ===\n";
                    string nombreEjercicio, areaCuerpo, codigo;
                    int duracion, repeticiones, series;
                    float pesoRecomendado;
                    string areasPosibles[5] = { "Pecho", "Biceps","Triceps", "Piernas", "Espalda"};
                    cout << "Areas del cuerpo posibles: " << endl;
                    for (int i = 0; i < 5; i++) {
                        cout << i + 1 << ". " << areasPosibles[i] << endl;
                    }
                    int opcionArea;
                    cout << "Ingrese el numero del area del cuerpo del ejercicio: ";
                    cin >> opcionArea;
                    while (opcionArea < 1 || opcionArea > 5) {
                        cout << "Opcion invalida. Ingrese un numero entre 1 y 5: ";
                        cin >> opcionArea;
                    }
                    
                    areaCuerpo = areasPosibles[opcionArea - 1];
                    cout << "Ingrese el nombre del ejercicio: ";
                    cin.ignore(); // Limpiar el buffer de entrada
                    getline(cin, nombreEjercicio);

                    cout << "Ingrese el codigo del ejercicio: ";
                    cin >> codigo;
                    if (coleccionEjercicios && coleccionEjercicios->buscarEjercicio(codigo)) {
                        cout << "Ya existe un ejercicio con ese codigo en la bateria. No se puede agregar.\n";
                        system("pause");
                        break;
                    }


                    cout << "Ingrese la duracion del ejercicio (en minutos): ";
                    cin >> duracion;
                    cout << "Ingrese el numero de repeticiones: ";
                    cin >> repeticiones;
                    cout << "Ingrese el numero de series: ";
                    cin >> series;
                    cout << "Ingrese el peso recomendado (45.5): ";
                    cin >> pesoRecomendado;
                    Ejercicio* nuevoEjercicio = new Ejercicio(codigo,nombreEjercicio, areaCuerpo, duracion, repeticiones, series, pesoRecomendado);
				
					system("cls");
                    if (!coleccionEjercicios) {
                        coleccionEjercicios = new ColeccionEjercicios(100);
                    }
                    if (coleccionEjercicios->agregarEjercicio(nuevoEjercicio)) {
                        cout << "Ejercicio agregado exitosamente a la bateria de ejercicios.\n";
                    }
                    else {
                        cout << "No se pudo agregar el ejercicio. La bateria puede estar llena.\n";
                        delete nuevoEjercicio;
                    }
					
					

                    system("pause");
                }
                      break;

				case 2: {
					system("cls");
                    cout << "=== Generar rutina para un cliente ===\n";
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
                    if (!coleccionEjercicios || coleccionEjercicios->getCantidad() == 0) {
                        cout << "No hay ejercicios en la bateria. No se puede generar rutina.\n";
                        break;
                    }
					system("cls"); 
                    cout << "Cliente encontrado y con instructor asignado.\n";
                    cout << "Sucursal: " << sucDondeEsta->getCodigo() << endl;
                    cout << "Instructor: " << instructorAsignado->getNombre() << endl;
					
                    if (!cliEncontrado) {
                        cout << "Error: cliente no encontrado.\n";
                        return;
                    }
                    cout << "Cliente encontrado: " << cliEncontrado->getNombre() << endl;

                

					if (!cliEncontrado->getColeccionRutinaActual()->getRutina()) {
                        cliEncontrado->getColeccionRutinaActual()->setRutinaActual(new Rutina(cedulaCliente));
                    }
                    Rutina* rutina = cliEncontrado->getColeccionRutinaActual()->getRutina();
                    if (!rutina) {
                        cout << "Error: rutina actual no inicializada.\n";
                        return;
                    }
					system("cls");
					cout << "Generando rutina para el cliente " << cliEncontrado->getNombre() << "...\n";
                    rutina->limpiarRutina();
					string areas[5] = { "Pecho", "Biceps","Triceps", "Piernas", "Espalda"};
                    for (const string& area : areas) {
                        cout << "Agregando ejercicios para el area: " << area << endl;
                        cout << "Ejercicios disponibles para " << area << ":\n";
                        bool hayEjerciciosArea = false;
                        for (int i = 0; i < coleccionEjercicios->getCantidad(); ++i) {
                            Ejercicio* ej = coleccionEjercicios->getPorIndice(i);
                            if (ej && ej->getAreaCuerpo() == area) {
                                cout << "- " << ej->getCodigo() << ": " << ej->getNombre() << endl;
                                hayEjerciciosArea = true;
                            }
                        }
                        if (!hayEjerciciosArea) {
                            cout << "No hay ejercicios disponibles para esta area.\n";
                            continue;
                        }
                       
						string codigoEjercicio;

                        
                        do {
                            cout << "Ingrese el codigo del ejercicio para agregar a la rutina (o 'fin' para terminar con esta area): ";
                            cin >> codigoEjercicio;
                            if (codigoEjercicio == "fin") break;
                            Ejercicio* ejSeleccionado = coleccionEjercicios->buscarEjercicio(codigoEjercicio);
                            if (!ejSeleccionado || ejSeleccionado->getAreaCuerpo() != area) {
                                cout << "Codigo invalido o ejercicio no pertenece a esta area.\n";
                            }
                            else {
                                if (rutina->getColeccionEjercicios()->agregarEjercicio(ejSeleccionado)) {
                                    cout << "Ejercicio agregado a la rutina.\n";
                                }
                                else {
                                    cout << "No se pudo agregar el ejercicio a la rutina.\n";
                                }
                            }
							
                        } while (true);
					}
				
                    cout << "Rutina generada exitosamente para el cliente.\n";
                    system("pause");
                }
					  break;
                     
                      case 3: {
						  system("cls");
                    cout << "=== Mostrar rutina de un cliente ===\n";
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
                    Rutina* rutina = nullptr;
                    if (cliEncontrado->getColeccionRutinaActual()) {
                        rutina = cliEncontrado->getColeccionRutinaActual()->getRutina();
                    }
                    if (!rutina) {
                        cout << "El cliente no tiene una rutina asignada.\n";
                    }
                    else {
                        cout << "Rutina actual de " << cliEncontrado->getNombre() << ":\n";
                        cout << rutina->getColeccionEjercicios()->toString() << endl;

					}
                    system("pause");
                }
            break;

                    
                case 0: break;
                default: cout << "Opcion invalida!\n";
     }
                } while (opcion != 0);
				}

			
                void Interfaz::subMenuMatriculaClasesGrupales() {
                    cout << "Sucursales disponibles:\n" << coleccionSucursales->toString() << endl;
                    cout << "Digite el codigo de la sucursal para gestionar clases grupales:";
                    string codigo;
                    cin >> codigo;
                    Sucursal* suc = coleccionSucursales->buscarSucursal(codigo);
                    if (!suc) {
                        cout << "Sucursal no encontrada.\n";
                        return;
                    }

                    int opcion, capacidadMaxima, codigoClase;
                    string horario, duracion, cedulaInstructor, salon, cedulaCliente;
                    Instructor* instr = nullptr;
                    ClaseGrupal* nuevaClase = nullptr;
                    Cliente* cliente = nullptr;
					string tipoClase[8] = { "CrossFit", "HIIT", "TRX", "Pesas", "Spinning", "Cardio", "Yoga", "Zumba" };
                    do {
                        cout << "\n--- CLASES GRUPALES ---" << endl;
                        cout << "1. Crear clase grupal por sucursal" << endl;
                        cout << "2. Matricular cliente en clase grupal" << endl;
                        cout << "3. Ver lista de clientes por clase" << endl;
                        cout << "4. Ver clases matriculadas por cliente" << endl;
                        cout << "0. Volver" << endl;
                        cout << "Seleccione una opcion: ";
                        cin >> opcion;
                        cin.ignore();

                        switch (opcion) {
                        case 1:
							cout << "\n";
                            cout << "===Creando clase grupal===" << endl;
                            suc->getClasesOfrecidas()->mostrarDisponibles();
                            cout << "----------------------------------" << endl;
                            cout << "Ingrese el codigo de la clase (numero): "; cin >> codigoClase;
                            while (codigoClase <= 0 || codigoClase > 8) {
								cout << "Codigo invalido. Ingrese un numero entre 1 y 8: "; cin >> codigoClase;
                            }
                            cout << "Ingrese el horario de la clase (HH:MM): "; cin >> horario;
                            cout << "Ingrese la duracion de la clase (en minutos): "; cin >> duracion;
                            cout << "Ingrese la capacidad maxima de la clase: "; cin >> capacidadMaxima;
                            cout << "Ingrese el salon de la clase: "; cin >> salon;
                            cout << "Instructores de la sucursal " << codigo << ":\n";
                            cout << suc->getColeccionInstructores()->toString() << endl;
                            cout << "Ingrese la cedula del instructor que dictara la clase: "; cin >> cedulaInstructor;
                            instr = suc->getColeccionInstructores()->buscarInstructor(cedulaInstructor);
                            if (!instr) {
                                cout << "Instructor no encontrado en esta sucursal.\n";
                                break;
                            }
                            if (!instr->tieneEspecialidad(tipoClase[codigoClase-1])) {
                                cout << "El instructor no tiene la especialidad requerida para esta clase.\n";
                                break;
                            }
                            nuevaClase = new ClaseGrupal(codigoClase, tipoClase[codigoClase-1], horario, duracion, capacidadMaxima, salon);
                            if (suc->getClasesOfrecidas()->agregarClase(nuevaClase)) {
                                cout << "Clase grupal creada exitosamente!\n";
                                instr->getClasesAsociadas()->agregarClase(nuevaClase);
                            }
                            else {
                                cout << "No se pudo crear la clase. Verifique que el codigo no este repetido y que haya espacio disponible.\n";
                                delete nuevaClase;
                            }
                            break;

                        case 2:
                            cout << "\n";
							cout << "===Matriculando cliente en clase grupal===" << endl;
                            cout << "Ingrese la cedula del cliente: ";
                            cin >> cedulaCliente;
                            cliente = suc->getClientes()->buscarCliente(cedulaCliente);
                            if (!cliente) {
                                cout << "Cliente no encontrado en la sucursal.\n";
                                break;
                            }
                            cout << "Clases grupales existentes:\n";
                            cout << suc->getClasesOfrecidas()->toString();
                            cout << "Ingrese el codigo de la clase: ";
                            cin >> codigoClase;
                            {
                                ClaseGrupal* clase = suc->getClasesOfrecidas()->buscarClase(codigoClase);
                                if (!clase) {
                                    cout << "Clase no encontrada.\n";
                                    break;
                                }
                                if (clase->getClientesMatriculados()->getCantidad() >= clase->getCapacidadMaxima()) {
                                    cout << "La clase ya est� llena.\n";
                                    break;
                                }
                                if (cliente->getClasesCliente()->agregarClase(clase)) {
                                    clase->getClientesMatriculados()->agregarCliente(cliente);
                                    cout << "Cliente matriculado correctamente en la clase!\n";
                                }
                                else {
                                    cout << "El cliente ya est� matriculado en esta clase o no hay espacio en su contenedor.\n";
                                }
                            }
                            break;

                        case 3: 
                            cout << "\n";
							cout << "=== Ver lista de clientes por clase ===\n";
							cout << "Clases grupales existentes:\n";
							cout << suc->getClasesOfrecidas()->toString();
                            cout << "Ingrese el codigo de la clase: ";
                            cin >> codigoClase;
                            {
                                ClaseGrupal* clase = suc->getClasesOfrecidas()->buscarClase(codigoClase);
                                if (!clase) {
                                    cout << "Clase no encontrada.\n";
                                    break;
                                }
                                cout << clase->toStringClientes() << endl; 
                            }
                            break;

                        case 4: 
                            cout << "\n";
							cout << "=== Ver clases matriculadas por cliente ===\n";
							cout << "Clientes de la sucursal " << codigo << ":\n";
							cout << suc->getClientes()->toString() << endl;
                            cout << "Ingrese la cedula del cliente: ";
                            cin >> cedulaCliente;
                            cliente = suc->getClientes()->buscarCliente(cedulaCliente);
                            if (!cliente) {
                                cout << "Cliente no encontrado en la sucursal.\n";
                                break;
                            }
                            cout << cliente->getClasesCliente()->toString() << endl;
                            break;

                        case 0: break;
                        default: cout << "Opcion invalida!" << endl;
                        }
                    }while (opcion != 0);
                }