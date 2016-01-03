#include "entitystate.hpp"

EntityState::EntityState() {
    direction = RIGHT;
    action = STANDING;
}

EntityState::EntityState(Direction direction, Action action) {
    this->direction = direction;
    this->action = action;
}

void EntityState::setDirection(Direction direction) {
    this->direction = direction;
}

void EntityState::setAction(Action action) {
    this->action = action;
}

Direction EntityState::getDirection() const {
    return direction;
}

Action EntityState::getAction() const {
    return action;
}

bool operator<(const EntityState &lhs, const EntityState &rhs) {
    return (lhs.getAction() < rhs.getAction()) && (lhs.getDirection() < rhs.getDirection());
}
