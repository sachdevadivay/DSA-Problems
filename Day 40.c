# Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low = 1, high = 0;


    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > high)
            high = piles[i];
    }

    while (low < high) {
        int mid = low + (high - low) / 2;
        long long hours = 0;

        for (int i = 0; i < pilesSize; i++) {
       
            hours += (piles[i] + (long long)mid - 1) / mid;
        }

        if (hours <= h)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}
