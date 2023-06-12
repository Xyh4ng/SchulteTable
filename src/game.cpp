/*
 * @Author: Xyh4ng 503177404@qq.com
 * @Date: 2023-06-11 16:23:02
 * @FilePath: \SchulteTable\src\game.cpp
 * @Description:
 * Copyright (c) 2023 by Xyh4ng, All Rights Reserved.
 */
#include "game.h"

#include <algorithm>
#include <ctime>
#include <iterator>
#include <numeric>
#include <qcolor.h>
#include <qmessagebox.h>
#include <qnamespace.h>
#include <qpalette.h>
#include <qtimer.h>
#include <random>
#include <string>

Game::Game(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout(this);

    for (int i = 0; i < 25; ++i)
    {
        table_list[i] = new MyLabel(this);
        layout->addWidget(table_list[i], i / 5, i % 5, 1, 1);
        table_list[i]->setFrameShape(QFrame::Box);
        table_list[i]->setFont(QFont("simhei", 30));
        table_list[i]->setAlignment(Qt::AlignCenter);
        connect(table_list[i], &MyLabel::clicked, this, &Game::clicked);
    }

    restart_button = new QPushButton(QString::fromStdString("重新开始"), this);
    restart_button->setFont(QFont("黑体", 12));
    back_button = new QPushButton(QString::fromStdString("返回主页"), this);
    back_button->setFont(QFont("黑体", 12));

    layout->addWidget(restart_button, 5, 1, 1, 1);
    layout->addWidget(back_button, 5, 3, 1, 1);

    setLayout(layout);

    connect(restart_button, &QPushButton::clicked, this, &Game::run);

    std::iota(std::begin(idx), std::end(idx), 0);
}

void Game::run()
{
    // 开始数字的范围为1~75
    std::uniform_int_distribution<unsigned> u(1, 75);
    static std::default_random_engine e((unsigned)time(nullptr));
    start_num = u(e);
    next_num = start_num;
    clicked_cnt = 0;
    // 打乱顺序
    srand((unsigned)time(nullptr));
    std::random_shuffle(std::begin(idx), std::end(idx));
    for (int i = 0; i < 25; ++i)
    {
        table_list[i]->setText(QString::fromStdString(std::to_string(idx[i] + start_num)));
    }
    start_time = clock();
}

void Game::clicked()
{
    ++clicked_cnt;
    MyLabel *send = dynamic_cast<MyLabel *>(sender());
    if (send->text() == QString::fromStdString(std::to_string(next_num)))
    {
        ++next_num;
        send->setStyleSheet(QString("background-color: %1").arg(QColor(0, 255, 0).name()));
    }
    else
    {
        send->setStyleSheet(QString("background-color: %1").arg(QColor(255, 0, 0).name()));
    }
    QTimer::singleShot(200, this, [=]()
                       { send->setStyleSheet(QString("background-color: %1").arg(QColor(240, 240, 240).name())); });
    if (next_num == start_num + 25)
    {
        double spend_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
        QMessageBox::information(this, QString::fromStdString("恭喜"),
                                 QString::fromStdString("恭喜您完成游戏！\n您共用时%1秒，准确率为：25/%2").arg(spend_time).arg(clicked_cnt),
                                 QMessageBox::Ok);
    }
}
