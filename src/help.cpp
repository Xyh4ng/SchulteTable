/*
 * @Author: Xyh4ng 503177404@qq.com
 * @Date: 2023-06-11 16:22:52
 * @FilePath: \SchulteTable\src\help.cpp
 * @Description:
 * Copyright (c) 2023 by Xyh4ng, All Rights Reserved.
 */
#include "help.h"

Help::Help(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout(this);
    layout->setAlignment(Qt::AlignHCenter);
    layout->setContentsMargins(50, 100, 50, 100);
    layout->setVerticalSpacing(30);

    note_label = new QLabel(QString::fromStdString("游戏说明："), this);
    note_label->setFont(QFont("黑体", 24));

    content_label = new QLabel(this);
    content_label->setText("\
1、游戏界面为由5x5大小的网格组成，每个网格内有一个数字，用户需要\n\n\
   将网格中出现的数，从小到大依次点击。\n\n\
2、每轮游戏会出现连续的25个数字，所有可能出现的数字的范围为1~99\n\n\
3、若点击正确，方格会显示绿色，否则显示红色。\n\n\
4、游戏会记录用户从开始到完成游戏的时长和总点击次数，在用户完成任\n\n\
   务后予以显示。\n\n\
5、预祝您游戏愉快！\n");
    content_label->setFont(QFont("黑体", 15));

    back_button = new QPushButton(QString::fromStdString("返回主页"), this);
    back_button->setFont(QFont("黑体", 12));

    layout->addWidget(note_label, 0, 0, 1, 1);
    layout->addWidget(content_label, 1, 0, 5, 5);
    layout->addWidget(back_button, 6, 0, 1, 1);

    setLayout(layout);
}