#include <iostream>

using namespace std;

// Protótipo
void inserirSemRepetir(int vetor[], int valor, int pos, int max);
bool verificaValor(int vetor[], int valor, int max);
void listar(int vetor[], int max);
bool verificaListaCheia(int pos, int max);
int *intercalar(int *vet, int *vetorDois, int quantidade);
int *intersecao(int *vet, int *vetorDois, int quantidade);
int *listauniao(int *lista1, int *lista2, int quantidade);
bool parar(int pos, int max, bool valor);

int main()
{
  int quantidade;

  cout << "Digite a quantidade de numeros na lista: ";
  cin >> quantidade;

  int *vetor = new int[quantidade];
  int *vetorDois = new int[quantidade];

  int *mudaVetor = vetor;
  int valor;
  int pos = 0;
  bool pare = false;
  int lista = 1;

  while (!parar(pos, quantidade, pare))
  {
    if (verificaListaCheia(pos, quantidade))
    {
      lista = 2;
    }
    cout << "Digite o numero para lista " << lista << ":";
    cin >> valor;

    if (verificaListaCheia(pos, quantidade))
    {
      mudaVetor = vetorDois;
      pare = true;
      pos = 0;
    }
    if (verificaValor(mudaVetor, valor, quantidade))
    {
      continue;
    }

    inserirSemRepetir(mudaVetor, valor, pos, quantidade);
    pos++;
  }

  listar(vetor, quantidade);
  cout << endl;
  listar(vetorDois, quantidade);

  int *vetorTres = intercalar(vetor, vetorDois, quantidade);
  int *vetorQuatro = intersecao(vetor, vetorDois, quantidade);
  int *vetorCinco = listauniao(vetor, vetorDois, quantidade);

  cout << endl;
  listar(vetorTres, quantidade * 2);

  cout << endl;
  listar(vetorQuatro, quantidade);

  cout << endl;
  listar(vetorCinco, quantidade * 2);
  return 0;
}

bool parar(int pos, int max, bool valor)
{
  if (pos == max && valor)
  {
    return true;
  }
  return false;
}

bool verificaListaCheia(int pos, int max)
{
  if (pos == max)
  {
    return true;
  }
  return false;
}

bool verificaValor(int vetor[], int valor, int max)
{
  bool resultado = false;
  for (int i = 0; i < max; i++)
  {
    if (vetor[i] == valor)
    {
      cout << "Esse valor ja existe" << endl;
      resultado = true;
    }
  }

  return resultado;
}

void inserirSemRepetir(int vetor[], int valor, int pos, int max)
{
  vetor[pos] = valor;
}

void listar(int vetor[], int max)
{
  cout << "Lista:" << endl;
  cout << "[";
  for (int i = 0; i < max; i++)
  {
    cout << " " << vetor[i];
  }
  cout << " ]";
}

int *intercalar(int *vetor, int *vetorDois, int quantidade)
{
  int *vet = new int[quantidade * 2];
  int l = 0;
  int i = 0;
  int j = 1;
  while (l < quantidade)
  {
    vet[i] = vetor[l];
    i = i + 2;
    vet[j] = vetorDois[l];
    j = j + 2;
    l++;
  }
  return vet;
}

int *intersecao(int *vet, int *vetorDois, int quantidade)
{
  int *vetorIntersecao = new int[quantidade];
  for (int i = 0; i < quantidade; i++)
  {
    for (int j = 0; j < quantidade; j++)
    {
      if (vet[i] == vetorDois[j])
        vetorIntersecao[i] = vet[i];
    }
  }
  return vetorIntersecao;
}

int *listauniao(int *lista1, int *lista2, int quantidade)
{
  int *uniao = new int[quantidade * 2];

  int indexUniao = 0;
  int indexLista1 = 0;
  int indexLista2 = 0;

  while (indexLista1 < quantidade && indexLista2 < quantidade)
  {
    if (lista1[indexLista1] < lista2[indexLista2])
    {
      uniao[indexUniao++] = lista1[indexLista1++];
    }
    else if (lista1[indexLista1] > lista2[indexLista2])
    {
      uniao[indexUniao++] = lista2[indexLista2++];
    }
    else
    {
      uniao[indexUniao++] = lista1[indexLista1++];
      indexLista2++;
    }
  }
  while (indexLista1 < quantidade)
  {
    uniao[indexUniao++] = lista1[indexLista1++];
  }
  while (indexLista2 < quantidade)
  {
    uniao[indexUniao++] = lista2[indexLista2++];
  }
  return uniao;
}