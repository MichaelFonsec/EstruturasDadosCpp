
typedef int TipoItem;
const int max_items = 100;

class pilha
{
private:
int tamanho;
TipoItem* estrutura;

public:
    pilha(); // funcao construtora
    ~pilha(); // funcao destrutora
    bool pilhacheia(); //verficar se está cheia a pilha
    bool pilhavazia(); //verificar se está vazia
    void push(TipoItem item); // função de inserir
    TipoItem pop(); // função de remoção
    void print(); 
    int length();
};

