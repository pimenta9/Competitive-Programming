// ACCEPTED!

class ParkingSystem {
public:
    int big, medium, small;

    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        switch (carType)
        {
            case 1:
                if (big)
                {
                    big--;
                    return true;
                }
                else
                    return false;
            case 2:
                if (medium)
                {
                    medium--;
                    return true;
                }
                else
                    return false;
            case 3:
                if (small)
                {
                    small--;
                    return true;
                }
                else
                    return false;
            default:
                return false;
        }
    }
};
