
//---Piece Starts to Fall When Game Starts---//
void fallingPiece(float& timer, float& delay, int& colorNum ){
    if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward
        }
        if (!anamoly()){
        	for(int i=0;i<4;i++)
        	gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;
        	colorNum=1+rand()%7;
            int n=rand()%7;
            //--- Un-Comment this Part When You Make BLOCKS array---//
            
                for (int i=0;i<4;i++){
                    point_1[i][0] = BLOCKS[n][i] % 2;
                    point_1[i][1] = BLOCKS[n][i] / 2;
                }
            
        }
        timer=0;
    }
    delay=0.4;
}
/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///

//--
void move(int delta_x)
{
	for (int i=0;i<4;i++)
	{
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][0]+=delta_x;                   //how much units will it move and which direction
        }
       	if(!anamoly())
       	{
        
        	for(int i=0;i<4;i++)
        	{
        	point_1[i][0]=point_2[i][0];
        
        	}
        }
}

void disappear()
{


int temp=M-1;
for(int i=M-1 ; i>0 ; i--)
{
int count=0;
	for(int j=0 ; j<N ;j++)  
	{
        if(gameGrid[i][j] != 0)
        count++;
        gameGrid[temp][j]=gameGrid[i][j];
        }
     		if(count<N)
       		temp--;
}

}
bool game_end()  // checks weather the blocks have over flowed the container
{
    bool end = false;
    for (int i = 0; i < N; i++)
    {
        if (gameGrid[0][i] != 0)
        {
            end = true;
        }
    }
    return end;
}
float drop(int& level, float& delay)  //for the soft drop of block
{

    for (int i = 0; i < 4; i++)
    {
        if (point_1[i][1] && (gameGrid[point_1[i][1]][1] != 0))
        {
            return 0.03;
        }
        else
        {
            reset(level, delay);
            return delay;
        }
    }

    return delay;

}


float reset(int& level, float& delay) 
{
    bool select = false;
    if (level == 1)
    {
        delay = 0.5;

        select = true;
    }

    else if (level == 2)
    {
        delay = 0.45;

        select = true;
    }

    else if (level == 3)
    {
        delay = 0.4;

        select = true;
    }

    else if (level == 4)
    {
        delay = 0.35;

        select = true;
    }

    return delay;

}
void movement(int& delta_x)  //will controll movement on x plane
{
    for (int i = 0; i < 4; i++)
    {
        point_2[i][0] = point_1[i][0];
        point_2[i][1] = point_1[i][1];
        point_1[i][0] += delta_x;

    }
    if (!anamoly())
    {
        for (int i = 0; i < 4; i++)
        {
            point_1[i][0] = point_2[i][0];
            point_1[i][1] = point_2[i][1];

        }
    }


}
bool line_clearing(int& score)   //clears line if it is filled
{

    static int line1;
    int line = 0;
    int full = 19;
    for (int i = 19; i > 0; i--)
    {

        int complete = 0;
        for (int j = 0; j < 10; j++)
        {
            if (gameGrid[i][j] != 0)               //checks weather line is full or not
                complete++;
            gameGrid[full][j] = gameGrid[i][j];   //after line clear moves the blocks down
        }
        if (complete < 10)
        {
            full--;
        }
        else if (complete >= 10)
        {
            line += 1;
            std::cout << "\nGame paused and line =" << line << std::endl;
        }

    }
    switch (line)    // scoring convention 
    {
   
    default:
        return 0;

    }
    line1 += line;
    //line=0;
    if (line1 > 0)
 
    return 1;


}
bool rotate()   //for the rotation of cordinates
{
    int cordinate_x = point_1[1][0];
    int cordinate_y = point_1[1][1];

    for (int i = 0; i < 4; i++)
    {
        int temp_x, temp_y;
        temp_x = point_1[i][1] - cordinate_y;
        temp_y = point_1[i][0] - cordinate_x;
        point_1[i][0] = cordinate_x - temp_x;
        point_1[i][1] = cordinate_y + temp_y;

    }
    if (!anamoly())
    {
        for (int i = 0; i < 4; i++)
        {
            point_1[i][0] = point_2[i][0];
            point_1[i][1] = point_2[i][1];

        }
    }

    return 0;


}






///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
