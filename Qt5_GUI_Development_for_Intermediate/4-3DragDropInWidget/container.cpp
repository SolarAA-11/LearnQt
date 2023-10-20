#include "container.h"

#include <QLabel>
#include <QPixmap>
#include <QDrag>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QDropEvent>
#include <QPainter>
#include <QPen>
#include <QApplication>
#include <QMimeData>
#include <QDataStream>
#include <QMimeData>

const QString Container::MIMEDATA_FORMAT = "Application/q-customdata";

Container::Container(QWidget *parent)
    : QWidget{parent}
{
    auto setPixmapLabel = [=](const QUrl &imagePath, const QPoint &pos) {
        QLabel *label = new QLabel(this);
        label->setAttribute(Qt::WA_DeleteOnClose);

        QPixmap pixmap;
        pixmap.load(imagePath.path());
        label->resize(pixmap.size());
        label->move(pos);
        label->setPixmap(pixmap);
        label->show();
    };

    setPixmapLabel(QUrl(":/images/cpp.png"), QPoint(50, 50));
    setPixmapLabel(QUrl(":/images/qt.png"), QPoint(150, 50));
    setPixmapLabel(QUrl(":/images/terminal.png"), QPoint(50, 150));

    setAcceptDrops(true);
}


void Container::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        startPosition = event->pos();
        event->accept();
    } else
    {
        event->ignore();
    }
}

void Container::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        QPoint currentPos = event->pos();
        double distance = (currentPos - startPosition).manhattanLength();
        if(distance > QApplication::startDragDistance())
        {
            // Mouse Move Distance Satisfies the Requirement of Triggering Drag Operation

            // Retrieve label widget's pointer
            QLabel *label = static_cast<QLabel*>(childAt(startPosition));
            if(label == nullptr)
            {
                event->accept();
                return;
            }



            QPointF offset = startPosition - label->pos();

            QByteArray buffer;
            QDataStream inputStream(&buffer, QIODevice::WriteOnly);
            QPixmap pixmap = label->pixmap();
            inputStream << pixmap << offset;

            QMimeData *mimeData = new QMimeData();
            mimeData->setData(
                MIMEDATA_FORMAT,
                buffer);

            // Create
            QDrag drag(this);
            drag.setPixmap(pixmap);
            drag.setHotSpot(offset.toPoint());
            drag.setMimeData(mimeData);

            // Blur the label
            QPixmap tempPixmap = label->pixmap();
            QPainter painter(&tempPixmap);
            painter.fillRect(label->rect(), QColor(137, 137, 137, 137));
            label->setPixmap(tempPixmap);

            // Exec a Drag Operation
            if(drag.exec(Qt::MoveAction | Qt::CopyAction, Qt::CopyAction) == Qt::MoveAction)
            {
                // The label is moved to current container.
                // We just close it(delete by attribute).
                label->close();
                event->accept();
            } else
            {
                // The label is copied to another container.
                // We accept event and restore the original pixmap
                label->setPixmap(drag.pixmap());
                event->accept();
            }
        } else event->ignore();
    } else
    {
        event->ignore();
    }
}

void Container::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void Container::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
}

void Container::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void Container::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    if(mimeData->hasFormat(MIMEDATA_FORMAT))
    {
        if(event->source() == this)
        {
            // Drag Label Within Current Container
            QLabel *newLabel = new QLabel(this);
            newLabel->setAttribute(Qt::WA_DeleteOnClose);

            // Set Pixmap Data and Offset
            QPointF currentPos = event->position();

            QPointF offset;
            QPixmap pixmap;
            QByteArray mimeDataBuffer = mimeData->data(MIMEDATA_FORMAT);
            QDataStream outStream(&mimeDataBuffer, QIODevice::ReadOnly);
            outStream >> pixmap >> offset;

            newLabel->setPixmap(pixmap);
            newLabel->move((currentPos - offset).toPoint());
            newLabel->show();

            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else
        {
            // Draw Label to Another Container
            // We should copy that label to current container

            QLabel *newLabel = new QLabel(this);
            newLabel->setAttribute(Qt::WA_DeleteOnClose);

            // Set Pixmap Data and Offset
            QPointF currentPos = event->position();

            QPointF offset;
            QPixmap pixmap;
            QByteArray mimeDataBuffer = mimeData->data(MIMEDATA_FORMAT);
            QDataStream outStream(&mimeDataBuffer, QIODevice::ReadOnly);
            outStream >> pixmap >> offset;

            newLabel->setPixmap(pixmap);
            newLabel->move((currentPos - offset).toPoint());
            newLabel->show();

            // Notify the opposite container that we accept CopyAction, the default setting
            event->acceptProposedAction();
        }
    } else
    {
        event->accept();
    }
}


void Container::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::black);
    pen.setJoinStyle(Qt::RoundJoin);

    QRect frameRect(
        4, 4,
        width() - 8, height() - 8);
    painter.drawRoundedRect(frameRect, 4, 4);

    QWidget::paintEvent(event);
}
