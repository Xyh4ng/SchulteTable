/*
 * @Author: Xyh4ng 503177404@qq.com
 * @Date: 2023-06-09 20:21:29
 * @FilePath: \SchulteTable\src\schulte.h
 * @Description:
 * Copyright (c) 2023 by Xyh4ng, All Rights Reserved.
 */
#ifndef SCHULTE_H
#define SCHULTE_H

#include "game.h"
#include "help.h"
#include "home.h"

#include <QMainWindow>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qstackedwidget.h>
#include <qwidget.h>
#include <qwindowdefs.h>

class Schulte : public QMainWindow
{
    Q_OBJECT

public:
    Schulte(QWidget *parent = nullptr);
    ~Schulte()
    {
        delete main_widget;
    }

private:
    QWidget *main_widget;
    QGridLayout *main_layout;
    QStackedWidget *statcked_widget;

    // 游戏主页
    Home *home_widget;

    // 游戏帮助界面
    Help *help_widget;

    // 游戏运行界面
    Game *game_widget;

private slots:
    void start_game();
    void game_help();
    void close_game();
    void back_to_home();
};

#endif