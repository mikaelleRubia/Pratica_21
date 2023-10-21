#include <iostream>
#include <vector>

using namespace std;

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
class Emprestimo{
    private:
        string nomeLivro;
        string nomeUsuario;
        string dataEmprestimo;
        string dataDevolucao;

        
    public:
        Emprestimo( string _nomeLivro, string _nomeUsuario, string _dataEmprestimo, string _dataDevolucao){          
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


        string getTitulo() const;
        void setTitulo(string _titulo);
        string getAutor() const;
        void setAutor(string _autor);
        int getNumero_copias() const;
        void setNumero_copias(int _numero_copias);
        
};

class Biblioteca{

    public:
    static void addLivroBiblioteca(vector <Livro> &livros, const Livro& livro);
    static void listaLivroBiblioteca(vector <Livro> &livros);
    static void removerLivroBiblioteca(vector <Livro> &livros, const Livro& livro);
    static void realizarEmprestimo(vector<Emprestimo> &, Usuario &, Livro &, string);
};

int main()
{
    vector<Livro> livros;
    Livro livro1("Titulo 1", "Autor 1", 3);
    Livro livro2("Titulo 2", "Autor 2", 5);
    Livro livro3("O Senhor dos Aneis", "J.R.R. Tolkien", 10);

    Biblioteca::addLivroBiblioteca(livros, livro1);
    Biblioteca::addLivroBiblioteca(livros, livro2);
    Biblioteca::addLivroBiblioteca(livros, livro3);

    Biblioteca::listaLivroBiblioteca(livros);


   
    cout << "Titulo: " << livro1.getTitulo() << endl;
    cout << "Autor: " << livro1.getAutor() << endl;
    cout << "Numero de copias: " << livro1.getNumero_copias() << endl;

    livro1.setNumero_copias(5);


    // Criando um usuario
    Usuario usuario1("Danilo", "123456789");

    cout << endl;
    cout << "---Usuario---" << endl;
  
    cout << "Nome do usuario: " << usuario1.getNome() << endl;
    cout << "CPF do usuario: " << usuario1.getCpf() << endl;

    // Criando um emprestimo
    Emprestimo emprestimo1("O Senhor dos Aneis", "Joao", "2023-10-21", "2023-11-21");

    cout << endl;
    cout << "---Emprestimo---" << endl;
    
    cout << "Livro emprestado: " << emprestimo1.getNomeLivro() << endl;
    cout << "Nome do usuario: " << emprestimo1.getNomeUsuario() << endl;
    cout << "Data de emprestimo: " << emprestimo1.getDataEmprestimo() << endl;
    cout << "Data de devolucao: " << emprestimo1.getDataDevolucao() << endl;
    return 0;

    return 0;
}

//////Getters e Setters  Livros////

string Livro::getTitulo() const {
    return titulo;
}
void Livro::setTitulo(string _titulo){
        titulo = _titulo;
    }

string Livro::getAutor() const {
    return autor;
}
void Livro::setAutor(string _autor){
        autor = _autor;
    }

int Livro::getNumero_copias() const {
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

string Emprestimo::getNomeLivro(){
    return nomeLivro;
}
void Emprestimo::setNomeLivro(string _nomeLivro){
    nomeLivro = _nomeLivro;
}
string Emprestimo::getNomeUsuario(){
    return nomeUsuario;
}
void Emprestimo::setNomeUsuario(string _nomeUsuario){
    nomeUsuario = _nomeUsuario;
}
string Emprestimo::getDataEmprestimo(){
    return dataEmprestimo;
}
void Emprestimo::setDataEmprestimo(string _dataEmprestimo){
    dataEmprestimo = _dataEmprestimo;
}
string Emprestimo::getDataDevolucao(){
    return dataDevolucao;
}
void Emprestimo::setDataDevolucao(string _dataDevolucao){
    dataDevolucao = _dataDevolucao;
}


void Biblioteca::addLivroBiblioteca(vector <Livro> &livros, const Livro& livro){
    for (const auto& liv : livros) {
        if (liv.getAutor() == livro.getAutor() && liv.getTitulo() == livro.getTitulo()) {
            cout << "Livro já cadastrado" << endl;
            return;
        }
    }
        livros.push_back(livro);
}

void Biblioteca::listaLivroBiblioteca(vector <Livro> &livros){
    cout << "---Lista de Livros---" << endl;

    for (const auto& liv : livros) {
        cout << "-----------------------------" << endl;
        cout << "Autor: " << liv.getAutor() << endl;
        cout << "Titulo: " << liv.getTitulo() << endl;
        cout << "Numeros de copias: " << liv.getNumero_copias() << endl;
        cout << endl;
        
    }
}

void Biblioteca::removerLivroBiblioteca(vector <Livro> &livros, const Livro& livro){
    for (int i = 0; i < livros.size(); i++){
        if (livros[i].getAutor() == livro.getAutor() && livros[i].getTitulo() == livro.getTitulo()) {
            livros.erase(livros.begin() + i);
            return;
        }
    }
        livros.push_back(livro);
}

void Biblioteca::realizarEmprestimo(vector<Emprestimo> &emprestimos, Usuario &usuario, Livro &livro, string data){
    Emprestimo emprestimo = Emprestimo(livro.getTitulo(), usuario.getNome(), data, "Em andamento");

    emprestimos.push_back(emprestimo);
}
  