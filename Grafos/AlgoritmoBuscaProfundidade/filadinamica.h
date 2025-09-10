// Fila Dinamica = Dynamic Queue
#include "Node.h"

class filadinamica
{
private:
    Node* primeiro; //front
    Node* ultimo; //rear
public:
    filadinamica(); //construtor
    ~filadinamica(); //destrutor
     bool filaCheia(); // isEmpty
    bool filaVazia(); // isFull
    void enqueue(TipoItem item); // Inserir ||Push
    TipoItem dequeue();  // Remover||pop
    void print();
};