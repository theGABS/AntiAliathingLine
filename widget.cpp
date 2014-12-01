#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent){

}

void Widget::paintEvent(QPaintEvent *){
    QPainter p(this);
    //p.scale(5,5);
    int X1,X2,Y1,Y2;
    X1 = 100;
    Y1 = 100;
    X2 = 500;
    Y2 = 0;

    float S = 0;
    float MS = 0;
    float TgA = (Y2 - Y1)/(float)(X2 - X1);
    float CtgA = 1/TgA;
    float CosecA = 1/cos(atan2(Y2-Y1, X2-X1));
    //float SinA  = sin(atan2(Y2-Y1, X2-X1));
    for(int i = X1; i < X2; i++){

        float y = Y1+TgA*(i-X1);
        float yMax = y - 0.5*TgA + 0.5*CosecA;
        float yMin = y + 0.5*TgA - 0.5*CosecA;
        for(int j = (int)yMin; j <= (int)yMax; j++){






            //float y = Y1+TgA*(i-X1) + SinA*j*0.5;
            float y = j;
            float offsetY = yMax - y + 0.5;

            if(offsetY < -TgA){S = -pow(offsetY , 2)*CtgA/2;}
            if(offsetY >= -TgA && offsetY < 1){S = offsetY+TgA - TgA/2;}
            if(offsetY >= 1 && offsetY < (1 - TgA)){S = 1 + pow(1 - offsetY - TgA , 2)*CtgA;}
            if(offsetY >= (1 - TgA)){S = 1;}


            offsetY -= CosecA;

            if(offsetY < -TgA){MS = -pow(offsetY , 2)*CtgA/2;}
            if(offsetY >= -TgA && offsetY < 1){MS = offsetY+TgA - TgA/2;}
            if(offsetY >= 1 && offsetY < (1 - TgA)){MS = 1 + pow(1 - offsetY - TgA , 2)*CtgA;}
            if(offsetY >= (1 - TgA)){MS = 1;}


            if(S-MS > 1 || S-MS < 0){
                //debug this
            }
            p.setPen(QColor(0,0,0,255*(S-MS)));
            p.drawPoint(i,(int)y);

        }
    }


    p.setPen(QColor(0,0,0));
    p.drawLine(100,110,500,10);
    p.setRenderHint(QPainter::Antialiasing);
    p.drawLine(100,105,500,5);
}
























