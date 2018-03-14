
class Evento {
public:
	// Construtor sem parâmetros da classe Evento
	Evento();

	// Construtores de todos os tipos possíveis de Eventos
	Evento(int tipo, double horaDeOcorrencia, Pista* local1, Pista* local2, Veiculo* veiculo);
	Evento(int tipo, double horaDeOcorrencia, Pista* local1, Veiculo* veiculo);
	Evento(int tipo, double horaDeOcorrencia, Pista* local1, Pista* local2);
	// Destrutor da classe Evento
	~Evento();

	// Retorna o valor inteiro correspondente ao "tipo" do Evento
	int getTipo();

	// Retorna o valor "double" correspondente ao horário de ocorrência do Evento
	double getHorario();

	// Retornam os ponteiros das pistas envolvidas no Evento
	Pista* getLocal1();
	Pista* getLocal2();

	// Retorna o veículo envolvido no Evento (caso exista)
	Veiculo* getVeiculo();

	// Sobrescritas dos operadores "<" e ">"
	inline bool operator< (const Evento& lhs) {return this->_horaDeOcorrencia < lhs._horaDeOcorrencia;}
	inline bool operator> (const Evento& lhs) {return this->_horaDeOcorrencia > lhs._horaDeOcorrencia;}

private:
	int _tipo;
	int _horaDeOcorrencia;
	Pista* _local1;
	Pista* _local2;
	Veiculo* _veiculo;
};


Evento::Evento() {
	_tipo = 0;
	_horaDeOcorrencia = 0;
	_local1 = NULL;
	_local2 = NULL;
	_veiculo = NULL;
}

Evento::Evento(int tipo, double horaDeOcorrencia, Pista* local1, Pista* local2, Veiculo* veiculo) {
	_tipo = tipo;
	_horaDeOcorrencia = horaDeOcorrencia;
	_local1 = local1;
	_local2 = local2;
	_veiculo = veiculo;
}

Evento::Evento(int tipo, double horaDeOcorrencia, Pista* local1, Veiculo* veiculo) {
	_tipo = tipo;
	_horaDeOcorrencia = horaDeOcorrencia;
	_local1 = local1;
	_local2 = NULL;
	_veiculo = veiculo;
}

Evento::Evento(int tipo, double horaDeOcorrencia, Pista* local1, Pista* local2) {
	_tipo = tipo;
	_horaDeOcorrencia = horaDeOcorrencia;
	_local1 = local1;
	_local2 = local2;
	_veiculo = NULL;
}

Evento::~Evento() {}

int Evento::getTipo() {
	return _tipo;
}

double Evento::getHorario() {
	return _horaDeOcorrencia;
}

Pista* Evento::getLocal1() {
	return _local1;
}

Pista* Evento::getLocal2() {
	return _local2;
}

Veiculo* Evento::getVeiculo() {
	return _veiculo;
}
