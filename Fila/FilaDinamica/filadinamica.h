// Fila Dinamica = Dynamic Queue

typedef int TipoItem;

 class Node  // NÓ
{
    public:
    TipoItem valor;
    Node* proximo;
};

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