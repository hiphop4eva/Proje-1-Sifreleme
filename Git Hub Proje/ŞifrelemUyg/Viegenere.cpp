#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX 50

char metin[50];
char sifre[50];

int alfabeBoyut;

void sifrele(char[], char[]);
void sifreCozumu(char[], char[]);
int bul(char[], char);

int main() {
    char alfabe[] = "abcdefghijklmnopqrstuvwyz";

    alfabeBoyut = strlen(alfabe);

    printf("Metin: ");
    scanf_s("%s", metin, MAX);
    printf("Sifre: ");
    scanf_s("%s", sifre, MAX);

    sifrele(alfabe, sifre);
    printf("Sifrelenmis Metin: %s\n", metin);

    sifreCozumu(alfabe, sifre);
    printf("Cozulmus metin: %s\n", metin);

    return 0;
}

void sifrele(char alfabe[], char sifre[]) {
    int boyut = strlen(metin);
    int sifreboyut = strlen(sifre);
    int j = 0;

    for (int i = 0; i < boyut; i++, j++) {
        if (j >= sifreboyut)
            j = 0;
        int metinsira = bul(alfabe, metin[i]);
        int sifresira = bul(alfabe, sifre[j]);

        if (metinsira != -1 && sifresira != -1) {
            metinsira = (metinsira + sifresira) % strlen(alfabe);
            metin[i] = alfabe[metinsira];
        }
    }
}

void sifreCozumu(char alfabe[], char sifre[]) {
    int i, j = 0, sira, sifresira;
    int metinBoyut = strlen(metin);
    int sifreBoyut = strlen(sifre);

    for (i = 0; i < metinBoyut; i++, j++) {

        if (j >= sifreBoyut)
            j = 0;
        sira = bul(alfabe, metin[i]);
        sifresira = bul(alfabe, sifre[j]);

        if (sira != -1 && sifresira != -1) {
            sira = (sira - sifresira) % alfabeBoyut;
            metin[i] = alfabe[sira];
        }
    }
}

int bul(char alfabe[], char aranan) {
    for (int i = 0; alfabe[i] != '\0'; i++) {
        if (aranan == alfabe[i])
            return i;
    }
    return -1;
}
