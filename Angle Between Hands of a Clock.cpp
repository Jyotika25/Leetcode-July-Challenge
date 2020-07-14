class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        //angle subtended by hour hand 360/12 = 30 degree/hour
        //angle subtended by min hand 360/60 = 6 degree/ min
        
       // float h = (hour%12 + (float)minutes/60) * 30;
        float h=(hour*30)+minutes*0.5;
        float m = (minutes) * 6;
        
        float angle = fabs(h-m);
        
        if(angle>180)
            angle = 360 - angle;
        return angle;
    }
};
