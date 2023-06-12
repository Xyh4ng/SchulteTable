/*
 * @Author: Xyh4ng 503177404@qq.com
 * @Date: 2023-06-11 16:22:57
 * @FilePath: \SchulteTable\src\game.h
 * @Description:
 * Copyright (c) 2023 by Xyh4ng, All Rights Reserved.
 */
#ifndef GAME_H
#define GAME_H

#include "mylabel.h"

#include <ctime>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qobjectdefs.h>
#include <qpushbutton.h>
#include <qwidget.h>

class Game : public QWidget
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game()
    {
        delete layout;
    }

    void run();

    QPushButton *back_button;

private:
    QGridLayout *layout;
    QPushButton *restart_button;
    MyLabel *table_list[25];

    int idx[25];
    unsigned start_num;
    unsigned next_num;
    unsigned clicked_cnt = 0;

    clock_t start_time;

private slots:
    void clicked();
};

#endif