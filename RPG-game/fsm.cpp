#include "fsm.h"
#include <QDebug>

FSM::FSM() : state(State::INIT) {}

void FSM::start() {
    state = State::HOME;
    emit stateChanged(state);
}

void FSM::create() {
    state = State::CREATE_CHARACTER;
    emit stateChanged(state);
}
