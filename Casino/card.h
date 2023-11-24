using namespace std;

class Card
{
public:
    Card();
    Card(Card_type type, Card_color color);
    //Card(Table_piles pile);

    void init(Card_type type, Card_color color);
    void draw(int x, int y);
    void draw_back(int x, int y);
    void draw_roulette_table(int x, int y);
    Card_type get_card_type(); ///not void because you cant return something with void; Card_type = void, char..

private:
    Card_type m_type;
    Card_color m_color;

};

Card::Card()
{
    m_type = Card_type::NEUTRAL;
    m_color = Card_color::NEUTRAL;
}

Card::Card(Card_type type, Card_color color)
{
    init(type, color);
}

void Card::init(Card_type type, Card_color color)
{
    m_type = type;
    m_color = color;
}

///getter
Card_type Card::get_card_type()
{
    return m_type;
}

void Card::draw(int x, int y)
{
    string temp[5] =
   {
    "GGGGG",
    "G  GG",
    "GGGGG",
    "GG  G",
    "GGGGG"
   };

   temp[1][1] = get_card_color_char(m_color);
   temp[3][2] = get_card_color_char(m_color);
   temp[1][2] = get_card_type_char(m_type);
   temp[3][3] = get_card_type_char(m_type);

   if(temp[1][2] == '0') {
        temp[1][2] = '1';
        temp[1][3] = '0';
        temp[3][3] = '0';
        temp[3][1] = temp[3][2];
        temp[3][2] = '1';
    } else {
        temp[3][3] = get_card_type_char(m_type);
    }

   for(int i = 0; i < 5; i++)
   {
       for(int j = 0; j < 5; j++)
       {
           if(temp[i][j] == 'G')
           {
               draw_char(temp[i][j], x+i, y+j, WHITE, WHITE);
               continue;
           }
           COLORS fcolor = (m_color == Card_color::spatia || m_color == Card_color::pika ? BLACK : RED); /// ? - if else shortcut
           draw_char(temp[i][j], x+i, y+j, fcolor, WHITE);
       }

   }
}

void Card::draw_back(int x, int y)
{
    string temp[5] =
   {
    "GBGBG",
    "BGGGB",
    "GGBGG",
    "BGGGB",
    "GBGBG"
   };


   for(int i = 0; i < 5; i++)
   {
       for(int j = 0; j < 5; j++)
       {
           if(temp[i][j] == 'G')
           {
               draw_char(temp[i][j], x+i, y+j, BLACK, BLACK);
               //continue;
           }
           else
           {
               draw_char(temp[i][j], x+i, y+j, WHITE, WHITE);
           }
       }
   }
}

