// posa - current position of alice
// posb - current position of bob
// capa - capacity of Jug with Alice
// capb - cpacity of Jug with Bob


class Solution
{
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
    {
        int posa = 0, posb = plants.size() - 1, capa = capacityA, capb = capacityB;
        int fill = 0;
        while (posa <= posb)
        {
            if (posa == posb)
            {
                if (capa == capb and capa < plants[posb])
                    fill++;
                else if (capa != capb and max(capa, capb) < plants[posb])
                    fill++;
                return fill;
            }

            if (capa >= plants[posa])
            {
                capa -= plants[posa];
            }
            else
            {
                capa = capacityA;
                capa -= plants[posa];
                fill++;
            }
            posa++;

            if (capb >= plants[posb])
            {
                capb -= plants[posb];
            }
            else
            {
                capb = capacityB;
                capb -= plants[posb];
                fill++;
            }
            posb--;
        }
        return fill;
    }
};