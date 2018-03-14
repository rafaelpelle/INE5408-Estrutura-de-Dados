/*! Copyright <Rafael Pelle> <Juan Cuttle> [2015]
 * \class LeituraEscrita
 * \author Rafael Pelle
 * \author Juan Cuttle
 * \since 30/06/15
 * \version 1.0
 *
 * A classe realiza as operações de leitura e escrita em disco do trabalho de
 * implementação 2 de Estrutura de Dados (Indexação e busca de texto usando listas invertidas).
 */

#include <iostream>
#include "NoAVL.hpp"
#include "ListaEnc.hpp"
using namespace std;


struct ManPage {
	char comando[255];
	char conteudo[143360];

    bool operator>(const ManPage& outra) const {
    	return (strcmp(this->comando, outra.comando) > 0);
    }
    bool operator<(const ManPage& outra) const {
    	return (strcmp(this->comando, outra.comando) < 0);
    }
    bool operator==(const ManPage& outra) const {
    	return (strcmp(this->comando, outra.comando) == 0);
    }
    bool operator!=(const ManPage& outra) const {
    	return (strcmp(this->comando, outra.comando) != 0);
    }
};


struct IndicePrimario {
	char chave[255];
	int enderecoDoRegistro;

    bool operator>(const IndicePrimario& outro) const {
    	return (strcmp(this->chave, outro.chave) > 0);
    }
    bool operator<(const IndicePrimario& outro) const {
    	return (strcmp(this->chave, outro.chave) < 0);
    }
    bool operator==(const IndicePrimario& outro) const {
    	return (strcmp(this->chave, outro.chave) == 0);
    }
    bool operator!=(const IndicePrimario& outro) const {
    	return (strcmp(this->chave, outro.chave) != 0);
    }
};

struct IndiceSecundario {
	char chave[100];
	int qtdRegistros;
	int endListaEnderecos;

	bool operator>(const IndiceSecundario& outro) const {
   		return (strcmp(this->chave, outro.chave) > 0);
    }
	bool operator<(const IndiceSecundario& outro) const {
   		return (strcmp(this->chave, outro.chave) < 0);
    }
	bool operator==(const IndiceSecundario& outro) const {
   		return (strcmp(this->chave, outro.chave) == 0);
    }
	bool operator!=(const IndiceSecundario& outro) const {
   		return (strcmp(this->chave, outro.chave) != 0);
    }
};


struct ListaDeEnderecos {
	int endRegistros[5642];
};


class LeituraEscrita {
private:
	// Lê do disco o registro de ManPage que está, em manpages.dat, na posição passada como parâmetro.
	static ManPage leManPage(int posicao);
	// Le do disco o IndicePrimario que está, em indicePrimario.dat, na posição passada como parâmetro.
	static IndicePrimario leIndicePrimario(int posicao);
	// Lê do disco o IndiceSecundario que está, em indiceSecundario.dat, na posição passada como parâmetro.
	static IndiceSecundario leIndiceSecundario(int posicao);
	// Escreve no disco um IndiceSecundario, em indiceSecundario.dat, na posição passsada como parâmetro.
	static void escreveIndiceSecundario(IndiceSecundario* is, int posicao, FILE* arquivo);
	// Transforma a árvore indexPrimario em um vetor. A posição é usada para recursivamente escrever os nós filhos
	// no mesmo vetor.
	static void transformaArvorePrimariaEmVetor(NoAVL<IndicePrimario>* indexPrimario, IndicePrimario* vetor, int posicao);
	// Busca uma chave em indiceSecundario.dat. A posição é usada para recursivamente procurar os nós filhos
	// no mesmo arquivo.
	static IndiceSecundario buscaUmIndiceSecundario(const char* chave, int posicao);

public:
	// Construtor e destrutor não são usados. Todos os métodos da classe são declarados static.
	LeituraEscrita();
	~LeituraEscrita();
	// Retorna a quantidade de arquivos e o nome dos arquivos que foram encontrados no caminho
	// passado como parâmetro.
	static glob_t getNomeDosArquivosTXT(const char* caminho);
	// Retorna um registro de ManPage contendo o comando e o conteúdo de uma manpage.txt.
	static ManPage leManPageTXT(const char* nomeDoArquivo);
	// Le do disco a ListaDeEnderecos que está, em listasDeEnderecos.dat, na posição passada como parâmetro.
	static ListaDeEnderecos leListaDeEnderecos(int posicao);
	// Escreve no disco uma ListaDeEnderecos, em listasDeEnderecos.dat, na posição passsada como parâmetro.
	static void escreveListaDeEnderecos(ListaDeEnderecos* lista, int posicao, FILE* arquivo);
	// Chama a função transformaArvorePrimariaEmVetor e escreve esse vetor em indicePrimario.dat.
	static void escreveArvoreIndexPrimario(NoAVL<IndicePrimario>* indexPrimario, int tamanhoDaArvore);
	// Percorre, recursivamente, a árvore usando a posição para escrevê-la em indiceSecundario.dat.
	static void escreveArvoreIndexSecundario(NoAVL<IndiceSecundario>* indexSecundario, int posicao, FILE* arquivo);
	// Procura um IndicePrimario, em indexPrimario.dat, e quando a chave é encontrada
	// retorna o registro de ManPage na posição apontada.
	static ManPage buscaPorChavePrimaria(const char* chave, int posicao);
	// Busca um IndiceSecundario, em indexSecundario.dat, lê a ListaDeEnderecos que esse índice aponta
	// e retorna uma ListaEnc<ManPage> com todos os registros endereçados na lista.
	static ListaEnc<ManPage> buscaPorChaveSecundaria(const char* chave);
};


LeituraEscrita::LeituraEscrita() {}

LeituraEscrita::~LeituraEscrita() {}

glob_t LeituraEscrita::getNomeDosArquivosTXT(const char* caminho) {
	glob_t data;
	switch (glob(caminho, 0, NULL, &data)) {
	case 0:
		break;
	case GLOB_NOSPACE:
		printf("Sem memória\n");
		break;
	case GLOB_ABORTED:
		printf("Erro de leitura\n");
		break;
	case GLOB_NOMATCH:
		printf("Nenhum arquivo encontrado\n");
		break;
	}
	return data;
}

ManPage LeituraEscrita::leManPageTXT(const char* nomeDoArquivo) {
	ManPage mp;
	strcpy(mp.comando, nomeDoArquivo);
	memmove(mp.comando, mp.comando + 9, (246) / sizeof(mp.comando[0]));  // Remove os primeiros 9 caracteres (ManPages/).
	mp.comando[strlen(mp.comando)-4] = 0;  // Descarta os últimos 4 caracteres (.txt).
	FILE* arquivo = fopen(nomeDoArquivo, "rb");
	if(arquivo == NULL) {
		throw "Erro ao abrir o arquivo.";
	} else {
		fseek(arquivo, 0, SEEK_END);
		long tamanhoDoArquivo = ftell(arquivo);
		rewind(arquivo);
		fread(mp.conteudo, tamanhoDoArquivo, 1, arquivo);
		fclose(arquivo);
		return mp;
	}
}

ManPage LeituraEscrita::leManPage(int posicao) {
	ManPage mp;
	FILE* arquivo = fopen("manpages.dat", "rb");
	if (arquivo == NULL) {
		throw "Erro ao abrir arquivo.";
	} else {
		fseek(arquivo, posicao * sizeof(struct ManPage), SEEK_SET);
		fread((char*)&mp, sizeof(struct ManPage), 1, arquivo);
		fclose(arquivo);
	}
	return mp;
}

IndicePrimario LeituraEscrita::leIndicePrimario(int posicao) {
	IndicePrimario ip;
	FILE* arquivo = fopen("indicePrimario.dat", "rb");
	if (arquivo == NULL) {
		throw "Erro ao abrir arquivo.";
	} else {
		fseek(arquivo, posicao * sizeof(struct IndicePrimario), SEEK_SET);
		fread((char*)&ip, sizeof(struct IndicePrimario), 1, arquivo);
		fclose(arquivo);
	}
	return ip;
}

IndiceSecundario LeituraEscrita::leIndiceSecundario(int posicao) {
	IndiceSecundario is;
	FILE* arquivo = fopen("indiceSecundario.dat", "rb");
	if (arquivo == NULL) {
		throw "Erro ao abrir arquivo.";
	} else {
		fseek(arquivo, posicao * sizeof(struct IndiceSecundario), SEEK_SET);
		fread((char*)&is, sizeof(struct IndiceSecundario), 1, arquivo);
		fclose(arquivo);
	}
	return is;
}

ListaDeEnderecos LeituraEscrita::leListaDeEnderecos(int posicao) {
	ListaDeEnderecos lr;
	FILE* arquivo = fopen("listasDeEnderecos.dat", "rb");
	if (!arquivo) {
		throw "Erro ao abrir o arquivo!";
	}
	fseek(arquivo, posicao * sizeof(struct ListaDeEnderecos), SEEK_SET);
	fread((char*) &lr, sizeof(struct ListaDeEnderecos), 1, arquivo);
	fclose(arquivo);
	return lr;
}

void LeituraEscrita::escreveIndiceSecundario(IndiceSecundario* is, int posicao, FILE* arquivo) {
	if (!arquivo) {
		throw "Erro ao abrir o arquivo!";
	}
	fseek(arquivo, posicao * sizeof(struct IndiceSecundario), SEEK_SET);
	fwrite((char*) is, sizeof(struct IndiceSecundario), 1, arquivo);
}

void LeituraEscrita::escreveListaDeEnderecos(ListaDeEnderecos* lista, int posicao, FILE* arquivo) {
	if (!arquivo) {
		throw "Erro ao abrir o arquivo!";
	}
	fseek(arquivo, posicao * sizeof(struct ListaDeEnderecos), SEEK_SET);
	fwrite((char*) lista, sizeof(struct ListaDeEnderecos), 1, arquivo);
}

void LeituraEscrita::escreveArvoreIndexPrimario(NoAVL<IndicePrimario>* indexPrimario, int tamanhoDaArvore) {
	if (indexPrimario != NULL) {
		int posicao = 0;
		int tamanhoDoVetor = tamanhoDaArvore * 2;
		IndicePrimario ip;
		IndicePrimario vetor[tamanhoDoVetor];
		LeituraEscrita::transformaArvorePrimariaEmVetor(indexPrimario, vetor, posicao);
		FILE* arquivo = fopen("indicePrimario.dat", "wb");
		if (arquivo != NULL) {
			for(int i = 0; i < tamanhoDoVetor; i++) {
				ip = vetor[i];
				fwrite((char*)&ip, sizeof(struct IndicePrimario), 1, arquivo);
			}
			fclose(arquivo);
		} else {
			throw "Erro ao abrir arquivo.";
		}
	}
}

void LeituraEscrita::escreveArvoreIndexSecundario(NoAVL<IndiceSecundario>* indexSecundario, int posicao, FILE* arquivo) {
	if (indexSecundario != NULL) {
		IndiceSecundario* is = indexSecundario->getDado();
		LeituraEscrita::escreveIndiceSecundario(is, posicao, arquivo);
		int posicaoEsquerda = posicao * 2 + 1;
		int posicaoDireita = posicao * 2 + 2;
		LeituraEscrita::escreveArvoreIndexSecundario(indexSecundario->getEsquerda(), posicaoEsquerda, arquivo);
		LeituraEscrita::escreveArvoreIndexSecundario(indexSecundario->getDireita(), posicaoDireita, arquivo);

	}
}

void LeituraEscrita::transformaArvorePrimariaEmVetor(NoAVL<IndicePrimario>* indexPrimario, IndicePrimario* vetor, int posicao) {
	if (indexPrimario != NULL) {
		vetor[posicao] = *indexPrimario->getDado();
		int posicaoEsquerda = posicao * 2 + 1;
		int posicaoDireita = posicao * 2 + 2;
		LeituraEscrita::transformaArvorePrimariaEmVetor(indexPrimario->getEsquerda(), vetor, posicaoEsquerda);
		LeituraEscrita::transformaArvorePrimariaEmVetor(indexPrimario->getDireita(), vetor, posicaoDireita);
	}
}

ManPage LeituraEscrita::buscaPorChavePrimaria(const char* chave, int posicao) {
	ManPage mp;
	IndicePrimario ip = LeituraEscrita::leIndicePrimario(posicao);
	if (strcmp(chave, ip.chave) == 0) {
		mp = LeituraEscrita::leManPage(ip.enderecoDoRegistro);
	} else if (strcmp(chave, ip.chave) < 0) {
		mp = LeituraEscrita::buscaPorChavePrimaria(chave, posicao * 2 + 1);
	} else if (strcmp(chave, ip.chave) > 0) {
		mp = LeituraEscrita::buscaPorChavePrimaria(chave, posicao * 2 + 2);
	}
	return mp;
}

ListaEnc<ManPage> LeituraEscrita::buscaPorChaveSecundaria(const char* chave) {
	ListaEnc<ManPage> registrosBuscados = ListaEnc<ManPage>();
	IndiceSecundario is = buscaUmIndiceSecundario(chave, 0);
	ListaDeEnderecos lr = LeituraEscrita::leListaDeEnderecos(is.endListaEnderecos);
	for (int i = 0; i < is.qtdRegistros; i++) {
		registrosBuscados.adicionaNoInicio(LeituraEscrita::leManPage(lr.endRegistros[i]));
	}
	return registrosBuscados;
}

IndiceSecundario LeituraEscrita::buscaUmIndiceSecundario(const char* chave, int posicao) {
	IndiceSecundario is = LeituraEscrita::leIndiceSecundario(posicao);
	if (strcmp(chave, is.chave) == 0) {
		return is;
	} else if (strcmp(chave, is.chave) < 0) {
		is = LeituraEscrita::buscaUmIndiceSecundario(chave, posicao * 2 + 1);
	} else if (strcmp(chave, is.chave) > 0) {
		is = LeituraEscrita::buscaUmIndiceSecundario(chave, posicao * 2 + 2);
	}
	return is;
}
