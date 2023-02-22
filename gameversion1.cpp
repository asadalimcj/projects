#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
void maze();
int timer;
int score;
string enemyDirection = "up";
//  player characters
char play1[6] = {'(', '@', '@', ')', '-', '>'};
char play2[6] = {' ', 'W', ' ', ' ', ' ', ' '};

//  enemy character
char tick1[6] = {'<', '-', '(', '0', '0', ')'};
char tick2[6] = {' ', ' ', ' ', ' ', 'W', ' '};
char yom1[6] = {'(', '^', '^', ')', '-', '>'};
char yom2[6] = {' ', 'o', 'o', ' ', ' ', ' '};

// player coordinates
int snowbroX = 2;
int snowbroY = 3;

// enemy coordinates
int enemyX = 95;
int enemyY = 25;
int yomX  = 2;
int yomY = 16;
int bulletX[100];
int bulletY[100];
bool isBulletActive[100];
int bulletCount = 0;

void gotoxy(int x, int y);
void printsnow_bro();
void print_enemy();

void moveleft();
void moveRight();
void moveUp();
void moveDown();
void moveEnemy();

void print_yom();
void moveYom();
void eraseYom();
void eraseEnemy();
void eraseSnowbro();
void generateBullet();
void moveBullet();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void makeBulletInactive(int idx);
void bulletCollisionWithEnemy();
void addScore();
void printScore();
char getCharAtxy(short int x, short int y);

void logo();
char mainMenu();
char options();

main()
{
    system("cls");
    logo();
    cout << "Press any key to continue......";
    getch();
    char choice;
    while (choice != '3')
    {
        system("cls");
        choice = mainMenu();
        if (choice == '1')
        {
            system("cls");
            maze();
            printsnow_bro();
            print_enemy();
            print_yom();
            while (true)
            {
                printScore();
                if (GetAsyncKeyState(VK_LEFT))
                {
                    moveleft();
                }
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    moveRight();
                }

                if (GetAsyncKeyState(VK_UP))
                {
                    moveUp();
                }
                if (GetAsyncKeyState(VK_DOWN))
                {
                    moveDown();
                }
                if (GetAsyncKeyState(VK_SPACE))
                {
                    generateBullet();
                }
                if (GetAsyncKeyState(VK_ESCAPE))
                {
                    break;
                }

                if (timer == 3)
                {
                    moveEnemy();
                    moveYom();
                    timer = 0;
                }
                moveBullet();
                bulletCollisionWithEnemy();
                timer++;
                Sleep(90);
            }
            gotoxy(1, 40);
        }

        if (choice == '2')
        {
            char option;
            while (option != '2')
            {

                option = options();
                if (option == '1')
                {
                    system("cls");
                    cout << "Keys\t\tFuntions" << endl;
                    cout << "__________________________"<<endl;
                    cout << "Up\t\tMoves Up" << endl;
                    cout << "Down\t\tMoves Down" << endl;
                    cout << "Left\t\tMoves Left" << endl;
                    cout << "Right\t\tMoves Right" << endl;
                    cout << "Space'\t\tFire" << endl;
                    cout << "Press any key to continue.........";
                    getch();
                }
                if (option == '2')
                {
                    break;
                }
            }
        }
    }
}

char mainMenu()
{
    char option;
    cout << "1.\tStart" << endl;
    cout << "2.\tOptions" << endl;
    cout << "3.\tExit" << endl;
    cout << "_________________________" << endl;
    cout << "Enter a choice : ";
    cin >> option;
    return option;
}

char options()
{
    system("cls");
    char choice;
    cout << "1.\tKeys" << endl;
    cout << "2.\tExit" << endl;
    cout << "_________________________" << endl;
    cout << "Enter a choice : ";
    cin >> choice;
    return choice;
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void moveYom()
{
     if (enemyDirection == "up")
    {
        char next = getCharAtxy(yomX, yomY - 1);
        if (next == ' ')
        {
            eraseYom();
            yomY--;
            print_yom();
        }
        if (next == '%')
        {
            enemyDirection = "down";
        }
    }
    if (enemyDirection == "down")
    {
        char next = getCharAtxy(yomX, yomY + 4);
        if (next == ' ')
        {
            eraseYom();
            yomY++;
            print_yom();
        }
        if (next == '%')
        {
            enemyDirection = "up";
        }
    }
}

void print_yom()
{
    gotoxy(yomX, yomY);
    for(int idx = 0; idx<6; idx++)
    {
        cout<<yom1[idx];
    }
    gotoxy(yomX, yomY+1);
    for(int idx = 0; idx<6; idx++)
    {
        cout<<yom2[idx];
    }
}

void eraseYom()
{
    gotoxy(yomX, yomY);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << " ";
    }
    gotoxy(yomX, yomY + 1);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << " ";
    }
}

void printScore()
{
    gotoxy(105, 8);
    cout << "score:" << score;
}

void addScore()
{
    score++;
}

void bulletCollisionWithEnemy()
{

    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            if (bulletX[x] + 1 == enemyX && (bulletY[x] == enemyY || bulletY[x] == enemyY + 2 || bulletY[x] == enemyY + 3))
            {
                addScore();
            }
            if (enemyX - 1 == bulletX[x] && enemyY + 1 == bulletY[x])
            {
                addScore();
            }
        }
    }
}

void makeBulletInactive(int idx)
{
    isBulletActive[idx] = false;
}

void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "*";
}

void moveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            char next = getCharAtxy(bulletX[x] + 1, bulletY[x]);
            if (next != ' ')
            {
                eraseBullet(bulletX[x], bulletY[x]);
                makeBulletInactive(x);
            }
            else
            {
                eraseBullet(bulletX[x], bulletY[x]);
                bulletX[x] = bulletX[x] + 1;
                printBullet(bulletX[x], bulletY[x]);
            }
        }
    }
}

void generateBullet()
{
    bulletX[bulletCount] = snowbroX + 7;
    bulletY[bulletCount] = snowbroY;
    isBulletActive[bulletCount] = true;
    gotoxy(snowbroX + 7, snowbroY);
    cout << "*";
    bulletCount++;
}

void eraseSnowbro()
{
    gotoxy(snowbroX, snowbroY);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << " ";
    }
    gotoxy(snowbroX, snowbroY + 1);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << " ";
    }
}

void eraseEnemy()
{
    gotoxy(enemyX, enemyY);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 1);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << " ";
    }
   
    
}

void moveEnemy()
{
    if (enemyDirection == "up")
    {
        char next = getCharAtxy(enemyX, enemyY - 1);
        if (next == ' ')
        {
            eraseEnemy();
            enemyY--;
            print_enemy();
        }
        if (next == '%')
        {
            enemyDirection = "down";
        }
    }
    if (enemyDirection == "down")
    {
        char next = getCharAtxy(enemyX, enemyY + 4);
        if (next == ' ')
        {
            eraseEnemy();
            enemyY++;
            print_enemy();
        }
        if (next == '%')
        {
            enemyDirection = "up";
        }
    }
}

void moveDown()
{
    char next = getCharAtxy(snowbroX, snowbroY + 2);
    if (next == ' ')
    {
        eraseSnowbro();
        snowbroY = snowbroY + 1;
        printsnow_bro();
    }
}

void moveUp()
{
    char next = getCharAtxy(snowbroX, snowbroY - 1);
    if (next == ' ')
    {
        eraseSnowbro();
        snowbroY = snowbroY - 1;
        printsnow_bro();
    }
    
}

void moveRight()
{
    char next = getCharAtxy(snowbroX + 6, snowbroY);
    if (next == ' ')
    {
        eraseSnowbro();
        snowbroX = snowbroX + 1;
        printsnow_bro();
    }
}

void moveleft()
{
    char next = getCharAtxy(snowbroX - 1, snowbroY);
    if (next == ' ')
    {
        eraseSnowbro();
        snowbroX = snowbroX - 1;
        printsnow_bro();
    }
}

void print_enemy()
{
    gotoxy(enemyX, enemyY);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << tick1[idx];
    }
    gotoxy(enemyX, enemyY + 1);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << tick2[idx];
    }
    
}


void printsnow_bro()
{
    gotoxy(snowbroX, snowbroY);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << play1[idx];
    }
    gotoxy(snowbroX, snowbroY + 1);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << play2[idx];
    }
}

void maze()
{
    cout << "#######################################################################################################" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                                 #####################################                               #" << endl;
    cout << "##     #############################                                  %%%%%%%%%%%%%%%%%%%%%%%%%%     #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                     #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##%%%%%%%%%%%%%%%%%%%%%%%%%                   %%%%%%%%%%%%%%%%%%%%%%         %%%%%%%%%%%%%%%%%%%%%%%%%#" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                  #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##       %%                                                                                 %%        #" << endl;
    cout << "##       %%      %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    %%        #" << endl;
    cout << "##       %%                                                                                 %%        #" << endl;
    cout << "##       %%                                                                                 %%        #" << endl;
    cout << "##       %%         %%%%%%%%                %%%%%%%%%%%%%%%%%%%%%           %%%%%%%%        %%        #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##       %%                                                                                 %%        #" << endl;
    cout << "##       %%                                                                                 %%        #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#" << endl;
    cout << "#######################################################################################################" << endl;
}

void logo()
{
    cout << "        SSSSSSSSSSSSSSS NNNNNNNN        NNNNNNNN     OOOOOOOOO     WWWWWWWW                           WWWWWWWW     BBBBBBBBBBBBBBBBB   RRRRRRRRRRRRRRRRR        OOOOOOOOO         " << endl;
    cout << "      SS:::::::::::::::SN:::::::N       N::::::N   OO:::::::::OO   W::::::W                           W::::::W     B::::::::::::::::B  R::::::::::::::::R     OO:::::::::OO       " << endl;
    cout << "      S:::::SSSSSS::::::SN::::::::N      N::::::N OO:::::::::::::OO W::::::W                           W::::::W     B::::::BBBBBB:::::B R::::::RRRRRR:::::R  OO:::::::::::::OO    " << endl;
    cout << "      S:::::S     SSSSSSSN:::::::::N     N::::::NO:::::::OOO:::::::OW::::::W                           W::::::W     BB:::::B     B:::::BRR:::::R     R:::::RO:::::::OOO:::::::O   " << endl;
    cout << "      S:::::S            N::::::::::N    N::::::NO::::::O   O::::::O W:::::W           WWWWW           W:::::W        B::::B     B:::::B  R::::R     R:::::RO::::::O   O::::::O   " << endl;
    cout << "      S:::::S            N:::::::::::N   N::::::NO:::::O     O:::::O  W:::::W         W:::::W         W:::::W         B::::B     B:::::B  R::::R     R:::::RO:::::O     O:::::O   " << endl;
    cout << "       S::::SSSS         N:::::::N::::N  N::::::NO:::::O     O:::::O   W:::::W       W:::::::W       W:::::W          B::::BBBBBB:::::B   R::::RRRRRR:::::R O:::::O     O:::::O   " << endl;
    cout << "        SS::::::SSSSS    N::::::N N::::N N::::::NO:::::O     O:::::O    W:::::W     W:::::::::W     W:::::W           B:::::::::::::BB    R:::::::::::::RR  O:::::O     O:::::O   " << endl;
    cout << "          SSS::::::::SS  N::::::N  N::::N:::::::NO:::::O     O:::::O     W:::::W   W:::::W:::::W   W:::::W            B::::BBBBBB:::::B   R::::RRRRRR:::::R O:::::O     O:::::O   " << endl;
    cout << "             SSSSSS::::S N::::::N   N:::::::::::NO:::::O     O:::::O      W:::::W W:::::W W:::::W W:::::W             B::::B     B:::::B  R::::R     R:::::RO:::::O     O:::::O   " << endl;
    cout << "                  S:::::SN::::::N    N::::::::::NO:::::O     O:::::O       W:::::W:::::W   W:::::W:::::W              B::::B     B:::::B  R::::R     R:::::RO:::::O     O:::::O   " << endl;
    cout << "                  S:::::SN::::::N     N:::::::::NO::::::O   O::::::O        W:::::::::W     W:::::::::W               B::::B     B:::::B  R::::R     R:::::RO::::::O   O::::::O   " << endl;
    cout << "      SSSSSSS     S:::::SN::::::N      N::::::::NO:::::::OOO:::::::O         W:::::::W       W:::::::W              BB:::::BBBBBB::::::BRR:::::R     R:::::RO:::::::OOO:::::::O   " << endl;
    cout << "      S::::::SSSSSS:::::SN::::::N       N:::::::N OO:::::::::::::OO           W:::::W         W:::::W               B:::::::::::::::::B R::::::R     R:::::R OO:::::::::::::OO    " << endl;
    cout << "      S:::::::::::::::SS N::::::N        N::::::N   OO:::::::::OO              W:::W           W:::W                B::::::::::::::::B  R::::::R     R:::::R   OO:::::::::OO      " << endl;
    cout << "       SSSSSSSSSSSSSSS   NNNNNNNN         NNNNNNN     OOOOOOOOO                 WWW             WWW                 BBBBBBBBBBBBBBBBB   RRRRRRRR     RRRRRRR     OOOOOOOOO        " << endl;
}