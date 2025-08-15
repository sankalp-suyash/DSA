class Twitter {
private:
    int timeStamp;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    Twitter() { timeStamp = 0; }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;

        for (auto& tw : tweets[userId]) {
            maxHeap.push(tw);
        }

        for (auto& followee : following[userId]) {
            for (auto& tw : tweets[followee]) {
                maxHeap.push(tw);
            }
        }

        vector<int> feed;
        int count = 0;
        while (!maxHeap.empty() && count < 10) {
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
            count++;
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (following.count(followerId)) {
            following[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */