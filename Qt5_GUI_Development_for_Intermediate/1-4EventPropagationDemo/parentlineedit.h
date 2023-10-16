#ifndef PARENTLINEEDIT_H
#define PARENTLINEEDIT_H

#include <QLineEdit>

class ParentLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    ParentLineEdit(QWidget *parent = nullptr);

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // PARENTLINEEDIT_H
