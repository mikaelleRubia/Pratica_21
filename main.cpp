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

class Livro{
    private:
        string titulo;
        string autor;
        int numero_copias;
        int qtd_emprestado; // Adicionei esse atributo para poder contar quantas copias desse livro foram emprestados
    public:
        Livro(string _titulo, string _autor, int _numero_copias){
            titulo = _titulo;
            autor = _autor;
            numero_copias = _numero_copias;
            qtd_emprestado = 0;
        }

        string tostring() const;

        string getTitulo() const;
        void setTitulo(string _titulo);
        string getAutor() const;
        void setAutor(string _autor);
        int getNumero_copias() const;
        void setNumero_copias(int _numero_copias);
        int getQtd_emprestado() const;
        void setQtd_emprestado(int _qtd_emprestado);
        
};

class Emprestimo{
    private:
        Livro *livro;
        Usuario *usuario; 
        string dataEmprestimo;
        string dataDevolucao;

        
    public:
        Emprestimo( Livro *_Livro, Usuario *_Usuario, string _dataEmprestimo, string _dataDevolucao){          
            livro = _Livro;
            usuario = _Usuario;
            dataEmprestimo = _dataEmprestimo;
            dataDevolucao = _dataDevolucao;
            livro->setQtd_emprestado(livro->getQtd_emprestado() + 1);
        }

        Livro getLivro();
        void setLivro(Livro *_Livro);
        Usuario getUsuario();
        void setUsuario(Usuario *_usuario);
        string getDataEmprestimo();
        void setDataEmprestimo(string _dataEmprestimo);
        string getDataDevolucao();
        void setDataDevolucao(string _dataDevolucao);
};

class Biblioteca{
    public:
    static void addLivroBiblioteca(vector <Livro> &livros, const Livro& livro);
    static void listaLivroBiblioteca(vector <Livro> &livros);
    static void removerLivroBiblioteca(vector <Livro> &livros, const Livro& livro);
    static void realizarEmprestimo(vector<Emprestimo> &, Usuario &, Livro &, string);
};

bool disponibilidadeLivro(const Livro& _livro, const vector<Livro> &livros){
    for (auto &livro : livros){
        if (_livro.getTitulo() == livro.getTitulo()){
            if(_livro.getQtd_emprestado() < _livro.getNumero_copias()){
                return true;
            }
        }
    }
    return false;
}

void ListarLivros_Por_Usuario(Usuario &usuario,vector<Emprestimo> &emprestimos){
    cout << "\nLivros emprestados para " << usuario.getNome() << ":" << endl;
    cout << "_________________________________________________________________" << endl;
    for (Emprestimo emprestimo : emprestimos){
        if (emprestimo.getUsuario().getNome() == usuario.getNome()){
            cout << "Titulo: " << emprestimo.getLivro().getTitulo() << endl;
            cout << "Autor: " << emprestimo.getLivro().getAutor() << endl;
            cout << "_________________________________________________________________" << endl;
        }
    }
}


int main()
{
    vector<Emprestimo> emprestimos;

    vector<Livro> livros;
    Livro livro1("Titulo 1", "Autor 1", 3);
    Livro livro2("Titulo 2", "Autor 2", 5);
    Livro livro3("O Senhor dos Aneis", "J.R.R. Tolkien", 10);
    Livro livro4("Amantes aventureiros", "J.R.R. Tolkien", 1);

    Biblioteca::addLivroBiblioteca(livros, livro1);
    Biblioteca::addLivroBiblioteca(livros, livro2);
    Biblioteca::addLivroBiblioteca(livros, livro3);
    Biblioteca::addLivroBiblioteca(livros, livro4);

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
    Emprestimo emprestimo1(&livro1, &usuario1, "2023-10-21", "2023-11-21");
    


    cout << endl;
    cout << "---Emprestimo---" << endl;
    
    cout << "Livro emprestado: " << emprestimo1.getLivro().getTitulo() << endl;
    cout << "Nome do usuario: " << emprestimo1.getUsuario().getNome() << endl;
    cout << "Data de emprestimo: " << emprestimo1.getDataEmprestimo() << endl;
    cout << "Data de devolucao: " << emprestimo1.getDataDevolucao() << endl;

    cout << endl;
    cout << "Verificando disponibilidade do livro: ";
    cout << livro4.getTitulo() << endl;
    cout << endl;
    // Verificando disponibilidade do livro
    if (disponibilidadeLivro(livro4, livros)){
        Emprestimo emprestimo2(&livro4, &usuario1, "2023-10-21", "2023-11-21");
        
        emprestimos.push_back(emprestimo2);
        cout << "Livro disponivel para emprestimo!!" << endl;
        cout << "emprestimo bem sucedido !!" << endl;
    }else{
        cout << "Livro indisponivel para emprestimo!!" << endl;
    }
    cout << "\nVerificando disponibilidade do livro: ";
    cout << livro4.getTitulo() << endl;
    cout << endl;
    // Verificando disponibilidade do livro
    
    if (disponibilidadeLivro(livro4, livros)){
        Emprestimo emprestimo2(&livro4, &usuario1, "2023-10-21", "2023-11-21");
        emprestimos.push_back(emprestimo2);
        cout << "Livro disponivel para emprestimo!!" << endl;
        cout << "emprestimo bem sucedido !!" << endl;
    }else{
        cout << "Livro indisponivel para emprestimo!!" << endl;
    }

    cout << endl;
    cout << "--- Emprestimos por Usuario ---" << endl;
    ListarLivros_Por_Usuario(usuario1, emprestimos);


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

int Livro::getQtd_emprestado() const {
    return qtd_emprestado;
}

void Livro::setQtd_emprestado(int _qtd_emprestado){
    qtd_emprestado = _qtd_emprestado;
}

string Livro::tostring() const {
    return "Titulo: " + getTitulo() + "\nAutor: " + getAutor() + "\nNumero de copias: " + to_string(numero_copias);
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

Livro Emprestimo::getLivro(){
    return *livro;
}
void Emprestimo::setLivro(Livro *_Livro){
    livro = _Livro;
}
Usuario Emprestimo::getUsuario(){
    return *usuario;
}
void Emprestimo::setUsuario(Usuario *_usuario){
    this->usuario = _usuario;
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
    for (int i = 0; i < int(livros.size()); i++){
        if (livros[i].getAutor() == livro.getAutor() && livros[i].getTitulo() == livro.getTitulo()) {
            livros.erase(livros.begin() + i);
            return;
        }
    }
        livros.push_back(livro);
}

void Biblioteca::realizarEmprestimo(vector<Emprestimo> &emprestimos, Usuario &usuario, Livro &livro, string data){
    Emprestimo emprestimo = Emprestimo(&livro, &usuario, data, "Em andamento");
    livro.setQtd_emprestado(livro.getQtd_emprestado() + 1);
    emprestimos.push_back(emprestimo);
}
  
