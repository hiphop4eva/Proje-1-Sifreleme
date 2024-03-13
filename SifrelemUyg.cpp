#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int alfabeBoyut;
char metin[50];
char sifre[50];

void sifrele(char[], char[]);
int bul(char[], char);

int main() {
	

	char alfabe[] = "abcdefghijklmnopqrstuvwyz";
	
	printf("Metin: ");
	scanf("%s",metin);
	printf("Sifre: ");
	scanf("%s",sifre);
	
	alfabeBoyut = strlen(alfabe);
	
	
	sifrele(alfabe, sifre);
	printf("Sifrelenmis Metin: %s", metin);

	
	return 0;
}

void sifrele(char alfabe[], char sifre[]) {
	int boyut,sifreboyut,i,j;
	int metinsira,sifresira;
	boyut = strlen(metin);
	sifreboyut = strlen(sifre);
	
	j=0;
	
	for (i=0; i<boyut; i++,j++) {
		if (j >= sifreboyut)
			j=0;
		metinsira = bul(alfabe,metin[i]);
		sifresira = bul(alfabe,sifre[j]);
		
		if (metinsira != -1 && sifresira != -1) {
			metinsira = (metinsira + sifresira) % alfabeBoyut;
			metin[i]= alfabe[metinsira];
		}
	}
}
	
int bul(char alfabe[], char aranan) {
	int i, sayac = 0;
	for (i=0; i<alfabeBoyut; i++) {
		if (aranan == alfabe[i])
			sayac = i;
	}
	return sayac;
}

