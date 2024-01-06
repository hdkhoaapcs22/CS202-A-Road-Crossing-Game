#ifndef STATES_STATE_H
#define STATES_STATE_H

#include "../BaseParameter.h"
#include "../ColorPalettes/AppColorPalette.h"
#include "../ResourceHolders/TextureHolder.h"
#include "StateIdentifiers.h"

#include <memory>

class StateStack;
class MusicPlayer;

class State {
public:
    typedef std::unique_ptr<State> Ptr;

    struct Context {
        Context(MusicPlayer& music);

        MusicPlayer* music;
    };

public:
    State(StateStack &stack, Context context);
    virtual ~State();

    virtual bool update(float dt) = 0;
    virtual void draw() = 0;
    virtual void setParameter(BaseParameter::Ptr parameter);

protected:
    void requestStackPush(StateIDs stateID);
    void requestStackPush(StateIDs stateID, BaseParameter::Ptr parameter);
    void requestStackPop();
    void requestStackClear();

    Context getContext() const;

private:
    StateStack *mStack;
    Context mContext;
};

#endif // STATES_STATE_H
