typedef int TipoItem;

struct Node {
    TipoItem valor;
    Node* proximo;
};

class pilhad {
private:
    Node* NoTopo;
public:
    pilhad
();
    ~pilhad
();
    bool pilhavazia();
    bool pilhaCheia();
    void push(TipoItem item);
    TipoItem pop();
    void print();
};