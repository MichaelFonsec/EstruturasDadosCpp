#include <iostream>
#include <cstddef> // Para Trabalhar com Ponteiro apontando para NULL
#include "arvoreBinaria.h"

using namespace std;

    BST::BST(){ // Construtor
        raiz = NULL;
    }
    BST::~BST(){ // Destrutor

    }
    void BST::deletarArvore(Node* Nodeatual){

    }
    Node* BST::obterRaiz(){
        return raiz;
    }
    bool BST::estaVazio(){
        return (raiz == NULL);
    }
    bool BST::estaCheio(){
        try
        {
           Node* temp = new Node; // cria um ponteiro temporario e cria um espaço para guardar um Nó, se achar um espaço na memoria para guardar esse Nó então não está cheio
           delete temp; // deleta esse espaço da memoria
           return false;

        }
        catch(bad_alloc exception)
        {
             cout << "Erro: memória insuficiente para alocar um novo nó. Árvore cheia.\n";
           return true;
        }
        
    }
    void BST::inserir(Aluno aluno){
                if(estaCheio()){
                    cout << "Arvore está cheia!\n";
                    cout << "Não foi possivel inserir esse elemento\n";
                }else{
                    Node* NodeNovo = new Node;
                    NodeNovo->aluno = aluno; //nesse nó o aluno será o aluno que o usuario irá inserir
                    NodeNovo->filhodireita = NULL; // ponteiro para o nó filho a direita está apontando para NULL pois não há um nó  
                    NodeNovo->filhoesquerda = NULL; // ponteiro para o nó filho a esquerda está apontando para NULL pois não há um nó
                    if(raiz == NULL){
                        raiz =  NodeNovo; // a raiz vai apontar para esse nó novo
                    } else{
                        Node* temp = raiz; // cria um nó temporario que vai receber a raiz
                        while (temp != NULL)
                        {
                            if(aluno.obterRa() < temp->aluno.obterRa()) // faz uma verificação se o RA do aluno que está sendo inserido for menor que o RA que está dentto do aluno do nó temporario
                            {
                                    if(temp->filhoesquerda == NULL){ // se for menor realiza uma outra verificação se o nó filho da esquerda é NULL
                                        temp->filhoesquerda = NodeNovo; // armazena o nó novo no nó do filho esquerdo
                                        break;                                        
                                    } else{
                                             temp = temp->filhoesquerda; // caso o no filho esquerdo não esteja NULL ele  vai para o nó esquerdo desse nó que ele verificou
                                    }
                            } else{
                                if(temp->filhodireita == NULL){  //se for maior realiza uma outra verificação se o nó filho da direita é NULL
                                    temp->filhodireita = NodeNovo; // armazena o nó novo no nó do filho direito
                                    break;
                                } else{
                                    temp = temp->filhodireita; //caso o no filho direito não esteja NULL ele  vai para o nó direito desse nó que ele verificou
                                }

                            }
                        }
                        
                    }
                }
                 
    }
    void BST::remover(Aluno aluno){
            removerBusca(aluno, raiz);

    }

    void BST::removerBusca(Aluno aluno, Node*& NoAtual) // O NoAtual ele é o ponteiro para o NoAtual
    {
            if(aluno.obterRa() < NoAtual->aluno.obterRa()){ // se o Ra  que está sendo buscado é menor que o Ra contido no NoAtual
                removerBusca(aluno, NoAtual->filhoesquerda); // Função Recursiva, ele busca pelo Nó da esquerda até o ponteiro desse nó ser NULL,se ele não achar ele chama a função novamente
            } else if(aluno.obterRa() > NoAtual->aluno.obterRa()){ // se for maior o Ra buscado do que o Ra que está no NoAtual ele faz a função de busca porém com o filho da direita 
                removerBusca(aluno, NoAtual->filhodireita); // Função Recursiva, ele busca pelo Nó da direita até o ponteiro desse nó ser NULL,se ele não achar ele chama a função novamente
            } else{
                deletarNode(NoAtual);
            }
    }
    void BST::deletarNode(Node*& NoAtual){
        Node* temp = NoAtual; // Caso o Nó a ser deletado tenha apenas um filho, o NoAtual é o ponteiro, ele aponta para o filho do Nó deletado,porem esse No temporario aponta para o Nó a ser deletado
        if(NoAtual->filhoesquerda == NULL){
            NoAtual = NoAtual->filhodireita; // Esse ponteiro do Nó a ser deletado recebe e aponta para o No filho do Nó a ser deletado
            delete temp; // deleta o nó temporario após o ponteiro NoAtual aponta para o filho do Nó deletado
        } else if(NoAtual->filhodireita == NULL){
            NoAtual = NoAtual->filhoesquerda;
            delete temp;
        } else{
            Aluno AlunoSucessor;
            obterSucessor(AlunoSucessor,NoAtual); //Obter Sucessor do Nó Atual caso os Nós filhos sejam diferente de vazio 
            NoAtual->aluno = AlunoSucessor; // Troca o valor do NoAtual pelo sucessor do Nó
            removerBusca(AlunoSucessor, NoAtual->filhodireita); // realiza uma busca utilizando o AlunoSucessor pelo Nó a Direita do NoAtual 
        }
    }
    void BST::obterSucessor(Aluno& AlunoSucessor, Node* temp){
            temp = temp->filhodireita; // recebe o filho à direita dele
            while(temp->filhoesquerda != NULL){ // o temp aponta para os nós esquerda enquanto não é NULL
                temp = temp->filhoesquerda;
            }
            AlunoSucessor = temp->aluno; // pega o valor desse nó temporario e atribui para AlunoSucessor 

    }
    void BST::buscar(Aluno& aluno, bool& busca){
            busca = false;
            Node* NoAtual = raiz;// cria um ponteiro para um nó apontando para o mesmo ponteiro da raiz
            while(NoAtual != NULL){
                if(aluno.obterRa() < NoAtual->aluno.obterRa()){ // verifica se o RA do aluno que está dentro do nó atual e menor do que Ra do aluno recebido pelo usuario
                    NoAtual = NoAtual->filhoesquerda;// o no atual vá para o nó da esquerda do nó atual
                } else if( aluno.obterRa() > NoAtual->aluno.obterRa()){ // caso o Ra  do aluno que está dentro do nó atual seja maior do que Ra do aluno recebido pelo usuario
                    NoAtual = NoAtual->filhodireita;      
                } else{
                    busca = true;
                    aluno = NoAtual->aluno;
                    break;
                }
            }

    }
    void BST::printPreOrdem(Node* Nodeatual){

    }
    void BST::printInOrdem(Node* Nodeatual){
        
    }
    void BST::printPosOrdem(Node* Nodeatual){

    }