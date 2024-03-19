#include "game.h"
#include "surface.h"
#include "windows.h"
#include "template.h"
#define WIN32_LEAN_AND_MEAN

constexpr int tileWidth = 32;
constexpr int tileHeight = 32;
constexpr int mapWidth = 10 * tileWidth;
constexpr int mapHeight = 5 * tileHeight;
constexpr int tileOffsetX = (ScreenWidth / 2 - mapWidth / 2 );
constexpr int tileOffsetY = (ScreenHeight / 2 - mapHeight / 2);


namespace Tmpl8
{
    void Game::Init() {}
    void Game::Shutdown() {}

    Surface tiles("assets/tilemap.png");
    Sprite tank(new Surface("assets/ctankbase.tga"), 16);
    float px = 32.0f + tileOffsetX, py = 32.0f + tileOffsetY;
    float playerSpeed = 60.0f;

    char map[5][31] = {
         "kc kc kc kc kc kc kc kc kc kc ",
         "kc fb fb fb kc kc kc kc kc kc ",
         "kc fb fb fb fb fb kc kc kc kc ",
         "kc lc lc fb fb fb kc kc kc kc ",
         "kc kc kc lc lc lc kc kc kc kc "
    };

    bool CheckPos(int x, int y)
    {
        int tx = (x - tileOffsetX) / tileWidth;
        int ty = (y - tileOffsetY) / tileHeight;
        return map[ty][tx * 3 + 2] != 'X';
    }

    void DrawTile(int tx, int ty, Surface* screen, int x, int y)
    {
        auto test1 = screen->GetWidth();
        auto test2 = screen->GetHeight();
        auto test3 = tiles.GetWidth();
        auto test4 = tiles.GetHeight();

        Pixel* src = tiles.GetBuffer() + 1 + tx * 33 + (1 + ty * 33) * tiles.GetWidth();
        Pixel* dst = screen->GetBuffer() + x + y * screen->GetWidth();
        for (int i = 0; i < 32; i++, src += tiles.GetWidth(), dst += screen->GetWidth())
            for (int j = 0; j < 32; j++)
                dst[j] = src[j];
    }

    void Game::Tick(float deltaTime)
    {
        deltaTime /= 1000.0f;
        float nx = px, ny = py;

        screen->Clear(0);
        for (int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 10; x++)
            {
                int tx = map[y][x * 3] - 'a';
                int ty = map[y][x * 3 + 1] - 'a';
                DrawTile(tx, ty, screen, x * 32 + tileOffsetX, y * 32 + tileOffsetY);
            }
        }

        float velocityX = 0.0f;
        float velocityY = 0.0f;

        if (GetAsyncKeyState(VK_LEFT))
        {
            velocityX = -playerSpeed * deltaTime;
            tank.SetFrame(12);
        }

        if (GetAsyncKeyState(VK_RIGHT))
        {
            velocityX = playerSpeed * deltaTime;
            tank.SetFrame(4);
        }

        if (GetAsyncKeyState(VK_UP))
        {
            velocityY = -playerSpeed * deltaTime;
            tank.SetFrame(0);
        }

        if (GetAsyncKeyState(VK_DOWN))
        {
            velocityY = playerSpeed * deltaTime;
            tank.SetFrame(8);
        }

        nx += velocityX;
        ny += velocityY;


        if (CheckPos(nx + tank.GetWidth() / 2, ny + tank.GetHeight() / 2) &&
            CheckPos(nx + tank.GetWidth(), ny + tank.GetHeight()))
        {
            px = nx;
            py = ny;
        }

        tank.Draw(screen, px, py);
        screen->Box(px, py, px + tank.GetWidth(), py + tank.GetHeight(), 0xffff00);
    }

};