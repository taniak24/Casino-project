///DRAW CHAR FUNCTIONS AND BACKGROUND

const int ROWS = 200;
const int COLS = 200;

enum class Card_color
{
    NEUTRAL = 4,
    pika = 3,
    kupa = 2,
    karo = 1,
    spatia = 0
};

enum class Card_type
{
    NEUTRAL = 1,
    two = 2,
    three = 3,
    four = 4,
    five = 5,
    six = 6,
    seven = 7,
    eight = 8,
    nine = 9,
    ten = 10,
    vale = 11,
    dama = 12,
    pop = 13,
    aso = 14
};

enum class Tile_color
{
    NEUTRAL = 0,
    BLACK = 1,
    RED = 2
};

enum class Tile_number
{
    NEUTRAL = 0,
    one = 1,
    two = 2,
    three = 3,
    four = 4,
    five = 5,
    six = 6,
    seven = 7,
    eight = 8,
    nine = 9,
    ten = 10,
    eleven = 11,
    twelve = 12,
    thirteen = 13,
    fourteen = 14,
    fifthteen = 15,
    sixteen = 16,
    seventeen = 17,
    eighteen = 18,
    nineteen = 19,
    twenty = 20,
    twenty_one = 21,
    twenty_two = 22,
    twenty_three = 23,
    twenty_four = 24,
    twenty_five = 25,
    twenty_six = 26,
    twenty_seven = 27,
    twenty_eight = 28,
    twenty_nine = 29,
    thirty = 30,
    thirty_one = 31,
    thirty_two = 32,
    thirty_three = 33,
    thirty_four = 34,
    thirty_five = 35,
    thirty_six = 36
};

enum COLORS {
    BLACK = 0,
    BLUE = FOREGROUND_BLUE,
    CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN,
    GREEN = FOREGROUND_GREEN,
    RED = FOREGROUND_RED,
    BROWN = FOREGROUND_RED | FOREGROUND_GREEN,
    PURPLE = FOREGROUND_RED | FOREGROUND_BLUE,
    LIGHT_GREY =  FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN,

    GREY = 0 | FOREGROUND_INTENSITY,
    LIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    LIGHT_CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    LIGHT_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    LIGHT_RED = FOREGROUND_RED | FOREGROUND_INTENSITY,
    YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    PINK = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    WHITE =  FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
};

/// declare new colour variable.GLOBAL
COLORS defaultColor = GREY;

/// drawing
HANDLE hConsoleOutput = ::GetStdHandle(STD_OUTPUT_HANDLE);
COORD screenBuf = {ROWS, COLS};
CHAR_INFO blankScreen[(ROWS)*(COLS)] = {0};

void draw_char(char ch, int y, int x, COLORS foregroundColor, COLORS backgroundColor)
{
    CHAR_INFO chInfo;
    chInfo.Char.AsciiChar = ch;
    chInfo.Attributes = foregroundColor | (backgroundColor<<4);
    COORD bufSize = {1,1};
    COORD bufCoord = {0,0};
    SMALL_RECT screen_pos = {x, y, x+1, y+1};
    ::WriteConsoleOutput(hConsoleOutput, &chInfo, bufSize, bufCoord, &screen_pos);
}

void set_background()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            draw_char(' ', i, j, GREEN, GREEN);
        }
    }
}

char get_card_type_char(Card_type type)
{
    switch(type)
    {
    case Card_type::aso:
        return 'A';
    case Card_type::two:
        return '2';
    case Card_type::three:
        return '3';
    case Card_type::four:
        return '4';
    case Card_type::five:
        return '5';
    case Card_type::six:
        return '6';
    case Card_type::seven:
        return '7';
    case Card_type::eight:
        return '8';
    case Card_type::nine:
        return '9';
    case Card_type::ten:
        return '0';
    case Card_type::vale:
        return 'J';
    case Card_type::dama:
        return 'Q';
    case Card_type::pop:
        return 'K';
    }
}

char get_card_color_char(Card_color color)
{
    switch(color)
    {
    case Card_color::spatia:
        return 5;
    case Card_color::karo:
        return 4;
    case Card_color::kupa:
        return 3;
    case Card_color::pika:
        return 6;
    }
}

char get_number_char(Tile_number number)
{
    switch(number)
    {
    case Tile_number::one:
    return 1;
    case Tile_number::two:
    return 2;
    case Tile_number::three:
    return 3;
    case Tile_number::four:
    return 4;
    case Tile_number::five:
    return 5;
    case Tile_number::six:
    return 6;
    case Tile_number::seven:
    return 7;
    case Tile_number::eight:
    return 8;
    case Tile_number::nine:
    return 9;
    case Tile_number::ten:
    return 10;
    case Tile_number::eleven:
    return 11;
    case Tile_number::twelve:
    return 12;
    case Tile_number::thirteen:
    return 13;
    case Tile_number::fourteen:
    return 14;
    case Tile_number::fifthteen:
    return 15;
    case Tile_number::sixteen:
    return 16;
    case Tile_number::seventeen:
    return 17;
    case Tile_number::eighteen:
    return 18;
    case Tile_number::nineteen:
    return 19;
    case Tile_number::twenty:
    return 20;
    case Tile_number::twenty_one:
    return 21;
    case Tile_number::twenty_two:
    return 22;
    case Tile_number::twenty_three:
    return 23;
    case Tile_number::twenty_four:
    return 24;
    case Tile_number::twenty_five:
    return 25;
    case Tile_number::twenty_six:
    return 26;
    case Tile_number::twenty_seven:
    return 27;
    case Tile_number::twenty_eight:
    return 28;
    case Tile_number::twenty_nine:
    return 29;
    case Tile_number::thirty:
    return 30;

    }
}

