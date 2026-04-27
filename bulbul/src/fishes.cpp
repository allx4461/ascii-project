#include "fishes.h"
#include <cstdlib>


fish4::fish4(int worldWidth, int worldHeight)
    : Actor(
        (rand() % (worldWidth-19)),   // x
        (rand() % (worldHeight-7))+2,  // y
        1,                     
    {
  ".        ,         ",
  "|\\._,,_..)\\      ",
  "|%%%%%%%%%%\"\"-._ ",
  "|/'-'-.%%%%{{{%*  . ",
  "'      '--|/-----v  "
}

    )
{}

fish5::fish5(int worldWidth, int worldHeight)
    : Actor(
        (rand() % (worldWidth-9)),   // x
        (rand() % (worldHeight-6))+2,  // y
        1,                     // 
    {
  "__       ",
  "|\\ /%.\\",
  "|%X%%%%) ",
  "|/ \\V_/ "
}
    )
{}


fish6::fish6(int worldWidth, int worldHeight)
    : Actor(
        (rand() % (worldWidth-19)),   // x
        (rand() % (worldHeight-7))+2,  // y
        1,                     // 
    {
"         ,--,_     ",
"__    _\\.---'-.   ",
"\\ '.-\"%%%%%//%o\\",
"/_.'-._%%%%\\%%/%\" ",
"       `\"--(/`\"   ",

}
    )
{}


fish1::fish1(int worldWidth, int worldHeight)
    : Actor(
        (rand() % (worldWidth-13)),   // x
        (rand() % (worldHeight-9))+2 ,  // y
        1,                     // v —
    {
"  :<>%><>    ",
"  :<>%%><>   ",
" ><>%><>%:<> ",
"><>%:<>%:<>  ",
"  :<>%><>%><>",
"><>%:<>%><>  ",
" ><>%%:<>    ",
}
    )
{}

fish2::fish2(int worldWidth, int worldHeight)
    : Actor(
        (rand() % (worldWidth-6)),   // x
        (rand() % (worldHeight-5-2))+2 ,  // y
        1,                     // v —
    {
" ____ ",
"(o%%o)",
" )))) ",
"(((( ",
" )))) "})
{}

fish3::fish3(int worldWidth, int worldHeight)
    : Actor(
        (rand() % (worldWidth-5)),   // x
        (rand() % (worldHeight-4-2))+2 ,  // y
        1,                     // v —
    {
" :=@ ",
" {|< ",
"  |  ",
"  J  "})
{}


fish7::fish7(int worldWidth, int worldHeight)
    : Actor(
        (rand() % (worldWidth-28)),   // x
        (rand() % (worldHeight-20-2))+2 ,  // y
        1,                     // v —
    {
"                                /\\    ",
"             |\\/\\_/\\/|         :%%:   ",
" /\\          |%.%:%.%|         |%%|   ",
" //\\\\      _.-'¯¯¯¯¯¯¯'-._      |%%|   ",
" \\\\/    /¯%%%%%%%%%%%%%%%¯\\    |%%|   ",
" XX    /%%%%%._%%%%%_.%%%%%\\   |%%|   ",
" ||   |%%%%%/-_'%%%'_-\\%%%%%|  |%%|   ",
" ||   |%%%%%\\_/%%%%%\\_/%%%%%|  |%%|   ",
" ||   |%%%%%%%%%%%%%%%%%%%%%|  |/\\|   ",
" ||    \\%%%%%%WWWWWWW%%%%%%/   ||||   ",
" ||     \\%%%%%%%%%%%%%%%%%/  ()=TT=() ",
"(¯¯¯\\    |%%%%%%%_%%%%%%%|    /¯¯¯)  ",
" TT\\%\\  /%/%/%/%/ \\%\\%\\%\\%  /%/TT   ",
" || \\%\\/%/%/%/%/   \\%\\%\\%\\/%/ ||   ",
" ||  \\__/%%/%/%(     )%\\%\\%__/ (oo)  ",
" ||     (%(%(%(     )%)%)%/          ",
" ||     (%(%(%(     )%)%)%/          ",
" ||     (%(%(%(     )%)%)%/          ",
" ||     (o(o(o(     )o)o)o)          "})
{}




weed1::weed1(int worldWidth, int worldHeight)
    : Actor(
        (rand() % (worldWidth-5)),   // x
        (worldHeight-6),  // y
        1,                     
    {"  )  ",
    " -(   ",
    "  )   ",
    " -(   ",
    "  )-  "
    }
    )
{}
void weed1::move(){v=-v;}
void weed1::draw(Canvas& canvas){ 
    std::vector<std::vector<char>> sprite = getSprite(); 
    int x = this->x;
    int y = this->y; 
    canvas.addSprite(sprite,x,y,Color::Green);
}
