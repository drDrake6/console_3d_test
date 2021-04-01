#include "Headers.h"

int main()
{
	system("mode con cols=120 lines=40");
	
    Set<string> game_space;
    

   /* game_space.Add("###################");//| 0
    game_space.Add("#                 #");//| 1
    game_space.Add("#   M             #");//| 2
    game_space.Add("#                 #");//| 3
    game_space.Add("#        ##       #");//| 4
    game_space.Add("#        ##       #");//| 5
    game_space.Add("#                 #");//| 6
    game_space.Add("#                 #");//| 7
    game_space.Add("#           #######");//| 8
    game_space.Add("#                 #");//| 9
    game_space.Add("#######      ######");//| 10
    game_space.Add("#     #           #");//| 11
    game_space.Add("#  ####           #");//| 12
    game_space.Add("#                 #");//| 13
    game_space.Add("#                 #");//V 14
    game_space.Add("###################");//x 15
                  //-------------------->y
                  //0123456789012345678
                  //          1*/

                  //01234567890123456789012345678901
                  //          1         2         3 
    game_space.Add("################################");//| 0
    game_space.Add("#     #                        #");//| 1
    game_space.Add("##### ##########################");//| 2
    game_space.Add("#     #                S       #");//| 3
    game_space.Add("## #### ########## #######C#####");//| 4
    game_space.Add("#  # ^#          # #  M  # #   #");//| 5
    game_space.Add("#  #  # ########T# # ### # # # #");//| 6
    game_space.Add("#       #oM      # # #   # #K# #");//| 7
    game_space.Add("#  ############### # ##### ### #");//| 8
    game_space.Add("#  #   S #            W  #    H#");//| 9
    game_space.Add("# ## X #    ############R#######");//| 10
    game_space.Add("# ######### #H#       #  #     #");//| 11
    game_space.Add("#W#         # # #######  ##### #");//| 12
    game_space.Add("############# #                #");//| 13
    game_space.Add("#               #######  ##R## #");//| 14
    game_space.Add("# #######T#######    #   #  ## #");//| 15
    game_space.Add("# #    ## #       #  #   #  ## #");//| 16
    game_space.Add("#       #     #########  #  ##T#");//| 17
    game_space.Add("# #######W#####  #   ^####  ## #");//| 18
    game_space.Add("# #     #           # #     ## #");//| 19
    game_space.Add("# #####   ############# ###### #");//| 20
    game_space.Add("# #X  T # #             #^   C #");//| 21
    game_space.Add("# ####### # ########### ########");//| 22
    game_space.Add("# #     # # # ^    #  # #      #");//| 23
    game_space.Add("#    ## # # #  #      # #####  #");//| 24
    game_space.Add("# #  # o# # ######    #        #");//| 25
    game_space.Add("######### # #       # #######  #");//| 26
    game_space.Add("#         #M      # #       #  #");//| 27
    game_space.Add("########### #####C# # #######T##");//| 28
    game_space.Add("########### #  #  ### # o   #  #");//| 29
    game_space.Add("#         R #X      ### #      #");//V 30
    game_space.Add("################################");//x 31             
                  //01234567890123456789012345678901
                  //          1         2         3 

    Map map(game_space);
    Player player(1.5f, 1.5f, 0.0f, 0.0f, 60.0f, 2.25f, 60.0f, 30.0f, 0.25f,
        2.0f, map, 'P', 100.0f);

    GameSpace gameSpace;

    Minimap* rect = new Minimap;
    Triangle* triangle = new Triangle;
    Circle* circle = new Circle;
    MedKit* medkit1 = new MedKit;
    Circle* circle2 = new Circle;
    Rhombus* rhombus2 = new Rhombus;
    Triangle* triangle1 = new Triangle;
    Triangle* triangle2 = new Triangle;
    Triangle* triangle3 = new Triangle;
    Circle* circle3 = new Circle;

    Rhombus* rhombus3 = new Rhombus;
    Rhombus* rhombus4 = new Rhombus;
    MedKit* medkit = new MedKit;
    MedKit* medkit2 = new MedKit;
    MedKit* medkit3 = new MedKit;

    
    
    gameSpace.AddObject(rect);
    gameSpace.AddObject(triangle);
    gameSpace.AddObject(circle);
    gameSpace.AddObject(medkit1);
    gameSpace.AddObject(rhombus2);
    gameSpace.AddObject(circle2);
    gameSpace.AddObject(triangle1);
    gameSpace.AddObject(triangle2);
    gameSpace.AddObject(rhombus3);
    gameSpace.AddObject(triangle3);
    gameSpace.AddObject(circle3);
    gameSpace.AddObject(rhombus4);
    gameSpace.AddObject(medkit);
    gameSpace.AddObject(medkit2);
    gameSpace.AddObject(medkit3);

    vector<pair<float, float>> coords;
    coords.push_back({ 7.5f , 28.5f });
    coords.push_back({ 5.5f , 5.0f });
    coords.push_back({ 7.5f, 9.5f });
    coords.push_back({ 9.5f , 30.5f });
    coords.push_back({ 10.0f , 5.0f });
    coords.push_back({ 25.5f , 7.5f });
    coords.push_back({ 21.5f , 25.5f });
    coords.push_back({ 18.5f, 21.5f });
    coords.push_back({ 21.5f , 3.5f });
    coords.push_back({ 23.5f , 14.5f });
    coords.push_back({ 29.5f , 24.0f });
    coords.push_back({ 30.0f , 13.5f });
    coords.push_back({ 11.5f , 13.5f });
    coords.push_back({ 15.5f , 20.5f });
    coords.push_back({ 30.5f , 25.5f });

        for (int i = 0; i < gameSpace.GetSize(); i++)
        {
            try
            {
                gameSpace[i]->Initialize(coords[i].first, coords[i].second,
                    map, 0.5f, 0.5f);
            }
            catch (PositionError& exp)
            {
                cerr << i << ") " << typeid(*(gameSpace[i])).name() << " " << exp.what() << ", press any key...";
                _getch();
            }
        }

        WeakTrap wtrap;
        wtrap.Initialize(12.7f, 1.0f, map, 0.5, 1);
        gameSpace.AddObject(&wtrap);

        WeakTrap wtrap1;
        wtrap1.Initialize(9.1f, 22.0f, map, 0.5, 0);
        gameSpace.AddObject(&wtrap1);

        WeakTrap wtrap2;
        wtrap2.Initialize(18.1f, 9.1f, map, 0.5, 1);
        gameSpace.AddObject(&wtrap2);

        MediumTrap mtrap;
        mtrap.Initialize(7.7f, 10.7f, map, 0.5, 0);
        gameSpace.AddObject(&mtrap);

        MediumTrap mtrap2;
        mtrap2.Initialize(21.1f, 1.1f, map, 0.5, 1);
        gameSpace.AddObject(&mtrap2);

        MediumTrap mtrap3;
        mtrap3.Initialize(22.1f, 1.1f, map, 0.5, 1);
        gameSpace.AddObject(&mtrap3);

        MediumTrap mtrap1;
        mtrap1.Initialize(5.7f, 22.0f, map, 0.5, 0);
        gameSpace.AddObject(&mtrap1);

        MediumTrap mtrap4;
        mtrap4.Initialize(27.7f, 11.1f, map, 0.5, 1);
        gameSpace.AddObject(&mtrap4);

        StrongTrap strap;
        strap.Initialize(3.1f, 23.0f, map, 0.5, 0);
        gameSpace.AddObject(&strap);

        StrongTrap strap1;
        strap1.Initialize(9.7f, 7.0f, map, 0.5, 0);
        gameSpace.AddObject(&strap1);

        StrongTrap strap2;
        strap2.Initialize(18.7f, 30.7f, map, 0.5, 1);
        gameSpace.AddObject(&strap2);

        StrongTrap strap3;
        strap3.Initialize(20.7f, 23.7f, map, 0.5, 1);
        gameSpace.AddObject(&strap3);

        StrongTrap strap4;
        strap4.Initialize(29.7f, 29.1f, map, 0.5, 1);
        gameSpace.AddObject(&strap4);

        CircDoor circdoor;
        circdoor.Initialize(4.1, 26.7, map, 0.5, 0);
        gameSpace.AddObject(&circdoor);

        CircDoor circdoor2;
        circdoor2.Initialize(21.1, 29.7, map, 0.5, 1);
        gameSpace.AddObject(&circdoor2);

        CircDoor circdoor3;
        circdoor3.Initialize(28.1, 17.7, map, 0.5, 0);
        gameSpace.AddObject(&circdoor3);

        RombDoor rombdoor;
        rombdoor.Initialize(10.1, 24.1, map, 0.5, 0);
        gameSpace.AddObject(&rombdoor);

        RombDoor rombdoor1;
        rombdoor1.Initialize(14.1, 27.7, map, 0.5, 0);
        gameSpace.AddObject(&rombdoor1);

        RombDoor rombdoor2;
        rombdoor2.Initialize(30.1, 10.7, map, 0.5, 1);
        gameSpace.AddObject(&rombdoor2);

        TrianDoor triandoor;
        triandoor.Initialize(6.7, 16.3, map, 0.5, 0);
        gameSpace.AddObject(&triandoor);

        TrianDoor triandoor1;
        triandoor1.Initialize(15.1, 9.3, map, 0.5, 0);
        gameSpace.AddObject(&triandoor1);

        TrianDoor triandoor2;
        triandoor2.Initialize(21.7, 6.7, map, 0.5, 1);
        gameSpace.AddObject(&triandoor2);

        TrianDoor triandoor3;
        triandoor3.Initialize(28.1, 29.7, map, 0.5, 0);
        gameSpace.AddObject(&triandoor3);

        Exit exit;
        exit.Initialize(30.7, 1.1, map, 0.5, 1);
        gameSpace.AddObject(&exit);


    FPS _fps;

    ConsoleBufferString* buffer = ConsoleBufferString::Instance(_FULL_SCREAN_);
    buffer->HideCursor();
    buffer->NotHighLightConsole();
    
    while (true)
    {
	    _fps.current_Calc_Period();
	    buffer->Render(map, player, _fps, gameSpace);
	    if (!player.Controle(map, _fps, gameSpace)) break;
        if (player.GetHP() <= 0.0f) break;
    }
    
    if (player.GetHP() <= 0.0f)
    {
        buffer->ClearScrean();
        buffer->PrintGameOver();
        while (!GetAsyncKeyState((unsigned short)Player::BUTTONS::Ecs)) {}
    }
    else
    {
        buffer->ClearScrean();
        buffer->PrintWin();
        while (!GetAsyncKeyState((unsigned short)Player::BUTTONS::Ecs)) {}
    }

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