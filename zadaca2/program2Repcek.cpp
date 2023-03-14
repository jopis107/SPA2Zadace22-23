#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

class HashTable {
    private:
        vector<bool> collision; // niz za spremanje informacije o kolizijama

        // hash funkcije
       int h1(const string& s) {
            ull sum = 0;
            for (char c : s) {
                sum += (int) c % size;
            }
            return sum % size;
        }

        int h2(const string& s) {
            ull sum = 0;
            for (int i = 0; i < s.length(); i++) {
                sum += (int)(s[i] * pow(19, i)) % size;
            }
            return sum % size;
        }

        int h3(const string& s) {
            ull sum = 7;
            for (int i = 0; i < s.length(); i++) {
                sum += (s[i] * pow(30,i))
                sum %= size;
            }
            return sum % size;
        }

        int h4(const string& s) {
            ull sum = 3;
            int p = 7;
            for (int i = 0; i < s.length(); i++) {
                sum += (int)(s[i] * pow(3, i) * pow(p, i)) % size;
            }
            return sum % size;
        }

    public:
        int size; // veličina tablice
        string* table; // polje za spremanje usernamea
        // konstruktor
        HashTable(int size) {
            this->size = size;
            table = new string[size];
            collision = vector<bool>(size);
        }

        // funkcija za spremanje usernamea
        void insert(const string& s) {
            int index1 = h1(s);
            int index2 = h2(s);
            int index3 = h3(s);
            int index4 = h4(s);

            collision[index1] = true;
            collision[index2] = true;
            collision[index3] = true;
            collision[index4] = true;
        }

        // funkcija za pretragu usernamea
        string search(const string& s) {
            int index1 = h1(s);
            int index2 = h2(s);
            int index3 = h3(s);
            int index4 = h4(s);

            if (collision[index1] && collision[index2]  && collision[index3] && collision[index4]) {
                return "Element je vjerojatno u tablici";
            }
            else {
                return "Element nije u tablici";
            }
        }
};

int main(){
    HashTable ht(100);
    vector<string> names = {
        "jopis107", "hstranput", "Matej293", "MateaCucman", "JosipCestar", 
        "lanamak", "DanijelaValjak", "filipuranjek", "domagojziros", "lsanic",
        "TomislavVinkovic", "IvoSusac", "matej2810", "KresimirSecan", 
        "inespejic", "InesSimunovic", "IvanFrantal", "Frle001", "inesstrapac", 
        "mkolak", "Dpritisa", "istvavk", "mtoldi", "lbrodar5", "mkristic", 
        "andreamatasovic", "balentovicanja", "IvanaVinkovic", "prakidzija", 
        "DMV1204", "JMesaric", "KarloKampic", "jurick1910", "LarisaDarojkovic"
    };

    for(const auto& name : names) {
        ht.insert(name);
    }


    cout << ht.search("andreamatasovic") << endl;
    cout << ht.search("jopis107") << endl;
    
    //kod ovog primjera grijesi recimo
    cout << ht.search("tomoV") << endl;

    cout << ht.search("BraneBB") << endl;
    cout << ht.search("ivosulinjo") << endl;
    cout << ht.search("FilipU") << endl;
    return 0;
}


