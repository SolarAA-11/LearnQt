#include "dragdroplabel.h"

#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QDropEvent>
#include <QPalette>

DragDropLabel::DragDropLabel(QWidget *parent)
    : QLabel(parent)
{
    setAutoFillBackground(true);
    QPalette widgetPalette = palette();
    widgetPalette.setColor(QPalette::Window, Qt::gray);
    setAcceptDrops(true);
}


void DragDropLabel::dragEnterEvent(QDragEnterEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    qDebug() << mimeData->formats();

    if(mimeData->hasText())
    {
        qDebug() << "hasText";
        QString text = mimeData->text();
        setText(text);
    } else if(mimeData->hasHtml())
    {
        qDebug() << "hasHtml";
        QString htmlText = mimeData->html();
        setText(htmlText);
    } else if(mimeData->hasImage())
    {
        qDebug() << "hasImage";
        QPixmap pixmap = QPixmap(mimeData->imageData().toByteArray());
        setPixmap(pixmap);
    } else if(mimeData->hasUrls())
    {
        qDebug() << "hasUrls";
        QString text;
        QList<QUrl> urlList = mimeData->urls();
        for(auto& url: urlList)
        {
            text.append(url.fileName()).append("\n");
        }
        setText(text);
    }

    event->acceptProposedAction();
}

void DragDropLabel::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}

void DragDropLabel::dragLeaveEvent(QDragLeaveEvent *event)
{
    clear();
    event->accept();
}

void DragDropLabel::dropEvent(QDropEvent *event)
{
    event->acceptProposedAction();
    emit mimedataChanged(event->mimeData());
}

void DragDropLabel::clear()
{
    setText("DROP HERE");
    emit mimedataChanged();
}
