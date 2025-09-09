#include <iostream>
#include <cstddef> // Para Trabalhar com Ponteiro apontando para NULL
#include "arvoreAVL.h"

using namespace std;

    ArvoreAVL::ArvoreAVL(){ // Construtor
        raiz = NULL;
    }
    ArvoreAVL::~ArvoreAVL(){ // Destrutor
        deletarArvore(raiz);
    }
    void ArvoreAVL::deletarArvore(Node* Nodeatual){
        if(Nodeatual != NULL){
            deletarArvore(Nodeatual->filhoesquerda); // chama a função recursiva aonde visita os filhos a esquerda do No Atual para deletar

            deletarArvore(Nodeatual->filhodireita); // chama a função recursiva aonde visita os filhos a direita do No Atual para deletar

            delete Nodeatual; //Deleta o Nó Atual
        }
    }
    Node* ArvoreAVL::obterRaiz(){
        return raiz;
    }
    bool ArvoreAVL::estaVazio(){
        return (raiz == NULL);
    }
    bool ArvoreAVL::estaCheio(){
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
    void ArvoreAVL::inserir(Aluno aluno){
             bool cresceu;
             insererecursivo(raiz, aluno, cresceu);
    }

    void ArvoreAVL::insererecursivo(Node*& Nodeatual, Aluno aluno, bool& cresceu){
            if(Nodeatual == NULL){ // verifica se o Nó for nulo ele acrescenta um novo nó
                Nodeatual = new Node; //cria um novo nó
                Nodeatual->filhodireita = NULL; // filho direito aponta para NULL
                Nodeatual->filhoesquerda = NULL; // filho esquerdo aponta para NULL
                Nodeatual->aluno = aluno; // recebe o aluno que foi mandado para função
                Nodeatual->fatorB = 0;  // quando um novo nó inserido começa com o Fator de Balanceamento em 0
                cresceu = true; 
                return; // retorna para o Nó Pai desse novo Nó
            }
            if(aluno.obterRa() < Nodeatual->aluno.obterRa()){
                insererecursivo(Nodeatual->filhoesquerda, aluno, cresceu); // chama a funçao recursiva para a esquerda
                if(cresceu){ // verifica se houve crescimento se for verdadeiro então atualiza o fator de balanceamento
                    Nodeatual->fatorB-=1;// diminui o fator de balanceamento
                }
            } else {
                insererecursivo(Nodeatual->filhodireita, aluno, cresceu); // chama a função recursiva para a direita
                if(cresceu){ // verifica se houve crescimento se for verdadeiro então atualiza o fator de balanceamento
                    Nodeatual->fatorB+=1; // aumenta o fator de balanceamento
                }
            }
            realizarotacao(Nodeatual); // verifica se precisa de rotação e qual rotação será utilizado

            if(cresceu && Nodeatual->fatorB == 0){ // se o fator de balanceamento for 0, o cresceu fica falso
                cresceu = false;
            }
    }
    void ArvoreAVL::remover(Aluno aluno){
        bool diminui;    
        removerBusca(aluno, raiz, diminui);

    }

    void ArvoreAVL::removerBusca(Aluno aluno, Node*& NoAtual, bool& diminuiu) // O NoAtual ele é o ponteiro para o NoAtual
    {
            if(aluno.obterRa() < NoAtual->aluno.obterRa()){ // se o Ra  que está sendo buscado é menor que o Ra contido no NoAtual
                removerBusca(aluno, NoAtual->filhoesquerda, diminuiu); // Função Recursiva, ele busca pelo Nó da esquerda até o ponteiro desse nó ser NULL,se ele não achar ele chama a função novamente
                if(diminuiu){ // verifica se diminuiu a sub-arvore da esquerda 
                    NoAtual->fatorB+=1; // atualizar o fator de balanceamento, aumentando em 1 
                }
            } else if(aluno.obterRa() > NoAtual->aluno.obterRa()){ // se for maior o Ra buscado do que o Ra que está no NoAtual ele faz a função de busca porém com o filho da direita 
                removerBusca(aluno, NoAtual->filhodireita, diminuiu); // Função Recursiva, ele busca pelo Nó da direita até o ponteiro desse nó ser NULL,se ele não achar ele chama a função novamente
                if(diminuiu){ // verifica se diminuiu a sub-arvore da direita 
                    NoAtual->fatorB-=1; // atualizar o fator de balanceamento, diminuindo em 1 
                }
            } else{
                deletarNode(NoAtual, diminuiu);
            }
            if(NoAtual != NULL){
                realizarotacao(NoAtual);
                if(diminuiu && NoAtual->fatorB != 0){// se tiver algum nó que o fator de balanceamento for diferente de 0 
                    diminuiu = false; // então não houve diminuição
                }
            }
    }
    void ArvoreAVL::deletarNode(Node*& NoAtual, bool& diminuiu){
        Node* temp = NoAtual; // Caso o Nó a ser deletado tenha apenas um filho, o NoAtual é o ponteiro, ele aponta para o filho do Nó deletado,porem esse No temporario aponta para o Nó a ser deletado
        if(NoAtual->filhoesquerda == NULL){
            NoAtual = NoAtual->filhodireita; // Esse ponteiro do Nó a ser deletado recebe e aponta para o No filho do Nó a ser deletado
            diminuiu = true;
            delete temp; // deleta o nó temporario após o ponteiro NoAtual aponta para o filho do Nó deletado
        } else if(NoAtual->filhodireita == NULL){
            NoAtual = NoAtual->filhoesquerda;
            diminuiu = true;
            delete temp;
        } else{
            Aluno AlunoSucessor;
            obterSucessor(AlunoSucessor,NoAtual); //Obter Sucessor do Nó Atual caso os Nós filhos sejam diferente de vazio 
            NoAtual->aluno = AlunoSucessor; // Troca o valor do NoAtual pelo sucessor do Nó
            removerBusca(AlunoSucessor, NoAtual->filhodireita, diminuiu); // realiza uma busca utilizando o AlunoSucessor pelo Nó a Direita do NoAtual 
            if(diminuiu){
                NoAtual->fatorB-=1;
            }
        }
    }
    void ArvoreAVL::obterSucessor(Aluno& AlunoSucessor, Node* temp){
            temp = temp->filhodireita; // recebe o filho à direita dele
            while(temp->filhoesquerda != NULL){ // o temp aponta para os nós esquerda enquanto não é NULL
                temp = temp->filhoesquerda;
            }
            AlunoSucessor = temp->aluno; // pega o valor desse nó temporario e atribui para AlunoSucessor 

    }
    void ArvoreAVL::buscar(Aluno& aluno, bool& busca){
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
    void ArvoreAVL::printPreOrdem(Node* Nodeatual){
            if(Nodeatual != NULL){ // Verificas se o Nó Atual é diferente de NULL
                cout << Nodeatual->aluno.obterNome() << ": "; // imprime o Nome do Aluno que está no No Atual
                cout << Nodeatual->aluno.obterRa() << endl; // imprime o RA do Aluno que está no No Atual
                
                printPreOrdem(Nodeatual->filhoesquerda); // chama a função recursiva dele mesmo imprimindo os filhos da esquerda do Nó Atual
                printPreOrdem(Nodeatual->filhodireita); // chama a função recursiva dele mesmo imprimindo os filhos da direita do Nó Atual
            }
    }
    void ArvoreAVL::printInOrdem(Node* Nodeatual){
            if(Nodeatual != NULL){
                printInOrdem(Nodeatual->filhoesquerda); // chama a função recursiva dele mesmo imprimindo os filhos da esquerda do Nó Atual
                cout << Nodeatual->aluno.obterNome() << ": "; // imprime o Nome do Aluno que está no No Atual
                cout << Nodeatual->aluno.obterRa() << endl; // imprime o RA do Aluno que está no No Atual
                printInOrdem(Nodeatual->filhodireita); // chama a função recursiva dele mesmo imprimindo os filhos da direita do Nó Atual
            }

    }
    void ArvoreAVL::printPosOrdem(Node* Nodeatual){
            if(Nodeatual != NULL){
                printPosOrdem(Nodeatual->filhoesquerda); // chama a função recursiva dele mesmo imprimindo os filhos da esquerda do Nó Atual
                printPosOrdem(Nodeatual->filhodireita); // chama a função recursiva dele mesmo imprimindo os filhos da direita do Nó Atual
                cout << Nodeatual->aluno.obterNome() << ": "; // imprime o Nome do Aluno que está no No Atual
                cout << Nodeatual->aluno.obterRa() << endl; // imprime o RA do Aluno que está no No Atual
            }
    }

    void ArvoreAVL::rotacaodireita(Node*& pai){
        Node* novoPai = pai->filhoesquerda;
        pai->filhoesquerda = novoPai->filhodireita;
        novoPai->filhodireita = pai;
        pai = novoPai;
    }

    void::ArvoreAVL::rotacaoesquerda(Node*& pai){
        Node* novoPai = pai->filhodireita;
        pai->filhodireita = novoPai->filhoesquerda;
        novoPai->filhoesquerda = pai;
        pai = novoPai;
    }

    void::ArvoreAVL::rotacaoesquerdadireita(Node*& pai){
        Node* filho = pai->filhoesquerda;
        rotacaoesquerda(filho);
        pai->filhoesquerda = filho;
        rotacaodireita(pai);
    }

    void::ArvoreAVL::rotacaodireitaesquerda(Node*& pai){
        Node* filho = pai->filhodireita;
        rotacaodireita(filho);
        pai->filhodireita = filho;
        rotacaoesquerda(pai);
    }

    