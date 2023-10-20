#include "widget.h"
#include "./ui_widget.h"

#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QDropEvent>
#include <QMimeData>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void Widget::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
}

void Widget::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void Widget::dropEvent(QDropEvent *event)
{
    event->acceptProposedAction();

    const QMimeData *mimeData = event->mimeData();
    if(mimeData->hasUrls())
    {
        qDebug() << "Has urls";
        QList<QUrl> urlList = mimeData->urls();
        if(urlList.size() > 1)
            return;

        QFileInfo fileInfo(urlList.first().toLocalFile());
        if(!isImage(fileInfo))
            return;

        QPixmap pixmap;
        if(pixmap.load(fileInfo.absoluteFilePath()))
        {
            ui->label->setPixmap(pixmap.scaled(ui->label->size()));
        }
    } else if(mimeData->hasImage())
    {
        qDebug() << "Has Images";
    }
}

bool Widget::isImage(const QFileInfo &fileInfo)
{
    QString fileNameSuffix = fileInfo.suffix().toLower();
    return fileNameSuffix == "png"
           || fileNameSuffix == "jpg"
           || fileNameSuffix == "jpeg";
}
