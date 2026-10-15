# A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

int shipWithinDays(int* weights, int weightsSize, int days) {
    int low = 0, high = 0;

    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > low)
            low = weights[i];

        high += weights[i];
    }

    while (low < high) {
        int mid = low + (high - low) / 2;

        int requiredDays = 1;
        int currentWeight = 0;

        for (int i = 0; i < weightsSize; i++) {
            if (currentWeight + weights[i] > mid) {
                requiredDays++;
                currentWeight = 0;
            }

            currentWeight += weights[i];
        }

        if (requiredDays <= days) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}
