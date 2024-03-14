#include <iostream>
#include <string>

// XOR þifreleme fonksiyonu
std::string xorEncryptDecrypt(const std::string &input, const std::string &key) {
    std::string output = input;
    for (size_t i = 0; i < input.size(); ++i) {
        output[i] = input[i] ^ key[i % key.size()]; // Her karakteri anahtarla XOR iþlemi yap
    }
    return output;
}

int main() {
    std::string key;
 
   std::cout << "Lütfen bir þifreleme anahtarý girin: ";
    std::cin >> key;
    std::cin.ignore(); // getline'dan önce getline'ýn tamamýný almasýný saðlamak için gereklidir
    std::string plaintext;
    std::cout << "Þifrelemek istediðiniz metni girin: ";
    std::getline(std::cin, plaintext);

    // Þifreleme
    std::string ciphertext = xorEncryptDecrypt(plaintext, key);
    std::cout << "Þifrelenmiþ metin: " << ciphertext << std::endl;

    // Þifre çözme (Opsiyonel, þifrelenmiþ metni çözmek için)
    //std::string decryptedText = xorEncryptDecrypt(ciphertext, key);
    //std::cout << "Çözülmüþ metin: " << decryptedText << std::endl;

    return 0;}
