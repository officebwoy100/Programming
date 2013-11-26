#include <iostream>
#include <string>
using namespace std;
 
class Vigenere

{
public:
  string key;
 
  Vigenere(string key)
  {
    for(int i = 0; i < key.size(); ++i)
    {
      if(key[i] >= 'A' && key[i] <= 'Z')
        this->key += key[i];
      else if(key[i] >= 'a' && key[i] <= 'z')
        this->key += key[i] + 'A' - 'a';
    }
  }
 
  string encrypt(string text)
  {
    string out;
 
    for(int i = 0, j = 0; i < text.length(); ++i)
    {
      char c = text[i];
 
      if(c >= 'a' && c <= 'z')
        c += 'A' - 'a';
      else if(c < 'A' || c > 'Z')
        continue;
 
      out += (c + key[j] - 2*'A') % 26 + 'A'; 
      j = (j + 1) % key.length();
    }
 
    return out;
  }
 
  string decrypt(string text)
  {
    string out;
 
    for(int i = 0, j = 0; i < text.length(); ++i)
    {
      char c = text[i];
 
      if(c >= 'a' && c <= 'z')
        c += 'A' - 'a';
      else if(c < 'A' || c > 'Z')
        continue;
 
      out += (c - key[j] + 26) % 26 + 'A'; 
      j = (j + 1) % key.length();
    }
 
    return out;
  }
};
 
int main()
{
  string original , encrypted , decrypted, kunci;
  int pilih;
  cout <<"----------------------------------------------------" <<endl;
  cout <<"--------------------STMIK WIDURI--------------------" <<endl;
  cout <<"----------------------------------------------------" <<endl<<endl;
  cout <<"Silakan Pilih 1 untuk Encrypt dan 2 untuk Decrypt : "; cin>>pilih;cout<<endl;
  if (pilih == 1)
  {
          cout <<"Masukan Kunci : "; cin>>kunci;
          Vigenere cipher(kunci);
          cout <<"Masukan Input : "; cin>>original;
          cout <<"----------------------------------------------------" <<endl<<endl;
          cout << "Teks Asli : " << original << endl;
          encrypted = cipher.encrypt(original);
          cout << "Encrypted: " << encrypted << endl ;
          cout<<endl<<endl;
  }
  else if (pilih == 2)
  {
          cout <<"Masukan Kunci : "; cin>>kunci;
          Vigenere cipher(kunci);
          cout <<"Masukan Input : "; cin>>original;
          cout <<"----------------------------------------------------" <<endl<<endl;
          cout << "Teks Asli : " << original << endl;
          decrypted = cipher.decrypt(original);
          cout << "Decrypted: " << decrypted << endl ;
          cout<<endl<<endl;
          system("PAUSE");
  }
  else
          cout <<"Anda Salah Memasukkan kode\n\n";
          system("PAUSE");
}
