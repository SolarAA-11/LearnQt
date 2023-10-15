#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>

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
    void on_fetchButton_clicked();

private:
    Ui::Widget *ui;
    QJsonDocument *m_json_document;
    QNetworkAccessManager *m_net_manager;
    QNetworkReply *m_net_reply;
    QByteArray *m_buffer;
};
#endif // WIDGET_H
