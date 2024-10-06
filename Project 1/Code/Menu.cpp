
#include "Menu.h"

using namespace std;

void Menu(std::ifstream &studentsinfo_file, std::ifstream &aulas_file){
    int option;
    cout << "1 -> Processar/Consultar dados atuais" << endl;
    cout << "2 -> Inserir novos dados" << endl;
    cout << "Escolha opção: ";
    cin >> option;

    switch (option) {
        case 1:
        {
            try {
                studentsinfo_file.open("Code/schedule/students_classes.csv");
            }
            catch (exception e) {
                cout << "Couldn't open students file" << endl;
            }
            try {
                aulas_file.open("Code/schedule/classes.csv");
            }
            catch (exception e) {
                cout << "Couldn't open classes file" << endl;
            }
            break;
        }
        case 2:
        {
            string studentsInfoFilePath, aulasFilePath;
            cout << "Insira o 'path' para os novos dados: " << "\n" << "'Path' para ficheiro com informação dos estudantes: ";
            cin >> studentsInfoFilePath;
            try {
                studentsinfo_file.open(studentsInfoFilePath);
            }
            catch (exception e) {
                cout << "Couldn't open students file" << endl;
            }
            cout << "'Path' para ficheiro com informação das turmas: " ;
            cin >>aulasFilePath;
            try {
                studentsinfo_file.open(studentsInfoFilePath);
            }
            catch (exception e) {
                cout << "Couldn't open classes file" << endl;
            }
            break;
        }
        default: {
            cout << "Escolha inválida " << endl;
            Menu(studentsinfo_file, aulas_file);
        }
    }
}

int mainMenu() {
    cout << "\n";
    cout << "MENU PRINCIPAL\n\n";
    cout << "1.Ver informações de um estudante" << '\n' << "2.Consultar turmas" << '\n' << "3.Listagens" << '\n'<< "4.Pedidos de alteração" << '\n' << "5.Salvar alterações"<< '\n' << "6.Configurações" << '\n' << "7.Sobre nós" << '\n' << "0.Sair" << "\n\n";
    cout << "Escolha opção: ";
    return auxMenu(7, 0);
}

int studentMenu(){
    cout << "\n";
    cout << setw(30) << left << "Menu de informações dos estudantes\n" << endl;
    cout << "1.Procurar por nome de estudante" << endl;
    cout << "2.Procurar por número mecanográfico do estudante " << endl;
    cout << "0.Voltar\n\n";
    cout << "Escolha opção: ";
    return auxMenu(3, 0);
}

int studentMenu2(){
    cout << endl << "1.Ver UC's/Turmas em que está inscrito \n" << "2.Ver horário \n" << "0.Voltar \n\n";
    cout << "Escolha opção: ";
    return auxMenu(3,0);
}

int turmaMenu(){
    cout << endl << "Qual o ano da turma(1-3): ";
    return auxMenu(3,0);
}


int turmaMenu2(int ano){
    switch(ano){
        case 1:
            cout << "Qual o número da turma(1LEIC0x/1LEICxx): ";
            return auxMenu(16,1);
        case 2:
            cout << "Qual o número da turma(2LEIC0x/2LEICxx): ";
            return auxMenu(16,1);
        case 3:
            cout << "Qual o número da turma(3LEIC0x/3LEICxx): ";
            return auxMenu(15,1);
    }
    return 0;
}

int turmaMenu3(){
    cout << "\nO que deseja fazer?\n";
    cout << "1. Ver o horário desta turma" << "\n";
    cout << "2. Ver os estudantes desta turma" << "\n";
    cout << "0. Voltar" << "\n";
    cout << "Escolha opção: ";
    return auxMenu(2,0);
}

int turmaMenuHorário(){
    cout << endl <<  "Deseja ver o horário desta turma a todas as UCs ou apenas de uma UC em específico?\n";

    cout << "1. Todas as UCs\n";
    cout << "2. De apenas uma UC em específico\n";
    cout << "Escolha opção: ";
    return auxMenu(2,1);
}

int turmaMenuStudents(){
    cout << "\nDeseja ver os estudantes desta turma a todas as UCs ou apenas de uma UC em específico?\n";
    cout << "1. Todas as UCs\n";
    cout << "2. De uma UC em específico\n";
    cout << "Escolha opção: ";
    return auxMenu(2, 1);
}

int displayStudents(){
    cout << "\nComo deseja visualizar os estudantes?\n";
    cout << "1. Alfabeticamente através do nome\n";
    cout << "2. Ordem inversa através do nome\n";
    cout << "3. Ordem crescente através do código do aluno\n";
    cout << "4. Ordem decrescente através do código do aluno\n";
    cout << "0. Voltar\n";
    cout << "Escolha opção: ";
    return auxMenu(4, 0);
}

std::string ucCode(std::vector<Turma*> vt){
    std::string ucCode;
    bool condition = true;
    cout << endl << "Lista de UCs da turma:\n";
    for (Turma* t : vt ){
        cout << t->get_ucCode() << endl;
    }
    cout << endl << "Qual é a UcCode desejada? (introduza apenas o número da UC , por exemplo para L.EIC001 introduza 1)\n";
    while(condition){
        cout << "L.EIC: ";
        cin >> ucCode;
        if (ucCode.size() == 1){ucCode = "00" + ucCode;}
        else if (ucCode.size() == 2){ucCode = "0" + ucCode;}
        ucCode = "L.EIC" + ucCode;
        auto it = std::find_if(vt.begin(), vt.end(), [&ucCode](const Turma* t) {return t->get_ucCode() == ucCode;});
        if(it != vt.end())
            condition = false;
        else(cout << "UcCode inválido para esta turma\n");
    }
    return ucCode;
}


int listagensMenu(){
    cout << setw(30) << left << "\nListagens\n" << endl;
    cout << "O que deseja fazer?\n";
    cout << "1. Ver todos os estudantes inscritos\n";
    cout << "2. Ver todos os estudantes inscritos em um ano específico\n";
    cout << "3. Ver todas as turmas\n";
    cout << "4. Ver número de estudantes inscritos em todas as UCs\n";
    cout << "5. Ver estudantes inscritos em certo número de UCs\n";
    cout << "0. Voltar\n";
    cout << "\nEscolha opção: ";
    return auxMenu(5,0);
}

int listagensAnoMenu(){
    cout << endl << "Qual o ano(1-3): ";
    return auxMenu(3,0);
}

int turmaListagemMenu(){
    cout << "\nComo deseja visualizar as turmas?\n";
    cout << "1. Por ano\n";
    cout << "2. Por capacidade\n";
    cout << "3. Por número de vagas\n";
    cout << "4. Todas as turmas\n";
    cout << "0. Voltar\n\n";
    cout << "Escolha opção: ";
    return auxMenu(4,0);
}

int ucListagemMenu(){
    cout << "\n1.Ver lista de todas as UC" << endl;
    cout << "2.Ver número de alunos inscritos numa UC" << endl;
    cout << "0.Voltar" << endl;
    return auxMenu(2,0);
}

int PAMenu(){
    cout << "\n1.Alocar estudante numa turma/UC" << endl;
    cout << "2.Remover estudante de uma turma/UC" << endl;
    cout << "3.Troca direta entre dois estudantes de uma turma/UC" << endl;
    cout << "4.Troca de turmas de aluno na mesma UC" << endl;
    cout << "5.Processar pedidos" << endl;
    cout << "0.Voltar\n" << endl;
    cout << "Escolha opção: ";
    return auxMenu(5,0);
}

int studentSearchMenu(){
    cout << "\n";
    cout << "1.Procurar por nome de estudante" << endl;
    cout << "2.Procurar por número do estudante " << endl;
    cout << "0.Voltar\n\n";
    cout << "Escolha opção: ";
    return auxMenu(3, 0);
}

int AlocationUCMenu(){
    cout << endl <<  "1.Tentar alocar estudante numa respetiva turma" << endl;
    cout << "2.Alocar estudante numa turma aleatória" << endl;
    cout << "0.Voltar" << endl;
    cout << "Escolha opção: ";
    return auxMenu(2,0);
}
int RemovalUCMenu(){
    cout << "1.Remover estudante da UC" << endl;
    cout << "0.Voltar" << endl;
    cout << "Escolha opção: ";
    return auxMenu(1,0);
}

int TrocaDiretaMenu(){
    cout << "1.Pretendo avançar com a troca do aluno" << endl;
    cout << "0.Voltar" << endl;
    cout << "Escolha opção: ";
    return auxMenu(1,0);
}

int ConfigMenu(){
    cout << "\n1.Definir capacidade máxima das turmas " << endl;
    cout << "0.Voltar" << endl;
    cout << "Escolha opção: ";
    return auxMenu(1,0);
}

int AboutUsMenu(){
    cout << "\nPlataforma de gestão de horários de LEIC criada em prol da disciplina de Algoritmos e Estrutura de Dados\n" << endl;
    cout << "Meet the team: \n";
    cout << left << setw(16) <<  "Carlos Daniel Rebelo\t" << "Número estudante: " << setw(9) << "202108885\n";
    cout << left << setw(20)  << "Hélder Costa\t" << setw(20) << "Número estudante: " << setw(9) << "202108719\n";
    cout << left << setw(20)  << "Jaime Fonseca\t" << setw(20) << "Número estudante: " << setw(9) << "202108789\n";
    cout << "0.Voltar" << endl;
    return auxMenu(0,0);
}

int EstudantesUCMenu(){
    cout << "\n1.Ver estudantes inscritos em mais do que n UCs" << endl;
    cout << "2.Ver estudantes inscritos em n UCs" << endl;
    cout << "3.Ver estudantes inscritos em menos de n UCs" << endl;
    cout << "0.Voltar\n\n";
    cout << "Escolha opção: ";
    return auxMenu(3,0);
}

int defNrUcMenu(){
    cout << "\nDefinir um número de UCs: ";
    return auxMenu(10,0);
}

int orderTypeMenu(){
    cout << "\nEscolha o tipo de ordenação:\n";
    cout << "1.Crescente" << endl;
    cout << "2.Decrescente\n" << endl;
    cout << "Escolha opção: ";
    return auxMenu(2,1);
}
















