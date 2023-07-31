#include <iostream>
#include <limits>

#include "LinkedList.cpp"
#include "Videogame.h"
#include "vector"
using namespace std;
LinkedList<Videogame> *listavideojuegos = new LinkedList<Videogame>();

int obtenerOpcion() {
    std::string input;

    //std::cout << "Elija una opcion (1-7): ";
    std::cin >> input;


    if (input.length() == 1 && (std::isdigit(input[0]) || std::isalpha(input[0]))) {
        char ch = input[0];
        if (std::isdigit(ch)) {
            int opcion = ch - '0';
            if (opcion >= 1 && opcion <= 7) {
                return opcion; // Retornar la opción válida
            }
        }
    }

    std::cout << "Error: Debes ingresar una opcion valida (1-7)." << std::endl;
    return 0; // Retornar 0 para indicar que la opción no es válida
}

void buscarVideojuego(){
    string idvideogame = "";
    cout << "digite el id del videojuego";
    cin >> idvideogame;
    Node<Videogame> *node = listavideojuegos->findNode(idvideogame);

    if (node != NULL) {
        cout << "Existe" << endl;


    } else {
        cout << "No existe" << endl;
    }
}

void agregarVideojuego(){
    string idvideogame = "";
    string name = "";
    string category = "";
    string targetId = "";
    string targetIdBefore = "";
    int price = 0;

    cout << "ingrese el id ";
    cin >> idvideogame;

    cout << "ingrese el nombre ";
    cin >> name;

    cout << "ingresa la categoria ";
    cin >> category;

    cout << "ingresa el precio ";
    cin >> price;



    if (idvideogame.find(' ') != std::string::npos) {
        throw std::invalid_argument("Error: El idvideogame no debe contener espacios.");
    }

    // Verificar si el idvideogame ya existe en la lista
    Node<Videogame>* existingNode = listavideojuegos->findNode(idvideogame);
    if (existingNode != nullptr) {
        cout << "Error: El idvideogame ya existe en la lista." << endl;
        return;
    }





    int opc2 = 0;
    std::cout << "En que parte desea agregar el nuevo elemento?" << std::endl;
    std::cout << "1. Principio" << std::endl;
    std::cout << "2. Final" << std::endl;
    std::cout << "3. Antes de..." << std::endl;
    std::cout << "4. Despues de..." << std::endl;
    std::cin >> opc2;
    switch (opc2) {
        case 1:

            listavideojuegos->addFirst(Videogame(idvideogame, name, category, price));
            break;
        case 2:
            listavideojuegos->addLast(Videogame(idvideogame, name, category, price));
            break;
        case 3:

            cout << "digite el id del videojuego";
            cin >> targetIdBefore;
            listavideojuegos->addFirst(Videogame("3", "Doom", "accion", 25000));
            listavideojuegos->addNodeBeforeTo(targetIdBefore, Videogame(idvideogame, name, category, price));


            break;
        case 4:

            cout << "digite el id del videojuego";
            cin >> targetId;

            listavideojuegos->addFirst(Videogame("5", "san andreas", "accion", 25000));

            listavideojuegos->addNodeAfterTo(targetId, Videogame(idvideogame, name, category, price));


            break;
        default:
            cout<< "Ingrese una opcion valida";

    }

}









int main() {

    while (true) {

        int cantidadObjetos = listavideojuegos->countObjects();
        string idvideogame = "";
        int opcion;

        opcion = 0;
        do {
            // Mostrar el menú
            std::cout << "MENU" << std::endl;
            std::cout << "1. Agregar nuevo Video juego" << std::endl;
            std::cout << "2. buscar video juego" << std::endl;
            std::cout << "3. Eliminar videojuego" << std::endl;
            std::cout << "4. Mostrar lista completa de video juegos" << std::endl;
            std::cout << "5. Mostrar cantidad de video juegos" << std::endl;
            std::cout << "6. obtener objeto de lista segun la posicion" << std::endl;
            std::cout << "7. salir" << std::endl;
            // std::cout << "Elija una opcion (1-6): ";
            // std::cin >> opcion;
            opcion = obtenerOpcion();

            switch (opcion) {
                case 1:

                    agregarVideojuego();

                    break;


                case 2:

                    buscarVideojuego();


                    break;

                case 3:


                    cout << "digite el id del videojuego";
                    cin >> idvideogame;

                    cout << "Se elimina " << listavideojuegos->deleteNode(listavideojuegos->findNode(idvideogame))
                         << endl;

                    break;
                case 4:
                    for (Videogame videogame: listavideojuegos->getLinkedList(true)) {
                        cout << videogame << endl;


                    }


                case 5 :


                    cout << "Cantidad de objetos en la lista de videojuegos: " << cantidadObjetos << endl;


                    break;
                case 6:

                    int positionToGet;
                    cout << "Ingrese la posicion del objeto que desea obtener: ";
                    cin >> positionToGet;

                    try {
                        Videogame videojuego = listavideojuegos->getFirstByPosition(positionToGet);
                        cout << "Objeto obtenido en la posicion " << positionToGet << ": " << videojuego << endl;
                    } catch (const std::out_of_range& e) {
                        cout << e.what() << endl;
                    }
                    break;

                        case 7 :

                            std::cout << "Saliendo del programa..." << std::endl;


                        break;


                        default:
                            std::cout << "Opcion invalida. Por favor, elija una opción válida (1-6)." << std::endl;
                    }


            }
            while (opcion != 7);

            return 0;
        }
    }