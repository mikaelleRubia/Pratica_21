#include <iostream>

using namespace std;

class ItemBiblioteca{
    private:
        string titulo;
        string autor;
        int numero_copias;
    public:
        ItemBiblioteca(string _titulo, string _autor, int _numero_copias){
            titulo = _titulo;
            autor = _autor;
            numero_copias = _numero_copias;
        }
        string getTitulo(){
            return titulo;
        }
        void setTitulo(string _titulo){
            titulo = _titulo;
        }
        string getAutor(){
            return autor;
        }
        void setAutor(string _autor){
            autor = _autor;
        }
        int getNumero_copias(){
            return numero_copias;
        }
        void setNumero_copias(int _numero_copias){
            numero_copias = _numero_copias;
        }
};


int main()
{

    return 0;
}
