#include <iostream>
#include <string.h>
#include <glob.h>
#include "LeituraEscrita.hpp"
#include "NoAVL.hpp"
#include "NoAVLString.hpp"
#include "ListaEnc.hpp"
using namespace std;


NoAVL<IndicePrimario>* indexPrimario;      // Árvore de indexação primária.
NoAVL<IndiceSecundario>* indexSecundario;  // Árvore de indexação secundária.
NoAVLString* palavrasNaoIndexadas;         // Árvore com artigo, conjunção, preposição e pronome.
NoAVLString* palavrasDescartaveis;         // Árvore com as palavras de uma ManPage que já foram indexadas.
int contadorEndListaDeEnderecos;           // Contador de palavras distintas (usado em IndiceSecundario.endListaEnderecos).
FILE* arquivoEscritaRegistrosManPage;      // FILE* para escrever em manpages.dat
FILE* arquivoEscritaArvoreSecundaria;	   // FILE* para escrever em indiceSecundario.dat
FILE* arquivoEscritaListasDeEnderecos;     // FILE* para escrever em listasDeEnderecos.dat


void criaPalavrasNaoIndexadas() {
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("the", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("a", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("an", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("for", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("and", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("nor", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("but", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("or", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("yet", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("so", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("after", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("although", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("as", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("because", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("before", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("if", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("lest", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("once", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("since", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("than", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("that", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("though", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("till", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("unless", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("until", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("when", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("whenever", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("where", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("wherever", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("while", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("both", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("either", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("neither", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("whether", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("abaft", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("abeam", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("aboard", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("about", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("above", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("absent", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("across", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("afore", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("after", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("against", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("along", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("alongside", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("amid", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("amidst", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("among", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("amongst", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("apropos", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("around", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("aside", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("astride", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("at", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("atop", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("barring", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("before", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("behind", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("below", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("beneath", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("beside", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("besides", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("between", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("beyond", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("but", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("by", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("chez", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("circa", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("concerning", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("despite", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("down", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("during", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("except", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("excluding", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("failing", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("following", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("for", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("forenenst", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("from", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("given", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("in", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("including", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("inside", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("into", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("like", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("mid", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("midst", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("minus", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("modulo", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("near", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("next", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("notwithstanding", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("of", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("off", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("on", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("onto", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("opposite", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("out", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("outside", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("over", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("pace", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("past", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("per", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("plus", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("pro", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("regarding", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("round", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("save", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("since", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("than", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("through", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("throughout", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("to", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("times", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("towards", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("under", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("underneath", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("unlike", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("unto", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("up", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("upon", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("versus", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("via", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("vice", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("vs", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("with", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("within", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("without", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("worth", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("opposite of", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("opposite to", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("out from", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("out of", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("i", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("you", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("he", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("she", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("it", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("we", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("you", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("they", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("me", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("them", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("him", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("her", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("us", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("there", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("yours", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("mine", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("theirs", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("ours", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("hers", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("his", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("it's", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("this", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("these", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("those", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("one", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("ones", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("who", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("whose", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("what", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("which", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("myself", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("yourself", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("himself", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("herself", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("itself", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("ourselves", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("yourselves", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("themselves", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("somebody", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("anybody", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("nobody", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("everybody", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("someone", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("anyone", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("everyone", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("something", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("anything", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("nothing", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("everything", palavrasNaoIndexadas);
	palavrasNaoIndexadas = palavrasNaoIndexadas->inserir("whom", palavrasNaoIndexadas);
}

// Recebe uma palavra e cria um Indice Secundário com ela.
// Se esse índice já está na árvore indexSecundario, o índice buscado (is2) é atualizado
// e a ListaDeRegistros correspondente à is2 também é atualizada.
// Se esse índice não está na árvore indexSecundario, o indice é inserido (is)
// e uma ListaDeEnderecos é criada, atualizada e escrita em disco.
void atualizarIndiceSecundario(const char* palavra, int endManPage) {
	IndiceSecundario is;
	strcpy(is.chave, palavra);
	is.qtdRegistros = 1;
	is.endListaEnderecos = contadorEndListaDeEnderecos;
	IndiceSecundario* is2 = indexSecundario->busca(is, indexSecundario);
	bool contem = is2;
	if (contem) {
		ListaDeEnderecos lista = LeituraEscrita::leListaDeEnderecos(is2->endListaEnderecos);
		lista.endRegistros[is2->qtdRegistros] = endManPage;
		LeituraEscrita::escreveListaDeEnderecos(&lista, is2->endListaEnderecos, arquivoEscritaListasDeEnderecos);
		is2->qtdRegistros++;
	} else {
		ListaDeEnderecos lista;
		lista.endRegistros[0] = endManPage;
		LeituraEscrita::escreveListaDeEnderecos(&lista, is.endListaEnderecos, arquivoEscritaListasDeEnderecos);
		indexSecundario = indexSecundario->inserir(is, indexSecundario);
		contadorEndListaDeEnderecos++;
	}
}

// Percorre, palavra por palavra, o conteúdo de uma ManPage mp.
// Se a palavra não está em palavrasNaoIndexadas (artigo, conjunção, preposição e pronome)
// nem em palavrasDescartaveis (palavras que já foram indexadas nesta ManPage) ela é enviada
// para atualizarIndiceSecundario.
void lerPalavraPorPalavra(ManPage* mp, int endManPage) {
	palavrasDescartaveis = new NoAVLString("the");
	char* buffer;
	char conteudo[143360];
	strcpy(conteudo, mp->conteudo);
	buffer = strtok(conteudo, " .,!?()[]{}:;*/#@$<->\n");
	while (buffer != NULL) {
		string palavra(buffer);
		if (!palavrasNaoIndexadas->busca(palavra, palavrasNaoIndexadas) && !palavrasDescartaveis->busca(palavra, palavrasDescartaveis)) {
			palavrasDescartaveis = palavrasDescartaveis->inserir(palavra, palavrasDescartaveis);
			atualizarIndiceSecundario(buffer, endManPage);
		}
		buffer = strtok(NULL, " .,!?()[]{}:;*/#@$<->\n");
	}
	delete palavrasDescartaveis;
}


int main(int argc, char* argv[]) {
	clock_t tStart = clock();
	bool desejaDeletarOsArquivos = false;
	bool desejaRefazerOsIndices = true;

	if (desejaRefazerOsIndices) {
		// Lê o nome dos arquivos .txt do diretório Manpages.
		glob_t data = LeituraEscrita::getNomeDosArquivosTXT("ManPages/*.txt");
		char** listaDeNomes = data.gl_pathv;
		int quantidadeDeNomes = data.gl_pathc;


		// Cria uma árvore com palavras que não serão indexadas (artigo, conjunção, preposição e pronome),
		palavrasNaoIndexadas = new NoAVLString("The");
		criaPalavrasNaoIndexadas();


		// Abre os FILE* de escrita dos registros, escrita da árvore secundária e das listas de endereços de registro.
		arquivoEscritaRegistrosManPage = fopen("manpages.dat", "wb");
		arquivoEscritaArvoreSecundaria = fopen("indiceSecundario.dat", "wb");
		arquivoEscritaListasDeEnderecos = fopen("listasDeEnderecos.dat", "wb");
		if (!arquivoEscritaRegistrosManPage || !arquivoEscritaArvoreSecundaria || !arquivoEscritaListasDeEnderecos)
			throw "Erro ao abrir arquivo.";
		fseek(arquivoEscritaRegistrosManPage, 0, SEEK_SET);
		fseek(arquivoEscritaArvoreSecundaria, 0, SEEK_SET);
		fseek(arquivoEscritaListasDeEnderecos, 0, SEEK_SET);


		int i = 0;
		contadorEndListaDeEnderecos = 0;


		// Lê o primeiro arquivo .txt, cria uma ManPage chamada de mp. Lê o texto palavra por palavra, gerando um índice secundário
		// e escreve o registro (mp) em manpages.dat
		ManPage mp = LeituraEscrita::leManPageTXT(listaDeNomes[i]);
		lerPalavraPorPalavra(&mp, i);
		IndicePrimario ip;
		IndiceSecundario is;
		strcpy(ip.chave, mp.comando);
		strcpy(is.chave, "Descartável");
		ip.enderecoDoRegistro = i;
		indexPrimario = new NoAVL<IndicePrimario>(ip);
		indexSecundario = new NoAVL<IndiceSecundario>(is);
		fwrite(&mp, sizeof(struct ManPage), 1, arquivoEscritaRegistrosManPage);


		// Repete o processo para todos os outros arquivos .txt mostrando o progresso do loop.
		for (i = 1; i < quantidadeDeNomes; i++) {
			mp = LeituraEscrita::leManPageTXT(listaDeNomes[i]);
			lerPalavraPorPalavra(&mp, i);
			strcpy(ip.chave, mp.comando);
			ip.enderecoDoRegistro = i;
			indexPrimario = indexPrimario->inserir(ip, indexPrimario);
			fwrite(&mp, sizeof(struct ManPage), 1, arquivoEscritaRegistrosManPage);
			cout << "ManPage lida e indexada: " << i << endl;
		}


		// Escreve a árvore indexPrimario no disco na forma de um vetor.
		// Escreve a árvore indexSecundario no disco na forma de um vetor.
		// Todas as ListasDeEnderecos já são geradas no disco então não são escritas agora.
		LeituraEscrita::escreveArvoreIndexPrimario(indexPrimario, quantidadeDeNomes);
		LeituraEscrita::escreveArvoreIndexSecundario(indexSecundario, 0, arquivoEscritaArvoreSecundaria);


		// Fecha todos os FILE* e libera memória alocada dinamicamente.
		// A partir desse ponto todos os índices primários e secundários estão em disco e só serão realizadas buscas.
		fclose(arquivoEscritaRegistrosManPage);
		fclose(arquivoEscritaArvoreSecundaria);
		fclose(arquivoEscritaListasDeEnderecos);
		globfree (&data);
		delete indexPrimario;
		delete indexSecundario;
		delete palavrasNaoIndexadas;
	}


	//  Busca um registro de ManPage por chave primária e mostra na tela.
	ManPage resultadoBusca = LeituraEscrita::buscaPorChavePrimaria("Intro.1m", 0);
	cout << "Comando: " << resultadoBusca.comando << endl;
	cout << "Conteúdo: " << resultadoBusca.conteudo << endl;


	// Busca todos os registros que contém o índice secundário e
	// mostra na tela a quantidade de registros buscados.
	ListaEnc<ManPage> registrosBuscados1 = LeituraEscrita::buscaPorChaveSecundaria("Main");
	cout << "Registros buscados 1: " << registrosBuscados1.getTamanho() << endl;

	// Busca todos os registros que contém o índice secundário e
	// mostra na tela a quantidade de registros buscados.
	ListaEnc<ManPage> registrosBuscados2 = LeituraEscrita::buscaPorChaveSecundaria("Proc");
	cout << "Registros buscados 2: " << registrosBuscados2.getTamanho() << endl;


	// Gera uma lista de co-ocorrência entre as duas pesquisas por chave secundária.
	ListaEnc<ManPage> coocorrencia = ListaEnc<ManPage>();
	for (int i = 0; i < registrosBuscados1.getTamanho(); i++) {
		ManPage manpage = registrosBuscados1.retiraDoInicio();
		if (registrosBuscados2.contem(manpage)) {
			coocorrencia.adicionaNoInicio(manpage);
		}
	}


	// Mostra o comando de todas as ManPages co-ocorrentes na tela.
	for (int i = 0; i < coocorrencia.getTamanho(); i++) {
		cout << "Co-ocorrência: " << coocorrencia.retiraDoInicio().comando << endl;
	}

	// Se não deletar os arquivos novas buscas podem ser realizadas usando os mesmos índices prontos.
	if (desejaDeletarOsArquivos) {
		remove("manpages.dat");
		remove("indicePrimario.dat");
		remove("indiceSecundario.dat");
		remove("listasDeEnderecos.dat");
	}


	// Finaliza mostrando o tempo de execução na tela.
	cout << "Tempo de execução: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << " segundos." << endl;
	return 0;
}

