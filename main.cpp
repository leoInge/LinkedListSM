#include <iostream>

#include "LinkedList.cpp"
#include "Videogame.h"
#include "vector"
using namespace std;
LinkedList<Videogame> *listavideojuegos = new LinkedList<Videogame>();


void AgregarInicio();

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
    int price = 0;

    cout << "ingrese el id ";
    cin >> idvideogame;

    cout << "ingrese el nombre ";
    cin >> name;

    cout << "ingresa la categoria ";
    cin >> category;

    cout << "ingresa el precio ";
    cin >> price;

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
            cin >> idvideogame;
            listavideojuegos->addFirst(Videogame("3", "Doom", "accion", 25000));
            listavideojuegos->addNodeBeforeTo(listavideojuegos->findNode(idvideogame), Videogame(idvideogame,name,category,price));


            break;
        case 4:

            cout << "digite el id del videojuego";
            cin >> idvideogame;

            listavideojuegos->addFirst(Videogame("5", "san andreas", "accion", 25000));

            listavideojuegos->addNodeAfterTo(listavideojuegos->findNode(idvideogame), Videogame(idvideogame,name,category,price));

            //poner metodo after to
            break;
        default:
            cout<< "Ingrese una opcion valida";

    }

}


int main() {

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
        std::cout << "6. salir" << std::endl;
        std::cout << "Elija una opción (1-6): ";
        std::cin >> opcion;


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

                break;
            case 6:
                std::cout << "Saliendo del programa..." << std::endl;

                break;

            default:
                std::cout << "Opción inválida. Por favor, elija una opción válida (1-6)." << std::endl;
        }


    }while (opcion != 6);

    return 0;
}