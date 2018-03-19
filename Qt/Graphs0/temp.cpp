        // Draw Heat's part of model
        for(short j = 1; j < (selectZ-1); ++j) // Heat and Fluid models need parallelize!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        {
            switch(j-1)
            {
                case 0: paint.setPen(QPen(Qt::red,1.05,Qt::SolidLine));   break;
                case 1: paint.setPen(QPen(Qt::green,1.05,Qt::SolidLine)); break;
                case 2: paint.setPen(QPen(Qt::blue,1.05,Qt::SolidLine));  break;
                default:{paint.setPen(QPen(Qt::darkCyan,1.05,Qt::SolidLine));  break;}
            }

            for(double i = (double)leftX+stepN; (i <= (double)rightX); i+=step)
            {
                if(!isnan(bTV(i, j)))
                {
                    if(mode)    // Set begin of point
                    {
                        path.moveTo((i+Ox)*onePixelX,(Oy-bTV(i, j))*onePixelY);
                        mode = false;
                    }
                    else
                        path.lineTo((i+Ox)*onePixelX,(Oy-bTV(i, j))*onePixelY);
                }
            }

            paint.drawPath(path);

            path = QPainterPath();  // Clear path for new curve

            path.moveTo((leftX+stepN+Ox)*onePixelX,(Oy-bTV(0, j+1))*onePixelY); // Move to begin og point
        }

        // Draw Fluid's part of model
        mode = true;

        for(short j = 1; j < (selectZ-1); ++j) // Heat and Fluid models need parallelize!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        {
            switch(j-1)
            {
                case 0: paint.setPen(QPen(Qt::red,1.05,Qt::DotLine));   break;
                case 1: paint.setPen(QPen(Qt::green,1.05,Qt::DotLine)); break;
                case 2: paint.setPen(QPen(Qt::blue,1.05,Qt::DotLine));  break;
                default:{paint.setPen(QPen(Qt::darkCyan,1.05,Qt::DotLine));  break;}
            }

            for(double i = (double)leftX+stepN; (i <= (double)rightX); i+=step)
            {
                if(!isnan(bTF(i, j)))
                {
                    if(mode)
                    {
                        path1.moveTo((i+Ox)*onePixelX,(Oy-bTF(i, j))*onePixelY);
                        mode = false;
                    }
                    else
                        path1.lineTo((i+Ox)*onePixelX,(Oy-bTF(i, j))*onePixelY);
                 }
            }

            paint.drawPath(path1);

            path1 = QPainterPath();

            path1.moveTo((leftX+stepN+Ox)*onePixelX,(Oy-bTF(0, j+1))*onePixelY);
        }