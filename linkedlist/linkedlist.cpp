// linkedlist.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

// Estructura para un nodo de la lista enlazada
struct Node {
    int data;        // Valor almacenado en el nodo
    Node* next;      // Puntero al siguiente nodo
};

// Clase LinkedList
class LinkedList {
private:
    Node* head;      // Puntero al primer nodo
    Node* tail;      // Puntero al último nodo

public:
    // Constructor
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor para liberar memoria
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Método para añadir un valor al final de la lista
    void push_back(const int& value) {
        Node* newNode = new Node{ value, nullptr };
        if (head == nullptr) {  // Si la lista está vacía
            head = tail = newNode;
        }
        else {                // Si la lista no está vacía
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Método para insertar un valor en una posición específica
    void insert(unsigned int position, const int& value) {
        Node* newNode = new Node{ value, nullptr };
        if (position == 0) {    // Insertar al inicio
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) {
                tail = newNode; // Si la lista estaba vacía
            }
        }
        else {                // Insertar en el medio o al final
            Node* current = head;
            unsigned int currentIndex = 0;

            // Avanzar hasta la posición anterior a la deseada
            while (current != nullptr && currentIndex < position - 1) {
                current = current->next;
                ++currentIndex;
            }

            if (current != nullptr) {  // Insertar en la posición deseada
                newNode->next = current->next;
                current->next = newNode;
                if (newNode->next == nullptr) {
                    tail = newNode;    // Actualizar el tail si es el último nodo
                }
            }
            else {    // Si la posición está fuera de rango
                cout << "Posición fuera de rango. No se insertó el valor." << endl;
                delete newNode;
            }
        }
    }

    // Método para imprimir la lista completa
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

// Función principal
int main() {
    LinkedList list;

    // Insertar elementos en diferentes posiciones
    cout << "Insertando valores en diferentes posiciones..." << endl;

    list.push_back(10); // Añadir al final
    list.print();       // Output: 10 -> NULL

    list.insert(0, 20); // Insertar al inicio
    list.print();       // Output: 20 -> 10 -> NULL

    list.insert(1, 30); // Insertar en la posición 1
    list.print();       // Output: 20 -> 30 -> 10 -> NULL

    list.insert(3, 40); // Insertar al final
    list.print();       // Output: 20 -> 30 -> 10 -> 40 -> NULL

    list.insert(2, 50); // Insertar en la posición 2
    list.print();       // Output: 20 -> 30 -> 50 -> 10 -> 40 -> NULL

    return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
