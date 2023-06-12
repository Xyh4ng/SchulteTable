/*
 * @Author: Xyh4ng 503177404@qq.com
 * @Date: 2023-06-11 18:59:56
 * @FilePath: \SchulteTable\src\mylabel.cpp
 * @Description:
 * Copyright (c) 2023 by Xyh4ng, All Rights Reserved.
 */
#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent)
    : QLabel(parent)
{
}

void MyLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit clicked();
    }
}
