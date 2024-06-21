#include "fsm.h"
#include <QDebug>

FSM::FSM() : state(State::INIT) {}

void FSM::start() {
    state = State::HOME;
    emit stateChanged(state);
}

void FSM::create_character() {
    state = State::CREATE_CHARACTER;
    emit stateChanged(state);
}

void FSM::generate_attributes(){
    state = State::GENERATE_ATTRIBUTES;
    emit stateChanged(state);
}
