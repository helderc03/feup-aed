//
// Created by helderc03 on 21/10/2022.
//


#include <string>
#include "Menu.h"

using namespace std;


int main() {
    std::ofstream ofs;
    ofs.open("Code/schedule/students_classes1.csv", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    ifstream studentsinfo_file, aulas_file;
    cout << "Bem-vindo à plataforma de gestão dos horários de LEIC. O que deseja fazer?\n";
    Menu(studentsinfo_file, aulas_file);

    FileReader fileReader = FileReader(studentsinfo_file,
                                       aulas_file); //read the files, organizing them through standard method
    Curso curso = Curso(fileReader.getStudents(),
                        fileReader.getTurmas(),fileReader.getSlots()); //create an object curso with all the information

    int op;
    Student *s;
    vector<Turma *> vt;
    do {
        op = mainMenu();
        int temp;

        do {
            switch (op) {
                case 1: // student menu
                {
                    int temp2;
                    temp = studentMenu();
                    switch (temp) {
                        case 1:
                            s = curso.PrintStudentByName();
                            do {
                                temp2 = studentMenu2();
                                switch (temp2) {
                                    case 1:
                                        s->PrintStudentTurmas();
                                        break;

                                    case 2:
                                        s->PrintHorario();
                                        break;

                                    default:
                                        break;
                                }

                            } while (temp2 != 0);
                            break;
                        case 2:
                            s = curso.PrintStudentByCode();
                            do {
                                temp2 = studentMenu2();
                                switch (temp2) {
                                    case 1: {
                                        s->PrintStudentTurmas();
                                        break;
                                    }
                                    case 2:
                                        s->PrintHorario();
                                        break;
                                    default:
                                        break;
                                }

                            } while (temp2 != 0);
                            break;
                        default:
                            break;

                    }
                    break;
                }
                case 2: // turma menu
                {

                    int control;
                    string choice;
                    vector<Turma *> vt;
                    do {
                        cout << setw(30) << left << "\nInformações de uma turma\n";
                        while (vt.size() == 0) {
                            vt = curso.FindTurma(); }
                        temp = turmaMenu3();
                        int temp2;
                        switch (temp) {
                            do {

                                case 1: //ver horario
                                    temp2 = turmaMenuHorário();
                                if (temp2 == 1) { curso.PrintHorarioTurma(vt); }
                                else {
                                    std::string x = ucCode(vt);
                                    curso.PrintHorarioTurma(vt, x);
                                }
                                break;
                                case 2: //ver estudantes
                                    temp2 = turmaMenuStudents();
                                int temp3;

                                if (temp2 == 1) {
                                    temp3 = displayStudents();
                                    switch (temp3) {
                                        case 1:
                                            curso.PrintStudents(curso.getStudentsTurma(vt), '1');
                                            break;
                                        case 2:
                                            curso.PrintStudents(curso.getStudentsTurma(vt), '2');
                                            break;
                                        case 3:
                                            curso.PrintStudents(curso.getStudentsTurma(vt), '3');
                                            break;
                                        case 4:
                                            curso.PrintStudents(curso.getStudentsTurma(vt), '4');
                                            break;
                                    }

                                } else {
                                    std::string x = ucCode(vt);
                                    temp3 = displayStudents();

                                    switch (temp3) {
                                        case 1:
                                            curso.PrintStudents(curso.getStudentsTurma(vt, x), '1');
                                            break;
                                        case 2:
                                            curso.PrintStudents(curso.getStudentsTurma(vt, x), '2');
                                            break;
                                        case 3:
                                            curso.PrintStudents(curso.getStudentsTurma(vt, x), '3');
                                            break;
                                        case 4:
                                            curso.PrintStudents(curso.getStudentsTurma(vt, x), '4');
                                            break;
                                    }

                                }
                                break;

                            } while (temp2 != 0);
                        }
                        cout << endl << "Deseja sair deste menu? (Y/N)\n";
                        cin >> choice;

                        if (tolower(choice[0]) == 'n') { control = 1; }
                        else if (tolower(choice[0]) == 'y') {
                            control = 0;
                            temp = 0;
                        }
                    } while (control == 1);
                    break;
                }
                case 3: //listagens menu
                {
                    temp = listagensMenu();
                    int temp2;

                    switch(temp){

                        case 1: {
                            temp2 = displayStudents();
                            switch (temp2) {
                                case 1:
                                    curso.PrintStudents(curso.getAllStudents(), '1');
                                    break;
                                case 2:
                                    curso.PrintStudents(curso.getAllStudents(), '2');
                                    break;
                                case 3:
                                    curso.PrintStudents(curso.getAllStudents(), '3');
                                    break;
                                case 4:
                                    curso.PrintStudents(curso.getAllStudents(), '4');
                                    break;
                            }
                            break;
                        }
                        case 2: {
                            int x = listagensAnoMenu();
                            temp2 = displayStudents();

                            switch (temp2) {
                                case 1: {
                                    curso.PrintStudents(curso.getStudentsYear(curso.getAllStudents(), x), '1');
                                    break;
                                }
                                case 2:
                                    curso.PrintStudents(curso.getStudentsYear(curso.getAllStudents(), x), '2');
                                    break;
                                case 3:
                                    curso.PrintStudents(curso.getStudentsYear(curso.getAllStudents(), x), '3');
                                    break;
                                case 4:
                                    curso.PrintStudents(curso.getStudentsYear(curso.getAllStudents(), x), '4');
                                    break;
                            }
                            break;
                        }
                        case 3:
                            temp2 = turmaListagemMenu();

                            switch (temp2) {
                                case 1:{
                                    int x;
                                    cout << endl << "Qual o ano pretendido?\n";
                                    cin >> x;
                                    curso.getTurmasYear(x);
                                    break;
                                }
                                case 2:{
                                    std::string x;
                                    cout << endl << "Qual a UC pretendida?\n";
                                    cin >> x;
                                    curso.SortbyTurmaCapacity( x, '1');
                                    break;
                                }
                                case 3:{
                                    std::string x;
                                    cout << endl << "Qual a UC pretendida?\n";
                                    cin >> x;
                                    curso.SortbyTurmaCapacity( x, '2');
                                    break;
                                }
                                case 4:{
                                    curso.getTurmasYear();
                                    break;
                                }

                            }

                            break;
                        case 4:
                        {
                            int temp2 = ucListagemMenu();
                            switch (temp2) {
                                case 1:
                                    curso.SortByEnrolledUC();
                                    break;
                                case 2:
                                {
                                    string turmaCode = curso.ucCodeNormalizer();
                                    curso.SortByEnrolledUC(2,turmaCode);
                                    break;
                                }
                                case 0:
                                    break;
                            }
                            break;
                        }
                        case 5:
                        {
                            int temp2 = EstudantesUCMenu();
                            switch (temp2) {
                                case 0:
                                    break;
                                case 1: { // mais do que n UCS
                                    int temp3 = defNrUcMenu();
                                    int temp4 = orderTypeMenu();
                                    curso.findListStudentsUC(temp3,temp2,temp4);
                                    break;
                                }
                                case 2: {
                                    int temp3 = defNrUcMenu();
                                    curso.findListStudentsUC(temp3,temp2,1);
                                    break;
                                }
                                case 3: {
                                    int temp3 = defNrUcMenu();
                                    int temp4 = orderTypeMenu();
                                    curso.findListStudentsUC(temp3,temp2,temp4);
                                    break;
                                }
                            }
                            break;
                        }
                    }

                    break;
                }
                case 4:
                    temp = PAMenu();
                    int temp2;
                    switch (temp) {
                        case 1:
                            // alocar estudante numa uc
                            temp2 = studentSearchMenu();
                            switch (temp2) {
                                // tipo de find do student
                                case 0:
                                    break;
                                case 1:
                                {
                                    s = curso.PrintStudentByName();
                                    s->PrintStudentTurmas();
                                    string uc = curso.ucCodeNormalizer();
                                    int temp3 = AlocationUCMenu(); // escolher preferencia de turma ou escolher alocacao aleatoria (para a turma c menos capacidade)
                                    switch (temp3) {
                                        // alocar na preferida ou a toa
                                        case 0:
                                            break;
                                        case 1:
                                        {

                                            vt = curso.FindTurma(uc);
                                            curso.AddPA(s,vt[0],1);
                                            break;
                                        }
                                        case 2:
                                        {
                                            Turma* t = curso.FindTurmaLowestCapacity(s,uc);
                                            if (t == NULL) {
                                                cout << "Impossível encontrar turma com horário compatível.\n" << endl;
                                                break;
                                            }
                                            curso.AddPA(s,t,1);
                                            break;
                                        }
                                    }
                                    break;
                                } // find por nome
                                case 2:
                                {
                                    s = curso.PrintStudentByCode();
                                    s->PrintStudentTurmas();
                                    string uc = curso.ucCodeNormalizer();
                                    int temp3 = AlocationUCMenu(); // escolher preferencia de turma ou escolher alocacao aleatoria (para a turma c menos capacidade)
                                    switch (temp3) {
                                        // alocar na preferida ou a toa
                                        case 0:
                                            break;
                                        case 1:
                                        {
                                            vt = curso.FindTurma();
                                            curso.AddPA(s,vt[0],1);
                                            break;
                                        }
                                        case 2:
                                        {
                                            Turma* t = curso.FindTurmaLowestCapacity(s,uc);
                                            if (t == NULL) {
                                                cout << "Impossivel encontrar turma com horario compativel.\n" << endl;
                                                break;
                                            }
                                            curso.AddPA(s,t,1);
                                            break;
                                        }
                                    }
                                    break;
                                } // find por code
                            }
                            break;
                        case 2:
                            // remover estudante de uma uc
                            temp2 = studentSearchMenu();
                            switch (temp2) {
                                // tipo de find do student
                                case 0:
                                    break;
                                case 1: {
                                    s = curso.PrintStudentByName();
                                    s->PrintStudentTurmas();
                                    string uc = curso.ucCodeNormalizer();
                                    int temp3 = RemovalUCMenu();
                                    //cout << uc << endl;
                                    switch (temp3) {
                                        case 0:
                                            break;
                                        case 1: {
                                            Turma* t;
                                            t = curso.GetTurma(s,uc);
                                            if (t == NULL) {
                                                cout << "O aluno nao esta inscrito nesta turma.\n" << endl;
                                                break;
                                            }
                                            curso.AddPA(s, t , 2);
                                            break;
                                        }
                                    }
                                    break;
                                } // find por nome
                                case 2: {
                                    s = curso.PrintStudentByCode();
                                    s->PrintStudentTurmas();
                                    string uc = curso.ucCodeNormalizer();
                                    int temp3 = RemovalUCMenu();
                                    //cout << uc << endl;
                                    switch (temp3) {
                                        case 0:
                                            break;
                                        case 1: {
                                            Turma* t;
                                            t = curso.GetTurma(s,uc);
                                            if (t == NULL) {
                                                cout << "O aluno nao esta inscrito nesta turma.\n" << endl;
                                                break;
                                            }
                                            curso.AddPA(s, t , 2);
                                            break;
                                        }
                                    }
                                    break;
                                } // find por code
                            }
                            break;
                        case 3: {
                            // troca direta
                            temp2 = studentSearchMenu();
                            switch (temp2) {
                                // tipo de find do student
                                case 0:
                                    break;
                                case 1: {
                                    s = curso.PrintStudentByName();
                                    s->PrintStudentTurmas();
                                    string uc = curso.ucCodeNormalizer();
                                    int temp3 = TrocaDiretaMenu();
                                    cout << s->get_Name() << endl;
                                    switch (temp3) {
                                        case 0:
                                            break;
                                        case 1: {
                                            Turma *t = curso.GetTurma(s, uc);
                                            curso.AddPA(s, t, 3);
                                            break;
                                        }
                                    }
                                    break;
                                } // find por nome
                                case 2: {
                                    s = curso.PrintStudentByCode();
                                    s->PrintStudentTurmas();
                                    string uc = curso.ucCodeNormalizer();
                                    int temp3 = TrocaDiretaMenu();
                                    cout << s->get_Name() << endl;
                                    switch (temp3) {
                                        case 0:
                                            break;
                                        case 1: {
                                            Turma* t = curso.GetTurma(s,uc);
                                            if (t == NULL) {
                                                cout << "O aluno nao esta inscrito nesta turma.\n" << endl;
                                                break;
                                            }
                                            curso.AddPA(s, t, 3);
                                            break;
                                        }
                                    }
                                    break;
                                } // find por code
                            }
                            break;
                        }
                        case 4:
                        {
                            temp2 = studentSearchMenu();
                            switch (temp2) {
                                // tipo de find do student
                                case 0:
                                    break;
                                case 1: {
                                    s = curso.PrintStudentByName();
                                    s->PrintStudentTurmas();
                                    string uc = curso.ucCodeNormalizer();
                                    Turma *t = curso.GetTurma(s, uc);
                                    if (t == NULL) {
                                        cout << "O aluno nao esta inscrito nesta UC.\n" << endl;
                                        break;
                                    }
                                    cout << endl;
                                    cout << s->get_Name() << " quer trocar da turma " << t->get_turmaCode()  << endl;
                                    int temp3 = TrocaDiretaMenu();
                                    switch (temp3) {
                                        case 0:
                                            break;
                                        case 1: {
                                            curso.AddPA(s,t,4);
                                            break;
                                        }
                                    }
                                    break;
                                } // find por nome
                                case 2: {
                                    s = curso.PrintStudentByCode();
                                    s->PrintStudentTurmas();
                                    string uc = curso.ucCodeNormalizer();
                                    int temp3 = TrocaDiretaMenu();
                                    cout << s->get_Name() << endl;
                                    switch (temp3) {
                                        case 0:
                                            break;
                                        case 1: {
                                            Turma* t = curso.GetTurma(s,uc);
                                            if (t == NULL) {
                                                cout << "O aluno nao esta inscrito nesta UC.\n" << endl;
                                                break;
                                            }
                                            curso.AddPA(s, t, 3);
                                            break;
                                        }
                                    }
                                    break;
                                } // find por code
                            }
                            break;
                            // TROCA TURMA ENTRE DOIS ESTUDANTES
                        }
                        case 5:
                        {
                            curso.ProcessPA();
                            // Process requests
                        }
                        break;
                    }
                    break;
                case 5: {
                    curso.Save();
                    temp = 0;
                    break;
                }
                case 6:
                {
                    temp = ConfigMenu();
                    switch (temp) {
                        // configuracoes
                        case 1:
                        {
                            cout << "\nAtual capacidade: " << curso.getDefaultCap() << endl;
                            cout << "Pretende alterar?(Y/N) ";
                            char response;
                            cin >> response;
                            if (tolower(response) == 'y')
                            {cout << "\nPara efeitos de comparação a turma com mais alunos tem " << curso.getTurmaMostStudents() << " alunos." << endl;
                                cout << "Introduza novo limite de capacidade das turmas: ";
                                int newCap;
                                cin >> newCap;
                                curso.setDefaultCap(newCap);
                            }
                            break;
                        }
                        case 0:
                            break;
                    }
                    break;
                }
                case 7:
                {
                    temp = AboutUsMenu();
                }
                case 0: {
                    temp = 0;
                    break;
                }
            }
        } while (temp != 0);

    } while (op != 0);
    cout << "\n";
    cout << "Obrigado por usar a nossa plataforma! :) " << endl;

    return 0;
}