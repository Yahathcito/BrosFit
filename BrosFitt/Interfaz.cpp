#include "Interfaz.h"


ColeccionSucursal* Interfaz::coleccionSucursales = nullptr;
ColeccionClientes* Interfaz::coleccionClientes = nullptr;

void Interfaz::menu() {
    if (!coleccionSucursales) {
        coleccionSucursales = new ColeccionSucursal(30);
    }
    if (!coleccionClientes)
    {
        coleccionClientes = new ColeccionClientes(100);
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
              /*  subMenuInformeDeInstructores();*/
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
                  // SOLO SE MUESTRA LA PARTE MODIFICADA DEL case 2 EN informeDeClientes
          // SOLO SE MUESTRA LA PARTE MODIFICADA DEL case 2 EN informeDeClientes
            case 2: {
				// debe haber al menos un cliente ingresado para que no se pidan los datos cuando no hay clientes
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
//--------------------------------------------------------------------------
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
            string horario, duracion, tipoClase, cedulaInstructor, salon, cedulaCliente;
            Instructor* instr = nullptr;
            ClaseGrupal* nuevaClase = nullptr;
            Cliente* cliente = nullptr;

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
                    cout << "===Creando clase grupal===" << endl;
                    suc->getClasesOfrecidas()->mostrarDisponibles();
                    cout << "----------------------------------" << endl;
                    cout << "Ingrese el codigo de la clase (numero): "; cin >> codigoClase;
                    cout << "Ingrese el nombre de la clase: "; cin >> tipoClase;
                    cout << "Ingrese el horario de la clase (HH:MM): "; cin >> horario;
                    cout << "Ingrese la duracion de la clase (en minutos): "; cin >> duracion;
                    cout << "Ingrese la capacidad maxima de la clase: "; cin >> capacidadMaxima;
                    cout << "Ingrese el salon de la clase: "; cin >> salon;
                    cout << "Instructores de la sucursal " << codigo << ":\n";
                    cout << "--------------------------------------\n";
                    cout << suc->getColeccionInstructores()->toString() << endl;
                    cout << "--------------------------------------\n";
                    cout << "Ingrese la cedula del instructor que dictara la clase: "; cin >> cedulaInstructor;
                    instr = suc->getColeccionInstructores()->buscarInstructor(cedulaInstructor);
                    if (!instr) {
                        cout << "Instructor no encontrado en esta sucursal.\n";
                        break;
                    }
                    if (!instr->tieneEspecialidad(tipoClase)) {
                        cout << "El instructor no tiene la especialidad requerida para esta clase.\n";
                        break;
                    }
                    nuevaClase = new ClaseGrupal(codigoClase, tipoClase, horario, duracion, capacidadMaxima, salon);
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
                    cout << "Ingrese la cedula del cliente: ";
                    cin >> cedulaCliente;
					cliente = suc->getClientes()->buscarCliente(cedulaCliente);
                    if (!cliente) {
                        cout << "Cliente no encontrado en la sucursal.\n";
                        break;
                    }
                    cout << "Clases grupales existentes:\n";
                    cout<<suc->getClasesOfrecidas()->toString();
                    cout << "Ingrese el codigo de la clase: ";
                    cin >> codigoClase;
                    {
                        ClaseGrupal* clase = suc->getClasesOfrecidas()->buscarClase(codigoClase);
                        if (!clase) {
                            cout << "Clase no encontrada.\n";
                            break;
                        }
                        if (clase->getClientesMatriculados()->getCantidad() >= clase->getCapacidadMaxima()) {
                            cout << "La clase ya está llena.\n";
                            break;
                        }
                        if (cliente->getClasesCliente()->agregarClase(clase)) {
							clase->getClientesMatriculados()->agregarCliente(cliente);
                            cout << "Cliente matriculado correctamente en la clase!\n";
                        }
                        else {
                            cout << "El cliente ya está matriculado en esta clase o no hay espacio en su contenedor.\n";
                        }
                    }
                    break;

                case 3: // Ver lista de clientes por clase
                    cout << "Ingrese el codigo de la clase: ";
                    cin >> codigoClase;
                    {
                        ClaseGrupal* clase = suc->getClasesOfrecidas()->buscarClase(codigoClase);
                        if (!clase) {
                            cout << "Clase no encontrada.\n";
                            break;
                        }
                        cout << clase->toStringClientes() << endl; // necesitas un método que devuelva string con clientes
                    }
                    break;

                case 4: // Ver clases matriculadas por cliente
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
            } while (opcion != 0);
        }
