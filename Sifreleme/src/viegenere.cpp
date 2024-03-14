#include "header.h"

namespace vieg {

    std::string sifrele(std::string& metin, std::string& sifre, std::string& alfabe) {
        std::string ret;
        
        int boyut = metin.length();
        int sifreboyut = sifre.length() - 1;
        int j = 0;

        ret.resize(boyut);

        for (int i = 0; i < boyut; i++, j++) {
            if (alfabe.find(metin[i]) == std::string::npos) {
                ret[i] = metin[i];
                j--;
            }
            if (j >= sifreboyut)
                j = 0;
            int metinsira = bul(alfabe, metin[i]);
            int sifresira = bul(alfabe, sifre[j]);

            if (metinsira != -1 && sifresira != -1) {
                metinsira = (metinsira + sifresira) % alfabe.length();
                ret[i] = (alfabe[metinsira]);
            }
        }
        return ret;
    }

    std::string sifreCozumu(std::string& metin, std::string& sifre, std::string& alfabe) {
        std::string ret;

        int i, j = 0, sira, sifresira;
        int metinBoyut = metin.length();
        int sifreBoyut = sifre.length() - 1;

        ret.resize(metinBoyut);

        for (i = 0; i < metinBoyut; i++, j++) {
            if (alfabe.find(metin[i]) == std::string::npos) {
                ret[i] = metin[i];
                j--;
            }
            if (j >= sifreBoyut)
                j = 0;
            sira = bul(alfabe, metin[i]);
            sifresira = bul(alfabe, sifre[j]);

            if (sira != -1 && sifresira != -1) {
                sira = (sira - sifresira) % alfabe.length();
                ret[i] = alfabe[sira];
            }
        }
        return ret;
    }

    int bul(std::string& alfabe, char aranan) {
        for (int i = 0; alfabe[i] != '\0'; i++) {
            if (aranan == alfabe[i])
                return i;
        }
        return -1;
    }

}