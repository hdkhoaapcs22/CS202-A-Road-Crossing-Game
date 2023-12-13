#ifndef STATESTACK_H
#define STATESTACK_H

#include "States/State.h"
#include "States/StateIdentifiers.h"
#include "BaseParameter.h"

#include <functional>
#include <map>
#include <vector>

class StateStack {
public:
    explicit StateStack(State::Context context);

    template <typename StateType>
    void registerState(StateIDs stateID);

    void update(float dt);
    void draw();

    void pushState(StateIDs stateID);
    void pushParameterizedState(StateIDs stateID, BaseParameter *parameter);
    void popState();
    void clearStates();

    bool isEmpty() const;

private:
    enum class Action {
        Push,
        PushParameterized,
        Pop,
        Clear
    };

    struct PendingChange {
        explicit PendingChange(Action action,
                               StateIDs stateID = StateIDs::None, BaseParameter *parameter = nullptr);

        Action action;
        StateIDs stateID;
        BaseParameter *parameter;
    };

private:
    void applyPendingChange();

    State::Ptr createState(StateIDs stateID);

private:
    std::vector<State::Ptr> mStack;
    std::vector<PendingChange> mPendingList;

    std::map<StateIDs, std::function<State::Ptr()>> mFactories;
    State::Context mContext;
};

#include "StateStack.inl"
#endif // STATESTACK_H
