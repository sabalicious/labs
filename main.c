#include "libs/data_structures/unordered_set/unordered_set.h"
#include <stdio.h>

#define MAX_SERIES 100000

int main() {
    int n;
    scanf("%d", &n);

    unordered_array_set watched_series = unordered_array_set_create(MAX_SERIES);

    long long expected_sum = (long long)n * (n + 1) / 2;
    long long sum_watched = 0;

    for (int i = 1; i < n; ++i) {
        int watched;
        scanf("%d", &watched);
        unordered_array_set_insert(&watched_series, watched);
        sum_watched += watched;
    }

    long long missed_episode = expected_sum - sum_watched;

    printf("%lld\n", missed_episode);

    unordered_array_set_delete(watched_series);

    return 0;
}



























