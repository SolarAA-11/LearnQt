#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->dragDropLabel, &DragDropLabel::mimedataChanged,
            this, &Widget::onMimeDataChanged);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::onMimeDataChanged(const QMimeData *mimeData)
{
    if(mimeData->hasText())
    {
        QString content = mimeData->text();
        ui->textEdit->setText(content);
    }


}


