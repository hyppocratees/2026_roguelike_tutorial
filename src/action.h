#ifndef ROGUELIKETUTORIAL_ACTION
#define ROGUELIKETUTORIAL_ACTION

struct Player;

class Action {
public:
	void virtual Perform(Player& player) = 0;
};

class EscapeAction : public Action {
public:
	void virtual Perform(Player& player);
};

class MovementAction : public Action {
public:
	void virtual Perform(Player& player);
	MovementAction(int dx, int dy) : Action(), dx_(dx), dy_(dy) {}
private:
	int dx_ = 0;
	int dy_ = 0;
};



#endif