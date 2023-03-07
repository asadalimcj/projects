#include <iostream> // libraries
#include <windows.h>
#include <conio.h>
using namespace std;

void maze();
int timer;
int score;
// health
int player_health = 100;
int tick_health = 15;
int yom_health = 100;
int lynch_health = 100;

string enemyDirection = "up";
//  player characters
char play1[6] = {'(', '@', '@', ')', '-', '>'};
char play2[6] = {' ', 'W', ' ', ' ', ' ', ' '};

//  enemy character
char tick1[6] = {'<', '-', '(', '0', '0', ')'};
char tick2[6] = {' ', ' ', ' ', ' ', 'M', ' '};
char yom1[6] = {'(', '^', '^', ')', '-', '>'};
char yom2[6] = {' ', 'o', 'o', ' ', ' ', ' '};

// player coordinates
int snowbroX = 2;
int snowbroY = 3;

// enemy coordinates
int enemyX = 95;
int enemyY = 25;
int yomX = 2;
int yomY = 20;
int bulletX[10000];
int bulletY[10000];
bool isBulletActive[10000];
int bulletCount = 0;

void gotoxy(int x, int y);
void printsnow_bro();
void print_enemy();

void moveleft();
void moveRight();
void moveUp();
void moveDown();
void moveEnemy();
void eraseEnemy();

void print_yom();
void moveYom();
void eraseYom();

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

void generateBulletLeft();
void moveBulletLeft();
void printBulletLeft(int x, int y);
void eraseBulletLeft(int x, int y);
void makeBulletInactiveLeft(int idx);
int bulletLeftX[10000];
int bulletLeftY[10000];
bool isBulletActiveLeft[10000];
int bulletCountLeft = 0;

// enemy 1 Tick

void generateTickBullet();
void moveTickBullet();
void printTickBullet(int x, int y);
void eraseTickBullet(int x, int y);
void makeTickBulletInactive(int idx);

int bulletTickX[10000];
int bulletTickY[10000];
bool isBulletActiveTick[10000];
int bulletCountTick = 0;

// enemy 2 Yom
void generateYomBullet();
void moveYomBullet();
void printYomBullet(int x, int y);
void eraseYomBullet(int x, int y);
void makeYomBulletInactive(int idx);
int bulletYomX[10000];
int bulletYomY[10000];
bool isBulletActiveYom[10000];
int bulletCountYom = 0;
void bulletCollisionWithYom();

// enemy 3 Lynch
string direction = "left";
int lynchX = 92;
int lynchY = 6;
char lynch1[6] = {'<', '+', '(', 'U', 'U', ')'};
char lynch2[6] = {' ', ' ', ' ', ' ', 'H', ' '};
void print_Lynch();
void moveLynch();
void eraseLynch();

void generateLynchBullet();
void moveLynchBullet();
void printLynchBullet(int x, int y);
void eraseLynchBullet(int x, int y);
void makeLynchBulletInactive(int idx);
int bulletLynchX[10000];
int bulletLynchY[10000];
bool isBulletActiveLynch[10000];
int bulletCountLynch = 0;
void bulletCollisionWithLynch();
void bulletCollisionWithLynchLeft();

// enemy collision with player
void enemyCollisionWithplayer();
void lynchCollisionWithPlayer();
void yomCollisionWithPlayer();
void rem_health();

// enemy health
void rem_lynchHealth();
void rem_yomHealth();
void rem_tickHealth();

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
            print_Lynch();
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
                if (GetAsyncKeyState(VK_LCONTROL))
                {
                    generateBulletLeft();
                }
                if (GetAsyncKeyState(VK_ESCAPE))
                {
                    break;
                }

                if (timer == 3)
                {
                    if(tick_health>0)
                    {
                        moveEnemy();
                    }
                    else if(tick_health==0)
                    {
                        eraseEnemy();
                    }
                    if (yom_health >0)
                    {
                        moveYom();
                    }
                    else if(yom_health==0)
                    {
                        eraseYom();
                    }
                    timer = 0;
                }
                moveLynchBullet();
                if (lynch_health > 0)
                {

                    generateLynchBullet();
                    moveLynch();
                    bulletCollisionWithLynch();
                    bulletCollisionWithLynchLeft();
                }
                else if (lynch_health == 0)
                {
                    eraseLynch();
                }
                moveYomBullet();
                if (yom_health > 0)
                {
                    generateYomBullet();
                    bulletCollisionWithYom();
                }
                else if (yom_health == 0)
                {
                    eraseYom();
                }
                moveTickBullet();
                if(tick_health>0)
                {
                    generateTickBullet();
                    bulletCollisionWithEnemy();
                }
                else if(tick_health==0)
                {
                    eraseEnemy();
                }
                moveBullet();
                moveBulletLeft();
                enemyCollisionWithplayer();
                lynchCollisionWithPlayer();
                yomCollisionWithPlayer();

                timer++;
                Sleep(50);
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
                    cout << "__________________________" << endl;
                    cout << "Up\t\tMoves Up" << endl;
                    cout << "Down\t\tMoves Down" << endl;
                    cout << "Left\t\tMoves Left" << endl;
                    cout << "Right\t\tMoves Right" << endl;
                    cout << "Space'\t\tFire" << endl;
                    cout << "Left Control\t Opposite Fire" << endl;
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

void rem_tickHealth()
{
    if (tick_health > 0)
    {
        tick_health = tick_health - 5;
    }
}
void rem_yomHealth()
{
    if (yom_health > 0)
    {
        yom_health = yom_health - 5;
    }
}
void rem_lynchHealth()
{
    if (lynch_health > 0)
    {
        lynch_health = lynch_health - 5;
    }
}
void yomCollisionWithPlayer() // yom
{
    for (int x = 0; x < bulletCountYom; x++)
    {
        if (isBulletActiveYom[x] == true)
        {
            if (bulletYomX[x] + 1 == snowbroX && (bulletYomY[x] == snowbroY || bulletYomY[x] == snowbroY + 1))
            {
                rem_health();
            }
            if (snowbroX == bulletYomX[x] && snowbroY == bulletYomY[x])
            {
                rem_health();
            }
        }
    }
}
void lynchCollisionWithPlayer() // lynch
{
    for (int x = 0; x < bulletCountLynch; x++)
    {
        if (isBulletActiveLynch[x] == true)
        {
            if (bulletLynchX[x] - 1 == snowbroX && (bulletLynchY[x] == snowbroY || bulletLynchY[x] == snowbroY + 1))
            {
                rem_health();
            }
            if (snowbroX + 6 == bulletLynchX[x] && snowbroY + 1 == bulletLynchY[x])
            {
                rem_health();
            }
        }
    }
}
void enemyCollisionWithplayer() // tick
{
    for (int x = 0; x < bulletCountTick; x++)
    {
        if (isBulletActiveTick[x] == true)
        {
            if (bulletTickX[x] - 1 == snowbroX && (bulletTickY[x] == snowbroY || bulletTickY[x] == snowbroY + 1))
            {
                rem_health();
            }
            if (snowbroX + 6 == bulletTickX[x] && snowbroY + 1 == bulletTickY[x])
            {
                rem_health();
            }
        }
    }
}
void rem_health()
{
    if (player_health > 0)
    {
        player_health = player_health - 3;
    }
}
void bulletCollisionWithYom()
{
    for (int x = 0; x < bulletCountLeft; x++)
    {
        if (isBulletActiveLeft[x] == true)
        {
            if (bulletLeftX[x] - 1 == yomX && (bulletLeftY[x] == yomY || bulletLeftY[x] == yomY + 1))
            {
                addScore();
                rem_yomHealth();
            }
            if (yomX + 6 == bulletLeftX[x] && yomY + 1 == bulletLeftY[x])
            {
                addScore();
                rem_yomHealth();
            }
        }
    }
}
void bulletCollisionWithLynchLeft()
{
    for (int x = 0; x < bulletCountLeft; x++)
    {
        if (isBulletActiveLeft[x] == true)
        {
            if (bulletLeftX[x] - 1 == lynchX && (bulletLeftY[x] == lynchY || bulletLeftY[x] == lynchY + 1))
            {
                addScore();
                rem_lynchHealth();
            }
            if (lynchX + 6 == bulletLeftX[x] && lynchY + 1 == bulletLeftY[x])
            {
                addScore();
                rem_lynchHealth();
            }
        }
    }
}
void bulletCollisionWithLynch()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            if (bulletX[x] + 1 == lynchX && (bulletY[x] == lynchY || bulletY[x] == lynchY + 1))
            {
                addScore();
                rem_lynchHealth();
            }
            if (lynchX - 1 == bulletX[x] && lynchY + 1 == bulletY[x])
            {
                addScore();
                rem_lynchHealth();
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
void print_Lynch()
{
    gotoxy(lynchX, lynchY);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << lynch1[idx];
    }
    gotoxy(lynchX, lynchY + 1);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << lynch2[idx];
    }
}
void eraseLynch()
{
    gotoxy(lynchX, lynchY);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << " ";
    }
    gotoxy(lynchX, lynchY + 1);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << " ";
    }
}
void moveLynch()
{
    if (direction == "left")
    {
        char next = getCharAtxy(lynchX - 1, lynchY);
        if (next == ' ')
        {
            eraseLynch();
            lynchX--;
            print_Lynch();
        }
        if (lynchX <= 12)
        {
            direction = "right";
        }
    }
    if (direction == "right")
    {
        char next = getCharAtxy(lynchX + 6, lynchY);
        if (next == ' ')
        {
            eraseLynch();
            lynchX++;
            print_Lynch();
        }
        if (lynchX >= 90)
        {
            direction = "left";
        }
    }
}
void printLynchBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "^";
}
void eraseLynchBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void generateLynchBullet()
{
    bulletLynchX[bulletCountLynch] = lynchX - 4;
    bulletLynchY[bulletCountLynch] = lynchY;
    isBulletActiveLynch[bulletCountLynch] = true;
    gotoxy(lynchX - 4, lynchY);
    cout << "^";
    bulletCountLynch++;
}
void moveLynchBullet()
{
    for (int x = 0; x < bulletCountLynch; x++)
    {
        if (isBulletActiveLynch[x] == true)
        {
            char next = getCharAtxy(bulletLynchX[x] - 2, bulletLynchY[x]);
            if (next != ' ')
            {
                eraseLynchBullet(bulletLynchX[x], bulletLynchY[x]);
                makeLynchBulletInactive(x);
            }
            else
            {
                eraseLynchBullet(bulletLynchX[x], bulletLynchY[x]);
                bulletLynchX[x] = bulletLynchX[x] - 2;
                printLynchBullet(bulletLynchX[x], bulletLynchY[x]);
            }
        }
    }
}
void makeLynchBulletInactive(int idx)
{
    isBulletActiveLynch[idx] = false;
}
void generateYomBullet()
{
    bulletYomX[bulletCountYom] = yomX + 6;
    bulletYomY[bulletCountYom] = yomY;
    isBulletActiveYom[bulletCountYom] = true;
    gotoxy(yomX + 6, yomY);
    cout << "-";
    bulletCountYom++;
}
void moveYomBullet()
{
    for (int x = 0; x < bulletCountYom; x++)
    {
        if (isBulletActiveYom[x] == true)
        {
            char next = getCharAtxy(bulletYomX[x] + 2, bulletYomY[x]);
            if (next != ' ')
            {
                eraseYomBullet(bulletYomX[x], bulletYomY[x]);
                makeYomBulletInactive(x);
            }
            else
            {
                eraseYomBullet(bulletYomX[x], bulletYomY[x]);
                bulletYomX[x] = bulletYomX[x] + 2;
                printYomBullet(bulletYomX[x], bulletYomY[x]);
            }
        }
    }
}
void printYomBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "-";
}
void eraseYomBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void makeYomBulletInactive(int idx)
{
    isBulletActiveYom[idx] = false;
}
void generateTickBullet()
{
    bulletTickX[bulletCountTick] = enemyX - 4;
    bulletTickY[bulletCountTick] = enemyY;
    isBulletActiveTick[bulletCountTick] = true;
    gotoxy(enemyX - 4, enemyY);
    cout << "+";
    bulletCountTick++;
}

void moveTickBullet()
{
    for (int x = 0; x < bulletCountTick; x++)
    {
        if (isBulletActiveTick[x] == true)
        {
            char next = getCharAtxy(bulletTickX[x] - 2, bulletTickY[x]);
            if (next != ' ')
            {
                eraseTickBullet(bulletTickX[x], bulletTickY[x]);
                makeTickBulletInactive(x);
            }
            else
            {
                eraseTickBullet(bulletTickX[x], bulletTickY[x]);
                bulletTickX[x] = bulletTickX[x] - 2;
                printTickBullet(bulletTickX[x], bulletTickY[x]);
            }
        }
    }
}

void printTickBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "+";
}

void eraseTickBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void makeTickBulletInactive(int idx)
{
    isBulletActiveTick[idx] = false;
}

void generateBulletLeft()
{
    bulletLeftX[bulletCountLeft] = snowbroX - 1;
    bulletLeftY[bulletCountLeft] = snowbroY;
    isBulletActiveLeft[bulletCountLeft] = true;
    gotoxy(snowbroX - 1, snowbroY);
    cout << "*";
    bulletCountLeft++;
}

void moveBulletLeft()
{
    for (int x = 0; x < bulletCountLeft; x++)
    {
        if (isBulletActiveLeft[x] == true)
        {
            char next = getCharAtxy(bulletLeftX[x] - 1, bulletLeftY[x]);
            if (next != ' ')
            {
                eraseBulletLeft(bulletLeftX[x], bulletLeftY[x]);
                makeBulletInactiveLeft(x);
            }
            else
            {
                eraseBulletLeft(bulletLeftX[x], bulletLeftY[x]);
                bulletLeftX[x] = bulletLeftX[x] - 1;
                printBulletLeft(bulletLeftX[x], bulletLeftY[x]);
            }
        }
    }
}

void printBulletLeft(int x, int y)
{
    gotoxy(x, y);
    cout << "*";
}
void eraseBulletLeft(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void makeBulletInactiveLeft(int idx)
{
    isBulletActiveLeft[idx] = false;
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
    for (int idx = 0; idx < 6; idx++)
    {
        cout << yom1[idx];
    }
    gotoxy(yomX, yomY + 1);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << yom2[idx];
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
    cout << "score:" << score << "  ";
    gotoxy(105, 9);
    cout << "player health:" << player_health << "  ";
    gotoxy(105, 10);
    cout << "Tick health:" << tick_health << " ";
    gotoxy(105, 11);
    cout << "Yom health:" << yom_health << " ";
    gotoxy(105, 12);
    cout << "Lynch health:" << lynch_health << " ";
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
            if (bulletX[x] + 1 == enemyX && (bulletY[x] == enemyY || bulletY[x] == enemyY + 1))
            {
                addScore();
                rem_tickHealth();
            }
            if (enemyX - 1 == bulletX[x] && enemyY + 1 == bulletY[x])
            {
                addScore();
                rem_tickHealth();
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
    for (int idx = 0; idx < 6; idx++)
    {
        char next = getCharAtxy(snowbroX + idx, snowbroY + 2);
        if (next != ' ')
        {
            return;
        }
    }

    eraseSnowbro();
    snowbroY = snowbroY + 1;
    printsnow_bro();
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
    for (int idx = 0; idx < 2; idx++)
    {
        char next = getCharAtxy(snowbroX + 6, snowbroY + idx);
        if (next != ' ')
        {
            return;
        }
    }

    eraseSnowbro();
    snowbroX = snowbroX + 1;
    printsnow_bro();
}

void moveleft()
{
    for (int idx = 0; idx < 2; idx++)
    {
        char next = getCharAtxy(snowbroX - 1, snowbroY + idx);
        if (next != ' ')
        {
            return;
        }
    }
    eraseSnowbro();
    snowbroX = snowbroX - 1;
    printsnow_bro();
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
    cout << "##                                 #####################################                              #" << endl;
    cout << "##      ############################                                  %%%%%%%%%%%%%%%%%%%%%%%%%%      #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                     #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##       %%%%%%%%%%%%%%%%%%%                   %%%%%%%%%%%%%%%%%%%%%%         %%%%%%%%%%%%%%%%%%%%%%%%%#" << endl;
    cout << "##                                                %%                                                  #" << endl;
    cout << "##                                                %%                                                  #" << endl;
    cout << "##                       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                  #" << endl;
    cout << "##                                                %%                                                  #" << endl;
    cout << "##       %%                                       %%                                        %%        #" << endl;
    cout << "##       %%      %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    %%        #" << endl;
    cout << "##       %%                                       %%                                        %%        #" << endl;
    cout << "##       %%                                       %%                                        %%        #" << endl;
    cout << "##       %%         %%%%%%%%                %%%%%%%%%%%%%%%%%%%%%           %%%%%%%%        %%        #" << endl;
    cout << "##                                                %%                                                  #" << endl;
    cout << "##                                                %%                                                  #" << endl;
    cout << "##       %%                                       %%                                        %%        #" << endl;
    cout << "##       %%                                       %%                                        %%        #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##                                                                                                    #" << endl;
    cout << "##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#" << endl;
    cout << "#######################################################################################################" << endl;
}

void logo()
{
    cout << " @@@@@@   @@@  @@@   @@@@@@   @@@  @@@  @@@     @@@@@@@   @@@@@@@    @@@@@@   " << endl;
    cout << "@@@@@@@   @@@@ @@@  @@@@@@@@  @@@  @@@  @@@     @@@@@@@@  @@@@@@@@  @@@@@@@@  " << endl;
    cout << "!@@       @@!@!@@@  @@!  @@@  @@!  @@!  @@!     @@!  @@@  @@!  @@@  @@!  @@@  " << endl;
    cout << "!@!       !@!!@!@!  !@!  @!@  !@!  !@!  !@!     !@   @!@  !@!  @!@  !@!  @!@  " << endl;
    cout << "!!@@!!    @!@ !!@!  @!@  !@!  @!!  !!@  @!@     @!@!@!@   @!@!!@!   @!@  !@!  " << endl;
    cout << " !!@!!!   !@!  !!!  !@!  !!!  !@!  !!!  !@!     !!!@!!!!  !!@!@!    !@!  !!!  " << endl;
    cout << "     !:!  !!:  !!!  !!:  !!!  !!:  !!:  !!:     !!:  !!!  !!: :!!   !!:  !!!  " << endl;
    cout << "    !:!   :!:  !:!  :!:  !:!  :!:  :!:  :!:     :!:  !:!  :!:  !:!  :!:  !:!  " << endl;
    cout << ":::: ::    ::   ::  ::::: ::   :::: :: :::       :: ::::  ::   :::  ::::: ::  " << endl;
    cout << ":: : :    ::    :    : :  :     :: :  : :       :: : ::    :   : :   : :  :   " << endl;
}