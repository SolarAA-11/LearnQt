#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void data_ready_to_read();
    void date_read_finished();

private:
    Ui::Widget *ui;
    QNetworkAccessManager *m_netManager;
    QNetworkReply *m_netReply;
    QByteArray *m_buffer;
};
#endif // WIDGET_H
