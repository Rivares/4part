//  Graphic;  Vectors; Threads
//  Linear Heat exchanger Mathematical Model

void displayMe()
{

    double  Rp = 0.0191806, Rj = 0.0000777, Gamma1 = (0.05654433 * t1) / 0.5, 
    Gamma2 = (0.0002291314 * t1) / 0.5,
    
	buf1[5] = {160, 160, 156, 151.99, 147.99},
	buf2[5] = {120.37, 120.37, 124.38, 128.38, 132.39};


    for(unsigned int i = 1; i < N; i++)   // n: t
    {
       for(short j = 1; j < (z-1); j++)  // i: z
       {
          x1[i][j] = x1[i-1][j] * (-Gamma1 + 1 - (t1 * Rp)) + (Gamma1 * x1[i-1][j-1]) + (t1 * Rp * y1[i-1][(z-1)-j]);
		  y1[i][j] = y1[i-1][j] * (-Gamma2 + 1 - (t1 * Rj)) + (Gamma2 * y1[i-1][j-1]) + (t1 * Rj * x1[i-1][(z-1)-j]);   	   
       }
    }

}
