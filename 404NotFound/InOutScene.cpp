#include "InOutScene.h"
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <conio.h>
#include "Core.h"

using namespace std;

InOutScene* InOutScene::m_pInst = nullptr;
InOutScene::InOutScene()
{
}

InOutScene::~InOutScene()
{
}

void InOutScene::Die()
{
    int iUnimode = _setmode(_fileno(stdout), _O_U16TEXT);

    wcout << L"    █████▒▒█████   █    ██  ███▄    █ ▓█████▄ ▓█████ ▓█████▄  ▐██▌ " << endl;
    wcout << L"  ▓██   ▒▒██▒  ██▒ ██  ▓██▒ ██ ▀█   █ ▒██▀ ██▌▓█   ▀ ▒██▀ ██▌ ▐██▌ " << endl;
    wcout << L"  ▒████ ░▒██░  ██▒▓██  ▒██░▓██  ▀█ ██▒░██   █▌▒███   ░██   █▌ ▐██▌ " << endl;
    wcout << L"  ░▓█▒  ░▒██   ██░▓▓█  ░██░▓██▒  ▐▌██▒░▓█▄   ▌▒▓█  ▄ ░▓█▄   ▌ ▓██▒ " << endl;
    wcout << L"  ░▒█░   ░ ████▓▒░▒▒█████▓ ▒██░   ▓██░░▒████▓ ░▒████▒░▒████▓  ▒▄▄  " << endl;
    wcout << L"   ▒ ░   ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒ ░ ▒░   ▒ ▒  ▒▒▓  ▒ ░░ ▒░ ░ ▒▒▓  ▒  ░▀▀▒ " << endl;
    wcout << L"   ░       ░ ▒ ▒░ ░░▒░ ░ ░ ░ ░░   ░ ▒░ ░ ▒  ▒  ░ ░  ░ ░ ▒  ▒  ░  ░ " << endl;
    wcout << L"   ░ ░   ░ ░ ░ ▒   ░░░ ░ ░    ░   ░ ░  ░ ░  ░    ░    ░ ░  ░     ░ " << endl;
    wcout << L"             ░ ░     ░              ░    ░       ░  ░   ░     ░    " << endl;
    wcout << L"                                       ░              ░            " << endl;

    int iDefmode = _setmode(_fileno(stdout), iUnimode);
    system("pause");
}

void InOutScene::Clear()
{
    int iUnimode = _setmode(_fileno(stdout), _O_U16TEXT);

    wcout << L"███▄▄▄▄    ▄██████▄      ███             ▄████████  ▄██████▄  ███    █▄  ███▄▄▄▄   ████████▄     ▄████████ ████████▄  " << endl;
    wcout << L"███▀▀▀██▄ ███    ███ ▀█████████▄        ███    ███ ███    ███ ███    ███ ███▀▀▀██▄ ███   ▀███   ███    ███ ███   ▀███ " << endl;
    wcout << L"███   ███ ███    ███    ▀███▀▀██        ███    █▀  ███    ███ ███    ███ ███   ███ ███    ███   ███    █▀  ███    ███ " << endl;
    wcout << L"███   ███ ███    ███     ███   ▀       ▄███▄▄▄     ███    ███ ███    ███ ███   ███ ███    ███  ▄███▄▄▄     ███    ███ " << endl;
    wcout << L"███   ███ ███    ███     ███          ▀▀███▀▀▀     ███    ███ ███    ███ ███   ███ ███    ███ ▀▀███▀▀▀     ███    ███ " << endl;
    wcout << L"███   ███ ███    ███     ███            ███        ███    ███ ███    ███ ███   ███ ███    ███   ███    █▄  ███    ███ " << endl;
    wcout << L"███   ███ ███    ███     ███            ███        ███    ███ ███    ███ ███   ███ ███   ▄███   ███    ███ ███   ▄███ " << endl;
    wcout << L" ▀█   █▀   ▀██████▀     ▄████▀          ███         ▀██████▀  ████████▀   ▀█   █▀  ████████▀    ██████████ ████████▀  " << endl;

    int iDefmode = _setmode(_fileno(stdout), iUnimode);
    system("pause");
}
