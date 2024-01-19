class Solution {
public:
    bool checkOverlap(int radius, int xCenter , int yCenter, int x1, int y1, int x2, int y2) {

        int xClosest=max(x1,min(x2,xCenter));
        int yClosest=max(y1,min(y2,yCenter));

        int Xnet=xClosest-xCenter;
        int Ynet=yClosest-yCenter;

        int d=sqrt(pow(Xnet,2)+pow(Ynet,2));
        if(d<=radius)
        return true;
        return false;
        
    }
};
