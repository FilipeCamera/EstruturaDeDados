#include <iostream>
using namespace std;

int buscaBinariaRecursiva(float v[], float valor, int ini, int fim);
void inserirCresc(float v[], int &n, int max, float valor);

int main()
{
  float notas[10], nota;
  int n = 0;
  int pos;

  do
  {
    cout << "Digite uma nota: ";
    cin >> nota;
    if (nota >= 0)
      inserirCresc(notas, n, 50, nota);
  } while (nota >= 0);

  cout << "Diga uma nota que deseja procurar: ";
  cin >> nota;

  int posBinario = buscaBinariaRecursiva(notas, nota, 0, 9);
  cout << posBinario << endl;
  cout << notas[posBinario] << endl;
}

void inserirCresc(float v[], int &n, int max, float valor)
{
  int i, pos;
  // Verifica se h� espa�o na lista
  if (n == max)
  {
    cout << "ERRO: Lista cheia!" << endl;
    return;
  }
  // Encontrar posi��o de inser��o
  i = 0;
  while (v[i] < valor && i < n)
    i++;
  pos = i;
  // Move para frente tudo que estiver ap�s a posi��o
  for (i = n; i > pos; i--)
    v[i] = v[i - 1];
  // Insere o elemento na posi��o
  v[pos] = valor;
  n++;
}

int buscaBinariaRecursiva(float v[], float valor, int ini, int fim)
{
  int meio = (ini + fim) / 2;

  if (valor == v[meio])
    return meio;

  if (valor < v[meio])
  {
    return buscaBinariaRecursiva(v, valor, ini, meio - 1);
  }
  return buscaBinariaRecursiva(v, valor, meio + 1, fim);
}