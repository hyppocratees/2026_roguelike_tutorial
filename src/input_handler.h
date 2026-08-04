#ifndef ROGUELIKETUTORIAL_INPUT_HANDLER
#define ROGUELIKETUTORIAL_INPUT_HANDLER

#include "action.h"

#include <SDL3/SDL_events.h>

#include <memory>

class EventHandler {
public:
	std::unique_ptr<Action> dispatch() const;
	std::unique_ptr<Action> ev_keydown(const SDL_Event& event) const;
};







#endif