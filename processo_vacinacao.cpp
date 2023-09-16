#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Idoso
{
  string id;
  string nome;
  int idade;
};

string gerarIdentificador(int tamanho);
void telaRegistro(Idoso idosos[], int &pos);
void registrar(Idoso &idosos, Idoso idoso);
void telaBuscar(Idoso idosos[]);
Idoso buscar(Idoso idosos[], string pesquisa);
void telaTodosCadastros(Idoso idosos[], int pos);
void merge(Idoso idosos[], int esquerda, int meio, int direita);
void mergeSort(Idoso idosos[], int esquerda, int direita);

int TAM = 25;

int main()
{
  Idoso idosos[TAM], idoso;
  int pos = -1;
  int escolha = 0;

  cout << "======== SISTEMA DE CADASTRO DE VACINACAO CONTRA COVID-19 ========" << endl;
  cout << endl;

  do
  {
    cout << "Selecione uma opcao:" << endl;
    cout << "(1) Cadastrar pessoa" << endl;
    cout << "(2) Buscar por uma pessoa" << endl;
    cout << "(3) Mostrar todas pessoas cadastradas" << endl;
    cout << "(4) Sair" << endl;
    cout << "cod: ";
    cin >> escolha;

    if (escolha == 1)
    {
      telaRegistro(idosos, pos);
    }
    else if (escolha == 2)
    {
      telaBuscar(idosos);
    }
    else if (escolha == 3)
    {
      telaTodosCadastros(idosos, pos);
    }

  } while (escolha != 4);
}

void telaRegistro(Idoso idosos[], int &pos)
{
  bool sair = false;
  string escolha;
  Idoso idoso;
  do
  {
    cout << "======== TELA DE CADASTRO DE USUARIO ========" << endl;
    cout << "Digite o nome: ";
    cin >> idoso.nome;
    cout << "Digite a idade: ";
    cin >> idoso.idade;
    idoso.id = gerarIdentificador(16);
    pos++;

    registrar(idosos[pos], idoso);

    cout << endl
         << "Deseja cadastrar um novo usuario? (S/n) ->";
    cin >> escolha;

    if (escolha == "N" || escolha == "n")
    {
      sair = true;
    }

  } while (!sair);

  mergeSort(idosos, 0, pos);

  return;
}

string gerarIdentificador(int tamanho)
{
  string caracteresPermitidos = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  int tamanhoCaracteres = caracteresPermitidos.length();

  string resultado;

  // Inicialize a semente para geração de números aleatórios com o tempo atual
  srand(static_cast<unsigned int>(time(nullptr)));

  for (int i = 0; i < tamanho; ++i)
  {
    int indiceAleatorio = rand() % tamanhoCaracteres;
    resultado += caracteresPermitidos[indiceAleatorio];
  }

  return resultado;
}

void registrar(Idoso &idosos, Idoso idoso)
{
  idosos = idoso;
  return;
}

void telaBuscar(Idoso idosos[])
{
  string pesquisa;
  bool sair = false;
  Idoso idoso;
  cout << "======== BUSCAR USUARIO ========" << endl;
  cout << endl
       << "No campo abaixo pesquise pelo nome ou identificador da pessoa" << endl;
  cout << "Caso deseje voltar para tela anterior, digite 'Sair' na hora de pesquisar" << endl;
  do
  {
    cout << "Pesquisar por: ";
    cin >> pesquisa;

    if (pesquisa.length() == 0)
    {
      cout << "Digite um nome ou identificador valido!" << endl;
    }
    else if (pesquisa == "Sair" || pesquisa == "sair")
    {
      sair = true;
    }
    else
    {
      idoso = buscar(idosos, pesquisa);
    }

    if (idoso.id.empty() && sair == false)
    {
      cout << "Nenhum usuario encontrado com esse nome ou identificador!" << endl;
    }
    else
    {
      sair = true;
    }

  } while (!sair);

  if (!idoso.id.empty())
  {
    cout << "==== PESSOA ====" << endl;
    cout << "Identificador: " << idoso.id << endl;
    cout << "Nome: " << idoso.nome << endl;
    cout << "Idade: " << idoso.idade << endl;
  }

  return;
}

Idoso buscar(Idoso idosos[], string pesquisa)
{
  Idoso idoso;
  for (int i = 0; i < TAM; i++)
  {
    if (idosos[i].nome == pesquisa || idosos[i].id == pesquisa)
    {
      idoso = idosos[i];
    }
  }

  return idoso;
}

void telaTodosCadastros(Idoso idosos[], int pos)
{
  cout << "======== TODOS CADASTROS ========" << endl;

  for (int i = pos; i >= 0; i--)
  {
    cout << "Identificador: " << idosos[i].id << " | "
         << "Nome: " << idosos[i].nome << " | "
         << "Idade: " << idosos[i].idade << endl;
  }

  return;
}

void merge(Idoso idosos[], int esquerda, int meio, int direita)
{
  int tamanho1 = meio - esquerda + 1;
  int tamanho2 = direita - meio;

  // Crie vetores temporários
  Idoso idososEsquerda[tamanho1];
  Idoso idososDireita[tamanho2];

  // Copie os dados para os vetores temporários idososEsquerda e idososDireita
  for (int i = 0; i < tamanho1; i++)
    idososEsquerda[i] = idosos[esquerda + i];
  for (int j = 0; j < tamanho2; j++)
    idososDireita[j] = idosos[meio + 1 + j];

  // Índices iniciais dos subvetores
  int i = 0, j = 0;

  // Índice inicial do subvetor fundido
  int k = esquerda;

  // Fundir os vetores temporários de volta no vetor original
  while (i < tamanho1 && j < tamanho2)
  {
    if (idososEsquerda[i].idade <= idososDireita[j].idade)
    {
      idosos[k] = idososEsquerda[i];
      i++;
    }
    else
    {
      idosos[k] = idososDireita[j];
      j++;
    }
    k++;
  }

  // Copie os elementos restantes de idososEsquerda[], se houver algum
  while (i < tamanho1)
  {
    idosos[k] = idososEsquerda[i];
    i++;
    k++;
  }

  // Copie os elementos restantes de idososDireita[], se houver algum
  while (j < tamanho2)
  {
    idosos[k] = idososDireita[j];
    j++;
    k++;
  }
}

// Função principal de ordenação do Merge Sort
void mergeSort(Idoso idosos[], int esquerda, int direita)
{
  if (esquerda < direita)
  {
    // Encontre o ponto médio do vetor
    int meio = esquerda + (direita - esquerda) / 2;

    // Ordenar a primeira metade
    mergeSort(idosos, esquerda, meio);

    // Ordenar a segunda metade
    mergeSort(idosos, meio + 1, direita);

    // Fundir as duas metades ordenadas
    merge(idosos, esquerda, meio, direita);
  }
}