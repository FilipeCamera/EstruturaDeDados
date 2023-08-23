#include <iostream>
#include <string>

using namespace std;

int enfileirar(char valores[], int &fim, char valor);
int desenfileirar(char valores[], int &inicio, int fim, char &valor);
void empilhar(char valores[], int &topo, int fim, char valor);
int desempilhar(char valores[], int &topo, char &valor);

int tam = 10;

int main()
{
  char valores[tam];
  char valores_pilha[tam];
  char valor;
  int inicio = 0, fim = -1;
  int topo = -1;

  do
  {
    cout << "Digite um conjunto de caracteres: ";
    cin >> valor;

    if (valor != '0')
      enfileirar(valores, fim, valor);
  } while (valor != '0');

  cout << "Empilhando..." << endl;
  while (desenfileirar(valores, inicio, fim, valor) == 0)
  {
    empilhar(valores_pilha, topo, fim, tolower(valor));
  }

  cout << "Desempilhando..." << endl;
  while (desempilhar(valores_pilha, topo, valor) == 0)
  {
    cout << valor << endl;
  }
}

int enfileirar(char valores[], int &fim, char valor)
{

  if (fim >= tam - 1)
    return 1;

  fim = fim + 1;

  valores[fim] = valor;

  return 0;
}

int desenfileirar(char valores[], int &inicio, int fim, char &valor)
{
  if (inicio > fim)
    return 1;

  valor = valores[inicio];
  inicio++;

  return 0;
}

void empilhar(char valores[], int &topo, int fim, char valor)
{
  if (topo >= fim)
  {
    return;
  }

  topo++;
  valores[topo] = valor;
}

int desempilhar(char valores[], int &topo, char &valor)
{
  if (topo >= 0)
  {
    valor = valores[topo];
    topo--;
    return 0;
  }
  return 1;
}