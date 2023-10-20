#ifndef DRAGDROPLABEL_H
#define DRAGDROPLABEL_H

#include <QLabel>
#include <QWidget>
#include <QMimeData>


/**
 * @brief The DragDropLabel class
 *
 * This class can accept drag and drop operations.
 *
 * The content of text will display different thing varying by drag situations:
 * 1. When there is not any drag or drop, the label's text
 *    will display "DRAG HERE"
 * 2. When there is a drag(enter or move), the label will display the content of drag operation
 * 3. When there is a drag level event, the label will be cleared and display "DRAG HERE" again,
 *    and emig signal mimedataChanged indicating content be cleared.
 * 4. When there is a drop event, the label will display concrete content and
 *    emit signal mimedataChanged containing drag's mimeData
 *
 */
class DragDropLabel : public QLabel
{
    Q_OBJECT
public:
    DragDropLabel(QWidget *parent);

signals:
    void mimedataChanged(const QMimeData *data = nullptr);

    // QWidget interface
protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private:
    void clear();
};

#endif // DRAGDROPLABEL_H
