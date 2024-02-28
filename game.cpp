#include "game.h"
#include "surface.h"
#include "template.h"

namespace Tmpl8
{
    float x = 400, y = 256;

    void Game::Init() {}

    void Game::Shutdown() {}

    void Game::Tick(float deltaTime)
    {
        screen->Clear(0);
        screen->Line(mousex, 0, mousex, 511, 0xff0000);
        screen->Line(0, mousey, 799, mousey, 0xff0000); float dx = x - mousex, dy = y - mousey;
        float dist = sqrtf(dx * dx + dy * dy);
        if (dist < 50)
            x += dx / dist, y += dy / dist;
        screen->Plot((int)x, (int)y, 0xffffff);
    }
};