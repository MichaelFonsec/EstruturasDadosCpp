typedef int TipoItem;

struct Node {
    TipoItem item;
    Node* proximo;
};

class pilhaDinamica {
private:
    Node* NoTopo;
public:
    pilhaDinamica();
    ~pilhaDinamica();
    bool pilhavazia();
    bool pilhaCheia();
    void push(TipoItem item);
    TipoItem pop();
    void print();
};