#include "Headers.h"

int main()
{
	system("mode con cols=120 lines=40");
	
    Set<string> game_space;
    

    game_space.Add("###################"); //0
    game_space.Add("#                 #"); //1
    game_space.Add("#                 #"); //2
    game_space.Add("#                 #"); //3
    game_space.Add("#        ##       #"); //4
    game_space.Add("#        ##       #"); //5
    game_space.Add("#                 #"); //6
    game_space.Add("#                 #"); //7
    game_space.Add("#           #######"); //8
    game_space.Add("#                 #"); //9
    game_space.Add("#######      ######"); //10
    game_space.Add("#     #           #"); //11
    game_space.Add("#  ####           #"); //12
    game_space.Add("#                 #"); //13
    game_space.Add("#                 #"); //14
    game_space.Add("###################"); //15
                  //0123456789012345678
                  //          1
    Map map(game_space);
    Player _player(4.74f, 3.44f, 0.0f, 0.0f, 60.0f, 1.5f, 345.0f, 1.5f, 30.0f, 0.25f, 2.0f, map, 'P');
    Entity& player = _player;

    GameSpace gameSpace;

    Circle circle;
    Circle circle2;
    Circle circle3;
    Circle circle4;
    Rect rect;

    try
    {
        circle.InitialiseCircle(6.9f, 9.9f, map, 0.5f, 0.5f);
        gameSpace.AddItem(&circle);

        circle2.InitialiseCircle(2.5f, 14.5f, map, 0.5f, 0.5f);
        gameSpace.AddItem(&circle2);

        circle3.InitialiseCircle(14.5f, 2.5f, map, 0.5f, 0.5f);
        gameSpace.AddItem(&circle3);

        circle4.InitialiseCircle(9.5f, 6.5f, map, 0.5f, 0.5f);
        gameSpace.AddItem(&circle4);

        rect.InitialiseRectangle(13.5f, 13.5f, map, 0.5f, 0.5f);
        gameSpace.AddItem(&rect);
    }
    catch (PositionError& exp)
    {
        cout << exp.what() << ", press any key...";
        _getch();
    }     

    FPS _fps;

    ConsoleBufferString* buffer = ConsoleBufferString::Instance(_FULL_SCREAN_);
    buffer->HideCursor();
    buffer->NotHighLightConsole();
    
    while (true)
    {
	    _fps.current_Calc_Period();
	    buffer->Render(map, player, _fps, gameSpace);
	    if (!player.Controle(map, _fps, gameSpace)) break;
    }
    
    _getch();

    /*HANDLE hStdout, hNewScreenBuffer;
    SMALL_RECT srctReadRect;
    SMALL_RECT srctWriteRect;
    CHAR_INFO chiBuffer[160]; // [2][80];
    COORD coordBufSize;
    COORD coordBufCoord;
    BOOL fSuccess;

    // Get a handle to the STDOUT screen buffer to copy from and
    // create a new screen buffer to copy to.

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    hNewScreenBuffer = CreateConsoleScreenBuffer(
        GENERIC_READ |           // read/write access
        GENERIC_WRITE,
        FILE_SHARE_READ |
        FILE_SHARE_WRITE,        // shared
        NULL,                    // default security attributes
        CONSOLE_TEXTMODE_BUFFER, // must be TEXTMODE
        NULL);                   // reserved; must be NULL
    if (hStdout == INVALID_HANDLE_VALUE ||
        hNewScreenBuffer == INVALID_HANDLE_VALUE)
    {
        printf("CreateConsoleScreenBuffer failed - (%d)\n", GetLastError());
        return 1;
    }

    // Make the new screen buffer the active screen buffer.

    if (!SetConsoleActiveScreenBuffer(hNewScreenBuffer))
    {
        printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError());
        return 1;
    }

    // Set the source rectangle.

    srctReadRect.Top = 0;    // top left: row 0, col 0
    srctReadRect.Left = 0;
    srctReadRect.Bottom = 1; // bot. right: row 1, col 79
    srctReadRect.Right = 79;

    // The temporary buffer size is 2 rows x 80 columns.

    coordBufSize.Y = 2;
    coordBufSize.X = 80;

    // The top left destination cell of the temporary buffer is
    // row 0, col 0.

    coordBufCoord.X = 0;
    coordBufCoord.Y = 0;

    // Copy the block from the screen buffer to the temp. buffer.

    fSuccess = ReadConsoleOutput(
        hStdout,        // screen buffer to read from
        chiBuffer,      // buffer to copy into
        coordBufSize,   // col-row size of chiBuffer
        coordBufCoord,  // top left dest. cell in chiBuffer
        &srctReadRect); // screen buffer source rectangle
    if (!fSuccess)
    {
        printf("ReadConsoleOutput failed - (%d)\n", GetLastError());
        return 1;
    }

    // Set the destination rectangle.

    srctWriteRect.Top = 10;    // top lt: row 10, col 0
    srctWriteRect.Left = 0;
    srctWriteRect.Bottom = 11; // bot. rt: row 11, col 79
    srctWriteRect.Right = 79;

    // Copy from the temporary buffer to the new screen buffer.

    chiBuffer[78].Attributes = { BACKGROUND_RED | FOREGROUND_RED };

    fSuccess = WriteConsoleOutput(
        hNewScreenBuffer, // screen buffer to write to
        chiBuffer,        // buffer to copy from
        coordBufSize,     // col-row size of chiBuffer
        coordBufCoord,    // top left src cell in chiBuffer
        &srctWriteRect);  // dest. screen buffer rectangle
    if (!fSuccess)
    {
        printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
        return 1;
    }
    Sleep(5000);

    // Restore the original active screen buffer.

    if (!SetConsoleActiveScreenBuffer(hStdout))
    {
        printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError());
        return 1;
    }*/
}