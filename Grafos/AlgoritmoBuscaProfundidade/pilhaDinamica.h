#include "Node.h"

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