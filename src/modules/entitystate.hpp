#ifndef ENTITYSTATE_HPP
#define ENTITYSTATE_HPP

#include "direction.hpp"
#include "action.hpp"

class EntityState {
    private:
        Direction direction;
        Action action;

    public:
        EntityState();
        EntityState(Direction direction, Action action);

        void setDirection(Direction direction);
        void setAction(Action action);

        Direction getDirection() const;
        Action getAction() const;

        friend bool operator <(const EntityState &lhs, const EntityState &rhs);
};

#endif
