# Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

#include <stdlib.h>
#include <stdbool.h>

#define MAX_USERS 501
#define MAX_TWEETS 10001

typedef struct {
    int userId;
    int tweetId;
    int time;
} Tweet;

typedef struct {
    bool follow[MAX_USERS][MAX_USERS];
    Tweet tweets[MAX_TWEETS];
    int tweetCount;
    int timer;
} Twitter;


Twitter* twitterCreate() {
    Twitter* obj = (Twitter*)calloc(1, sizeof(Twitter));
    return obj;
}


void twitterPostTweet(Twitter* obj, int userId, int tweetId) {
    obj->tweets[obj->tweetCount].userId = userId;
    obj->tweets[obj->tweetCount].tweetId = tweetId;
    obj->tweets[obj->tweetCount].time = obj->timer++;

    obj->tweetCount++;
}


int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) {

    int* result = (int*)malloc(10 * sizeof(int));
    *retSize = 0;

   
    for (int i = obj->tweetCount - 1;
         i >= 0 && *retSize < 10;
         i--) {

        int tweetUser = obj->tweets[i].userId;

        
        if (tweetUser == userId ||
            obj->follow[userId][tweetUser]) {

            result[*retSize] = obj->tweets[i].tweetId;
            (*retSize)++;
        }
    }

    return result;
}


void twitterFollow(Twitter* obj, int followerId, int followeeId) {

    if (followerId != followeeId) {
        obj->follow[followerId][followeeId] = true;
    }
}


void twitterUnfollow(Twitter* obj, int followerId, int followeeId) {

    if (followerId != followeeId) {
        obj->follow[followerId][followeeId] = false;
    }
}


void twitterFree(Twitter* obj) {
    free(obj);
}
