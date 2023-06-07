#ifndef JSONREADER_H
#define JSONREADER_H

#include <QObject>

class JsonReader : public QObject
{
    Q_OBJECT
public:
    static JsonReader* GetInstance(QObject *parent = nullptr);
private:
    static JsonReader* m_instance;
    explicit JsonReader(QObject *parent = nullptr);

signals:

};

#endif // JSONREADER_H
