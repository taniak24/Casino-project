using namespace std;

class Tile
{
public:
    Tile();
    Tile(Tile_number number, Tile_color color);
    //Tile(Table_piles pile);

    void init(Tile_number number, Tile_color color);
    void draw_roulette_table(int x, int y);
    Tile_number get_number_char();

private:
    Tile_number m_number;
    Tile_color m_color;

};

Tile::Tile()
{
    m_number = Tile_number::NEUTRAL;
    m_color = Tile_color::NEUTRAL;
}

Tile::Tile(Tile_number number, Tile_color color)
{
    init(number, color);
}

void Tile::init(Tile_number number, Tile_color color)
{
    m_number = number;
    m_color = color;
}

///getter
Tile_number Tile::get_number_char()
{
    return m_number;
}

void Tile::draw_roulette_table(int x, int y)
{
    string temp[5] =
   {
    "BBBBBBB",
    "B&&&&&B",
    "B&@#&&B",
    "B&&&&&B",
    "BBBBBBB"
   };

   for(int i = 0; i < 5; i++)
   {
       for(int j = 0; j < 7; j++)
       {
           if(temp[i][j] == 'B')
           {
               draw_char(temp[i][j], x+i, y+j, BLACK, BLACK); /// to change colors see card.h
           }
           else
           {
               draw_char(temp[i][j], x+i, y+j, WHITE, WHITE);
           }
       }
   }

}

