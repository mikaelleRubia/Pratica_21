#include <iostream>
#include <vector>

using namespace std;

class Livro{
    private:
        string titulo;
        string autor;
        int numero_copias;
        static vector<Livro> livros;
    public:
        Livro(string _titulo, string _autor, int _numero_copias){
            titulo = _titulo;
            autor = _autor;
            numero_copias = _numero_copias;
        }

        static void adicionarLivro(Livro livro);
        static bool emprestarLivro(const std::string& titulo, const std::string& nomeUsuario);
        static void listarLivros();
        static void listarLivrosEmprestadosPorUsuario(const std::string& nomeUsuario);


        string getTitulo();
        void setTitulo(string _titulo);
        string getAutor();
        void setAutor(string _autor);
        int getNumero_copias();
        void setNumero_copias(int _numero_copias);

};

class Usuario{
    private:
        string nome;
        string cpf;
    
    public:
        Usuario(string _nome, string _cpf){
            nome = _nome;
            cpf = _cpf;
        }

        string getNome();
        void setNome(string _nome);
        string getCpf();
        void setCpf(string _cpf);
            
       
};

class Emprestivo{
    private:
        string nomeLivro;
        string nomeUsuario;
        string dataEmprestimo;
        string dataDevolucao;

        
    public:
        Emprestivo( string _nomeLivro, string _nomeUsuario, string _dataEmprestimo, string _dataDevolucao){          
            nomeLivro = _nomeLivro;
            nomeUsuario = _nomeUsuario;
            dataEmprestimo = _dataEmprestimo;
            dataDevolucao = _dataDevolucao;
        }

        string getNomeLivro();
        void setNomeLivro(string _nomeLivro);
        string getNomeUsuario();
        void setNomeUsuario(string _nomeUsuario);
        string getDataEmprestimo();
        void setDataEmprestimo(string _dataEmprestimo);
        string getDataDevolucao();
        void setDataDevolucao(string _dataDevolucao);
};


int main()
{

    // Criando um livro
    Livro livro1("O Senhor dos Aneis", "J.R.R. Tolkien", 10);

   
    cout << "Titulo: " << livro1.getTitulo() << endl;
    cout << "Autor: " << livro1.getAutor() << endl;
    cout << "Numero de copias: " << livro1.getNumero_copias() << endl;

    livro1.setNumero_copias(5);


    // Criando um usuario
    Usuario usuario1("Danilo", "123456789");

  
    cout << "Nome do usuario: " << usuario1.getNome() << endl;
    cout << "CPF do usuario: " << usuario1.getCpf() << endl;

    // Criando um emprestimo
    Emprestivo emprestimo1("O Senhor dos Aneis", "Joao", "2023-10-21", "2023-11-21");

    
    cout << "Livro emprestado: " << emprestimo1.getNomeLivro() << endl;
    cout << "Nome do usuario: " << emprestimo1.getNomeUsuario() << endl;
    cout << "Data de emprestimo: " << emprestimo1.getDataEmprestimo() << endl;
    cout << "Data de devolucao: " << emprestimo1.getDataDevolucao() << endl;
    return 0;
}

//////Getters e Setters  Livros////


    string Livro::getTitulo(){
        return titulo;
    }
    void Livro::setTitulo(string _titulo){
        titulo = _titulo;
    }
    string Livro::getAutor(){
        return autor;
    }
    void Livro::setAutor(string _autor){
        autor = _autor;
    }
    int Livro::getNumero_copias(){
        return numero_copias;
    }
    void Livro::setNumero_copias(int _numero_copias){
        numero_copias = _numero_copias;
    }


 //////Getters e Setters  Usuarios////

    string Usuario::getNome(){
        return nome;
    }
    void Usuario::setNome(string _nome){
        nome = _nome;
    }

    string Usuario::getCpf(){
        return cpf;
    }

    void Usuario::setCpf(string _cpf){
        cpf = _cpf;
    }


 //////Getters e Setters  Emprestimo////

    string Emprestivo::getNomeLivro(){
        return nomeLivro;
    }
    void Emprestivo::setNomeLivro(string _nomeLivro){
        nomeLivro = _nomeLivro;
    }
    string Emprestivo::getNomeUsuario(){
        return nomeUsuario;
    }
    void Emprestivo::setNomeUsuario(string _nomeUsuario){
        nomeUsuario = _nomeUsuario;
    }
    string Emprestivo::getDataEmprestimo(){
        return dataEmprestimo;
    }
    void Emprestivo::setDataEmprestimo(string _dataEmprestimo){
        dataEmprestimo = _dataEmprestimo;
    }
    string Emprestivo::getDataDevolucao(){
        return dataDevolucao;
    }
    void Emprestivo::setDataDevolucao(string _dataDevolucao){
        dataDevolucao = _dataDevolucao;
    }


