/*
 * @Author: Xyh4ng 503177404@qq.com
 * @Date: 2023-06-09 20:21:29
 * @FilePath: \SchulteTable\src\schulte.cpp
 * @Description:
 * Copyright (c) 2023 by Xyh4ng, All Rights Reserved.
 */
#include "schulte.h"

#include <qmessagebox.h>

Schulte::Schulte(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(QString::fromStdString("舒尔特方格"));
    // resize(800, 800);

    // 游戏主页
    home_widget = new Home(this);

    connect(home_widget->start_button, &QPushButton::clicked, this, &Schulte::start_game);
    connect(home_widget->help_button, &QPushButton::clicked, this, &Schulte::game_help);
    connect(home_widget->close_button, &QPushButton::clicked, this, &Schulte::close_game);

    // 游戏帮助界面
    help_widget = new Help(this);

    connect(help_widget->back_button, &QPushButton::clicked, this, &Schulte::back_to_home);

    // 游戏运行界面
    game_widget = new Game(this);

    connect(game_widget->back_button, &QPushButton::clicked, this, &Schulte::back_to_home);

    // 主显示
    statcked_widget = new QStackedWidget(this);
    statcked_widget->addWidget(home_widget);
    statcked_widget->addWidget(help_widget);
    statcked_widget->addWidget(game_widget);
    statcked_widget->setCurrentIndex(0);

    main_widget = new QWidget(this);
    main_layout = new QGridLayout(this);
    setCentralWidget(main_widget);

    main_layout->addWidget(statcked_widget);
    main_widget->setLayout(main_layout);
}

void Schulte::start_game()
{
    statcked_widget->setCurrentIndex(2);
    game_widget->run();
}
void Schulte::game_help()
{
    statcked_widget->setCurrentIndex(1);
}

void Schulte::close_game()
{
    close();
}

void Schulte::back_to_home()
{
    statcked_widget->setCurrentIndex(0);
}
