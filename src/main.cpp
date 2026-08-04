#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <libtcod/libtcod.hpp>
#include <libtcod/console_printing.hpp>

#include "action.h"
#include "input_handler.h"

struct Player {
    int x;
    int y;
};


int main(int argc, char* argv[]) {
	constexpr int SCREEN_WIDTH = 80;
	constexpr int SCREEN_HEIGHT = 50;

	tcod::Tileset tileset = tcod::load_tilesheet("../dejavu10x10_gs_tc.png", { 32, 8 }, tcod::CHARMAP_TCOD);

    tcod::Console console = tcod::Console{ SCREEN_WIDTH, SCREEN_HEIGHT};  // Main console.

    TCOD_ContextParams params = TCOD_ContextParams{};
    params.console = console.get();  // Derive the window size from the console size.
    params.window_title = "roguelike tutorial";
    params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
    params.vsync = true;
    params.argc = argc;  // This allows some user-control of the context.
    params.argv = argv;
    params.tileset = tileset.get();

	tcod::Context context = tcod::Context(params);

    Player player(1, 1);

    EventHandler handler = EventHandler();

    while (true) {
        //tcod::print(console, { 0, 0 }, "Hello World", std::nullopt, std::nullopt);
        tcod::print(console, { player.x, player.y }, "@", std::nullopt, std::nullopt);
        context.present(console);
        console.clear();

        std::unique_ptr<Action> action = nullptr;

        action = handler.dispatch();
        if (action != nullptr) {
            action->Perform(player);
        }

    }
    return 1;
}