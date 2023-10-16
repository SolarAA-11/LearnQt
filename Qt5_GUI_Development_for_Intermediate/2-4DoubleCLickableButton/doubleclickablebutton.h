#ifndef DOUBLECLICKABLEBUTTON_H
#define DOUBLECLICKABLEBUTTON_H

#include <QWidget>


// A Custom Widget that can react to double mouse press
// and emit signal doubleClicked
class DoubleClickableButton : public QWidget
{
    Q_OBJECT
public:
    explicit DoubleClickableButton(QWidget *parent = nullptr);

signals:
    void doubleClicked();

    // QWidget interface
protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;
};

#endif // DOUBLECLICKABLEBUTTON_H
