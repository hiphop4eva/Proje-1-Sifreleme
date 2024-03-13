#include "header.h"

using namespace std;

void Ceasar::sifrele()
{
	int x = metin.length();
	sifrelimetin.resize(x);

	for(int i = 0; i < x; i++)
	{
		if(isalpha(metin[i]))
		{
			char c = tolower(metin[i]);
			int indis = c - 'a';
			indis = (indis + kayma) % 26;
			sifrelimetin[i] = alfabe[indis];
		}
		else
		{
			sifrelimetin[i] = metin[i];
		}
	}
	sifrelimetin[x] = '\0';
}

void Ceasar::desifrele()
{
	int x = sifrelimetin.length();
	desifrelimetin.resize(x);
	
	for(int i = 0; i < x; i++)
	{
		if(isalpha(sifrelimetin[i]))
		{
			char c = tolower(sifrelimetin[i]);
			int indis = c - 'a';
			indis = (indis - kayma + 26) % 26;
			desifrelimetin[i] = alfabe[indis];
		}
		else
		{
			desifrelimetin[i] = sifrelimetin[i];
		}
	}
	desifrelimetin[x] = '\0';
}


