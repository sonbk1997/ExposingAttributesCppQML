#ifndef MESSAGEBOARD_H
#define MESSAGEBOARD_H

#include <QObject>
#include <QDebug>

class MessageBoard : public QObject
{
    Q_OBJECT
public:
    explicit MessageBoard(QObject *parent = nullptr);

    Q_INVOKABLE bool postMessage(const QString &msg) { //Exposing method using Method 1 Q_INVOKABLE
        qDebug() << "Called the C++ method with" << msg;
        emit messageSent(msg);
        return true;
    }
public slots:      //Exposing method using Method 2 slots
    void refresh() {
        qDebug() << "Called the C++ slot";
    }
signals:
    void messageSent(const QString &msg);     // Exposing signals to QML msg call in QML
};

#endif // MESSAGEBOARD_H
