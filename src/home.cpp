/*
 * @Author: Xyh4ng 503177404@qq.com
 * @Date: 2023-06-11 16:22:32
 * @FilePath: \SchulteTable\src\home.cpp
 * @Description:
 * Copyright (c) 2023 by Xyh4ng, All Rights Reserved.
 */
#include "home.h"

Home::Home(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout(this);
    layout->setAlignment(Qt::AlignHCenter);
    layout->setContentsMargins(100, 100, 100, 100);
    layout->setVerticalSpacing(30);

    title = new QLabel(QString::fromStdString("Schulte Table"), this);
    title->setFont(QFont("黑体", 36));
    start_button = new QPushButton(QString::fromStdString("开始游戏"), this);
    start_button->setFont(QFont("黑体", 18));
    help_button = new QPushButton(QString::fromStdString("游戏帮助"), this);
    help_button->setFont(QFont("黑体", 18));
    close_button = new QPushButton(QString::fromStdString("退出游戏"), this);
    close_button->setFont(QFont("黑体", 18));

    layout->addWidget(title, 0, 0);
    layout->addWidget(start_button, 1, 0);
    layout->addWidget(help_button, 2, 0);
    layout->addWidget(close_button, 3, 0);

    setLayout(layout);
}