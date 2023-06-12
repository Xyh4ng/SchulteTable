/*
 * @Author: Xyh4ng 503177404@qq.com
 * @Date: 2023-06-12 12:07:27
 * @FilePath: \SchulteTable\src\help.h
 * @Description:
 * Copyright (c) 2023 by Xyh4ng, All Rights Reserved.
 */
#ifndef HELP_H
#define HELP_H

#include <qgridlayout.h>
#include <qlabel.h>
#include <qobjectdefs.h>
#include <qpushbutton.h>
#include <qwidget.h>

class Help : public QWidget
{
    Q_OBJECT

public:
    Help(QWidget *parent = nullptr);
    ~Help()
    {
        delete layout;
    }

    QPushButton *back_button;

private:
    QGridLayout *layout;
    QLabel *note_label;
    QLabel *content_label;
};

#endif