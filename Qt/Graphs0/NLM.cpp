//  Graphic;  Vectors; Threads
//  Non-Linear Heat exchanger Mathematical Model

void displayMe()
{

    double Rp = 0.0191806, Rj = 0.0000777, h = 0.5, a0 = 0.0001152735759,
    P1 = (a0*273.15)/h, P2 = 0, PG = (0.0002291314)/h,
    
    buf1[5] = {160, 160, 156, 151.99, 147.99},
    buf2[5] = {120.37, 120.37, 124.38, 128.38, 132.39};


    //-------------------------DEFINED FOR ALL SCHEMA-----------------------------

    for(unsigned int i = 1; i < N; i++)         // n: t
    {
        for(short j = 1; j < (z-1); j++)        // i: z
        {
            P2 = (a0*x1[i-1][j+1])/h;
            
            x1[i][j] = (-x1[i-1][j]) * ((P1 * t1) - 1 - (P2 * t1) + (t1 * Rp)) 
            + (P1 * x1[i-1][j-1] * t1) - (P2 * t1 * x1[i-1][j+1]) + (t1 * Rp * y1[i-1][(z-1)-j]);
            
            y1[i][j] = y1[i-1][j] * ((-PG * t1) + 1 - (t1 * Rj)) + ((PG * t1) * y1[i-1][j-1])
            + (t1 * Rj * x1[i-1][(z-1)-j]);
        }
    }

}


