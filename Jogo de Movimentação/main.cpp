#include <iostream>
#include <windows.h>
#include <conio.h> ///para o getch()
///https://stackoverflow.com/questions/34474627/linux-equivalent-for-conio-h-getch
using namespace std;

#define L 20
#define C 20
///inclua um símbolo de fim que quando o personagem chegar lá o jogo acaba.
///um dos problemas que encontrarão é que o jogo acabará uma posição antes de realmente chegar... como resolver?


int main()
{
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    COORD coord;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.


    int mapa[L][C]= {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 0, 1, 2, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 1,
        1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
        1,1,1,1,1,0,2,2,2,1,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        1,0,0,0,0,0,0,0,1,2,1,1,1,1,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,2,0,0,0,0,1,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,0,1,
        1,0,0,2,0,0,2,2,0,0,0,0,0,1,0,0,0,0,0,1,
        1,2,0,2,0,2,0,2,0,0,0,0,0,0,0,1,1,1,0,1,
        1,2,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1,0,1,
        1,0,2,2,2,2,0,2,0,0,0,0,1,1,1,0,0,1,0,1,
        1,0,2,0,0,0,0,2,0,0,0,0,1,0,0,0,0,1,0,1,
        1,0,2,0,2,2,2,2,0,0,0,0,1,0,1,1,1,1,0,1,
        1,0,2,0,2,0,0,0,0,0,0,0,1,0,1,1,1,1,0,1,
        1,0,2,5,2,0,0,0,0,0,0,0,1,0,0,0,0,5,1,1,
        1,0,2,2,2,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,};


    char tecla;
    int px=1 , py=1;


    while (1){
        for(int li=0;li<L;li++){
            for(int co=0;co<C;co++){
                if (li==px and co==py){
                    SetConsoleTextAttribute(out, 13); cout<<char(207); //personagem
                } else {
                    switch (mapa[li][co]) {
                        case 0: cout<<" "; break;
                        case 1: SetConsoleTextAttribute(out, 2); cout<<char(219); break;// bordas
                        case 2: SetConsoleTextAttribute(out, 8); cout<<"#"; break;//arame farpado
                        case 5: SetConsoleTextAttribute(out, 6);cout<<char(175); break;// saida
                    }
                }


            }
            cout<<"\n";
        }
        tecla=getch();
        switch (tecla) {
            case 72: ///cima
            case '8': ///cima
                if(mapa[px-1][py]==0){
                    px--;
                } else if (mapa[px-1][py]==2){
                     cout<<"***********";
                    cout<<"\nSe Fudeu!!";
                    cout<<"\n**********";
                    exit(0);
                }else if (mapa[px-1][py]==5){
                    cout<<"********************";
                    cout<<"\nParabens voce venceu!!";
                    cout<<"\n********************";
                    exit(0);
                }
                break;

            case 75: ///esquerda
            case '4': ///esquerda
                if(mapa[px][py-1]==0){
                    py--;
                } else if (mapa[px][py-1]==2){
                    cout<<"***********";
                    cout<<"\nSe Fudeu!!";
                    cout<<"\n**********";
                    exit(0);
                }else if (mapa[px][py-1]==5){
                     cout<<"********************";
                    cout<<"\nParabens voce venceu!!";
                    cout<<"\n********************";
                    exit(0);
                }
                break;

            case 77: ///direita
            case '6': ///direita
                if(mapa[px][py+1]==0){
                    py++;
                } else if (mapa[px][py+1]==2){
                    cout<<"***********";
                    cout<<"\nSe Fudeu!!";
                    cout<<"\n**********";
                    exit(0);
                } else if (mapa[px][py+1]==5){
                     cout<<"********************";
                    cout<<"\nParabens voce venceu!!";
                    cout<<"\n********************";
                    exit(0);
                }

                break;

            case 80: ///baixo
            case '2': ///baixo
                if(mapa[px+1][py]==0){
                    px++;
                } else if (mapa[px+1][py]==2){
                    cout<<"***********";
                    cout<<"\nSe Fudeu!!";
                    cout<<"\n**********";
                    exit(0);
                }else if (mapa[px+1][py]==5){
                     cout<<"********************";
                    cout<<"\nParabens voce venceu!!";
                    cout<<"\n********************";
                    exit(0);
                }
                break;
        }///fim switch tecla



        ///comandos para imprimir na tela
        coord.X = 0;    coord.Y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }




    return 0;

}
