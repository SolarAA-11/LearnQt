#ifndef CONTAINER_H
#define CONTAINER_H

#include <QWidget>
#include <QPoint>

/**
 * @brief The Container class
 * allow user to use mouse drag and drop qlabel widget in itself
 * and between other container widget.
 *
 *
 */
class Container : public QWidget
{
    Q_OBJECT
public:
    explicit Container(QWidget *parent = nullptr);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    const static QString MIMEDATA_FORMAT;

    // The point information when user click a label
    // and the moving distance satisfies application's requirement for triggering drag
    QPoint startPosition;
};

#endif // CONTAINER_H
