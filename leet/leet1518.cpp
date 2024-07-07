// ACCEPTED!

int numWaterBottles(int numBottles, int numExchange)
{
    int bottlesDrinked = 0;
    int fullBottles = numBottles;
    int emptyBottles = 0;

    while (fullBottles > 0)
    {
        bottlesDrinked += fullBottles;
        emptyBottles += fullBottles;
        fullBottles = 0;

        fullBottles = emptyBottles / numExchange;
        emptyBottles = emptyBottles % numExchange;
    }

    return bottlesDrinked;
}
