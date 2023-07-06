#include "funcoes.h"
#include "cores.h"

using namespace std;


/*
 * Função de ordenção pelo método de troca (bubble sort).
 * @param o vetor a ser ordenado
 * @param tamano N do vetor a ser ordenado
 */
int bubblesort(int vetor[], int n){
  int v[n]={};
  int aux, contBubble;
  aux = contBubble = 0;

  for (int i = 0; i < n; i++){
   v[i] = vetor[i];
  }

  for (int i = n - 1; i > 0; i--){
    for (int j = 0; j < i; j++){
    contBubble += 2;
      if (v[j] > v[j + 1]){
        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
        contBubble += 4;
      }
    }
  }
  return contBubble;
}

/*
 * Função de ordenção pelo método de inserção (insertion sort).
 * @param o vetor a ser ordenado
 * @param tamano N do vetor a ser ordenado
 */
int insertionsort(int vetor[], int n){
  int aux, j, contInsertion;
  int v[n] = {};
  contInsertion = 0;

  for (int i = 0; i < n; i++){
    v[i] = vetor[i];
  }

  for (int i = 1; i < n; i++){
    aux = v[i];
    j = i - 1;
    while (j >= 0 && v[j] > aux){
      v[j + 1] = v[j];
      j--;
      contInsertion += 2;
    }
    v[j + 1] = aux;
    contInsertion += 3;
  }

  return contInsertion;
}

int selectionsort(int vetor[], int n){
  int v[n]={};
  int aux, min, contSelection;
  contSelection = 0;

  for (int i = 0; i < n; i++){
   v[i] = vetor[i];
  }
  
  for (int i = 0; i < n-1; i++){
    min = i;
    aux = v[i];
    for (int j = i + 1; j < n; j++){
      contSelection ++;
      if (v[j] < aux){
        aux = v[j];
        min = j;
        contSelection++;
      }
    }
    v[min] = v[i];
    v[i] = aux;
    contSelection+=4;
  }
  return contSelection;
}

void create_file_random(int n, int m){
    int vetor[n] = {};
    int random_value = 0;
    cout << "Criando arquivo com valores aleatórios..." << endl;
    srand((unsigned) time(NULL));
    ofstream out ("random.txt");
    if (!out.is_open()){
      cout << vermelho_G "Erro na criação do arquivo!" reset << endl;
      exit(1);
    }
    out << n << endl;
    for (int i = 0; i < n; i++){
        random_value = rand() % m; 
        int j = 0;
        while (j < n){
            if (random_value == vetor[j]){ 
                random_value = rand() % m;  
                j = 0;
            } else {
                j++;
            }
        }
        vetor[i] = random_value;
        out << vetor[i];
        out << endl;
    }
    cout << "Arquivo criado com sucesso!"  << endl;
    out.close();
}

void ordena_vetor(int vetor[], int n, string chave){
  int aux, min;
  if (chave == "cresc"){
    for (int i = 0; i < n; i++){
    min = i;
    aux = vetor[i];
    for (int j = i + 1; j < n; j++){
      if (vetor[j] < aux){
        aux = vetor[j];
        min = j;
      }
    }
    vetor[min] = vetor[i];
    vetor[i] = aux;
   }
  } else {
    for (int i = 0; i < n; i++){
    min = i;
    aux = vetor[i];
    for (int j = i + 1; j < n; j++){
      if (vetor[j] > aux){
        aux = vetor[j];
        min = j;
      }
    }
    vetor[min] = vetor[i];
    vetor[i] = aux;
   }
  }  
}

void open_file(int vetor[], int n){
  ifstream arquivo("random.txt");
  int valor = 0;
  if (!arquivo.is_open()){
      cout << vermelho_G "Erro na abertura do arquivo" reset << endl;
      exit(1);
    }
  arquivo >> valor; //descarte da primeira linha do arquivo
  for (int i = 0; i < n ; i++){
    arquivo >> valor;
    vetor[i] = valor;
  }
  arquivo.close();
}

void header_exit_file(string filename){
  ofstream out (filename);
  if (!out.is_open()){
    cout << vermelho_G "Erro na criação do arquivo" reset << endl;
    exit(1);
  }
  out << "qtd_elementos,cont_bbs,cont_ins,cont_sel\n" << endl;
  out.close(); 
}

void exit_file(string filename, int qtd_elementos, int cont_bbs, int cont_ins, int cont_sel){
  ofstream out;
  out.open(filename, ios_base::app);
  if (!out.is_open()){
    cout << vermelho_G "Não foi possível abrir o arquivo de saída: " << filename << reset << endl;
    exit(1);
  }
  out << qtd_elementos << "," << cont_bbs << "," << cont_ins << "," << cont_sel << endl;
  out.close();
}

void interface(){
  cout << magenta_N "             ___                                                                   " << endl;
  cout << "            /  /                                                                    " << endl;
  cout << " __   __  _/__/__  _______  _______  ______   _______  _______            ______   _______ " << endl;
  cout << "|  |_|  ||       ||       ||       ||      | |       ||       |          |      | |       |" << endl;
  cout << "|       ||    ___||_     _||   _   ||  _    ||   _   ||  _____|          |  _    ||    ___| " << endl;
  cout << "|       ||   |___   |   |  |  | |  || | |   ||  | |  || |_____           | | |   ||   |___ " << endl;
  cout << "|       ||    ___|  |   |  |  |_|  || |_|   ||  |_|  ||_____  |          | |_|   ||    ___| " << endl;
  cout << "| ||_|| ||   |___   |   |  |       ||       ||       | _____| |          |       ||   |___  " << endl;
  cout << "|_|   |_||_______|  |___|  |_______||______| |_______||_______|          |______| |_______|" << endl;
  cout << "                                                                  _____           " << endl;
  cout << "                                                                 |_____|           " << endl;
  cout << " _______  ______    ______   _______  __    _  _______  _______  _______  _______ " << endl;
  cout << "|       ||    _ |  |      | |       ||  |  | ||   _   ||       ||   _   ||       |" << endl;
  cout << "|   _   ||   | ||  |  _    ||    ___||   |_| ||  |_|  ||     __||  |_|  ||   _   |" << endl;
  cout << "|  | |  ||   |_||_ | | |   ||   |___ |       ||       ||    |   |       ||  | |  |" << endl;
  cout << "|  |_|  ||    __  || |_|   ||    ___||  _    ||       ||    |__ |       ||  |_|  |" << endl;
  cout << "|       ||   |  | ||       ||   |___ | | |   ||   _   ||       ||   _   ||       |" << endl;
  cout << "|_______||___|  |_||______| |_______||_|  |__||__| |__||_______||__| |__||_______|" << endl;     
  cout << "                                                        __| |                     " << endl;
  cout << "                                                       |____|                      " reset << endl;
  cout << "=============================================================================================" << endl;
}

void result_print(string entrada, int qtd_elementos, int cont_bbs, int cont_ins, int cont_sel){
  cout << magenta_N "\n  ----------------" reset "VETOR DE ENTRADA " ciano_N << setw(11) << entrada
    << magenta_N "-----------------" << endl;
  cout << "  |   " reset "Tamanho" magenta_N "    |   " reset "Número de acesso do vetor pelo método" magenta_N "    |" << endl;
  cout << "  |   " reset "do Vetor" magenta_N "   |    " reset "Bubble" magenta_N "    |  " reset 
    "Selection" magenta_N "   |   " reset "Insertion" magenta_N "  |" << endl;
  cout << "  -------------------------------------------------------------" << endl;
  cout << "  |" verde_N << setw(10) << qtd_elementos << magenta_N "    |  " verde_N << setw(10) << cont_bbs 
    << magenta_N "  |  " verde_N << setw(10) << cont_sel << magenta_N "  |  " verde_N << setw(10) 
    << cont_ins << magenta_N "  |" << endl;
  cout << "  -------------------------------------------------------------" reset << endl;
}

void result_to_file(int vetor[], int intervalo, int n){
  int cont_bbs, cont_ins, cont_sel;
  cont_bbs = cont_ins = cont_sel = 0;
  for (int i = intervalo; i <= n; i += intervalo){
    cont_bbs = bubblesort(vetor, i);
    cont_ins = insertionsort(vetor, i);
    cont_sel = selectionsort(vetor, i);
    exit_file("ALEATORIO.txt", i, cont_bbs, cont_ins, cont_sel );
  }
  for (int i = intervalo; i <= n; i += intervalo){
    ordena_vetor(vetor, i, "cresc");
    cont_bbs = bubblesort(vetor, i);
    cont_ins = insertionsort(vetor, i);
    cont_sel = selectionsort(vetor, i);
    exit_file("CRESCENTE.txt", i, cont_bbs, cont_ins, cont_sel );

    ordena_vetor(vetor, i, "dec");
    cont_bbs = bubblesort(vetor, i);
    ordena_vetor(vetor, i, "dec");
    cont_ins = insertionsort(vetor, i);
    ordena_vetor(vetor, i, "dec");
    cont_sel = selectionsort(vetor, i);
    exit_file("DECRESCENTE.txt", i, cont_bbs, cont_ins, cont_sel );
  }
}
