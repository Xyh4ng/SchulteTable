/*
 * @Author: Xyh4ng 503177404@qq.com
 * @Date: 2023-06-11 16:22:23
 * @FilePath: \SchulteTable\src\home.h
 * @Description:
 * Copyright (c) 2023 by Xyh4ng, All Rights Reserved.
 */
#ifndef HOME_H
#define HOME_H

#include <qgridlayout.h>
#include <qlabel.h>
#include <qobjectdefs.h>
#include <qpushbutton.h>
#include <qwidget.h>

class Home : public QWidget
{
    Q_OBJECT

public:
    Home(QWidget *parent = nullptr);
    ~Home()
    {
        delete layout;
    }

    QPushButton *start_button;
    QPushButton *help_button;
    QPushButton *close_button;

private:
    QGridLayout *layout;
    QLabel *title;
};

#endif