#ifndef FSM_H
#define FSM_H
#include <QObject>

class FSM : public QObject {
    Q_OBJECT

public:
    enum class State {
        INIT,
        HOME,
        CREATE_CHARACTER

    };
    Q_ENUM(State)

    FSM();

public slots:
    void start();

    void create();

signals:
    void stateChanged(State state);

private:
    State state;
};


#endif // FSM_H
