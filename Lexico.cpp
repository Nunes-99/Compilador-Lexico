#include "Lexico.h"

void Lexico::AnalisadorLexico()
{
	int num;
	string frase;

	cout<<"Digite um texto com numeros e operadotes"<<endl;
	getline(cin,frase);

	// define lista de padrões
	map<string,string> padroes {
		{ "[0-9]+" ,   "Numeros" },
		{ "[()]+" ,   "Pontuacao" },
		{ "^[A-Z]+[a-z]", "Identificadores"},
		{ "[+-/*]+",  "Operadores" }
	};

	// define padrão de regex
	map< unsigned int, pair<string,string> > combinar;

	for ( auto padrao = padroes.begin(); padrao != padroes.end(); padrao++ )
	{
		regex reg(padrao->first);
		auto palavra_begin = sregex_iterator( frase.begin(), frase.end(), reg );
		auto palavra_end   = sregex_iterator();

		for ( auto i = palavra_begin; i != palavra_end; i++ )
			combinar[ i->position() ] = make_pair( i->str(), padrao->second );
	}
	
	for ( auto combine = combinar.begin(); combine != combinar.end(); ++combine )
		cout<< combine->second.first << " -> " << combine->second.second << endl;		
}
