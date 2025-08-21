// fila = queue

typedef int TipoItem;
const int max_items = 100;

class fila
{
private:
  int primeiro, ultimo;
  TipoItem* estrutura;
public:
    fila(); // construtor
    ~fila(); // destrutor
    bool filaCheia(); // isEmpty
    bool filaVazia(); // isFull
    void enqueue(TipoItem item); // Inserir ||Push
    TipoItem dequeue();  // Remover||pop
    void print();

};

