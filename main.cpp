#include <iostream>
#include <qapplication.h>
#include <qmessagebox.h>
#include "main_window.h"
#include "FWLoader/FWLoader.hpp"

int main(int argv, char** argc)
{
    QApplication app(argv, argc);
    MainWindow mainWin(argv, argc);
    mainWin.resize(500, 200);
    mainWin.show();
    int res = app.exec();
    return res;
}