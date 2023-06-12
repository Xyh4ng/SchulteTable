/*
 * @Author: Xyh4ng 503177404@qq.com
 * @Date: 2023-06-09 20:21:29
 * @FilePath: \SchulteTable\src\main.cpp
 * @Description:
 * Copyright (c) 2023 by Xyh4ng, All Rights Reserved.
 */
#include "schulte.h"

#include <QApplication>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Schulte w;
    w.show();
    return a.exec();
}