    srand(time(0));
    
    for ( int i = 0; i < 10; i++ )
    {
        int randomNumber = rand() % 100 + 1;
        push( randomNumber );
    }