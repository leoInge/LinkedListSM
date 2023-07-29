#include <iostream>

#include "LinkedList.cpp"
#include "Dish.h"
#include "Videogame.h"
#include "vector"
using namespace std;

void AgregarInicio();


int main() {
    LinkedList<Videogame> *listavideojuegos = new LinkedList<Videogame>();

    int opcion;

    opcion = 0;
    do {


    string idvideogame;
    string name;
    string category;
    int price;
    cout << "ingrese el id ";
    cin >> idvideogame;


    cout << "ingrese el nombre ";
    cin >> name;




    cout << "ingresa la categoria ";
    cin >> category;


    cout << "ingresa el precio ";
    cin >> price;




        // Mostrar el menú
        std::cout << "MENU" << std::endl;
        std::cout << "1. Agregar al nodo incio" << std::endl;
        std::cout << "2. Agregar el nodo final" << std::endl;
        std::cout << "3. buscar nodo" << std::endl;
        std::cout << "4. Eliminar nodo" << std::endl;
        std::cout << "5. Mostrar nodo" << std::endl;
        std::cout << "6. salir" << std::endl;
        std::cout << "Elija una opción (1-6): ";
        std::cin >> opcion;


        switch (opcion) {
            case 1:
                listavideojuegos->addFirst(Videogame(idvideogame, name, category, price));


                break;

            case 2:

                listavideojuegos->addLast(Videogame(idvideogame, name, category, price));

                break;

                //  case 3:


                //    cout << "digite el id del videojuego";
                //  cin >> idvideogame;


                //Node<Videogame> *node = listavideojuegos->findNode(idvideogame);

                // if (node != NULL) {
                cout << "Existe" << endl;
                // } else {
                //   cout << "No existe" << endl;
                // }
                break;

            case 4:


                cout << "digite el id del videojuego";
                cin >> idvideogame;

                cout << "Se elimina " << listavideojuegos->deleteNode(listavideojuegos->findNode(idvideogame))
                     << endl;

                break;
            case 5:
                for (Videogame videogame: listavideojuegos->getLinkedList(true)) {
                    cout << videogame << endl;
                }

                break;
            case 6:
                std::cout << "Saliendo del programa..." << std::endl;

                break;

            default:
                std::cout << "Opción inválida. Por favor, elija una opción válida (1-4)." << std::endl;
        }


    }while (opcion != 6);

    return 0;
}



