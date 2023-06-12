/*
 * @Author: Xyh4ng 503177404@qq.com
 * @Date: 2023-06-11 18:59:49
 * @FilePath: \SchulteTable\src\mylabel.h
 * @Description:
 * Copyright (c) 2023 by Xyh4ng, All Rights Reserved.
 */
#ifndef MYLABEL_H
#define MYLABEL_H

#include <QMouseEvent>
#include <qlabel.h>
#include <qobjectdefs.h>
#include <qwidget.h>

class MyLabel : public QLabel
{
    Q_OBJECT

signals:
    //定义clicked()信号, 在 mouseReleaseEvent 事件发生时触发
    void clicked();

public:
    MyLabel(QWidget *parent = nullptr);
    ~MyLabel() {}

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif